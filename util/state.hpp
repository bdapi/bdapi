
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_STATE_HPP
#define BDAPI_UTIL_STATE_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "string/string.hpp"

/* namespaces */
namespace bdapi {
namespace util  {

/* state class declaration */

class state
{

private: // private core data

	result (*function_initialize)();
	result (*function_resume    )();
	result (*function_iterate   )();
	result (*function_suspend   )();
	result (*function_kill      )();

private: // private descriptor data

	BD_GET_COPY( private, string, name );

	BD_IS_COPY( private, bl, initialized );
	BD_IS_COPY( private, bl, active      );

	BD_GET_COPY( private, s64, initialize_count );
	BD_GET_COPY( private, s64, resume_count     );
	BD_GET_COPY( private, s64, iterate_count    );
	BD_GET_COPY( private, s64, suspend_count    );
	BD_GET_COPY( private, s64, kill_count       );


public: // public initialization functions (util_state_init.cpp)

	state () {};
	state ( string name, result(*function_initialize)(), result(*function_resume)(),
	        result(*function_iterate)(), result(*function_suspend)(), result(*function_kill)() );
	state ( const state& copy );
 ~state () {};

	result initialize ( string name, result(*function_initialize)(), result(*function_resume)(),
	                    result(*function_iterate)(), result(*function_suspend)(),
	                    result(*function_kill)() );
	result initialize ( const state& copy );

public: // public core functions (util_state_core.cpp)

	result do_initialize ();
	result do_resume     ();
	result do_iterate    ();
	result do_suspend    ();
	result do_kill       ();

};

/* end */

}
}

#endif
