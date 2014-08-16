
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_VBO_INIT_CPP
#define BDAPI_VIDEO_VBO_INIT_CPP
#include "video/vbo.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace video {

/* vertex buffer object class initialization function implementations */

// constructors
vbo::vbo( s32 vertex_size, bl using_normals, bl using_colors, bl using_textures, s32 update_mode,
s32 draw_mode )
{
	initialize( vertex_size, using_normals, using_colors, using_textures, update_mode, draw_mode );
}

// destructor
vbo::~vbo()
{
	if( active )
	{
		deactivate();
	}

	if( linked )
	{
		unlink();
	}
}

// initializers
result vbo::initialize( s32 vertex_size, bl using_normals, bl using_colors, bl using_textures,
s32 update_mode, s32 draw_mode )
{
	if( vertex_size != 2 && vertex_size != 3 )
	{
		return 0;
	}

	this->vertex_size = vertex_size;

	this->using_normals  = using_normals;
	this->using_colors   = using_colors;
	this->using_textures = using_textures;

	this->update_mode = update_mode;
	this->draw_mode   = draw_mode;

	return 1;
}

/* end */

}
}

#endif
