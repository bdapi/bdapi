
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_PARAMETERS_HPP
#define BDAPI_SYNTH_PARAMETERS_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "audio/synth.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer oscillator parameters class declaration */

class oscillator_parameters
{

public: // public data

//generator source = BD_GENERATOR_SINE;

	f32 volume    =  1.00f;
	f32 frequency = 16.35f;
//s32 harmonics =  0;
//f32 phase     =  1.00f;

public: // public initialization functions (synth_parameters_init.cpp)

	oscillator_parameters () {};
 ~oscillator_parameters () {};

public: // public operator functions (synth_parameters_oper.cpp)

	void operator = ( const oscillator_parameters& other );

};

/* synthesizer operator parameters class declaration */

class operator_parameters
{

public: // public data

	oscillator_parameters frequency_params;
	oscillator_parameters lfo_amplitude_params;
	oscillator_parameters lfo_pulse_params;

	bl lfo_amplitude = true;
	bl lfo_pulse     = true;

	f32 volume = 1.f;

	f32 attack_target = 1.000f;
	f32 attack_time   = 0.025f;
	f32 decay_time    = 0.050f;
	f32 sustain_level = 0.750f;
	f32 release_time  = 0.250f;

	f32 feedback = 0.f;

	s32 octave = 2;
	s32 note   = 0;

	bl adjusted_frequency = true;

public: // public initialization functions (synth_parameters_init.cpp)

	operator_parameters () {};
 ~operator_parameters () {};

public: // public operator functions (synth_parameters_oper.cpp)

	void operator = ( const operator_parameters& other );

};

/* synthesizer module parameters typedef declarations */

typedef operator_parameters module_parameters_operator_parameters[ BD_SYNTH_OPERATORS ];

/* synthesizer module parameters class declaration */

class module_parameters
{

public: // public descriptor data

	s32 output_algorithm = 0;

	f32 volume = 1.f;

private: // private core data

	BD_GET_REFR( private, module_parameters_operator_parameters, operators );

public: // public initialization functions (synth_parameters_init.cpp)

	module_parameters () {};
 ~module_parameters () {};

public: // public query functions (synth_parameters_query.cpp)

	operator_parameters& get_parameters ( s32 i );

public: // public operator functions (synth_parameters_oper.cpp)

	operator_parameters& operator [] ( s32 i );

	void operator = ( const module_parameters& other );

};

/* synthesizer engine typedef declarations */

typedef module_parameters engine_parameters_module_parameters[ BD_SYNTH_MODULES ];

/* synthesizer engine parameters class declaration */

class engine_parameters
{

public: // public descriptor data

	s32 module_amount = 1;

	f32 volume = 0.25f;

private: // private core data

	BD_GET_REFR( private, engine_parameters_module_parameters, modules );

public: // public initialization functions (synth_parameters_init.cpp)

	engine_parameters () {};
 ~engine_parameters () {};

public: // public query functions (synth_parameters_query.cpp)

	module_parameters&   get_parameters ( s32 i        );
	operator_parameters& get_parameters ( s32 i, s32 j );

public: // public operator functions (synth_parameters_oper.cpp)

	module_parameters& operator [] ( s32 i );

	void operator = ( const engine_parameters& other );

};

/* end */

}
}

#endif
