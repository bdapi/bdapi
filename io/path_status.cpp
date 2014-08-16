
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_PATH_STATUS_CPP
#define BDAPI_IO_PATH_STATUS_CPP
#include "io/path.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace io    {

/* path class status function implementations */

// private get boost file status
bfilestatus path::get_bfilestatus() const
{
	return bfs::status(boost_path);
}

// private get boost permissions
bperms path::get_bperms() const
{
	return get_bfilestatus().permissions();
}

// has file permissions
bl path::has_perms() const
{
	return !has_no_perms();
}
bl path::has_no_perms() const
{
	return get_bperms() & bperms::no_perms;
}
bl path::has_owner_read() const
{
	return get_bperms() & bperms::owner_read;
}
bl path::has_owner_write() const
{
	return get_bperms() & bperms::owner_write;
}
bl path::has_owner_exe() const
{
	return get_bperms() & bperms::owner_exe;
}
bl path::has_owner_all() const
{
	return get_bperms() & bperms::owner_all;
}
bl path::has_group_read() const
{
	return get_bperms() & bperms::group_read;
}
bl path::has_group_write() const
{
	return get_bperms() & bperms::group_write;
}
bl path::has_group_exe() const
{
	return get_bperms() & bperms::group_exe;
}
bl path::has_group_all() const
{
	return get_bperms() & bperms::group_all;
}
bl path::has_others_read() const
{
	return get_bperms() & bperms::others_read;
}
bl path::has_others_write() const
{
	return get_bperms() & bperms::others_write;
}
bl path::has_others_exe() const
{
	return get_bperms() & bperms::others_exe;
}
bl path::has_others_all() const
{
	return get_bperms() & bperms::others_all;
}
bl path::has_all_all() const
{
	return get_bperms() & bperms::all_all;
}
bl path::has_set_uid_on_exe() const
{
	return get_bperms() & bperms::set_uid_on_exe;
}
bl path::has_set_gid_on_exe() const
{
	return get_bperms() & bperms::set_gid_on_exe;
}
bl path::has_sticky_bit() const
{
	return get_bperms() & bperms::sticky_bit;
}
bl path::has_perms_mask() const
{
	return get_bperms() & bperms::perms_mask;
}
bl path::has_perms_not_known() const
{
	return get_bperms() & bperms::perms_not_known;
}
bl path::has_add_perms() const
{
	return get_bperms() & bperms::add_perms;
}
bl path::has_remove_perms() const
{
	return get_bperms() & bperms::remove_perms;
}
bl path::has_symlink_perms() const
{
	return get_bperms() & bperms::symlink_perms;
}

/* end */

}
}

#endif
