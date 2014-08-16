
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MOUSE_HANDLER_INIT_CPP
#define BDAPI_MOUSE_HANDLER_INIT_CPP
#define BD_DATA_MOUSE
#include "mouse/handler.hpp"

/* includes */

// bdapi
#include "display/handler.hpp"
#include "error/handler.hpp"
#include "logging/message.hpp"
#include "sys/handler.hpp"
#include "window/handler.hpp"

/* namespaces */
namespace bdapi {
namespace mouse {

/* static variables */

static bool handler_instance = false;

/* mouse handler singleton initialization function implementations */

// private initializers
result initialize( parameters* handler_parameters )
{
	LOG_ERROR_1( "~F6subsystem", "~~ has already been initialized", !handler_instance );

	handler_instance = true;

	LOG_ERROR_1( "~F6subsystem parameters", "failed to read ~~", handler_parameters );

	mouse::handler_parameters = handler_parameters;

	subsystem_state = SUBSYS_INITIALIZED;

	buttons = new button[6]();

	buttons[0].button_code = 0;

	buttons[0].name.clear();

	buttons[0].frame_count = -1;
	buttons[0].delta_count = -1.0;

	for( s32 i = 1; i < 6; i++ )
	{
		buttons[i].button_code = i;

		switch(i)
		{
			case MB_LEFT:   buttons[i].name = "Left";   break;
			case MB_MIDDLE: buttons[i].name = "Middle"; break;
			case MB_RIGHT:  buttons[i].name = "Right";  break;
			case MB_X1:     buttons[i].name = "X1";     break;
			case MB_X2:     buttons[i].name = "X2";     break;
		}

		buttons[i].frame_count = 0;
		buttons[i].delta_count = 0.0;
	}

	default_visibility = handler_parameters->visible;
	default_lock_state = handler_parameters->locked;

	if( USING_DISPLAY )
	{
		current_x_internal = display::get_width()  / 2;
		current_y_internal = display::get_height() / 2;
	}
	else
	{
		current_x_internal = 0;
		current_y_internal = 0;
	}

	previous_x_internal = current_x_internal;
	previous_y_internal = current_y_internal;

	movement_x_internal = 0;
	movement_y_internal = 0;

	if( default_visibility )
	{
		show();
	}
	else
	{
		hide();
	}

	if( default_lock_state )
	{
		lock();
	}
	else
	{
		unlock();
	}

	inside = true;

	subsystem_state = SUBSYS_ACTIVE;

	return 1;
}

// private shutdown
result shutdown()
{
	subsystem_state = SUBSYS_SUSPENDED;

	delete[] buttons;

	subsystem_state = SUBSYS_SHUTDOWN;

	return 1;
}

/* end */

}
}

#endif
