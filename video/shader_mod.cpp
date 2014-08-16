
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_SHADER_MOD_CPP
#define BDAPI_VIDEO_SHADER_MOD_CPP
#include "video/shader.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"
#include "video/color.hpp"
#include "video/image.hpp"
#include "video/palette.hpp"
#include "video/swatch.hpp"

// namespaces
namespace bdapi {
namespace video {

/* shader class modification function implementations */

// set int
shader& shader::set_int( string parameter, s32 x )
{
	glUniform1iARB( glGetUniformLocationARB( handle, parameter.c_str() ), x );

	RETHIS;
}
shader& shader::set_int( string parameter, s32 x, s32 y )
{
	glUniform2iARB( glGetUniformLocationARB( handle, parameter.c_str() ), x, y );

	RETHIS;
}
shader& shader::set_int( string parameter, s32 x, s32 y, s32 z )
{
	glUniform3iARB( glGetUniformLocationARB( handle, parameter.c_str() ), x, y, z );

	RETHIS;
}
shader& shader::set_int( string parameter, s32 x, s32 y, s32 z, s32 w )
{
	glUniform4iARB( glGetUniformLocationARB( handle, parameter.c_str() ), x, y, z, w );

	RETHIS;
}
shader& shader::set_ints( string parameter, s32 size, const s32* data, s32 amount )
{
	switch( size )
	{
		case 1:
		{
			glUniform1ivARB( glGetUniformLocationARB( handle, parameter.c_str() ), amount, data );

			break;
		}
		case 2:
		{
			glUniform2ivARB( glGetUniformLocationARB( handle, parameter.c_str() ), amount, data );

			break;
		}
		case 3:
		{
			glUniform3ivARB( glGetUniformLocationARB( handle, parameter.c_str() ), amount, data );

			break;
		}
		case 4:
		{
			glUniform4ivARB( glGetUniformLocationARB( handle, parameter.c_str() ), amount, data );

			break;
		}
	}

	RETHIS;
}

// set float
shader& shader::set_float( string parameter, f32 x )
{
	glUniform1fARB( glGetUniformLocationARB( handle, parameter.c_str() ), x );

	RETHIS;
}
shader& shader::set_float( string parameter, f32 x, f32 y )
{
	glUniform2fARB( glGetUniformLocationARB( handle, parameter.c_str() ), x, y );

	RETHIS;
}
shader& shader::set_float( string parameter, f32 x, f32 y, f32 z )
{
	glUniform3fARB( glGetUniformLocationARB( handle, parameter.c_str() ), x, y, z );

	RETHIS;
}
shader& shader::set_float( string parameter, f32 x, f32 y, f32 z, f32 w )
{
	glUniform4fARB( glGetUniformLocationARB( handle, parameter.c_str() ), x, y, z, w );

	RETHIS;
}
shader& shader::set_floats( string parameter, s32 size, const f32* data, s32 amount )
{
	switch( size )
	{
		case 1:
		{
			glUniform1fvARB( glGetUniformLocationARB( handle, parameter.c_str() ), amount, data );

			break;
		}
		case 2:
		{
			glUniform2fvARB( glGetUniformLocationARB( handle, parameter.c_str() ), amount, data );

			break;
		}
		case 3:
		{
			glUniform3fvARB( glGetUniformLocationARB( handle, parameter.c_str() ), amount, data );

			break;
		}
		case 4:
		{
			glUniform4fvARB( glGetUniformLocationARB( handle, parameter.c_str() ), amount, data );

			break;
		}
	}

	RETHIS;
}

// set color
shader& shader::set_color( string parameter, const color* shader_color )
{
	glUniform4fvARB( glGetUniformLocationARB( handle, parameter.c_str() ), 1, shader_color->get_data() );

	RETHIS;
}

// set texture
shader& shader::set_texture( string parameter, s32 index, const image* shader_image )
{
	s32 location = glGetUniformLocationARB( handle, parameter.c_str() );

	glUniform1iARB( location, index );

	glActiveTextureARB( TEXTURE0_ARB + index );

	glBindTexture( TEXTURE_2D, shader_image->get_handle() );

	glActiveTextureARB( TEXTURE0_ARB );

	RETHIS;
}

// set palette
shader& shader::set_palette( const palette* shader_palette )
{
	return set_palette( 1, shader_palette );
}
shader& shader::set_palette( s32 index, const palette* shader_palette )
{
	return set_texture( "palette_texture", index, shader_palette->get_palette_image() );
}

// set swatch
shader& shader::set_swatch( const swatch* shader_swatch )
{
	return set_swatch( 2, shader_swatch, 0 );
}
shader& shader::set_swatch( s32 texture_index, const swatch* shader_swatch )
{
	return set_swatch( texture_index, shader_swatch, 0 );
}
shader& shader::set_swatch( const swatch* shader_swatch, s32 swatch_index )
{
	return set_swatch( 2, shader_swatch, swatch_index );
}
shader& shader::set_swatch( s32 texture_index, const swatch* shader_swatch, s32 swatch_index )
{
	set_texture( "swatch_texture", texture_index, shader_swatch->get_swatch_image() );

	return set_swatch_index( shader_swatch, swatch_index );
}

// set swatch index
shader& shader::set_swatch_index( const swatch* shader_swatch, s32 swatch_index )
{
	return set_float( "swatch_index", f32( swatch_index % shader_swatch->get_height() )
		* 0.0039215686274509803921568627451f );
}

/* end */

}
}

#endif
