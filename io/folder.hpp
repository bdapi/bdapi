
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_FOLDER_HPP
#define BDAPI_IO_FOLDER_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "vector"

// bdapi
#include "io/path.hpp"
#include "string/string.hpp"
#include "sys/timedata.hpp"
#include "sys/timer.hpp"
#include "util/container.hpp"

/* namespaces */
namespace bdapi {
namespace io    {

/* folder typedef declarations */

typedef util::container< io::path, std::vector > folder_path_container;

/* folder class declaration */

class folder
{

private: // private data

	BD_GET_CONST_REFR( private, io::path, folder_path );

	BD_GET_CONST_REFR( private, folder_path_container, folders );
	BD_GET_CONST_REFR( private, folder_path_container, files   );

	BD_GET_REFR( private, sys::timedata, scan_timedata );
	BD_GET_REFR( private, sys::timer,    scan_timer    );

public: // public initialization functions (io_folder_init.cpp)

	folder () {};
	folder ( io::path folder_path );
	folder ( const folder& copy   );
 ~folder () {};

	result initialize ( io::path folder_path );
	result initialize ( const folder& copy   );

public: // public core functions (io_folder_core.cpp)

	folder& scan ();

	io::path get_folder ( s32 index ) const;
	io::path get_file   ( s32 index ) const;

public: // public query functions (io_folder_query.cpp)

	bl is_empty () const;

	s32 get_folder_amount () const;
	s32 get_file_amount   () const;
	s32 get_all_amount    () const;

	f64 get_scan_time () const;

	string get_scan_time_string () const;


};

/* end */

}
}

#endif
