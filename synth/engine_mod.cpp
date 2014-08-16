
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_ENGINE_MOD_CPP
#define BDAPI_SYNTH_ENGINE_MOD_CPP
#include "synth/engine.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer engine class modification function implementations */

// set parameters
void engine::set_parameters( const synth::engine_parameters& params )
{
	//BD_MUTEX( engine_mutex );

	this->params = params;
}

// apply parameters
void engine::apply_parameters()
{
	apply_parameters( params );
}
void engine::apply_parameters( const synth::engine_parameters& params )
{
	fori( BD_SYNTH_MODULES )
	{
		get_module(i)->set_parameters( this->params.get_parameters(i) );
	}
}

/* end */

}
}

#endif
