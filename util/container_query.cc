
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_CONTAINER_QUERY_CC
#define BDAPI_UTIL_CONTAINER_QUERY_CC
#include "util/container.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* implementation macro definitions */

#define TMP template < typename AA, template< typename, typename > class BB, typename CC >

/* container class query function implementations */

// get data
TMP AA* container<AA,BB,CC>::get_data()
{
	return data.data();
}
TMP AA* container<AA,BB,CC>::get_data( s32 i )
{
	return data.data() + i;
}
TMP const AA* container<AA,BB,CC>::get_data() const
{
	return data.data();
}
TMP const AA* container<AA,BB,CC>::get_data( s32 i ) const
{
	return data.data() + i;
}

// get element
TMP AA& container<AA,BB,CC>::get( s32 i )
{
	return get_front(i);
}

// get element at back
TMP AA& container<AA,BB,CC>::get_back()
{
	return data.back();
}
TMP AA& container<AA,BB,CC>::get_back( s32 i )
{
	return data.at( get_size() - 1 - i % get_size() );
}

// get element at front
TMP AA& container<AA,BB,CC>::get_front()
{
	return data.front();
}
TMP AA& container<AA,BB,CC>::get_front( s32 i )
{
	return data.at( i % get_size() );
}

// get const element
TMP const AA& container<AA,BB,CC>::get( s32 i ) const
{
	return data.at( i % get_size() );
}

// get const element at back
TMP const AA& container<AA,BB,CC>::get_back() const
{
	return data.back();
}
TMP const AA& container<AA,BB,CC>::get_back( s32 i ) const
{
	return data.at( get_size() - 1 - i % get_size() );
}

// get const element at front
TMP const AA& container<AA,BB,CC>::get_front() const
{
	return data.front();
}
TMP const AA& container<AA,BB,CC>::get_front( s32 i ) const
{
	return data.at( i % get_size() );
}

// is empty
TMP bl container<AA,BB,CC>::is_empty() const
{
	if( data.empty() )
	{
		return true;
	}

	return false;
}

// is within
TMP bl container<AA,BB,CC>::is_within( s32 i ) const
{
	if( i < 0 || i >= get_size() )
	{
		return false;
	}

	return true;
}

// get elements
TMP s32 container<AA,BB,CC>::get_elements() const
{
	return data.size();
}

// get element size
TMP s32 container<AA,BB,CC>::get_element_size() const
{
	return sizeof(AA);
}

// get size
TMP s32 container<AA,BB,CC>::get_size() const
{
	return data.size();
}
TMP s32 container<AA,BB,CC>::get_size( bl bytes ) const
{
	if( !bytes )
	{
		return get_elements();
	}
	else
	{
		return get_bytes();
	}
}

// get bytes
TMP s32 container<AA,BB,CC>::get_bytes() const
{
	return get_elements() * get_element_size();
}

/* implementation macro undefs */

#undef TMP

/* end */

}
}

#endif
