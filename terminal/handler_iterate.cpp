
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_TERMINAL_HANDLER_ITERATE_CPP
#define BDAPI_TERMINAL_HANDLER_ITERATE_CPP
#define BD_DATA_TERMINAL
#include "terminal/handler.hpp"

/* includes */

/* namespaces */
namespace bdapi    {
namespace terminal {

/* terminal handler singleton iteration function implementations */

// private frame begin
result frame_begin()
{
	s32 getch_result;

	{ using namespace curses;

		getch_result = curses::getch();
	}

	last_key = getch_result;

	if( getch_result > 31 && getch_result < 127 )
	{
		last_character = getch_result;
	}

	{ using namespace curses;

		curses::request_mouse_pos();

		mouse_x = MOUSE_X_POS;
		mouse_y = MOUSE_Y_POS;
	}

	if( curses::Mouse_status.button[0] )
	{
		if( !left_button_state )
		{
			left_button_state = 1;
		}
	}
	else
	{
		left_button_state = 0;
	}

	if( curses::Mouse_status.button[2] )
	{
		if( !right_button_state )
		{
			right_button_state = 1;
		}
	}
	else
	{
		right_button_state = 0;
	}

	return 1;
}

// private frame finish
result frame_finish()
{
	if( left_button_state  > 0 )
	{
		left_button_state++;
	}

	if( right_button_state > 0 )
	{
		right_button_state++;
	}

	if( automatic )
	{
		refresh();
	}

	return 1;
}

/* end */

}
}

#endif