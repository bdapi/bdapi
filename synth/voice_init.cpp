
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_VOICE_INIT_CPP
#define BDAPI_SYNTH_VOICE_INIT_CPP
#include "synth/voice.hpp"

/* includes */

// bdapi
#include "synth/engine.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer voice class initialization function implementations */

// destructor
voice::~voice()
{
	DESTRUCT( voice_mutex );
}

// private initializers
result voice::initialize( synth::engine* parent_engine, synth::module* parent_module, s32 engine_index,
s32 module_index, s32 voice_index )
{
	this->parent_engine = parent_engine;
	this->parent_module = parent_module;
	this->engine_index  = engine_index;
	this->module_index  = module_index;
	this->voice_index   = voice_index;

	voice_output = &this->parent_engine->get_voice_outputs()[ this->voice_index ][ this->module_index ];

	voice_mutex = new boost::mutex();

	fori( BD_SYNTH_OPERATORS )
	{
		operators[i].initialize(
			this->parent_engine, this->parent_module, this,
			this->engine_index,  this->module_index,  this->voice_index,
			i );
	}

	reset();

	return 1;
}

/* end */

}
}

#endif
