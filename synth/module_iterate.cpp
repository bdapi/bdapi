
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_MODULE_ITERATE_CPP
#define BDAPI_SYNTH_MODULE_ITERATE_CPP
#include "synth/module.hpp"

/* includes */

// bdapi
#include "audio/raw.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer module class iteration function implementations */

// run
audio::raw& module::run()
{
	BD_MUTEX( module_mutex );

	module_output->clear();

	fori( voice_indices.get_size() )
	{
		*module_output += get_voice( voice_indices[i] )->run();
	}

	ifor( voice_indices.get_size() )
	{
		if( get_voice( voice_indices[i] )->get_voice_state() == BD_STATE_IDLE )
		{
			get_voice( voice_indices[i] )->reset();

			voice_indices.erase(i);
		}
	}

	return *module_output;
}

/* end */

}
}

#endif
