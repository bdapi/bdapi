
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_MULTILINE_CPP
#define BDAPI_ENG2D_MULTILINE_CPP
#include "eng2d_primitive.hpp"

/* includes */

// bdapi
#include "eng2d_const.hpp"
#include "eng2d_map2d.hpp"

// namespaces
namespace bdapi {
namespace eng2d {



/* static variables *************************************************************************************/



static       vector       __vertex_dummy__ = vector();
static const vector __const_vertex_dummy__ = vector();

static       line       __line_dummy__ = line();
static const line __const_line_dummy__ = line();



/* 2d engine multiline class implementation *************************************************************/



// constructors

multiline::multiline() : util::container< line, std::deque >()
{
}
multiline::multiline( const map2d::tile& _tile )
{
	*this = multiline( static_cast<const multiline&>( _tile.get_polygon() ) );
}
multiline::multiline( const multiline& _multiline ) :
util::container< line, std::deque >( static_cast<const util::container< line, std::deque >&>( _multiline ) )
{
}



// operator += vector

multiline& multiline::operator += ( const vector& _vector )
{
	util::container< line, std::deque >& m = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, m )
		*i += _vector;

	return *this;
}

// operator -= vector

multiline& multiline::operator -= ( const vector& _vector )
{
	util::container< line, std::deque >& m = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, m )
		*i -= _vector;

	return *this;
}

// operator *= vector

multiline& multiline::operator *= ( const vector& _vector )
{
	util::container< line, std::deque >& m = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, m )
		*i *= _vector;

	return *this;
}

// operator /= vector

multiline& multiline::operator /= ( const vector& _vector )
{
	util::container< line, std::deque >& m = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, m )
		*i /= _vector;

	return *this;
}

// operator + vector

multiline multiline::operator + ( const vector& _vector ) const
{
	return multiline( *this ) += _vector;
}

// operator - vector

multiline multiline::operator - ( const vector& _vector ) const
{
	return multiline( *this ) -= _vector;
}

// operator * vector

multiline multiline::operator * ( const vector& _vector ) const
{
	return multiline( *this ) *= _vector;
}

// operator / vector

multiline multiline::operator / ( const vector& _vector ) const
{
	return multiline( *this ) /= _vector;
}



// operator += f32

multiline& multiline::operator += ( f32 n )
{
	util::container< line, std::deque >& m = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, m )
		*i += n;

	return *this;
}

// operator -= f32

multiline& multiline::operator -= ( f32 n )
{
	util::container< line, std::deque >& m = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, m )
		*i -= n;

	return *this;
}

// operator *= f32

multiline& multiline::operator *= ( f32 n )
{
	util::container< line, std::deque >& m = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, m )
		*i *= n;

	return *this;
}

// operator /= f32

multiline& multiline::operator /= ( f32 n )
{
	util::container< line, std::deque >& m = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, m )
		*i /= n;

	return *this;
}

// operator + f32

multiline multiline::operator + ( f32 n ) const
{
	return multiline( *this ) += n;
}

// operator - f32

multiline multiline::operator - ( f32 n ) const
{
	return multiline( *this ) -= n;
}

// operator * f32

multiline multiline::operator * ( f32 n ) const
{
	return multiline( *this ) *= n;
}

// operator / f32

multiline multiline::operator / ( f32 n ) const
{
	return multiline( *this ) /= n;
}



// get vector

vector& multiline::get_vertex( s32 n )
{
	if( is_empty() )
		return __vertex_dummy__;

	return get(n).p1;
}

// get const vector

const vector& multiline::get_vertex( s32 n ) const
{
	if( is_empty() )
		return __const_vertex_dummy__;

	return get(n).p1;
}



// set tile

multiline& multiline::set_tile( const map2d::tile& _tile )
{
	map2d::layer* layer_tile = _tile.get_layer();

	s32 x = _tile.get_index_x();
	s32 y = _tile.get_index_y();

	s32 w = layer_tile->get_w();
	s32 h = layer_tile->get_h();

	s32 types[5];
	                                  types[0] =                       _tile.get_type();
	if( math<s32>::within( y-1, h ) ) types[1] = layer_tile->get( x,   y-1 ).get_type(); else types[1] = 0;
	if( math<s32>::within( x+1, w ) ) types[2] = layer_tile->get( x+1, y   ).get_type(); else types[2] = 0;
	if( math<s32>::within( y+1, h ) ) types[3] = layer_tile->get( x,   y+1 ).get_type(); else types[3] = 0;
	if( math<s32>::within( x-1, w ) ) types[4] = layer_tile->get( x-1, y   ).get_type(); else types[4] = 0;

	clear();

	fori(5)
	{
		if( math<s32>::within( types[i], 22 ) )
		{
			s32 b = (*__s32_tile_border_types__[i])[ _tile.get_type() ][ types[i] ];

			if( math<s32>::within( b, 22 ) )
			{
				line line_tile( layer_tile->get_line_type(b) + _tile.get_position() );

				if( i == 0 && __bl_tile_line_type_flip__[ _tile.get_type() ] )
					line_tile = line_tile.get_flipped();

				insert( line_tile );
	} } }

	return *this;
}



// get aabb

line multiline::get_aabb() const
{
	if( is_empty() )
		return __line_dummy__;

	vector vector_min, vector_max( get_vertex(0).x, get_vertex(0).y );

	for( s32 i = 1; i < get_size(); i++ )
	{
		if( get_vertex(i).x < vector_min.x )
			vector_min.x = get_vertex(i).x;

		if( get_vertex(i).x > vector_max.x )
			vector_max.x = get_vertex(i).x;

		if( get_vertex(i).y < vector_min.y )
			vector_min.y = get_vertex(i).y;

		if( get_vertex(i).y > vector_max.y )
			vector_max.y = get_vertex(i).y;
	}

	return line( vector_min, vector_max );
}



// get moved

multiline multiline::get_moved( f32 _f32_direction, f32 _f32_distance ) const
{
	multiline multiline_moved( *this );

	multiline_moved += vector().get_moved( _f32_direction, _f32_distance );

	return multiline_moved;
}



// does multiline intersect line

bl multiline::intersects( translation& _translation, f32 _f32_direction, f32 _f32_distance,
const line& _line ) const
{
	translation translation_this;

	f32 f32_maximum_distance = _f32_distance;

	bl bl_overlapping = false;

	const util::container< line, std::deque >& m
		= static_cast<const util::container< line, std::deque >&>( *this );

	c_for_i( line, std::deque, m )
	{
		if( i->p1.intersects( translation_this, false, _f32_direction, _f32_distance, _line, true ) )
		{
			bl_overlapping = true;

			if( translation_this.get_collision_distance() < f32_maximum_distance )
			{
				f32_maximum_distance = translation_this.get_collision_distance();

				_translation = translation_this;
	} } }

	c_for_i( line, std::deque, m )
	{
		forj(2)
		{
			if( _line(j).intersects( translation_this, true,
			math<f32>::clamp_radians( _f32_direction - math<f32>::pi() ), _f32_distance, *i ) )
			{
				bl_overlapping = true;

				if( translation_this.get_collision_distance() < f32_maximum_distance )
				{
					f32_maximum_distance = translation_this.get_collision_distance();

					_translation = translation_this;
	} } } }

	return bl_overlapping;
}

// does multiline intersect multiline

bl multiline::intersects( translation& _translation, f32 _f32_direction, f32 _f32_distance,
const multiline& _multiline ) const
{
	translation translation_this;

	f32 f32_maximum_distance = _f32_distance;

	bl bl_overlapping = false;

	const util::container< line, std::deque >& m1
		= static_cast<const util::container< line, std::deque >&>( *this );

	const util::container< line, std::deque >& m2
		= static_cast<const util::container< line, std::deque >&>( _multiline );

	c_for_i( line, std::deque, m1 )
	{
		c_for_j( line, std::deque, m2 )
		{
			fork(2)
			{
				if( i->get(k).intersects( translation_this, false, _f32_direction, _f32_distance, *j ) )
				{
					bl_overlapping = true;

					if( translation_this.get_collision_distance() < f32_maximum_distance )
					{
						f32_maximum_distance = translation_this.get_collision_distance();

						_translation = translation_this;
	} } } } }

	c_for_i( line, std::deque, m1 )
	{
		fork(2)
		{
			c_for_j( line, std::deque, m2 )
			{
				if( i->get(k).intersects( translation_this, true,
				math<f32>::clamp_radians( _f32_direction - math<f32>::pi() ), _f32_distance, *j ) )
				{
					bl_overlapping = true;

					if( translation_this.get_collision_distance() < f32_maximum_distance )
					{
						f32_maximum_distance = translation_this.get_collision_distance();

						_translation = translation_this;
	} } } } }

	return bl_overlapping;
}

// does multiline intersect polygon

bl multiline::intersects( translation& _translation, f32 _f32_direction, f32 _f32_distance,
const polygon& _polygon ) const
{
	translation translation_this;

	f32 f32_maximum_distance = _f32_distance;

	bl bl_overlapping = false;

	const util::container< line, std::deque >& m
		= static_cast<const util::container< line, std::deque >&>( *this );

	const util::container< line, std::deque >& p
		= static_cast<const util::container< line, std::deque >&>( _polygon );

	c_for_i( line, std::deque, m )
	{
		c_for_j( line, std::deque, p )
		{
			if( i->p1.intersects( translation_this, false, _f32_direction, _f32_distance, *j ) )
			{
				bl_overlapping = true;

				if( translation_this.get_collision_distance() < f32_maximum_distance )
				{
					f32_maximum_distance = translation_this.get_collision_distance();

					_translation = translation_this;
	} } } }

	c_for_i( line, std::deque, m )
	{
		c_for_j( line, std::deque, p )
		{
			if( i->p1.intersects( translation_this, true, _f32_direction - math<f32>::pi(), _f32_distance, *j ) )
			{
				bl_overlapping = true;

				if( translation_this.get_collision_distance() < f32_maximum_distance )
				{
					f32_maximum_distance = translation_this.get_collision_distance();

					_translation = translation_this;
	} } } }

	return bl_overlapping;
}



// draw

void multiline::draw( const video::color& _color_1, const video::color& _color_2 ) const
{
	const util::container< line, std::deque >& m
		= static_cast<const util::container< line, std::deque >&>( *this );

	c_for_i( line, std::deque, m )
		i->draw( _color_1, _color_2 );
}
void multiline::draw( const video::color& _color ) const
{
	const util::container< line, std::deque >& m
		= static_cast<const util::container< line, std::deque >&>( *this );

	c_for_i( line, std::deque, m )
		i->draw( _color );
}



/* end */
}}
#endif
