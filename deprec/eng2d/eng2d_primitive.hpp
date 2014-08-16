
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_PRIMITIVE_HPP
#define BDAPI_ENG2D_PRIMITIVE_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "deque"

// bdapi
#include "util_container.hpp"
#include "util_math.hpp"

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine vector class declaration *******************************************************************/



class vector : public vec2
{

public:

	vector (                );
	vector (       f32      );
	vector (       f32, f32 );
	vector ( const vec2&    );
	vector ( const vector&  );
 ~vector () {};

	bl operator == ( const vector& ) const;
	bl operator != ( const vector& ) const;

	vector& operator += ( const vector& );
	vector& operator -= ( const vector& );
	vector& operator *= ( const vector& );
	vector& operator /= ( const vector& );
	vector  operator +  ( const vector& ) const;
	vector  operator -  ( const vector& ) const;
	vector  operator *  ( const vector& ) const;
	vector  operator /  ( const vector& ) const;

	vector& operator *= ( f32 );
	vector& operator /= ( f32 );
	vector  operator *  ( f32 ) const;
	vector  operator /  ( f32 ) const;

	f32 get_length         () const;
	f32 get_squared_length () const;

	f32 get_direction     ( const vector& ) const;
	f32 get_distance      ( const vector& ) const;
	f32 get_cross_product ( const vector& ) const;
	f32 get_dot_product   ( const vector& ) const;

	vector get_normal       (    ) const;
	vector get_normal       ( bl ) const;
	vector get_normal_left  (    ) const;
	vector get_normal_right (    ) const;

	vector get_unit       (               ) const;
	vector get_projection ( const vector& ) const;

	vector get_moved ( f32, f32 ) const;

	virtual bl intersects ( translation&, bl,     f32, f32,  const line&     ) const;
	virtual bl intersects ( translation&, bl,     f32, f32,  const line&, bl ) const;
	virtual bl intersects ( translation&, bl, const vector&, const line&     ) const;
	virtual bl intersects ( translation&, bl, const vector&, const line&, bl ) const;

	virtual bl collides ( translation&, const vector&, const map2d::layer* ) const;
	virtual bl collides ( translation&,     f32, f32,  const map2d::layer* ) const;

	virtual void draw ( const video::color&, const video::color& ) const;
	virtual void draw ( const video::color&                      ) const;

};



/* 2d engine line class declaration *********************************************************************/



class line
{

public:

	vector p1;
	vector p2;

public:

	line (                              );
	line (       f32                    );
	line ( const vector&                );
	line ( const vector&, const vector& );
	line ( const line&                  );
 ~line () {};

	      vector& operator () ( s32 );
	const vector& operator () ( s32 ) const;

	      vector& operator [] ( s32 );
	const vector& operator [] ( s32 ) const;

	bl operator == ( const line& ) const;
	bl operator != ( const line& ) const;

	line& operator += ( const vector& );
	line& operator -= ( const vector& );
	line& operator *= ( const vector& );
	line& operator /= ( const vector& );
	line  operator +  ( const vector& ) const;
	line  operator -  ( const vector& ) const;
	line  operator *  ( const vector& ) const;
	line  operator /  ( const vector& ) const;

	line& operator += ( f32 );
	line& operator -= ( f32 );
	line& operator *= ( f32 );
	line& operator /= ( f32 );
	line  operator +  ( f32 ) const;
	line  operator -  ( f32 ) const;
	line  operator *  ( f32 ) const;
	line  operator /  ( f32 ) const;

	      vector& get ( s32 );
	const vector& get ( s32 ) const;

	bl is_horizontal () const;
	bl is_vertical   () const;
	bl is_sloped     () const;
	bl is_upwards    () const;
	bl is_downwards  () const;
	bl is_left       () const;
	bl is_right      () const;

	s32 get_type () const;

	f32 get_length         () const;
	f32 get_squared_length () const;

	f32 get_distance      () const;
	f32 get_direction     () const;
	f32 get_cross_product () const;
	f32 get_dot_product   () const;

	f32 get_normal_direction       (    ) const;
	f32 get_normal_direction       ( bl ) const;
	f32 get_normal_direction_left  (    ) const;
	f32 get_normal_direction_right (    ) const;

	vector get_normal       (    ) const;
	vector get_normal       ( bl ) const;
	vector get_normal_left  (    ) const;
	vector get_normal_right (    ) const;

	vector get_unit       (               ) const;
	vector get_projection ( const vector& ) const;

	vector get_identity (               ) const;
	vector get_identity ( const vector& ) const;

	vector get_midpoint (               ) const;
	vector get_midpoint (       f32     ) const;
	vector get_nearest  ( const vector& ) const;

	line get_moved ( f32, f32 ) const;

	line get_flipped () const;

	line get_normal_line       (    ) const;
	line get_normal_line       ( bl ) const;
	line get_normal_line_left  (    ) const;
	line get_normal_line_right (    ) const;

	line get_identity_line (               ) const;
	line get_identity_line ( const vector& ) const;

	bl get_intersection ( vector&, const line&     ) const;
	bl get_intersection ( vector&, const line&, bl ) const;

	bl intersects ( translation&, f32, f32, const line&      ) const;
	bl intersects ( translation&, f32, f32, const multiline& ) const;
	bl intersects ( translation&, f32, f32, const polygon&   ) const;

	void draw ( const video::color&, const video::color& ) const;
	void draw ( const video::color&                      ) const;

};



/* 2d engine translation class declaration **************************************************************/



class translation
{

public:

	line line_trajectory;

	vector vector_collision;
	line   line_collision;

	bl bl_destination_intersection;

public:

	translation (                                             );
	translation ( const line&, const vector&, const line&, bl );
	translation ( const translation&                          );
 ~translation () {};

	f32 get_collision_distance () const;
	f32 get_remaining_distance () const;

};



/* 2d engine multiline class declaration ****************************************************************/



class multiline : public util::container< line, std::deque >
{

public:

	multiline (                    );
	multiline ( const map2d::tile& );
	multiline ( const multiline&   );
 ~multiline () {};

	multiline& operator += ( const vector& );
	multiline& operator -= ( const vector& );
	multiline& operator *= ( const vector& );
	multiline& operator /= ( const vector& );
	multiline  operator +  ( const vector& ) const;
	multiline  operator -  ( const vector& ) const;
	multiline  operator *  ( const vector& ) const;
	multiline  operator /  ( const vector& ) const;

	multiline& operator += ( f32 );
	multiline& operator -= ( f32 );
	multiline& operator *= ( f32 );
	multiline& operator /= ( f32 );
	multiline  operator +  ( f32 ) const;
	multiline  operator -  ( f32 ) const;
	multiline  operator *  ( f32 ) const;
	multiline  operator /  ( f32 ) const;

	      vector& get_vertex ( s32 );
	const vector& get_vertex ( s32 ) const;

	virtual multiline& set_tile ( const map2d::tile& );

	line get_aabb () const;

	multiline get_moved ( f32, f32 ) const;

	virtual bl intersects ( translation&, f32, f32, const line&      ) const;
	virtual bl intersects ( translation&, f32, f32, const multiline& ) const;
	virtual bl intersects ( translation&, f32, f32, const polygon&   ) const;

	virtual void draw ( const video::color&, const video::color& ) const;
	virtual void draw ( const video::color&                      ) const;

};



/* 2d engine polygon class declaration ******************************************************************/



class polygon : public multiline
{

public:

	polygon (                                                            );
	polygon ( const vector&, const vector&, const vector&                );
	polygon ( const vector&, const vector&, const vector&, const vector& );
	polygon ( const map2d::tile&                                         );
	polygon ( const polygon&                                             );
 ~polygon () {};

	polygon& operator += ( const vector& );
	polygon& operator -= ( const vector& );
	polygon& operator *= ( const vector& );
	polygon& operator /= ( const vector& );
	polygon  operator +  ( const vector& ) const;
	polygon  operator -  ( const vector& ) const;
	polygon  operator *  ( const vector& ) const;
	polygon  operator /  ( const vector& ) const;

	polygon& operator += ( f32 );
	polygon& operator -= ( f32 );
	polygon& operator *= ( f32 );
	polygon& operator /= ( f32 );
	polygon  operator +  ( f32 ) const;
	polygon  operator -  ( f32 ) const;
	polygon  operator *  ( f32 ) const;
	polygon  operator /  ( f32 ) const;

	polygon get_moved ( f32, f32 ) const;

	void draw ( const video::color&, const video::color& ) const;
	void draw ( const video::color&                      ) const;

};



/* 2d engine projection class declaration ***************************************************************/



class projection
{

public:

	f32 min;
	f32 max;

public:

	projection (                               );
	projection ( const polygon&, const vector& );
	projection ( const projection&             );
 ~projection () {};

	bl operator <  ( const projection& ) const;
	bl operator <= ( const projection& ) const;
	bl operator == ( const projection& ) const;
	bl operator >= ( const projection& ) const;
	bl operator >  ( const projection& ) const;

	bl overlaps ( const projection& ) const;

	f32 get_overlap (                   ) const;
	f32 get_overlap ( const projection& ) const;

	f32 get_min_diff ( const projection& ) const;
	f32 get_max_diff ( const projection& ) const;

	projection& clear ();

	projection& get_projection ( const polygon&, const vector& );

	projection merge ( const projection& ) const;

};



/* end */
}}
#endif
