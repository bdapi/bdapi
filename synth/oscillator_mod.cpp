
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OSCILLATOR_MOD_CPP
#define BDAPI_SYNTH_OSCILLATOR_MOD_CPP
#include "synth/oscillator.hpp"

/* includes */

// stk
//#include "Blit.h"
//#include "BlitSaw.h"
//#include "BlitSquare.h"
#include "SineWave.h"

// bdapi
#include "math/core.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer oscillator class modification function implementations */

// set parameters
void oscillator::set_parameters( const synth::oscillator_parameters& params )
{
	this->params = params;
}

// apply parameters
void oscillator::apply_parameters()
{
	apply_parameters( params );
}
void oscillator::apply_parameters( const synth::oscillator_parameters& params )
{
	//set_harmonics( params.harmonics );
	//set_phase    ( params.phase     );
}

// set volume
void oscillator::set_volume( f32 volume )
{
	params.volume = math::clamp<f32>( 0.f, volume, 1.f );
}

// set frequency
void oscillator::set_frequency( f32 frequency )
{
	if( frequency > 0.f )
	{
		params.frequency = frequency;
	}
}

/*
// set harmonics
void oscillator::set_harmonics()
{
	switch( params.source )
	{
		case BD_GENERATOR_SQUARE: square->setHarmonics( params.harmonics ); break;
		case BD_GENERATOR_SAW:       saw->setHarmonics( params.harmonics ); break;
		case BD_GENERATOR_BLIT:     blit->setHarmonics( params.harmonics ); break;
	}
}
void oscillator::set_harmonics( s32 harmonics )
{
	if( harmonics < 0 )
	{
		return;
	}

	params.harmonics = harmonics;

	set_harmonics();
}

// set phase
void oscillator::set_phase()
{
	switch( params.source )
	{
		case BD_GENERATOR_SQUARE: square->setPhase( params.phase ); break;
		case BD_GENERATOR_BLIT:     blit->setPhase( params.phase ); break;
	}
}
void oscillator::set_phase( f32 phase )
{
	params.phase = phase;

	set_phase();
}
*/

/* end */

}
}

#endif
