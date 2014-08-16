
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG3D_WORLD_CPP
#define BDAPI_ENG3D_WORLD_CPP
#include "eng3d_core.hpp"

/* includes */

// bdapi
#include "sys_core.hpp"

// namespaces
namespace bdapi {
namespace eng3d {



/* 3d engine world class implementation *****************************************************************/



// private nullify

void world::__nullify()
{
	bt_broadphase    = NULL;
	bt_configuration = NULL;
	bt_dispatcher    = NULL;
	bt_solver        = NULL;
	bt_world         = NULL;

	f32_gravity = 0.f;

	s32_precision = 0;
}



// constructors

world::world()
{
	__nullify();
}
world::world( f32 _f32_gravity, s32 _s32_precision )
{
	__nullify();

	initialize( _f32_gravity, _s32_precision );
}

// destructor

world::~world()
{
	discard();
}



// initializers

result world::initialize( f32 _f32_gravity, s32 _s32_precision )
{
	bt_broadphase    = new btDbvtBroadphase();
	bt_configuration = new btDefaultCollisionConfiguration();
	bt_dispatcher    = new btCollisionDispatcher( bt_configuration );
	bt_solver        = new btSequentialImpulseConstraintSolver;
	bt_world         = new btDiscreteDynamicsWorld( bt_dispatcher, bt_broadphase, bt_solver,
		bt_configuration );

	set_gravity( _f32_gravity );

	s32_precision = _s32_precision;

	return 1;
}

// discard

result world::discard()
{
	bdel( bt_world         );
	bdel( bt_solver        );
	bdel( bt_dispatcher    );
	bdel( bt_configuration );
	bdel( bt_broadphase    );

	return 1;
}



// iterate

world& world::iterate()
{
	return iterate( false, 1.f );
}
world& world::iterate( f32 _f32_rate )
{
	return iterate( false, _f32_rate );
}
world& world::iterate( bl _bl_fixed )
{
	return iterate( _bl_fixed, 1.f );
}
world& world::iterate( bl _bl_fixed, f32 _f32_rate )
{
	if( _bl_fixed )
		bt_world->stepSimulation(                _f32_rate, s32_precision );
	else
		bt_world->stepSimulation( sys::delta() * _f32_rate, s32_precision );

	return *this;
}



// set gravity

world& world::set_gravity( f32 _f32_gravity )
{
	f32_gravity = _f32_gravity;

	bt_world->setGravity( btVector3( 0, -f32_gravity, 0 ) );

	return *this;
}



/* end */
}}
#endif
