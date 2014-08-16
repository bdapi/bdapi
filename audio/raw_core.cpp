
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_RAW_CORE_CPP
#define BDAPI_AUDIO_RAW_CORE_CPP
#include "audio/raw.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace audio {

/* audio raw data class core function implementations */

// clear
void raw::clear()
{
	memset( data, 0, size * sizeof(f32) );
}

// copy
f32* raw::copy()
{
	f32* c = new f32[ size ];

	fori( size )
	{
		c[i] = data[i];
	}

	return c;
}

/* end */

}
}

#endif
