
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_TIMEDATA_INIT_CPP
#define BDAPI_SYS_TIMEDATA_INIT_CPP
#include "sys/timedata.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace sys   {

/* time data class initialization function implementations */

// constructors
timedata::timedata()
{
	update();
}
timedata::timedata( const timedata& copy )
{
	year   = copy.year;
	month  = copy.month;
	day    = copy.day;
	hour   = copy.hour;
	minute = copy.minute;
	second = copy.second;

	time_string      = copy.time_string;
	safe_time_string = copy.safe_time_string;
	date_string      = copy.date_string;
}

/* end */

}
}

#endif
