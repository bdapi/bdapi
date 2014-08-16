
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_ECHO_HPP
#define BDAPI_AUDIO_ECHO_HPP
#include "bdapi.hpp"

/* includes */

// forward declarations
namespace stk
{
	class Echo;
}

// namespaces
namespace bdapi {
namespace audio {

/* audio echo class declaration */

class echo
{

private: // private core data

	BD_GET_COPY_INIT( private, stk::Echo*, stk_echo, NULL );

private: // private descriptor data

	BD_GET_COPY_INIT( private, f32, mix,   0.25f );
	BD_GET_COPY_INIT( private, f32, delay, 0.25f );

public: // public initialization functions (audio_echo_init.cpp)

	echo () {};
	echo ( f32 mix, f32 delay );
	echo ( const echo& copy   );
 ~echo ();

	result initialize (                    );
	result initialize ( f32 mix, f32 delay );

public: // public core functions (audio_echo_core.cpp)

	f32 iterate ( f32 input );

	void clear ();

public: // public modification functions (audio_echo_mod.cpp)

	void set_mix   ( f32 mix   );
	void set_delay ( f32 delay );
	void set_echos ( f32 echos );

};

/* end */

}
}

#endif
