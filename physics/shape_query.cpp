
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_SHAPE_QUERY_CPP
#define BDAPI_PHYSICS_SHAPE_QUERY_CPP
#define BD_PHYSICS_IMPL
#include "physics/shape.hpp"

/* includes */

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics shape class query function implementations */

// get aabb
aabb shape::get_aabb() const
{
	return get_aabb( btTransform() );
}
aabb shape::get_aabb( const btTransform& transformation ) const
{
	btVector3 min, max;

	bullet_collision_shape->getAabb( transformation, min, max );

	return aabb( convert( min ), convert( max ) );
}

// private get box shape
btBoxShape* shape::get_box()
{
	if( shape_type == box )
	{
		return reinterpret_cast<btBoxShape*>( bullet_collision_shape );
	}
	else
	{
		return NULL;
	}
}

// private get capsule shape
btCapsuleShape* shape::get_capsule()
{
	if( shape_type == capsule )
	{
		return reinterpret_cast<btCapsuleShape*>( bullet_collision_shape );
	}
	else
	{
		return NULL;
	}
}

// private get cone shape
btConeShape* shape::get_cone()
{
	if( shape_type == cone )
	{
		return reinterpret_cast<btConeShape*>( bullet_collision_shape );
	}
	else
	{
		return NULL;
	}
}

// private get cylinder shape
btCylinderShape* shape::get_cylinder()
{
	if( shape_type == cylinder )
	{
		return reinterpret_cast<btCylinderShape*>( bullet_collision_shape );
	}
	else
	{
		return NULL;
	}
}

// private get plane shape
btStaticPlaneShape* shape::get_plane()
{
	if( shape_type == plane )
	{
		return reinterpret_cast<btStaticPlaneShape*>( bullet_collision_shape );
	}
	else
	{
		return NULL;
	}
}

// private get sphere shape
btSphereShape* shape::get_sphere()
{
	if( shape_type == sphere )
	{
		return reinterpret_cast<btSphereShape*>( bullet_collision_shape );
	}
	else
	{
		return NULL;
	}
}

/* end */

}
}

#endif
