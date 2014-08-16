
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_TIMER_INIT_CPP
#define BDAPI_SYS_TIMER_INIT_CPP
#include "sys/timer.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace sys   {

/* timer class class initialization function implementations */

// constructors
timer::timer( const timer& copy )
{
	boost_timer = copy.boost_timer;

	saved_time = copy.saved_time;

	paused = copy.paused;
}

/* end */

}
}

#endif
