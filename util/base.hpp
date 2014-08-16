
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_BASE_HPP
#define BDAPI_UTIL_BASE_HPP
#include "bdapi.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* base class declaration */

class base
{

private: // private data



public: // public initialization functions (util_base_init.cpp)

	base ();
	base ( const base& copy );
 ~base ();

	result initialize ();
	result initialize ( const base& copy );

public: // public core functions (util_base_core.cpp)



};

/* end */

}
}

#endif
