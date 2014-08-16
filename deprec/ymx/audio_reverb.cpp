
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_REVERB_CPP
#define BDAPI_AUDIO_REVERB_CPP
#include "ymx/audio_reverb.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace audio {



/* audio reverb class implementation ********************************************************************/



// static clamping function

static s32 __clamp( s32 v )
{
	if(      v < -32768 ) return -32768;
	else if( v >  32767 ) return  32767;
	else                  return  v;
}



// private nullify

void reverb::__nullify()
{
	max_delay = 0;

	r_param.band_pole = 0;
	r_param.band_gain = 0;

	fori(2)
		forj(4)
			r_param.comb_delay[i][j] = 0;

	r_param.comb_gain = 0;

	r_param.allpass_delay = 0;
	r_param.allpass_gain  = 0;

	r_param.vol_dry_left  = 0;
	r_param.vol_dry_right = 0;

	r_param.vol_wet_left  = 0;
	r_param.vol_wet_right = 0;

	yp = 0;

	fori(2)
	{
		forj(4)
			y[i][j] = NULL;

		 x[i] = NULL;
		ax[i] = NULL;
		ay[i] = NULL;

		forj(2)
			bx1[i][j] = 0;

		by1[i] = 0;
	}

	s16p_buffer = NULL;
}



// constructors

reverb::reverb()
{
	__nullify();
}
reverb::reverb( s32 _max_delay )
{
	__nullify();

	initialize( _max_delay );
}

// destructor

reverb::~reverb()
{
	discard();
}



// initialize

result reverb::initialize( s32 _max_delay )
{
	max_delay = _max_delay * 16;

	reset();

	yp = 0;

	fori(2)
	{
		forj(4)
		{
			y[i][j] = new s16[max_delay];

			memset( y[i][j], 0, max_delay * sizeof(s16) );
		}

		 x[i] = new s16[max_delay];
		ax[i] = new s16[max_delay];
		ay[i] = new s16[max_delay];

		memset(  x[i], 0, max_delay * sizeof(s16) );
		memset( ax[i], 0, max_delay * sizeof(s16) );
		memset( ay[i], 0, max_delay * sizeof(s16) );
	}

	memset( bx1, 0, sizeof(bx1) );
	memset( by1, 0, sizeof(by1) );

	s16p_buffer = new s16[ max_delay ];

	return 1;
}

// discard

result reverb::discard()
{
	fori(2)
	{
		forj(4)
			delete[] y[i][j];

		delete[]  x[i];
		delete[] ax[i];
		delete[] ay[i];
	}

	delete[] s16p_buffer;

	return 1;
}



// process

void reverb::process( s16* _stream, u32 _size )
{
	s16* _input  =  s16p_buffer;
	s16* _output = _stream;

	memcpy( s16p_buffer, _output, max_delay / 4 );

	if( r_param.band_gain > 0 )
	{
		__calc_bandpass( _input, _size );

		__calc_reverb( _input, _output, _size );
	}
	else
	{
		for( u32 i = 0; i < ( _size >> 2 ); i++ )
		{
			_output[0] = __clamp( _output[0] + _input[0] );
			_output[1] = __clamp( _output[1] + _input[1] );

			_output += 2;
			_input  += 2;
} } }



// reset

void reverb::reset()
{
	r_param.band_pole = 128;
	r_param.band_gain =  64;

	r_param.comb_delay[0][0] = 101;
	r_param.comb_delay[0][1] = 132;
	r_param.comb_delay[0][2] = 203;
	r_param.comb_delay[0][3] = 364;

	r_param.comb_delay[1][0] = 111;
	r_param.comb_delay[1][1] = 142;
	r_param.comb_delay[1][2] = 213;
	r_param.comb_delay[1][3] = 374;

	r_param.comb_gain = 224;

	r_param.allpass_delay = 1024;
	r_param.allpass_gain  =  192;

	r_param.vol_dry_left  =  128;
	r_param.vol_dry_right =  128;

	r_param.vol_wet_left  =  128;
	r_param.vol_wet_right =  128;
}



// private calculate bandpass

void reverb::__calc_bandpass( s16* _output, u32 _size )
{
	s32 band_pole = __clamp( r_param.band_pole * 128 );
	s32 band_gain = __clamp( r_param.band_gain * 128 );

	s32 xp = yp;

	for( u32 i = 0; i < ( _size >> 2 ); i++, _output += 2 )
	{
		forj(2)
		{
			s32 x1 = ( xp - 1 ) & ( max_delay - 1 ), bv;

			bv = _output[j] + bx1[j][1] + ( ( band_pole * x[j][x1] ) >> 15 );
			bv = ( bv * band_gain ) >> 15;

			x[j][xp] = __clamp(bv);

			bx1[j][1] = bx1[j][0];
			bx1[j][0] =  _output[j];
		}

		xp = ( xp + 1 ) & ( max_delay - 1 );
} }

// private calculate allpass

void reverb::__calc_allpass( s16* _input, s16* _output, comb_param& _comb_delay, s32 _comb_gain,
s32 _allpass_delay, s32 _allpass_gain, f32* _dry_volume, f32* _wet_volume, u32 _size )
{
	for( u32 i = 0; i < ( _size >> 2 ); i++, _input += 2, _output += 2 )
	{
		forj(2)
		{
			s32 v = 0;

			fork(4)
			{
				s32 yck = ( yp - _comb_delay[j][k] ) & ( max_delay - 1 );

				y[j][k][yp] = __clamp( x[j][yck] + ( ( _comb_gain * y[j][k][yck] ) >> 15 ) );

				v += y[j][k][yp];
			}

			v >>= 2;

			if( _allpass_delay )
			{
				ax[j][yp] = v;

				s32 ypa = ( yp - _allpass_delay ) & ( max_delay - 1 );

				v = ( ( _allpass_gain * ( ay[j][ypa] - x[j][yp] ) ) >> 15 ) + ax[j][ypa];
				v = __clamp(v);

				ay[j][yp] = v;
			}

			_output[j] = __clamp( _input[j] * _dry_volume[j] + v * _wet_volume[j] );
		}

		yp = ( yp + 1 ) & ( max_delay - 1 );
} }

// private calculate reverb

void reverb::__calc_reverb( s16* _input, s16* _output, u32 _size )
{
	s32	comb_gain = __clamp( r_param.comb_gain * 128 );

	s32 allpass_delay = s32( ( ( (f32)r_param.allpass_delay /  1000.f ) * 44100.f ) ) & ~3;
	s32 allpass_gain  = __clamp(      r_param.allpass_gain  *   128   );

	f32 dry_volume[2] = { (f32)r_param.vol_dry_left / 256.f, (f32)r_param.vol_dry_right / 256.f };
	f32 wet_volume[2] = { (f32)r_param.vol_wet_left / 256.f, (f32)r_param.vol_wet_right / 256.f };

	comb_param comb_delay;

	forj(2)
	{
		comb_delay[j][0] = r_param.comb_delay[j][0];

		fori(3)
			comb_delay[j][i+1] = comb_delay[j][i] + r_param.comb_delay[j][i+1];
	}

	fori(4)
		forj(2)
			comb_delay[j][i] = s32( ( ( (f32)comb_delay[j][i] / 1000.f ) * 44100.f ) ) & ~3;

	__calc_allpass( _input, _output, (comb_param&)comb_delay, comb_gain, allpass_delay, allpass_gain,
		dry_volume, wet_volume, _size );
}



/* end */
}}
#endif
