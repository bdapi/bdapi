
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_REVERB_MOD_CPP
#define BDAPI_AUDIO_REVERB_MOD_CPP
#include "audio/reverb.hpp"

/* includes */

// stk
#include "FreeVerb.h"

// bdapi
#include "math/core.hpp"

// namespaces
namespace bdapi {
namespace audio {

/* audio reverb class modification function implementations */

// set mix
void reverb::set_mix( f32 mix )
{
	this->mix = math::clamp<f32>( 0.f, mix, 1.f );

	freeverb->setEffectMix( this->mix );
}

// set size
void reverb::set_size( f32 size )
{
	this->size = math::clamp<f32>( 0.f, size, 1.f );

	freeverb->setRoomSize( this->size );
}

// set damping
void reverb::set_damping( f32 damping )
{
	this->damping = math::clamp<f32>( 0.f, damping, 1.f );

	freeverb->setDamping( this->damping );
}

// set width
void reverb::set_width( f32 width )
{
	this->width = math::clamp<f32>( 0.f, width, 1.f );

	freeverb->setWidth( this->width );
}

// set all
void reverb::set_all( f32 all )
{
	set_size   ( all );
	set_damping( all );
	set_width  ( all );
}

/* end */

}
}

#endif
