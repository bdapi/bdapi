
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_LINE_CPP
#define BDAPI_ENG2D_LINE_CPP
#include "eng2d_primitive.hpp"

/* includes */

// bdapi
#include "eng2d_const.hpp"
#include "sys_opengl.hpp"

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine line class implementation ******************************************************************/



// constructors

line::line()
{
	p1 = vector();
	p2 = vector();
}
line::line( f32 _f32_direction )
{
	p1 = vector(                );
	p2 = vector( _f32_direction );
}
line::line( const vector& _vector )
{
	p1 =  vector();
	p2 = _vector;
}
line::line( const vector& _vector_p1, const vector& _vector_p2 )
{
	p1 = _vector_p1;
	p2 = _vector_p2;
}
line::line( const line& _line )
{
	p1 = _line.p1;
	p2 = _line.p2;
}



// operator () s32

vector& line::operator () ( s32 n )
{
	return get(n);
}

// const operator () s32

const vector& line::operator () ( s32 n ) const
{
	return get(n);
}



// operator [] s32

vector& line::operator [] ( s32 n )
{
	return get(n);
}

// const operator [] s32

const vector& line::operator [] ( s32 n ) const
{
	return get(n);
}



// operator == line

bl line::operator == ( const line& _line ) const
{
	if( p1 == _line.p1 && p2 == _line.p2 )
	{
		return true;
	}

	return false;
}

// operator != line

bl line::operator != ( const line& _line ) const
{
	return !( *this == _line );
}



// operator += vector

line& line::operator += ( const vector& _vector )
{
	p1 += _vector;
	p2 += _vector;

	return *this;
}

// operator -= vector

line& line::operator -= ( const vector& _vector )
{
	p1 -= _vector;
	p2 -= _vector;

	return *this;
}

// operator *= vector

line& line::operator *= ( const vector& _vector )
{
	p1 *= _vector;
	p2 *= _vector;

	return *this;
}

// operator /= vector

line& line::operator /= ( const vector& _vector )
{
	p1 /= _vector;
	p2 /= _vector;

	return *this;
}

// operator + vector

line line::operator + ( const vector& _vector ) const
{
	return line( *this ) += _vector;
}

// operator - vector

line line::operator - ( const vector& _vector ) const
{
	return line( *this ) -= _vector;
}

// operator * vector

line line::operator * ( const vector& _vector ) const
{
	return line( *this ) *= _vector;
}

// operator / vector

line line::operator / ( const vector& _vector ) const
{
	return line( *this ) /= _vector;
}



// operator += f32

line& line::operator += ( f32 n )
{
	p2 = get_midpoint().get_moved( get_direction(), get_length() + n );

	return *this;
}

// operator -= f32

line& line::operator -= ( f32 n )
{
	p2 = get_midpoint().get_moved( get_direction(), get_length() - n );

	return *this;
}

// operator *= f32

line& line::operator *= ( f32 n )
{
	vector vector_midpoint = get_midpoint();

	vector vector_1 = vector_midpoint.get_moved( get_direction() - math<f32>::pi(), get_length() * 0.5f * n );
	vector vector_2 = vector_midpoint.get_moved( get_direction(),                   get_length() * 0.5f * n );

	p1 = vector_1;
	p2 = vector_2;

	return *this;
}

// operator /= f32

line& line::operator /= ( f32 n )
{
	vector vector_midpoint = get_midpoint();

	vector vector_1 = vector_midpoint.get_moved( get_direction() - math<f32>::pi(),
		math<f32>::divide( get_length() * 0.5f, n ) );

	vector vector_2 = vector_midpoint.get_moved( get_direction(),
		math<f32>::divide( get_length() * 0.5f, n ) );

	p1 = vector_1;
	p2 = vector_2;

	return *this;
}

// operator + f32

line line::operator + ( f32 n ) const
{
	return line( *this ) += n;
}

// operator - f32

line line::operator - ( f32 n ) const
{
	return line( *this ) -= n;
}

// operator * f32

line line::operator * ( f32 n ) const
{
	return line( *this ) *= n;
}

// operator / f32

line line::operator / ( f32 n ) const
{
	return line( *this ) /= n;
}



// get

vector& line::get( s32 n )
{
	if( n % 2 )
		return p2;

	return p1;
}

// get const

const vector& line::get( s32 n ) const
{
	if( n % 2 )
		return p2;

	return p1;
}



// is horizontal

bl line::is_horizontal() const
{
	f32 f32_direction = math<f32>::clamp_radians( get_direction() );

	if(      math<f32>::equals( f32_direction ) )
		return true;
	else if( math<f32>::equals( f32_direction, math<f32>::clamp_radians( math<f32>::radians() * 0.5f ) ) )
		return true;

	return false;
}

// is vertical

bl line::is_vertical() const
{
	f32 f32_direction = math<f32>::clamp_radians( get_direction() );

	if(      math<f32>::equals( f32_direction, math<f32>::clamp_radians( math<f32>::radians() * 0.25f ) ) )
		return true;
	else if( math<f32>::equals( f32_direction, math<f32>::clamp_radians( math<f32>::radians() * 0.75f ) ) )
		return true;

	return false;
}

// is sloped

bl line::is_sloped() const
{
	return !is_horizontal() && !is_vertical();
}

// is upwards

bl line::is_upwards() const
{
	f32 f32_direction = math<f32>::clamp_radians( get_normal_direction_right() );

	if( f32_direction > 0.f
	&&  f32_direction < math<f32>::pi() )
		return true;

	return false;
}

// is downwards

bl line::is_downwards() const
{
	f32 f32_direction = math<f32>::clamp_radians( get_normal_direction_left() );

	if( f32_direction > 0.f
	&&  f32_direction < math<f32>::pi() )
		return true;

	return false;
}

// is left

bl line::is_left() const
{
	f32 f32_direction = math<f32>::clamp_radians( get_direction() - math<f32>::pi() );

	if( f32_direction > 0.f
	&&  f32_direction < math<f32>::pi() )
		return true;

	return false;
}

// is right

bl line::is_right() const
{
	f32 f32_direction = math<f32>::clamp_radians( get_direction() );

	if( f32_direction > 0.f
	&&  f32_direction < math<f32>::pi() )
		return true;

	return false;
}



// get line type

s32 line::get_type() const
{
	f32 f32_direction = math<f32>::clamp_radians( get_direction() );

	if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() * -0.0625f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  0.0625f ) ) )
		return ENG2D_LINE_HORIZONTAL_BOTTOM;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  0.0625f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  0.1875f ) ) )
		return ENG2D_LINE_BOTTOM_LEFT_MINOR;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  0.1875f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  0.3125f ) ) )
		return ENG2D_LINE_BOTTOM_LEFT_MEDIUM;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  0.3125f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  0.4375f ) ) )
		return ENG2D_LINE_BOTTOM_LEFT_MAJOR;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  0.4375f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  0.5625f ) ) )
		return ENG2D_LINE_VERTICAL_LEFT;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  0.5625f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  0.6875f ) ) )
		return ENG2D_LINE_TOP_LEFT_MAJOR;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  0.6875f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  0.8125f ) ) )
		return ENG2D_LINE_TOP_LEFT_MEDIUM;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  0.8125f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  0.9375f ) ) )
		return ENG2D_LINE_TOP_LEFT_MINOR;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  0.9375f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  1.0625f ) ) )
		return ENG2D_LINE_HORIZONTAL_TOP;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  1.0625f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  1.1875f ) ) )
		return ENG2D_LINE_TOP_RIGHT_MINOR;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  1.1875f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  1.3125f ) ) )
		return ENG2D_LINE_TOP_RIGHT_MEDIUM;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  1.3125f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  1.4375f ) ) )
		return ENG2D_LINE_TOP_RIGHT_MAJOR;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  1.4375f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  1.5625f ) ) )
		return ENG2D_LINE_VERTICAL_RIGHT;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  1.5625f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  1.6875f ) ) )
		return ENG2D_LINE_BOTTOM_RIGHT_MAJOR;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  1.6875f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  1.8125f ) ) )
		return ENG2D_LINE_BOTTOM_RIGHT_MEDIUM;

	else if( math<f32>::within(
	math<f32>::clamp_radians( math<f32>::pi() *  1.8125f ), f32_direction,
	math<f32>::clamp_radians( math<f32>::pi() *  1.9375f ) ) )
		return ENG2D_LINE_BOTTOM_RIGHT_MINOR;

	else
		return ENG2D_LINE_HORIZONTAL_BOTTOM;
}



// get distance

f32 line::get_length() const
{
	return get_identity().get_length();
}

// get direction

f32 line::get_squared_length() const
{
	return get_identity().get_squared_length();
}



// get distance

f32 line::get_distance() const
{
	return p1.get_distance(p2);
}

// get direction

f32 line::get_direction() const
{
	return p1.get_direction(p2);
}

// get cross product

f32 line::get_cross_product() const
{
	return p1.get_cross_product(p2);
}

// get dot product

f32 line::get_dot_product() const
{
	return p1.get_dot_product(p2);
}



// get normal direction

f32 line::get_normal_direction() const
{
	return get_normal_direction_left();
}
f32 line::get_normal_direction( bl _bl_right ) const
{
	if( _bl_right )
		return get_normal_direction_right();

	return get_normal_direction_left();
}
f32 line::get_normal_direction_left() const
{
	return get_direction() - math<f32>::pi_05();
}
f32 line::get_normal_direction_right() const
{
	return get_direction() + math<f32>::pi_05();
}



// get normal

vector line::get_normal() const
{
	return get_normal_left();
}
vector line::get_normal( bl _bl_right ) const
{
	if( _bl_right )
		return get_normal_right();

	return get_normal_left();
}
vector line::get_normal_left() const
{
	return get_identity().get_normal_left() + p1;
}
vector line::get_normal_right() const
{
	return get_identity().get_normal_right() + p1;
}



// get unit vector

vector line::get_unit() const
{
	return get_identity().get_unit();
}

// get projection

vector line::get_projection( const vector& _vector ) const
{
	return get_identity().get_projection( _vector );
}



// get identity

vector line::get_identity() const
{
	return p2 - p1;
}
vector line::get_identity( const vector& _vector ) const
{
	return get_identity() + _vector;
}



// get midpoint

vector line::get_midpoint() const
{
	return get_midpoint( 0.5f );
}
vector line::get_midpoint( f32 _f32_point ) const
{
	return vector( ( p1.x + p2.x ) * _f32_point, ( p1.y + p2.y ) * _f32_point );
}

// get nearest

vector line::get_nearest( const vector& _vector ) const
{
	math<f32>::vec3 point = glm::closestPointOnLine( math<f32>::vec3( _vector.x, _vector.y, 0.f ),
		math<f32>::vec3( p1.x, p1.y, 0.f ), math<f32>::vec3( p2.x, p2.y, 0.f ) );

	return vector( point.x, point.y );
}



// get moved

line line::get_moved( f32 _f32_direction, f32 _f32_distance ) const
{
	line line_moved( *this );

	line_moved += vector().get_moved( _f32_direction, _f32_distance );

	return line_moved;
}



// get flipped

line line::get_flipped() const
{
	return line( p2, p1 );
}



// get normal line

line line::get_normal_line() const
{
	return get_normal_line_left();
}
line line::get_normal_line( bl _bl_right ) const
{
	if( _bl_right )
		return get_normal_line_right();

	return get_normal_line_left();
}
line line::get_normal_line_left() const
{
	return line( p1, get_normal_left() );
}
line line::get_normal_line_right() const
{
	return line( p1, get_normal_right() );
}



// get identity line

line line::get_identity_line() const
{
	return line( get_identity() );
}
line line::get_identity_line( const vector& _vector ) const
{
	return line( get_identity() ) + _vector;
}



// get intersection

bl line::get_intersection( vector& _vector, const line& l ) const
{
	return get_intersection( _vector, l, false );
}
bl line::get_intersection( vector& _vector, const line& l, bl _bl_facing_away ) const
{
	if( !_bl_facing_away )
	{
		if( abs( math<f32>::diff_radians( l.get_normal_direction(),
		get_direction() + math<f32>::pi() ) ) >= math<f32>::pi_05() )
		{
			return false;
	} }

	f32 deno = ( l.p2.y - l.p1.y ) * ( p2.x - p1.x   ) - ( l.p2.x - l.p1.x ) * ( p2.y - p1.y   );
	f32 num1 = ( l.p2.x - l.p1.x ) * ( p1.y - l.p1.y ) - ( l.p2.y - l.p1.y ) * ( p1.x - l.p1.x );
	f32 num2 = (   p2.x - p1.x   ) * ( p1.y - l.p1.y ) - (   p2.y - p1.y   ) * ( p1.x - l.p1.x );

	if( math<f32>::equals( deno ) )
	{
		if( math<f32>::equals( num1 ) && math<f32>::equals( num2 ) )
		{
			if(      l.p1 == p1 || l.p2 == p1 ) _vector = p1;
			else if( l.p2 == p2 || l.p1 == p2 ) _vector = p2;
			else if( l.p1.x > p1.x && l.p2.x > p1.x && l.p1.x > p2.x && l.p2.x > p2.x ) return false;
			else if( l.p1.y > p1.y && l.p2.y > p1.y && l.p1.y > p2.y && l.p2.y > p2.y ) return false;
			else if( l.p1.x < p1.x && l.p2.x < p1.x && l.p1.x < p2.x && l.p2.x < p2.x ) return false;
			else if( l.p1.y < p1.y && l.p2.y < p1.y && l.p1.y < p2.y && l.p2.y < p2.y ) return false;
			else
			{
				vector vector_min, vector_max;

				if(      (   p1.x > l.p1.x &&   p1.x > l.p2.x &&   p1.x > p2.x )
				||       (   p1.y > l.p1.y &&   p1.y > l.p2.y &&   p1.y > p2.y ) ) vector_max = p1;
				else if( (   p2.x > l.p1.x &&   p2.x > l.p2.x &&   p2.x > p1.x )
				||       (   p2.y > l.p1.y &&   p2.y > l.p2.y &&   p2.y > p1.y ) ) vector_max = p2;
				else if( ( l.p1.x > p1.x   && l.p1.x > l.p2.x && l.p1.x > p2.x )
				||       ( l.p1.y > p1.y   && l.p1.y > l.p2.y && l.p1.y > p2.y ) ) vector_max = l.p1;
				else vector_max = l.p2;

				if( vector_max != p1
				&& ( (   p1.x < l.p1.x &&   p1.x < l.p2.x &&   p1.x < p2.x )
				||   (   p1.y < l.p1.y &&   p1.y < l.p2.y &&   p1.y < p2.y ) ) ) vector_min = p1;
				else if( vector_max != p2
				&& ( (   p2.x < l.p1.x &&   p2.x < l.p2.x &&   p2.x < p1.x )
				||   (   p2.y < l.p1.y &&   p2.y < l.p2.y &&   p2.y < p1.y ) ) ) vector_min = p2;
				else if( vector_max != l.p1
				&& ( ( l.p1.x < p1.x   && l.p1.x < l.p2.x && l.p1.x < p2.x )
				|| (   l.p1.y < p1.y   && l.p1.y < l.p2.y && l.p1.y < p2.y ) ) ) vector_min = l.p1;
				else vector_min = l.p2;

				_vector = vector();

				if(   p1 != vector_max &&   p1 != vector_min ) _vector +=   p1;
				if(   p2 != vector_max &&   p2 != vector_min ) _vector +=   p2;
				if( l.p1 != vector_max && l.p1 != vector_min ) _vector += l.p1;
				if( l.p2 != vector_max && l.p2 != vector_min ) _vector += l.p2;

				_vector *= 0.5f;
			}

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

	_vector = vector( p1.x + f32_u1 * ( p2.x - p1.x ), p1.y + f32_u1 * ( p2.y - p1.y ) );

	return true;
}



// does line intersect line

bl line::intersects( translation& _translation, f32 _f32_direction, f32 _f32_distance, const line& _line )
const
{
	translation translation_this;

	f32 f32_maximum_distance = _f32_distance;

	bl bl_overlapping = false;

	fori(2)
	{
		if( get(i).intersects( translation_this, false, _f32_direction, _f32_distance, _line, true ) )
		{
			bl_overlapping = true;

			if( translation_this.get_collision_distance() < f32_maximum_distance )
			{
				f32_maximum_distance = translation_this.get_collision_distance();

				_translation = translation_this;
	} } }

	fori(2)
	{
		if( _line(i).intersects( translation_this, true, _f32_direction - math<f32>::pi(), _f32_distance, *this,
		true ) )
		{
			bl_overlapping = true;

			if( translation_this.get_collision_distance() < f32_maximum_distance )
			{
				f32_maximum_distance = translation_this.get_collision_distance();

				_translation = translation_this;
	} } }

	return bl_overlapping;
}



// does line intersect multiline

bl line::intersects( translation& _translation, f32 _f32_direction, f32 _f32_distance,
const multiline& _multiline ) const
{
	translation translation_this;

	f32 f32_maximum_distance = _f32_distance;

	bl bl_overlapping = false;

	c_for_i( line, std::deque, _multiline )
	{
		forj(2)
		{
			if( get(j).intersects( translation_this, false, _f32_direction, _f32_distance, *i ) )
			{
				bl_overlapping = true;

				if( translation_this.get_collision_distance() < f32_maximum_distance )
				{
					f32_maximum_distance = translation_this.get_collision_distance();

					_translation = translation_this;
	} } } }

	c_for_i( line, std::deque, _multiline )
	{
		forj(2)
		{
			if( i->get(j).intersects( translation_this, true,
			math<f32>::clamp_radians( _f32_direction - math<f32>::pi() ), _f32_distance, *this, true ) )
			{
				bl_overlapping = true;

				if( translation_this.get_collision_distance() < f32_maximum_distance )
				{
					f32_maximum_distance = translation_this.get_collision_distance();

					_translation = translation_this;
	} } } }

	return bl_overlapping;
}



// does line intersect polygon

bl line::intersects( translation& _translation, f32 _f32_direction, f32 _f32_distance,
const polygon& _polygon ) const
{
	translation translation_this;

	f32 f32_maximum_distance = _f32_distance;

	bl bl_overlapping = false;

	c_for_i( line, std::deque, _polygon )
	{
		forj(2)
		{
			if( get(j).intersects( translation_this, false, _f32_direction, _f32_distance, *i ) )
			{
				bl_overlapping = true;

				if( translation_this.get_collision_distance() < f32_maximum_distance )
				{
					f32_maximum_distance = translation_this.get_collision_distance();

					_translation = translation_this;
	} } } }

	c_for_i( line, std::deque, _polygon )
	{
		if( i->p1.intersects( translation_this, true,
		math<f32>::clamp_radians( _f32_direction - math<f32>::pi() ), _f32_distance, *this, true ) )
		{
			bl_overlapping = true;

			if( translation_this.get_collision_distance() < f32_maximum_distance )
			{
				f32_maximum_distance = translation_this.get_collision_distance();

				_translation = translation_this;
	} } }

	return bl_overlapping;
}



// draw

void line::draw( const video::color& _color_1, const video::color& _color_2 ) const
{
	   draw(           _color_2 );
	p1.draw( _color_1, _color_2 );
	p2.draw( _color_1, _color_2 );
}
void line::draw( const video::color& _color ) const
{
	_color.bind();

	gl::begin(LINES);
		gl::vert_2f( p1.x + 0.5f, p1.y );
		gl::vert_2f( p2.x + 0.5f, p2.y );
	gl::end();
}



/* end */
}}
#endif
