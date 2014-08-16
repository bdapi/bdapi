
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_ECHO_INIT_CPP
#define BDAPI_AUDIO_ECHO_INIT_CPP
#include "audio/echo.hpp"

/* includes */

// stk
#include "Echo.h"

// namespaces
namespace bdapi {
namespace audio {

/* audio echo class initialization function implementations */

// constructors
echo::echo( f32 mix, f32 delay )
{
	initialize( mix, delay );
}
echo::echo( const echo& copy )
{
	stk_echo = new stk::Echo( *copy.stk_echo );

	mix   = copy.mix;
	delay = copy.delay;
}

// destructor
echo::~echo()
{
	delete stk_echo;
}

// initializers
result echo::initialize()
{
	return initialize( mix, delay );
}
result echo::initialize( f32 mix, f32 delay )
{
	stk_echo = new stk::Echo();

	set_mix  ( mix   );
	set_delay( delay );

	return 1;
}

/* end */

}
}

#endif
