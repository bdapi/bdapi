
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_IMAGE_MOD_CPP
#define BDAPI_VIDEO_IMAGE_MOD_CPP
#include "video/image.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"

// namespaces
namespace bdapi {
namespace video {

/* image class modification function implementations */

// set filtered setting
image& image::set_filtered()
{
	return set_filtered( default_filtered );
}
image& image::set_filtered( bl filtered )
{
	image_open();

	this->filtered = filtered;

	s32 filter_parameters = get_filter_params( this->filtered, mipmapped );

	glTexParameteri( TEXTURE_2D, TEXTURE_MIN_FILTER, filter_parameters );
	glTexParameteri( TEXTURE_2D, TEXTURE_MAG_FILTER, filter_parameters );

	image_close();

	RETHIS;
}

// set mipmapped setting
image& image::set_mipmapped()
{
	return set_mipmapped( default_mipmapped );
}
image& image::set_mipmapped( bl mipmapped )
{
	image_open();

	this->mipmapped = mipmapped;

	s32 filter_parameters = get_filter_params( filtered, this->mipmapped );

	glTexParameteri( TEXTURE_2D, TEXTURE_MIN_FILTER, filter_parameters );
	glTexParameteri( TEXTURE_2D, TEXTURE_MAG_FILTER, filter_parameters );

	image_close();

	RETHIS;
}

// set clamped setting
image& image::set_clamped()
{
	return set_clamped( default_clamped );
}
image& image::set_clamped( bl clamped )
{
	image_open();

	this->clamped = clamped;

	s32 clamping_parameters = get_clamping_params( this->clamped );

	glTexParameteri( TEXTURE_2D, TEXTURE_WRAP_S, clamping_parameters );
	glTexParameteri( TEXTURE_2D, TEXTURE_WRAP_T, clamping_parameters );

	image_close();

	RETHIS;
}

/* end */

}
}

#endif
