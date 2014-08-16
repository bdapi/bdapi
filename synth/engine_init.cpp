
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_ENGINE_INIT_CPP
#define BDAPI_SYNTH_ENGINE_INIT_CPP
#include "synth/engine.hpp"

/* includes */

// bdapi
#include "audio/handler.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer engine class initialization function implementations */

// destructor
engine::~engine()
{
	DESTRUCT( engine_mutex );
}

// initializers
result engine::initialize( audio::channel* parent_channel, s32 engine_index )
{
	this->parent_channel = parent_channel;
	this->engine_index   = engine_index;

	engine_outputs.initialize( audio::get_chunk_size(), 1 );

	fori( BD_SYNTH_MODULES )
	{
		module_outputs[i].initialize( audio::get_chunk_size(), 1 );

		forj( BD_SYNTH_VOICES )
		{
			voice_outputs[j][i].initialize( audio::get_chunk_size(), 1 );

			fork( BD_SYNTH_OPERATORS )
			{
				operator_outputs[k][j][i].initialize( audio::get_chunk_size(), 1 );
			}
		}
	}

	engine_mutex = new boost::mutex();

	fori( BD_SYNTH_MODULES )
	{
		modules[i].initialize(
			this,
			this->engine_index,
			i );
	}

	return 1;
}

/* end */

}
}

#endif
