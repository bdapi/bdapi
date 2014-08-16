
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_THREADING_CORE_CPP
#define BDAPI_SYS_THREADING_CORE_CPP
#include "sys/threading.hpp"

/* includes */

// standard
#include "chrono"

/* namespaces */
namespace bdapi {
namespace sys   {

/* threading function implementations */

// sleep
void sleep( f64 milliseconds )
{
	if( milliseconds > 0 )
	{
		boost::posix_time::time_duration sleep_time( 0, 0, 0, milliseconds * 1000.0 );

		boost::this_thread::sleep( sleep_time );
	}
}

/* end */

}
}

#endif
