
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_BUFFER_CPP
#define BDAPI_AUDIO_BUFFER_CPP
#include "ymx/audio_buffer.hpp"

/* includes */

// bdapi
#include "audio/handler.hpp"

// namespaces
namespace bdapi {
namespace audio {



/* audio buffer class implementation ********************************************************************/



// private nullify

void buffer::__nullify()
{
	sdl_chunk_previous = NULL;
	sdl_chunk_current  = NULL;
	sdl_chunk_next     = NULL;

	s32_samples = 0;

	s32_channel = -1;
}



// constructors

buffer::buffer()
{
	__nullify();
}
buffer::buffer( s32 _s32_samples )
{
	__nullify();

	initialize( _s32_samples );
}

// destructor

buffer::~buffer()
{
	discard();
}



// initialize

result buffer::initialize( s32 _s32_samples )
{
	s32_samples = _s32_samples;

	return 1;
}

// discard

result buffer::discard()
{
	if( s32_channel >= 0 )
		Mix_HaltChannel( s32_channel );

	return 1;
}



// fill

s16* buffer::fill()
{
	if( sdl_chunk_next )
		Mix_FreeChunk( sdl_chunk_next );

	sdl_chunk_next = new Mix_Chunk();

	s16* data = new s16[ s32_samples * 2 ]();

	sdl_chunk_next->allocated = 1;
	sdl_chunk_next->abuf      = (u8*)data;
	sdl_chunk_next->alen      = s32_samples * 2 * sizeof(s16);
	sdl_chunk_next->volume    = 255;

	return data;
}



// play

result buffer::play( s32 _s32_channel )
{
	sdl_chunk_previous = sdl_chunk_current;
	sdl_chunk_current  = sdl_chunk_next;

	Mix_PlayChannel( _s32_channel, sdl_chunk_current, 0 );

	if( sdl_chunk_previous )
		Mix_FreeChunk( sdl_chunk_previous );

	sdl_chunk_next = NULL;

	return 1;
}



/* end */
}}
#endif
