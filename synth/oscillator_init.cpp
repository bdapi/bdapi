
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OSCILLATOR_INIT_CPP
#define BDAPI_SYNTH_OSCILLATOR_INIT_CPP
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

/* synthesizer oscillator class initialization function implementations */

// constructors
oscillator::oscillator()
{
	sine   = new stk::SineWave();
	//square = new stk::BlitSquare();
	//saw    = new stk::BlitSaw();
	//blit   = new stk::Blit();
}

// destructor
oscillator::~oscillator()
{
	DESTRUCT( sine   );
	//DESTRUCT( square );
	//DESTRUCT( saw    );
	//DESTRUCT( blit   );

	DESTRUCT( oscillator_mutex );
}

/* end */

}
}

#endif
