
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_HANDLER_INIT_CPP
#define BDAPI_SYS_HANDLER_INIT_CPP
#define BD_DATA_GLOBAL
#include "sys/handler.hpp"

/* includes */

// boost
#include "boost/program_options/options_description.hpp"
#include "boost/program_options/parsers.hpp"
#include "boost/program_options/variables_map.hpp"

// sdl
#include "SDL.h"

// bdapi
#include "audio/handler.hpp"
#include "core/platform.hpp"
#include "display/handler.hpp"
#include "error/handler.hpp"
#include "gamepad/handler.hpp"
#include "keyboard/handler.hpp"
#include "logging/handler.hpp"
#include "logging/message.hpp"
#include "mouse/handler.hpp"
#include "sys/timedata.hpp"
#include "sys/timer.hpp"
#include "terminal/handler.hpp"
#include "util/statehandler.hpp"
#include "video/handler.hpp"
#include "window/handler.hpp"

/* namespaces */
namespace bdapi {
namespace sys   {

/* static variables */

static bool handler_instance = false;

/* system handler singleton initialization function implementations */

// initializers
result initialize( parameters* handler_parameters )
{
	if( handler_instance == true ) return 0;

	handler_instance = true;

	if( handler_parameters == NULL ) return 0;

	sys::handler_parameters = handler_parameters;

	if( !init_subsystems_1() ) return 0;
	if( !init_timing()       ) return 0;
	if( !init_command_line() ) return 0;
	if( !init_descriptors()  ) return 0;

	subsystem_state = SUBSYS_INITIALIZED;

	if( !init_logging() ) return 0;

	string entry_string = str::format( "~FB%s", engine_title.c_str() );

	LOG_ERROR_3(
		entry_string.c_str(),
		"initializing ~~",
		"~~ initialization successful",
		"failed to initialize ~~",
		init_subsystems_2() );

	if( handler_parameters->run_after_initialization )
	{
		return run();
	}
	else
	{
		return 1;
	}
}

// shutdown
result shutdown()
{
	subsystem_state = SUBSYS_SUSPENDED;

	if( USING_AUDIO && audio::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		audio::mute();
	}

	if( USING_WINDOW && window::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		window::hide();
	}

	if( (  handler_parameters->function_game_initialize
	&&     handler_parameters->function_game_shutdown && game_initialized )
	||  ( !handler_parameters->function_game_initialize
	&&     handler_parameters->function_game_shutdown ) )
	{
		string entry_string = str::format( "~FB%s", game_title.c_str() );

		LOG_WARNING_3(
			entry_string.c_str(),
			"shutting down ~~",
			"~~ shut down normally",
			"~~ shut down abnormally",
			(*handler_parameters->function_game_shutdown)() );
	}

	string entry_string = str::format( "~FB%s", engine_title.c_str() );

	LOG_WARNING( 1,
		entry_string.c_str(),
		"shutting down ~~",
		"~~ shut down normally",
		"~~ shut down abnormally" );

	if( USING_AUDIO && audio::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		LOG_WARNING_2(
			"~FAaudio ~F2handling subsystem",
			"shutting down ~~",
			"~~ shut down abnormally",
			audio::shutdown() );
	}

	if( USING_VIDEO && video::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		LOG_WARNING_2(
			"~FAvideo ~F2handling subsystem",
			"shutting down ~~",
			"~~ shut down abnormally",
			video::shutdown() );
	}

	if( USING_GAMEPAD && gamepad::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		LOG_WARNING_2(
			"~FAgamepad ~F2handling subsystem",
			"shutting down ~~",
			"~~ shut down abnormally",
			gamepad::shutdown() );
	}

	if( USING_MOUSE && mouse::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		LOG_WARNING_2(
			"~FAmouse ~F2handling subsystem",
			"shutting down ~~",
			"~~ shut down abnormally",
			mouse::shutdown() );
	}

	if( USING_KEYBOARD && keyboard::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		LOG_WARNING_2(
			"~FAkeyboard ~F2handling subsystem",
			"shutting down ~~",
			"~~ shut down abnormally",
			keyboard::shutdown() );
	}

	if( USING_WINDOW && window::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		LOG_WARNING_2(
			"~FAwindow ~F2handling subsystem",
			"shutting down ~~",
			"~~ shut down abnormally",
			window::shutdown() );
	}

	if( USING_DISPLAY && display::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		LOG_WARNING_2(
			"~FAdisplay ~F2handling subsystem",
			"shutting down ~~",
			"~~ shut down abnormally",
			display::shutdown() );
	}

	if( USING_TERMINAL && terminal::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		terminal::refresh();
	}

	s32 shutdown_result = 0;

	if( ERROR_EXISTS && error::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		shutdown_result = 1;
	}

	if( shutdown_result == 0 )
	{
		LOG_RETURN( 1, true );
	}
	else
	{
		LOG_RETURN( 1, false );
	}

	LOG_CLOSE();

	finish_time = new sys::timedata();

	if( USING_LOGGING && logging::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		LOG( "Session closed with ~F9exit code ~FF%u ~F7on ~FF%04u~F7-~FF%02u~F7-~FF%02u ~F7at "
			"~FF%02u~F7:~FF%02u~F7:~FF%02u",
			shutdown_result,
			finish_time->get_year(),
			finish_time->get_month(),
			finish_time->get_day(),
			finish_time->get_hour(),
			finish_time->get_minute(),
			finish_time->get_second() );
	}

	if( USING_LOGGING && logging::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		logging::shutdown();
	}

	if( USING_TERMINAL && terminal::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		terminal::shutdown();
	}

	if( USING_ERROR && error::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		if( error::get_handler_parameters()->shutdown_report )
		{
			error::generate_report();
		}

		error::shutdown();
	}

	DEL( start_time  );
	DEL( finish_time );

	DEL( global_timer );
	DEL( frame_timer  );

	DEL( open_timer );
	DEL( fps_timer  );

	DEL( state_handler );

	subsystem_state = SUBSYS_SHUTDOWN;

	return shutdown_result;
}

// private initialize subsystems 1
result init_subsystems_1()
{
	if( handler_parameters->error_parameters != NULL )
	{
		error::set_subsystem_state(SUBSYS_USED);
	}

	if( handler_parameters->terminal_parameters != NULL )
	{
		terminal::set_subsystem_state(SUBSYS_USED);
	}

	if( handler_parameters->logging_parameters != NULL )
	{
		logging::set_subsystem_state(SUBSYS_USED);
	}

	if( handler_parameters->display_parameters != NULL )
	{
		display::set_subsystem_state(SUBSYS_USED);
	}

	if( handler_parameters->window_parameters != NULL )
	{
		window::set_subsystem_state(SUBSYS_USED);
	}

	if( handler_parameters->keyboard_parameters != NULL )
	{
		keyboard::set_subsystem_state(SUBSYS_USED);
	}

	if( handler_parameters->mouse_parameters != NULL )
	{
		mouse::set_subsystem_state(SUBSYS_USED);
	}

	if( handler_parameters->gamepad_parameters != NULL )
	{
		gamepad::set_subsystem_state(SUBSYS_USED);
	}

	if( handler_parameters->video_parameters != NULL )
	{
		video::set_subsystem_state(SUBSYS_USED);
	}

	if( handler_parameters->audio_parameters != NULL )
	{
		audio::set_subsystem_state(SUBSYS_USED);
	}

	return 1;
}

// private initialize timing
result init_timing()
{
	start_time = new sys::timedata();

	global_timer = new sys::timer();
	frame_timer  = new sys::timer();

	fps_timer = new sys::timer();

	samples = 24;

	delta_list.initialize( 1, 1.0 / (f64)samples );

	return 1;
}

// private initialize command line
result init_command_line()
{
	argc = handler_parameters->argc;
	argv = handler_parameters->argv;

	using namespace boost::program_options;

	parsed_options command_line_pars = command_line_parser( argc, argv ).options(
		options_description("") ).allow_unregistered().run();

	command_line_args.data = collect_unrecognized( command_line_pars.options, include_positional );

	return 1;
}

// private initialize descriptors
result init_descriptors()
{
	#if WIN

	compiler_title      = "Microsoft C/C++ Optimizing Compiler";
	compiler_version    = "18.00.21005.1";

	#elif MAC

	#warning "Macintosh compiler unspecified."

	compiler_title      = "";
	compiler_version    = "";

	#elif NIX

	#warning "Unix compiler unspecified."

	compiler_title      = "";
	compiler_version    = "";

	#elif PS4

	#warning "PlayStation 4 compiler unspecified."

	compiler_title      = "";
	compiler_version    = "";

	#elif XBO

	#warning "Xbox One compiler unspecified."

	compiler_title      = "";
	compiler_version    = "";

	#elif WII

	#warning "Wii compiler unspecified."

	compiler_title      = "";
	compiler_version    = "";

	#endif

	compiler_full_title = compiler_title + " " + compiler_version;

	framework_title   = "Brain Damage API";
	framework_version = str::format( "%u.%u.%u",
		BDAPI_VERSION_MAJOR,
		BDAPI_VERSION_MINOR,
		BDAPI_VERSION_PATCH );
	framework_full_title = framework_title + " " + framework_version;

	engine_title   = handler_parameters->engine_title;
	engine_version = str::format( "%u.%u.%u",
		handler_parameters->engine_version[0],
		handler_parameters->engine_version[1],
		handler_parameters->engine_version[2] );
	engine_full_title = engine_title + " " + engine_version;

	game_title   = handler_parameters->game_title;
	game_version = str::format( "%u.%u.%u",
		handler_parameters->game_version[0],
		handler_parameters->game_version[1],
		handler_parameters->game_version[2] );
	game_full_title = game_title + " " + game_version;

	return 1;
}

// priviate initialize logging
result init_logging()
{
	LOG( "~F9MODULE~F8:    ~FB%s ~FF%s",      game_title.c_str(),
		str::replace( game_version,      ".", "~F8.~FF"  ).c_str() );

	LOG( "~F9ENGINE~F8:    ~FB%s ~FF%s",    engine_title.c_str(),
		str::replace( engine_version,    ".", "~F8.~FF"  ).c_str() );

	LOG( "~F9FRAMEWORK~F8: ~FB%s ~FF%s", framework_title.c_str(),
		str::replace( framework_version, ".", "~F8.~FF"  ).c_str() );

	LOG( "~F9COMPILER~F8:  ~FB%s ~FF%s",  compiler_title.c_str(),
		str::replace( compiler_version,  ".", "~F8.~FF"  ).c_str() );

	LOG( "Session opened on ~FF%04i~F8-~FF%02i~F8-~FF%02i ~F7at ~FF%02i~F8:~FF%02i~F8:~FF%02i",
		start_time->get_year(),
		start_time->get_month(),
		start_time->get_day(),
		start_time->get_hour(),
		start_time->get_minute(),
		start_time->get_second() );

	LOG_OPEN();

	return 1;
}

// private initialize sdl
result init_sdl()
{
	SDL_ClearError();

	if( SDL_Init(0) < 0 )
	{
		WRITE_ERROR( "%s", SDL_GetError() );

		return 0;
	}

	return 1;
}

// private initialize subsystems 2
result init_subsystems_2()
{
	if( USING_ERROR )
	{
		LOG_ERROR_2(
			"~FAerror ~F2handling subsystem",
			"initializing ~~",
			"failed to initialize ~~",
			error::initialize( handler_parameters->error_parameters ) );
	}

	if( USING_TERMINAL )
	{
		LOG_ERROR_2(
			"~FAterminal ~F2handling subsystem",
			"initializing ~~",
			"failed to initialize ~~",
			terminal::initialize( handler_parameters->terminal_parameters ) );
	}

	if( USING_LOGGING )
	{
		LOG_ERROR_3(
			"~FAlog ~F2handling subsystem",
			"initializing ~~",
			"~~ initialization successful",
			"failed to initialize ~~",
			logging::initialize( handler_parameters->logging_parameters ) );
	}

	if( USING_DISPLAY || USING_WINDOW || USING_KEYBOARD || USING_MOUSE || USING_GAMEPAD || USING_VIDEO
	||  USING_AUDIO )
	{
		LOG_ERROR_2(
			"~FASDL ~F2library",
			"initializing ~~",
			"failed to initialize ~~",
			init_sdl() );
	}

	if( USING_DISPLAY )
	{
		LOG_ERROR_3(
			"~FAdisplay ~F2handling subsystem",
			"initializing ~~",
			"~~ initialization successful",
			"failed to initialize ~~",
			display::initialize( handler_parameters->display_parameters ) );
	}

	if( USING_WINDOW )
	{
		LOG_ERROR_3(
			"~FAwindow ~F2handling subsystem",
			"initializing ~~",
			"~~ initialization successful",
			"failed to initialize ~~",
			window::initialize( handler_parameters->window_parameters ) );
	}

	if( USING_KEYBOARD )
	{
		LOG_ERROR_2(
			"~FAkeyboard ~F2handling subsystem",
			"initializing ~~",
			"failed to initialize ~~",
			keyboard::initialize( handler_parameters->keyboard_parameters ) );
	}

	if( USING_MOUSE )
	{
		LOG_ERROR_2(
			"~FAmouse ~F2handling subsystem",
			"initializing ~~",
			"failed to initialize ~~",
			mouse::initialize( handler_parameters->mouse_parameters ) );
	}

	if( USING_GAMEPAD )
	{
		LOG_ERROR_2(
			"~FAgamepad ~F2handling subsystem",
			"initializing ~~",
			"failed to initialize ~~",
			gamepad::initialize( handler_parameters->gamepad_parameters ) );
	}

	if( USING_VIDEO )
	{
		LOG_ERROR_3(
			"~FAvideo ~F2handling subsystem",
			"initializing ~~",
			"~~ initialization successful",
			"failed to initialize ~~",
			video::initialize( handler_parameters->video_parameters ) );
	}

	if( USING_AUDIO )
	{
		LOG_ERROR_3(
			"~FAaudio ~F2handling subsystem",
			"initializing ~~",
			"~~ initialization successful",
			"failed to initialize ~~",
			audio::initialize( handler_parameters->audio_parameters ) );
	}

	return 1;
}

/* end */

}
}

#endif
