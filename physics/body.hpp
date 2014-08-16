
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_BODY_HPP
#define BDAPI_PHYSICS_BODY_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "physics/core.hpp"

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics body class declarations */

class body
{
	// external bullet physics data
	BD_COPY_INIT( shape*,   collision_shape, get_shape,   NULL );
	BD_COPY_INIT( handler*, physics_handler, get_handler, NULL );

	// internal bullet physics data
	BD_COPY_INIT( btDefaultMotionState*, motion_state, get_motion, NULL );
	BD_COPY_INIT( btRigidBody*,          rigid_body,   get_body,   NULL );

public: // public initialization functions (physics_body_init.cpp)

	body ();
 ~body ();

	result initialize ( shape* collision_shape,
	                                                   handler* physics_handler );
	result initialize ( shape* collision_shape,           const math::vec3& position,
	                                                   handler* physics_handler );
	result initialize ( shape* collision_shape,           const math::vec3& position,
	                    const math::quat& orientation, handler* physics_handler );
	result initialize ( shape* collision_shape, f32 mass,
	                                                   handler* physics_handler );
	result initialize ( shape* collision_shape, f32 mass, const math::vec3& position,
	                                                   handler* physics_handler );
	result initialize ( shape* collision_shape, f32 mass, const math::vec3& position,
	                    const math::quat& orientation, handler* physics_handler );

public: // public core functions (physics_body_core.cpp)



public: // public modification functions (physics_body_mod.cpp)



public: // public query functions (physics_body_query.cpp)



};

/* end */

}
}

#endif
