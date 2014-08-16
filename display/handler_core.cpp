
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_DISPLAY_HANDLER_CORE_CPP
#define BDAPI_DISPLAY_HANDLER_CORE_CPP
#define BD_DATA_DISPLAY
#include "display/handler.hpp"

/* includes */

// bdapi
#include "display/monitor.hpp"
#include "error/handler.hpp"

/* namespaces */
namespace bdapi   {
namespace display {

/* display handler singleton core function implementations */

// refresh
result refresh()
{
	primary_monitor = NULL;

	monitor_amount = 0;

	SDL_ClearError();

	monitor_amount = SDL_GetNumVideoDisplays();

	if( monitor_amount < 1 )
	{
		WRITE_ERROR( "%s", SDL_GetError() );

		return 0;
	}

	NEW_X( display::monitor, monitors, monitor_amount );

	fori( monitor_amount )
	{
		monitors[i].initialize(i);
	}

	primary_monitor = &monitors[0];

	width  = primary_monitor->get_current_mode()->get_width();
	height = primary_monitor->get_current_mode()->get_height();

	aspect_ratio = primary_monitor->get_current_mode()->get_aspect_ratio();

	refresh_rate = primary_monitor->get_current_mode()->get_refresh_rate();
	pixel_format = primary_monitor->get_current_mode()->get_pixel_format();

	return 1;
}

/* end */

}
}

#endif
