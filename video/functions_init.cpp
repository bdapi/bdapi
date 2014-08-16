
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_FUNCTIONS_INIT_CPP
#define BDAPI_VIDEO_FUNCTIONS_INIT_CPP
#include "video/functions.hpp"

/* includes */

// magick
#include "Magick++.h"

// namespaces
namespace bdapi {
namespace video {

/* video initialization function implementations */

// load from native file
result init_magick()
{
	static bl magick_initialized = false;

	if( !magick_initialized )
	{
		Magick::InitializeMagick( NULL );

		magick_initialized = true;
	}

	return 1;
}

/* end */

}
}

#endif
