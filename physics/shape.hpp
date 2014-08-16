
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_PHYSICS_SHAPE_HPP
#define BDAPI_PHYSICS_SHAPE_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "physics/core.hpp"

/* namespaces */
namespace bdapi   {
namespace physics {

/* bullet physics shape class declarations */

class shape
{

public: // public enumerator declarations

	// shape type
	enum type
	{
		box,
		capsule,
		cone,
		cylinder,
		plane,
		sphere
	};

protected: // protected data

	// internal bullet physics data
	BD_COPY_INIT( btCollisionShape*, bullet_collision_shape, get_shape, NULL );

	// descriptor data
	BD_COPY( type, shape_type, get_type );

private: // private initialization functions (physics_shape_init.cpp)

	shape (        );
	shape ( type t );

public: // public initialization functions (physics_shape_init.cpp)

 ~shape ();

public: // public core functions (physics_shape_core.cpp)

	static shape* make_box ( f32 half_extent_size           );
	static shape* make_box ( f32 x, f32 y, f32 z            );
	static shape* make_box ( const math::vec3& half_extents );

	static shape* make_capsule ( f32 radius, f32 height );

	static shape* make_cone ( f32 radius, f32 height );

	static shape* make_cylinder ( f32 half_extent_size           );
	static shape* make_cylinder ( f32 x, f32 y, f32 z            );
	static shape* make_cylinder ( const math::vec3& half_extents );

	static shape* make_plane ( f32 normal_size,           f32 plane_constant );
	static shape* make_plane ( f32 x, f32 y, f32 z,       f32 plane_constant );
	static shape* make_plane ( const math::vec3& normals, f32 plane_constant );

	static shape* make_sphere ( f32 radius );

public: // public query functions (physics_shape_query.cpp)

	aabb get_aabb (                                   ) const;
	aabb get_aabb ( const btTransform& transformation ) const;

public: // private query functions (physics_shape_query.cpp)

	btBoxShape*         get_box      ();
	btCapsuleShape*     get_capsule  ();
	btConeShape*        get_cone     ();
	btCylinderShape*    get_cylinder ();
	btStaticPlaneShape* get_plane    ();
	btSphereShape*      get_sphere   ();

};

/* end */

}
}

#endif
