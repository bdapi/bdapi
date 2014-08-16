
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_VBO_QUERY_CPP
#define BDAPI_VIDEO_VBO_QUERY_CPP
#include "video/vbo.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace video {

/* vertex buffer object class query function implementations */

// get vec2 buffer size
s32 vbo::get_vec2s_size() const
{
	return vec2s.get_size();
}

// get vec3 buffer size
s32 vbo::get_vec3s_size() const
{
	return vec3s.get_size();
}

// get any vec buffer size
s32 vbo::get_vecs_size() const
{
	if( vertex_size == 2 )
	{
		return get_vec2s_size();
	}
	else if( vertex_size == 3 )
	{
		return get_vec3s_size();
	}
	else
	{
		return -1;
	}
}

// get normal buffer size
s32 vbo::get_normals_size() const
{
	return normals.get_size();
}

// get color buffer size
s32 vbo::get_colors_size() const
{
	return colors.get_size();
}

// get texture coordinate buffer size
s32 vbo::get_textures_size() const
{
	return textures.get_size();
}

// get size
s32 vbo::get_size() const
{
	return get_vecs_size();
}

// is empty
bl vbo::is_empty() const
{
	if( vertex_size == 2 )
	{
		return vec2s.is_empty();
	}
	else if( vertex_size == 3 )
	{
		return vec3s.is_empty();
	}
	else
	{
		return true;
	}
}

/* end */

}
}

#endif
