
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ERROR_HANDLER_QUERY_CPP
#define BDAPI_ERROR_HANDLER_QUERY_CPP
#define BD_DATA_ERROR
#include "error/handler.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace error {

/* static variables */

static message dummy_message;

/* error handler singleton query function implementations */

// get last error
const message& get_last_error()
{
	if( error_exists() )
	{
		return error_list.get_back();
	}
	else
	{
		return dummy_message;
	}
}

// get last warning
const message& get_last_warning()
{
	if( warning_exists() )
	{
		return warning_list.get_back();
	}
	else
	{
		return dummy_message;
	}
}

// get last any
const message& get_last_any()
{
	if( any_exists() )
	{
		return any_list.get_back();
	}
	else
	{
		return dummy_message;
	}
}

// get error count
s32 get_error_count()
{
	return error_list.get_size();
}

// get warning count
s32 get_warning_count()
{
	return warning_list.get_size();
}

// get any count
s32 get_any_count()
{
	return any_list.get_size();
}

// does error exist
bl error_exists()
{
	return !error_list.is_empty();
}

// does warning exist
bl warning_exists()
{
	return !warning_list.is_empty();
}

// does any exist
bl any_exists()
{
	return !any_list.is_empty();
}

/* end */

}
}

#endif
