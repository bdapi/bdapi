
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_WINDOW_HANDLER_HPP
#define BDAPI_WINDOW_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

// sdl
#include "SDL_events.h"

// bdapi
#include "string/string.hpp"

/* namespaces */
namespace bdapi  {
namespace window {

/* window handler parameter struct declaration */

struct parameters
{
};

/* window handler singleton declaration */

#ifdef  BD_DATA_WINDOW
#define BD_DATA_EXTERN
#endif
#include "core/local_open.hpp"

// initialization data

BD_DATA_GET_COPY_INIT_SET( subsys, subsystem_state, SUBSYS_UNUSED );

BD_DATA_GET_COPY( parameters*, handler_parameters );

// core data

BD_DATA_GET_COPY( SDL_Window*, sdl_window );

// initialization functions (window_handler_init.cpp)

result initialize ( parameters* handler_parameters );
result shutdown   ();

result init_window ();

// core functions (window_handler_core.cpp)

result raise   ();
result restore ();

result maximize ();
result minimize ();

result show ();
result hide ();

result set_position ( s32 x,     s32 y      );
result set_size     ( s32 width, s32 height );
result set_title    ( string title          );

// event functions (window_handler_event.cpp)

result process_event ( SDL_DropEvent&        sdl_drop_event         );
result process_event ( SDL_SysWMEvent&       sdl_sys_wm_event       );
result process_event ( SDL_TextEditingEvent& sdl_text_editing_event );
result process_event ( SDL_WindowEvent&      sdl_window_event       );

// iteration functions (window_handler_iterate.cpp)

result frame_begin  ();
result frame_finish ();

#include "core/local_close.hpp"

/* window handling function macro definitions */

#define USING_WINDOW ( window::get_subsystem_state() != SUBSYS_UNUSED )

/* end */

}
}

#endif
