
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_PATH_HPP
#define BDAPI_IO_PATH_HPP
#include "bdapi.hpp"

/* includes */

// boost
#include "boost/filesystem.hpp"

// bdapi
#include "string/string.hpp"

/* namespaces */
namespace bdapi {
namespace io    {

namespace bfs = boost::filesystem;

/* boost filesystem typedef declarations */

typedef bfs::path        bpath;
typedef bfs::file_status bfilestatus;
typedef bfs::perms       bperms;

/* path class declaration */

class path
{

private: // private data

	BD_GET_COPY( private, bpath, boost_path );

public: // public initialization functions (io_path_init.cpp)

	path () {};
	path ( string input     );
	path ( cstr   input     );
	path ( const path& copy );
 ~path () {};

	path& initialize ( string input     );
	path& initialize ( cstr   input     );
	path& initialize ( const path& copy );

public: // public core functions (io_path_core.cpp)

	path branch ( string input ) const;

	result create_folder ( string folder_name ) const;
	result create_folder (                    ) const;
	result create_file   ( string file_name   ) const;
	result create_file   (                    ) const;

	result delete_folder () const;
	result delete_file   () const;

	static string get_current_path ();

private: // private modification functions (io_path_mod.cpp)

	static string fix_string ( string input );

public: // public modification functions (io_path_mod.cpp)

	path& set ( cstr input );

	path& set_parent_path ( string parent_path );
	path& set_stem        ( string stem        );
	path& set_extension   ( string extension   );

	path& clear ();

	path& remove_parent_path ();
	path& remove_stem        ();
	path& remove_extension   ();

public: // public query functions (io_path_query.cpp)

	string get_string () const;

	string get_root_name      () const;
	string get_root_directory () const;
	string get_root_path      () const;
	string get_relative_path  () const;
	string get_parent_path    () const;
	string get_filename       () const;
	string get_stem           () const;
	string get_extension      () const;

	s32 get_length () const;
	s32 get_size   () const;

	bl has_root_name      () const;
	bl has_root_directory () const;
	bl has_root_path      () const;
	bl has_relative_path  () const;
	bl has_parent_path    () const;
	bl has_filename       () const;
	bl has_stem           () const;
	bl has_extension      () const;

	bl exists       () const;
	bl is_directory () const;
	bl is_file      () const;
	bl is_other     () const;
	bl is_unknown   () const;
	bl is_empty     () const;
	bl is_absolute  () const;
	bl is_relative  () const;

private: // private status functions (io_path_status.cpp)

	bfilestatus get_bfilestatus () const;
	bperms      get_bperms      () const;

public: // public status functions (io_path_status.cpp)

	bl has_perms           () const;
	bl has_no_perms        () const;
	bl has_owner_read      () const;
	bl has_owner_write     () const;
	bl has_owner_exe       () const;
	bl has_owner_all       () const;
	bl has_group_read      () const;
	bl has_group_write     () const;
	bl has_group_exe       () const;
	bl has_group_all       () const;
	bl has_others_read     () const;
	bl has_others_write    () const;
	bl has_others_exe      () const;
	bl has_others_all      () const;
	bl has_all_all         () const;
	bl has_set_uid_on_exe  () const;
	bl has_set_gid_on_exe  () const;
	bl has_sticky_bit      () const;
	bl has_perms_mask      () const;
	bl has_perms_not_known () const;
	bl has_add_perms       () const;
	bl has_remove_perms    () const;
	bl has_symlink_perms   () const;

public: // public operator functions (io_path_oper.cpp)

	path& operator = ( cstr input );

	string operator () () const;

	bl operator == ( const path& other );
	bl operator == ( string input      );
	bl operator != ( const path& other );
	bl operator != ( string input      );

};

/* end */

}
}

#endif
