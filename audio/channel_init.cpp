
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_CHANNEL_INIT_CPP
#define BDAPI_AUDIO_CHANNEL_INIT_CPP
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

/* audio channel class initialization function implementations */

// destructor
channel::~channel()
{
	if( channel_index >= 0 )
	{
		Mix_FreeChunk( current );
	}

	delete[] channel_reverb;
	delete[] channel_echo;
}

// initializers
result channel::initialize( s32 channel_index )
{
	this->channel_index = channel_index;

	channel_output_pre.initialize(  audio::get_chunk_size(), 1                            );
	channel_output_post.initialize( audio::get_chunk_size(), audio::get_output_channels() );

	if( !synthesizer.initialize( this, this->channel_index ) )
	{
		return 0;
	}

	channel_echo   = new audio::echo  [ audio::get_output_channels() ]();
	channel_reverb = new audio::reverb[ audio::get_output_channels() ]();

	fori( audio::get_output_channels() )
	{
		get_echo  (i)->initialize();
		get_reverb(i)->initialize();
	}

	fill();

	play();

	return 1;
}

/* end */

}
}

#endif
