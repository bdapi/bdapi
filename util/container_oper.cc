
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_CONTAINER_OPER_CC
#define BDAPI_UTIL_CONTAINER_OPER_CC
#include "util/container.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* implementation macro definitions */

#define TMP1 template < typename AA, template< typename, typename > class BB, typename CC >
#define TMP2 template < template< typename, typename > class DD, typename EE >

/* container class operator function implementations */

// operator [] s32
TMP1 AA& container<AA,BB,CC>::operator [] ( s32 i )
{
	return get(i);
}

// operator [] s32 const
TMP1 const AA& container<AA,BB,CC>::operator [] ( s32 i ) const
{
	return get(i);
}

// operator == container
TMP1 TMP2 bl container<AA,BB,CC>::operator == ( const container<AA,DD,EE>& other ) const
{
	if( get_size() != other.get_size() )
	{
		return false;
	}

	fori( get_size() )
	{
		if( get(i) != other.get(i) )
		{
			return false;
		}
	}

	return true;
}

// operator != container
TMP1 TMP2 bl container<AA,BB,CC>::operator != ( const container<AA,DD,EE>& other ) const
{
	return !( *this == other );
}

// operator << element
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::operator << ( const AA& aa )
{
	insert(aa);

	RETHIS;
}

// operator << container
TMP1 TMP2 container<AA,BB,CC>& container<AA,BB,CC>::operator << ( const container<AA,DD,EE>& other )
{
	insert(other);

	RETHIS;
}

// operator , element
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::operator , ( const AA& aa )
{
	insert(aa);

	RETHIS;
}

// operator , container
TMP1 TMP2 container<AA,BB,CC>& container<AA,BB,CC>::operator , ( const container<AA,DD,EE>& other )
{
	insert(other);

	RETHIS;
}

/* implementation macro undefs */

#undef TMP1
#undef TMP2

/* end */

}
}

#endif
