
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_KEYBOARD_HANDLER_HPP
#define BDAPI_KEYBOARD_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

// sdl
#include "SDL_events.h"

// bdapi
#include "keyboard/codes.hpp"
#include "string/string.hpp"

/* namespaces */
namespace bdapi    {
namespace keyboard {

/* key struct declaration */

struct key
{
	s32 scan_code = -1;
	s32 key_code  = -1;

	string name;

	s32 frame_count  = -1;
	s32 repeat_count = -1;
	f64 delta_count  = -1.0;
};

/* keyboard handler parameters struct declaration */

struct parameters
{
};

/* keyboard handler singleton declaration */

#ifdef  BD_DATA_KEYBOARD
#define BD_DATA_EXTERN
#endif
#include "core/local_open.hpp"

// initialization data

BD_DATA_GET_COPY_INIT_SET( subsys, subsystem_state, SUBSYS_UNUSED );

BD_DATA_GET_COPY( parameters*, handler_parameters );

// core data

BD_DATA_HAS_COPY( bl, focus      );
BD_DATA_HAS_COPY( bl, activity   );
BD_DATA_HAS_COPY( bl, text_input );

BD_DATA_GET_COPY( key*, keys );

BD_DATA_GET_COPY( u8,         u8_text_input );
BD_DATA_GET_COPY( string, string_text_input );

// hidden data

BD_DATA_GET_REFR( key, dummy_key );

// initialization functions (keyboard_handler_init.cpp)

result initialize ( parameters* handler_parameters );
result shutdown   ();

// core functions (keyboard_handler_core.cpp)

bl check ( s32 k );

result key_down ( s32 i );
result key_up   ( s32 i );

result set_focus ( bl focus );

// event functions (keyboard_handler_event.cpp)

result process_event ( SDL_KeyboardEvent&  sdl_keyboard_event   );
result process_event ( SDL_TextInputEvent& sdl_text_input_event );

// iteration functions (keyboard_handler_iterate.cpp)

result frame_begin  ();
result frame_finish ();

// query functions (keyboard_handler_query.cpp)

bl held     ( s32 k );
bl pressed  ( s32 k );
bl released ( s32 k );
bl repeated ( s32 k );

s32 get_frame_count  ( s32 k );
s32 get_repeat_count ( s32 k );
f64 get_delta_count  ( s32 k );

u8     get_input_char   ( bl last );
u8     get_input_char   (         );
string get_input_string ( bl last );
string get_input_string (         );
s32    get_input_size   ( bl last );
s32    get_input_size   (         );

u8     get_last_input_char   ();
string get_last_input_string ();
s32    get_last_input_size   ();

const key& get_key ( s32 k );

#include "core/local_close.hpp"

/* keyboard handling function macro definitions */

#define USING_KEYBOARD ( keyboard::get_subsystem_state() != SUBSYS_UNUSED )

/* end */

}
}

#endif
