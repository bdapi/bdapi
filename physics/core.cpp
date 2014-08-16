
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_CORE_CPP
#define BDAPI_PHYSICS_CORE_CPP
#define BD_PHYSICS_IMPL
#include "physics/core.hpp"

/* includes */

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics general function implementations */

// convert vector 3
math::vec3 convert( const btVector3& v )
{
	return math::vec3(
		v.x(),
		v.y(),
		v.z() );
}
btVector3 convert( const math::vec3& v )
{
	return btVector3(
		v.x,
		v.y,
		v.z );
}

// convert quaternion
math::quat convert( const btQuaternion& q )
{
	return math::quat(
		q.x(),
		q.y(),
		q.z(),
		q.w() );
}
btQuaternion convert( const math::quat& q )
{
	return btQuaternion(
		q.x,
		q.y,
		q.z,
		q.w );
}

// convert 3x3 matrix
math::mat3 convert( const btMatrix3x3& m )
{
	return math::mat3(
		convert( m[0] ),
		convert( m[1] ),
		convert( m[2] ) );
}
btMatrix3x3 convert( const math::mat3& m )
{
	return btMatrix3x3(
		m[0][0], m[0][1], m[0][2],
		m[1][0], m[1][1], m[1][2],
		m[2][0], m[2][1], m[2][2] );
}

// convert transformation
transform convert( const btTransform& f )
{
	return transform(
		convert( f.getBasis()  ),
		convert( f.getOrigin() ) );
}
btTransform convert( const transform& f )
{
	return btTransform(
		convert( f.basis  ),
		convert( f.origin ) );
}

/* end */

}
}

#endif
