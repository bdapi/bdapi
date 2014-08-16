
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_HANDLER_INIT_CPP
#define BDAPI_AUDIO_HANDLER_INIT_CPP
#define BD_DATA_AUDIO
#include "audio/handler.hpp"

/* includes */

// sdl
#include "SDL.h"
#include "SDL_mixer.h"

// stk
#include "Stk.h"

// bdapi
#include "audio/channel.hpp"
#include "audio/synth.hpp"
#include "error/handler.hpp"
#include "logging/handler.hpp"
#include "logging/message.hpp"

/* namespaces */
namespace bdapi {
namespace audio {

/* static variables */

static bool handler_instance = false;

/* audio handler singleton initialization function implementations */

// initializers
result initialize( parameters* handler_parameters )
{
	LOG_ERROR_1( "~F6subsystem", "~~ has already been initialized", !handler_instance );

	handler_instance = true;

	LOG_ERROR_1( "~F6subsystem parameters", "failed to read ~~", handler_parameters );

	audio::handler_parameters = handler_parameters;

	subsystem_state = SUBSYS_INITIALIZED;

	LOG_ERROR_3(
		"~FEaudio ~F6format information",
		"reading ~~",
		"~~ analysis complete",
		"failed to read ~~",
		init_format() );

	LOG_ERROR_2(
		"~FESDL ~F6audio subsystem",
		"initializing ~~",
		"failed to initialize ~~",
		init_sdl() );

	LOG_ERROR_2(
		"~FEaudio ~F6mixer",
		"initializing ~~",
		"failed to initialize ~~",
		init_mixer() );

	LOG_ERROR_2(
		"~FEaudio ~F6post processing",
		"initializing ~~",
		"failed to initialize ~~",
		init_post() );

	LOG_ERROR_2(
		"~FESTK ~F6audio subsystem",
		"initializing ~~",
		"failed to initialize ~~",
		init_stk() );

	LOG_ERROR_2(
		"~FEaudio ~F6channels",
		"initializing ~~",
		"failed to initialize ~~",
		init_channels() );

	subsystem_state = SUBSYS_ACTIVE;

	return 1;
}

// shutdown
result shutdown()
{
	subsystem_state = SUBSYS_SUSPENDED;

	Mix_Pause(-1);
	Mix_HaltChannel(-1);
	Mix_UnregisterAllEffects(MIX_CHANNEL_POST);
	Mix_CloseAudio();

	subsystem_state = SUBSYS_SHUTDOWN;

	return 1;
}

// initialize format
result init_format()
{
	format = AUDIO_F32SYS;

	output_mode = handler_parameters->output_mode;

	frequency = handler_parameters->frequency;

	string output_string;

	switch( output_mode )
	{
		case AUDIO_MODE_MONO:
		{
			output_channels = 1;
			output_string   = "Mono";

			break;
		}
		case AUDIO_MODE_STEREO:
		{
			output_channels = 2;
			output_string   = "Stereo";

			break;
		}
		default:
		{
			return 0;
		}
	}

	chunk_size = handler_parameters->chunk_size;

	latency = (f32)chunk_size / (f32)frequency;

	input_channels = handler_parameters->input_channels;

	LOG( "~FCFORMAT~F8:      ~FF%s",      "32-Bit Float"          );
	LOG( "~FCMODE~F8:        ~FF%s",      output_string.c_str()   );
	LOG( "~FCFREQUENCY~F8:   ~FF%i",      frequency               );
	LOG( "~FCCHANNELS~F8:    ~FF%i",      input_channels          );
	LOG( "~FCBUFFER SIZE~F8: ~FF%i",      chunk_size              );
	LOG( "~FCLATENCY~F8:     ~FF%.3f ms", latency * 1000.f        );

	return 1;
}

// initialize sdl audio
result init_sdl()
{
	SDL_ClearError();

	if( SDL_InitSubSystem(SDL_INIT_AUDIO) < 0 )
	{
		WRITE_ERROR( "%s", SDL_GetError() );

		return 0;
	}

	return 1;
}

// initialize sdl mixer
result init_mixer()
{
	SDL_ClearError();

	if( Mix_OpenAudio( frequency, format, output_channels, chunk_size ) < 0 )
	{
		WRITE_ERROR( "%s", Mix_GetError() );

		return 0;
	}

	Mix_AllocateChannels( input_channels );

	Mix_Volume( -1, 128 );

	Mix_ChannelFinished( callback_finished );

	return 1;
}

// initialize post mix
result init_post()
{
	SDL_ClearError();

	if( !Mix_RegisterEffect( MIX_CHANNEL_POST, callback_postmix, NULL, NULL ) )
	{
		WRITE_ERROR( "%s", Mix_GetError() );

		return 0;
	}

	return 1;
}

// initialize stk
result init_stk()
{
	stk::Stk::setSampleRate( (f32)frequency );

	return 1;
}

// initialize channels
result init_channels()
{
	channels = new audio::channel[ input_channels ]();

	fori( input_channels )
	{
		channels[i].initialize(i);
	}

	return 1;
}

/* end */

}
}

#endif
