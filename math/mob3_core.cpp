
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_MOB3_CORE_CPP
#define BDAPI_MATH_MOB3_CORE_CPP
#include "math/mob3.hpp"

/* includes */

// bdapi
#include "math/core.hpp"
#include "video/opengl.hpp"

/* namespaces */
namespace bdapi {
namespace math  {

/* 3-dimensional mobile class core function implementations */

// reset
void mob3::reset()
{
	offset_position    = vec3();
	offset_orientation = vec3();
}

// update
void mob3::update()
{
	update_orientation();
	update_position();

	angles = glm::eulerAngles( orientation );

	reset();
}

// view
void mob3::view( f32 fov, f32 distance ) const
{
	f32 aspect_ratio;

	if( gl::get_current_buffer() != NULL )
	{
		aspect_ratio
			= (f32)gl::get_current_buffer()->get_width()
			/ (f32)gl::get_current_buffer()->get_height();
	}
	else
	{
		aspect_ratio = display::get_aspect_ratio();
	}

	gl::projection_matrix( glm::perspective( fov, aspect_ratio, 0.001f, distance ) );

	gl::model_matrix( view_matrix );
}

// private update view matrix
void mob3::update_view_matrix()
{
	view_matrix = glm::mat4_cast( orientation );

	view_matrix_axis[0] = vec3( view_matrix[0][0], view_matrix[1][0], view_matrix[2][0] );
	view_matrix_axis[1] = vec3( view_matrix[0][1], view_matrix[1][1], view_matrix[2][1] );
	view_matrix_axis[2] = vec3( view_matrix[0][2], view_matrix[1][2], view_matrix[2][2] );

	view_matrix[3][0] = -glm::dot( view_matrix_axis[0], position );
	view_matrix[3][1] = -glm::dot( view_matrix_axis[1], position );
	view_matrix[3][2] = -glm::dot( view_matrix_axis[2], position );

	forward_axis = -view_matrix_axis[2];

	first_person_axis = glm::cross( vec3( 0.f, 1.f, 0.f ), view_matrix_axis[0] );
	first_person_axis = glm::normalize( first_person_axis );
}

// private update orientation
void mob3::update_orientation()
{
	quat rotation;

	if( !math::equals<f32>( offset_orientation.x ) )
	{
		rotation = glm::angleAxis( offset_orientation.x, vec3( 0.f, 1.f, 0.f ) );

		orientation = rotation * orientation;

		orientation = glm::normalize( orientation );
	}

	if( !math::equals<f32>( offset_orientation.y ) )
	{
		rotation = glm::angleAxis( offset_orientation.y, vec3( 1.f, 0.f, 0.f ) );

		orientation = orientation * rotation;

		orientation = glm::normalize( orientation );
	}

	if( !math::equals<f32>( offset_orientation.z ) )
	{
		rotation = glm::angleAxis( offset_orientation.z, vec3( 0.f, 0.f, 1.f ) );

		orientation = orientation * rotation;

		orientation = glm::normalize( orientation );
	}

	update_view_matrix();
}

// private update position
void mob3::update_position()
{
	if( flight_mode )
	{
		position +=         view_matrix_axis[0] * offset_position.x;
		position +=         view_matrix_axis[1] * offset_position.y;
		position +=          forward_axis * offset_position.z;
	}
	else
	{
		position +=         view_matrix_axis[0] * offset_position.x;
		position += vec3( 0.f, 1.f, 0.f ) * offset_position.y;
		position +=     first_person_axis * offset_position.z;
	}

	update_view_matrix();
}

/* end */

}
}

#endif
