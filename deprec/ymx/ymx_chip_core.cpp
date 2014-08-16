
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_CHIP_CORE_CPP
#define BDAPI_YMX_CHIP_CORE_CPP
#include "ymx/ymx_chip.hpp"

/* includes */

// bdapi
#include "ymx/audio_band.hpp"
#include "ymx/audio_buffer.hpp"
#include "ymx/audio_reverb.hpp"
#include "core/math.hpp"
#include "ymx/ymx_core.hpp"

#include "audio/handler.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* static variables *************************************************************************************/



static s32 __s32_YMX_operator_output_dummy__;



/* ymx chip class core function implementations *********************************************************/



// private fill

void chip::__fill()
{
	if( track_current )
	{
		f32_fade_strength = math<f32>::clamp( f32_fade_strength - f32_fade_mod, 1.f );
	}
	else
	{
		f32_fade_strength = 1.f;
	}

	//-------------------------------------------------------------------------------------------------------|

	if( !bl_debug )
	{
		run( audio::get_chunk_size(), band_chip->s16p_data,
			f32_volume * f32_fade_strength );
	}
	else
	{
		run( audio::get_chunk_size(), band_chip->s16p_data, 0, s16pp_operator_buffers,
			f32_volume * f32_fade_strength );
	}

	//-------------------------------------------------------------------------------------------------------|

	band_chip->run( s16p_output_buffer );

	//-------------------------------------------------------------------------------------------------------|

	s16* data = buffer_chip->fill();

	fori( audio::get_chunk_size() )
	{
		data[i*2  ] = s16p_output_buffer[i];
		data[i*2+1] = s16p_output_buffer[i];
	}

	//-------------------------------------------------------------------------------------------------------|

	if( reverb_filter && bl_reverb )
	{
		reverb_filter->process( data, 1024 );
	}
}



// private set alg

void chip::__set_alg( s32 _channel, s32 _s32_algorithm )
{
	s32_algorithm = _s32_algorithm;

	switch( s32_algorithm )
	{
		case 0:
		{
			container_operators[_channel][0].s32_output_1 = &container_operators[_channel][1].s32_input;
			container_operators[_channel][0].s32_output_2 = &__s32_YMX_operator_output_dummy__;
			container_operators[_channel][0].s32_output_3 = &__s32_YMX_operator_output_dummy__;

			container_operators[_channel][1].s32_output_1 = &container_operators[_channel][2].s32_input;
			container_operators[_channel][2].s32_output_1 = &container_operators[_channel][3].s32_input;
			container_operators[_channel][3].s32_output_1 = &s32p_operator_output[_channel];

			break;
		}
		case 1:
		{
			container_operators[_channel][0].s32_output_1 = &container_operators[_channel][2].s32_input;
			container_operators[_channel][0].s32_output_2 = &__s32_YMX_operator_output_dummy__;
			container_operators[_channel][0].s32_output_3 = &__s32_YMX_operator_output_dummy__;

			container_operators[_channel][1].s32_output_1 = &container_operators[_channel][2].s32_input;
			container_operators[_channel][2].s32_output_1 = &container_operators[_channel][3].s32_input;
			container_operators[_channel][3].s32_output_1 = &s32p_operator_output[_channel];

			break;
		}
		case 2:
		{
			container_operators[_channel][0].s32_output_1 = &container_operators[_channel][3].s32_input;
			container_operators[_channel][0].s32_output_2 = &__s32_YMX_operator_output_dummy__;
			container_operators[_channel][0].s32_output_3 = &__s32_YMX_operator_output_dummy__;

			container_operators[_channel][1].s32_output_1 = &container_operators[_channel][2].s32_input;
			container_operators[_channel][2].s32_output_1 = &container_operators[_channel][3].s32_input;
			container_operators[_channel][3].s32_output_1 = &s32p_operator_output[_channel];

			break;
		}
		case 3:
		{
			container_operators[_channel][0].s32_output_1 = &container_operators[_channel][1].s32_input;
			container_operators[_channel][0].s32_output_2 = &__s32_YMX_operator_output_dummy__;
			container_operators[_channel][0].s32_output_3 = &__s32_YMX_operator_output_dummy__;

			container_operators[_channel][1].s32_output_1 = &container_operators[_channel][3].s32_input;
			container_operators[_channel][2].s32_output_1 = &container_operators[_channel][3].s32_input;
			container_operators[_channel][3].s32_output_1 = &s32p_operator_output[_channel];

			break;
		}
		case 4:
		{
			container_operators[_channel][0].s32_output_1 = &container_operators[_channel][1].s32_input;
			container_operators[_channel][0].s32_output_2 = &__s32_YMX_operator_output_dummy__;
			container_operators[_channel][0].s32_output_3 = &__s32_YMX_operator_output_dummy__;

			container_operators[_channel][1].s32_output_1 = &s32p_operator_output[_channel];
			container_operators[_channel][2].s32_output_1 = &container_operators[_channel][3].s32_input;
			container_operators[_channel][3].s32_output_1 = &s32p_operator_output[_channel];

			break;
		}
		case 5:
		{
			container_operators[_channel][0].s32_output_1 = &container_operators[_channel][1].s32_input;
			container_operators[_channel][0].s32_output_2 = &container_operators[_channel][2].s32_input;
			container_operators[_channel][0].s32_output_3 = &container_operators[_channel][3].s32_input;

			container_operators[_channel][1].s32_output_1 = &s32p_operator_output[_channel];
			container_operators[_channel][2].s32_output_1 = &s32p_operator_output[_channel];
			container_operators[_channel][3].s32_output_1 = &s32p_operator_output[_channel];

			break;
		}
		case 6:
		{
			container_operators[_channel][0].s32_output_1 = &container_operators[_channel][1].s32_input;
			container_operators[_channel][0].s32_output_2 = &__s32_YMX_operator_output_dummy__;
			container_operators[_channel][0].s32_output_3 = &__s32_YMX_operator_output_dummy__;

			container_operators[_channel][1].s32_output_1 = &s32p_operator_output[_channel];
			container_operators[_channel][2].s32_output_1 = &s32p_operator_output[_channel];
			container_operators[_channel][3].s32_output_1 = &s32p_operator_output[_channel];

			break;
		}
		case 7:
		{
			container_operators[_channel][0].s32_output_1 = &s32p_operator_output[_channel];
			container_operators[_channel][0].s32_output_2 = &__s32_YMX_operator_output_dummy__;
			container_operators[_channel][0].s32_output_3 = &__s32_YMX_operator_output_dummy__;

			container_operators[_channel][1].s32_output_1 = &s32p_operator_output[_channel];
			container_operators[_channel][2].s32_output_1 = &s32p_operator_output[_channel];
			container_operators[_channel][3].s32_output_1 = &s32p_operator_output[_channel];

			break;
		}
		case 8:
		{
			container_operators[_channel][0].s32_output_1 = &__s32_YMX_operator_output_dummy__;
			container_operators[_channel][0].s32_output_2 = &__s32_YMX_operator_output_dummy__;
			container_operators[_channel][0].s32_output_3 = &__s32_YMX_operator_output_dummy__;

			container_operators[_channel][1].s32_output_1 = &__s32_YMX_operator_output_dummy__;
			container_operators[_channel][2].s32_output_1 = &__s32_YMX_operator_output_dummy__;
			container_operators[_channel][3].s32_output_1 = &s32p_operator_output[_channel];

			break;
} } }



// private execute command

void chip::__execute_command( s32 i )
{
	if( i >= 0 && i < container_commands.get_size() )
	{
		command& c = container_commands[i];

		if( c.get_channel() >= 0 && c.get_channel() < s32_channels )
			__execute_command( c.get_function(), c.get_value(), c.get_channel(), c.get_operator() );
} }
void chip::__execute_command( s32 _function, s32 _value, s32 _channel, s32 _operator )
{
	switch( _function )
	{
		case YMX_CMND_KEY_ON:
		{
			fori(4)
			{
				if( container_active[_channel][i] == 1 )
					container_operators[_channel][i].set_key_on();
			}

			break;
		}

		case YMX_CMND_KEY_OFF:
		{
			fori(4)
				container_operators[_channel][i].set_key_off();

			break;
		}

		case YMX_CMND_ALG:       __set_alg( _channel, YMX_ALG(_value) );                     break;

		case YMX_CMND_OP:        container_active   [_channel][_operator%4]       = _value;  break;
		case YMX_CMND_NE:        container_operators[_channel][_operator%4].set_ne (_value); break;
		case YMX_CMND_AME:       container_operators[_channel][_operator%4].set_ame(_value); break;

		case YMX_CMND_TL:        container_operators[_channel][_operator%4].set_tl (_value); break;
		case YMX_CMND_AR:        container_operators[_channel][_operator%4].set_ar (_value); break;
		case YMX_CMND_D1R:       container_operators[_channel][_operator%4].set_d1r(_value); break;
		case YMX_CMND_D1L:       container_operators[_channel][_operator%4].set_d1l(_value); break;
		case YMX_CMND_D2R:       container_operators[_channel][_operator%4].set_d2r(_value); break;
		case YMX_CMND_RR:        container_operators[_channel][_operator%4].set_rr (_value); break;

		case YMX_CMND_OWF:       container_operators[_channel][_operator%4].set_owf(_value); break;
		case YMX_CMND_MUL:       container_operators[_channel][_operator%4].set_mul(_value); break;
		case YMX_CMND_KC:        container_operators[_channel][_operator%4].set_kc (_value); break;
		case YMX_CMND_KF:        container_operators[_channel][_operator%4].set_kf (_value); break;
		case YMX_CMND_FB:        container_operators[_channel][_operator%4].set_fb (_value); break;
		case YMX_CMND_NFQ:       container_operators[_channel][_operator%4].set_nfq(_value); break;

		case YMX_CMND_LWF:       container_operators[_channel][_operator%4].set_lwf(_value); break;
		case YMX_CMND_FRQ:       container_operators[_channel][_operator%4].set_frq(_value); break;
		case YMX_CMND_AMD:       container_operators[_channel][_operator%4].set_amd(_value); break;
		case YMX_CMND_PMD:       container_operators[_channel][_operator%4].set_pmd(_value); break;
		case YMX_CMND_AMS:       container_operators[_channel][_operator%4].set_ams(_value); break;
		case YMX_CMND_PMS:       container_operators[_channel][_operator%4].set_pms(_value); break;

		case YMX_CMND_LFO_RESET: container_operators[_channel][_operator%4].set_lfo_reset(); break;
		case YMX_CMND_LFO_START: container_operators[_channel][_operator%4].set_lfo_start(); break;
} }



// start

void chip::start()
{
	__fill();

	play();
}

// play

void chip::play()
{
	buffer_chip->play( s32_mixer_channel );

	__fill();
}

// reset

void chip::reset()
{
	fori( s32_channels )
	{
		forj(4)
		{
			container_operators[i][j].initialize(this);
		}

		__set_alg( i, 0 );
	}

	container_commands.clear();

	fori(3)
	{
		s32a_opm_execute_buffer[i] = 0;
		s32a_opm_return_buffer [i] = 0;
	}

	s32a_envelope_counter[0] = 0;
	s32a_envelope_counter[1] = 3;
}

// set force off

void chip::set_force_off()
{
	fori( s32_channels )
	{
		forj(4)
		{
			container_operators[i][j].initialize(this);
	} }

	fori(3)
	{
		s32a_opm_execute_buffer[i] = 0;
		s32a_opm_return_buffer [i] = 0;
} }



// fade

void chip::fade( f32 _f32_fade_time )
{
	f32_fade_mod = _f32_fade_time / ( 44100.f / 256.f );
}



// run

void chip::run( s32 _samples, s16* _pcm_buffer )
{
	run( _samples, _pcm_buffer, 0, NULL, 1.f );
}
void chip::run( s32 _samples, s16* _pcm_buffer, f32 _volume_master )
{
	run( _samples, _pcm_buffer, 0, NULL, _volume_master );
}
void chip::run( s32 _samples, s16* _pcm_buffer, s32 _op_chan, s16** _op_buf )
{
	run( _samples, _pcm_buffer, _op_chan, _op_buf, 1.f );
}
void chip::run( s32 _samples, s16* _pcm_buffer, s32 _op_chan, s16** _op_buf, f32 _volume_master )
{
	fori( container_commands.get_size() )
	{
		__execute_command(i);
	}

	container_commands.clear();

	s32	output;

	fori( _samples )
	{
		if( ( --s32a_envelope_counter[1] ) == 0 )
		{
			s32a_envelope_counter[0]++;
			s32a_envelope_counter[1] = 3;

			if( s32_algorithm < 8 )
			{
				forj( s32_channels )
				{
					fork(4)
					{
						container_operators[j][k].set_envelope( s32a_envelope_counter[0] );
			} } }
			else
			{
				forj( s32_channels )
				{
					container_operators[j][3].set_envelope( s32a_envelope_counter[0] );
		} } }

		forj( s32_channels )
		{
			if( s32_algorithm < 8 )
			{
				fork(4)
				{
					container_operators[j][k].get_lfo()->update();
				}

				container_operators[j][1].s32_input = 0;
				container_operators[j][2].s32_input = 0;
				container_operators[j][3].s32_input = 0;

				s32p_operator_output[j] = 0;

				s32 send_buffer_1 = container_operators[j][0].send_output_1();
				s32 send_buffer_2 = container_operators[j][1].send_output_2();
				s32 send_buffer_3 = container_operators[j][2].send_output_2();
				s32 send_buffer_4 = container_operators[j][3].send_output_3();

				if( _op_buf && _op_chan == j )
				{
					_op_buf[0][i] = math<s32>::to_s16( send_buffer_1 );
					_op_buf[1][i] = math<s32>::to_s16( send_buffer_2 );
					_op_buf[2][i] = math<s32>::to_s16( send_buffer_3 );
					_op_buf[3][i] = math<s32>::to_s16( send_buffer_4 );
			} }
			else
			{
				container_operators[j][3].get_lfo()->update();
				container_operators[j][3].s32_input = 0;

				s32p_operator_output[j] = 0;

				s32 send_buffer = container_operators[j][3].send_output_3();

				if( _op_buf && _op_chan == j )
				{
					_op_buf[0][i] = 0;
					_op_buf[1][i] = 0;
					_op_buf[2][i] = 0;
					_op_buf[3][i] = math<s32>::to_s16( send_buffer );
		} } }

		s32a_opm_execute_buffer[0] = 0;

		forj( s32_channels )
		{
			s32a_opm_execute_buffer[0] += s32p_operator_output[j] * 512;
		}

		s32a_opm_execute_buffer[0]  = ( s32a_opm_execute_buffer[0] & (s32)0xFFFFFC00 ) >> 7;
		s32a_opm_execute_buffer[0] += ( s32a_opm_execute_buffer[0] << 4 ) + s32a_opm_execute_buffer[0];

		s32a_opm_return_buffer[0] =
			( s32a_opm_execute_buffer[0]
			+ s32a_opm_execute_buffer[1]
			+ s32a_opm_execute_buffer[1]
			+ s32a_opm_execute_buffer[2]
			+ s32a_opm_return_buffer [1]
			+ s32a_opm_return_buffer [1]
			+ s32a_opm_return_buffer [1]
			- s32a_opm_return_buffer [2] * 11 ) >> 6;

		s32a_opm_execute_buffer[2] = s32a_opm_execute_buffer[1];
		s32a_opm_execute_buffer[2] = s32a_opm_execute_buffer[1];
		s32a_opm_execute_buffer[1] = s32a_opm_execute_buffer[0];
		s32a_opm_execute_buffer[1] = s32a_opm_execute_buffer[0];

		s32a_opm_return_buffer [2] = s32a_opm_return_buffer [1];
		s32a_opm_return_buffer [2] = s32a_opm_return_buffer [1];
		s32a_opm_return_buffer [1] = s32a_opm_return_buffer [0];
		s32a_opm_return_buffer [1] = s32a_opm_return_buffer [0];

		output = s32a_opm_return_buffer[0] >> 5;

		if( u32( output + 32767 ) > (u32)65534 )
		{
			if( s32( output + 32767 ) >= (s32)65534 )
			{
				output =  32767;
			}
			else
			{
				output = -32767;
		} }

		_pcm_buffer[i] = (f32)output * _volume_master * 0.25f;
} }



/* end */
}}
#endif
