
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_MOB3_QUERY_CPP
#define BDAPI_MATH_MOB3_QUERY_CPP
#include "math/mob3.hpp"

/* includes */

// bdapi
#include "math/const.hpp"

/* namespaces */
namespace bdapi {
namespace math  {

/* 3-dimensional mobile class query function implementations */

// get position
f32 mob3::get_x_position() const
{
	return position.x;
}
f32 mob3::get_y_position() const
{
	return position.y;
}
f32 mob3::get_z_position() const
{
	return position.z;
}

// get angle
f32 mob3::get_x_angle() const
{
	return angles.x;
}
f32 mob3::get_y_angle() const
{
	return angles.y;
}
f32 mob3::get_z_angle() const
{
	return angles.z;
}

// get offset position
f32 mob3::get_x_offset_position() const
{
	return offset_position.x;
}
f32 mob3::get_y_offset_position() const
{
	return offset_position.y;
}
f32 mob3::get_z_offset_position() const
{
	return offset_position.z;
}

// get offset angle
f32 mob3::get_x_offset_angle() const
{
	return offset_orientation.x;
}
f32 mob3::get_y_offset_angle() const
{
	return offset_orientation.y;
}
f32 mob3::get_z_offset_angle() const
{
	return offset_orientation.z;
}

/* end */

}
}

#endif
