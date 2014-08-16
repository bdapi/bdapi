
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_PIPELINE_INIT_CPP
#define BDAPI_VIDEO_PIPELINE_INIT_CPP
#include "video/pipeline.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace video {

/* pipeline class initialization function implementations */

// add buffer
result pipeline::add_buffer( buffer* pipeline_buffer )
{
	buffers.insert( pipeline_buffer );

	return 1;
}

// add shader
result pipeline::add_shader( shader* pipeline_shader )
{
	shaders.insert( pipeline_shader );

	return 1;
}

/* end */

}
}

#endif
