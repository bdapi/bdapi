
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_ECHO_CORE_CPP
#define BDAPI_AUDIO_ECHO_CORE_CPP
#include "audio/echo.hpp"

/* includes */

// stk
#include "Echo.h"

// namespaces
namespace bdapi {
namespace audio {

/* audio echo class core function implementations */

// iterate
f32 echo::iterate( f32 input )
{
	return stk_echo->tick( input );
}

// clear
void echo::clear()
{
	stk_echo->clear();
}

/* end */

}
}

#endif
