
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_MOBILE_CPP
#define BDAPI_ENG2D_MOBILE_CPP
#include "eng2d_dynamic.hpp"

/* includes */

// bdapi
#include "eng2d_const.hpp"
#include "sys_core.hpp"

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine mobile class implementation ****************************************************************/



// constructors

mobile::mobile() : vector()
{
	direction = 0.f;
	velocity  = 0.f;
}
mobile::mobile( const vector& _vector ) : vector( _vector )
{
	direction = 0.f;
	velocity  = 0.f;
}
mobile::mobile( const vector& _vector, f32 _f32_direction, f32 _f32_velocity ) : vector( _vector )
{
	direction = _f32_direction;
	velocity  = _f32_velocity;
}
mobile::mobile( const mobile& _mobile ) : vector( static_cast<const vector&>( _mobile ) )
{
	direction = _mobile.direction;
	velocity  = _mobile.velocity;
}



// get position

vector& mobile::position()
{
	return static_cast<vector&>(*this);
}

// get constant position

const vector& mobile::position() const
{
	return static_cast<const vector&>(*this);
}



// operator ()

vector& mobile::operator () ()
{
	return position();
}

// const operator ()

const vector& mobile::operator () () const
{
	return position();
}



// operator == mobile

bl mobile::operator == ( const mobile& _mobile ) const
{
	if( position() == _mobile.position()
	&& math<f32>::equals( direction, _mobile.direction )
	&& math<f32>::equals( velocity,  _mobile.velocity  ) )
	{
		return true;
	}

	return false;
}

// operator != mobile

bl mobile::operator != ( const mobile& _mobile ) const
{
	return !( *this == _mobile );
}



// get distance from destination

f32 mobile::get_distance() const
{
	return get_distance( false, 1.f  );
}
f32 mobile::get_distance( f32 _f32_rate ) const
{
	return get_distance( false, _f32_rate );
}
f32 mobile::get_distance( bl _bl_fixed ) const
{
	return get_distance( _bl_fixed, 1.f  );
}
f32 mobile::get_distance( bl _bl_fixed, f32 _f32_rate ) const
{
	return position().get_distance( get_destination( _bl_fixed, _f32_rate ) );
}



// set velocity

mobile& mobile::set_velocity( f32 _f32_velocity )
{
	return set_velocity( _f32_velocity, false, 1.f );
}
mobile& mobile::set_velocity( f32 _f32_velocity, f32 _f32_rate )
{
	return set_velocity( _f32_velocity, false, _f32_rate );
}
mobile& mobile::set_velocity( f32 _f32_velocity, bl _bl_fixed )
{
	return set_velocity( _f32_velocity, _bl_fixed, 1.f );
}
mobile& mobile::set_velocity( f32 _f32_velocity, bl _bl_fixed, f32 _f32_rate )
{
	if( _bl_fixed )
		velocity = _f32_velocity * _f32_rate;
	else
		velocity = _f32_velocity * _f32_rate * sys::delta();

	return *this;
}



// get distance from vector

f32 mobile::get_distance( const vector& _vector ) const
{
	return position().get_distance( _vector );
}

// get distance from mobile

f32 mobile::get_distance( const mobile& _mobile ) const
{
	return position().get_distance( _mobile );
}



// get destination

vector mobile::get_destination() const
{
	return get_destination( false, 1.f  );
}
vector mobile::get_destination( f32 _f32_rate ) const
{
	return get_destination( false, _f32_rate );
}
vector mobile::get_destination( bl _bl_fixed ) const
{
	return get_destination( _bl_fixed, 1.f  );
}
vector mobile::get_destination( bl _bl_fixed, f32 _f32_rate ) const
{
	if( _bl_fixed )
	{
		return vector(
			x + velocity * _f32_rate * cos( direction ),
			y + velocity * _f32_rate * sin( direction ) );
	}
	else
	{
		return vector(
			x + velocity * _f32_rate * cos( direction ) * sys::delta(),
			y + velocity * _f32_rate * sin( direction ) * sys::delta() );
} }

// set destination

mobile& mobile::set_destination( f32 _f32_x, f32 _f32_y )
{
	return set_destination( vector( _f32_x, _f32_y ), false, 1.f );
}
mobile& mobile::set_destination( f32 _f32_x, f32 _f32_y, f32 _f32_rate )
{
	return set_destination( vector( _f32_x, _f32_y ), false, _f32_rate );
}
mobile& mobile::set_destination( f32 _f32_x, f32 _f32_y, bl _bl_fixed )
{
	return set_destination( vector( _f32_x, _f32_y ), _bl_fixed, 1.f );
}
mobile& mobile::set_destination( f32 _f32_x, f32 _f32_y, bl _bl_fixed, f32 _f32_rate )
{
	return set_destination( vector( _f32_x, _f32_y ), _bl_fixed, _f32_rate );
}
mobile& mobile::set_destination( const vector& _vector_destination )
{
	return set_destination( _vector_destination, false, 1.f );
}
mobile& mobile::set_destination( const vector& _vector_destination, f32 _f32_rate )
{
	return set_destination( _vector_destination, false, _f32_rate );
}
mobile& mobile::set_destination( const vector& _vector_destination, bl _bl_fixed )
{
	return set_destination( _vector_destination, _bl_fixed, 1.f );
}
mobile& mobile::set_destination( const vector& _vector_destination, bl _bl_fixed, f32 _f32_rate )
{
	direction = position().get_direction( _vector_destination );

	return set_velocity( position().get_distance( _vector_destination ), _bl_fixed, _f32_rate );
}



// get offset

vector mobile::get_offset() const
{
	return get_offset( false, 1.f );
}
vector mobile::get_offset( f32 _f32_rate ) const
{
	return get_offset( false, _f32_rate );
}
vector mobile::get_offset( bl _bl_fixed ) const
{
	return get_offset( _bl_fixed, 1.f );
}
vector mobile::get_offset( bl _bl_fixed, f32 _f32_rate ) const
{
	return get_destination( _bl_fixed, _f32_rate ) - position();
}

// get offset x

f32 mobile::get_offset_x() const
{
	return get_offset_x( false, 1.f );
}
f32 mobile::get_offset_x( f32 _f32_rate ) const
{
	return get_offset_x( false, _f32_rate );
}
f32 mobile::get_offset_x( bl _bl_fixed ) const
{
	return get_offset_x( _bl_fixed, 1.f );
}
f32 mobile::get_offset_x( bl _bl_fixed, f32 _f32_rate ) const
{
	return get_offset( _bl_fixed, _f32_rate ).x;
}

// get offset y

f32 mobile::get_offset_y() const
{
	return get_offset_y( false, 1.f );
}
f32 mobile::get_offset_y( f32 _f32_rate ) const
{
	return get_offset_y( false, _f32_rate );
}
f32 mobile::get_offset_y( bl _bl_fixed ) const
{
	return get_offset_y( _bl_fixed, 1.f );
}
f32 mobile::get_offset_y( bl _bl_fixed, f32 _f32_rate ) const
{
	return get_offset( _bl_fixed, _f32_rate ).y;
}



// set offset

mobile& mobile::set_offset( f32 _f32_x, f32 _f32_y )
{
	return set_offset( vector( _f32_x, _f32_y ), false, 1.f );
}
mobile& mobile::set_offset( f32 _f32_x, f32 _f32_y, f32 _f32_rate )
{
	return set_offset( vector( _f32_x, _f32_y ), false, _f32_rate );
}
mobile& mobile::set_offset( f32 _f32_x, f32 _f32_y, bl _bl_fixed )
{
	return set_offset( vector( _f32_x, _f32_y ), _bl_fixed, 1.f );
}
mobile& mobile::set_offset( f32 _f32_x, f32 _f32_y, bl _bl_fixed, f32 _f32_rate )
{
	return set_offset( vector( _f32_x, _f32_y ), _bl_fixed, _f32_rate );
}
mobile& mobile::set_offset( const vector& _vector )
{
	return set_offset( _vector, false, 1.f );
}
mobile& mobile::set_offset( const vector& _vector, f32 _f32_rate )
{
	return set_offset( _vector, false, _f32_rate );
}
mobile& mobile::set_offset( const vector& _vector, bl _bl_fixed )
{
	return set_offset( _vector, _bl_fixed, 1.f );
}
mobile& mobile::set_offset( const vector& _vector, bl _bl_fixed, f32 _f32_rate )
{
	return set_destination( position() + _vector, _bl_fixed, _f32_rate );
}

// set offset x

mobile& mobile::set_offset_x( f32 _f32_x )
{
	return set_offset_x( _f32_x, false, 1.f );
}
mobile& mobile::set_offset_x( f32 _f32_x, f32 _f32_rate )
{
	return set_offset_x( _f32_x, false, _f32_rate );
}
mobile& mobile::set_offset_x( f32 _f32_x, bl _bl_fixed )
{
	return set_offset_x( _f32_x, _bl_fixed, 1.f );
}
mobile& mobile::set_offset_x( f32 _f32_x, bl _bl_fixed, f32 _f32_rate )
{
	return set_offset( vector( _f32_x, 0.f ), _bl_fixed, _f32_rate );
}

// set offset y

mobile& mobile::set_offset_y( f32 _f32_y )
{
	return set_offset_y( _f32_y, false, 1.f );
}
mobile& mobile::set_offset_y( f32 _f32_y, f32 _f32_rate )
{
	return set_offset_y( _f32_y, false, _f32_rate );
}
mobile& mobile::set_offset_y( f32 _f32_y, bl _bl_fixed )
{
	return set_offset_y( _f32_y, _bl_fixed, 1.f );
}
mobile& mobile::set_offset_y( f32 _f32_y, bl _bl_fixed, f32 _f32_rate )
{
	return set_offset( vector( 0.f, _f32_y ), _bl_fixed, _f32_rate );
}



// shift offset

mobile& mobile::shift_offset( f32 _f32_x, f32 _f32_y )
{
	return shift_offset( vector( _f32_x, _f32_y ), false, 1.f );
}
mobile& mobile::shift_offset( f32 _f32_x, f32 _f32_y, f32 _f32_rate )
{
	return shift_offset( vector( _f32_x, _f32_y ), false, _f32_rate );
}
mobile& mobile::shift_offset( f32 _f32_x, f32 _f32_y, bl _bl_fixed )
{
	return shift_offset( vector( _f32_x, _f32_y ), _bl_fixed, 1.f );
}
mobile& mobile::shift_offset( f32 _f32_x, f32 _f32_y, bl _bl_fixed, f32 _f32_rate )
{
	return shift_offset( vector( _f32_x, _f32_y ), _bl_fixed, _f32_rate );
}
mobile& mobile::shift_offset( const vector& _vector )
{
	return shift_offset( _vector, false, 1.f );
}
mobile& mobile::shift_offset( const vector& _vector, f32 _f32_rate )
{
	return shift_offset( _vector, false, _f32_rate );
}
mobile& mobile::shift_offset( const vector& _vector, bl _bl_fixed )
{
	return shift_offset( _vector, _bl_fixed, 1.f );
}
mobile& mobile::shift_offset( const vector& _vector, bl _bl_fixed, f32 _f32_rate )
{
	return set_offset( get_offset( _bl_fixed, _f32_rate ) + _vector, _bl_fixed, _f32_rate );
}

// shift offset x

mobile& mobile::shift_offset_x( f32 _f32_x )
{
	return shift_offset_x( _f32_x, false, 1.f );
}
mobile& mobile::shift_offset_x( f32 _f32_x, f32 _f32_rate )
{
	return shift_offset_x( _f32_x, false, _f32_rate );
}
mobile& mobile::shift_offset_x( f32 _f32_x, bl _bl_fixed )
{
	return shift_offset_x( _f32_x, _bl_fixed, 1.f );
}
mobile& mobile::shift_offset_x( f32 _f32_x, bl _bl_fixed, f32 _f32_rate )
{
	return shift_offset( vector( _f32_x, 0.f ), _bl_fixed, _f32_rate );
}

// shift offset y

mobile& mobile::shift_offset_y( f32 _f32_y )
{
	return shift_offset_y( _f32_y, false, 1.f );
}
mobile& mobile::shift_offset_y( f32 _f32_y, f32 _f32_rate )
{
	return shift_offset_y( _f32_y, false, _f32_rate );
}
mobile& mobile::shift_offset_y( f32 _f32_y, bl _bl_fixed )
{
	return shift_offset_y( _f32_y, _bl_fixed, 1.f );
}
mobile& mobile::shift_offset_y( f32 _f32_y, bl _bl_fixed, f32 _f32_rate )
{
	return shift_offset( vector( 0.f, _f32_y ), _bl_fixed, _f32_rate );
}



// get trajectory

line mobile::get_trajectory() const
{
	return get_trajectory( false, 1.f );
}
line mobile::get_trajectory( f32 _f32_rate ) const
{
	return get_trajectory( false, _f32_rate );
}
line mobile::get_trajectory( bl _bl_fixed ) const
{
	return get_trajectory( _bl_fixed, 1.f );
}
line mobile::get_trajectory( bl _bl_fixed, f32 _f32_rate ) const
{
	return line( *this, get_destination( _bl_fixed, _f32_rate ) );
}



// get moved

mobile mobile::get_moved( f32 _f32_direction, f32 _f32_distance ) const
{
	mobile mobile_moved( *this );

	mobile_moved.position() += vector().get_moved( _f32_direction, _f32_distance );

	return mobile_moved;
}



// does mobile intersect line

bl mobile::intersects( translation& _translation, const line& _line ) const
{
	return intersects( _translation, _line, false, 1.f );
}
bl mobile::intersects( translation& _translation, const line& _line, f32 _f32_rate ) const
{
	return intersects( _translation, _line, false, _f32_rate );
}
bl mobile::intersects( translation& _translation, const line& _line, bl _bl_fixed ) const
{
	return intersects( _translation, _line, _bl_fixed, 1.f );
}
bl mobile::intersects( translation& _translation, const line& _line, bl _bl_fixed, f32 _f32_rate ) const
{
	return position().intersects( _translation, false, get_destination( _bl_fixed, _f32_rate ), _line );
}



// does mobile collide with map

bl mobile::collides( translation& _translation, const map2d::layer* _layer ) const
{
	return collides( _translation, _layer, false, 1.f );
}
bl mobile::collides( translation& _translation, const map2d::layer* _layer, f32 _f32_rate ) const
{
	return collides( _translation, _layer, false, _f32_rate );
}
bl mobile::collides( translation& _translation, const map2d::layer* _layer, bl _bl_fixed ) const
{
	return collides( _translation, _layer, _bl_fixed, 1.f );
}
bl mobile::collides( translation& _translation, const map2d::layer* _layer, bl _bl_fixed, f32 _f32_rate )
const
{
	return position().collides( _translation, get_destination( _bl_fixed, _f32_rate ), _layer );
}



// iterate

bl mobile::iterate( vector& _vector, const map2d::layer* _layer )
{
	return iterate( _vector, _layer, false, 1.f );
}
bl mobile::iterate( vector& _vector, const map2d::layer* _layer, f32 _f32_rate )
{
	return iterate( _vector, _layer, false, _f32_rate );
}
bl mobile::iterate( vector& _vector, const map2d::layer* _layer, bl _bl_fixed )
{
	return iterate( _vector, _layer, _bl_fixed, 1.f );
}
bl mobile::iterate( vector& _vector, const map2d::layer* _layer, bl _bl_fixed, f32 _f32_rate )
{
	translation translation_iteration;

	if( collides( translation_iteration, _layer, _bl_fixed, _f32_rate ) )
	{
		_vector = translation_iteration.vector_collision;

		if( translation_iteration.get_collision_distance() - ENG2D_PRECISION > 0.f )
			position() = get_moved( direction, translation_iteration.get_collision_distance() - ENG2D_PRECISION );

		line   line_iteration   = translation_iteration.line_collision * ( 1.f + ENG2D_PRECISION );
		vector vector_iteration = line_iteration.get_nearest( translation_iteration.line_trajectory.p2 );

		mobile mobile_copy( *this );

		mobile_copy.direction = _vector.get_direction( vector_iteration );
		mobile_copy.velocity  = _vector.get_distance(  vector_iteration );

		if( mobile_copy.collides( translation_iteration, _layer, true, 1.f ) )
		{
			if( translation_iteration.get_collision_distance() - ENG2D_PRECISION > 0.f )
			{
				position() = get_moved( mobile_copy.direction,
					translation_iteration.get_collision_distance() - ENG2D_PRECISION );
		} }
		else
		{
			position() = get_moved( mobile_copy.direction, mobile_copy.velocity );
		}

		return true;
	}
	else
	{
		position() = get_moved( direction, get_distance( _bl_fixed, _f32_rate ) );

		return false;
} }



// move

bl mobile::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, false, 1.f );
}
bl mobile::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, f32 _f32_rate )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, false, _f32_rate );
}
bl mobile::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, bl _bl_fixed )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, _bl_fixed, 1.f );
}
bl mobile::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, bl _bl_fixed, f32 _f32_rate )
{
	mobile mobile_copy( *this );

	mobile_copy.direction = _f32_direction;
	mobile_copy.velocity  = _f32_distance;

	if( mobile_copy.collides( _translation, _layer, _bl_fixed, _f32_rate ) )
	{
		if( _translation.get_collision_distance() - ENG2D_PRECISION > 0.f )
		{
			*this = get_moved( mobile_copy.direction, _translation.get_collision_distance() - ENG2D_PRECISION );
		}

		return true;
	}
	else
	{
		*this = get_moved( mobile_copy.direction, mobile_copy.get_distance( _bl_fixed, _f32_rate ) );

		return false;
} }



/* end */
}}
#endif
