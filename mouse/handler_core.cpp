
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MOUSE_HANDLER_CORE_CPP
#define BDAPI_MOUSE_HANDLER_CORE_CPP
#define BD_DATA_MOUSE
#include "mouse/handler.hpp"

/* includes */

// bdapi
#include "display/handler.hpp"
#include "sys/handler.hpp"
#include "window/handler.hpp"

/* namespaces */
namespace bdapi {
namespace mouse {

/* mouse handler singleton core function implementations */

// static check mouse button code
bl check( s32 i )
{
	if( i > 0 && i < 6 && buttons[i].button_code > 0 && buttons[i].button_code < 6 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// static button down
result button_down( s32 i )
{
	if( check(i) )
	{
		button& b = buttons[i];

		if( b.frame_count == 0 )
		{
			b.frame_count = 1;
			b.delta_count = sys::get_delta();
		}

		activity = true;
	}

	return 1;
}

// static button up
result button_up( s32 i )
{
	if( check(i) )
	{
		button& b = buttons[i];

		b.frame_count = -1;
		b.delta_count =  0.0;

		activity = true;
	}

	return 1;
}

// static move cursor
result move( s32 x, s32 y )
{
	if( x != current_x_internal || y != current_y_internal )
	{
		previous_x_internal = current_x_internal;
		previous_y_internal = current_y_internal;

		if( locked )
		{
			movement_x_internal = x - display::get_width()  / 2;
			movement_y_internal = y - display::get_height() / 2;

			current_x_internal += movement_x_internal;
			current_y_internal += movement_y_internal;

			if( current_x_internal < 0 )
			{
				  current_x_internal = 0;
			}
			else
			if( current_x_internal > display::get_width() - 1 )
			{
				  current_x_internal = display::get_width() - 1;
			}

			if( current_y_internal < 0 )
			{
				  current_y_internal = 0;
			}
			else
			if( current_y_internal > display::get_height() - 1 )
			{
				  current_y_internal = display::get_height() - 1;
			}
		}
		else
		{
			current_x_internal = x;
			current_y_internal = y;

			movement_x_internal = current_x_internal - previous_x_internal;
			movement_y_internal = current_y_internal - previous_y_internal;
		}

		activity = true;
	}

	return 1;
}

// static rotate mouse wheel
result rotate( s32 i )
{
	rotation += i;

	activity = true;

	return 1;
}

// set inside
result set_inside( bl inside )
{
	mouse::inside = inside;

	return 1;
}

// show mouse cursor
result show()
{
	SDL_ShowCursor(1);

	visible = true;

	return 1;
}

// hide mouse cursor
result hide()
{
	SDL_ShowCursor(0);

	visible = false;

	return 1;
}

// lock mouse
result lock()
{
	locked = true;

	return 1;
}

// unlock mouse
result unlock()
{
	locked = false;

	return 1;
}

// set mouse position
result set_position( s32 x, s32 y )
{
	SDL_WarpMouseInWindow( window::get_sdl_window(), x, y );

	return 1;
}

/* end */

}
}

#endif
