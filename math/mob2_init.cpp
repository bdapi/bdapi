
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_MOB2_INIT_CPP
#define BDAPI_MATH_MOB2_INIT_CPP
#include "math/mob2.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace math  {

/* 2-dimensional mobile class initialization function implementations */

// constructors
mob2::mob2( f32 x, f32 y )
{
	pos.x = x;
	pos.y = y;
}
mob2::mob2( f32 x, f32 y, f32 a, f32 b )
{
	pos.x = x;
	pos.y = y;

	dir.x = a;
	dir.y = b;
}
mob2::mob2( const glm::vec2& vec )
{
	pos = vec;
}
mob2::mob2( const glm::vec2& pos, const glm::vec2& dir )
{
	this->pos = pos;
	this->dir = dir;
}
mob2::mob2( const mob2& copy )
{
	pos = copy.pos;
	dir = copy.dir;
}

/* end */

}
}

#endif
