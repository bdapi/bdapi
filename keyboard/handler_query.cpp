
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_KEYBOARD_HANDLER_QUERY_CPP
#define BDAPI_KEYBOARD_HANDLER_QUERY_CPP
#define BD_DATA_KEYBOARD
#include "keyboard/handler.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"

/* namespaces */
namespace bdapi    {
namespace keyboard {

/* keyboard handler singleton query function implementations */

// is key held
bl held( s32 k )
{
	if( check(k) && keys[k].frame_count > 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// has key been pressed
bl pressed( s32 k )
{
	if( check(k) && keys[k].frame_count == 1 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// has key been released
bl released( s32 k )
{
	if( check(k) && keys[k].frame_count == -1 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// has key repeated
bl repeated( s32 k )
{
	if( check(k) && keys[k].repeat_count == 1 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// get key frame count
s32 get_frame_count( s32 k )
{
	if( check(k) )
	{
		return keys[k].frame_count;
	}
	else
	{
		return -1;
	}
}

// get key repeat count
s32 get_repeat_count( s32 k )
{
	if( check(k) )
	{
		return keys[k].repeat_count;
	}
	else
	{
		return -1;
	}
}

// get key delta count
f64 get_delta_count( s32 k )
{
	if( check(k) )
	{
		return keys[k].delta_count;
	}
	else
	{
		return -1.0;
	}
}

// get input character
u8 get_input_char( bl last )
{
	if( !last )
	{
		return get_input_char();
	}
	else
	{
		return get_last_input_char();
	}
}
u8 get_input_char()
{
	if( text_input )
	{
		return u8_text_input;
	}
	else
	{
		return 0;
	}
}

// get input string
string get_input_string( bl last )
{
	if( !last )
	{
		return get_input_string();
	}
	else
	{
		return get_last_input_string();
	}
}
string get_input_string()
{
	if( text_input )
	{
		return string_text_input;
	}
	else
	{
		return "";
	}
}

// get input size
s32 get_input_size( bl last )
{
	if( !last )
	{
		return get_input_size();
	}
	else
	{
		return get_last_input_size();
	}
}
s32 get_input_size()
{
	if( text_input )
	{
		return string_text_input.size();
	}
	else
	{
		return 0;
	}
}

// get last input character
u8 get_last_input_char()
{
	return u8_text_input;
}

// get last input string
string get_last_input_string()
{
	return string_text_input;
}

// get last input size
s32 get_last_input_size()
{
	return string_text_input.size();
}

// get key
const key& get_key( s32 k )
{
	if( check(k) )
	{
		return keys[k];
	}
	else
	{
		WRITE_WARNING( "Keyboard scan code ~FF%i ~F7does not exist", k );

		return dummy_key;
	}
}

/* end */

}
}

#endif
