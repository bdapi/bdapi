
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_PARAMETERS_QUERY_CPP
#define BDAPI_SYNTH_PARAMETERS_QUERY_CPP
#include "synth/parameters.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer module parameters class query function implementations */

// get parameters
operator_parameters& module_parameters::get_parameters( s32 i )
{
	return operators[ i % BD_SYNTH_OPERATORS ];
}

/* synthesizer engine parameters class query function implementations */

// get parameters
module_parameters& engine_parameters::get_parameters( s32 i )
{
	return modules[ i % BD_SYNTH_MODULES ];
}
operator_parameters& engine_parameters::get_parameters( s32 i, s32 j )
{
	return get_parameters(i).get_parameters(j);
}

/* end */

}
}

#endif
