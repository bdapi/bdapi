
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_IMAGE_INIT_CPP
#define BDAPI_VIDEO_IMAGE_INIT_CPP
#include "video/image.hpp"

/* includes */

// bdapi
#include "display/handler.hpp"
#include "io/file.hpp"
#include "video/buffer.hpp"
#include "video/opengl.hpp"
#include "video/raw.hpp"

// namespaces
namespace bdapi {
namespace video {

/* image class initialization function implementations */

// constructors

// destructor
image::~image()
{
	if( handle )
	{
		if( gl::get_current_image() == this )
		{
			unbind();
		}

		glDeleteTextures( 1, &handle );
	}
}

// initialize from file
result image::initialize( const io::path filename )
{
	return initialize( filename, video::is_default_filtered(), video::is_default_mipmapped(),
		video::is_default_clamped() );
}
result image::initialize( const io::path filename, bl filtered, bl mipmapped, bl clamped )
{
	raw raw_image;

	if( !raw_image.initialize( filename ) )
	{
		return 0;
	}

	return initialize( raw_image, filtered, mipmapped, clamped );
}

// initialize from raw image
result image::initialize( raw& raw_image )
{
	return initialize( raw_image, video::is_default_filtered(), video::is_default_mipmapped(),
		video::is_default_clamped() );
}
result image::initialize( raw& raw_image, bl filtered, bl mipmapped, bl clamped )
{
	return initialize( raw_image.get_data(), raw_image.get_width(), raw_image.get_height(),
		raw_image.get_channels(), filtered, mipmapped, clamped );
}

// initialize from memory
result image::initialize( u8* data,s32 width, s32 height, s32 channels )
{
	return initialize( data, width, height, channels, video::is_default_filtered(),
		video::is_default_mipmapped(), video::is_default_clamped() );
}
result image::initialize( u8* data, s32 width, s32 height, s32 channels, bl filtered, bl mipmapped,
bl clamped )
{
	initialize_image( width, height, channels, filtered, mipmapped, clamped );

	s32 int_fmt = get_internal_format( this->channels, data == NULL );
	s32 ext_fmt = get_external_format( this->channels               );
	s32 dat_fmt = get_data_format    (                 data == NULL );

	glTexImage2D( TEXTURE_2D, 0, int_fmt, this->width, this->height, 0, ext_fmt, dat_fmt, data );

	if( mipmapped )
	{
		gluBuild2DMipmaps( TEXTURE_2D, int_fmt, this->width, this->height, ext_fmt, dat_fmt, data );
	}

	image_close();

	return 1;
}

// initialize from buffer
result image::initialize( s32 x, s32 y, s32 width, s32 height, s32 channels )
{
	return initialize( x, y, width, height, channels, video::is_default_filtered(),
		video::is_default_mipmapped(), video::is_default_clamped() );
}
result image::initialize( s32 x, s32 y, s32 width, s32 height, s32 channels, bl filtered, bl mipmapped,
bl clamped )
{
	return load_from_buffer( x, y, width, height, channels, filtered, mipmapped, clamped );
}

// load from buffer
result image::load_from_buffer( s32 x, s32 y, s32 width, s32 height, s32 channels )
{
	return load_from_buffer( x, y, width, height, channels, video::is_default_filtered(),
		video::is_default_mipmapped(), video::is_default_clamped() );
}
result image::load_from_buffer( s32 x, s32 y, s32 width, s32 height, s32 channels, bl filtered, bl mipmapped,
bl clamped )
{
	initialize_image( width, height, channels, filtered, mipmapped, clamped );

	if( gl::get_current_buffer() != NULL )
	{
		glCopyTexImage2D( TEXTURE_2D, 0, get_internal_format( this->channels ), x,
			gl::get_current_buffer()->get_height() - y - this->height, this->width, this->height, 0 );
	}
	else
	{
		glCopyTexImage2D( TEXTURE_2D, 0, get_internal_format( this->channels ), x,
			display::get_height()                  - y - this->height, this->width, this->height, 0 );
	}

	if( this->mipmapped )
	{
		// make mipmaps somehow
	}

	image_close();

	return 1;
}

// private initialize image
void image::initialize_image( s32 width, s32 height, s32 channels, bl filtered, bl mipmapped,
bl clamped )
{
	this->width    = width;
	this->height   = height;
	this->channels = channels;

	this->filtered  = this->default_filtered  = filtered;
	this->mipmapped = this->default_mipmapped = mipmapped;
	this->clamped   = this->default_clamped   = clamped;

	s32 filter_parameters   = get_filter_params  ( this->filtered, this->mipmapped );
	s32 clamping_parameters = get_clamping_params( this->clamped                   );

	glGenTextures( 1, &handle );

	image_open();

	glTexParameteri( TEXTURE_2D, TEXTURE_MIN_FILTER, filter_parameters   );
	glTexParameteri( TEXTURE_2D, TEXTURE_MAG_FILTER, filter_parameters   );
	glTexParameteri( TEXTURE_2D, TEXTURE_WRAP_S,     clamping_parameters );
	glTexParameteri( TEXTURE_2D, TEXTURE_WRAP_T,     clamping_parameters );
}

// private image open
void image::image_open()
{
	glBindTexture( TEXTURE_2D, handle );
}

// private image close
void image::image_close()
{
	if( gl::get_current_image() != NULL )
	{
		gl::get_current_image()->bind();
	}
	else
	{
		glBindTexture( TEXTURE_2D, 0 );
	}
}

/* end */

}
}

#endif
