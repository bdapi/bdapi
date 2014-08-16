
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_HANDLER_HPP
#define BDAPI_PHYSICS_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "physics/core.hpp"

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics handler class declarations */

class handler
{

	// internal bullet physics data
	BD_COPY_INIT( btBroadphaseInterface*,               broadphase,    get_broadphase,    NULL );
	BD_COPY_INIT( btDefaultCollisionConfiguration*,     configuration, get_configuration, NULL );
	BD_COPY_INIT( btCollisionDispatcher*,               dispatcher,    get_dispatcher,    NULL );
	BD_COPY_INIT( btSequentialImpulseConstraintSolver*, solver,        get_solver,        NULL );
	BD_COPY_INIT( btDiscreteDynamicsWorld*,             world,         get_world,         NULL );

public: // public initialization functions (physics_handler_init.cpp)

	handler ();
 ~handler ();

	result initialize ();

public: // public core functions (physics_handler_core.cpp)



public: // public iteration functions (physics_handler_iterate.cpp)

	void iterate ( f32 delta, s32 sub_steps );

public: // public modification functions (physics_handler_mod.cpp)

	void set_gravity (        f32 y        );
	void set_gravity ( f32 x, f32 y, f32 z );
	void set_gravity ( const btVector3& v  );

public: // public query functions (physics_handler_query.cpp)



};

/* end */

}
}

#endif
