
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_BUFFER_QUERY_CPP
#define BDAPI_VIDEO_BUFFER_QUERY_CPP
#include "video/buffer.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"

// namespaces
namespace bdapi {
namespace video {

/* frame buffer class query function implementations */

// get width
s32 buffer::get_width() const
{
	return buffer_image.get_width();
}

// get height
s32 buffer::get_height() const
{
	return buffer_image.get_height();
}

// get channels
s32 buffer::get_channels() const
{
	return buffer_image.get_channels();
}

// is filtered
bl buffer::is_filtered() const
{
	return buffer_image.is_filtered();
}

// is mipmapped
bl buffer::is_mipmapped() const
{
	return buffer_image.is_mipmapped();
}

// is clamped
bl buffer::is_clamped() const
{
	return buffer_image.is_clamped();
}

// is active
bl buffer::is_active() const
{
	return gl::get_current_buffer() == this;
}

/* end */

}
}

#endif
