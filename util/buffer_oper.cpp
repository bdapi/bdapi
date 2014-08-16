
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_BUFFER_OPER_CPP
#define BDAPI_UTIL_BUFFER_OPER_CPP
#include "util/buffer.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* buffer class operator function implementations */

// operator = s32
s32 buffer::operator = ( s32 i )
{
	index = i;

	return index;
}

// operator += s32
s32 buffer::operator += ( s32 i )
{
	index += i;

	return index;
}

// operator -= s32
s32 buffer::operator -= ( s32 i )
{
	index -= i;

	return index;
}

// operator ++
s32 buffer::operator ++ ()
{
	index++;

	return index;
}

// operator --
s32 buffer::operator -- ()
{
	index--;

	return index;
}

/* end */

}
}

#endif
