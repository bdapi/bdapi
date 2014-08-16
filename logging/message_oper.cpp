
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_LOGGING_MESSAGE_OPER_CPP
#define BDAPI_LOGGING_MESSAGE_OPER_CPP
#include "logging/message.hpp"

/* includes */

// namespaces
namespace bdapi   {
namespace logging {

/* logging message class operator function implementation */

// operator = bl
result message::operator = ( bl success )
{
	return set_result(success);
}

// operator = result
result message::operator = ( result success )
{
	return set_result(success);
}

// operator () bl
result message::operator () ( bl success )
{
	return set_result(success);
}

// operator () result
result message::operator () ( result success )
{
	return set_result(success);
}

// operator ()
result message::operator () ()
{
	if(failed)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/* end */

}
}

#endif
