
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_IMAGE_QUERY_CPP
#define BDAPI_VIDEO_IMAGE_QUERY_CPP
#include "video/image.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"

// namespaces
namespace bdapi {
namespace video {

/* image class query function implementations */

// is active
bl image::is_active() const
{
	return gl::get_current_image() == this;
}

// static get filter parameters
s32 image::get_filter_params( bl filtered, bl mipmapped )
{
	if( mipmapped )
	{
		if( filtered )
		{
			return GL_LINEAR_MIPMAP_LINEAR;
		}
		else
		{
			return GL_NEAREST_MIPMAP_NEAREST;
		}
	}
	else
	{
		if( filtered )
		{
			return GL_LINEAR;
		}
		else
		{
			return GL_NEAREST;
		}
	}
}

// static get clamping parameters
s32 image::get_clamping_params( bl clamped )
{
	if( clamped )
	{
		return GL_CLAMP;
	}
	else
	{
		return GL_REPEAT;
	}
}

// static get internal format
s32 image::get_internal_format( s32 channels )
{
	return get_internal_format( channels, false );
}
s32 image::get_internal_format( s32 channels, bl is_buffer )
{
	if( is_buffer )
	{
		switch( channels )
		{
			case 1:  return GL_R16F;
			case 2:  return GL_RG16F;
			case 3:  return GL_RGB16F;
			case 4:  return GL_RGBA16F;
			default: return GL_RGB16F;
		}
	}
	else
	{
		switch( channels )
		{
			case 1:  return GL_R8;
			case 2:  return GL_RG8;
			case 3:  return GL_RGB8;
			case 4:  return GL_RGBA8;
			default: return GL_RGB8;
		}
	}
}

// static get external format
s32 image::get_external_format( s32 channels )
{
	switch( channels )
	{
		case 1:  return GL_RED;
		case 2:  return GL_RG;
		case 3:  return GL_RGB;
		case 4:  return GL_RGBA;
		default: return GL_RGB;
	}
}

// static get data format
s32 image::get_data_format()
{
	return get_data_format( false );
}
s32 image::get_data_format( bl is_buffer )
{
	if( is_buffer )
	{
		return GL_FLOAT;
	}
	else
	{
		return GL_UNSIGNED_BYTE;
	}
}

/* end */

}
}

#endif
