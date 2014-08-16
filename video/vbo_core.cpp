
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_VBO_CORE_CPP
#define BDAPI_VIDEO_VBO_CORE_CPP
#include "video/vbo.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"

// namespaces
namespace bdapi {
namespace video {

/* vertex buffer object class core function implementations */

// link
result vbo::link()
{
	if( is_empty() || linked || active )
	{
		return 0;
	}

	if( vertex_size == 2 )
	{
		clear_vec3s();
	}
	else if( vertex_size == 3 )
	{
		clear_vec2s();
	}

	if( !using_normals )
	{
		clear_normals();
	}

	if( !using_colors )
	{
		clear_colors();
	}

	if( !using_textures )
	{
		clear_textures();
	}

	s32 size = get_size();

	if( using_normals  && get_normals_size()  != size )
	{
		return 0;
	}

	if( using_colors   && get_colors_size()   != size )
	{
		return 0;
	}

	if( using_textures && get_textures_size() != size )
	{
		return 0;
	}

	if( vertex_size == 2 )
	{
		position_normals = vec2s.get_bytes();
	}
	else if( vertex_size == 3 )
	{
		position_normals = vec3s.get_bytes();
	}
	else
	{
		return 0;
	}

	position_colors   = position_normals  +  normals.get_bytes();
	position_textures = position_colors   +   colors.get_bytes();
	buffer_size       = position_textures + textures.get_bytes();

	if( vertex_size == 2 )
	{
		array_vecs = new f32[ size * 2 ]();

		fori( size )
		{
			array_vecs[ (i*2) + 0 ] = vec2s.get(i).x;
			array_vecs[ (i*2) + 1 ] = vec2s.get(i).y;
		}
	}
	else if( vertex_size == 3 )
	{
		array_vecs = new f32[ size * 3 ]();

		fori( size )
		{
			array_vecs[ (i*3) + 0 ] = vec3s.get(i).x;
			array_vecs[ (i*3) + 1 ] = vec3s.get(i).y;
			array_vecs[ (i*3) + 2 ] = vec3s.get(i).z;
		}
	}
	else
	{
		return 0;
	}

	if( using_normals )
	{
		array_normals = new f32[ size * 3 ]();

		fori( size )
		{
			array_normals[ (i*3) + 0 ] = normals.get(i).x;
			array_normals[ (i*3) + 1 ] = normals.get(i).y;
			array_normals[ (i*3) + 2 ] = normals.get(i).z;
		}
	}

	if( using_colors )
	{
		array_colors = new f32[ size * 4 ]();

		fori( size )
		{
			array_colors[ (i*4) + 0 ] = colors.get(i).get_f32_r();
			array_colors[ (i*4) + 1 ] = colors.get(i).get_f32_g();
			array_colors[ (i*4) + 2 ] = colors.get(i).get_f32_b();
			array_colors[ (i*4) + 3 ] = colors.get(i).get_f32_a();
		}
	}

	if( using_textures )
	{
		array_textures = new f32[ size * 2 ]();

		fori( size )
		{
			array_textures[ (i*2) + 0 ] = textures.get(i).x;
			array_textures[ (i*2) + 1 ] = textures.get(i).y;
		}
	}

	s32 size_bytes = size * sizeof(f32);

	glGenBuffers(            1, &handle );
	glBindBuffer( ARRAY_BUFFER,  handle );

	glBufferData( ARRAY_BUFFER, buffer_size, NULL, update_mode );

	glBufferSubData(   ARRAY_BUFFER, 0,                 size_bytes * vertex_size, array_vecs     );

	if( using_normals )
	{
		glBufferSubData( ARRAY_BUFFER, position_normals,	size_bytes * 3,           array_normals  );
	}

	if( using_colors )
	{
		glBufferSubData( ARRAY_BUFFER, position_colors,	  size_bytes * 4,           array_colors   );
	}

	if( using_textures )
	{
		glBufferSubData( ARRAY_BUFFER, position_textures, size_bytes * 2,           array_textures );
	}

	glBindBuffer( ARRAY_BUFFER, 0 );

	linked = true;

	return 1;
}

// unlink
result vbo::unlink()
{
	if( active )
	{
		deactivate();
	}

	linked = false;

	glDeleteBuffers( 1, &handle );

	DEL_X( array_vecs     );
	DEL_X( array_normals  );
	DEL_X( array_colors   );
	DEL_X( array_textures );

	buffer_size = 0;

	position_normals  = 0;
	position_colors   = 0;
	position_textures = 0;

	return 1;
}

// activate
result vbo::activate()
{
	if( !linked || active )
	{
		return 0;
	}

	if( vertex_size == 2 )
	{
		active = true;

		glBindBuffer( ARRAY_BUFFER, handle );

		glEnableClientState( VERTEX_ARRAY );

		glVertexPointer( 2, FLOAT, 0, (void*)0 );
	}
	else if( vertex_size == 3 )
	{
		active = true;

		glBindBuffer( ARRAY_BUFFER, handle );

		glEnableClientState( VERTEX_ARRAY );

		glVertexPointer( 3, FLOAT, 0, (void*)0 );
	}
	else
	{
		return 0;
	}

	if( using_normals )
	{
		glEnableClientState( NORMAL_ARRAY );

		glNormalPointer( FLOAT, 0, (void*)position_normals );
	}

	if( using_colors )
	{
		glEnableClientState( COLOR_ARRAY );

		glColorPointer( 4, FLOAT, 0, (void*)position_colors );
	}

	if( using_textures )
	{
		glEnableClientState( TEXTURE_COORD_ARRAY );

		glTexCoordPointer( 2, FLOAT, 0, (void*)position_textures );
	}

	return 1;
}

// deactivate
result vbo::deactivate()
{
	active = false;

	glDisableClientState( VERTEX_ARRAY );

	if( using_textures )
	{
		glDisableClientState( TEXTURE_COORD_ARRAY );
	}

	if( using_colors )
	{
		glDisableClientState( COLOR_ARRAY );
	}

	if( using_normals )
	{
		glDisableClientState( NORMAL_ARRAY );
	}

	glBindBuffer( ARRAY_BUFFER, 0 );

	return 1;
}

// draw
vbo& vbo::draw()
{
	return draw( draw_mode );
}
vbo& vbo::draw( s32 draw_mode )
{
	glDrawArrays( draw_mode, 0, get_size() );

	RETHIS;
}

/* end */

}
}

#endif
