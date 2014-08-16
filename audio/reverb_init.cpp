
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_REVERB_INIT_CPP
#define BDAPI_AUDIO_REVERB_INIT_CPP
#include "audio/reverb.hpp"

/* includes */

// stk
#include "FreeVerb.h"

// namespaces
namespace bdapi {
namespace audio {

/* audio reverb class initialization function implementations */

// constructors
reverb::reverb( f32 mix, f32 size, f32 damping, f32 width )
{
	initialize( mix, size, damping, width );
}
reverb::reverb( const reverb& copy )
{
	freeverb = new stk::FreeVerb( *copy.freeverb );

	mix     = copy.mix;
	size    = copy.size;
	damping = copy.damping;
	width   = copy.width;
}

// destructor
reverb::~reverb()
{
	delete freeverb;
}

// initializers
result reverb::initialize()
{
	return initialize( mix, size, damping, width );
}
result reverb::initialize( f32 mix, f32 size, f32 damping, f32 width )
{
	freeverb = new stk::FreeVerb();

	set_mix    ( mix     );
	set_size   ( size    );
	set_damping( damping );
	set_width  ( width   );

	return 1;
}

/* end */

}
}

#endif
