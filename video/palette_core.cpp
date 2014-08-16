
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_PALETTE_CORE_CPP
#define BDAPI_VIDEO_PALETTE_CORE_CPP
#include "video/palette.hpp"

/* includes */

// bdapi
#include "video/image.hpp"
#include "video/raw.hpp"

/* namespaces */
namespace bdapi {
namespace video {

/* palette class core function implementations */

// private create raw image
raw* palette::create_raw() const
{
	raw* raw_image = new raw( 256, 256, 4 );

	fory( height )
	{
		forx( width )
		{
			raw_image->set_color( x, y, get( x, y ) );
		}
	}

	return raw_image;
}

// private create image
image* palette::create_image() const
{
	raw* raw_image = create_raw();

	image* new_image = new image();

	if( !new_image->initialize( *raw_image, false, false, true ) )
	{
		delete raw_image; raw_image = NULL;
		delete new_image; new_image = NULL;

		return NULL;
	}

	delete raw_image; raw_image = NULL;

	return new_image;
}

// compile
image* palette::compile()
{
	if( get_size() < 2 )
	{
		return NULL;
	}

	delete palette_image;

	palette_image = create_image();

	return palette_image;
}

/* end */

}
}

#endif
