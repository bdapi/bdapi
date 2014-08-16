
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_CHANNEL_CORE_CPP
#define BDAPI_AUDIO_CHANNEL_CORE_CPP
#include "audio/channel.hpp"

/* includes */

// sdl
#include "SDL_mixer.h"

// bdapi
#include "audio/echo.hpp"
#include "audio/handler.hpp"
#include "audio/reverb.hpp"

// namespaces
namespace bdapi {
namespace audio {

/* audio channel class core function implementations */

// iterate
f32 channel::iterate( f32 input, s32 output_channel )
{
	if( using_echo )
	{
		input = get_echo( output_channel )->iterate( input );
	}

	if( using_reverb )
	{
		input = get_reverb( output_channel )->iterate( input );
	}

	return input * volume;
}

// fill
void channel::fill()
{
	next = new Mix_Chunk();

	f32* data = new f32[ audio::get_chunk_size() * audio::get_output_channels() ]();

	next->allocated = 1;
	next->abuf      = (u8*)data;
	next->alen      = audio::get_chunk_size() * audio::get_output_channels() * sizeof(f32);
	next->volume    = 255;

	channel_output_pre = synthesizer.run();

	fori( audio::get_chunk_size() )
	{
		forj( audio::get_output_channels() )
		{
			data[ i * audio::get_output_channels() + j ] = iterate( channel_output_pre[i], j );
		}
	}

	channel_output_post = data;
}

// play
void channel::play()
{
	previous = current;
	current  = next;

	Mix_PlayChannel( channel_index, current, 0 );

	if( previous )
	{
		Mix_FreeChunk( previous );
	}

	next = NULL;

	fill();
}

/* end */

}
}

#endif
