
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_KEYBOARD_HANDLER_INIT_CPP
#define BDAPI_KEYBOARD_HANDLER_INIT_CPP
#define BD_DATA_KEYBOARD
#include "keyboard/handler.hpp"

/* includes */

// bdapi
#include "logging/message.hpp"

/* namespaces */
namespace bdapi    {
namespace keyboard {

/* static variables */

static bool handler_instance = false;

/* keyboard handler singleton initialization function implementations */

// private initializers
result initialize( parameters* handler_parameters )
{
	LOG_ERROR_1( "~F6subsystem", "~~ has already been initialized", !handler_instance );

	handler_instance = true;

	LOG_ERROR_1( "~F6subsystem parameters", "failed to read ~~", handler_parameters );

	keyboard::handler_parameters = handler_parameters;

	subsystem_state = SUBSYS_INITIALIZED;

	keys = new key[512]();

	u8_text_input = 0;
	string_text_input.clear();

	dummy_key.scan_code = -1;
	dummy_key.key_code  = -1;

	dummy_key.name.clear();

	dummy_key.frame_count  = -1;
	dummy_key.repeat_count = -1;
	dummy_key.delta_count  = -1.0;

	fori(512)
	{
		string s = SDL_GetKeyName( SDL_GetKeyFromScancode( SDL_Scancode(i) ) );

		if( !s.empty() )
		{
			keys[i].scan_code = i;
			keys[i].key_code  = SDL_GetKeyFromScancode( SDL_Scancode(i) );

			keys[i].name = s;

			keys[i].frame_count  = 0;
			keys[i].repeat_count = 0;
			keys[i].delta_count  = 0.0;
		}
		else
		{
			keys[i] = dummy_key;
		}
	}

	focus = true;

	subsystem_state = SUBSYS_ACTIVE;

	return 1;
}

// private shutdown
result shutdown()
{
	subsystem_state = SUBSYS_SUSPENDED;

	delete[] keys;

	subsystem_state = SUBSYS_SHUTDOWN;

	return 1;
}

/* end */

}
}

#endif
