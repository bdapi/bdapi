
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG3D_CORE_HPP
#define BDAPI_ENG3D_CORE_HPP
#include "bdapi.hpp"

/* includes */

// bullet
#include "btBulletDynamicsCommon.h"

// namespaces
namespace bdapi {
namespace eng3d {



/* 3d engine typedefs ***********************************************************************************/



typedef btVector3 vec3;



/* 3d engine world class declaration ********************************************************************/



class world
{

private:

	BD_GET_COPY( btBroadphaseInterface*,               bt_broadphase,    get_bt_broadphase    );
	BD_GET_COPY( btDefaultCollisionConfiguration*,     bt_configuration, get_bt_configuration );
	BD_GET_COPY( btCollisionDispatcher*,               bt_dispatcher,    get_bt_dispatcher    );
	BD_GET_COPY( btSequentialImpulseConstraintSolver*, bt_solver,        get_bt_solver        );
	BD_GET_COPY( btDiscreteDynamicsWorld*,             bt_world,         get_bt_world         );

	BD_GET_COPY( f32, f32_gravity, get_gravity );

	BD_GET_COPY_SET( world, s32, s32_precision, get_precision, set_precision );

private:

	void __nullify ();

public:

	world (          );
	world ( f32, s32 );
 ~world (          );

	result initialize ( f32, s32 );
	result discard    (          );

 	world& iterate (         );
 	world& iterate (     f32 );
 	world& iterate ( bl      );
 	world& iterate ( bl, f32 );

	world& set_gravity ( f32 );

};



/* 3d engine body class declaration *********************************************************************/



class body
{

private:

	BD_GET_COPY( btCollisionShape*,     bt_collision_shape,      get_bt_collision_shape      );
	BD_GET_COPY( btDefaultMotionState*, bt_default_motion_state, get_bt_default_motion_state );
	BD_GET_COPY( btRigidBody*,          bt_rigid_body,           get_bt_rigid_body           );

	BD_GET_COPY( world*, world_parent, get_world );

private:

	void __nullify ();

public:

	body (        );
	body ( world* );
 ~body (        );

	result initialize ( world* );
	result discard    (        );

};



/* end */
}}
#endif
