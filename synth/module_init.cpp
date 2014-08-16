
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_MODULE_INIT_CPP
#define BDAPI_SYNTH_MODULE_INIT_CPP
#include "synth/module.hpp"

/* includes */

// bdapi
#include "synth/engine.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer module class initialization function implementations */

// destructor
module::~module()
{
	DESTRUCT( module_mutex );
}

// private initializers
result module::initialize( synth::engine* parent_engine, s32 engine_index, s32 module_index )
{
	this->parent_engine = parent_engine;
	this->engine_index  = engine_index;
	this->module_index  = module_index;

	module_output = &this->parent_engine->get_module_outputs()[ this->module_index ];

	module_mutex = new boost::mutex();

	fori( BD_SYNTH_VOICES )
	{
		voices[i].initialize(
			this->parent_engine, this,
			this->engine_index,  this->module_index,
			i );
	}

	return 1;
}

/* end */

}
}

#endif
