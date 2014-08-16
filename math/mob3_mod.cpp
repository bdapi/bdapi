
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_MOB3_MOD_CPP
#define BDAPI_MATH_MOB3_MOD_CPP
#include "math/mob3.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace math  {

/* 3-dimensional mobile class modification function implementations */

// move
void mob3::move_x( f32 x )
{
	offset_position.x += x;
}
void mob3::move_y( f32 y )
{
	offset_position.y += y;
}
void mob3::move_z( f32 z )
{
	offset_position.z += z;
}
void mob3::move( const vec3& v )
{
	offset_position += v;
}

// rotate
void mob3::rotate_x( f32 x )
{
	offset_orientation.x += x;
}
void mob3::rotate_y( f32 y )
{
	offset_orientation.y += y;
}
void mob3::rotate_z( f32 z )
{
	offset_orientation.z += z;
}
void mob3::rotate( const vec3& v )
{
	offset_orientation += v;
}

/* end */

}
}

#endif
