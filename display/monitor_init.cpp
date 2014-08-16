
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_DISPLAY_MONITOR_INIT_CPP
#define BDAPI_DISPLAY_MONITOR_INIT_CPP
#include "display/monitor.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"

/* namespaces */
namespace bdapi   {
namespace display {

/* monitor class initialization function implementations */

// constructors
monitor::monitor( s32 display_index )
{
	initialize( display_index );
}
monitor::monitor( const monitor& copy )
{
	display_index = copy.display_index;

	mode_amount = copy.mode_amount;

	modes = copy.modes;

	desktop_mode = copy.desktop_mode;
	current_mode = copy.current_mode;
}

// initializers
result monitor::initialize( s32 display_index )
{
	this->display_index = display_index;

	SDL_ClearError();

	mode_amount = SDL_GetNumDisplayModes( this->display_index );

	if( mode_amount < 1 )
	{
		WRITE_ERROR( "%s", SDL_GetError() );

		return 0;
	}

	SDL_DisplayMode sdl_desktop_mode;
	SDL_DisplayMode sdl_current_mode;

	sdl_desktop_mode.driverdata = NULL;
	sdl_current_mode.driverdata = NULL;

	SDL_ClearError();

	if( SDL_GetDesktopDisplayMode( this->display_index, &sdl_desktop_mode ) < 0 )
	{
		WRITE_ERROR( "%s", SDL_GetError() );

		return 0;
	}

	SDL_ClearError();

	if( SDL_GetCurrentDisplayMode( this->display_index, &sdl_current_mode ) < 0 )
	{
		WRITE_ERROR( "%s", SDL_GetError() );

		return 0;
	}

	modes.initialize( mode_amount );

	fori( mode_amount )
	{
		modes[i].initialize( this->display_index, i );

		if( modes[i] == sdl_desktop_mode )
		{
			desktop_mode = &modes[i];
		}

		if( modes[i] == sdl_current_mode )
		{
			current_mode = &modes[i];
		}
	}

	return 1;
}

/* end */

}
}

#endif
