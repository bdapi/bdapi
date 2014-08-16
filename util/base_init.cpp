
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_BASE_INIT_CPP
#define BDAPI_UTIL_BASE_INIT_CPP
#include "util/base.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* base class initialization function implementations */

// constructors
base::base()
{
}
base::base( const base& copy )
{
	initialize(copy);
}

// destructors
base::~base()
{
}

// initializers
result base::initialize()
{
	return 1;
}
result base::initialize( const base& copy )
{
	return 1;
}

/* end */

}
}

#endif
