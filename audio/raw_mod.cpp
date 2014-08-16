
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_RAW_MOD_CPP
#define BDAPI_AUDIO_RAW_MOD_CPP
#include "audio/raw.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace audio {

/* audio raw data class modification function implementations */

// set
f32& raw::set( s32 i, f32 d )
{
	return get(i) = d;
}
f32& raw::set( s32 c, s32 i, f32 d )
{
	return get( c, i ) = d;
}

/* end */

}
}

#endif
