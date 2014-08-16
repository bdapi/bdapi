
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_CORE_HPP
#define BDAPI_PHYSICS_CORE_HPP
#include "bdapi.hpp"

/* includes */

// bullet
#ifdef BD_PHYSICS_IMPL
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include "BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h"
#endif

// bdapi
#include "math/typedefs.hpp"

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics forward declarations */

#ifndef BD_PHYSICS_IMPL

class btBroadphaseInterface;
class btCollisionDispatcher;
class btCollisionShape;
class btDbvtBroadphase;
class btDefaultCollisionConfiguration;
class btDefaultMotionState;
class btDiscreteDynamicsWorld;
class btRigidBody;
class btSequentialImpulseConstraintSolver;

class btBoxShape;
class btBvhTriangleMeshShape;
class btCapsuleShape;
class btCompoundShape;
class btConeShape;
class btConvexHullShape;
class btConvexTriangleMeshShape;
class btCylinderShape;
class btEmptyShape;
class btHeightfieldTerrainShape;
class btMultiSphereShape;
class btSphereShape;
class btStaticPlaneShape;

class btMatrix3x3;
class btQuaternion;
class btScalar;
class btTransform;
class btVector3;

#endif

/* bullet physics general function declarations */

math::vec3   convert ( const btVector3&    v );
btVector3    convert ( const math::vec3&   v );

math::quat   convert ( const btQuaternion& q );
btQuaternion convert ( const math::quat&   q );

math::mat3   convert ( const btMatrix3x3&  m );
btMatrix3x3  convert ( const math::mat3&   m );

transform    convert ( const btTransform&  f );
btTransform  convert ( const transform&    f );

/* bullet physics axis-aligned bounding box struct declaration */

struct aabb
{
	math::vec3 min;
	math::vec3 max;

	aabb( const math::vec3& min, const math::vec3& max )
	{
		this->min = min;
		this->max = max;
	}

};

/* bullet physics transform struct declaration */

struct transform
{
	math::mat3 basis;
	math::vec3 origin;

	transform( const math::mat3& base_matrix,     const math::vec3& origin )
	{
		      basis  = base_matrix;
		this->origin = origin;
	}
	transform( const math::quat& base_quaternion, const math::vec3& origin )
	{
		      basis  = glm::mat3_cast( base_quaternion );
		this->origin = origin;
	}

};

/* end */

}
}

#endif
