
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_PIPELINE_CORE_CPP
#define BDAPI_VIDEO_PIPELINE_CORE_CPP
#include "video/pipeline.hpp"

/* includes */

// bdapi
#include "video/opengl.hpp"
#include "video/buffer.hpp"
#include "video/color.hpp"
#include "video/image.hpp"
#include "video/shader.hpp"

// namespaces
namespace bdapi {
namespace video {

/* pipeline class core function implementations */

// begin
void pipeline::begin()
{
	current_index = 0;

	current_buffer = buffers[ current_index ];
	current_shader = shaders[ current_index ];

	activate();

	gl::reset();
	gl::clear();
	gl::view_2d();
	gl::white();
	gl::texture_2d(true);
	gl::blend(true);
	gl::blend_func(BF_ALPHA);

	start();
}

// next
void pipeline::next()
{
	if( current_buffer )
	{
		next( &current_buffer->get_image() );
	}
	else
	{
		next( NULL );
	}
}
void pipeline::next( image* pipeline_image )
{
	deactivate();
	stop();

	if( pipeline_image )
	{
		pipeline_image->bind();
	}

	current_index++;

	current_buffer = buffers[ current_index ];
	current_shader = shaders[ current_index ];

	activate();

	gl::reset();
	gl::clear();
	gl::view_2d();

	start();
}

// draw
void pipeline::draw()
{
	gl::white();
	gl::texture_2d(true);
	gl::blend(true);
	gl::blend_func(BF_ALPHA);
	gl::v_buffer();
	gl::t_image();
	gl::begin(QUADS);
	gl::draw();
	gl::end();
}

// finish
void pipeline::finish()
{
	if( current_buffer )
	{
		finish( &current_buffer->get_image() );
	}
	else
	{
		finish( NULL );
	}
}
void pipeline::finish( image* pipeline_image )
{
	deactivate();
	stop();

	if( pipeline_image )
	{
		pipeline_image->bind();
	}

	current_index = 0;

	current_buffer = NULL;
	current_shader = NULL;

	gl::reset();
	gl::clear();
	gl::view_2d();
	gl::white();
	gl::texture_2d(true);
	gl::blend(true);
	gl::blend_func(BF_ALPHA);
	gl::v_display();
	gl::t_image();
	gl::begin(QUADS);
	gl::draw();
	gl::end();
}

// activate
void pipeline::activate()
{
	if( current_buffer )
	{
		current_buffer->activate();
	}
}

// deactivate
void pipeline::deactivate()
{
	if( current_buffer )
	{
		current_buffer->deactivate();
	}
}

// start
void pipeline::start()
{
	if( current_shader )
	{
		current_shader->start();
	}
}

// stop
void pipeline::stop()
{
	if( current_shader )
	{
		current_shader->stop();
	}
}

// bind
void pipeline::bind()
{
	if( current_buffer )
	{
		current_buffer->bind();
	}
}

// unbind
void pipeline::unbind()
{
	if( current_buffer )
	{
		current_buffer->unbind();
	}
}

/* end */

}
}

#endif
