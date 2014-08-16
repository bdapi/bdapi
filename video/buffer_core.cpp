
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_BUFFER_CORE_CPP
#define BDAPI_VIDEO_BUFFER_CORE_CPP
#include "video/buffer.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"

// namespaces
namespace bdapi {
namespace video {

/* frame buffer class core function implementations */

// activate
buffer& buffer::activate()
{
	if( gl::get_current_buffer() != NULL )
	{
		gl::get_current_buffer()->deactivate();
	}

	glBindFramebufferEXT(  FRAMEBUFFER_EXT,  frame_handle  );
	glBindRenderbufferEXT( RENDERBUFFER_EXT, render_handle );

	gl::set_current_buffer( this );

	gl::view_2d();

	RETHIS;
}

// deactivate
buffer& buffer::deactivate()
{
	if( gl::get_current_buffer() == this )
	{
		glBindFramebufferEXT(  FRAMEBUFFER_EXT,  0 );
		glBindRenderbufferEXT( RENDERBUFFER_EXT, 0 );

		gl::set_current_buffer( NULL );

		gl::view_2d();
	}

	RETHIS;
}

// bind
buffer& buffer::bind()
{
	buffer_image.bind();

	RETHIS;
}

// unbind image
buffer& buffer::unbind()
{
	buffer_image.unbind();

	RETHIS;
}

// get image
image& buffer::get_image()
{
	return buffer_image;
}
const image& buffer::get_image() const
{
	return buffer_image;
}

/* end */

}
}

#endif
