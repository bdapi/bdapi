
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_SHADER_CORE_CPP
#define BDAPI_VIDEO_SHADER_CORE_CPP
#include "video/shader.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"

// namespaces
namespace bdapi {
namespace video {

/* shader class core function implementations */

// start shader
shader& shader::start()
{
	if( gl::get_current_shader() != NULL )
	{
		gl::get_current_shader()->stop();
	}

	glUseProgramObjectARB( handle );

	gl::set_current_shader( this );

	RETHIS;
}

// stop shader
shader& shader::stop()
{
	glUseProgramObjectARB(0);

	gl::set_current_shader( NULL );

	RETHIS;
}

/* end */

}
}

#endif
