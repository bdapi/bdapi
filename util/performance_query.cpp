
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_PERFORMANCE_QUERY_CPP
#define BDAPI_UTIL_PERFORMANCE_QUERY_CPP
#include "util/performance.hpp"

/* includes */

// bdapi
#include "math/core.hpp"

// namespaces
namespace bdapi {
namespace util  {

/* performance monitor class query function implementations */

// get seconds
f64 performance::get_seconds() const
{
	return math::divide<f64>( accrued_time, (f64)update_count );
}

// get milliseconds
f64 performance::get_milliseconds() const
{
	return get_seconds() * 1000.0;
}

// get microseconds
f64 performance::get_microseconds() const
{
	return get_seconds() * 1000000.0;
}

/* end */

}
}

#endif
