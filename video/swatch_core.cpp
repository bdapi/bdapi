
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_SWATCH_CORE_CPP
#define BDAPI_VIDEO_SWATCH_CORE_CPP
#include "video/swatch.hpp"

/* includes */

// bdapi
#include "video/palette.hpp"
#include "video/raw.hpp"

// namespaces
namespace bdapi {
namespace video {

/* swatch class core function implementations */

// get color
color swatch::get_color( s32 x, s32 y, const palette* swatch_palette ) const
{
	return swatch_palette->get(
		swatch_raw->get_u8_r( x, y ),
		swatch_raw->get_u8_g( x, y ) );
}

/* end */

}
}

#endif
