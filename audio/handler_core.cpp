
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_HANDLER_CORE_CPP
#define BDAPI_AUDIO_HANDLER_CORE_CPP
#define BD_DATA_AUDIO
#include "audio/handler.hpp"

/* includes */

// sdl
#include "SDL_mixer.h"

// bdapi
#include "audio/channel.hpp"
#include "math/core.hpp"

/* namespaces */
namespace bdapi {
namespace audio {

/* audio handler singleton core function implementations */

// private callback finished
void callback_finished( s32 channel_index )
{
	if( subsystem_state == SUBSYS_ACTIVE
	||  subsystem_state == SUBSYS_INITIALIZED )
	{
		if( math::within<s32>( channel_index, input_channels ) )
		{
			get_channel( channel_index )->play();
		}
	}
}

// private callback post mix
void callback_postmix( s32 channel_index, void* stream, s32 length, void* params )
{
	post_channel =       channel_index;
	post_stream  = (f32*)stream;
	post_length  =       length;
	post_params  =       params;
}

// mute
void mute()
{
	Mix_Volume( -1, 0 );
}

/* end */

}
}

#endif
