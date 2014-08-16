
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_PATH_QUERY_CPP
#define BDAPI_IO_PATH_QUERY_CPP
#include "io/path.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace io    {

/* path class query function implementations */

// get string
string path::get_string() const
{
	return boost_path.generic_string<string>();
}

// get root name
string path::get_root_name() const
{
	return boost_path.root_name().generic_string<string>();
}

// get root directory
string path::get_root_directory() const
{
	return boost_path.root_directory().generic_string<string>();
}

// get root path
string path::get_root_path() const
{
	return boost_path.root_path().generic_string<string>();
}

// get relative path
string path::get_relative_path() const
{
	return boost_path.relative_path().generic_string<string>();
}

// get parent path
string path::get_parent_path() const
{
	return boost_path.parent_path().generic_string<string>();
}

// get filename
string path::get_filename() const
{
	return boost_path.filename().generic_string<string>();
}

// get stem
string path::get_stem() const
{
	return boost_path.stem().generic_string<string>();
}

// get extension
string path::get_extension() const
{
	string extension = boost_path.extension().generic_string<string>();

	if( extension.front() == '.' )
	{
		extension.erase( 0, 1 );
	}

	return extension;
}

// get length
s32 path::get_length() const
{
	return get_string().size();
}

// get size
s32 path::get_size() const
{
	if( exists() && is_file() )
	{
		return bfs::file_size(boost_path);
	}
	else
	{
		return -1;
	}
}

// has root name
bl path::has_root_name() const
{
	return boost_path.has_root_name();
}

// has root directory
bl path::has_root_directory() const
{
	return boost_path.has_root_directory();
}

// has root path
bl path::has_root_path() const
{
	return boost_path.has_root_path();
}

// has relative path
bl path::has_relative_path() const
{
	return boost_path.has_relative_path();
}

// has parent path
bl path::has_parent_path() const
{
	return boost_path.has_parent_path();
}

// has filename
bl path::has_filename() const
{
	return boost_path.has_filename();
}

// has stem
bl path::has_stem() const
{
	return boost_path.has_stem();
}

// has extension
bl path::has_extension() const
{
	return boost_path.has_extension();
}

// does path exist
bl path::exists() const
{
	return bfs::exists(boost_path);
}

// is directory
bl path::is_directory() const
{
	return bfs::is_directory(boost_path);
}

// is file
bl path::is_file() const
{
	return bfs::is_regular_file(boost_path);
}

// is other
bl path::is_other() const
{
	return !is_directory() && !is_file();
}

// is unknown
bl path::is_unknown() const
{
	return !is_directory() && !is_file();
}

// is empty
bl path::is_empty() const
{
	return boost_path.empty();
}

// is absolute
bl path::is_absolute() const
{
	return boost_path.empty();
}

// is relative
bl path::is_relative() const
{
	return boost_path.is_relative();
}

/* end */

}
}

#endif
