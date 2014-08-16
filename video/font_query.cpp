
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_FONT_QUERY_CPP
#define BDAPI_VIDEO_FONT_QUERY_CPP
#include "video/font.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace video {

/* bitmap font class query function implementations */

// get glyph width
s32 font::get_glyph_width( u8 c )
{
	return glyph_widths[c];
}

// get x1
f32 font::get_x1( u8 c )
{
	return tex_coords_x1[c];
}

// get y1
f32 font::get_y1( u8 c )
{
	return tex_coords_y1[c];
}

// get x2
f32 font::get_x2( u8 c )
{
	return tex_coords_x2[c];
}

// get y2
f32 font::get_y2( u8 c )
{
	return tex_coords_y2[c];
}

/* end */

}
}

#endif
