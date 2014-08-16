
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_FILE_BUFFER_CPP
#define BDAPI_IO_FILE_BUFFER_CPP
#include "io/file.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace io    {

/* file class buffer function implementations */

// reset index
file& file::reset_index()
{
	file_buffer.reset_index();

	RETHIS;
}

// set index
file& file::set_index( s32 i )
{
	file_buffer.set_index(i);

	RETHIS;
}

// shift index
file& file::shift_index( s32 i )
{
	file_buffer.shift_index(i);

	RETHIS;
}

// clear
file& file::clear()
{
	file_buffer.clear();

	RETHIS;
}

// get data
u8* file::get_data()
{
	return file_buffer.get_pointer();
}
u8* file::get_data( bl indexed )
{
	return file_buffer.get_pointer( indexed );
}

// get index
s32 file::get_index() const
{
	return file_buffer.get_index();
}

// get size
s32 file::get_size() const
{
	return file_buffer.get_size();
}

// operator = s32
file& file::operator = ( s32 i )
{
	file_buffer = i;

	RETHIS;
}

// operator += s32
file& file::operator += ( s32 i )
{
	file_buffer += i;

	RETHIS;
}

// operator -= s32
file& file::operator -= ( s32 i )
{
	file_buffer -= i;

	RETHIS;
}

// operator ++
file& file::operator ++ ()
{
	file_buffer += 1;

	RETHIS;
}

// operator --
file& file::operator -- ()
{
	file_buffer -= 1;

	RETHIS;
}

// operator ()
path& file::operator () ()
{
	return get_path();
}

/* end */

}
}

#endif
