
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_FOLDER_CORE_CPP
#define BDAPI_IO_FOLDER_CORE_CPP
#include "io/folder.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace io    {

/* folder class core function implementations */

// scan
folder& folder::scan()
{
	scan_timer.start();

	scan_timedata.update();

	folders.clear();
	files.clear();

	util::container< bpath, std::vector > bpaths;

	std::copy( bfs::directory_iterator( folder_path.get_boost_path() ), bfs::directory_iterator(),
		back_inserter( bpaths.data ) );

	std::sort( bpaths.data.begin(), bpaths.data.end() );

	util::container< io::path, std::vector > paths;

	for_i(bpaths)
	{
		paths.insert( i->generic_string<string>() );
	}

	for_i(paths)
	{
		if( i->exists() )
		{
			if( i->is_directory() )
			{
				folders.insert(*i);
			}
			else if( i->is_file() )
			{
				files.insert(*i);
			}
		}
	}

	scan_timer.stop();

	RETHIS;
}

// get folder
io::path folder::get_folder( s32 index ) const
{
	return folders[index];
}

// get file
io::path folder::get_file( s32 index ) const
{
	return files[index];
}

/* end */

}
}

#endif
