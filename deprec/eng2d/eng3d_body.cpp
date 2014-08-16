
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG3D_BODY_CPP
#define BDAPI_ENG3D_BODY_CPP
#include "eng3d_core.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace eng3d {



/* 3d engine body class implementation ******************************************************************/



// private nullify

void body::__nullify()
{
	bt_collision_shape      = NULL;
	bt_default_motion_state = NULL;
	bt_rigid_body           = NULL;

	world_parent = NULL;
}



// constructors

body::body()
{
	__nullify();
}
body::body( world* _world_parent )
{
	__nullify();

	initialize( _world_parent );
}

// destructor

body::~body()
{
	discard();
}



// initializers

result body::initialize( world* _world_parent )
{
	world_parent = _world_parent;

	return 1;
}

// discard

result body::discard()
{
	return 1;
}



/* end */
}}
#endif
