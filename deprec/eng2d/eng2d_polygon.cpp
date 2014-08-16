
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_POLYGON_CPP
#define BDAPI_ENG2D_POLYGON_CPP
#include "eng2d_primitive.hpp"

/* includes */

// bdapi
#include "eng2d_map2d.hpp"
#include "sys_opengl.hpp"

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine polygon class implementation ***************************************************************/



// constructors

polygon::polygon() : multiline()
{
}
polygon::polygon( const vector& v1, const vector& v2, const vector& v3 ) : multiline()
{
	insert( line( v1, v2 ) );
	insert( line( v2, v3 ) );
	insert( line( v3, v1 ) );
}
polygon::polygon( const vector& v1, const vector& v2, const vector& v3, const vector& v4 ) : multiline()
{
	insert( line( v1, v2 ) );
	insert( line( v2, v3 ) );
	insert( line( v3, v4 ) );
	insert( line( v4, v1 ) );
}
polygon::polygon( const map2d::tile& _tile ) : multiline()
{
	*this = _tile.get_polygon();
}
polygon::polygon( const polygon& _polygon ) : multiline( static_cast<const multiline&>( _polygon ) )
{
}



// operator += vector

polygon& polygon::operator += ( const vector& _vector )
{
	util::container< line, std::deque >& p = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, p )
		*i += _vector;

	return *this;
}

// operator -= vector

polygon& polygon::operator -= ( const vector& _vector )
{
	util::container< line, std::deque >& p = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, p )
		*i -= _vector;

	return *this;
}

// operator *= vector

polygon& polygon::operator *= ( const vector& _vector )
{
	util::container< line, std::deque >& p = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, p )
		*i *= _vector;

	return *this;
}

// operator /= vector

polygon& polygon::operator /= ( const vector& _vector )
{
	util::container< line, std::deque >& p = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, p )
		*i /= _vector;

	return *this;
}

// operator + vector

polygon polygon::operator + ( const vector& _vector ) const
{
	return polygon( *this ) += _vector;
}

// operator - vector

polygon polygon::operator - ( const vector& _vector ) const
{
	return polygon( *this ) -= _vector;
}

// operator * vector

polygon polygon::operator * ( const vector& _vector ) const
{
	return polygon( *this ) *= _vector;
}

// operator / vector

polygon polygon::operator / ( const vector& _vector ) const
{
	return polygon( *this ) /= _vector;
}



// operator += f32

polygon& polygon::operator += ( f32 n )
{
	util::container< line, std::deque >& p = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, p )
		*i += n;

	return *this;
}

// operator -= f32

polygon& polygon::operator -= ( f32 n )
{
	util::container< line, std::deque >& p = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, p )
		*i -= n;

	return *this;
}

// operator *= f32

polygon& polygon::operator *= ( f32 n )
{
	util::container< line, std::deque >& p = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, p )
		*i *= n;

	return *this;
}

// operator /= f32

polygon& polygon::operator /= ( f32 n )
{
	util::container< line, std::deque >& p = static_cast<util::container< line, std::deque >&>( *this );

	for_i( line, std::deque, p )
		*i /= n;

	return *this;
}

// operator + f32

polygon polygon::operator + ( f32 n ) const
{
	return polygon( *this ) += n;
}

// operator - f32

polygon polygon::operator - ( f32 n ) const
{
	return polygon( *this ) -= n;
}

// operator * f32

polygon polygon::operator * ( f32 n ) const
{
	return polygon( *this ) *= n;
}

// operator / f32

polygon polygon::operator / ( f32 n ) const
{
	return polygon( *this ) /= n;
}



// get moved

polygon polygon::get_moved( f32 _f32_direction, f32 _f32_distance ) const
{
	polygon polygon_moved( *this );

	polygon_moved += vector().get_moved( _f32_direction, _f32_distance );

	return polygon_moved;
}



// draw

void polygon::draw( const video::color& _color_1, const video::color& _color_2 ) const
{
	draw( _color_1 );

	static_cast<multiline>(*this).draw( _color_2 );
}
void polygon::draw( const video::color& _color ) const
{
	switch( get_size() )
	{
		case 3:
		{
			_color.bind();

			gl::begin(TRIANGLES);
				gl::vert_2f( get_vertex(2).x + 0.5f, get_vertex(2).y );
				gl::vert_2f( get_vertex(1).x + 0.5f, get_vertex(1).y );
				gl::vert_2f( get_vertex(0).x + 0.5f, get_vertex(0).y );
			gl::end();

			break;
		}
		case 4:
		{
			_color.bind();

			gl::begin(QUADS);
				gl::vert_2f( get_vertex(3).x + 0.5f, get_vertex(3).y );
				gl::vert_2f( get_vertex(2).x + 0.5f, get_vertex(2).y );
				gl::vert_2f( get_vertex(1).x + 0.5f, get_vertex(1).y );
				gl::vert_2f( get_vertex(0).x + 0.5f, get_vertex(0).y );
			gl::end();
} } }



/* end */
}}
#endif
