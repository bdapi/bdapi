
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_PATH_CORE_CPP
#define BDAPI_IO_PATH_CORE_CPP
#include "io/path.hpp"

/* includes */

// standard
#include "fstream"

/* namespaces */
namespace bdapi {
namespace io    {

/* path class core function implementations */

// branch
path path::branch( string input ) const
{
	if( has_extension() )
	{
		return get_parent_path() + '/' + input;
	}
	else
	{
		return get_string()      + '/' + input;
	}
}

// create folder
result path::create_folder( string folder_name ) const
{
	return path( branch(folder_name) ).create_folder();
}
result path::create_folder() const
{
	if( exists() )
	{
		return 0;
	}

	if( !bfs::create_directory(boost_path) )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// create file
result path::create_file( string file_name ) const
{
	return path( branch(file_name) ).create_file();
}
result path::create_file() const
{
	if( exists() )
	{
		return 0;
	}

	std::ofstream output;

	output.open( get_string().c_str(), std::ios::binary );

	if( !output.is_open() )
	{
		output.close();

		return 0;
	}

	output.close();

	return 1;
}

// delete folder
result path::delete_folder() const
{
	if( !exists() )
	{
		return 0;
	}

	if( !is_directory() )
	{
		return 0;
	}

	s32 remove_amount = bfs::remove_all(boost_path);

	if( remove_amount <= 0 )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// delete file
result path::delete_file() const
{
	if( !exists() )
	{
		return 0;
	}

	if( !is_file() )
	{
		return 0;
	}

	bl remove_result = bfs::remove(boost_path);

	if( !remove_result )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// static get current path
string path::get_current_path()
{
	return bfs::current_path().generic_string<string>();
}

/* end */

}
}

#endif
