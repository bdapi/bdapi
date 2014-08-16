
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_ACTOR_CPP
#define BDAPI_ENG2D_ACTOR_CPP
#include "eng2d_dynamic.hpp"

/* includes */

// bdapi
#include "eng2d_const.hpp"
#include "eng2d_map2d.hpp"
#include "sys_core.hpp"

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine actor class implementation *****************************************************************/



// constructors

actor::actor() : mobile_line()
{
	velocity_direction    = false;
	velocity_accelerating = false;

	velocity_current      = 0.f;
	velocity_acceleration = 0.f;
	velocity_maximum      = 0.f;

	gravity_current       = 0.f;
	gravity_acceleration  = 0.f;

	adjacent              = false;
	adjacent_direction    = 0.f;
	adjacent_line         = line();
}
actor::actor( const mobile_line& _mobile_line, f32 _f32_velocity_acceleration, f32 _f32_velocity_maximum ) :
mobile_line( _mobile_line )
{
	velocity_direction    = false;
	velocity_accelerating = false;

	velocity_current      = 0.f;
	velocity_acceleration = math<f32>::divide( _f32_velocity_maximum, _f32_velocity_acceleration );
	velocity_maximum      = _f32_velocity_maximum;

	gravity_current       = 0.f;
	gravity_acceleration  = 0.f;

	adjacent              = false;
	adjacent_direction    = 0.f;
	adjacent_line         = line();
}
actor::actor( const mobile_line& _mobile_line, f32 _f32_velocity_acceleration, f32 _f32_velocity_maximum,
f32 _f32_gravity_acceleration ) : mobile_line( _mobile_line )
{
	velocity_direction    = false;
	velocity_accelerating = false;

	velocity_current      = 0.f;
	velocity_acceleration = math<f32>::divide( _f32_velocity_maximum, _f32_velocity_acceleration );
	velocity_maximum      = _f32_velocity_maximum;

	gravity_current       = 0.f;
	gravity_acceleration  = _f32_gravity_acceleration;

	adjacent              = false;
	adjacent_direction    = 0.f;
	adjacent_line         = line();
}
actor::actor( const actor& _actor ) : mobile_line( static_cast<const mobile_line&>( _actor ) )
{
	velocity_direction    = _actor.velocity_direction;
	velocity_accelerating = _actor.velocity_accelerating;

	velocity_current      = _actor.velocity_current;
	velocity_acceleration = _actor.velocity_acceleration;
	velocity_maximum      = _actor.velocity_maximum;

	gravity_current       = _actor.gravity_current;
	gravity_acceleration  = _actor.gravity_acceleration;

	adjacent              = _actor.adjacent;
	adjacent_direction    = _actor.adjacent_direction;
	adjacent_line         = _actor.adjacent_line;
}



// get mobile line control source

mobile_line& actor::control()
{
	return static_cast<mobile_line&>(*this);
}

// get constant mobile line control source

const mobile_line& actor::control() const
{
	return static_cast<const mobile_line&>(*this);
}



// get moved

actor actor::get_moved( f32 _f32_direction, f32 _f32_distance ) const
{
	actor actor_moved( *this );

	actor_moved.position() += vector().get_moved( _f32_direction, _f32_distance );

	return actor_moved;
}



// accelerate

actor& actor::accelerate( bl _bl_right )
{
	velocity_direction    = _bl_right;
	velocity_accelerating = true;

	return *this;
}

// decelerate

actor& actor::decelerate()
{
	velocity_accelerating = false;

	return *this;
}



// apply velocity

actor& actor::apply_velocity()
{
	return apply_velocity( gravity_acceleration, false, 1.f );
}
actor& actor::apply_velocity( f32 _f32_rate )
{
	return apply_velocity( gravity_acceleration, false, _f32_rate );
}
actor& actor::apply_velocity( bl _bl_fixed )
{
	return apply_velocity( gravity_acceleration, _bl_fixed, 1.f );
}
actor& actor::apply_velocity( bl _bl_fixed, f32 _f32_rate )
{
	return apply_velocity( gravity_acceleration, _bl_fixed, _f32_rate );
}
actor& actor::apply_velocity( f32 _f32_gravity, f32 _f32_rate )
{
	return apply_velocity( _f32_gravity, false, _f32_rate );
}
actor& actor::apply_velocity( f32 _f32_gravity, bl _bl_fixed )
{
	return apply_velocity( _f32_gravity, _bl_fixed, 1.f );
}
actor& actor::apply_velocity( f32 _f32_gravity, bl _bl_fixed, f32 _f32_rate )
{
	if( velocity_accelerating )
	{
		if( _bl_fixed )
		{
			if( velocity_direction )
				velocity_current += velocity_acceleration * _f32_rate;
			else
				velocity_current -= velocity_acceleration * _f32_rate;
		}
		else
		{
			if( velocity_direction )
				velocity_current += velocity_acceleration * _f32_rate * sys::delta();
			else
				velocity_current -= velocity_acceleration * _f32_rate * sys::delta();
		}

		if( !math<f32>::equals( velocity_maximum ) )
		{
			velocity_current = math<f32>::clamp( -velocity_maximum, velocity_current, velocity_maximum );
	} }
	else
	{
		if( math<f32>::equals( velocity_current ) )
		{
			velocity_current = 0.f;
		}
		else if( velocity_current > 0.f )
		{
			if( _bl_fixed )
				velocity_current -= velocity_acceleration * _f32_rate;
			else
				velocity_current -= velocity_acceleration * _f32_rate * sys::delta();

			if( velocity_current < 0.f )
				velocity_current = 0.f;
		}
		else if( velocity_current < 0.f )
		{
			if( _bl_fixed )
				velocity_current += velocity_acceleration * _f32_rate;
			else
				velocity_current += velocity_acceleration * _f32_rate * sys::delta();

			if( velocity_current > 0.f )
				velocity_current = 0.f;
	} }

	return *this;
}



// adjacent check

bl actor::adjacent_check( const map2d::layer* _layer )
{
	return adjacent_check( _layer, ENG2D_PRECISION * 4.f );
}
bl actor::adjacent_check( const map2d::layer* _layer, f32 _f32_check_distance )
{
	translation translation_adjacent;

	mobile_line mobile_line_copy( *this );

	mobile_line_copy.direction = math<f32>::pi_05();
	mobile_line_copy.velocity  = _f32_check_distance;

	if( mobile_line_copy.collides( translation_adjacent, _layer, true, 1.f ) )
	{
		gravity_current = 0.f;

		adjacent           = true;
		adjacent_direction = translation_adjacent.line_collision.get_direction();
		adjacent_line      = translation_adjacent.line_collision;

		move( translation_adjacent, _layer, -math<f32>::pi_05(), _f32_check_distance, true, 1.f );

		return true;
	}
	else
	{
		adjacent           = false;
		adjacent_direction = 0.f;
		adjacent_line      = line();

		return false;
} }



// line check

actor& actor::line_check( const line& _line )
{
	if( _line.is_vertical() )
	{
		velocity_current = 0.f;
	}
	else if( _line.is_horizontal() || _line.is_upwards() )
	{
		gravity_current = 0.f;

		if( adjacent && _line.is_downwards() )
		{
			velocity_current = 0.f;
	} }
	else if( gravity_current < 0.f )
	{
		gravity_current = 0.f;
	}
	else if( adjacent )
	{
		velocity_current = 0.f;
	}

	return *this;
}



// iterate

bl actor::iterate( vector& _vector, const map2d::layer* _layer )
{
	return iterate( _vector, _layer, gravity_acceleration, false, 1.f );
}
bl actor::iterate( vector& _vector, const map2d::layer* _layer, f32 _f32_rate )
{
	return iterate( _vector, _layer, gravity_acceleration, false, _f32_rate );
}
bl actor::iterate( vector& _vector, const map2d::layer* _layer, bl _bl_fixed )
{
	return iterate( _vector, _layer, gravity_acceleration, _bl_fixed, 1.f );
}
bl actor::iterate( vector& _vector, const map2d::layer* _layer, bl _bl_fixed, f32 _f32_rate )
{
	return iterate( _vector, _layer, gravity_acceleration, _bl_fixed, _f32_rate );
}
bl actor::iterate( vector& _vector, const map2d::layer* _layer, f32 _f32_gravity, f32 _f32_rate )
{
	return iterate( _vector, _layer, _f32_gravity, false, _f32_rate );
}
bl actor::iterate( vector& _vector, const map2d::layer* _layer, f32 _f32_gravity, bl _bl_fixed )
{
	return iterate( _vector, _layer, _f32_gravity, _bl_fixed, 1.f );
}
bl actor::iterate( vector& _vector, const map2d::layer* _layer, f32 _f32_gravity, bl _bl_fixed,
f32 _f32_rate )
{
	bl bl_iterate_return = false;

	translation translation_iteration;

	apply_velocity( _bl_fixed, _f32_rate );

	if( adjacent )
	{
		if( math<f32>::equals( sin( abs( adjacent_direction ) ) ) )
		{
			set_destination( position().get_moved( adjacent_direction, velocity_current ), true, 1.f );
		}
		else
		{
			set_destination( position().get_moved( adjacent_direction,
				math<f32>::divide( velocity_current, sin( abs( adjacent_direction ) ) ) ), true, 1.f );
		}
	}
	else
	{
		set_offset( velocity_current, gravity_current, true );
	}

	if( collides( translation_iteration, _layer, _bl_fixed, _f32_rate ) )
	{
		_vector = translation_iteration.vector_collision;

		line_check( translation_iteration.line_collision );

		if( translation_iteration.get_collision_distance() - ENG2D_PRECISION > 0.f )
		{
			*this = get_moved( direction, translation_iteration.get_collision_distance() - ENG2D_PRECISION );
		}

		line   line_iteration     = translation_iteration.line_collision * ( 1.f + ENG2D_PRECISION );
		vector vector_iteration_1 = line_iteration.get_nearest( translation_iteration.line_trajectory.p2 );
		vector vector_iteration_2 = line_iteration.get_nearest( _vector.get_moved(
			translation_iteration.line_trajectory.get_direction(),
			translation_iteration.line_trajectory.get_length() ) );

		direction = _vector.get_direction( vector_iteration_1 );

		actor actor_copy( *this );

		actor_copy.set_velocity( _vector.get_distance( vector_iteration_2 ), true, 1.f );

		if( actor_copy.collides( translation_iteration, _layer, true, 1.f ) )
		{
			line_check( translation_iteration.line_collision );

			if( translation_iteration.get_collision_distance() - ENG2D_PRECISION > 0.f )
			{
				control() = get_moved( direction,
					translation_iteration.get_collision_distance() - ENG2D_PRECISION );
		} }
		else
		{
			control() = get_moved( direction, actor_copy.velocity );
		}

		if( _bl_fixed )
		{
			gravity_current += _f32_gravity * _layer->get_gravity() * _f32_rate;
		}
		else
		{
			gravity_current += _f32_gravity * _layer->get_gravity() * _f32_rate * ( sys::delta() * 1000.0 );
		}

		bl_iterate_return = true;
	}
	else
	{
		control() = get_moved( direction, get_distance( _bl_fixed, _f32_rate ) );

		if( _bl_fixed )
		{
			gravity_current += _f32_gravity * _layer->get_gravity() * _f32_rate;
		}
		else
		{
			gravity_current += _f32_gravity * _layer->get_gravity() * _f32_rate * ( sys::delta() * 1000.0 );
	} }

	if( adjacent )
	{
		mobile_line mobile_line_copy( *this );

		mobile_line_copy.direction = math<f32>::pi_05();
		mobile_line_copy.velocity  = 4.f;

		if( mobile_line_copy.collides( translation_iteration, _layer, true, 1.f ) )
		{
			if( translation_iteration.get_collision_distance() - ENG2D_PRECISION > 0.f )
			{
				control() = get_moved( mobile_line_copy.direction,
					translation_iteration.get_collision_distance() - ENG2D_PRECISION );
		} }
		else
		{
			vector vector_offset = get_offset( true, 1.f );

			if( vector_offset.y > 0.f )
			{
				velocity_current = vector_offset.x;
				gravity_current  = vector_offset.y;
	} } }

	adjacent_check( _layer );

	return bl_iterate_return;
}



// move

bl actor::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, false, 1.f );
}
bl actor::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, f32 _f32_rate )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, false, _f32_rate );
}
bl actor::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, bl _bl_fixed )
{
	return move( _translation, _layer, _f32_direction, _f32_distance, _bl_fixed, 1.f );
}
bl actor::move( translation& _translation, const map2d::layer* _layer, f32 _f32_direction,
f32 _f32_distance, bl _bl_fixed, f32 _f32_rate )
{
	mobile_line mobile_line_copy( *this );

	mobile_line_copy.direction = _f32_direction;
	mobile_line_copy.velocity  = _f32_distance;

	if( mobile_line_copy.collides( _translation, _layer, _bl_fixed, _f32_rate ) )
	{
		if( _translation.get_collision_distance() - ENG2D_PRECISION > 0.f )
		{
			control() = get_moved( mobile_line_copy.direction,
				_translation.get_collision_distance() - ENG2D_PRECISION );
		}

		return true;
	}
	else
	{
		control() = get_moved( mobile_line_copy.direction,
			mobile_line_copy.get_distance( _bl_fixed, _f32_rate ) );

		return false;
} }



/* end */
}}
#endif
