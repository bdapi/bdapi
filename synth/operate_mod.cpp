
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OPERATE_MOD_CPP
#define BDAPI_SYNTH_OPERATE_MOD_CPP
#include "synth/operate.hpp"

/* includes */

// stk
#include "ADSR.h"

// bdapi
#include "math/core.hpp"

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer operator class modification function implementations */

// set parameters
void operate::set_parameters( const synth::operator_parameters& params )
{
	this->params = params;
}

// apply parameters
void operate::apply_parameters()
{
	apply_parameters( params );
}
void operate::apply_parameters( const synth::operator_parameters& params )
{
	set_attack_target( params.attack_target );
	set_attack_time  ( params.attack_time   );
	set_decay_time   ( params.decay_time    );
	set_sustain_level( params.sustain_level );
	set_release_time ( params.release_time  );
}

// set attack target
void operate::set_attack_target( f32 target )
{
	target = math::clamp<f32>( 0.f, target, 1.f );

	adsr->setAttackTarget( target );
}

// set attack time
void operate::set_attack_time( f32 time )
{
	if( time < 0.f )
	{
		time = 0.f;
	}

	adsr->setAttackTime( time );
}

// set decay time
void operate::set_decay_time( f32 time )
{
	if( time < 0.f )
	{
		time = 0.f;
	}

	adsr->setDecayTime( time );
}

// set sustain level
void operate::set_sustain_level( f32 level )
{
	level = math::clamp<f32>( 0.f, level, 1.f );

	adsr->setSustainLevel( level );
}

// set release time
void operate::set_release_time( f32 time )
{
	if( time < 0.f )
	{
		time = 0.f;
	}

	adsr->setReleaseTime( time );
}

/* end */

}
}

#endif
