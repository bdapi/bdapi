
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_PERFORMANCE_INIT_CPP
#define BDAPI_UTIL_PERFORMANCE_INIT_CPP
#include "util/performance.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace util  {

/* performance monitor class initialization function implementations */

// constructors
performance::performance( const performance& copy )
{
	performance_timer = sys::timer( copy.performance_timer );
}

/* end */

}
}

#endif
