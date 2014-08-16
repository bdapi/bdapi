
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_HANDLER_ITERATE_CPP
#define BDAPI_PHYSICS_HANDLER_ITERATE_CPP
#define BD_PHYSICS_IMPL
#include "physics/handler.hpp"

/* includes */

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics handler class iteration function implementations */

// iterate
void handler::iterate( f32 delta, s32 sub_steps )
{
	world->stepSimulation( delta, sub_steps );
}

/* end */

}
}

#endif
