
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_IMAGE_CORE_CPP
#define BDAPI_VIDEO_IMAGE_CORE_CPP
#include "video/image.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"

// namespaces
namespace bdapi {
namespace video {

/* image class core function implementations */

// bind image
image& image::bind()
{
	glBindTexture( TEXTURE_2D, handle );

	gl::set_current_image( this );

	RETHIS;
}

// unbind image
image& image::unbind()
{
	if( is_active() )
	{
		glBindTexture( TEXTURE_2D, 0 );
	}

	gl::set_current_image( NULL );

	RETHIS;
}

/* end */

}
}

#endif
