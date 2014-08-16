
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_VECTOR_CPP
#define BDAPI_ENG2D_VECTOR_CPP
#include "eng2d_primitive.hpp"

/* includes */

// bdapi
#include "eng2d_map2d.hpp"
#include "sys_opengl.hpp"

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine vector class implementation ****************************************************************/



// constructors

vector::vector() : vec2( 0.f, 0.f )
{
}
vector::vector( f32 _f32_direction )
{
	*this = vector().get_moved( _f32_direction, 1.f ).get_unit();
}
vector::vector( f32 _f32_x, f32 _f32_y ) : vec2( _f32_x, _f32_y )
{
}
vector::vector( const vec2& _vector ) : vec2( _vector )
{
}
vector::vector( const vector& _vector ) : vec2( static_cast<const vec2&>( _vector ) )
{
}



// operator == vector

bl vector::operator == ( const vector& _vector ) const
{
	if( math<f32>::equals( x, _vector.x ) && math<f32>::equals( y, _vector.y ) )
		return true;

	return false;
}

// operator != vector

bl vector::operator != ( const vector& _vector ) const
{
	return !( *this == _vector );
}



// operator += vector

vector& vector::operator += ( const vector& _vector )
{
	x += _vector.x;
	y += _vector.y;

	return *this;
}

// operator -= vector

vector& vector::operator -= ( const vector& _vector )
{
	x -= _vector.x;
	y -= _vector.y;

	return *this;
}

// operator *= vector

vector& vector::operator *= ( const vector& _vector )
{
	x *= _vector.x;
	y *= _vector.y;

	return *this;
}

// operator /= vector

vector& vector::operator /= ( const vector& _vector )
{
	x = math<f32>::divide( x, _vector.x );
	y = math<f32>::divide( y, _vector.y );

	return *this;
}

// operator + vector

vector vector::operator + ( const vector& _vector ) const
{
	return vector( *this ) += _vector;
}

// operator - vector

vector vector::operator - ( const vector& _vector ) const
{
	return vector( *this ) -= _vector;
}

// operator * vector

vector vector::operator * ( const vector& _vector ) const
{
	return vector( *this ) *= _vector;
}

// operator / vector

vector vector::operator / ( const vector& _vector ) const
{
	return vector( *this ) /= _vector;
}



// operator *= f32

vector& vector::operator *= ( f32 n )
{
	x *= n;
	y *= n;

	return *this;
}

// operator /= f32

vector& vector::operator /= ( f32 n )
{
	x = math<f32>::divide( x, n );
	y = math<f32>::divide( y, n );

	return *this;
}

// operator * f32

vector vector::operator * ( f32 n ) const
{
	return vector( *this ) *= n;
}

// operator / f32

vector vector::operator / ( f32 n ) const
{
	return vector( *this ) /= n;
}



// get length

f32 vector::get_length() const
{
	return sqrt( get_squared_length() );
}

// get squared length

f32 vector::get_squared_length() const
{
	return x * x  +  y * y;
}



// get _f32_direction

f32 vector::get_direction( const vector& _vector ) const
{
	return atan2( _vector.y - y, _vector.x - x );
}

// get _f32_distance

f32 vector::get_distance( const vector& _vector ) const
{
	return hypot( _vector.x - x, _vector.y - y );
}

// get cross product

f32 vector::get_cross_product( const vector& _vector ) const
{
	return x * _vector.x - y * _vector.y;
}

// get dot product

f32 vector::get_dot_product( const vector& _vector ) const
{
	return x * _vector.x + y * _vector.y;
}



// get normal

vector vector::get_normal() const
{
	return get_normal_left();
}
vector vector::get_normal( bl _bl_right ) const
{
	if( _bl_right )
		return get_normal_right();
	else
		return get_normal_left();
}
vector vector::get_normal_left() const
{
	return vector(  y, -x );
}
vector vector::get_normal_right() const
{
	return vector( -y,  x );
}



// get unit vector

vector vector::get_unit() const
{
	f32 f32_length = get_length();

	return vector( math<f32>::divide( x, f32_length ), math<f32>::divide( y, f32_length ) );
}

// get projection

vector vector::get_projection( const vector& _vector ) const
{
	f32 f32_projection = math<f32>::divide( get_dot_product( _vector ), _vector.get_squared_length() );

	return vector( f32_projection * _vector.x, f32_projection * _vector.y );
}



// get moved

vector vector::get_moved( f32 _f32_direction, f32 _f32_distance ) const
{
	vector vector_moved( *this );

	vector_moved.x += _f32_distance * cos( _f32_direction );
	vector_moved.y += _f32_distance * sin( _f32_direction );

	return vector_moved;
}



// does vector intersect line

bl vector::intersects( translation& _translation, bl _bl_dst_int, f32 _f32_direction, f32 _f32_distance,
const line& l ) const
{
	return intersects( _translation, _bl_dst_int, get_moved( _f32_direction, _f32_distance ), l, false );
}
bl vector::intersects( translation& _translation, bl _bl_dst_int, f32 _f32_direction, f32 _f32_distance,
const line& l, bl _bl_facing_away ) const
{
	return intersects( _translation, _bl_dst_int, get_moved( _f32_direction, _f32_distance ), l,
		_bl_facing_away );
}
bl vector::intersects( translation& _translation, bl _bl_dst_int, const vector& _vector, const line& l )
const
{
	return intersects( _translation, _bl_dst_int, _vector, l, false );
}
bl vector::intersects( translation& _translation, bl _bl_dst_int, const vector& _vector, const line& l,
bl _bl_facing_away ) const
{
	if( !_bl_facing_away )
	{
		if( abs( math<f32>::diff_radians( l.get_normal_direction(),
		get_direction( _vector ) + math<f32>::pi() ) ) >= math<f32>::pi_05() )
		{
			return false;
	} }

	vector post( *this   );
	vector dest( _vector );

	f32 deno = ( l.p2.y - l.p1.y ) * ( dest.x - post.x ) - ( l.p2.x - l.p1.x ) * ( dest.y - post.y );
	f32 num1 = ( l.p2.x - l.p1.x ) * ( post.y - l.p1.y ) - ( l.p2.y - l.p1.y ) * ( post.x - l.p1.x );
	f32 num2 = ( dest.x - post.x ) * ( post.y - l.p1.y ) - ( dest.y - post.y ) * ( post.x - l.p1.x );

	if( math<f32>::equals( deno ) )
	{
		if( math<f32>::equals( num1 ) && math<f32>::equals( num2 ) )
		{
			vector vector_intersection;

			if(      l.p1 == post || l.p2 == post ) vector_intersection = post;
			else if( l.p2 == dest || l.p1 == dest ) vector_intersection = dest;
			else if( l.p1.x > post.x && l.p2.x > post.x && l.p1.x > dest.x && l.p2.x > dest.x ) return false;
			else if( l.p1.y > post.y && l.p2.y > post.y && l.p1.y > dest.y && l.p2.y > dest.y ) return false;
			else if( l.p1.x < post.x && l.p2.x < post.x && l.p1.x < dest.x && l.p2.x < dest.x ) return false;
			else if( l.p1.y < post.y && l.p2.y < post.y && l.p1.y < dest.y && l.p2.y < dest.y ) return false;
			else
			{
				vector vector_min, vector_max;

				if(      ( post.x > l.p1.x && post.x > l.p2.x && post.x > dest.x )
				||       ( post.y > l.p1.y && post.y > l.p2.y && post.y > dest.y ) ) vector_max = post;
				else if( ( dest.x > l.p1.x && dest.x > l.p2.x && dest.x > post.x )
				||       ( dest.y > l.p1.y && dest.y > l.p2.y && dest.y > post.y ) ) vector_max = dest;
				else if( ( l.p1.x > post.x && l.p1.x > l.p2.x && l.p1.x > dest.x )
				||       ( l.p1.y > post.y && l.p1.y > l.p2.y && l.p1.y > dest.y ) ) vector_max = l.p1;
				else vector_max = l.p2;

				if( vector_max != post
				&& ( ( post.x < l.p1.x && post.x < l.p2.x && post.x < dest.x )
				||   ( post.y < l.p1.y && post.y < l.p2.y && post.y < dest.y ) ) ) vector_min = post;
				else if( vector_max != dest
				&& ( ( dest.x < l.p1.x && dest.x < l.p2.x && dest.x < post.x )
				||   ( dest.y < l.p1.y && dest.y < l.p2.y && dest.y < post.y ) ) ) vector_min = dest;
				else if( vector_max != l.p1
				&& ( ( l.p1.x < post.x && l.p1.x < l.p2.x && l.p1.x < dest.x )
				|| (   l.p1.y < post.y && l.p1.y < l.p2.y && l.p1.y < dest.y ) ) ) vector_min = l.p1;
				else vector_min = l.p2;

				vector_intersection = vector();

				if( post != vector_max && post != vector_min ) vector_intersection += post;
				if( dest != vector_max && dest != vector_min ) vector_intersection += dest;
				if( l.p1 != vector_max && l.p1 != vector_min ) vector_intersection += l.p1;
				if( l.p2 != vector_max && l.p2 != vector_min ) vector_intersection += l.p2;

				vector_intersection *= 0.5f;
			}

			_translation = translation( line( post, dest ), vector_intersection, l, _bl_dst_int );

			return true;
		}

		return false;
	}

	f32 f32_u1 = math<f32>::divide( num1, deno );
	if( f32_u1 < 0.f || f32_u1 > 1.f )
		return false;

	f32 f32_u2 = math<f32>::divide( num2, deno );
	if( f32_u2 < 0.f || f32_u2 > 1.f )
		return false;

	vector vector_intersection(
		post.x + f32_u1 * ( dest.x - post.x ),
		post.y + f32_u1 * ( dest.y - post.y ) );

	_translation = translation( line( post, dest ), vector_intersection, l, _bl_dst_int );

	return true;
}



// does vector collide with map

bl vector::collides( translation& _translation, const vector& _vector, const map2d::layer* _layer ) const
{
	return collides( _translation, get_direction( _vector ), get_distance( _vector ), _layer );
}
bl vector::collides( translation& _translation, f32 _f32_direction, f32 _f32_distance,
const map2d::layer* _layer ) const
{
	if( math<f32>::equals( _f32_distance ) )
		return false;

	vector vector_moved = get_moved( _f32_direction, _f32_distance );

	math<s32>::vec2 vec2_pos_src = _layer->get_index( *this        );
	math<s32>::vec2 vec2_pos_dst = _layer->get_index( vector_moved );

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
				multiline   multiline_tile = _layer->get( xx, yy ).get_multiline();
				translation translation_collision;

				for_i( line, std::deque, multiline_tile )
				{
					if( intersects( translation_collision, false, vector_moved, *i ) )
					{
						container_collisions.insert( translation_collision );
	} } } } }

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
					if( math<f32>::diff_radians( get_direction( vector_moved ),
					container_collisions[                i ].line_collision.get_direction() )
					<   math<f32>::diff_radians( get_direction( vector_moved ),
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



// draw

void vector::draw( const video::color& _color_1, const video::color& _color_2 ) const
{
	_color_1.bind();

	gl::begin(QUADS);
		gl::vert_2i( x - 1, y + 2 );
		gl::vert_2i( x + 2, y + 2 );
		gl::vert_2i( x + 2, y - 1 );
		gl::vert_2i( x - 1, y - 1 );
	gl::end();

	_color_2.bind();

	gl::begin(POINTS);
		gl::vert_2f( x, y );
	gl::end();
}
void vector::draw( const video::color& _color ) const
{
	_color.bind();

	gl::begin(POINTS);
		gl::vert_2f( x, y );
	gl::end();
}



/* end */
}}
#endif
