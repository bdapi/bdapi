
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_COLOR_HPP
#define BDAPI_VIDEO_COLOR_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "vector"

// bdapi
#include "string/string.hpp"
#include "util/container.hpp"

/* namespaces */
namespace bdapi {
namespace video {

/* color class declaration */

class color
{

public: // public data

	f32 data[4] = { 0.f, 0.f, 0.f, 1.f };

public: // public initialization functions (video_color_init.cpp)

	color () {};
	color ( f32 red                                 );
	color ( f32 red, f32 green                      );
	color ( f32 red, f32 green, f32 blue            );
	color ( f32 red, f32 green, f32 blue, f32 alpha );
	color ( const color& copy                       );
 ~color () {};

	static color by_f32 ( f32 red                                 );
	static color by_f32 ( f32 red, f32 green                      );
	static color by_f32 ( f32 red, f32 green, f32 blue            );
	static color by_f32 ( f32 red, f32 green, f32 blue, f32 alpha );

	static color by_u8 ( s32 red                                 );
	static color by_u8 ( s32 red, s32 green                      );
	static color by_u8 ( s32 red, s32 green, s32 blue            );
	static color by_u8 ( s32 red, s32 green, s32 blue, s32 alpha );

public: // public core functions (video_color_core.cpp)

	color& invert (                              );
	color& invert ( bl color_flag                );
	color& invert ( bl color_flag, bl alpha_flag );

	color& bind       ();
	color& bind_clear ();

	util::container<  u8, std::vector > get_u8_data  () const;
	util::container< f32, std::vector > get_f32_data () const;

	string create_html_color () const;

	color to_xyz        () const;
	color to_hunter_lab () const;
	color to_cie_lab    () const;

	f32 get_distance ( const color& other ) const;

public: // public modification functions (video_color_mod.cpp)

	color& set_f32   ( s32 i, f32 c );
	color& set_f32_r ( f32 red      );
	color& set_f32_g ( f32 green    );
	color& set_f32_b ( f32 blue     );
	color& set_f32_a ( f32 alpha    );

	color& set_u8   ( s32 i, s32 c );
	color& set_u8_r ( s32 red      );
	color& set_u8_g ( s32 green    );
	color& set_u8_b ( s32 blue     );
	color& set_u8_a ( s32 alpha    );

	color& set_color ( const color& other );

public: // public query functions (video_color_query.cpp)

	f32 get_f32   ( s32 i ) const;
	f32 get_f32_r (       ) const;
	f32 get_f32_g (       ) const;
	f32 get_f32_b (       ) const;
	f32 get_f32_a (       ) const;

	s32 get_u8   ( s32 i ) const;
	s32 get_u8_r (       ) const;
	s32 get_u8_g (       ) const;
	s32 get_u8_b (       ) const;
	s32 get_u8_a (       ) const;

	const f32* get_data () const;

public: // public operator functions (video_color_ops.cpp)

	color  operator +  ( const color& other ) const;
	color  operator -  ( const color& other ) const;
	color  operator *  ( const color& other ) const;
	color  operator /  ( const color& other ) const;
	color& operator += ( const color& other );
	color& operator -= ( const color& other );
	color& operator *= ( const color& other );
	color& operator /= ( const color& other );

	bl operator == ( const color& other ) const;
	bl operator != ( const color& other ) const;

	f32  operator () ( s32 i ) const;
	f32& operator [] ( s32 i );

};

/* end */

}
}

#endif
