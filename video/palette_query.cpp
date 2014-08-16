
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_PALETTE_QUERY_CPP
#define BDAPI_VIDEO_PALETTE_QUERY_CPP
#include "video/palette.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace video {

/* palette class query function implementations */

// get
color& palette::get( s32 i )
{
	return palette_color_vector::get(i);
}
color& palette::get( s32 x, s32 y )
{
	return get( x + y * width );
}

// get const
const color& palette::get( s32 i ) const
{
	return palette_color_vector::get(i);
}
const color& palette::get( s32 x, s32 y ) const
{
	return get( x + y * width );
}

// get swatch
s32 palette::get_swatch( const color& c ) const
{
	fori( get_size() )
	{
		if( get(i) == c )
		{
			return i;
		}
	}

	return -1;
}

/* end */

}
}

#endif
