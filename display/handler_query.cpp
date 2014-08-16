
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_DISPLAY_HANDLER_QUERY_CPP
#define BDAPI_DISPLAY_HANDLER_QUERY_CPP
#define BD_DATA_DISPLAY
#include "display/handler.hpp"

/* includes */

// bdapi
#include "display/monitor.hpp"
#include "math/core.hpp"

/* namespaces */
namespace bdapi   {
namespace display {

/* display handler singleton query function implementations */

// get monitor
display::monitor* get_monitor( s32 i )
{
	if( math::within<s32>( i, monitor_amount ) )
	{
		return &monitors[i];
	}
	else
	{
		RENULL;
	}
}

/* end */

}
}

#endif
