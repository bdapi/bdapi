
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_PALETTE_INIT_CPP
#define BDAPI_VIDEO_PALETTE_INIT_CPP
#include "video/palette.hpp"

/* includes */

// bdapi
#include "video/raw.hpp"

/* namespaces */
namespace bdapi {
namespace video {

/* palette class initialization function implementations */

// constructors
palette::palette() : palette_color_vector()
{
}
palette::palette( s32 size ) : palette_color_vector( size )
{
	width = size;
}
palette::palette( s32 width, s32 height ) : palette_color_vector( width * height )
{
	this->width  = width;
	this->height = height;
}
palette::palette( io::path filename )
{
	initialize( filename );
}
palette::palette( const raw& raw_image )
{
	initialize( raw_image );
}

// initializers
result palette::initialize( io::path filename )
{
	raw raw_image;

	if( !raw_image.initialize( filename ) )
	{
		return 0;
	}

	return initialize( raw_image );
}
result palette::initialize( const raw& raw_image )
{
	width  = raw_image.get_width();
	height = raw_image.get_height();

	palette_color_vector::initialize( width * height );

	fori( raw_image.get_pixels() )
	{
		set( i, raw_image.get_color(i) );
	}

	return 1;
}

/* end */

}
}

#endif
