
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_TYPEDEFS_HPP
#define BDAPI_MATH_TYPEDEFS_HPP
#include "bdapi.hpp"

/* includes */

// glm
#include "glm/glm.hpp"
#include "glm/ext.hpp"

/* namespaces */
namespace bdapi {
namespace math  {

/* math typedef declarations */

template<typename T> struct trig
{
	// vector typedefs

	typedef typename glm::detail::tvec2< T, glm::precision::defaultp > vec2;
	typedef typename glm::detail::tvec3< T, glm::precision::defaultp > vec3;
	typedef typename glm::detail::tvec4< T, glm::precision::defaultp > vec4;

	// generic matrix typedefs

	typedef typename glm::detail::tmat2x2< T, glm::precision::defaultp > mat2;
	typedef typename glm::detail::tmat3x3< T, glm::precision::defaultp > mat3;
	typedef typename glm::detail::tmat4x4< T, glm::precision::defaultp > mat4;

	// variable matrix typedefs

	typedef typename glm::detail::tmat2x2< T, glm::precision::defaultp > mat2x2;
	typedef typename glm::detail::tmat2x3< T, glm::precision::defaultp > mat2x3;
	typedef typename glm::detail::tmat2x4< T, glm::precision::defaultp > mat2x4;
	typedef typename glm::detail::tmat3x2< T, glm::precision::defaultp > mat3x2;
	typedef typename glm::detail::tmat3x3< T, glm::precision::defaultp > mat3x3;
	typedef typename glm::detail::tmat3x4< T, glm::precision::defaultp > mat3x4;
	typedef typename glm::detail::tmat4x2< T, glm::precision::defaultp > mat4x2;
	typedef typename glm::detail::tmat4x3< T, glm::precision::defaultp > mat4x3;
	typedef typename glm::detail::tmat4x4< T, glm::precision::defaultp > mat4x4;

	// quaternion typedefs

	typedef typename glm::detail::tquat< T, glm::precision::defaultp > quat;

};

/* default floating point typedefs */

// vectors
typedef trig<f32>::vec2 vec2;
typedef trig<f32>::vec3 vec3;
typedef trig<f32>::vec4 vec4;

// generic matrices
typedef trig<f32>::mat2 mat2;
typedef trig<f32>::mat3 mat3;
typedef trig<f32>::mat4 mat4;

// variable matrices
typedef trig<f32>::mat2x2 mat2x2;
typedef trig<f32>::mat2x3 mat2x3;
typedef trig<f32>::mat2x4 mat2x4;
typedef trig<f32>::mat3x2 mat3x2;
typedef trig<f32>::mat3x3 mat3x3;
typedef trig<f32>::mat3x4 mat3x4;
typedef trig<f32>::mat4x2 mat4x2;
typedef trig<f32>::mat4x3 mat4x3;
typedef trig<f32>::mat4x4 mat4x4;

// quaternions
typedef trig<f32>::quat quat;

/* end */

}
}

#endif
