
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_REVERB_CORE_CPP
#define BDAPI_AUDIO_REVERB_CORE_CPP
#include "audio/reverb.hpp"

/* includes */

// stk
#include "FreeVerb.h"

// namespaces
namespace bdapi {
namespace audio {

/* audio reverb class core function implementations */

// iterate
f32 reverb::iterate( f32 input )
{
	return freeverb->tick( input );
}

// clear
void reverb::clear()
{
	freeverb->clear();
}

/* end */

}
}

#endif
