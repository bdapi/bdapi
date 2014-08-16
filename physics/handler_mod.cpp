
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_HANDLER_MOD_CPP
#define BDAPI_PHYSICS_HANDLER_MOD_CPP
#define BD_PHYSICS_IMPL
#include "physics/handler.hpp"

/* includes */

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics handler class modification function implementations */

// set gravity
void handler::set_gravity( f32 y )
{
	world->setGravity( btVector3( 0.f, y, 0.f ) );
}
void handler::set_gravity( f32 x, f32 y, f32 z )
{
	world->setGravity( btVector3( x, y, z ) );
}
void handler::set_gravity( const btVector3& v )
{
	world->setGravity( v );
}

/* end */

}
}

#endif
