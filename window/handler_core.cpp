
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_WINDOW_HANDLER_CORE_CPP
#define BDAPI_WINDOW_HANDLER_CORE_CPP
#define BD_DATA_WINDOW
#include "window/handler.hpp"

/* includes */

/* namespaces */
namespace bdapi  {
namespace window {

/* window handler singleton core function implementations */

// raise
result raise()
{
	SDL_RaiseWindow( sdl_window );

	return 1;
}

// restore
result restore()
{
	SDL_RestoreWindow( sdl_window );

	return 1;
}

// maximize
result maximize()
{
	SDL_MaximizeWindow( sdl_window );

	return 1;
}

// minimize
result minimize()
{
	SDL_MinimizeWindow( sdl_window );

	return 1;
}

// show
result show()
{
	SDL_ShowWindow( sdl_window );

	return 1;
}

// hide
result hide()
{
	SDL_HideWindow( sdl_window );

	return 1;
}

// set position
result set_position( s32 x, s32 y )
{
	SDL_SetWindowPosition( sdl_window, x, y );

	return 1;
}

// set size
result set_size( s32 width, s32 height )
{
	SDL_SetWindowSize( sdl_window, width, height );

	return 1;
}

// set title
result set_title( string title )
{
	SDL_SetWindowTitle( sdl_window, title.c_str() );

	return 1;
}

/* end */

}
}

#endif
