
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_MOBILE_POLYGON_CPP
#define BDAPI_ENG2D_MOBILE_POLYGON_CPP
#include "eng2d_dynamic.hpp"

/* includes */

// bdapi
#include "eng2d_const.hpp"
#include "eng2d_map2d.hpp"
#include "sys_core.hpp"

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine mobile polygon class implementation ********************************************************/



// constructors

mobile_polygon::mobile_polygon() : mobile()
{
	box    = polygon();
	width  = 0.f;
	height = 0.f;
}
mobile_polygon::mobile_polygon( const mobile& _mobile, f32 _f32_width, f32 _f32_height ) : mobile( _mobile )
{
	set_size( _f32_width, _f32_height );
}
mobile_polygon::mobile_polygon( const mobile_polygon& _mobile_polygon ) :
mobile( static_cast<const mobile&>( _mobile_polygon ) )
{
	box    = _mobile_polygon.box;
	width  = _mobile_polygon.width;
	height = _mobile_polygon.height;
}



// get source

mobile& mobile_polygon::source()
{
	return static_cast<mobile&>(*this);
}

// get constant source

const mobile& mobile_polygon::source() const
{
	return static_cast<const mobile&>(*this);
}



// set width

mobile_polygon& mobile_polygon::set_width( f32 _f32_width )
{
	return set_size( _f32_width, height );
}

// set height

mobile_polygon& mobile_polygon::set_height( f32 _f32_height )
{
	return set_size( width, _f32_height );
}

// set size

mobile_polygon& mobile_polygon::set_size( f32 _f32_width, f32 _f32_height )
{
	width  = _f32_width;
	height = _f32_height;

	box = polygon(
		vector(   0.f,    0.f ),
		vector( width,    0.f ),
		vector( width, height ),
		vector(   0.f, height ) ) - vector( width * 0.5f, height * 0.5f );

	return *this;
}



// get box

polygon mobile_polygon::get_box() const
{
	return box + position();
}



// get destination box

polygon mobile_polygon::get_destination_box() const
{
	return get_destination_box( false, 1.f );
}
polygon mobile_polygon::get_destination_box( f32 _f32_rate ) const
{
	return get_destination_box( false, _f32_rate );
}
polygon mobile_polygon::get_destination_box( bl _bl_fixed ) const
{
	return get_destination_box( _bl_fixed, 1.f );
}
polygon mobile_polygon::get_destination_box( bl _bl_fixed, f32 _f32_rate ) const
{
	return box + get_destination( _bl_fixed, _f32_rate );
}



// get moved

mobile_polygon mobile_polygon::get_moved( f32 _f32_direction, f32 _f32_distance ) const
{
	mobile_polygon mobile_polygon_moved( *this );

	mobile_polygon_moved.position() += vector().get_moved( _f32_direction, _f32_distance );

	return mobile_polygon_moved;
}



// does mobile polygon intersect line

bl mobile_polygon::intersects( translation& _translation, const line& _line ) const
{
	return intersects( _translation, _line, false, 1.f );
}
bl mobile_polygon::intersects( translation& _translation, const line& _line, f32 _f32_rate ) const
{
	return intersects( _translation, _line, false, _f32_rate );
}
bl mobile_polygon::intersects( translation& _translation, const line& _line, bl _bl_fixed ) const
{
	return intersects( _translation, _line, _bl_fixed, 1.f );
}
bl mobile_polygon::intersects( translation& _translation, const line& _line, bl _bl_fixed, f32 _f32_rate )
const
{
	return get_box().intersects( _translation, direction, get_distance( _bl_fixed, _f32_rate ), _line );
}



// does mobile polygon intersect multiline

bl mobile_polygon::intersects( translation& _translation, const multiline& _multiline ) const
{
	return intersects( _translation, _multiline, false, 1.f );
}
bl mobile_polygon::intersects( translation& _translation, const multiline& _multiline, f32 _f32_rate ) const
{
	return intersects( _translation, _multiline, false, _f32_rate );
}
bl mobile_polygon::intersects( translation& _translation, const multiline& _multiline, bl _bl_fixed ) const
{
	return intersects( _translation, _multiline, _bl_fixed, 1.f );
}
bl mobile_polygon::intersects( translation& _translation, const multiline& _multiline, bl _bl_fixed,
f32 _f32_rate ) const
{
	return get_box().intersects( _translation, direction, get_distance( _bl_fixed, _f32_rate ), _multiline );
}



// does mobile polygon intersect polygon

bl mobile_polygon::intersects( translation& _translation, const polygon& _polygon ) const
{
	return intersects( _translation, _polygon, false, 1.f );
}
bl mobile_polygon::intersects( translation& _translation, const polygon& _polygon, f32 _f32_rate ) const
{
	return intersects( _translation, _polygon, false, _f32_rate );
}
bl mobile_polygon::intersects( translation& _translation, const polygon& _polygon, bl _bl_fixed ) const
{
	return intersects( _translation, _polygon, _bl_fixed, 1.f );
}
bl mobile_polygon::intersects( translation& _translation, const polygon& _polygon, bl _bl_fixed,
f32 _f32_rate ) const
{
	return get_box().intersects( _translation, direction, get_distance( _bl_fixed, _f32_rate ), _polygon );
}



// does mobile polygon collide with map

bl mobile_polygon::collides( translation& _translation, const map2d::layer* _layer ) const
{
	return collides( _translation, _layer, false, 1.f );
}
bl mobile_polygon::collides( translation& _translation, const map2d::layer* _layer, f32 _f32_rate ) const
{
	return collides( _translation, _layer, false, _f32_rate );
}
bl mobile_polygon::collides( translation& _translation, const map2d::layer* _layer, bl _bl_fixed ) const
{
	return collides( _translation, _layer, _bl_fixed, 1.f );
}
bl mobile_polygon::collides( translation& _translation, const map2d::layer* _layer, bl _bl_fixed,
f32 _f32_rate ) const
{
	polygon polygon_src = get_box();
	polygon polygon_dst = get_destination_box( _bl_fixed, _f32_rate );

	line line_aabb;

	line_aabb.p1 = polygon_src[0].p1;
	line_aabb.p2 = polygon_src[0].p1;

	fori(4)
	{
		if( polygon_src[i].p1.x < line_aabb.p1.x ) line_aabb.p1.x = polygon_src[i].p1.x;
		if( polygon_dst[i].p1.x < line_aabb.p1.x ) line_aabb.p1.x = polygon_dst[i].p1.x;

		if( polygon_src[i].p1.x > line_aabb.p2.x ) line_aabb.p2.x = polygon_src[i].p1.x;
		if( polygon_dst[i].p1.x > line_aabb.p2.x ) line_aabb.p2.x = polygon_dst[i].p1.x;

		if( polygon_src[i].p1.y < line_aabb.p1.y ) line_aabb.p1.y = polygon_src[i].p1.y;
		if( polygon_dst[i].p1.y < line_aabb.p1.y ) line_aabb.p1.y = polygon_dst[i].p1.y;

		if( polygon_src[i].p1.y > line_aabb.p2.y ) line_aabb.p2.y = polygon_src[i].p1.y;
		if( polygon_dst[i].p1.y > line_aabb.p2.y ) line_aabb.p2.y = polygon_dst[i].p1.y;
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

bl mobile_polygon::iterate( vector& _vector, const map2d::layer* _layer )
{
	return iterate( _vector, _layer, false, 1.f );
}
bl mobile_polygon::iterate( vector& _vector, const map2d::layer* _layer, f32 _f32_rate )
{
	return iterate( _vector, _layer, false, _f32_rate );
}
bl mobile_polygon::iterate( vector& _vector, const map2d::layer* _layer, bl _bl_fixed )
{
	return iterate( _vector, _layer, _bl_fixed, 1.f );
}
bl mobile_polygon::iterate( vector& _vector, const map2d::layer* _layer, bl _bl_fixed, f32 _f32_rate )
{
	translation translation_iteration;

	if( collides( translation_iteration, _layer, _bl_fixed, _f32_rate ) )
	{
		_vector = translation_iteration.vector_collision;

		if( translation_iteration.get_collision_distance() - ENG2D_PRECISION > 0.f )
			*this = get_moved( direction, translation_iteration.get_collision_distance() - ENG2D_PRECISION );

		line   line_iteration   = translation_iteration.line_collision * ( 1.f + ENG2D_PRECISION );
		vector vector_iteration = line_iteration.get_nearest( translation_iteration.line_trajectory.p2 );

		mobile_polygon mobile_polygon_copy( *this );

		mobile_polygon_copy.direction = _vector.get_direction(vector_iteration);
		mobile_polygon_copy.velocity  = _vector.get_distance(vector_iteration);

		if( mobile_polygon_copy.collides( translation_iteration, _layer, true, 1.f ) )
		{
			if( translation_iteration.get_collision_distance() - ENG2D_PRECISION > 0.f )
			{
				*this = get_moved( mobile_polygon_copy.direction,
					translation_iteration.get_collision_distance() - ENG2D_PRECISION );
		} }
		else
		{
			*this = get_moved( mobile_polygon_copy.direction, mobile_polygon_copy.velocity );
		}

		return true;
	}
	else
	{
		*this = get_moved( direction, get_distance( _bl_fixed, _f32_rate ) );

		return false;
} }



// move

bl mobile_polygon::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, false, 1.f );
}
bl mobile_polygon::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, f32 _f32_rate )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, false, _f32_rate );
}
bl mobile_polygon::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, bl _bl_fixed )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, _bl_fixed, 1.f );
}
bl mobile_polygon::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, bl _bl_fixed, f32 _f32_rate )
{
	mobile_polygon mobile_polygon_copy( *this );

	mobile_polygon_copy.direction = _f32_direction;
	mobile_polygon_copy.velocity  = _f32_distance;

	if( mobile_polygon_copy.collides( _translation, _layer, _bl_fixed, _f32_rate ) )
	{
		if( _translation.get_collision_distance() - ENG2D_PRECISION > 0.f )
		{
			*this = get_moved( mobile_polygon_copy.direction,
				_translation.get_collision_distance() - ENG2D_PRECISION );
		}

		return true;
	}
	else
	{
		*this = get_moved( mobile_polygon_copy.direction,
			mobile_polygon_copy.get_distance( _bl_fixed, _f32_rate ) );

		return false;
} }



// draw

void mobile_polygon::draw( const video::color& _color_1, const video::color& _color_2 ) const
{
	get_box().draw( _color_1, _color_2 );
}
void mobile_polygon::draw( const video::color& _color ) const
{
	get_box().draw( _color );
}



/* end */
}}
#endif
