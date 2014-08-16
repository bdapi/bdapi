
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_REVERB_HPP
#define BDAPI_AUDIO_REVERB_HPP
#include "bdapi.hpp"

/* includes */

// forward declarations
namespace stk
{
	class FreeVerb;
}

// namespaces
namespace bdapi {
namespace audio {

/* audio reverb class declaration */

class reverb
{

private: // private core data

	BD_GET_COPY_INIT( private, stk::FreeVerb*, freeverb, NULL );

private: // private descriptor data

	BD_GET_COPY_INIT( private, f32, mix,     0.50f );
	BD_GET_COPY_INIT( private, f32, size,    0.50f );
	BD_GET_COPY_INIT( private, f32, damping, 0.50f );
	BD_GET_COPY_INIT( private, f32, width,   0.50f );

public: // public initialization functions (audio_reverb_init.cpp)

	reverb () {};
	reverb ( f32 mix, f32 size, f32 damping, f32 width );
	reverb ( const reverb& copy                        );
 ~reverb ();

	result initialize (                                           );
	result initialize ( f32 mix, f32 size, f32 damping, f32 width );

public: // public core functions (audio_reverb_core.cpp)

	f32 iterate ( f32 input );

	void clear ();

public: // public modification functions (audio_reverb_mod.cpp)

	void set_mix     ( f32 mix     );
	void set_size    ( f32 size    );
	void set_damping ( f32 damping );
	void set_width   ( f32 width   );
	void set_all     ( f32 all     );

};

/* end */

}
}

#endif
