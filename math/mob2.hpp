
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_MOB2_HPP
#define BDAPI_MATH_MOB2_HPP
#include "bdapi.hpp"

/* includes */

// glm
#include "glm/glm.hpp"
#include "glm/ext.hpp"

/* namespaces */
namespace bdapi {
namespace math  {

/* 2-dimensional mobile class declaration */

class mob2
{

public: // public data

	glm::vec2 pos;
	glm::vec2 dir;

public: // public initialization functions (math_mob2_init.cpp)

	mob2 () {};
	mob2 ( f32 x, f32 y                               );
	mob2 ( f32 x, f32 y, f32 a, f32 b                 );
	mob2 ( const glm::vec2& vec                       );
	mob2 ( const glm::vec2& pos, const glm::vec2& dir );
	mob2 ( const mob2& copy                           );
 ~mob2 () {};

public: // public core functions (math_mob2_core.cpp)



};

/* end */

}
}

#endif
