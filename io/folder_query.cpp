
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_FOLDER_QUERY_CPP
#define BDAPI_IO_FOLDER_QUERY_CPP
#include "io/folder.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace io    {

/* folder class query function implementations */

// is empty
bl folder::is_empty() const
{
	if( folders.is_empty() && files.is_empty() )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// get folder amount
s32 folder::get_folder_amount() const
{
	return folders.get_size();
}

// get file amount
s32 folder::get_file_amount() const
{
	return files.get_size();
}

// get all amount
s32 folder::get_all_amount() const
{
	return get_folder_amount() + get_file_amount();
}

// get scan time
f64 folder::get_scan_time() const
{
	return scan_timer.get_stopped();
}

// get scan time string
string folder::get_scan_time_string() const
{
	return scan_timer.get_stopped_string();
}

/* end */

}
}

#endif
