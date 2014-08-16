
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_PATH_OPER_CPP
#define BDAPI_IO_PATH_OPER_CPP
#include "io/path.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace io    {

/* path class operator function implementations */

// operator = string
path& path::operator = ( cstr input )
{
	set( input );

	RETHIS;
}

// operator ()
string path::operator () () const
{
	return get_string();
}

// operator == path
bl path::operator == ( const path& other )
{
	return boost_path == other.boost_path;
}

// operator == string
bl path::operator == ( string input )
{
	return boost_path == input;
}

// operator != path
bl path::operator != ( const path& other )
{
	return boost_path != other.boost_path;
}

// operator != string
bl path::operator != ( string input )
{
	return boost_path != input;
}

/* end */

}
}

#endif
