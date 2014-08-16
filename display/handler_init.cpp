
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_DISPLAY_HANDLER_INIT_CPP
#define BDAPI_DISPLAY_HANDLER_INIT_CPP
#define BD_DATA_DISPLAY
#include "display/handler.hpp"

/* includes */

// sdl
#include "SDL.h"

// bdapi
#include "display/monitor.hpp"
#include "error/handler.hpp"
#include "logging/handler.hpp"
#include "logging/message.hpp"

/* namespaces */
namespace bdapi   {
namespace display {

/* static variables */

static bool handler_instance = false;

/* display handler singleton initialization function implementations */

// private initializers
result initialize( parameters* handler_parameters )
{
	LOG_ERROR_1( "~F6subsystem", "~~ has already been initialized", !handler_instance );

	handler_instance = true;

	LOG_ERROR_1( "~F6subsystem parameters", "failed to read ~~", handler_parameters );

	display::handler_parameters = handler_parameters;

	subsystem_state = SUBSYS_INITIALIZED;

	LOG_ERROR_2(
		"~FESDL ~F6video subsystem",
		"initializing ~~",
		"failed to initialize ~~",
		init_sdl() );

	LOG_ERROR_2(
		"~F6monitors",
		"initializing ~~",
		"failed to initialize ~~",
		init_monitors() );

	LOG_ERROR_3(
		"~FEmonitor ~F6diagnostics",
		"reading ~~",
		"~~ report complete",
		"failed to read ~~",
		init_diagnostics() );

	subsystem_state = SUBSYS_ACTIVE;

	return 1;
}

// private shutdown
result shutdown()
{
	subsystem_state = SUBSYS_SUSPENDED;

	DESTRUCT_X( monitors );

	subsystem_state = SUBSYS_SHUTDOWN;

	return 1;
}

// private initialize sdl
result init_sdl()
{
	SDL_ClearError();

	if( SDL_InitSubSystem(SDL_INIT_VIDEO) < 0 )
	{
		WRITE_ERROR( "%s", SDL_GetError() );

		return 0;
	}

	return 1;
}

// private initialize monitors
result init_monitors()
{
	return refresh();
}

// private initialize diagnostics
result init_diagnostics()
{
	LOG( "~FCDISPLAYS~F8: ~FF%i", monitor_amount );
	LOG( "~FCWIDTH~F8:    ~FF%i", width          );
	LOG( "~FCHEIGHT~F8:   ~FF%i", height         );
	LOG( "~FCRATE~F8:     ~FF%i", refresh_rate   );

	switch( pixel_format )
	{
		case SDL_PIXELFORMAT_UNKNOWN:     LOG( "~FCFORMAT~F8:   ~FF%s", "UNKNOWN"     ); break;
		case SDL_PIXELFORMAT_INDEX1LSB:   LOG( "~FCFORMAT~F8:   ~FF%s", "INDEX1LSB"   ); break;
		case SDL_PIXELFORMAT_INDEX1MSB:   LOG( "~FCFORMAT~F8:   ~FF%s", "INDEX1MSB"   ); break;
		case SDL_PIXELFORMAT_INDEX4LSB:   LOG( "~FCFORMAT~F8:   ~FF%s", "INDEX4LSB"   ); break;
		case SDL_PIXELFORMAT_INDEX4MSB:   LOG( "~FCFORMAT~F8:   ~FF%s", "INDEX4MSB"   ); break;
		case SDL_PIXELFORMAT_INDEX8:      LOG( "~FCFORMAT~F8:   ~FF%s", "INDEX8"      ); break;
		case SDL_PIXELFORMAT_RGB332:      LOG( "~FCFORMAT~F8:   ~FF%s", "RGB332"      ); break;
		case SDL_PIXELFORMAT_RGB444:      LOG( "~FCFORMAT~F8:   ~FF%s", "RGB444"      ); break;
		case SDL_PIXELFORMAT_RGB555:      LOG( "~FCFORMAT~F8:   ~FF%s", "RGB555"      ); break;
		case SDL_PIXELFORMAT_BGR555:      LOG( "~FCFORMAT~F8:   ~FF%s", "BGR555"      ); break;
		case SDL_PIXELFORMAT_ARGB4444:    LOG( "~FCFORMAT~F8:   ~FF%s", "ARGB4444"    ); break;
		case SDL_PIXELFORMAT_RGBA4444:    LOG( "~FCFORMAT~F8:   ~FF%s", "RGBA4444"    ); break;
		case SDL_PIXELFORMAT_ABGR4444:    LOG( "~FCFORMAT~F8:   ~FF%s", "ABGR4444"    ); break;
		case SDL_PIXELFORMAT_BGRA4444:    LOG( "~FCFORMAT~F8:   ~FF%s", "BGRA4444"    ); break;
		case SDL_PIXELFORMAT_ARGB1555:    LOG( "~FCFORMAT~F8:   ~FF%s", "ARGB1555"    ); break;
		case SDL_PIXELFORMAT_RGBA5551:    LOG( "~FCFORMAT~F8:   ~FF%s", "RGBA5551"    ); break;
		case SDL_PIXELFORMAT_ABGR1555:    LOG( "~FCFORMAT~F8:   ~FF%s", "ABGR1555"    ); break;
		case SDL_PIXELFORMAT_BGRA5551:    LOG( "~FCFORMAT~F8:   ~FF%s", "BGRA5551"    ); break;
		case SDL_PIXELFORMAT_RGB565:      LOG( "~FCFORMAT~F8:   ~FF%s", "RGB565"      ); break;
		case SDL_PIXELFORMAT_BGR565:      LOG( "~FCFORMAT~F8:   ~FF%s", "BGR565"      ); break;
		case SDL_PIXELFORMAT_RGB24:       LOG( "~FCFORMAT~F8:   ~FF%s", "RGB24"       ); break;
		case SDL_PIXELFORMAT_BGR24:       LOG( "~FCFORMAT~F8:   ~FF%s", "BGR24"       ); break;
		case SDL_PIXELFORMAT_RGB888:      LOG( "~FCFORMAT~F8:   ~FF%s", "RGB888"      ); break;
		case SDL_PIXELFORMAT_RGBX8888:    LOG( "~FCFORMAT~F8:   ~FF%s", "RGBX8888"    ); break;
		case SDL_PIXELFORMAT_BGR888:      LOG( "~FCFORMAT~F8:   ~FF%s", "BGR888"      ); break;
		case SDL_PIXELFORMAT_BGRX8888:    LOG( "~FCFORMAT~F8:   ~FF%s", "BGRX8888"    ); break;
		case SDL_PIXELFORMAT_ARGB8888:    LOG( "~FCFORMAT~F8:   ~FF%s", "ARGB8888"    ); break;
		case SDL_PIXELFORMAT_RGBA8888:    LOG( "~FCFORMAT~F8:   ~FF%s", "RGBA8888"    ); break;
		case SDL_PIXELFORMAT_ABGR8888:    LOG( "~FCFORMAT~F8:   ~FF%s", "ABGR8888"    ); break;
		case SDL_PIXELFORMAT_BGRA8888:    LOG( "~FCFORMAT~F8:   ~FF%s", "BGRA8888"    ); break;
		case SDL_PIXELFORMAT_ARGB2101010: LOG( "~FCFORMAT~F8:   ~FF%s", "ARGB2101010" ); break;
		case SDL_PIXELFORMAT_YV12:        LOG( "~FCFORMAT~F8:   ~FF%s", "YV12"        ); break;
		case SDL_PIXELFORMAT_IYUV:        LOG( "~FCFORMAT~F8:   ~FF%s", "IYUV"        ); break;
		case SDL_PIXELFORMAT_YUY2:        LOG( "~FCFORMAT~F8:   ~FF%s", "YUY2"        ); break;
		case SDL_PIXELFORMAT_UYVY:        LOG( "~FCFORMAT~F8:   ~FF%s", "UYVY"        ); break;
		case SDL_PIXELFORMAT_YVYU:        LOG( "~FCFORMAT~F8:   ~FF%s", "YVYU"        ); break;
	}

	return 1;
}

/* end */

}
}

#endif
