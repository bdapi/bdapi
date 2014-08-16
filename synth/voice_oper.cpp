
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_VOICE_OPERATOR_CPP
#define BDAPI_SYNTH_VOICE_OPERATOR_CPP
#include "synth/voice.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer voice class operator function implementations */

// [] operator
synth::operate* voice::operator [] ( s32 i )
{
	return get_operator(i);
}

/* end */

}
}

#endif
