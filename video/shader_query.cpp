
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_SHADER_QUERY_CPP
#define BDAPI_VIDEO_SHADER_QUERY_CPP
#include "video/shader.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"

// namespaces
namespace bdapi {
namespace video {

/* shader class query function implementations */

// is active
bl shader::is_active() const
{
	if( gl::get_current_shader() == this )
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* end */

}
}

#endif
