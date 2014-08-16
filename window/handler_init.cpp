
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_WINDOW_HANDLER_INIT_CPP
#define BDAPI_WINDOW_HANDLER_INIT_CPP
#define BD_DATA_WINDOW
#include "window/handler.hpp"

/* includes */

// bdapi
#include "display/handler.hpp"
#include "logging/message.hpp"
#include "sys/handler.hpp"

/* namespaces */
namespace bdapi  {
namespace window {

/* static variables */

static bool handler_instance = false;

/* window handler singleton initialization function implementations */

// private initializers
result initialize( parameters* handler_parameters )
{
	LOG_ERROR_1( "~F6subsystem", "~~ has already been initialized", !handler_instance );

	handler_instance = true;

	LOG_ERROR_1( "~F6subsystem parameters", "failed to read ~~", handler_parameters );

	window::handler_parameters = handler_parameters;

	subsystem_state = SUBSYS_INITIALIZED;

	LOG_ERROR_2(
		"~FEwindow ~F6handle",
		"creating ~~",
		"failed to create ~~",
		init_window() );

	subsystem_state = SUBSYS_ACTIVE;

	return 1;
}

// private shutdown
result shutdown()
{
	subsystem_state = SUBSYS_SUSPENDED;

	if( !sdl_window )
	{
		return 0;
	}

	SDL_DestroyWindow( sdl_window );

	subsystem_state = SUBSYS_SHUTDOWN;

	return 1;
}

// private initialize window
result init_window()
{
	sdl_window = SDL_CreateWindow( sys::get_game_full_title().c_str(), 0, 0, display::get_width(),
		display::get_height(), SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS | SDL_WINDOW_HIDDEN );

	if( !sdl_window )
	{
		return 0;
	}

	SDL_DisableScreenSaver();

	SDL_EventState( SDL_DROPFILE, 1 );

	return 1;
}

/* end */

}
}

#endif
