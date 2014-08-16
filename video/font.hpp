
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_FONT_HPP
#define BDAPI_VIDEO_FONT_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "io/path.hpp"

// namespaces
namespace bdapi {
namespace video {

/* bitmap font class declaration */

class font
{

private: // private data

	BD_GET_COPY( private, image*,   font_image   );
	BD_GET_COPY( private, palette*, font_palette );
	BD_GET_COPY( private, swatch*,  font_swatch  );

	BD_GET_COPY( private, s32, glyph_height    );
	BD_GET_COPY( private, s32, glyph_max_width );

	s32 glyph_widths[256];

	f32 tex_coords_x1[256];
	f32 tex_coords_y1[256];
	f32 tex_coords_x2[256];
	f32 tex_coords_y2[256];

	BD_GET_COPY( private, s32, char_spacing  );
	BD_GET_COPY( private, s32, line_spacing  );
	BD_GET_COPY( private, s32, default_color );

	BD_GET_COPY( private, s32, write_x );
	BD_GET_COPY( private, s32, write_y );


public: // public initialization functions (video_font_init.cpp)

	font () {};
	font ( const io::path& filename, palette* font_palette, swatch* font_swatch,
	       s32 char_spacing, s32 line_spacing, s32 default_color );
 ~font ();

	result initialize ( const io::path& filename, palette* font_palette, swatch* font_swatch,
	                    s32 char_spacing, s32 line_spacing, s32 default_color );

public: // public core functions (video_font_core.cpp)

	void set_position ( s32 x, s32 y             );
	void set_position ( s32 x, s32 y, bl aligned );

	void write ( s32 x, s32 y, cstr input, ... );
	void write (               cstr input, ... );

	void write_break ();

public: // public query functions (video_font_query.cpp)

	s32 get_glyph_width ( u8 c );

	f32 get_x1 ( u8 c );
	f32 get_y1 ( u8 c );
	f32 get_x2 ( u8 c );
	f32 get_y2 ( u8 c );

};

/* end */

}
}

#endif
