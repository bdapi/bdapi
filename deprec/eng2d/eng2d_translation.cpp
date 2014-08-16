
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_TRANSLATION_CPP
#define BDAPI_ENG2D_TRANSLATION_CPP
#include "eng2d_primitive.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine translation class implementation ***********************************************************/



// constructors

translation::translation()
{
	line_trajectory = line();

	vector_collision = vector();
	line_collision     = line();

	bl_destination_intersection = false;
}
translation::translation( const line& _line_trajectory, const vector& _vector_collision,
const line& _line_collision, bl _bl_destination_intersection )
{
	line_trajectory = _line_trajectory;

	vector_collision = _vector_collision;
	line_collision   = _line_collision;

	bl_destination_intersection = _bl_destination_intersection;

	if( bl_destination_intersection )
	{
		f32 collision_distance = get_collision_distance();

		f32 direction = math<f32>::clamp_radians( line_trajectory.get_direction() + math<f32>::pi() );
		f32 distance  =                           line_trajectory.get_distance();

		line_trajectory.p1 = vector_collision;
		line_trajectory.p2 = vector_collision.get_moved( direction, distance );

		vector_collision = line_trajectory.p1.get_moved(  direction, collision_distance );
		line_collision   = line_collision.get_moved( direction, collision_distance );
	}
}
translation::translation( const translation& t )
{
	line_trajectory = t.line_trajectory;

	vector_collision = t.vector_collision;
	line_collision   = t.line_collision;

	bl_destination_intersection = t.bl_destination_intersection;
}



// get collision distance

f32 translation::get_collision_distance() const
{
	return line_trajectory.p1.get_distance( vector_collision );
}

// get remaining distance

f32 translation::get_remaining_distance() const
{
	return vector_collision.get_distance( line_trajectory.p2 );
}



/* end */
}}
#endif
