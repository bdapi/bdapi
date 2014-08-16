
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_VOICE_QUERY_CPP
#define BDAPI_SYNTH_VOICE_QUERY_CPP
#include "synth/voice.hpp"

/* includes */

// bdapi
#include "synth/module.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer voice class query function implementations */

// get operator
synth::operate* voice::get_operator( s32 i )
{
	return &operators[ i % BD_SYNTH_OPERATORS ];
}

// get parameters
synth::module_parameters* voice::get_parameters()
{
	return &params;
}

/* end */

}
}

#endif
