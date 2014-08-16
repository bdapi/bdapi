
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_FOLDER_INIT_CPP
#define BDAPI_IO_FOLDER_INIT_CPP
#include "io/folder.hpp"

/* includes */

// boost
#include "boost/filesystem.hpp"

/* namespaces */
namespace bdapi {
namespace io    {

/* folder class initialization function implementations */

// constructors
folder::folder( io::path folder_path )
{
	initialize(folder_path);
}
folder::folder( const folder& copy )
{
	initialize(copy);
}

// initializers
result folder::initialize( io::path folder_path )
{
	if( !folder_path.exists() || !folder_path.is_directory() )
	{
		return 0;
	}

	this->folder_path = folder_path;

	scan();

	return 1;
}
result folder::initialize( const folder& copy )
{
	folder_path = copy.folder_path;

	folders = copy.folders;
	files   = copy.files;

	scan_timedata = copy.scan_timedata;
	scan_timer     = copy.scan_timer;

	return 1;
}

/* end */

}
}

#endif
