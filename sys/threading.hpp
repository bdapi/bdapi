
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_THREADING_HPP
#define BDAPI_SYS_THREADING_HPP
#include "bdapi.hpp"

/* includes */

// boost
#define BOOST_THREAD_USE_LIB
#include "boost/thread/thread.hpp"

/* namespaces */
namespace bdapi {
namespace sys   {

/* threading core function declarations (sys_threading_core.cpp) */

void sleep ( f64 milliseconds );

/* threading function macro definitions */

#define BD_MUTEX(AA)  boost::lock_guard<boost::mutex>_( *AA )
#define BD_LOCK(AA)   AA->lock()
#define BD_UNLOCK(AA) AA->unlock()

/* end */

}
}

#endif
