
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_PERFORMANCE_CORE_CPP
#define BDAPI_UTIL_PERFORMANCE_CORE_CPP
#include "util/performance.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace util  {

/* performance monitor class core function implementations */

// start
void performance::start()
{
	performance_timer.start();
}

// stop
void performance::stop()
{
	if( performance_timer.is_on() )
	{
		performance_timer.stop();

		update_count++;

		accrued_time += performance_timer.get_stopped();
	}
}

/* end */

}
}

#endif
