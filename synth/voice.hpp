
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_VOICE_HPP
#define BDAPI_SYNTH_VOICE_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "audio/synth.hpp"
#include "synth/operate.hpp"
#include "synth/parameters.hpp"
#include "sys/timer.hpp"
#include "sys/threading.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer voice typedef declarations */

typedef synth::operate voice_operators[ BD_SYNTH_OPERATORS ];

/* synthesizer voice class declaration */

class voice
{
	// descriptors
	BD_GET_COPY_INIT( private, synth::engine*, parent_engine, NULL );
	BD_GET_COPY_INIT( private, synth::module*, parent_module, NULL );
	BD_GET_COPY_INIT( private, s32,            engine_index,    -1 );
	BD_GET_COPY_INIT( private, s32,            module_index,    -1 );
	BD_GET_COPY_INIT( private, s32,            voice_index,     -1 );

	// parameters
	BD_GET_REFR( private, synth::module_parameters, params );

	// outputs
	BD_GET_COPY_INIT( private, audio::raw*, voice_output, NULL );

	// threading
	BD_GET_COPY_INIT( private, boost::mutex*, voice_mutex, NULL );

	// operators
	BD_GET_REFR( private, voice_operators, operators );

	// state
	BD_GET_COPY_INIT_SET( private, state,      voice_state, BD_STATE_READY );
	BD_GET_COPY_INIT(     private, f32,        key_off_time,           1.f );
	BD_GET_PNTR(          private, sys::timer, voice_timer                 );

public: // public initialization functions (synth_voice_init.cpp)

	voice () {};
 ~voice ();

	result initialize ( synth::engine* parent_engine, synth::module* parent_module, s32 engine_index,
	                    s32 module_index, s32 voice_index );

public: // public core functions (synth_voice_core.cpp)

	void key_on  ( s32 note, f32 velocity, f32 duration );
	void key_off (                                      );

	void reset ();

public: // public iteration functions (synth_voice_iterate.cpp)

	audio::raw& run (          );
	audio::raw& run ( s32 size );

public: // public modification functions (synth_voice_mod.cpp)

	void set_parameters ( const synth::module_parameters& params );

	void apply_parameters (                                        );
	void apply_parameters ( const synth::module_parameters& params );

public: // public query functions (synth_voice_query.cpp)

	synth::operate* get_operator ( s32 i );

	synth::module_parameters* get_parameters ();

public: // public operator functions (synth_voice_oper.cpp)

	synth::operate* operator [] ( s32 i );

};

/* end */

}
}

#endif
