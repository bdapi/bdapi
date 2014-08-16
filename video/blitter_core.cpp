
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_BLITTER_CORE_CPP
#define BDAPI_VIDEO_BLITTER_CORE_CPP
#include "video/blitter.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"
#include "video/handler.hpp"
#include "video/palette.hpp"
#include "video/shader.hpp"
#include "video/swatch.hpp"

// namespaces
namespace bdapi {
namespace gl    {

/* static blitter shader singleton struct core function implementations */

// start
void blitter::start( const video::palette* blitter_palette, const video::swatch* blitter_swatch )
{
	start( blitter_palette, blitter_swatch, 0 );
}
void blitter::start( const video::palette* blitter_palette, const video::swatch* blitter_swatch,
s32 swatch_index )
{
	if( !is_active() )
	{
		video::get_shader_blitter()->start();
	}

	set_palette( blitter_palette );

	set_swatch( blitter_swatch, swatch_index );
}

// stop
void blitter::stop()
{
	if( is_active() )
	{
		video::get_shader_blitter()->stop();
	}
}

// set palette
void blitter::set_palette( const video::palette* blitter_palette )
{
	if( is_active() )
	{
		video::get_shader_blitter()->set_palette( blitter_palette );
	}
}

// set swatch
void blitter::set_swatch( const video::swatch* blitter_swatch )
{
	set_swatch( blitter_swatch, 0 );
}
void blitter::set_swatch( const video::swatch* blitter_swatch, s32 swatch_index )
{
	if( is_active() )
	{
		video::get_shader_blitter()->set_swatch( blitter_swatch, swatch_index );
	}
}

// set index
void blitter::set_index( const video::swatch* blitter_swatch, s32 swatch_index )
{
	if( is_active() )
	{
		video::get_shader_blitter()->set_swatch_index( blitter_swatch, swatch_index );
	}
}

// is active
bl blitter::is_active()
{
	return video::get_shader_blitter()->is_active();
}

/* end */

}
}

#endif
