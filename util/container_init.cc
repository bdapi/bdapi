
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_CONTAINER_INIT_CC
#define BDAPI_UTIL_CONTAINER_INIT_CC
#include "util/container.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* implementation macro definitions */

#define TMP1 template < typename AA, template< typename, typename > class BB, typename CC >
#define TMP2 template < template< typename, typename > class DD, typename EE >

/* container class initialization function implementations */

// constructors
TMP1 container<AA,BB,CC>::container( s32 size )
{
	initialize( size );
}
TMP1 container<AA,BB,CC>::container( s32 size, const AA& aa )
{
	initialize( size, aa );
}
TMP1 container<AA,BB,CC>::container( AA* aa, s32 size )
{
	initialize( aa, size );
}
TMP1 TMP2 container<AA,BB,CC>::container( const container<AA,DD,EE>& copy )
{
	initialize(copy);
}

// initializers
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::initialize( s32 size )
{
	data.assign( size, AA() );

	RETHIS;
}
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::initialize( s32 size, const AA& aa )
{
	data.assign( size, aa );

	RETHIS;
}
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::initialize( AA* aa, s32 size )
{
	clear();

	return copy_from( aa, size );
}
TMP1 TMP2 container<AA,BB,CC>& container<AA,BB,CC>::initialize( const container<AA,DD,EE>& copy )
{
	clear();

	insert( copy );

	RETHIS;
}

/* implementation macro undefs */

#undef TMP1
#undef TMP2

/* end */

}
}

#endif
