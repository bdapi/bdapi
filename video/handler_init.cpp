
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_HANDLER_INIT_CPP
#define BDAPI_VIDEO_HANDLER_INIT_CPP
#define BD_DATA_VIDEO
#include "video/handler.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"
#include "logging/handler.hpp"
#include "logging/message.hpp"
#include "video/opengl.hpp"
#include "video/pipeline.hpp"
#include "window/handler.hpp"

/* namespaces */
namespace bdapi {
namespace video {

/* static variables */

static bool handler_instance = false;

/* video handler singleton initialization function implementations */

// private initializers
result initialize( parameters* handler_parameters )
{
	LOG_ERROR_1( "~F6subsystem", "~~ has already been initialized", !handler_instance );

	handler_instance = true;

	LOG_ERROR_1( "~F6subsystem parameters", "failed to read ~~", handler_parameters );

	video::handler_parameters = handler_parameters;

	subsystem_state = SUBSYS_INITIALIZED;

	LOG_ERROR_2(
		"~FEOpenGL ~F6context",
		"initializing ~~",
		"failed to initialize ~~",
		init_video_context() );

	LOG_ERROR_3(
		"~FEOpenGL ~F6version information",
		"reading ~~",
		"~~ analysis complete",
		"failed to read ~~",
		init_video_version() );

	LOG_ERROR_2(
		"~FEGLEW ~F6library",
		"initializing ~~",
		"failed to initialize ~~",
		init_video_glew() );

	LOG_ERROR_3(
		"~FEOpenGL ~F6extensions",
		"checking for required ~~",
		"all required ~~ are available",
		"not all required ~~ are available",
		init_video_ext() );

	LOG_ERROR_1(
		"~FEOpenGL ~F6subsystem",
		"failed to initialize ~~",
		init_video_gl() );

	LOG_ERROR_3(
		"~F6shaders",
		"initializing ~~",
		"~~ initialization complete",
		"failed to initialize ~~",
		init_video_shaders() );

	if( using_pipeline )
	{
		LOG_ERROR_2(
			"~F6pipeline",
			"initializing ~~",
			"failed to initialize ~~",
			initialize_pipeline( canvas_width, canvas_height, using_index, using_ntsc ) );
	}

	subsystem_state = SUBSYS_ACTIVE;

	return 1;
}

// private shutdown
result shutdown()
{
	subsystem_state = SUBSYS_SUSPENDED;

	LOG_WARNING_1(
		"OpenGL context",
		"failed to destroy ~~",
		kill_video_context() );

	subsystem_state = SUBSYS_SHUTDOWN;

	return 1;
}

// private initialize opengl context
result init_video_context()
{
	SDL_GL_SetAttribute( SDL_GL_ACCELERATED_VISUAL,     1 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION,  2 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION,  1 );
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE,            16 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER,           1 );
	SDL_GL_SetAttribute( SDL_GL_MULTISAMPLEBUFFERS,     0 );
	SDL_GL_SetAttribute( SDL_GL_MULTISAMPLESAMPLES,     0 );
	SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE,           8 );
	SDL_GL_SetAttribute( SDL_GL_STEREO,                 0 );

	sdl_gl_context = new SDL_GLContext();

	*sdl_gl_context = SDL_GL_CreateContext( window::get_sdl_window() );

	return 1;
}

// private initialize opengl version
result init_video_version()
{
	gl_renderer = (char*)glGetString( GL_RENDERER );
	gl_vendor   = (char*)glGetString( GL_VENDOR   );
	gl_version  = (char*)glGetString( GL_VERSION  );

	string log_gl_renderer = gl_renderer;
	string log_gl_vendor   = gl_vendor;
	string log_gl_version  = gl_version;

	log_gl_renderer = str::replace( log_gl_renderer, ".",  "~F8.~FF" );
	log_gl_renderer = str::replace( log_gl_renderer, "/",  "~F8/~FF" );
	log_gl_renderer = str::replace( log_gl_renderer, "\\", "~F8/~FF" );

	log_gl_vendor   = str::replace( log_gl_vendor,   ".",  "~F8.~FF" );
	log_gl_vendor   = str::replace( log_gl_vendor,   "/",  "~F8/~FF" );
	log_gl_vendor   = str::replace( log_gl_vendor,   "\\", "~F8/~FF" );

	log_gl_version  = str::replace( log_gl_version,  ".",  "~F8.~FF" );
	log_gl_version  = str::replace( log_gl_version,  "/",  "~F8/~FF" );
	log_gl_version  = str::replace( log_gl_version,  "\\", "~F8/~FF" );

	SDL_GL_GetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, &gl_version_major );
	SDL_GL_GetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, &gl_version_minor );

	LOG( "~FCRENDERER~F8: ~FF%s",                  log_gl_renderer.c_str()    );
	LOG( "~FCVENDOR~F8:   ~FF%s",                  log_gl_vendor.c_str()      );
	LOG( "~FCVERSION~F8:  ~FF%s",                  log_gl_version.c_str()     );
	LOG( "~FCPROFILE~F8:  ~FF%i~F8.~FF%i~F8.~FF0", gl_version_major, gl_version_minor );

	return 1;
}

// private initialize glew
result init_video_glew()
{
	if( glewInit() != GLEW_OK )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// private initialize opengl extensions
result init_video_ext()
{
	if( !check_ext( true, "GL_ARB_fragment_program"         ) ) return 0;
	if( !check_ext( true, "GL_ARB_fragment_shader"          ) ) return 0;
	if( !check_ext( true, "GL_ARB_multitexture"             ) ) return 0;
	if( !check_ext( true, "GL_ARB_texture_non_power_of_two" ) ) return 0;
	if( !check_ext( true, "GL_ARB_vertex_program"           ) ) return 0;
	if( !check_ext( true, "GL_ARB_vertex_shader"            ) ) return 0;
	if( !check_ext( true, "GL_EXT_framebuffer_object"       ) ) return 0;

	if( SDL_GL_GetSwapInterval() == -1 )
	{
		vsync_available = false;
		vsync_active    = false;

		WRITE_WARNING( "~FCVertical synchronization ~F7is unavailable" );
	}
	else
	{
		vsync_available = true;

		LOG( "~FCVertical synchronization ~F7is available~F8." );

		if( handler_parameters->use_vsync )
		{
			set_vsync( true );
		}
		else
		{
			set_vsync( false );
		}
	}

	return 1;
}

// private initialize opengl subsystem
result init_video_gl()
{
	gl::initialize();

	default_filtered  = handler_parameters->default_filtered;
	default_mipmapped = handler_parameters->default_mipmapped;
	default_clamped   = handler_parameters->default_clamped;

	using_blitter = handler_parameters->using_blitter;
	using_index   = handler_parameters->using_index;
	using_ntsc    = handler_parameters->using_ntsc;

	using_pipeline = handler_parameters->using_pipeline;

	canvas_width  = handler_parameters->canvas_width;
	canvas_height = handler_parameters->canvas_height;

	return 1;
}

// private initialize shaders
result init_video_shaders()
{
	shader_default = new shader();

	LOG_ERROR_2(
		"~FCdefault shader",
		"loading ~~",
		"failed to loading ~~",
		shader_default->initialize(
			"data/filter_core_default.bdvrt",
			"data/filter_core_default.bdfrg" ) );

	if( using_blitter )
	{
		shader_blitter = new shader();

		LOG_ERROR_2(
			"~FCblitter shader",
			"loading ~~",
			"failed to loading ~~",
			shader_blitter->initialize(
				shader_default,
				"data/filter_core_blitter.bdfrg" ) );
	}

	if( using_index )
	{
		shader_index = new shader();

		LOG_ERROR_2(
			"~FCindex shader",
			"loading ~~",
			"failed to loading ~~",
			shader_index->initialize(
				shader_default,
				"data/filter_core_index.bdfrg" ) );
	}

	if( using_ntsc )
	{
		shader_chroma    = new shader();
		shader_composite = new shader();
		shader_luma      = new shader();

		LOG_ERROR_2(
			"~FCchroma shader",
			"loading ~~",
			"failed to loading ~~",
			shader_chroma->initialize(
				"data/filter_core_chroma.bdvrt",
				"data/filter_core_chroma.bdfrg" ) );

		LOG_ERROR_2(
			"~FCcomposite shader",
			"loading ~~",
			"failed to loading ~~",
			shader_composite->initialize(
				"data/filter_core_composite.bdvrt",
				"data/filter_core_composite.bdfrg" ) );

		LOG_ERROR_2(
			"~FCluma shader",
			"loading ~~",
			"failed to loading ~~",
			shader_luma->initialize(
				shader_default,
				"data/filter_core_luma.bdfrg" ) );
	}

	return 1;
}

// private destroy opengl context
result kill_video_context()
{
	SDL_GL_DeleteContext( &sdl_gl_context );

	delete sdl_gl_context;

	return 1;
}

// initialize pipeline
result initialize_pipeline( s32 canvas_width, s32 canvas_height, bl using_index, bl using_ntsc )
{
	video::canvas_width  = canvas_width;
	video::canvas_height = canvas_height;

	video::using_index = using_index;
	video::using_ntsc  = using_ntsc;

	if( gl::get_current_image() != NULL )
	{
		gl::get_current_image()->unbind();
	}

	if( gl::get_current_buffer() != NULL )
	{
		gl::get_current_buffer()->deactivate();
	}

	if( gl::get_current_shader() != NULL )
	{
		gl::get_current_shader()->stop();
	}

	DEL( buffer_canvas    );
	DEL( buffer_index     );
	DEL( buffer_chroma    );
	DEL( buffer_composite );
	DEL( buffer_luma      );

	DEL( pipe );

	buffer_canvas = new video::buffer();

	//if( !buffer_canvas->initialize( canvas_width, canvas_height, 3, false, false, true ) )
	if( !buffer_canvas->initialize( canvas_width, canvas_height, 3, true, false, true ) )
	{
		return 0;
	}

	pipe = new video::pipeline();

	pipe->add_shader( NULL );
	pipe->add_buffer( buffer_canvas );

	if( using_index )
	{
		buffer_index = new video::buffer();

		if( !buffer_index->initialize( canvas_width, canvas_height, 3, true, false, true ) )
		{
			return 0;
		}

		pipe->add_shader( shader_index );
		pipe->add_buffer( buffer_index );
	}

	if( using_ntsc )
	{
		buffer_chroma    = new video::buffer();
		buffer_composite = new video::buffer();
		buffer_luma      = new video::buffer();

		if( !buffer_chroma->initialize( canvas_width * 4, canvas_height, 3, true, false, true ) )
		{
			return 0;
		}

		if( !buffer_composite->initialize( canvas_width * 4, canvas_height, 3, true, false, true ) )
		{
			return 0;
		}

		if( !buffer_luma->initialize( canvas_width * 4, canvas_height, 3, true, false, true ) )
		{
			return 0;
		}

		pipe->add_shader( shader_chroma );
		pipe->add_buffer( buffer_chroma );

		pipe->add_shader( shader_composite );
		pipe->add_buffer( buffer_composite );

		pipe->add_shader( shader_luma );
		pipe->add_buffer( buffer_luma );
	}

	return 1;
}

/* end */

}
}

#endif
