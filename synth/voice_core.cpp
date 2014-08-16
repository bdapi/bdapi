
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_VOICE_CORE_CPP
#define BDAPI_SYNTH_VOICE_CORE_CPP
#include "synth/voice.hpp"

/* includes */

// bdapi
#include "audio/raw.hpp"
#include "synth/module.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* static variables */

static s32 dummy_output;

/* synthesizer voice class core function implementations */

// key on
void voice::key_on( s32 note, f32 velocity, f32 duration )
{
	BD_MUTEX( voice_mutex );

	if( voice_state != BD_STATE_KEY_ON )
	{
		key_off_time = duration;

		voice_timer.start();

		fori( BD_SYNTH_OPERATORS )
		{
			get_operator(i)->reset();

			get_operator(i)->set_parameters( params[i] );

			get_operator(i)->apply_parameters();

			get_operator(i)->key_on( note, velocity );
		}

		voice_state = BD_STATE_KEY_ON;
	}
}

// key off
void voice::key_off()
{
	BD_MUTEX( voice_mutex );

	if( voice_state == BD_STATE_KEY_ON )
	{
		voice_timer.stop();

		fori( BD_SYNTH_OPERATORS )
		{
			get_operator(i)->key_off();
		}

		voice_state = BD_STATE_KEY_OFF;
	}
}

// reset
void voice::reset()
{
	BD_MUTEX( voice_mutex );

	voice_output->clear();

	fori( BD_SYNTH_OPERATORS )
	{
		get_operator(i)->reset();

		get_operator(i)->get_operator_output()->clear();
	}

	voice_state = BD_STATE_READY;
}

/* end */

}
}

#endif
