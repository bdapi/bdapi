
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_FONT_CORE_CPP
#define BDAPI_VIDEO_FONT_CORE_CPP
#include "video/font.hpp"

/* includes */

// bdapi

#include "string/core.hpp"
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

/* bitmap font class core function implementations */

// set position
void font::set_position( s32 x, s32 y )
{
	set_position( x, y, false );
}
void font::set_position( s32 write_x, s32 write_y, bl aligned )
{
	this->write_x = write_x;
	this->write_y = write_y;

	if( aligned )
	{
		write_x *= ( glyph_max_width + char_spacing );
		write_y *= ( glyph_height    + line_spacing );
	}
}

// write
void font::write( s32 x, s32 y, cstr input, ... )
{
	STR_FORMAT;

	set_position( x, y );

	write( input );
}
void font::write( cstr input, ... )
{
	STR_FORMAT;

	font_image->bind();

	bl deactivate = false;

	if( gl::blitter::is_active() )
	{
		gl::blitter::set_palette( font_palette );
		gl::blitter::set_swatch( font_swatch, default_color );
	}
	else
	{
		gl::blitter::start( font_palette, font_swatch, default_color );

		deactivate = true;
	}

	s32 size = strlen( input );

	s32 x = write_x;
	s32 y = write_y;

	gl::begin(QUADS);

	fori( size )
	{
		if( input[i] == '~' && isdigit( input[i+1] ) && isdigit( input[i+2] ) )
		{
			gl::end();

			gl::blitter::set_index( font_swatch, ( input[i+1] - 48 ) * 10 + input[i+2] - 48 );

			gl::begin(QUADS);

			i += 2;
		}
		else if( input[i] == '\n' )
		{
			x  = write_x;
			y += glyph_height + line_spacing;
		}
		else
		{
			gl::tex    ( get_x1( input[i] ),              get_y2( input[i] )     );
			gl::vert_2i( x,                               y + get_glyph_height() );

			gl::tex    ( get_x2( input[i] ),              get_y2( input[i] )     );
			gl::vert_2i( x + get_glyph_width( input[i] ), y + get_glyph_height() );

			gl::tex    ( get_x2( input[i] ),              get_y1( input[i] )     );
			gl::vert_2i( x + get_glyph_width( input[i] ), y                      );

			gl::tex    ( get_x1( input[i] ),              get_y1( input[i] )     );
			gl::vert_2i( x,                               y                      );

			x += get_glyph_width( input[i] ) + char_spacing;
		}
	}

	gl::end();

	if( deactivate )
	{
		gl::blitter::stop();
	}

	write_y = y + glyph_height + line_spacing;
}

// write break
void font::write_break()
{
	write_y += glyph_height + line_spacing;
}

/* end */

}
}

#endif
