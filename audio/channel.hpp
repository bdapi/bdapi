
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_CHANNEL_HPP
#define BDAPI_AUDIO_CHANNEL_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "audio/raw.hpp"
#include "synth/engine.hpp"
#include "synth/parameters.hpp"

/* third party forward declarations */

// sdl mixer
struct Mix_Chunk;

// namespaces
namespace bdapi {
namespace audio {

/* audio channel class declaration */

class channel
{

private: // private descriptor data

	BD_GET_COPY_INIT( private, s32, channel_index, -1 );

	BD_GET_COPY_INIT_SET( private, f32, volume, 0.25f );

private: // private core data

	BD_GET_COPY_INIT( private, Mix_Chunk*, previous, NULL ); // internal
	BD_GET_COPY_INIT( private, Mix_Chunk*, current,  NULL ); // internal
	BD_GET_COPY_INIT( private, Mix_Chunk*, next,     NULL ); // internal

	BD_GET_REFR( private, audio::raw, channel_output_pre  );
	BD_GET_REFR( private, audio::raw, channel_output_post );

	BD_GET_PNTR( private, synth::engine, synthesizer );

private: // private filter data

	BD_GET_COPY_INIT( private, audio::echo*,   channel_echo,   NULL ); // internal
	BD_GET_COPY_INIT( private, audio::reverb*, channel_reverb, NULL ); // internal

	BD_IS_COPY_INIT_SET( private, bl, using_echo,   false );
	BD_IS_COPY_INIT_SET( private, bl, using_reverb, false );

public: // public initialization functions (audio_channel_init.cpp)

	channel () {};
 ~channel ();

	result initialize ( s32 channel_index );

public: // public core functions (audio_channel_core.cpp)

	f32 iterate ( f32 input, s32 output_channel );

	void fill ();
	void play ();

public: // public modification function (audio_channel_mod.cpp)

	//void set_parameters ( const synth::engine_parameters& params );

public: // public query functions (audio_channel_query.cpp)

	audio::echo*   get_echo   ( s32 i );
	audio::reverb* get_reverb ( s32 i );

	synth::module*  get_module   ( s32 i               );
	synth::voice*   get_voice    ( s32 i, s32 j        );
	synth::voice*   get_voice    ( s32 i               );
	synth::operate* get_operator ( s32 i, s32 j, s32 k );
	synth::operate* get_operator ( s32 i,        s32 k );

	f32* get_engine_output   (                     );
	f32* get_module_output   ( s32 i               );
	f32* get_voice_output    ( s32 i, s32 j        );
	f32* get_voice_output    ( s32 i               );
	f32* get_operator_output ( s32 i, s32 j, s32 k );
	f32* get_operator_output ( s32 i,        s32 k );

	synth::engine_parameters* get_parameters ();

};

/* end */

}
}

#endif
