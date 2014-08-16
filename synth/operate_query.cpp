
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OPERATE_QUERY_CPP
#define BDAPI_SYNTH_OPERATE_QUERY_CPP
#include "synth/operate.hpp"

/* includes */

// stk
#include "ADSR.h"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer operator class query function implementations */

// get parameters
synth::operator_parameters* operate::get_parameters()
{
	return &params;
}

// get adsr state
s32 operate::get_adsr_state() const
{
	return adsr->getState();
}

/* end */

}
}

#endif
