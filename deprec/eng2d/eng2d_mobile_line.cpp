
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_MOBILE_LINE_CPP
#define BDAPI_ENG2D_MOBILE_LINE_CPP
#include "eng2d_dynamic.hpp"

/* includes */

// bdapi
#include "eng2d_const.hpp"
#include "eng2d_map2d.hpp"
#include "sys_core.hpp"

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine mobile line class implementation ***********************************************************/



// constructors

mobile_line::mobile_line() : mobile()
{
	height = 0.f;
}
mobile_line::mobile_line( const mobile& _mobile, f32 _f32_height ) : mobile( _mobile )
{
	height = _f32_height;
}
mobile_line::mobile_line( const mobile_line& _mobile_line ) :
mobile( static_cast<const mobile&>( _mobile_line ) )
{
	height = _mobile_line.height;
}



// get source

mobile& mobile_line::source()
{
	return static_cast<mobile&>(*this);
}

// get constant source

const mobile& mobile_line::source() const
{
	return static_cast<const mobile&>(*this);
}



// get line

line mobile_line::get_line() const
{
	return line( vector( x, y ), vector( x, y - height ) );
}



// get destination line

line mobile_line::get_destination_line() const
{
	return get_destination_line( false, 1.f );
}
line mobile_line::get_destination_line( f32 _f32_rate ) const
{
	return get_destination_line( false, _f32_rate );
}
line mobile_line::get_destination_line( bl _bl_fixed ) const
{
	return get_destination_line( _bl_fixed, 1.f );
}
line mobile_line::get_destination_line( bl _bl_fixed, f32 _f32_rate ) const
{
	vector vector_destination = get_destination( _bl_fixed, _f32_rate );

	return line(
		vector( vector_destination.x, vector_destination.y ),
		vector( vector_destination.x, vector_destination.y - height ) );
}



// get moved

mobile_line mobile_line::get_moved( f32 _f32_direction, f32 _f32_distance ) const
{
	mobile_line mobile_line_moved( *this );

	mobile_line_moved.position() += vector().get_moved( _f32_direction, _f32_distance );

	return mobile_line_moved;
}



// does mobile line intersect line

bl mobile_line::intersects( translation& _translation, const line& _line ) const
{
	return intersects( _translation, _line, false, 1.f );
}
bl mobile_line::intersects( translation& _translation, const line& _line, f32 _f32_rate ) const
{
	return intersects( _translation, _line, false, _f32_rate );
}
bl mobile_line::intersects( translation& _translation, const line& _line, bl _bl_fixed ) const
{
	return intersects( _translation, _line, _bl_fixed, 1.f );
}
bl mobile_line::intersects( translation& _translation, const line& _line, bl _bl_fixed, f32 _f32_rate )
const
{
	return get_line().intersects( _translation, direction, get_distance( _bl_fixed, _f32_rate ), _line );
}



// does mobile line intersect multiline

bl mobile_line::intersects( translation& _translation, const multiline& _multiline ) const
{
	return intersects( _translation, _multiline, false, 1.f );
}
bl mobile_line::intersects( translation& _translation, const multiline& _multiline, f32 _f32_rate ) const
{
	return intersects( _translation, _multiline, false, _f32_rate );
}
bl mobile_line::intersects( translation& _translation, const multiline& _multiline, bl _bl_fixed ) const
{
	return intersects( _translation, _multiline, _bl_fixed, 1.f );
}
bl mobile_line::intersects( translation& _translation, const multiline& _multiline, bl _bl_fixed,
f32 _f32_rate ) const
{
	return get_line().intersects( _translation, direction, get_distance( _bl_fixed, _f32_rate ), _multiline );
}



// does mobile line intersect polygon

bl mobile_line::intersects( translation& _translation, const polygon& _polygon ) const
{
	return intersects( _translation, _polygon, false, 1.f );
}
bl mobile_line::intersects( translation& _translation, const polygon& _polygon, f32 _f32_rate ) const
{
	return intersects( _translation, _polygon, false, _f32_rate );
}
bl mobile_line::intersects( translation& _translation, const polygon& _polygon, bl _bl_fixed ) const
{
	return intersects( _translation, _polygon, _bl_fixed, 1.f );
}
bl mobile_line::intersects( translation& _translation, const polygon& _polygon, bl _bl_fixed,
f32 _f32_rate ) const
{
	return get_line().intersects( _translation, direction, get_distance( _bl_fixed, _f32_rate ), _polygon );
}



// does mobile line collide with map

bl mobile_line::collides( translation& _translation, const map2d::layer* _layer ) const
{
	return collides( _translation, _layer, false, 1.f );
}
bl mobile_line::collides( translation& _translation, const map2d::layer* _layer, f32 _f32_rate ) const
{
	return collides( _translation, _layer, false, _f32_rate );
}
bl mobile_line::collides( translation& _translation, const map2d::layer* _layer, bl _bl_fixed ) const
{
	return collides( _translation, _layer, _bl_fixed, 1.f );
}
bl mobile_line::collides( translation& _translation, const map2d::layer* _layer, bl _bl_fixed,
f32 _f32_rate ) const
{
	line line_src = get_line();
	line line_dst = get_destination_line( _bl_fixed, _f32_rate );

	line line_aabb;

	line_aabb.p1 = line_src.p1;
	line_aabb.p2 = line_src.p1;

	fori(2)
	{
		if( line_src(i).x < line_aabb.p1.x ) line_aabb.p1.x = line_src(i).x;
		if( line_dst(i).x < line_aabb.p1.x ) line_aabb.p1.x = line_dst(i).x;

		if( line_src(i).x > line_aabb.p2.x ) line_aabb.p2.x = line_src(i).x;
		if( line_dst(i).x > line_aabb.p2.x ) line_aabb.p2.x = line_dst(i).x;

		if( line_src(i).y < line_aabb.p1.y ) line_aabb.p1.y = line_src(i).y;
		if( line_dst(i).y < line_aabb.p1.y ) line_aabb.p1.y = line_dst(i).y;

		if( line_src(i).y > line_aabb.p2.y ) line_aabb.p2.y = line_src(i).y;
		if( line_dst(i).y > line_aabb.p2.y ) line_aabb.p2.y = line_dst(i).y;
	}

	math<s32>::vec2 vec2_pos_src = _layer->get_index( line_aabb.p1 );
	math<s32>::vec2 vec2_pos_dst = _layer->get_index( line_aabb.p2 );

	s32 s32_dx = vec2_pos_dst.x - vec2_pos_src.x;
	s32 s32_dy = vec2_pos_dst.y - vec2_pos_src.y;

	s32 s32_x1, s32_x2, s32_y1, s32_y2;

	if( s32_dx < 0 )
	{
		s32_x1 = vec2_pos_src.x + s32_dx;
		s32_x2 = s32_x1 - s32_dx;
	}
	else
	{
		s32_x1 = vec2_pos_src.x;
		s32_x2 = s32_x1 + s32_dx;
	}

	if( s32_dy < 0 )
	{
		s32_y1 = vec2_pos_src.y + s32_dy;
		s32_y2 = s32_y1 - s32_dy;
	}
	else
	{
		s32_y1 = vec2_pos_src.y;
		s32_y2 = s32_y1 + s32_dy;
	}

	util::container< translation, std::deque > container_collisions;

	for( s32 xx = s32_x1; xx <= s32_x2; xx++ )
	{
		for( s32 yy = s32_y1; yy <= s32_y2; yy++ )
		{
			const map2d::tile* tile_map = &_layer->get( xx, yy );

			if( tile_map->get_type() )
			{
				translation translation_collision;

				if( intersects( translation_collision, tile_map->get_multiline(), _bl_fixed, _f32_rate ) )
				{
					container_collisions.insert( translation_collision );
	} } } }

	if( !container_collisions.is_empty() )
	{
		f32 f32_lowest_distance = container_collisions[0].get_collision_distance();
		s32 s32_lowest_index    = 0;

		if( container_collisions.get_size() > 0 )
		{
			for( s32 i = 1; i < container_collisions.get_size(); i++ )
			{
				f32 f32_collision_distance = container_collisions[i].get_collision_distance();

				if( math<f32>::equals( f32_collision_distance, f32_lowest_distance ) )
				{
					if( math<f32>::diff_radians( direction,
					container_collisions[                i ].line_collision.get_direction() )
					<   math<f32>::diff_radians( direction,
					container_collisions[ s32_lowest_index ].line_collision.get_direction() ) )
					{
						f32_lowest_distance	= f32_collision_distance;
						s32_lowest_index    = i;
				} }
				else if( f32_collision_distance < f32_lowest_distance )
				{
					f32_lowest_distance	= f32_collision_distance;
					s32_lowest_index    = i;
		} } }

		_translation = translation( container_collisions[ s32_lowest_index ] );

		return true;
	}

	return false;
}



// iterate

bl mobile_line::iterate( vector& _vector, const map2d::layer* _layer )
{
	return iterate( _vector, _layer, false, 1.f );
}
bl mobile_line::iterate( vector& _vector, const map2d::layer* _layer, f32 _f32_rate )
{
	return iterate( _vector, _layer, false, _f32_rate );
}
bl mobile_line::iterate( vector& _vector, const map2d::layer* _layer, bl _bl_fixed )
{
	return iterate( _vector, _layer, _bl_fixed, 1.f );
}
bl mobile_line::iterate( vector& _vector, const map2d::layer* _layer, bl _bl_fixed, f32 _f32_rate )
{
	translation translation_iteration;

	if( collides( translation_iteration, _layer, _bl_fixed, _f32_rate ) )
	{
		_vector = translation_iteration.vector_collision;

		if( translation_iteration.get_collision_distance() - ENG2D_PRECISION > 0.f )
			*this = get_moved( direction, translation_iteration.get_collision_distance() - ENG2D_PRECISION );

		line   line_iteration   = translation_iteration.line_collision * ( 1.f + ENG2D_PRECISION );
		vector vector_iteration = line_iteration.get_nearest( translation_iteration.line_trajectory.p2 );

		mobile_line mobile_line_copy( *this );

		mobile_line_copy.direction = _vector.get_direction(vector_iteration);
		mobile_line_copy.velocity  = _vector.get_distance(vector_iteration);

		if( mobile_line_copy.collides( translation_iteration, _layer, true, 1.f ) )
		{
			if( translation_iteration.get_collision_distance() - ENG2D_PRECISION > 0.f )
			{
				*this = get_moved( mobile_line_copy.direction,
					translation_iteration.get_collision_distance() - ENG2D_PRECISION );
		} }
		else
		{
			*this = get_moved( mobile_line_copy.direction, mobile_line_copy.velocity );
		}

		return true;
	}
	else
	{
		*this = get_moved( direction, get_distance( _bl_fixed, _f32_rate ) );

		return false;
} }



// move

bl mobile_line::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, false, 1.f );
}
bl mobile_line::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, f32 _f32_rate )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, false, _f32_rate );
}
bl mobile_line::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, bl _bl_fixed )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, _bl_fixed, 1.f );
}
bl mobile_line::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, bl _bl_fixed, f32 _f32_rate )
{
	mobile_line mobile_line_copy( *this );

	mobile_line_copy.direction = _f32_direction;
	mobile_line_copy.velocity  = _f32_distance;

	if( mobile_line_copy.collides( _translation, _layer, _bl_fixed, _f32_rate ) )
	{
		if( _translation.get_collision_distance() - ENG2D_PRECISION > 0.f )
		{
			*this = get_moved( mobile_line_copy.direction,
				_translation.get_collision_distance() - ENG2D_PRECISION );
		}

		return true;
	}
	else
	{
		*this = get_moved( mobile_line_copy.direction, mobile_line_copy.get_distance( _bl_fixed, _f32_rate ) );

		return false;
} }



// draw

void mobile_line::draw( const video::color& _color_1, const video::color& _color_2 ) const
{
	get_line().draw( _color_1, _color_2 );
}
void mobile_line::draw( const video::color& _color ) const
{
	get_line().draw( _color );
}



/* end */
}}
#endif
