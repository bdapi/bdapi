
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MOUSE_HANDLER_EVENT_CPP
#define BDAPI_MOUSE_HANDLER_EVENT_CPP
#define BD_DATA_MOUSE
#include "mouse/handler.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace mouse {

/* mouse handler singleton event function implementations */

// process mouse button event
result process_event_button( SDL_MouseButtonEvent& sdl_mouse_button_event )
{
	if( sdl_mouse_button_event.type == SDL_MOUSEBUTTONDOWN
	||  sdl_mouse_button_event.type == SDL_MOUSEBUTTONUP )
	{
		if( sdl_mouse_button_event.type == SDL_MOUSEBUTTONDOWN )
		{
			button_down( sdl_mouse_button_event.button );
		}
		else if( sdl_mouse_button_event.type == SDL_MOUSEBUTTONUP )
		{
			button_up( sdl_mouse_button_event.button );
		}
	}

	return 1;
}

// process mouse motion event
result process_event_motion( SDL_MouseMotionEvent& sdl_mouse_motion_event )
{
	if( sdl_mouse_motion_event.type == SDL_MOUSEMOTION )
	{
		move( sdl_mouse_motion_event.x, sdl_mouse_motion_event.y );
	}

	return 1;
}

// process mouse wheel event
result process_event_wheel( SDL_MouseWheelEvent& sdl_mouse_wheel_event )
{
	if( sdl_mouse_wheel_event.type == SDL_MOUSEWHEEL )
	{
		rotate( sdl_mouse_wheel_event.y );
	}

	return 1;
}

/* end */

}
}

#endif
