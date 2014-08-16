
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_DISPLAY_MODE_HPP
#define BDAPI_DISPLAY_MODE_HPP
#include "bdapi.hpp"

/* includes */

// sdl
#include "SDL_video.h"

/* namespaces */
namespace bdapi   {
namespace display {

/* mode class declaration */

class mode
{

private: // private data

	BD_GET_COPY( private, s32, width  );
	BD_GET_COPY( private, s32, height );

	BD_GET_COPY( private, f32, aspect_ratio );

	BD_GET_COPY( private, s32, refresh_rate );
	BD_GET_COPY( private, s32, pixel_format );

public: // public initialization functions (display_mode_init.cpp)

	mode () {};
	mode ( s32 display_index, s32 mode_index       );
	mode ( const SDL_DisplayMode& sdl_display_mode );
	mode ( const mode& copy                        );
 ~mode () {};

	result initialize ( s32 display_index, s32 mode_index       );
	result initialize ( const SDL_DisplayMode& sdl_display_mode );

public: // public operator functions (display_mode_oper.cpp)

	bl operator == ( const mode& other                       ) const;
	bl operator == ( const SDL_DisplayMode& sdl_display_mode ) const;

	bl operator != ( const mode& other                       ) const;
	bl operator != ( const SDL_DisplayMode& sdl_display_mode ) const;

};

/* end */

}
}

#endif
