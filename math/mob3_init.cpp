
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_MOB3_INIT_CPP
#define BDAPI_MATH_MOB3_INIT_CPP
#include "math/mob3.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace math  {

/* 3-dimensional mobile class initialization function implementations */

// constructors
mob3::mob3( f32 x, f32 y, f32 z )
{
	position.x = x;
	position.y = y;
	position.z = z;
}
mob3::mob3( f32 x, f32 y, f32 z, f32 a, f32 b, f32 c )
{
	position.x = x;
	position.y = y;
	position.z = z;

	offset_orientation.x = a;
	offset_orientation.y = b;
	offset_orientation.z = c;
}
mob3::mob3( const vec3& position )
{
	this->position = position;
}
mob3::mob3( const vec3& position, const vec3& angle )
{
	this->position = position;

	offset_orientation = angle;
}
mob3::mob3( const mob3& copy )
{
	position = copy.position;

	offset_position    = copy.offset_position;
	offset_orientation = copy.offset_orientation;

	orientation = copy.orientation;

	view_matrix_axis[0] = copy.view_matrix_axis[0];
	view_matrix_axis[1] = copy.view_matrix_axis[1];
	view_matrix_axis[2] = copy.view_matrix_axis[2];

	view_matrix = copy.view_matrix;

	forward_axis      = copy.forward_axis;
	first_person_axis = copy.first_person_axis;

	flight_mode = copy.flight_mode;
}

/* end */

}
}

#endif
