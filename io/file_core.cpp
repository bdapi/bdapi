
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_FILE_CORE_CPP
#define BDAPI_IO_FILE_CORE_CPP
#include "io/file.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace io    {

/* file class core function implementations */

// get path
io::path& file::get_path()
{
	return file_path;
}

// private get key
u32 file::get_key() const
{
	u32 key = 0;

	string stem = file_path.get_stem();

	s32 size = stem.size();

	fori( size )
	{
		if( i % 2 )
		{
			key += (u32)stem[i] << ( ( size - i ) % 25 );
		}
		else
		{
			key ^= (u32)stem[i] << (          i   % 17 );
		}
	}

	return key;
}

/* end */

}
}

#endif
