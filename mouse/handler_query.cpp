
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MOUSE_HANDLER_QUERY_CPP
#define BDAPI_MOUSE_HANDLER_QUERY_CPP
#define BD_DATA_MOUSE
#include "mouse/handler.hpp"

/* includes */

// bdapi
#include "display/handler.hpp"
#include "error/handler.hpp"
#include "video/opengl.hpp"

/* namespaces */
namespace bdapi {
namespace mouse {

/* mouse handler singleton query function implementations */

// is button held
bl held( s32 i )
{
	if( check(i) && buttons[i].frame_count > 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// has button been pressed
bl pressed( s32 i )
{
	if( check(i) && buttons[i].frame_count == 1 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// has button been released
bl released( s32 i )
{
	if( check(i) && buttons[i].frame_count == -1 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// get button frame count
s32 get_frame_count( s32 i )
{
	if( check(i) )
	{
		return buttons[i].frame_count;
	}
	else
	{
		return -1;
	}
}

// get button delta count
f64 get_delta_count( s32 i )
{
	if( check(i) )
	{
		return buttons[i].delta_count;
	}
	else
	{
		return -1.0;
	}
}

// get current x
f32 get_current_x()
{
	return get_current_x(true);
}
f32 get_current_x( bl frame_buffer )
{
	if( frame_buffer && gl::get_current_buffer() )
	{
		return (f32)current_x_internal
			/ (f32)display::get_width() * (f32)gl::get_current_buffer()->get_width();
	}
	else
	{
		return (f32)current_x_internal;
	}
}

// get current y
f32 get_current_y()
{
	return get_current_y(true);
}
f32 get_current_y( bl frame_buffer )
{
	if( frame_buffer && gl::get_current_buffer() )
	{
		return (f32)current_y_internal
			/ (f32)display::get_height() * (f32)gl::get_current_buffer()->get_height();
	}
	else
	{
		return (f32)current_y_internal;
	}
}

// get previous x
f32 get_previous_x()
{
	return get_previous_x(true);
}
f32 get_previous_x( bl frame_buffer )
{
	if( frame_buffer && gl::get_current_buffer() )
	{
		return (f32)previous_x_internal
			/ (f32)display::get_width() * (f32)gl::get_current_buffer()->get_width();
	}
	else
	{
		return (f32)previous_x_internal;
	}
}

// get previous y
f32 get_previous_y()
{
	return get_previous_y(true);
}
f32 get_previous_y( bl frame_buffer )
{
	if( frame_buffer && gl::get_current_buffer() )
	{
		return (f32)previous_y_internal
			/ (f32)display::get_height() * (f32)gl::get_current_buffer()->get_height();
	}
	else
	{
		return (f32)previous_y_internal;
	}
}

// get movement x
f32 get_movement_x()
{
	return get_movement_x(true);
}
f32 get_movement_x( bl frame_buffer )
{
	if( frame_buffer && gl::get_current_buffer() )
	{
		return (f32)movement_x_internal
			/ (f32)display::get_width() * (f32)gl::get_current_buffer()->get_width();
	}
	else
	{
		return (f32)movement_x_internal;
	}
}

// get movement y
f32 get_movement_y()
{
	return get_movement_y(true);
}
f32 get_movement_y( bl frame_buffer )
{
	if( frame_buffer && gl::get_current_buffer() )
	{
		return (f32)movement_y_internal
			/ (f32)display::get_height() * (f32)gl::get_current_buffer()->get_height();
	}
	else
	{
		return (f32)movement_y_internal;
	}
}

// get button
const button& get_button( s32 i )
{
	if( check(i) )
	{
		return buttons[i];
	}
	else
	{
		WRITE_WARNING( "Mouse scan code ~FF%i ~F7does not exist", i );

		return buttons[0];
	}
}

/* end */

}
}

#endif
