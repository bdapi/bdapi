
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_PATH_INIT_CPP
#define BDAPI_IO_PATH_INIT_CPP
#include "io/path.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace io    {

/* path class initialization function implementations */

// constructors
path::path( string input )
{
	initialize( input );
}
path::path( cstr input )
{
	initialize( string( input ) );
}
path::path( const path& copy )
{
	initialize( copy );
}

// initializers
path& path::initialize( string input )
{
	return set( input.c_str() );
}
path& path::initialize( cstr input )
{
	return set( input );
}
path& path::initialize( const path& copy )
{
	boost_path = copy.boost_path;

	RETHIS;
}

/* end */

}
}

#endif
