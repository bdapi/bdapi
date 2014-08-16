
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_FONT_INIT_CPP
#define BDAPI_VIDEO_FONT_INIT_CPP
#include "video/font.hpp"

/* includes */

// bdapi
#include "io/file.hpp"

#include "video/opengl.hpp"
#include "video/blitter.hpp"
#include "video/color.hpp"
#include "video/image.hpp"
#include "video/palette.hpp"
#include "video/raw.hpp"
#include "video/swatch.hpp"

// namespaces
namespace bdapi {
namespace video {

/* bitmap font class initialization function implementations */

// contructors
font::font( const io::path& filename, palette* palette_font, swatch* swatch_font, s32 char_spacing,
s32 line_spacing, s32 default_color )
{
	initialize( filename, palette_font, swatch_font, char_spacing, line_spacing, default_color );
}

// destructor
font::~font()
{
	delete font_image;
}

// initialize
result font::initialize( const io::path& filename, palette* font_palette, swatch* font_swatch,
s32 char_spacing, s32 line_spacing, s32 default_color )
{
	io::file font_file( filename );

	if( !font_file.read( true ) )
	{
		return 0;
	}

	s32 font_width    = font_file.out<s32>();
	s32 font_height   = font_file.out<s32>();
	s32 font_channels = font_file.out<u8>();

	if( font_channels != 1 )
	{
		return 0;
	}

	raw font_raw;

	if( !font_raw.initialize( font_file.get_data( true ), font_width, font_height, font_channels ) )
	{
		return 0;
	}

	font_image = new image();

	if( !font_image->initialize( font_raw, false, false, false ) )
	{
		return 0;
	}

	font_file += font_raw.get_size();

	glyph_height = font_file.out<s32>();

	fori(256)
	{
		glyph_widths[i] = font_file.out<s32>();
	}

	fori(256)
	{
		tex_coords_x1[i] = font_file.out<f32>();
	}

	fori(256)
	{
		tex_coords_y1[i] = font_file.out<f32>();
	}

	fori(256)
	{
		tex_coords_x2[i] = font_file.out<f32>();
	}

	fori(256)
	{
		tex_coords_y2[i] = font_file.out<f32>();
	}

	glyph_max_width = font_file.out<s32>();

	if( !font_palette )
	{
		return 0;
	}

	this->font_palette = font_palette;

	if( !font_swatch )
	{
		return 0;
	}

	this->font_swatch = font_swatch;

	this->char_spacing  = char_spacing;
	this->line_spacing  = line_spacing;
	this->default_color = default_color;

	return 1;
}

/* end */

}
}

#endif
