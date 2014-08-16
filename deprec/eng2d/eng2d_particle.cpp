
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_PARTICLE_CPP
#define BDAPI_ENG2D_PARTICLE_CPP
#include "eng2d_dynamic.hpp"

/* includes */

// bdapi
#include "eng2d_const.hpp"
#include "eng2d_map2d.hpp"
#include "sys_core.hpp"

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine particle class implementation **************************************************************/



// constructors

particle::particle() : mobile()
{
	roughness = 0.5f;
	hardness  = 0.5f;
	gravity   = 1.0f;
}
particle::particle( const mobile& _mobile ) : mobile( _mobile )
{
	roughness = 0.5f;
	hardness  = 0.5f;
	gravity   = 1.0f;
}
particle::particle( const mobile& _mobile, f32 _f32_roughness, f32 _f32_hardness ) : mobile( _mobile )
{
	roughness = _f32_roughness;
	hardness  = _f32_hardness;
	gravity   = 1.f;
}
particle::particle( const mobile& _mobile, f32 _f32_roughness, f32 _f32_hardness, f32 _f32_gravity ) :
mobile( _mobile )
{
	roughness = _f32_roughness;
	hardness  = _f32_hardness;
	gravity   = _f32_gravity;
}
particle::particle( const particle& _particle ) : mobile( static_cast<const mobile&>( _particle ) )
{
	roughness = _particle.roughness;
	hardness  = _particle.hardness;
	gravity   = _particle.gravity;
}



// get moved

particle particle::get_moved( f32 _f32_direction, f32 _f32_distance ) const
{
	particle particle_moved( *this );

	particle_moved += vector().get_moved( _f32_direction, _f32_distance );

	return particle_moved;
}



// iterate

bl particle::iterate( vector& _vector, const map2d::layer* _layer )
{
	return iterate( _vector, _layer, gravity, false, 1.f );
}
bl particle::iterate( vector& _vector, const map2d::layer* _layer, f32 _f32_rate )
{
	return iterate( _vector, _layer, gravity, false, _f32_rate );
}
bl particle::iterate( vector& _vector, const map2d::layer* _layer, bl _bl_fixed )
{
	return iterate( _vector, _layer, gravity, _bl_fixed, 1.f );
}
bl particle::iterate( vector& _vector, const map2d::layer* _layer, bl _bl_fixed, f32 _f32_rate )
{
	return iterate( _vector, _layer, gravity, _bl_fixed, _f32_rate );
}
bl particle::iterate( vector& _vector, const map2d::layer* _layer, f32 _f32_gravity, f32 _f32_rate )
{
	return iterate( _vector, _layer, _f32_gravity, false, _f32_rate );
}
bl particle::iterate( vector& _vector, const map2d::layer* _layer, f32 _f32_gravity, bl _bl_fixed )
{
	return iterate( _vector, _layer, _f32_gravity, _bl_fixed, 1.f );
}
bl particle::iterate( vector& _vector, const map2d::layer* _layer, f32 _f32_gravity, bl _bl_fixed,
f32 _f32_rate )
{
	translation translation_iteration;

	if( collides( translation_iteration, _layer, _bl_fixed, _f32_rate ) )
	{
		_vector = translation_iteration.vector_collision;

		if( translation_iteration.get_collision_distance() - ENG2D_PRECISION > 0.f )
			position() = get_moved( direction, translation_iteration.get_collision_distance() - ENG2D_PRECISION );

		f32 d = direction;
		f32 c = translation_iteration.line_collision.get_normal_direction();
		f32 b = c - d;

		direction = c + b - math<f32>::radians_05();

		vector vector_offset = get_offset(true);

		const map2d::tile* tile_map = &_layer->get( _vector );

		vector_offset.x *= ( 1.f - roughness ) * ( 1.f - tile_map->get_friction()    );
		vector_offset.y *=         hardness    * ( 1.f - tile_map->get_restitution() );

		set_offset( vector_offset, true );

		return true;
	}
	else
	{
		position() = get_moved( direction, get_distance( _bl_fixed, _f32_rate ) );

		if( _bl_fixed )
		{
			shift_offset_y( _f32_gravity * _layer->get_gravity(),                             true, _f32_rate );
		}
		else
		{
			shift_offset_y( _f32_gravity * _layer->get_gravity() * ( sys::delta() * 1000.0 ), true, _f32_rate );
		}

		return false;
} }



/* end */
}}
#endif
