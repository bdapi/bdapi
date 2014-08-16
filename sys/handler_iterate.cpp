
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_HANDLER_ITERATE_CPP
#define BDAPI_SYS_HANDLER_ITERATE_CPP
#define BD_DATA_SYS
#include "sys/handler.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"
#include "gamepad/handler.hpp"
#include "keyboard/handler.hpp"
#include "logging/handler.hpp"
#include "logging/message.hpp"
#include "math/core.hpp"
#include "mouse/handler.hpp"
#include "util/statehandler.hpp"
#include "sys/timer.hpp"
#include "terminal/handler.hpp"
#include "window/handler.hpp"

/* namespaces */
namespace bdapi {
namespace sys   {

/* system handler singleton iteration function implementations */

// private frame begin
result frame_begin()
{
	if( USING_TERMINAL && terminal::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		terminal::frame_begin();
	}

	if( USING_WINDOW && window::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		window::frame_begin();
	}

	if( USING_KEYBOARD && keyboard::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		keyboard::frame_begin();
	}

	if( USING_MOUSE && mouse::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		mouse::frame_begin();
	}

	if( USING_GAMEPAD && gamepad::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		gamepad::frame_begin();
	}

	return 1;
}

// private frame iterate
result frame_iterate()
{
	return state_handler->do_iterate();
}

// private frame finish
result frame_finish()
{
	if( USING_TERMINAL && terminal::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		terminal::frame_finish();
	}

	if( USING_WINDOW && window::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		window::frame_finish();
	}

	if( USING_KEYBOARD && keyboard::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		keyboard::frame_finish();
	}

	if( USING_MOUSE && mouse::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		mouse::frame_finish();
	}

	if( USING_GAMEPAD && gamepad::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		gamepad::frame_finish();
	}

	update_timing();

	return 1;
}

// private update timing
result update_timing()
{
	f64 iteration_time = frame_timer->stop();

	frame_timer->start();

	if( delta_list.get_size() >= samples )
	{
		delta_list.pop_front();
	}

	delta_list.insert( iteration_time );

	f64 average_delta = 0.0;

	for_i( delta_list )
	{
		average_delta += *i;
	}

	average_delta /= delta_list.get_size();

	delta = average_delta;

	if( fps_timer->get_elapsed() >= 0.25 )
	{
		fps_timer->start();

		fps = math::divide<f64>( 1.0, delta );
	}

	current_frame++;
	total_frames++;

	return 1;
}

// run
result run()
{
	if( handler_parameters->function_game_initialize )
	{
		string entry_string = str::format( "~FB%s", game_title.c_str() );

		LOG_ERROR( 1,
			entry_string.c_str(),
			"initializing ~~",
			"~~ initialization successful",
			"failed to initialize ~~" );
		LOG_RECEIVE( 1, (*handler_parameters->function_game_initialize)() )
		{
			return shutdown();
		}
	}

	game_initialized = true;

	state_handler = new util::statehandler();

	string entry_string = str::format( "~FB%s ~F3state handler", game_title.c_str() );

	LOG_ERROR( 2,
		entry_string.c_str(),
		"failed to initialize ~~" );
	LOG_RECEIVE( 2, handler_parameters->initial_state )
	{
		return shutdown();
	}

	state_handler->initialize( handler_parameters->initial_state );

	LOG_RECEIVE( 2, state_handler->do_initialize() )
	{
		return shutdown();
	}

	if( USING_WINDOW && window::get_subsystem_state() == SUBSYS_ACTIVE )
	{
		window::show();
	}

	LOG( "Entering ~FB%s ~F3main loop ~F8...", game_title.c_str() );

	LOG_OPEN();

	frame_timer->start();

	while( !shutting_down )
	{
		if( !frame_begin() )
		{
			WRITE_ERROR( "Failed to open frame ~X4E#%i~B0", total_frames );

			LOG_CLOSE();
			WRITE_ERROR( "~FB%s ~F3main loop ~F7terminated abnormally", game_title.c_str() );

			return shutdown();
		}

		if( shutting_down )
		{
			break;
		}

		if( !frame_iterate() )
		{
			WRITE_ERROR( "Failed to iterate frame ~X4E#%i~B0", total_frames );

			LOG_CLOSE();
			WRITE_ERROR( "~FB%s ~F3main loop ~F7terminated abnormally", game_title.c_str() );

			return shutdown();
		}

		if( shutting_down )
		{
			break;
		}

		if( !frame_finish() )
		{
			WRITE_ERROR( "Failed to close frame ~X4E#%i~B0", total_frames );

			LOG_CLOSE();
			WRITE_ERROR( "~FB%s ~F3main loop ~F7terminated abnormally", game_title.c_str() );

			return shutdown();
		}
	}

	LOG_CLOSE();
	LOG( "~FB%s ~F3main loop ~F7terminated normally ~F8...", game_title.c_str() );

	return shutdown();
}

// toggle shutdown
result toggle_shutdown()
{
	shutting_down = true;

	return 1;
}

/* end */

}
}

#endif
