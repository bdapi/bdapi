
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_FILE_INIT_CPP
#define BDAPI_IO_FILE_INIT_CPP
#include "io/file.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace io    {

/* file class initialization function implementations */

// constructors
file::file( io::path file_path )
{
	initialize( file_path );
}
file::file( const file& copy )
{
	initialize( copy );
}

// initializers
file& file::initialize( io::path file_path )
{
	this->file_path = file_path;

	file_buffer.clear();

	RETHIS;
}
file& file::initialize( const file& copy )
{
	file_path = copy.file_path;

	file_buffer = copy.file_buffer;

	RETHIS;
}

/* end */

}
}

#endif
