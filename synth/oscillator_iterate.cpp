
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OSCILLATOR_ITERATE_CPP
#define BDAPI_SYNTH_OSCILLATOR_ITERATE_CPP
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

/* synthesizer oscillator class iteration function implementations */

// iterate
f32 oscillator::iterate()
{
	return iterate( 0.f );
}
f32 oscillator::iterate( f32 modulation )
{
	BD_MUTEX( oscillator_mutex );

	/*
	switch( params.source )
	{
		case BD_GENERATOR_SINE:
		{
			*/

			sine->setFrequency( params.frequency * pow( 2.f, modulation ) );

			return sine->tick() * params.volume;

			/*
		}
		case BD_GENERATOR_SQUARE:
		{
			square->setFrequency( params.frequency * pow( 2.f, modulation ) );

			return square->tick() * params.volume;
		}
		case BD_GENERATOR_SAW:
		{
			saw->setFrequency( params.frequency * pow( 2.f, modulation ) );

			return saw->tick() * params.volume;
		}
		case BD_GENERATOR_BLIT:
		{
			blit->setFrequency( params.frequency * pow( 2.f, modulation ) );

			return blit->tick() * params.volume;
		}
	}
	*/
}

/* end */

}
}

#endif
