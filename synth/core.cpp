
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_CORE_CPP
#define BDAPI_SYNTH_CORE_CPP
#include "audio/synth.hpp"

/* includes */

// standard
#include "cmath"

// namespaces
namespace bdapi {
namespace synth {

/* static variable declarations */

static f32 frequency_table[12] =
{
	16.35f, // C
	17.32f, // C#
	18.35f, // D
	19.45f, // D#
	20.60f, // E
	21.83f, // F
	23.12f, // F#
	24.50f, // G
	25.96f, // G#
	27.50f, // A
	29.14f, // A#
	30.87f  // B
};

/* synthesizer core function implementations */

// get key
f32 get_key( s32 note )
{
	if( note < 0 )
	{
		note = 0;
	}

	return get_key( note / 12, note % 12 );
}
f32 get_key( s32 octave, s32 note )
{
	if( octave < 0 )
	{
		octave = 0;
	}

	octave += note / 12;

	note %= 12;

	return frequency_table[ note ] * pow( 2, octave );
}

/* end */

}
}

#endif
