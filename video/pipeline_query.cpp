
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_PIPELINE_QUERY_CPP
#define BDAPI_VIDEO_PIPELINE_QUERY_CPP
#include "video/pipeline.hpp"

/* includes */

// bdapi
#include "video/buffer.hpp"
#include "video/shader.hpp"

// namespaces
namespace bdapi {
namespace video {

/* pipeline class query function implementations */

// get width
s32 pipeline::get_width() const
{
	if( current_buffer )
	{
		return current_buffer->get_width();
	}
	else
	{
		return -1;
	}
}

// get height
s32 pipeline::get_height() const
{
	if( current_buffer )
	{
		return current_buffer->get_height();
	}
	else
	{
		return -1;
	}
}

// get channels
s32 pipeline::get_channels() const
{
	if( current_buffer )
	{
		return current_buffer->get_channels();
	}
	else
	{
		return -1;
	}
}

// is filtered
bl pipeline::is_filtered() const
{
	if( current_buffer )
	{
		return current_buffer->is_filtered();
	}
	else
	{
		return false;
	}
}

// is mipmapped
bl pipeline::is_mipmapped() const
{
	if( current_buffer )
	{
		return current_buffer->is_mipmapped();
	}
	else
	{
		return false;
	}
}

// is clamped
bl pipeline::is_clamped() const
{
	if( current_buffer )
	{
		return current_buffer->is_clamped();
	}
	else
	{
		return false;
	}
}

// is buffer active
bl pipeline::is_buffer_active() const
{
	if( current_buffer )
	{
		return current_buffer->is_active();
	}
	else
	{
		return false;
	}
}

// is shader active
bl pipeline::is_shader_active() const
{
	if( current_shader )
	{
		return current_shader->is_active();
	}
	else
	{
		return false;
	}
}

// get image
image& pipeline::get_image()
{
	return current_buffer->get_image();
}

// get const image
const image& pipeline::get_image() const
{
	return current_buffer->get_image();
}

/* end */

}
}

#endif
