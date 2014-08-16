
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_BUFFER_INIT_CPP
#define BDAPI_VIDEO_BUFFER_INIT_CPP
#include "video/buffer.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"

// namespaces
namespace bdapi {
namespace video {

/* frame buffer class initialization function implementations */

// constructors
buffer::buffer( s32 width, s32 height, s32 channels )
{
	initialize( width, height, channels );
}
buffer::buffer( s32 width, s32 height, s32 channels, bl filtered, bl mipmapped, bl clamped )
{
	initialize( width, height, channels, filtered, mipmapped, clamped );
}

// destructor
buffer::~buffer()
{
	if( frame_handle && render_handle )
	{
		if( gl::get_current_buffer() == this )
		{
			deactivate();
		}

		glDeleteFramebuffersEXT(  1, &frame_handle  );
		glDeleteRenderbuffersEXT( 1, &render_handle );
	}
}

// initialize
result buffer::initialize( s32 width, s32 height, s32 channels )
{
	return initialize( width, height, channels, video::is_default_filtered(), video::is_default_mipmapped(),
		video::is_default_clamped() );
}
result buffer::initialize( s32 width, s32 height, s32 channels, bl filtered, bl mipmapped, bl clamped )
{
	if( !buffer_image.initialize( NULL, width, height, channels, filtered, mipmapped, clamped ) )
	{
		return 0;
	}

	glGenFramebuffersEXT(  1, &frame_handle  );
	glGenRenderbuffersEXT( 1, &render_handle );

	buffer_open();

	glRenderbufferStorageEXT( RENDERBUFFER_EXT, DEPTH_COMPONENT, width, height );

	glFramebufferTexture2DEXT( FRAMEBUFFER_EXT, COLOR_ATTACHMENT0_EXT, TEXTURE_2D, buffer_image.handle, 0 );

	glFramebufferRenderbufferEXT( FRAMEBUFFER_EXT, DEPTH_ATTACHMENT, RENDERBUFFER_EXT, render_handle );

	buffer_close();

	return 1;
}

// private buffer open
void buffer::buffer_open()
{
	glBindFramebufferEXT(  FRAMEBUFFER_EXT,  frame_handle  );
	glBindRenderbufferEXT( RENDERBUFFER_EXT, render_handle );
}

// private buffer close
void buffer::buffer_close()
{
	if( gl::get_current_buffer() )
	{
		gl::get_current_buffer()->activate();
	}
	else
	{
		glBindFramebufferEXT(  FRAMEBUFFER_EXT,  0 );
		glBindRenderbufferEXT( RENDERBUFFER_EXT, 0 );
	}
}

/* end */

}
}

#endif
