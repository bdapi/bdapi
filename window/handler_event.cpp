
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_WINDOW_HANDLER_EVENT_CPP
#define BDAPI_WINDOW_HANDLER_EVENT_CPP
#define BD_DATA_WINDOW
#include "window/handler.hpp"

/* includes */

// bdapi
#include "keyboard/handler.hpp"
#include "mouse/handler.hpp"

/* namespaces */
namespace bdapi  {
namespace window {

/* window handler singleton event function implementations */

// process drop event
result process_event( SDL_DropEvent& sdl_drop_event )
{
	return 1;
}

// process system window manager event
result process_event( SDL_SysWMEvent& sdl_sys_wm_event )
{
	return 1;
}

// process text editing event
result process_event( SDL_TextEditingEvent& sdl_text_editing_event )
{
	return 1;
}

// process window event
result process_event( SDL_WindowEvent& sdl_window_event )
{
	switch( sdl_window_event.type )
	{
		case SDL_WINDOWEVENT_SHOWN:
		{
			// do something

			break;
		}

		case SDL_WINDOWEVENT_HIDDEN:
		{
			// do something

			break;
		}

		case SDL_WINDOWEVENT_FOCUS_GAINED:
		{
			keyboard::set_focus(true);

			break;
		}

		case SDL_WINDOWEVENT_FOCUS_LOST:
		{
			keyboard::set_focus(false);

			break;
		}

		case SDL_WINDOWEVENT_ENTER:
		{
			//mouse::set_inside(true);

			break;
		}

		case SDL_WINDOWEVENT_LEAVE:
		{
			//mouse::set_inside(false);

			break;
		}
	}

	return 1;
}

/* end */

}
}

#endif
