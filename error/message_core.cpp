
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ERROR_MESSAGE_CORE_CPP
#define BDAPI_ERROR_MESSAGE_CORE_CPP
#include "error/message.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace error {

/* error message class core function implementations */

// operator ()
string message::operator () ()
{
	return output;
}

// get c string
cstr message::c_str()
{
	return output.c_str();
}

/* end */

}
}

#endif
