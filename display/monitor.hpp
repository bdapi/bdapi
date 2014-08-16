
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_DISPLAY_MONITOR_HPP
#define BDAPI_DISPLAY_MONITOR_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "vector"

// bdapi
#include "display/mode.hpp"
#include "util/container.hpp"

/* namespaces */
namespace bdapi   {
namespace display {

/* monitor typedef declarations */

typedef util::container< mode, std::vector > display_mode_vector;

/* monitor class declaration */

class monitor
{

private: // private data

	BD_GET_COPY_INIT( private, s32, display_index, -1 );

	BD_GET_COPY( private, s32, mode_amount );

	BD_GET_REFR( private, display_mode_vector, modes );

	BD_GET_COPY( private, mode*, desktop_mode );
	BD_GET_COPY( private, mode*, current_mode );

public: // public initialization functions (display_monitor_init.cpp)

	monitor () {};
	monitor ( s32 display_index   );
	monitor ( const monitor& copy );
 ~monitor () {};

	result initialize ( s32 display_index );

};

/* end */

}
}

#endif
