
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_HANDLER_HPP
#define BDAPI_AUDIO_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace audio {

/* audio handler enumerator declarations */

enum mode
{
	AUDIO_MODE_MONO   = 1,
	AUDIO_MODE_STEREO = 2
};

/* audio handler parameters struct declaration */

struct parameters
{
	mode output_mode = AUDIO_MODE_STEREO;

	s32 frequency  = 44100;
	s32 chunk_size =  1024;

	s32 input_channels = 8;
};

/* audio handler singleton declaration */

#ifdef  BD_DATA_AUDIO
#define BD_DATA_EXTERN
#endif
#include "core/local_open.hpp"

// initialization data

BD_DATA_GET_COPY_INIT_SET( subsys, subsystem_state, SUBSYS_UNUSED );

BD_DATA_GET_COPY_INIT( parameters*, handler_parameters, NULL );

// descriptor data

BD_DATA_GET_COPY( u16, format );

BD_DATA_GET_COPY( mode, output_mode );

BD_DATA_GET_COPY( s32, frequency       );
BD_DATA_GET_COPY( s32, output_channels );
BD_DATA_GET_COPY( s32, input_channels  );

BD_DATA_GET_COPY( s32, chunk_size );
BD_DATA_GET_COPY( f32, latency    );

// core data

BD_DATA_GET_COPY_INIT( audio::channel*, channels, NULL ); // internal

BD_DATA_GET_COPY( s32, next_channel_internal );

BD_DATA_GET_COPY_INIT(          s32,   post_channel,    0 );
BD_DATA_GET_COPY_INIT( volatile f32*,  post_stream,  NULL );
BD_DATA_GET_COPY_INIT(          s32,   post_length,     0 );
BD_DATA_GET_COPY_INIT( volatile void*, post_params,  NULL );

// initialization functions (audio_handler_init.cpp)

result initialize ( parameters* handler_parameters );
result shutdown   ();

result init_format   ();
result init_sdl      ();
result init_mixer    ();
result init_post     ();
result init_stk      ();
result init_channels ();

// core functions (audio_handler_core.cpp)

void callback_finished ( s32 channel_index                                         );
void callback_postmix  ( s32 channel_index, void* stream, s32 length, void* params );

void mute ();

// query functions (audio_handler_query.cpp)

audio::channel* get_channel ( s32 i );

s32 get_next_channel ();

#include "core/local_close.hpp"

/* audio handling function macro definitions */

#define USING_AUDIO ( audio::get_subsystem_state() != SUBSYS_UNUSED )

/* end */

}
}

#endif
