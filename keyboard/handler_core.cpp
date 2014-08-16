
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_KEYBOARD_HANDLER_CORE_CPP
#define BDAPI_KEYBOARD_HANDLER_CORE_CPP
#define BD_DATA_KEYBOARD
#include "keyboard/handler.hpp"

/* includes */

// bdapi
#include "sys/handler.hpp"

/* namespaces */
namespace bdapi    {
namespace keyboard {

/* keyboard handler singleton core function implementations */

// private check key
bl check( s32 k )
{
	if( k >= 0 && k < 512 && keys[k].scan_code >= 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// private key down
result key_down( s32 i )
{
	if( check(i) )
	{
		key& k = keys[i];

		if( k.frame_count == 0 )
		{
			k.frame_count = 1;
			k.delta_count = sys::get_delta();
		}

		k.repeat_count = 1;

		activity = true;
	}

	return 1;
}

// private key up
result key_up( s32 i )
{
	if( check(i) )
	{
		key& k = keys[i];

		k.frame_count  = -1;
		k.repeat_count =  0;
		k.delta_count  =  0.0;

		activity = true;
	}

	return 1;
}

// set focus
result set_focus( bl focus )
{
	keyboard::focus = focus;

	return 1;
}

/* end */

}
}

#endif
