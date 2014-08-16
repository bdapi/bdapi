
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_WINDOW_HANDLER_ITERATE_CPP
#define BDAPI_WINDOW_HANDLER_ITERATE_CPP
#define BD_DATA_WINDOW
#include "window/handler.hpp"

/* includes */

// bdapi
#include "keyboard/handler.hpp"
#include "mouse/handler.hpp"
#include "sys/handler.hpp"

/* namespaces */
namespace bdapi  {
namespace window {

/* window handler singleton iteration function implementations */

// frame begin
result frame_begin()
{
	SDL_Event sdl_event;

	while( SDL_PollEvent( &sdl_event ) )
	{
		switch( sdl_event.type )
		{
			case SDL_KEYDOWN:
			case SDL_KEYUP:
			{
				keyboard::process_event( sdl_event.key );

				break;
			}

			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			{
				mouse::process_event_button( sdl_event.button );

				break;
			}

			case SDL_MOUSEMOTION:
			{
				mouse::process_event_motion( sdl_event.motion );

				break;
			}

			case SDL_MOUSEWHEEL:
			{
				mouse::process_event_wheel( sdl_event.wheel );

				break;
			}

			case SDL_QUIT:
			{
				sys::toggle_shutdown();

				break;
			}

			case SDL_TEXTINPUT:
			{
				keyboard::process_event( sdl_event.text );

				break;
			}

			case SDL_DROPFILE:
			{
				process_event( sdl_event.drop );

				break;
			}

			case SDL_SYSWMEVENT:
			{
				process_event( sdl_event.syswm );

				break;
			}

			case SDL_TEXTEDITING:
			{
				process_event( sdl_event.edit );

				break;
			}

			case SDL_WINDOWEVENT:
			{
				process_event( sdl_event.window );

				break;
			}
		}
	}

	return 1;
}

// frame finish
result frame_finish()
{
	return 1;
}

/* end */

}
}

#endif
