
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_PATH_MOD_CPP
#define BDAPI_IO_PATH_MOD_CPP
#include "io/path.hpp"

/* includes */

// bdapi
#include "string/core.hpp"

/* namespaces */
namespace bdapi {
namespace io    {

/* path class modification function implementations */

// private static fix string
string path::fix_string( string input )
{
	input = str::replace( input, "\\", "/" );

	if( input.front() == '/' )
	{
		input.erase( 0, 1 );
	}

	if( input.back() == '/' )
	{
		input.pop_back();
	}

	return input;
}

// set path
path& path::set( cstr input )
{
	boost_path = fix_string( input );

	RETHIS;
}

// set parent path
path& path::set_parent_path( string parent_path )
{
	return set( string( fix_string( parent_path ) + '/' + get_stem() + '.' + get_extension() ).c_str() );
}

// set stem
path& path::set_stem( string stem )
{
	return set( string( get_parent_path() + '/' + stem + '.' + get_extension() ).c_str() );
}

// set extension
path& path::set_extension( string extension )
{
	boost_path.replace_extension( fix_string( extension ) );

	RETHIS;
}

// clear
path& path::clear()
{
	boost_path.clear();

	RETHIS;
}

// remove parent path
path& path::remove_parent_path()
{
	if( has_extension() )
	{
		return set( string( get_stem() + '.' + get_extension() ).c_str() );
	}
	else
	{
		return set( string( get_stem() ).c_str() );
	}
}

// remove stem
path& path::remove_stem()
{
	return set( string( get_parent_path() ).c_str() );
}

// remove extension
path& path::remove_extension()
{
	return set_extension( "" );
}

/* end */

}
}

#endif
