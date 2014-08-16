
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MOUSE_HANDLER_ITERATE_CPP
#define BDAPI_MOUSE_HANDLER_ITERATE_CPP
#define BD_DATA_MOUSE
#include "mouse/handler.hpp"

/* includes */

// bdapi
#include "display/handler.hpp"
#include "sys/handler.hpp"

/* namespaces */
namespace bdapi {
namespace mouse {

/* mouse handler singleton iteration function implementations */

// frame begin
result frame_begin()
{
	if( display::get_subsystem_state() == SUBSYS_ACTIVE && locked )
	{
		set_position( display::get_width() / 2, display::get_height() / 2 );
	}

	return 1;
}

// frame finish
result frame_finish()
{
	for( s32 i = 1; i < 6; i++ )
	{
		button& b = buttons[i];

		if( b.frame_count > 0 )
		{
			b.frame_count++;

			b.delta_count += sys::get_delta();
		}
		else if( b.frame_count == -1 )
		{
			b.frame_count = 0;
	} }

	rotation = 0;

	activity = false;

	return 1;
}

/* end */

}
}

#endif
