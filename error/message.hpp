
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ERROR_MESSAGE_HPP
#define BDAPI_ERROR_MESSAGE_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "string/string.hpp"

/* namespaces */
namespace bdapi {
namespace error {

/* error message class declaration */

class message
{

private: // private data

	BD_IS_COPY( private, bl, fatal );

	BD_GET_COPY( private, f64, stopped_time );

	BD_GET_COPY( private, string, function );
	BD_GET_COPY( private, string, file     );

	BD_GET_COPY( private, s32, line );

	BD_GET_COPY( private, string, input  );
	BD_GET_COPY( private, string, output );

public: // public initialization functions (error_message_init.cpp)

	message () {};
	message (                             string function, string file, s32 line, cstr input, ... );
	message ( bl fatal,                   string function, string file, s32 line, cstr input, ... );
	message (           f64 stopped_time, string function, string file, s32 line, cstr input, ... );
	message ( bl fatal, f64 stopped_time, string function, string file, s32 line, cstr input, ... );
	message ( const message& copy );
 ~message () {};

private: // private initialization functions (error_message_init.cpp)

	message& initialize ( bl fatal, f64 stopped_time, string function, string file, s32 line,
		string input );

public: // public core functions (error_message_core.cpp)

	string operator () ();

	cstr c_str ();
};

/* end */

}
}

#endif
