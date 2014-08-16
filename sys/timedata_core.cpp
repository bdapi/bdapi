
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_TIMEDATA_CORE_CPP
#define BDAPI_SYS_TIMEDATA_CORE_CPP
#include "sys/timedata.hpp"

/* includes */

// standard
#include "ctime"

// bdapi
#include "string/core.hpp"

/* namespaces */
namespace bdapi {
namespace sys   {

/* time data class core function implementations */

// update
timedata& timedata::update()
{
	time_t getter = time( NULL );

	struct tm* data = localtime( &getter );

	year   = data->tm_year + 1900;
	month  = data->tm_mon;
	day    = data->tm_mday;
	hour   = data->tm_hour;
	minute = data->tm_min;
	second = data->tm_sec;

	time_string      = str::format( "%02i:%02i:%02i", hour, minute, second );
	safe_time_string = str::format( "%02i-%02i-%02i", hour, minute, second );
	date_string      = str::format( "%04i-%02i-%02i", year,  month,    day );

	RETHIS;
}

/* end */

}
}

#endif
