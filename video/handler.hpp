
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_HANDLER_HPP
#define BDAPI_VIDEO_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

// sdl
#include "SDL_video.h"

// bdapi
#include "string/string.hpp"

/* namespaces */
namespace bdapi {
namespace video {

/* video handler parameters struct declaration */

struct parameters
{
	bl use_vsync = true;

	bl default_filtered  = false;
	bl default_mipmapped = false;
	bl default_clamped   = true;

	bl using_blitter = false;
	bl using_index   = false;
	bl using_ntsc    = false;

	bl using_pipeline = false;

	s32 canvas_width;
	s32 canvas_height;

};

/* video handler singleton declaration */

#ifdef  BD_DATA_VIDEO
#define BD_DATA_EXTERN
#endif
#include "core/local_open.hpp"

// initialization data

BD_DATA_GET_COPY_INIT_SET( subsys, subsystem_state, SUBSYS_UNUSED );

BD_DATA_GET_COPY( parameters*, handler_parameters );

// core data

BD_DATA_GET_COPY( SDL_GLContext*, sdl_gl_context );

BD_DATA_GET_COPY( string, gl_renderer );
BD_DATA_GET_COPY( string, gl_vendor   );
BD_DATA_GET_COPY( string, gl_version  );

BD_DATA_GET_COPY( s32, gl_version_major );
BD_DATA_GET_COPY( s32, gl_version_minor );

// descriptor data

BD_DATA_IS_COPY( bl, vsync_available );
BD_DATA_IS_COPY( bl, vsync_active    );

BD_DATA_IS_COPY( bl, default_filtered  );
BD_DATA_IS_COPY( bl, default_mipmapped );
BD_DATA_IS_COPY( bl, default_clamped   );

BD_DATA_IS_COPY( bl, using_blitter );
BD_DATA_IS_COPY( bl, using_index   );
BD_DATA_IS_COPY( bl, using_ntsc    );

BD_DATA_IS_COPY( bl, using_pipeline );

BD_DATA_GET_COPY( s32, canvas_width  );
BD_DATA_GET_COPY( s32, canvas_height );

// pipeline data

BD_DATA_GET_COPY( shader*, shader_default   );
BD_DATA_GET_COPY( shader*, shader_blitter   );
BD_DATA_GET_COPY( shader*, shader_index     );
BD_DATA_GET_COPY( shader*, shader_chroma    );
BD_DATA_GET_COPY( shader*, shader_composite );
BD_DATA_GET_COPY( shader*, shader_luma      );

BD_DATA_GET_COPY_INIT( buffer*, buffer_canvas,    NULL );
BD_DATA_GET_COPY_INIT( buffer*, buffer_index,     NULL );
BD_DATA_GET_COPY_INIT( buffer*, buffer_chroma,    NULL );
BD_DATA_GET_COPY_INIT( buffer*, buffer_composite, NULL );
BD_DATA_GET_COPY_INIT( buffer*, buffer_luma,      NULL );

BD_DATA_GET_COPY_INIT( pipeline*, pipe, NULL );

// initialization functions (video_handler_init.cpp)

result initialize ( parameters* handler_parameters );
result shutdown   ();

result init_video_context  ();
result init_video_version  ();
result init_video_glew     ();
result init_video_ext      ();
result init_video_gl       ();
result init_video_shaders  ();

result kill_video_context ();

result initialize_pipeline ( s32 canvas_width, s32 canvas_height, bl using_index, bl using_ntsc );

// core functions (video_handler_core.cpp)

result check_ext ( bl log_error, cstr extension );

result set_vsync (          );
result set_vsync ( bl vsync );

result render ();

#include "core/local_close.hpp"

/* video handling function macro definitions */

#define USING_VIDEO ( video::get_subsystem_state() != SUBSYS_UNUSED )

/* end */

}
}

#endif
