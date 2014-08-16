
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_BUFFER_INIT_CPP
#define BDAPI_UTIL_BUFFER_INIT_CPP
#include "util/buffer.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* buffer class initialization function implementations */

// constructors
buffer::buffer( const buffer& copy ) : buffer_u8_vector( static_cast< const buffer_u8_vector& >( copy ) )
{
	initialize( copy );
}

// initializers
buffer& buffer::initialize( const buffer& copy )
{
	data = copy.data;

	index = copy.index;

	RETHIS;
}

/* end */

}
}

#endif
