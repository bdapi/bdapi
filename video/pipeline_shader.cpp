
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_PIPELINE_SHADER_CPP
#define BDAPI_VIDEO_PIPELINE_SHADER_CPP
#include "video/pipeline.hpp"

/* includes */

// bdapi
#include "video/shader.hpp"

// namespaces
namespace bdapi {
namespace video {

/* pipeline class shader function implementations */

// set int
void pipeline::set_int( string parameter, s32 x )
{
	current_shader->set_int( parameter, x );
}
void pipeline::set_int( string parameter, s32 x, s32 y )
{
	current_shader->set_int( parameter, x, y );
}
void pipeline::set_int( string parameter, s32 x, s32 y, s32 z )
{
	current_shader->set_int( parameter, x, y, z );
}
void pipeline::set_int( string parameter, s32 x, s32 y, s32 z, s32 w )
{
	current_shader->set_int( parameter, x, y, z, w );
}
void pipeline::set_ints( string parameter, s32 size, const s32* data, s32 amount )
{
	current_shader->set_ints( parameter, size, data, amount );
}

// set float
void pipeline::set_float( string parameter, f32 x )
{
	current_shader->set_float( parameter, x );
}
void pipeline::set_float( string parameter, f32 x, f32 y )
{
	current_shader->set_float( parameter, x, y );
}
void pipeline::set_float( string parameter, f32 x, f32 y, f32 z )
{
	current_shader->set_float( parameter, x, y, z );
}
void pipeline::set_float( string parameter, f32 x, f32 y, f32 z, f32 w )
{
	current_shader->set_float( parameter, x, y, z, w );
}
void pipeline::set_floats( string parameter, s32 size, const f32* data, s32 amount )
{
	current_shader->set_floats( parameter, size, data, amount );
}

// set color
void pipeline::set_color( string parameter, const color* shader_color )
{
	current_shader->set_color( parameter, shader_color );
}

// set texture
void pipeline::set_texture( string parameter, s32 index, const image* shader_image )
{
	current_shader->set_texture( parameter, index, shader_image );
}

// set palette
void pipeline::set_palette( const palette* shader_palette )
{
	current_shader->set_palette( shader_palette );
}
void pipeline::set_palette( s32 index, const palette* shader_palette )
{
	current_shader->set_palette( index, shader_palette );
}

// set swatch
void pipeline::set_swatch( const swatch* shader_swatch )
{
	current_shader->set_swatch( shader_swatch );
}
void pipeline::set_swatch( s32 texture_index, const swatch* shader_swatch )
{
	current_shader->set_swatch( texture_index, shader_swatch );
}
void pipeline::set_swatch( const swatch* shader_swatch, s32 swatch_index )
{
	current_shader->set_swatch( shader_swatch, swatch_index );
}
void pipeline::set_swatch( s32 texture_index, const swatch* shader_swatch, s32 swatch_index )
{
	current_shader->set_swatch( texture_index, shader_swatch, swatch_index );
}

// set swatch index
void pipeline::set_swatch_index( const swatch* shader_swatch, s32 swatch_index )
{
	current_shader->set_swatch_index( shader_swatch, swatch_index );
}

/* end */

}
}

#endif
