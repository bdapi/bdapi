
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_HANDLER_QUERY_CPP
#define BDAPI_AUDIO_HANDLER_QUERY_CPP
#define BD_DATA_AUDIO
#include "audio/handler.hpp"

/* includes */

// bdapi
#include "audio/channel.hpp"
#include "math/core.hpp"

/* namespaces */
namespace bdapi {
namespace audio {

/* audio handler singleton query function implementations */

// get channel
audio::channel* get_channel( s32 i )
{
	if( math::within<s32>( i, input_channels ) )
	{
		return &channels[i];
	}
	else
	{
		RENULL;
	}
}

// get next channel_index
s32 get_next_channel()
{
	next_channel_internal++;

	if( next_channel_internal >= input_channels )
	{
		next_channel_internal = 0;
	}

	return next_channel_internal;
}

/* end */

}
}

#endif
