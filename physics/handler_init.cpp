
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_HANDLER_INIT_CPP
#define BDAPI_PHYSICS_HANDLER_INIT_CPP
#define BD_PHYSICS_IMPL
#include "physics/handler.hpp"

/* includes */

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics handler class initialization function implementations */

// constructors
handler::handler()
{
}

// destructor
handler::~handler()
{
	DESTRUCT( broadphase    );
	DESTRUCT( configuration );
	DESTRUCT( dispatcher    );
	DESTRUCT( solver        );
	DESTRUCT( world         );
}

// initializers
result handler::initialize()
{
	broadphase = new btDbvtBroadphase();

	configuration = new btDefaultCollisionConfiguration();

	dispatcher = new btCollisionDispatcher( configuration );

	solver = new btSequentialImpulseConstraintSolver;

	world = new btDiscreteDynamicsWorld( dispatcher, broadphase, solver, configuration );

	set_gravity( -10.f );

	return 1;
}

/* end */

}
}

#endif
