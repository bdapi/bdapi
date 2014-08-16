
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_SYNTH_HPP
#define BDAPI_AUDIO_SYNTH_HPP
#include "bdapi.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer enumerator declarations */

// generator
enum generator
{
	BD_GENERATOR_SINE,
	BD_GENERATOR_SQUARE,
	BD_GENERATOR_SAW,
	BD_GENERATOR_TRIANGLE,
	BD_GENERATOR_BLIT
};

// state
enum state
{
	BD_STATE_READY,
	BD_STATE_KEY_ON,
	BD_STATE_KEY_OFF,
	BD_STATE_IDLE
};

/* synthesizer macro definitions */

// configuration

#define BD_SYNTH_MODULES   8
#define BD_SYNTH_VOICES    8
#define BD_SYNTH_OPERATORS 4

/* synthesizer function declarations */

// core functions

f32 get_key (             s32 note );
f32 get_key ( s32 octave, s32 note );

/* end */

}
}

#endif
