
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_PERFORMANCE_OPER_CPP
#define BDAPI_UTIL_PERFORMANCE_OPER_CPP
#include "util/performance.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace util  {

/* performance monitor class operator function implementations */

// operator ++
void performance::operator ++ ()
{
	start();
}

// operator --
void performance::operator -- ()
{
	stop();
}

// operator ()
f64 performance::operator () () const
{
	return get_seconds();
}

/* end */

}
}

#endif
