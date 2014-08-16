
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_CHANNEL_QUERY_CPP
#define BDAPI_AUDIO_CHANNEL_QUERY_CPP
#include "audio/channel.hpp"

/* includes */

// bdapi
#include "audio/echo.hpp"
#include "audio/handler.hpp"
#include "audio/reverb.hpp"

// namespaces
namespace bdapi {
namespace audio {

/* audio channel class query function implementations */

// get echo
audio::echo* channel::get_echo( s32 i )
{
	return &channel_echo[ i % audio::get_output_channels() ];
}

// get reverb
audio::reverb* channel::get_reverb( s32 i )
{
	return &channel_reverb[ i % audio::get_output_channels() ];
}

// get module
synth::module* channel::get_module( s32 i )
{
	return synthesizer.get_module(i);
}

// get voice
synth::voice* channel::get_voice( s32 i, s32 j )
{
	return synthesizer.get_voice( i, j );
}
synth::voice* channel::get_voice( s32 i )
{
	return synthesizer.get_voice(i);
}

// get operator
synth::operate* channel::get_operator( s32 i, s32 j, s32 k )
{
	return synthesizer.get_operator( i, j, k );
}
synth::operate* channel::get_operator( s32 i, s32 k )
{
	return synthesizer.get_operator( i, k );
}

// get engine output
f32* channel::get_engine_output()
{
	return synthesizer.get_engine_output();
}

// get module output
f32* channel::get_module_output( s32 i )
{
	return synthesizer.get_module_output(i);
}

// get voice output
f32* channel::get_voice_output( s32 i, s32 j )
{
	return synthesizer.get_voice_output( i, j );
}
f32* channel::get_voice_output( s32 i )
{
	return synthesizer.get_voice_output(i);
}

// get operator output
f32* channel::get_operator_output( s32 i, s32 j, s32 k )
{
	return synthesizer.get_operator_output( i, j, k );
}
f32* channel::get_operator_output( s32 i, s32 k )
{
	return synthesizer.get_operator_output( i, k );
}

// get parameters
synth::engine_parameters* channel::get_parameters()
{
	return synthesizer.get_parameters();
}

/* end */

}
}

#endif
