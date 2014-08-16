
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_RAW_HPP
#define BDAPI_VIDEO_RAW_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "vector"

// bdapi
#include "string/string.hpp"
#include "io/path.hpp"
#include "util/container.hpp"
#include "video/color.hpp"

// namespaces
namespace bdapi {
namespace video {

/* raw image typedef declarations */

typedef util::container<    u8, std::vector > raw_u8_vector;
typedef util::container<   f32, std::vector > raw_f32_vector;
typedef util::container< color, std::vector > raw_color_vector;

/* raw image class declaration */

class raw
{

private: // private core data

	raw_u8_vector data;

private: // private descriptor data

	BD_GET_COPY( private, s32, width    );
	BD_GET_COPY( private, s32, height   );
	BD_GET_COPY( private, s32, channels );

	BD_GET_COPY( private, s32, pixels );
	BD_GET_COPY( private, s32, size   );

public: // public initialization functions (video_raw_init.cpp)

	raw () {};
	raw ( io::path filename                                           );
	raw ( io::path filename, bl bdfile                                );
	raw ( raw_color_vector& data, s32 width, s32 height, s32 channels );
	raw (   raw_f32_vector& data, s32 width, s32 height, s32 channels );
	raw (    raw_u8_vector& data, s32 width, s32 height, s32 channels );
	raw (            color* data, s32 width, s32 height, s32 channels );
	raw (              f32* data, s32 width, s32 height, s32 channels );
	raw (               u8* data, s32 width, s32 height, s32 channels );
	raw (                         s32 width, s32 height, s32 channels );
	raw ( const raw& copy                                             );
 ~raw () {};

	result initialize ( io::path filename                                           );
	result initialize ( io::path filename, bl bdfile                                );
	result initialize ( raw_color_vector& data, s32 width, s32 height, s32 channels );
	result initialize (   raw_f32_vector& data, s32 width, s32 height, s32 channels );
	result initialize (    raw_u8_vector& data, s32 width, s32 height, s32 channels );
	result initialize (            color* data, s32 width, s32 height, s32 channels );
	result initialize (              f32* data, s32 width, s32 height, s32 channels );
	result initialize (               u8* data, s32 width, s32 height, s32 channels );
	result initialize (                         s32 width, s32 height, s32 channels );

public: // public core functions (video_raw_core.cpp)

	raw_u8_vector extract_channel ( s32 channel_index ) const;

	raw& flip_horizontally ();
	raw& flip_vertically   ();

	raw& rgb_to_bgr ();
	raw& bgr_to_rgb ();

	raw& replace ( const color& old_color, const color& new_color );

	raw_f32_vector   get_f32_data   () const;
	raw_color_vector get_color_data () const;

public: // public modification functions (video_raw_mod.cpp)

	raw& set_u8 ( s32 i,               s32 c );
	raw& set_u8 ( s32 i,        s32 j, s32 c );
	raw& set_u8 ( s32 x, s32 y, s32 j, s32 c );

	raw& set_u8_r ( s32 i, s32 red   );
	raw& set_u8_g ( s32 i, s32 green );
	raw& set_u8_b ( s32 i, s32 blue  );
	raw& set_u8_a ( s32 i, s32 alpha );

	raw& set_u8_r ( s32 x, s32 y, s32 red   );
	raw& set_u8_g ( s32 x, s32 y, s32 green );
	raw& set_u8_b ( s32 x, s32 y, s32 blue  );
	raw& set_u8_a ( s32 x, s32 y, s32 alpha );

	raw& set_f32 ( s32 i,               f32 c );
	raw& set_f32 ( s32 i,        s32 j, f32 c );
	raw& set_f32 ( s32 x, s32 y, s32 j, f32 c );

	raw& set_f32_r ( s32 i, f32 red   );
	raw& set_f32_g ( s32 i, f32 green );
	raw& set_f32_b ( s32 i, f32 blue  );
	raw& set_f32_a ( s32 i, f32 alpha );

	raw& set_f32_r ( s32 x, s32 y, f32 red   );
	raw& set_f32_g ( s32 x, s32 y, f32 green );
	raw& set_f32_b ( s32 x, s32 y, f32 blue  );
	raw& set_f32_a ( s32 x, s32 y, f32 alpha );

	raw& set_color ( s32 i,        const color& c );
	raw& set_color ( s32 x, s32 y, const color& c );

public: // public query functions (video_raw_query.cpp)

	s32 get_u8 ( s32 i               ) const;
	s32 get_u8 ( s32 i,        s32 j ) const;
	s32 get_u8 ( s32 x, s32 y, s32 j ) const;

	s32 get_u8_r ( s32 i ) const;
	s32 get_u8_g ( s32 i ) const;
	s32 get_u8_b ( s32 i ) const;
	s32 get_u8_a ( s32 i ) const;

	s32 get_u8_r ( s32 x, s32 y ) const;
	s32 get_u8_g ( s32 x, s32 y ) const;
	s32 get_u8_b ( s32 x, s32 y ) const;
	s32 get_u8_a ( s32 x, s32 y ) const;

	f32 get_f32 ( s32 i               ) const;
	f32 get_f32 ( s32 i,        s32 j ) const;
	f32 get_f32 ( s32 x, s32 y, s32 j ) const;

	f32 get_f32_r ( s32 i ) const;
	f32 get_f32_g ( s32 i ) const;
	f32 get_f32_b ( s32 i ) const;
	f32 get_f32_a ( s32 i ) const;

	f32 get_f32_r ( s32 x, s32 y ) const;
	f32 get_f32_g ( s32 x, s32 y ) const;
	f32 get_f32_b ( s32 x, s32 y ) const;
	f32 get_f32_a ( s32 x, s32 y ) const;

	color get_color ( s32 i        ) const;
	color get_color ( s32 x, s32 y ) const;

	u8* get_data ();

};

/* end */

}
}

#endif
