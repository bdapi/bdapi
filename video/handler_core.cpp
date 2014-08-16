
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_HANDLER_CORE_CPP
#define BDAPI_VIDEO_HANDLER_CORE_CPP
#define BD_DATA_VIDEO
#include "video/handler.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"
#include "logging/handler.hpp"
#include "video/opengl.hpp"
#include "window/handler.hpp"

/* namespaces */
namespace bdapi {
namespace video {

/* video handler singleton initialization function implementations */

// private check gl extension
result check_ext( bl log_error, cstr extension )
{
	if( glewGetExtension( extension ) )
	{
		LOG( "~FCExtension ~FE\"%s\" ~F7is available~F8.", extension );

		return 1;
	}
	else
	{
		if( log_error )
		{
			WRITE_ERROR( "~FCExtension ~FE\"%s\" ~F7is unavailable", extension );

			return 0;
		}
		else
		{
			WRITE_WARNING( "~FCExtension ~FE\"%s\" ~F7is unavailable", extension );

			return 1;
		}
	}
}

// set vsync
result set_vsync()
{
	return set_vsync( !vsync_active );
}
result set_vsync( bl vsync )
{
	if( vsync_available )
	{
		if( vsync )
		{
			vsync_active = true;

			SDL_GL_SetSwapInterval(1);
		}
		else
		{
			vsync_active = false;

			SDL_GL_SetSwapInterval(0);
		}
	}

	return 1;
}

// render
result render()
{
	SDL_GL_SwapWindow( window::get_sdl_window() );

	return 1;
}

/* end */

}
}

#endif
