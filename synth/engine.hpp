
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_ENGINE_HPP
#define BDAPI_SYNTH_ENGINE_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "audio/raw.hpp"
#include "audio/synth.hpp"
#include "synth/module.hpp"
#include "synth/parameters.hpp"
#include "sys/threading.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer engine typedef declarations */

typedef audio::raw           engine_raw_output;
typedef engine_raw_output    engine_module_output  [ BD_SYNTH_MODULES   ];
typedef engine_module_output engine_voice_output   [ BD_SYNTH_VOICES    ];
typedef engine_voice_output  engine_operator_output[ BD_SYNTH_OPERATORS ];

typedef synth::module engine_modules[ BD_SYNTH_MODULES ];

/* synthesizer engine class declaration */

class engine
{
	// descriptors
	BD_GET_COPY_INIT( private, audio::channel*, parent_channel, NULL );
	BD_GET_COPY_INIT( private, s32,             engine_index,     -1 );

	// parameters
	BD_GET_REFR( private, synth::engine_parameters, params )

	// outputs
	BD_GET_REFR( private, engine_raw_output,      engine_outputs   );
	BD_GET_REFR( private, engine_module_output,   module_outputs   );
	BD_GET_REFR( private, engine_voice_output,    voice_outputs    );
	BD_GET_REFR( private, engine_operator_output, operator_outputs );

	// threading
	BD_GET_COPY_INIT( private, boost::mutex*, engine_mutex, NULL );

	// modules
	BD_GET_REFR( private, engine_modules, modules );

public: // public initialization functions (synth_engine_init.cpp)

	engine () {};
 ~engine ();

	result initialize ( audio::channel* parent_channel, s32 engine_index );

public: // public iteration function (synth_engine_iterate.cpp)

	audio::raw& run ();

public: // public modification function (synth_engine_mod.cpp)

	void set_parameters ( const synth::engine_parameters& params );

	void apply_parameters (                                        );
	void apply_parameters ( const synth::engine_parameters& params );

public: // public query function (synth_engine_query.cpp)

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
