
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_HANDLER_HPP
#define BDAPI_SYS_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "deque"
#include "vector"

// bdapi
#include "string/string.hpp"
#include "util/container.hpp"

/* namespaces */
namespace bdapi {
namespace sys   {

/* system handler typedef declarations */

typedef util::container<    f64, std::deque  > sys_f64_deque;
typedef util::container< string, std::vector > sys_string_vector;

/* system handler parameters struct declaration */

struct parameters
{
	int    argc = -1;
	char** argv = NULL;

	string game_title   = "";
	u8*    game_version = NULL;

	string engine_title   = "";
	u8*    engine_version = NULL;

	bl run_after_initialization = false;

	result (*function_game_initialize)() = NULL;
	result (*function_game_shutdown  )() = NULL;

	util::state* initial_state = NULL;

	error::parameters*    error_parameters    = NULL;
	terminal::parameters* terminal_parameters = NULL;
	logging::parameters*  logging_parameters  = NULL;
	display::parameters*  display_parameters  = NULL;
	window::parameters*   window_parameters   = NULL;
	keyboard::parameters* keyboard_parameters = NULL;
	mouse::parameters*    mouse_parameters    = NULL;
	gamepad::parameters*  gamepad_parameters  = NULL;
	video::parameters*    video_parameters    = NULL;
	audio::parameters*    audio_parameters    = NULL;
};

/* system handler singleton declaration */

#ifdef  BD_DATA_SYS
#define BD_DATA_EXTERN
#endif
#include "core/local_open.hpp"

// initialization data

BD_DATA_GET_COPY_INIT_SET( subsys, subsystem_state, SUBSYS_UNUSED );

BD_DATA_GET_COPY( parameters*, handler_parameters );

// time handling data

BD_DATA_GET_COPY( sys::timedata*, start_time  );
BD_DATA_GET_COPY( sys::timedata*, finish_time );

BD_DATA_GET_COPY( sys::timer*, global_timer );
BD_DATA_GET_COPY( sys::timer*, frame_timer  );

BD_DATA_GET_COPY( sys::timer*, open_timer );
BD_DATA_GET_COPY( sys::timer*, fps_timer  );

BD_DATA_GET_REFR( sys_f64_deque, delta_list );

BD_DATA_GET_COPY( f64, delta );
BD_DATA_GET_COPY( f64, fps   );

BD_DATA_GET_COPY( s32, samples );

BD_DATA_GET_COPY( s64, current_frame );
BD_DATA_GET_COPY( s64, total_frames  );

// command line parameter data

BD_DATA_GET_COPY( int,    argc );
BD_DATA_GET_COPY( char**, argv );

BD_DATA_GET_REFR( sys_string_vector, command_line_args );

// state data

BD_DATA_IS_COPY( bl, game_initialized );

BD_DATA_IS_COPY( bl, shutting_down );

BD_DATA_GET_COPY( util::statehandler*, state_handler );

// descriptor data

BD_DATA_GET_COPY( string, compiler_title      );
BD_DATA_GET_COPY( string, compiler_version    );
BD_DATA_GET_COPY( string, compiler_full_title );

BD_DATA_GET_COPY( string, framework_title      );
BD_DATA_GET_COPY( string, framework_version    );
BD_DATA_GET_COPY( string, framework_full_title );

BD_DATA_GET_COPY( string, engine_title      );
BD_DATA_GET_COPY( string, engine_version    );
BD_DATA_GET_COPY( string, engine_full_title );

BD_DATA_GET_COPY( string, game_title      );
BD_DATA_GET_COPY( string, game_version    );
BD_DATA_GET_COPY( string, game_full_title );

// initialization functions (sys_handler_init.cpp)

result initialize ( parameters* handler_parameters );
result shutdown   ();

result init_subsystems_1 ();
result init_timing       ();
result init_command_line ();
result init_descriptors  ();
result init_logging      ();
result init_sdl          ();
result init_subsystems_2 ();

// iteration functions (sys_handler_iterate.cpp)

result frame_begin   ();
result frame_iterate ();
result frame_finish  ();

result update_timing ();

result run ();

result toggle_shutdown ();

// command line parameter functions (sys_handler_command.cpp)

s32  get_clps (       );
cstr get_clp  ( s32 i );

bl check_clp ( string clp_substr );

#include "core/local_close.hpp"

/* system handling function macro definitions */

#define USING_SYS ( sys::get_subsystem_state() != SUBSYS_UNUSED )

/* end */

}
}

#endif
