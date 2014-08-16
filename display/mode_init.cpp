
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_DISPLAY_MODE_INIT_CPP
#define BDAPI_DISPLAY_MODE_INIT_CPP
#include "display/mode.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"

/* namespaces */
namespace bdapi   {
namespace display {

/* display mode class initialization function implementations */

// constructors
mode::mode( s32 display_index, s32 mode_index )
{
	initialize( display_index, mode_index );
}
mode::mode( const SDL_DisplayMode& sdl_display_mode )
{
	initialize( sdl_display_mode );
}
mode::mode( const mode& copy )
{
	width  = copy.width;
	height = copy.height;

	aspect_ratio = copy.aspect_ratio;

	refresh_rate = copy.refresh_rate;
	pixel_format = copy.pixel_format;
}

// initializers
result mode::initialize( s32 display_index, s32 mode_index )
{
	SDL_DisplayMode sdl_display_mode;

	sdl_display_mode.driverdata = NULL;

	SDL_ClearError();

	if( SDL_GetDisplayMode( display_index, mode_index, &sdl_display_mode ) < 0 )
	{
		WRITE_ERROR( "%s", SDL_GetError() );

		return 0;
	}

	return initialize( sdl_display_mode );
}
result mode::initialize( const SDL_DisplayMode& sdl_display_mode )
{
	width  = sdl_display_mode.w;
	height = sdl_display_mode.h;

	aspect_ratio = (f32)width / (f32)height;

	refresh_rate = sdl_display_mode.refresh_rate;
	pixel_format = sdl_display_mode.format;

	return 1;
}

/* end */

}
}

#endif
