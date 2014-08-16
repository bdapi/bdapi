
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_SHAPE_CORE_CPP
#define BDAPI_PHYSICS_SHAPE_CORE_CPP
#define BD_PHYSICS_IMPL
#include "physics/shape.hpp"

/* includes */

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics shape class core function implementations */

// make box shape
shape* shape::make_box( f32 half_extent_size )
{
	return make_box( math::vec3( half_extent_size, half_extent_size, half_extent_size ) );
}
shape* shape::make_box( f32 x, f32 y, f32 z )
{
	return make_box( math::vec3( x, y, z ) );
}
shape* shape::make_box( const math::vec3& half_extents )
{
	shape* s = new shape( box );

	s->bullet_collision_shape = new btBoxShape( convert( half_extents ) );

	return s;
}

// make capsule shape
shape* shape::make_capsule( f32 radius, f32 height )
{
	shape* s = new shape( capsule );

	s->bullet_collision_shape = new btCapsuleShape( radius, height );

	return s;
}

// make cone shape
shape* shape::make_cone( f32 radius, f32 height )
{
	shape* s = new shape( cone );

	s->bullet_collision_shape = new btConeShape( radius, height );

	return s;
}

// make cylinder shape
shape* shape::make_cylinder( f32 half_extent_size )
{
	return make_cylinder( math::vec3( half_extent_size, half_extent_size, half_extent_size ) );
}
shape* shape::make_cylinder( f32 x, f32 y, f32 z )
{
	return make_cylinder( math::vec3( x, y, z ) );
}
shape* shape::make_cylinder( const math::vec3& half_extents )
{
	shape* s = new shape( cylinder );

	s->bullet_collision_shape = new btCylinderShape( convert( half_extents ) );

	return s;
}

// make plane shape
shape* shape::make_plane( f32 normal_size, f32 plane_constant )
{
	return make_plane( math::vec3( normal_size, normal_size, normal_size ), plane_constant );
}
shape* shape::make_plane( f32 x, f32 y, f32 z, f32 plane_constant )
{
	return make_plane( math::vec3( x, y, z ), plane_constant );
}
shape* shape::make_plane( const math::vec3& normals, f32 plane_constant )
{
	shape* s = new shape( plane );

	s->bullet_collision_shape = new btStaticPlaneShape( convert( normals ), plane_constant );

	return s;
}

// make sphere shape
shape* shape::make_sphere( f32 radius )
{
	shape* s = new shape( sphere );

	s->bullet_collision_shape = new btSphereShape( radius );

	return s;
}

/* end */

}
}

#endif
