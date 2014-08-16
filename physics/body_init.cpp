
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_BODY_INIT_CPP
#define BDAPI_PHYSICS_BODY_INIT_CPP
#define BD_PHYSICS_IMPL
#include "physics/body.hpp"

/* includes */

// bdapi
#include "physics/handler.hpp"
#include "physics/shape.hpp"

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics body class initialization function implementations */

// constructors
body::body()
{
}

// destructor
body::~body()
{
	DESTRUCT( motion_state );
	DESTRUCT( rigid_body   );
}

// initializers
result body::initialize( shape* collision_shape, handler* physics_handler )
{
	return initialize( collision_shape, 0.f, math::vec3( 0.f, 0.f, 0.f ), math::quat( 0.f, 0.f, 0.f, 1.f ),
		physics_handler );
}
result body::initialize( shape* collision_shape, const math::vec3& position, handler* physics_handler )
{
	return initialize( collision_shape, 0.f, position, math::quat( 0.f, 0.f, 0.f, 1.f ), physics_handler );
}
result body::initialize( shape* collision_shape, const math::vec3& position, const math::quat& orientation,
handler* physics_handler )
{
	return initialize( collision_shape, 0.f, position, orientation, physics_handler );
}
result body::initialize( shape* collision_shape, f32 mass, handler* physics_handler )
{
	return initialize( collision_shape, mass, math::vec3( 0.f, 0.f, 0.f ), math::quat( 0.f, 0.f, 0.f, 1.f ),
		physics_handler );
}
result body::initialize( shape* collision_shape, f32 mass, const math::vec3& position,
handler* physics_handler )
{
	return initialize( collision_shape, mass, position, math::quat( 0.f, 0.f, 0.f, 1.f ), physics_handler );
}
result body::initialize( shape* collision_shape, f32 mass, const math::vec3& position,
const math::quat& orientation, handler* physics_handler )
{
	this->collision_shape = collision_shape;
	this->physics_handler = physics_handler;

	motion_state = new btDefaultMotionState( btTransform( convert( orientation ), convert( position ) ) );

	btRigidBody::btRigidBodyConstructionInfo rigid_body_ci( mass, motion_state,
		this->collision_shape->get_shape(), btVector3( 0.f, 0.f, 0.f ) );

	rigid_body = new btRigidBody( rigid_body_ci );

	this->physics_handler->get_world()->addRigidBody( rigid_body );

	return 1;
}

/* end */

}
}

#endif
