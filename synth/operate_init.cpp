
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OPERATE_INIT_CPP
#define BDAPI_SYNTH_OPERATE_INIT_CPP
#include "synth/operate.hpp"

/* includes */

// stk
#include "ADSR.h"

// bdapi
#include "synth/engine.hpp"
#include "synth/module.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer operator class initialization function implementations */

// destructor
operate::~operate()
{
	DESTRUCT( oscillator_frequency     );
	DESTRUCT( oscillator_lfo_amplitude );
	DESTRUCT( oscillator_lfo_pulse     );
	DESTRUCT( adsr                     );

	DESTRUCT( operator_mutex );
}

// initializers
result operate::initialize( synth::engine* parent_engine, synth::module* parent_module,
synth::voice* parent_voice, s32 engine_index, s32 module_index, s32 voice_index, s32 operator_index )
{
	this->parent_engine  = parent_engine;
	this->parent_module  = parent_module;
	this->parent_voice   = parent_voice;
	this->engine_index   = engine_index;
	this->module_index   = module_index;
	this->voice_index    = voice_index;
	this->operator_index = operator_index;

	operator_output = &this->parent_engine->get_operator_outputs()[ this->operator_index ][ this->voice_index ]
		[ this->module_index ];

	operator_mutex = new boost::mutex();

	oscillator_frequency     = new synth::oscillator();
	oscillator_lfo_amplitude = new synth::oscillator();
	oscillator_lfo_pulse     = new synth::oscillator();
	adsr                     = new stk::ADSR();

	reset();

	return 1;
}

/* end */

}
}

#endif
