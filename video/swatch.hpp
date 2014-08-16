
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_SWATCH_HPP
#define BDAPI_VIDEO_SWATCH_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "io/path.hpp"

// namespaces
namespace bdapi {
namespace video {

/* swatch class declaration */

class swatch
{

private: // private core data

	BD_GET_COPY_INIT( private, raw*, swatch_raw, NULL );

	BD_GET_COPY_INIT( private, image*, swatch_image, NULL );

private: // private descriptor data

	BD_GET_COPY_INIT( private, s32, width,  1 );
	BD_GET_COPY_INIT( private, s32, height, 1 );

public: // public initialization functions (video_swatch_init.cpp)

	swatch () {};
	swatch ( io::path filename );
 ~swatch ();

	result initialize ( io::path filename );

public: // public core functions (video_swatch_core.cpp)

	color get_color ( s32 x, s32 y, const palette* swatch_palette ) const;

};

/* end */

}
}

#endif
