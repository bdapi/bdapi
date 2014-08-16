
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_VBO_MOD_CPP
#define BDAPI_VIDEO_VBO_MOD_CPP
#include "video/vbo.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace video {

/* vertex buffer object class modification function implementations */

// insert vec2
vbo& vbo::in_vec2( f32 x, f32 y )
{
	return in_vec2( math::vec2( x, y ) );
}
vbo& vbo::in_vec2( const math::vec2& v )
{
	if( vertex_size == 2 )
	{
		vec2s.insert(v);
	}

	RETHIS;
}

// insert vec3
vbo& vbo::in_vec3( f32 x, f32 y, f32 z )
{
	return in_vec3( math::vec3( x, y, z ) );
}
vbo& vbo::in_vec3( const math::vec3& v )
{
	if( vertex_size == 3 )
	{
		vec3s.insert(v);
	}

	RETHIS;
}

// insert normal
vbo& vbo::in_normal( f32 x, f32 y, f32 z )
{
	return in_normal( math::vec3( x, y, z ) );
}
vbo& vbo::in_normal( const math::vec3& n )
{
	if( using_normals )
	{
		normals.insert(n);
	}

	RETHIS;
}

// insert color
vbo& vbo::in_color( f32 r )
{
	return in_color( color(r) );
}
vbo& vbo::in_color( f32 r, f32 g )
{
	return in_color( color( r, g ) );
}
vbo& vbo::in_color( f32 r, f32 g, f32 b )
{
	return in_color( color( r, g, b ) );
}
vbo& vbo::in_color( f32 r, f32 g, f32 b, f32 a )
{
	return in_color( color( r, g, b, a ) );
}
vbo& vbo::in_color( const color& c )
{
	if( using_colors )
	{
		colors.insert(c);
	}

	RETHIS;
}

// insert texture coordinates
vbo& vbo::in_texture( f32 x, f32 y )
{
	return in_texture( math::vec2( x, y ) );
}
vbo& vbo::in_texture( const math::vec2& t )
{
	if( using_textures )
	{
		textures.insert(t);
	}

	RETHIS;
}

// clear vec2 buffer
vbo& vbo::clear_vec2s()
{
	if( active )
	{
		deactivate();
	}

	if( linked )
	{
		unlink();
	}

	vec2s.clear();

	RETHIS;
}

// clear vec3 buffer
vbo& vbo::clear_vec3s()
{
	if( active )
	{
		deactivate();
	}

	if( linked )
	{
		unlink();
	}

	vec3s.clear();

	RETHIS;
}

// clear any vec buffer
vbo& vbo::clear_vecs()
{
	if( active )
	{
		deactivate();
	}

	if( linked )
	{
		unlink();
	}

	if( vertex_size == 2 )
	{
		vec2s.clear();
	}
	else if( vertex_size == 3 )
	{
		vec3s.clear();
	}

	RETHIS;
}

// clear normal buffer
vbo& vbo::clear_normals()
{
	if( active )
	{
		deactivate();
	}

	if( linked )
	{
		unlink();
	}

	normals.clear();

	RETHIS;
}

// clear color buffer
vbo& vbo::clear_colors()
{
	if( active )
	{
		deactivate();
	}

	if( linked )
	{
		unlink();
	}

	colors.clear();

	RETHIS;
}

// clear texture coordinate buffer
vbo& vbo::clear_textures()
{
	if( active )
	{
		deactivate();
	}

	if( linked )
	{
		unlink();
	}

	textures.clear();

	RETHIS;
}

// clear all
vbo& vbo::clear()
{
	if( active )
	{
		deactivate();
	}

	if( linked )
	{
		unlink();
	}

	vec2s.clear();
	vec3s.clear();
	normals.clear();
	colors.clear();
	textures.clear();

	RETHIS;
}

/* end */

}
}

#endif
