
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_ENGINE_ITERATE_CPP
#define BDAPI_SYNTH_ENGINE_ITERATE_CPP
#include "synth/engine.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer engine class iteration function implementations */

// run
audio::raw& engine::run()
{
	BD_MUTEX( engine_mutex );

	engine_outputs.clear();

	fori( params.module_amount )
	{
		engine_outputs += get_module(i)->run();
	}

	return engine_outputs;
}

/* end */

}
}

#endif
