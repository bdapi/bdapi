
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_ECHO_MOD_CPP
#define BDAPI_AUDIO_ECHO_MOD_CPP
#include "audio/echo.hpp"

/* includes */

// stk
#include "Echo.h"

// bdapi
#include "audio/handler.hpp"
#include "math/core.hpp"

// namespaces
namespace bdapi {
namespace audio {

/* audio echo class modification function implementations */

// set mix
void echo::set_mix( f32 mix )
{
	this->mix = math::clamp<f32>( 0.f, mix, 1.f );

	stk_echo->setEffectMix( this->mix );
}

// set delay
void echo::set_delay( f32 delay )
{
	this->delay = math::clamp<f32>( 0.001f, delay, 1.f );

	stk_echo->setDelay( ceil( this->delay * audio::get_frequency() ) );
}

// set echos
void echo::set_echos( f32 echos )
{
	if( echos < 1.f )
	{
		echos = 1.f;
	}

	set_delay( 1.f / echos );
}

/* end */

}
}

#endif
