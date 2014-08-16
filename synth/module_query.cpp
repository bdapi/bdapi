
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_MODULE_QUERY_CPP
#define BDAPI_SYNTH_MODULE_QUERY_CPP
#include "synth/module.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer module class query function implementations */

// get voice
synth::voice* module::get_voice( s32 i )
{
	return &voices[ i % BD_SYNTH_VOICES ];
}
synth::voice* module::get_voice()
{
	return &voices[ last_voice_index ];
}

// get operator
synth::operate* module::get_operator( s32 i, s32 j )
{
	return get_voice(i)->get_operator(j);
}
synth::operate* module::get_operator( s32 j )
{
	return get_voice()->get_operator(j);
}

// get parameters
synth::module_parameters* module::get_parameters()
{
	return &params;
}

// get next available voice
s32 module::get_next()
{
	if( voice_indices.get_size() < BD_SYNTH_VOICES )
	{
		fori( BD_SYNTH_VOICES )
		{
			if( voices[i].get_voice_state() == BD_STATE_READY )
			{
				return i;
			}
		}
	}

	return -1;
}

/* end */

}
}

#endif
