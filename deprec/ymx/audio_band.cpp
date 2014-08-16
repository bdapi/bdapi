
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_BAND_CPP
#define BDAPI_AUDIO_BAND_CPP
#include "ymx/audio_band.hpp"

/* includes */

// bdapi
#include "core/math.hpp"

// namespaces
namespace bdapi {
namespace audio {



/* audio band limiter class implementation **************************************************************/



// private nullify

void band::__nullify()
{
	s16p_data = NULL;

	s32_size = 0;

	s32_phase_count = 0;
	s32_step_width  = 0;

	f32_low_pass  = 0.f;
	f32_high_pass = 0.f;

	f32pp_steps = NULL;
}



// constructors

band::band()
{
	__nullify();
}
band::band( s32 _s32_size )
{
	__nullify();

	initialize( _s32_size );
}
band::band( s32 _s32_size, s32 _s32_phase_count, s32 _s32_step_width, f32 _f32_low_pass,
f32 _f32_high_pass )
{
	__nullify();

	initialize( _s32_size, _s32_phase_count, _s32_step_width, _f32_low_pass, _f32_high_pass );
}
band::band( const band& b )
{
	s32_size = b.s32_size;

	s16p_data = new s16[ s32_size ]();

	fori( s32_size )
	{
		s16p_data[i] = b.s16p_data[i];
	}

	s32_phase_count = b.s32_phase_count;
	s32_step_width  = b.s32_step_width;

	f32_low_pass  = b.f32_low_pass;
	f32_high_pass = b.f32_high_pass;

	f32pp_steps = new f32*[ s32_phase_count ]();

	fori( s32_phase_count )
	{
		f32pp_steps[i] = new f32[ s32_step_width ]();

		forj( s32_step_width )
		{
			f32pp_steps[i][j] = b.f32pp_steps[i][j];
} } }

// destructor

band::~band()
{
	discard();
}



// initializers

result band::initialize( s32 _s32_size )
{
	return initialize( _s32_size, 32, 16, 0.999f, 0.99f );
}
result band::initialize( s32 _s32_size, s32 _s32_phase_count, s32 _s32_step_width, f32 _f32_low_pass,
f32 _f32_high_pass )
{
	s32_size = _s32_size;

	s16p_data = new s16[ s32_size ]();

	memset( s16p_data, 0, s32_size * sizeof(s16) );

	s32_phase_count = _s32_phase_count;
	s32_step_width  = _s32_step_width;

	f32_low_pass  = _f32_low_pass;
	f32_high_pass = _f32_high_pass;

	f32pp_steps = new f32*[ s32_phase_count ]();

	fori( s32_phase_count )
	{
		f32pp_steps[i] = new f32[ s32_step_width ]();

		forj( s32_step_width )
		{
			f32pp_steps[i][j] = 0.f;
	} }

	s32 __s32_master_size = s32_step_width * s32_phase_count;

	f32 __f32_master[ __s32_master_size ];

	fori( __s32_master_size )
	{
		__f32_master[i] = 0.5f;
	}

	f32 __f32_gain = 0.5f / 0.777f;

	s32 __s32_sine_size    = 256 * s32_phase_count + 2;
	s32 __s32_max_harmonic = __s32_sine_size / 2 / s32_phase_count;

	for( s32 h = 1; h <= __s32_max_harmonic; h = h + 2 )
	{
		f32 __f32_amplitude = __f32_gain / h;
		f32 __f32_to_angle  = math<f32>::pi() * 2.f / __s32_sine_size * h;

		fori( s32_step_width )
		{
			__f32_master[i] += sin( ( i - __s32_master_size / 2 ) * __f32_to_angle ) * __f32_amplitude;
		}

		__f32_gain = __f32_gain * f32_low_pass;
	}

	forh( s32_phase_count )
	{
		f32 __f32_error    = 1.f;
		f32 __f32_previous = 0.f;

		fori( s32_step_width )
		{
			f32 __f32_current = __f32_master[ i * s32_phase_count + ( s32_phase_count - 1 - h ) ];
			f32 __f32_delta   = __f32_current - __f32_previous;

			__f32_error    = __f32_error - __f32_delta;
			__f32_previous = __f32_current;

			f32pp_steps[h][i] = __f32_delta;
		}

		f32pp_steps[h][ s32_step_width / 2 - 1 ] += __f32_error * 0.5f;
		f32pp_steps[h][ s32_step_width / 2     ] += __f32_error * 0.5f;
	}

	return 1;
}

// discard

result band::discard()
{
	delete[] s16p_data;

	fori( s32_phase_count )
	{
		delete[] f32pp_steps[i];
	}

	delete[] f32pp_steps;

	return 1;
}



// run

result band::run( s16* _s32p_output )
{
	fori( s32_size )
	{
		_s32p_output[i] = s16p_data[i];
	}

	return 1;
}



/* end */
}}
#endif
