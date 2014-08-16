
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_SHAPE_INIT_CPP
#define BDAPI_PHYSICS_SHAPE_INIT_CPP
#define BD_PHYSICS_IMPL
#include "physics/shape.hpp"

/* includes */

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics shape class initialization function implementations */

// private constructors
shape::shape()
{
}
shape::shape( type t )
{
	shape_type = t;
}

// destructor
shape::~shape()
{
	DESTRUCT( bullet_collision_shape );
}

/* end */

}
}

#endif
