
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_DISPLAY_MODE_OPER_CPP
#define BDAPI_DISPLAY_MODE_OPER_CPP
#include "display/mode.hpp"

/* includes */

/* namespaces */
namespace bdapi   {
namespace display {

/* display mode class operator function implementations */

// operator == mode
bl mode::operator == ( const mode& other ) const
{
	if( width  != other.width  ) return false;
	if( height != other.height ) return false;

	if( refresh_rate != other.refresh_rate ) return false;
	if( pixel_format != other.pixel_format ) return false;

	return true;
}

// operator == sdl display mode
bl mode::operator == ( const SDL_DisplayMode& sdl_display_mode ) const
{
	if( width  != sdl_display_mode.w ) return false;
	if( height != sdl_display_mode.h ) return false;

	if( refresh_rate != sdl_display_mode.refresh_rate ) return false;
	if( pixel_format != sdl_display_mode.format       ) return false;

	return true;
}

// operator != mode
bl mode::operator != ( const mode& other ) const
{
	return !( *this == other );
}

// operator != sdl display mode
bl mode::operator != ( const SDL_DisplayMode& sdl_display_mode ) const
{
	return !( *this == sdl_display_mode );
}

/* end */

}
}

#endif
