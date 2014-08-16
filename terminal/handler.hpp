
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_TERMINAL_HANDLER_HPP
#define BDAPI_TERMINAL_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

// curses
namespace curses
{
#include "curses.h"
}

/* namespaces */
namespace bdapi    {
namespace terminal {

/* terminal handler parameters struct declaration */

struct parameters
{
	bl automatic;
	bl scrolling;

	s32 width;
	s32 height;
};

/* terminal handler singleton declaration */

#ifdef  BD_DATA_TERMINAL
#define BD_DATA_EXTERN
#endif
#include "core/local_open.hpp"

// initialization data

BD_DATA_GET_COPY_INIT_SET( subsys, subsystem_state, SUBSYS_UNUSED );

BD_DATA_GET_COPY( parameters*, handler_parameters );

// terminal data

BD_DATA_IS_COPY( bl, automatic );
BD_DATA_IS_COPY( bl, scrolling );

BD_DATA_GET_COPY( s32, width  );
BD_DATA_GET_COPY( s32, height );

BD_DATA_GET_COPY( s32, last_key       );
BD_DATA_GET_COPY( s32, last_character );

BD_DATA_GET_COPY( s32, cursor_x );
BD_DATA_GET_COPY( s32, cursor_y );

// terminal mouse data

BD_DATA_GET_COPY( s32, mouse_x );
BD_DATA_GET_COPY( s32, mouse_y );

BD_DATA_GET_COPY( s32, left_button_state  );
BD_DATA_GET_COPY( s32, right_button_state );

// terminal color data

BD_DATA_GET_COPY( s32, background_color );
BD_DATA_GET_COPY( s32, foreground_color );

BD_DATA_GET_COPY( curses::chtype**, chtype_color_pairs );

// initialization functions (terminal_handler_init.cpp)

result initialize ( parameters* handler_parameters );
result shutdown   ();

result init_handle ();
result init_params ();
result init_color  ();
result init_title  ();

// core functions (terminal_handler_core.cpp)

void scroll        (               );
void scroll        ( s32 amount    );
void set_automatic (  bl automatic );
void set_scrolling (  bl scrolling );

void clear   ();
void refresh ();

void set_color (                                );
void set_color (                 s32 foreground );
void set_color ( s32 background, s32 foreground );

void move (              );
void move ( s32 x, s32 y );

void shift_x ( s32 x        );
void shift_y (        s32 y );
void shift   ( s32 x, s32 y );

void draw (                             s32 c );
void draw ( s32 x, s32 y,               s32 c );
void draw ( s32 x, s32 y, s32 b, s32 f, s32 c );

void write (               cstr input, ... );
void write ( s32 x, s32 y, cstr input, ... );

// query functions (terminal_handler_query.cpp)

bl   is_left_held      ();
bl   is_left_pressed   ();
s32 get_left_duration  ();

bl   is_right_held     ();
bl   is_right_pressed  ();
s32 get_right_duration ();

// iteration functions (terminal_handler_iterate.cpp)

result frame_begin  ();
result frame_finish ();

#include "core/local_close.hpp"

/* terminal handling function macro definitions */

#define USING_TERMINAL ( terminal::get_subsystem_state() != SUBSYS_UNUSED )

/* end */

}
}

#endif
