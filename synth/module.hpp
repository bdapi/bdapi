
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_MODULE_HPP
#define BDAPI_SYNTH_MODULE_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "deque"

// bdapi
#include "audio/synth.hpp"
#include "synth/voice.hpp"
#include "synth/parameters.hpp"
#include "util/container.hpp"
#include "sys/threading.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer module typedef declarations */

typedef synth::voice module_voices[ BD_SYNTH_VOICES ];

typedef util::container< s32, std::deque > module_s32_deque;

/* synthesizer module class declaration */

class module
{
	// descriptors
	BD_GET_COPY_INIT( private, synth::engine*, parent_engine, NULL );
	BD_GET_COPY_INIT( private, s32,            engine_index,    -1 );
	BD_GET_COPY_INIT( private, s32,            module_index,    -1 );

	// parameters
	BD_GET_REFR( private, synth::module_parameters, params );

	// outputs
	BD_GET_COPY_INIT( private, audio::raw*, module_output, NULL );

	// threading
	BD_GET_COPY_INIT( private, boost::mutex*, module_mutex, NULL );

	// voices
	BD_GET_REFR(      private, module_voices,    voices              );
	BD_GET_REFR(      private, module_s32_deque, voice_indices       );
	BD_GET_COPY_INIT( private, s32,              last_voice_index, 0 );

public: // public initialization functions (synth_module_init.cpp)

	module () {};
 ~module ();

	result initialize ( synth::engine* parent_engine, s32 engine_index, s32 module_index );

public: // public core functions (synth_module_core.cpp)

	void key_on  ( s32 note, f32 velocity               );
	void key_on  ( s32 note, f32 velocity, f32 duration );
	void key_off (                                      );
	void key_off ( s32 i                                );

public: // public iteration functions (synth_module_iterate.cpp)

	audio::raw& run ();

public: // public modification functions (synth_module_mod.cpp)

	void set_parameters ( const synth::module_parameters& params );

	void apply_parameters (                                        );
	void apply_parameters ( const synth::module_parameters& params );

public: // public query functions (synth_module_query.cpp)

	synth::voice*   get_voice    ( s32 i        );
	synth::voice*   get_voice    (              );
	synth::operate* get_operator ( s32 i, s32 j );
	synth::operate* get_operator (        s32 j );

	synth::module_parameters* get_parameters ();

	s32 get_next ();

};

/* end */

}
}

#endif
