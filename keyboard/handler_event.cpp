
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_KEYBOARD_HANDLER_EVENT_CPP
#define BDAPI_KEYBOARD_HANDLER_EVENT_CPP
#define BD_DATA_KEYBOARD
#include "keyboard/handler.hpp"

/* includes */

/* namespaces */
namespace bdapi    {
namespace keyboard {

/* keyboard handler singleton event function implementations */

// process keyboard event
result process_event( SDL_KeyboardEvent& sdl_keyboard_event )
{
	if( sdl_keyboard_event.type == SDL_KEYDOWN || sdl_keyboard_event.type == SDL_KEYUP )
	{
		if( sdl_keyboard_event.type == SDL_KEYDOWN )
		{
			key_down( sdl_keyboard_event.keysym.scancode );
		}
		else if( sdl_keyboard_event.type == SDL_KEYUP )
		{
			key_up( sdl_keyboard_event.keysym.scancode );
		}
	}

	return 1;
}

// process text input event
result process_event( SDL_TextInputEvent& sdl_text_input_event )
{
	if( strlen( sdl_text_input_event.text ) > 0 )
	{
		u8_text_input     = sdl_text_input_event.text[0];
		string_text_input = sdl_text_input_event.text;

		activity   = true;
		text_input = true;
	}

	return 1;
}

/* end */

}
}

#endif
