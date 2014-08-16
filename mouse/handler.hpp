
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MOUSE_HANDLER_HPP
#define BDAPI_MOUSE_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

// sdl
#include "SDL_events.h"

// bdapi
#include "string/string.hpp"

/* namespaces */
namespace bdapi {
namespace mouse {

/* mouse button struct declaration */

struct button
{
	s32 button_code = -1;

	string name;

	s32 frame_count = -1;
	f64 delta_count = -1.0;
};

/* mouse handler parameters struct declaration */

struct parameters
{
	bl visible = true;
	bl locked  = false;
};

/* mouse handler singleton declaration */

#ifdef  BD_DATA_MOUSE
#define BD_DATA_EXTERN
#endif
#include "core/local_open.hpp"

// initialization data

BD_DATA_GET_COPY_INIT_SET( subsys, subsystem_state, SUBSYS_UNUSED );

BD_DATA_GET_COPY( parameters*, handler_parameters );

// core data

BD_DATA_GET_COPY( s32, rotation );

BD_DATA_GET_COPY( bl, default_visibility );
BD_DATA_GET_COPY( bl, default_lock_state );

BD_DATA_IS_COPY( bl, visible );
BD_DATA_IS_COPY( bl, locked  );
BD_DATA_IS_COPY( bl, inside  );

BD_DATA_HAS_COPY( bl, activity );

BD_DATA_GET_COPY( button*, buttons );

BD_DATA_GET_COPY( s32, current_x_internal  );
BD_DATA_GET_COPY( s32, current_y_internal  );
BD_DATA_GET_COPY( s32, previous_x_internal );
BD_DATA_GET_COPY( s32, previous_y_internal );
BD_DATA_GET_COPY( s32, movement_x_internal );
BD_DATA_GET_COPY( s32, movement_y_internal );

// initialization functions (mouse_handler_init.cpp)

result initialize ( parameters* handler_parameters );
result shutdown   ();

// core functions (mouse_handler_core.cpp)

bl check ( s32 i );

result button_down ( s32 i );
result button_up   ( s32 i );

result move ( s32 x, s32 y );

result rotate ( s32 i );

result set_inside ( bl );

result show ();
result hide ();

result lock   ();
result unlock ();

result set_position ( s32 x, s32 y );

// event functions (mouse_handler_event.cpp)

result process_event_button ( SDL_MouseButtonEvent& sdl_mouse_button_event );
result process_event_motion ( SDL_MouseMotionEvent& sdl_mouse_motion_event );
result process_event_wheel  ( SDL_MouseWheelEvent&  sdl_mouse_wheel_event  );

// iteration functions (mouse_handler_iterate.cpp)

result frame_begin  ();
result frame_finish ();

// query functions (mouse_handler_query.cpp)

bl held     ( s32 i );
bl pressed  ( s32 i );
bl released ( s32 i );

s32 get_frame_count ( s32 i );
f64 get_delta_count ( s32 i );

f32 get_current_x  (                 );
f32 get_current_x  ( bl frame_buffer );
f32 get_current_y  (                 );
f32 get_current_y  ( bl frame_buffer );
f32 get_previous_x (                 );
f32 get_previous_x ( bl frame_buffer );
f32 get_previous_y (                 );
f32 get_previous_y ( bl frame_buffer );
f32 get_movement_x (                 );
f32 get_movement_x ( bl frame_buffer );
f32 get_movement_y (                 );
f32 get_movement_y ( bl frame_buffer );

const button& get_button ( s32 i );

#include "core/local_close.hpp"

/* mouse handling function macro definitions */

#define USING_MOUSE ( mouse::get_subsystem_state() != SUBSYS_UNUSED )

#undef MB_LEFT
#undef MB_MIDDLE
#undef MB_RIGHT
#undef MB_X1
#undef MB_X2

#define MB_LEFT   1 //SDL_BUTTON(SDL_BUTTON_LEFT)
#define MB_MIDDLE 2 //SDL_BUTTON(SDL_BUTTON_MIDDLE)
#define MB_RIGHT  3 //SDL_BUTTON(SDL_BUTTON_RIGHT)
#define MB_X1     4 //SDL_BUTTON(SDL_BUTTON_X1)
#define MB_X2     5 //SDL_BUTTON(SDL_BUTTON_X2)

/* end */

}
}

#endif
