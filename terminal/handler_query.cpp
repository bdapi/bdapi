
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_TERMINAL_HANDLER_QUERY_CPP
#define BDAPI_TERMINAL_HANDLER_QUERY_CPP
#define BD_DATA_TERMINAL
#include "terminal/handler.hpp"

/* includes */

/* namespaces */
namespace bdapi    {
namespace terminal {

/* terminal handler singleton query function implementations */

// is left held
bl is_left_held()
{
	if( left_button_state )
	{
		return true;
	}

	return false;
}

// is left pressed
bl is_left_pressed()
{
	if( left_button_state == 1 )
	{
		return true;
	}

	return false;
}

// get left duration
s32 get_left_duration()
{
	return left_button_state;
}

// is right held
bl is_right_held()
{
	if( right_button_state )
	{
		return true;
	}

	return false;
}

// is right pressed
bl is_right_pressed()
{
	if( right_button_state == 1 )
	{
		return true;
	}

	return false;
}

// get right duration
s32 get_right_duration()
{
	return right_button_state;
}

/* end */

}
}

#endif