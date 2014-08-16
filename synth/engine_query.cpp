
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_ENGINE_QUERY_CPP
#define BDAPI_SYNTH_ENGINE_QUERY_CPP
#include "synth/engine.hpp"

/* includes */

// bdapi
#include "audio/handler.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer engine class query function implementations */

// get module
synth::module* engine::get_module( s32 i )
{
	return &modules[ i % BD_SYNTH_MODULES ];
}

// get voice
synth::voice* engine::get_voice( s32 i, s32 j )
{
	return get_module(i)->get_voice(j);
}
synth::voice* engine::get_voice( s32 i )
{
	return get_module(i)->get_voice( get_module(i)->get_last_voice_index() );
}

// get operator
synth::operate* engine::get_operator( s32 i, s32 j, s32 k )
{
	return get_voice( i, j )->get_operator(k);
}
synth::operate* engine::get_operator( s32 i, s32 k )
{
	return get_voice(i)->get_operator(k);
}

// get engine output
f32* engine::get_engine_output()
{
	return engine_outputs.get_data();
}

// get module output
f32* engine::get_module_output( s32 i )
{
	return module_outputs[ i % BD_SYNTH_MODULES ].get_data();
}

// get voice output
f32* engine::get_voice_output( s32 i, s32 j )
{
	return voice_outputs
		[ j % BD_SYNTH_VOICES  ]
		[ i % BD_SYNTH_MODULES ].get_data();
}
f32* engine::get_voice_output( s32 i )
{
	return voice_outputs
		[ get_module(i)->get_last_voice_index() ]
		[ i % BD_SYNTH_MODULES                  ].get_data();
}

// get operator output
f32* engine::get_operator_output( s32 i, s32 j, s32 k )
{
	return operator_outputs
		[ k % BD_SYNTH_OPERATORS ]
		[ j % BD_SYNTH_VOICES    ]
		[ i % BD_SYNTH_MODULES   ].get_data();
}
f32* engine::get_operator_output( s32 i, s32 k )
{
	return operator_outputs
		[ k % BD_SYNTH_OPERATORS                ]
		[ get_module(i)->get_last_voice_index() ]
		[ i % BD_SYNTH_MODULES                  ].get_data();
}

// get parameters
synth::engine_parameters* engine::get_parameters()
{
	return &params;
}

/* end */

}
}

#endif
