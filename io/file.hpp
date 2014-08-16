
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_FILE_HPP
#define BDAPI_IO_FILE_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "io/path.hpp"
#include "string/string.hpp"
#include "util/buffer.hpp"

/* namespaces */
namespace bdapi {
namespace io    {

/* file class declaration */

class file
{

private: // private data

	BD_GET_REFR_SET( private, io::path, file_path );

	BD_GET_REFR_SET( private, util::buffer, file_buffer );

public: // public initialization functions (io_file_init.cpp)

	file () {};
	file ( io::path file_path );
	file ( const file& copy   );
 ~file () {};

	file& initialize ( io::path file_path );
	file& initialize ( const file& copy   );

public: // public core functions (io_file_core.cpp)

	io::path& get_path ();

private: // private core functions (io_file_core.cpp)

	u32 get_key () const;

public: // public io functions (io_file_io.cpp)

	result read (           );
	result read ( bl bdfile );

	result save (           );
	result save ( bl bdfile );

private: // private io functions (io_file_io.cpp)

	string corruption_error ( s32 code );
	string extension_error  ( s32 code );

public: // public buffer functions (io_file_buffer.cpp)

	file& reset_index (       );
	file& set_index   ( s32 i );
	file& shift_index ( s32 i );

	file& clear ();

	u8* get_data (            );
	u8* get_data ( bl indexed );

	s32 get_index () const;
	s32 get_size  () const;

	file& operator  = ( s32 i );
	file& operator += ( s32 i );
	file& operator -= ( s32 i );
	file& operator ++ (       );
	file& operator -- (       );

	path& operator () ();

public: // public inlined buffer functions

	// in
	template<typename T> file& in ( T i )
	{
		file_buffer.in<T>(i);

		RETHIS;
	};

	// out
	template<typename T> T out ()
	{
		return file_buffer.out<T>();
	};

};

/* end */

}
}

#endif
