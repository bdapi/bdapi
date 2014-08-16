
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OSCILLATOR_CORE_CPP
#define BDAPI_SYNTH_OSCILLATOR_CORE_CPP
#include "synth/oscillator.hpp"

/* includes */

// stk
//#include "Blit.h"
//#include "BlitSaw.h"
//#include "BlitSquare.h"
#include "SineWave.h"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer oscillator class core function implementations */

// reset
void oscillator::reset()
{
	/*
	switch( params.source )
	{
		case BD_GENERATOR_SINE:   reset_sine();   break;
		case BD_GENERATOR_SQUARE: reset_square(); break;
		case BD_GENERATOR_SAW:    reset_saw();    break;
		case BD_GENERATOR_BLIT:   reset_blit();   break;
	}
	*/

	reset_sine();
	//reset_square();
	//reset_saw();
	//reset_blit();
}

// reset sine
void oscillator::reset_sine()
{
	BD_MUTEX( oscillator_mutex );

	sine->reset();
}

/*
// reset square
void oscillator::reset_square()
{
	BD_MUTEX( oscillator_mutex );

	square->reset();

	set_harmonics();
	set_phase();
}

// reset saw
void oscillator::reset_saw()
{
	BD_MUTEX( oscillator_mutex );

	saw->reset();

	set_harmonics();
}

// reset blit
void oscillator::reset_blit()
{
	BD_MUTEX( oscillator_mutex );

	blit->reset();

	set_harmonics();
	set_phase();
}
*/

/* end */

}
}

#endif
