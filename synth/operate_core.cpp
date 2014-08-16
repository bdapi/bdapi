
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OPERATE_CORE_CPP
#define BDAPI_SYNTH_OPERATE_CORE_CPP
#include "synth/operate.hpp"

/* includes */

// stk
#include "ADSR.h"

// bdapi
#include "audio/synth.hpp"
#include "math/core.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer operator class core function implementations */

// key on
void operate::key_on( s32 note, f32 velocity )
{
	BD_MUTEX( operator_mutex );

	if( operator_state != BD_STATE_KEY_ON )
	{
		if( params.adjusted_frequency )
		{
			oscillator_frequency->set_frequency( get_key( params.octave, params.note + note ) );
		}
		else
		{
			oscillator_frequency->set_frequency( get_key( params.octave, params.note ) );
		}

		velocity = math::clamp<f32>( 0.f, velocity, 1.f );

		adsr->setAttackTarget( params.attack_target * velocity );

		adsr->setSustainLevel( params.sustain_level * velocity );

		adsr->keyOn();

		operator_state = BD_STATE_KEY_ON;
	}
}

// key off
void operate::key_off()
{
	BD_MUTEX( operator_mutex );

	if( operator_state == BD_STATE_KEY_ON )
	{
		adsr->keyOff();

		operator_state = BD_STATE_KEY_OFF;
	}
}

// update state
void operate::update_state()
{
	BD_MUTEX( operator_mutex );

	if( operator_state   == BD_STATE_KEY_OFF
	&&  get_adsr_state() == stk::ADSR::IDLE  )
	{
		operator_state = BD_STATE_IDLE;
	}
}

// reset
void operate::reset()
{
	reset_oscillator();

	reset_lfo();

	reset_asdr();
}

// reset oscillator
void operate::reset_oscillator()
{
	BD_MUTEX( operator_mutex );

	oscillator_frequency->reset();
}

// reset low frequency oscillation
void operate::reset_lfo()
{
	BD_MUTEX( operator_mutex );

	oscillator_lfo_amplitude->reset();
	oscillator_lfo_pulse->reset();
}

// reset asdr
void operate::reset_asdr()
{
	BD_MUTEX( operator_mutex );

	*adsr = stk::ADSR();
}

/* end */

}
}

#endif
