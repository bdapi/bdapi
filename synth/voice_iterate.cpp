
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_VOICE_ITERATE_CPP
#define BDAPI_SYNTH_VOICE_ITERATE_CPP
#include "synth/voice.hpp"

/* includes */

// bdapi
#include "audio/handler.hpp"
#include "audio/raw.hpp"


// namespaces
namespace bdapi {
namespace synth {

/* synthesizer voice class iteration function implementations */

// run
audio::raw& voice::run()
{
	return run( audio::get_chunk_size() );
}
audio::raw& voice::run( s32 size )
{
	BD_MUTEX( voice_mutex );

	if( voice_state != BD_STATE_IDLE )
	{
		f32* data = voice_output->get_data();

		f32* operator_data[ BD_SYNTH_OPERATORS ];

		fori( BD_SYNTH_OPERATORS )
		{
			operator_data[i] = get_operator(i)->get_operator_output()->get_data();
		}

		switch( params.output_algorithm )
		{
			case 0:
			{
				fori( size )
				{
					operator_data[0][i] = get_operator(0)->iterate();
					operator_data[1][i] = get_operator(1)->iterate( operator_data[0][i] );
					operator_data[2][i] = get_operator(2)->iterate( operator_data[1][i] );
					operator_data[3][i] = get_operator(3)->iterate( operator_data[2][i] );

					#if 0

					operator_data[4][i] = get_operator(4)->iterate( operator_data[3][i] );
					operator_data[5][i] = get_operator(5)->iterate( operator_data[4][i] );

					data[i] = operator_data[5][i];

					#else

					data[i] = operator_data[3][i];

					#endif
				}

				break;
			}
			case 1:
			{
				fori( size )
				{
					operator_data[0][i] = get_operator(0)->iterate();
					operator_data[1][i] = get_operator(1)->iterate();

					f32 temp = (
						operator_data[0][i] +
						operator_data[1][i] ) / 2.f;

					operator_data[2][i] = get_operator(2)->iterate( temp                );
					operator_data[3][i] = get_operator(3)->iterate( operator_data[2][i] );

					data[i] = operator_data[3][i];
				}

				break;
			}
			case 2:
			{
				fori( size )
				{
					operator_data[0][i] = get_operator(0)->iterate();
					operator_data[1][i] = get_operator(1)->iterate();
					operator_data[2][i] = get_operator(2)->iterate( operator_data[1][i] );

					f32 temp = (
						operator_data[0][i] +
						operator_data[2][i] ) / 2.f;

					operator_data[3][i] = get_operator(3)->iterate( temp );

					data[i] = operator_data[3][i];
				}

				break;
			}
			case 3:
			{
				fori( size )
				{
					operator_data[0][i] = get_operator(0)->iterate();
					operator_data[1][i] = get_operator(1)->iterate( operator_data[0][i] );
					operator_data[2][i] = get_operator(2)->iterate();

					f32 temp = (
						operator_data[1][i] +
						operator_data[2][i] ) / 2.f;

					operator_data[3][i] = get_operator(3)->iterate( temp );

					data[i] = operator_data[3][i];
				}

				break;
			}
			case 4:
			{
				fori( size )
				{
					operator_data[0][i] = get_operator(0)->iterate();
					operator_data[1][i] = get_operator(1)->iterate( operator_data[0][i] );
					operator_data[2][i] = get_operator(2)->iterate();
					operator_data[3][i] = get_operator(3)->iterate( operator_data[2][i] );

					f32 temp = (
						operator_data[1][i] +
						operator_data[3][i] ) / 2.f;

					data[i] = temp;
				}

				break;
			}
			case 5:
			{
				fori( size )
				{
					operator_data[0][i] = get_operator(0)->iterate();
					operator_data[1][i] = get_operator(1)->iterate( operator_data[0][i] );
					operator_data[2][i] = get_operator(2)->iterate( operator_data[0][i] );
					operator_data[3][i] = get_operator(3)->iterate( operator_data[0][i] );

					f32 temp = (
						operator_data[1][i] +
						operator_data[2][i] +
						operator_data[3][i] ) / 3.f;

					data[i] = temp;
				}

				break;
			}
			case 6:
			{
				fori( size )
				{
					operator_data[0][i] = get_operator(0)->iterate();
					operator_data[1][i] = get_operator(1)->iterate( operator_data[0][i] );
					operator_data[2][i] = get_operator(2)->iterate();
					operator_data[3][i] = get_operator(3)->iterate();

					f32 temp = (
						operator_data[1][i] +
						operator_data[2][i] +
						operator_data[3][i] ) / 3.f;

					data[i] = temp;
				}

				break;
			}
			case 7:
			{
				fori( size )
				{
					operator_data[0][i] = get_operator(0)->iterate();
					operator_data[1][i] = get_operator(1)->iterate();
					operator_data[2][i] = get_operator(2)->iterate();
					operator_data[3][i] = get_operator(3)->iterate();

					f32 temp = (
						operator_data[0][i] +
						operator_data[1][i] +
						operator_data[2][i] +
						operator_data[3][i] ) / 4.f;

					data[i] = temp;
				}

				break;
			}
		}

		if( voice_state == BD_STATE_KEY_ON )
		{
			if( key_off_time > 0.f && voice_timer.get_elapsed() >= key_off_time )
			{
				voice_timer.stop();

				fori( BD_SYNTH_OPERATORS )
				{
					get_operator(i)->key_off();
				}

				voice_state = BD_STATE_KEY_OFF;
			}
		}

		if( voice_state == BD_STATE_KEY_OFF )
		{
			fori( BD_SYNTH_OPERATORS )
			{
				get_operator(i)->update_state();
			}

			if( get_operator(0)->get_operator_state() == BD_STATE_IDLE
			&&  get_operator(1)->get_operator_state() == BD_STATE_IDLE
			&&  get_operator(2)->get_operator_state() == BD_STATE_IDLE
			&&  get_operator(3)->get_operator_state() == BD_STATE_IDLE
			#if 0
			&&  get_operator(4)->get_operator_state() == BD_STATE_IDLE
			&&  get_operator(5)->get_operator_state() == BD_STATE_IDLE
			#endif
			)
			{
				voice_state = BD_STATE_IDLE;
			}
		}
	}

	return *voice_output;
}

/* end */

}
}

#endif
