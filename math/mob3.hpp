
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_MOB3_HPP
#define BDAPI_MATH_MOB3_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "math/typedefs.hpp"

/* namespaces */
namespace bdapi {
namespace math  {

/* 3-dimensional mobile class declaration */

class mob3
{

private: // private core data

	BD_GET_COPY( private, vec3, position );
	BD_GET_COPY( private, vec3, angles   );

	BD_GET_COPY( private, vec3, offset_position    );
	BD_GET_COPY( private, vec3, offset_orientation );

	BD_GET_COPY( private, quat, orientation );

	BD_GET_COPY( private, mat4, view_matrix );

private: // private internal data

	vec3 view_matrix_axis[3];

	vec3 forward_axis;
	vec3 first_person_axis;

	bl flight_mode = false;

public: // public initialization functions (math_mob3_init.cpp)

	mob3 () {};
	mob3 ( f32 x, f32 y, f32 z                      );
	mob3 ( f32 x, f32 y, f32 z, f32 a, f32 b, f32 c );
	mob3 ( const vec3& position                     );
	mob3 ( const vec3& position, const vec3& angle  );
	mob3 ( const mob3& copy                         );
 ~mob3 () {};

public: // public core functions (math_mob3_core.cpp)

	void reset ();

	void update ();

	void view ( f32 fov, f32 distance ) const;

private: // private core functions (math_mob3_core.cpp)

	void update_view_matrix ();
	void update_orientation ();
	void update_position    ();

public: // public modification functions (math_mob3_mod.cpp)

	void move_x (        f32  x );
	void move_y (        f32  y );
	void move_z (        f32  z );
	void move   ( const vec3& v );

	void rotate_x (        f32  x );
	void rotate_y (        f32  y );
	void rotate_z (        f32  z );
	void rotate   ( const vec3& v );

public: // public query functions (math_mob3_mod.cpp)

	f32 get_x_position () const;
	f32 get_y_position () const;
	f32 get_z_position () const;

	f32 get_x_angle () const;
	f32 get_y_angle () const;
	f32 get_z_angle () const;

	f32 get_x_offset_position () const;
	f32 get_y_offset_position () const;
	f32 get_z_offset_position () const;

	f32 get_x_offset_angle () const;
	f32 get_y_offset_angle () const;
	f32 get_z_offset_angle () const;

};

/* end */

}
}

#endif
