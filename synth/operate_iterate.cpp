
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OPERATE_ITERATE_CPP
#define BDAPI_SYNTH_OPERATE_ITERATE_CPP
#include "synth/operate.hpp"

/* includes */

// stk
#include "ADSR.h"

#include "SineWave.h"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer operator class iteration function implementations */

// iterate
f32 operate::iterate()
{
	return iterate( 0.f );
}
f32 operate::iterate( f32 modulation )
{
	BD_MUTEX( operator_mutex );

	f32 amp   = 1.f;
	f32 pulse = 0.f;

	if( params.lfo_amplitude )
	{
		oscillator_lfo_amplitude->set_frequency( params.lfo_amplitude_params.frequency );

		amp = ( oscillator_lfo_amplitude->iterate() + 1.f ) * 0.5f;
	}

	if( params.lfo_pulse )
	{
		oscillator_lfo_pulse->set_frequency( params.lfo_pulse_params.frequency );

		pulse = oscillator_lfo_pulse->iterate();
	}

	f32 output = oscillator_frequency->iterate( pow( 2.f, pulse + modulation ) )
		* adsr->tick()
		* amp
		* params.volume
		* 0.5f;

	oscillator_frequency->get_sine()->addTime( feedback_out );

	feedback_out = ( output + feedback_in ) * params.feedback;
	feedback_in  =   output;

	return output;
}

/* end */

}
}

#endif
