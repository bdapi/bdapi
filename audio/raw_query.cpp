
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_RAW_QUERY_CPP
#define BDAPI_AUDIO_RAW_QUERY_CPP
#include "audio/raw.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace audio {

/* audio raw data class query function implementations */

// get
f32& raw::get( s32 i )
{
	return data[ i % size ];
}
f32& raw::get( s32 c, s32 i )
{
	return data[ i * channels % size + c ];
}

/* end */

}
}

#endif
