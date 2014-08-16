
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_PARAMETERS_OPER_CPP
#define BDAPI_SYNTH_PARAMETERS_OPER_CPP
#include "synth/parameters.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer oscillator parameters class operator function implementations */

// operator =
void oscillator_parameters::operator = ( const oscillator_parameters& other )
{
	//source = other.source;

	volume    = other.volume;
	frequency = other.frequency;
	//harmonics = other.harmonics;
	//phase     = other.phase;
}

/* synthesizer operator parameters class operator function implementations */

// operator =
void operator_parameters::operator = ( const operator_parameters& other )
{
	frequency_params     = other.frequency_params;
	lfo_amplitude_params = other.lfo_amplitude_params;
	lfo_pulse_params     = other.lfo_pulse_params;

	lfo_amplitude = other.lfo_amplitude;
	lfo_pulse     = other.lfo_pulse;

	volume = other.volume;

	attack_target = other.attack_target;
	attack_time   = other.attack_time;
	decay_time    = other.decay_time;
	sustain_level = other.sustain_level;
	release_time  = other.release_time;

	feedback = other.feedback;

	octave = other.octave;
	note   = other.note;

	adjusted_frequency = other.adjusted_frequency;
}

/* synthesizer module parameters class operator function implementations */

// operator []
operator_parameters& module_parameters::operator [] ( s32 i )
{
	return get_parameters(i);
}

// operator =
void module_parameters::operator = ( const module_parameters& other )
{
	output_algorithm = other.output_algorithm;

	volume = other.volume;

	fori( BD_SYNTH_OPERATORS )
	{
		operators[i] = other.operators[i];
	}
}

/* synthesizer engine parameters class operator function implementations */

// operator []
module_parameters& engine_parameters::operator [] ( s32 i )
{
	return get_parameters(i);
}

// operator =
void engine_parameters::operator = ( const engine_parameters& other )
{
	module_amount = other.module_amount;

	volume = other.volume;

	fori( BD_SYNTH_MODULES )
	{
		modules[i] = other.modules[i];
	}
}

/* end */

}
}

#endif
