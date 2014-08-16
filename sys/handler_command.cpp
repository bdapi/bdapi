
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_HANDLER_COMMAND_CPP
#define BDAPI_SYS_HANDLER_COMMAND_CPP
#define BD_DATA_SYS
#include "sys/handler.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace sys   {

/* system handler singleton command line function implementations */

// get command line parameter amount
s32 get_clps()
{
	return command_line_args.get_size();
}

// get command line parameter by index
cstr get_clp( s32 i )
{
	if( command_line_args.is_within(i) )
	{
		return command_line_args[i].c_str();
	}
	else
	{
		return "";
	}
}

// check command line parameter
bl check_clp( string clp_substr )
{
	if( get_clps() > 0 )
	{
		for_i( command_line_args )
		{
			if( clp_substr.compare(*i) == 0 )
			{
				return true;
			}
		}

		return false;
	}

	return false;
}

/* end */

}
}

#endif
