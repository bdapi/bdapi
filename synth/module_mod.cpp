
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_MODULE_MOD_CPP
#define BDAPI_SYNTH_MODULE_MOD_CPP
#include "synth/module.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer module class modification function implementations */

// set parameters
void module::set_parameters( const synth::module_parameters& params )
{
	//BD_MUTEX( module_mutex );

	this->params = params;
}

// apply parameters
void module::apply_parameters()
{
	apply_parameters( params );
}
void module::apply_parameters( const synth::module_parameters& params )
{
}

/* end */

}
}

#endif
