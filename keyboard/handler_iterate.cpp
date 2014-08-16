
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_KEYBOARD_HANDLER_ITERATE_CPP
#define BDAPI_KEYBOARD_HANDLER_ITERATE_CPP
#define BD_DATA_KEYBOARD
#include "keyboard/handler.hpp"

/* includes */

// bdapi
#include "sys/handler.hpp"

/* namespaces */
namespace bdapi    {
namespace keyboard {

/* keyboard handler singleton iteration function implementations */

// private frame begin
result frame_begin()
{
	return 1;
}

// private frame finish
result frame_finish()
{
	fori(512)
	{
		if( check(i) )
		{
			key& k = keys[i];

			if( k.frame_count > 0 )
			{
				k.frame_count++;
				k.repeat_count++;

				k.delta_count += sys::get_delta();
			}
			else if( k.frame_count == -1 )
			{
				k.frame_count = 0;
			}
		}
	}

	activity   = false;
	text_input = false;

	SDL_StopTextInput();
	SDL_StartTextInput();

	return 1;
}

/* end */

}
}

#endif
