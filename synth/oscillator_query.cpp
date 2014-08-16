
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OSCILLATOR_QUERY_CPP
#define BDAPI_SYNTH_OSCILLATOR_QUERY_CPP
#include "synth/oscillator.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer oscillator class query function implementations */

// get parameters
synth::oscillator_parameters* oscillator::get_parameters()
{
	return &params;
}

/* end */

}
}

#endif
