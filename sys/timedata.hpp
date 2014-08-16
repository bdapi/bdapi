
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_TIMEDATA_HPP
#define BDAPI_SYS_TIMEDATA_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "string/string.hpp"

/* namespaces */
namespace bdapi {
namespace sys   {

/* time data class declaration */

class timedata
{

private: // private data

	BD_GET_COPY( private, s32, year   );
	BD_GET_COPY( private, s32, month  );
	BD_GET_COPY( private, s32, day    );
	BD_GET_COPY( private, s32, hour   );
	BD_GET_COPY( private, s32, minute );
	BD_GET_COPY( private, s32, second );

	BD_GET_COPY( private, string, time_string      );
	BD_GET_COPY( private, string, safe_time_string );
	BD_GET_COPY( private, string, date_string      );

public: // public initialization functions (util_timedata_init.cpp)

	timedata ();
	timedata ( const timedata& copy );
 ~timedata () {};

public: // public core functions (util_timedata_core.cpp)

	timedata& update ();

};

/* end */

}
}

#endif
