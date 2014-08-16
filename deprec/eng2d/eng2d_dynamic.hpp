
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_DYNAMIC_HPP
#define BDAPI_ENG2D_DYNAMIC_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "eng2d_primitive.hpp"

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine mobile class declaration *******************************************************************/



class mobile : public vector
{

public:

	f32 direction;
	f32 velocity;

public:

	mobile (                         );
	mobile ( const vector&           );
	mobile ( const vector&, f32, f32 );
	mobile ( const mobile&           );
 ~mobile () {};

	      vector& position ();
	const vector& position () const;

	      vector& operator () ();
	const vector& operator () () const;

	bl operator == ( const mobile& ) const;
	bl operator != ( const mobile& ) const;

	f32 get_distance (         ) const;
	f32 get_distance (     f32 ) const;
	f32 get_distance ( bl      ) const;
	f32 get_distance ( bl, f32 ) const;

	f32 get_distance ( const vector& ) const;
	f32 get_distance ( const mobile& ) const;

	mobile& set_velocity ( f32          );
	mobile& set_velocity ( f32,     f32 );
	mobile& set_velocity ( f32, bl      );
	mobile& set_velocity ( f32, bl, f32 );

	vector get_destination (         ) const;
	vector get_destination (     f32 ) const;
	vector get_destination ( bl      ) const;
	vector get_destination ( bl, f32 ) const;

	mobile& set_destination (       f32, f32          );
	mobile& set_destination (       f32, f32,     f32 );
	mobile& set_destination (       f32, f32, bl      );
	mobile& set_destination (       f32, f32, bl, f32 );
	mobile& set_destination ( const vector&           );
	mobile& set_destination ( const vector&,      f32 );
	mobile& set_destination ( const vector&,  bl      );
	mobile& set_destination ( const vector&,  bl, f32 );

	vector get_offset (         ) const;
	vector get_offset (     f32 ) const;
	vector get_offset ( bl      ) const;
	vector get_offset ( bl, f32 ) const;

	f32 get_offset_x (         ) const;
	f32 get_offset_x (     f32 ) const;
	f32 get_offset_x ( bl      ) const;
	f32 get_offset_x ( bl, f32 ) const;
	f32 get_offset_y (         ) const;
	f32 get_offset_y (     f32 ) const;
	f32 get_offset_y ( bl      ) const;
	f32 get_offset_y ( bl, f32 ) const;

	mobile& set_offset     (       f32, f32          );
	mobile& set_offset     (       f32, f32,     f32 );
	mobile& set_offset     (       f32, f32, bl      );
	mobile& set_offset     (       f32, f32, bl, f32 );
	mobile& set_offset     ( const vector&           );
	mobile& set_offset     ( const vector&,      f32 );
	mobile& set_offset     ( const vector&,  bl      );
	mobile& set_offset     ( const vector&,  bl, f32 );
	mobile& set_offset_x   (       f32               );
	mobile& set_offset_x   (       f32,          f32 );
	mobile& set_offset_x   (       f32,      bl      );
	mobile& set_offset_x   (       f32,      bl, f32 );
	mobile& set_offset_y   (            f32          );
	mobile& set_offset_y   (            f32,     f32 );
	mobile& set_offset_y   (            f32, bl      );
	mobile& set_offset_y   (            f32, bl, f32 );

	mobile& shift_offset   (       f32, f32          );
	mobile& shift_offset   (       f32, f32,     f32 );
	mobile& shift_offset   (       f32, f32, bl      );
	mobile& shift_offset   (       f32, f32, bl, f32 );
	mobile& shift_offset   ( const vector&           );
	mobile& shift_offset   ( const vector&,      f32 );
	mobile& shift_offset   ( const vector&,  bl      );
	mobile& shift_offset   ( const vector&,  bl, f32 );
	mobile& shift_offset_x (       f32               );
	mobile& shift_offset_x (       f32,          f32 );
	mobile& shift_offset_x (       f32,      bl      );
	mobile& shift_offset_x (       f32,      bl, f32 );
	mobile& shift_offset_y (            f32          );
	mobile& shift_offset_y (            f32,     f32 );
	mobile& shift_offset_y (            f32, bl      );
	mobile& shift_offset_y (            f32, bl, f32 );

	line get_trajectory (         ) const;
	line get_trajectory (     f32 ) const;
	line get_trajectory ( bl      ) const;
	line get_trajectory ( bl, f32 ) const;

	mobile get_moved ( f32, f32 ) const;

	virtual bl intersects ( translation&, const line&          ) const;
	virtual bl intersects ( translation&, const line&,     f32 ) const;
	virtual bl intersects ( translation&, const line&, bl      ) const;
	virtual bl intersects ( translation&, const line&, bl, f32 ) const;

	virtual bl collides ( translation&, const map2d::layer*          ) const;
	virtual bl collides ( translation&, const map2d::layer*,     f32 ) const;
	virtual bl collides ( translation&, const map2d::layer*, bl      ) const;
	virtual bl collides ( translation&, const map2d::layer*, bl, f32 ) const;

	virtual bl iterate ( vector&, const map2d::layer*          );
	virtual bl iterate ( vector&, const map2d::layer*,     f32 );
	virtual bl iterate ( vector&, const map2d::layer*, bl      );
	virtual bl iterate ( vector&, const map2d::layer*, bl, f32 );

	virtual bl move ( translation&, const map2d::layer*, f32, f32          );
	virtual bl move ( translation&, const map2d::layer*, f32, f32,     f32 );
	virtual bl move ( translation&, const map2d::layer*, f32, f32, bl      );
	virtual bl move ( translation&, const map2d::layer*, f32, f32, bl, f32 );

};



/* 2d engine mobile line class declaration **************************************************************/



class mobile_line : public mobile
{

public:

	f32 height;

public:

	mobile_line (                    );
	mobile_line ( const mobile&, f32 );
	mobile_line ( const mobile_line& );
 ~mobile_line () {};

	      mobile& source ();
	const mobile& source () const;

	line get_line () const;

	line get_destination_line (         ) const;
	line get_destination_line (     f32 ) const;
	line get_destination_line ( bl      ) const;
	line get_destination_line ( bl, f32 ) const;

	mobile_line get_moved ( f32, f32 ) const;

	virtual bl intersects ( translation&, const line&               ) const;
	virtual bl intersects ( translation&, const line&,          f32 ) const;
	virtual bl intersects ( translation&, const line&,      bl      ) const;
	virtual bl intersects ( translation&, const line&,      bl, f32 ) const;

	virtual bl intersects ( translation&, const multiline&          ) const;
	virtual bl intersects ( translation&, const multiline&,     f32 ) const;
	virtual bl intersects ( translation&, const multiline&, bl      ) const;
	virtual bl intersects ( translation&, const multiline&, bl, f32 ) const;

	virtual bl intersects ( translation&, const polygon&            ) const;
	virtual bl intersects ( translation&, const polygon&,       f32 ) const;
	virtual bl intersects ( translation&, const polygon&,   bl      ) const;
	virtual bl intersects ( translation&, const polygon&,   bl, f32 ) const;

	virtual bl collides ( translation&, const map2d::layer*          ) const;
	virtual bl collides ( translation&, const map2d::layer*,     f32 ) const;
	virtual bl collides ( translation&, const map2d::layer*, bl      ) const;
	virtual bl collides ( translation&, const map2d::layer*, bl, f32 ) const;

	virtual bl iterate ( vector&, const map2d::layer*          );
	virtual bl iterate ( vector&, const map2d::layer*,     f32 );
	virtual bl iterate ( vector&, const map2d::layer*, bl      );
	virtual bl iterate ( vector&, const map2d::layer*, bl, f32 );

	virtual bl move ( translation&, const map2d::layer*, f32, f32          );
	virtual bl move ( translation&, const map2d::layer*, f32, f32,     f32 );
	virtual bl move ( translation&, const map2d::layer*, f32, f32, bl      );
	virtual bl move ( translation&, const map2d::layer*, f32, f32, bl, f32 );

	void draw ( const video::color&, const video::color& ) const;
	void draw ( const video::color&                      ) const;

};



/* 2d engine mobile polygon class declaration ***********************************************************/



class mobile_polygon : public mobile
{

public:

	polygon box;

	f32 width;
	f32 height;

public:

	mobile_polygon (                         );
	mobile_polygon ( const mobile&, f32, f32 );
	mobile_polygon ( const mobile_polygon&   );
 ~mobile_polygon () {};

	      mobile& source ();
	const mobile& source () const;

	mobile_polygon& set_width  ( f32      );
	mobile_polygon& set_height (      f32 );
	mobile_polygon& set_size   ( f32, f32 );

	polygon get_box () const;

	polygon get_destination_box (         ) const;
	polygon get_destination_box (     f32 ) const;
	polygon get_destination_box ( bl      ) const;
	polygon get_destination_box ( bl, f32 ) const;

	mobile_polygon get_moved ( f32, f32 ) const;

	virtual bl intersects ( translation&, const line&               ) const;
	virtual bl intersects ( translation&, const line&,          f32 ) const;
	virtual bl intersects ( translation&, const line&,      bl      ) const;
	virtual bl intersects ( translation&, const line&,      bl, f32 ) const;

	virtual bl intersects ( translation&, const multiline&          ) const;
	virtual bl intersects ( translation&, const multiline&,     f32 ) const;
	virtual bl intersects ( translation&, const multiline&, bl      ) const;
	virtual bl intersects ( translation&, const multiline&, bl, f32 ) const;

	virtual bl intersects ( translation&, const polygon&            ) const;
	virtual bl intersects ( translation&, const polygon&,       f32 ) const;
	virtual bl intersects ( translation&, const polygon&,   bl      ) const;
	virtual bl intersects ( translation&, const polygon&,   bl, f32 ) const;

	virtual bl collides ( translation&, const map2d::layer*          ) const;
	virtual bl collides ( translation&, const map2d::layer*,     f32 ) const;
	virtual bl collides ( translation&, const map2d::layer*, bl      ) const;
	virtual bl collides ( translation&, const map2d::layer*, bl, f32 ) const;

	virtual bl iterate ( vector&, const map2d::layer*          );
	virtual bl iterate ( vector&, const map2d::layer*,     f32 );
	virtual bl iterate ( vector&, const map2d::layer*, bl      );
	virtual bl iterate ( vector&, const map2d::layer*, bl, f32 );

	virtual bl move ( translation&, const map2d::layer*, f32, f32          );
	virtual bl move ( translation&, const map2d::layer*, f32, f32,     f32 );
	virtual bl move ( translation&, const map2d::layer*, f32, f32, bl      );
	virtual bl move ( translation&, const map2d::layer*, f32, f32, bl, f32 );

	void draw ( const video::color&, const video::color& ) const;
	void draw ( const video::color&                      ) const;

};



/* 2d engine particle class declaration *****************************************************************/



class particle : public mobile
{

public:

	f32 roughness;
	f32 hardness;
	f32 gravity;

public:

	particle (                                );
	particle ( const mobile&                  );
	particle ( const mobile&,   f32, f32      );
	particle ( const mobile&,   f32, f32, f32 );
	particle ( const particle&                );
 ~particle () {};

	particle get_moved ( f32, f32 ) const;

	virtual bl iterate ( vector&, const map2d::layer*               );
	virtual bl iterate ( vector&, const map2d::layer*,          f32 );
	virtual bl iterate ( vector&, const map2d::layer*,      bl      );
	virtual bl iterate ( vector&, const map2d::layer*,      bl, f32 );
	virtual bl iterate ( vector&, const map2d::layer*, f32,     f32 );
	virtual bl iterate ( vector&, const map2d::layer*, f32, bl      );
	virtual bl iterate ( vector&, const map2d::layer*, f32, bl, f32 );

};



/* 2d engine actor class declaration ********************************************************************/



class actor : public mobile_line
{

public:

	bl velocity_direction;
	bl velocity_accelerating;

	f32 velocity_current;
	f32 velocity_acceleration;
	f32 velocity_maximum;

	f32 gravity_current;
	f32 gravity_acceleration;

	bl   adjacent;
	f32  adjacent_direction;
	line adjacent_line;

public:

	actor (                                   );
	actor ( const mobile_line&, f32, f32      );
	actor ( const mobile_line&, f32, f32, f32 );
	actor ( const actor&                      );
 ~actor () {};

	      mobile_line& control ();
	const mobile_line& control () const;

	actor get_moved ( f32, f32 ) const;

	actor& accelerate ( bl );
	actor& decelerate (    );

	actor& apply_velocity (              );
	actor& apply_velocity (          f32 );
	actor& apply_velocity (      bl      );
	actor& apply_velocity (      bl, f32 );
	actor& apply_velocity ( f32,     f32 );
	actor& apply_velocity ( f32, bl      );
	actor& apply_velocity ( f32, bl, f32 );

	bl adjacent_check ( const map2d::layer*      );
	bl adjacent_check ( const map2d::layer*, f32 );

	actor& line_check ( const line& );

	virtual bl iterate ( vector&, const map2d::layer*               );
	virtual bl iterate ( vector&, const map2d::layer*,          f32 );
	virtual bl iterate ( vector&, const map2d::layer*,      bl      );
	virtual bl iterate ( vector&, const map2d::layer*,      bl, f32 );
	virtual bl iterate ( vector&, const map2d::layer*, f32,     f32 );
	virtual bl iterate ( vector&, const map2d::layer*, f32, bl      );
	virtual bl iterate ( vector&, const map2d::layer*, f32, bl, f32 );

	virtual bl move ( translation&, const map2d::layer*, f32, f32          );
	virtual bl move ( translation&, const map2d::layer*, f32, f32,     f32 );
	virtual bl move ( translation&, const map2d::layer*, f32, f32, bl      );
	virtual bl move ( translation&, const map2d::layer*, f32, f32, bl, f32 );

};



/* end */
}}
#endif
