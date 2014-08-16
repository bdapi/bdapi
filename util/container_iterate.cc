
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_CONTAINER_ITERATE_CC
#define BDAPI_UTIL_CONTAINER_ITERATE_CC
#include "util/container.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* implementation macro definitions */

#define TMP template < typename AA, template< typename, typename > class BB, typename CC >

/* container class iterator function implementations */

// get begin iterator
TMP typename container<AA,BB,CC>::itr container<AA,BB,CC>::get_begin()
{
	return data.begin();
}
TMP typename container<AA,BB,CC>::itr container<AA,BB,CC>::get_begin( s32 i )
{
	return data.begin() + i % get_size();
}

// get end iterator
TMP typename container<AA,BB,CC>::itr container<AA,BB,CC>::get_end()
{
	return data.end();
}
TMP typename container<AA,BB,CC>::itr container<AA,BB,CC>::get_end( s32 i )
{
	return data.end() - i % get_size();
}

// get const begin iterator
TMP typename container<AA,BB,CC>::c_itr container<AA,BB,CC>::get_cbegin() const
{
	return data.begin();
}
TMP typename container<AA,BB,CC>::c_itr container<AA,BB,CC>::get_cbegin( s32 i ) const
{
	return data.begin() + i % get_size();
}

// get const end iterator
TMP typename container<AA,BB,CC>::c_itr container<AA,BB,CC>::get_cend() const
{
	return data.end();
}
TMP typename container<AA,BB,CC>::c_itr container<AA,BB,CC>::get_cend( s32 i ) const
{
	return data.end() - i % get_size();
}

// get reverse begin iterator
TMP typename container<AA,BB,CC>::r_itr container<AA,BB,CC>::get_rbegin()
{
	return data.rbegin();
}
TMP typename container<AA,BB,CC>::r_itr container<AA,BB,CC>::get_rbegin( s32 i )
{
	return data.rbegin() + i % get_size();
}

// get reverse end iterator
TMP typename container<AA,BB,CC>::r_itr container<AA,BB,CC>::get_rend()
{
	return data.rend();
}
TMP typename container<AA,BB,CC>::r_itr container<AA,BB,CC>::get_rend( s32 i )
{
	return data.rend() - i % get_size();
}

/* implementation macro undefs */

#undef TMP

/* end */

}
}

#endif
