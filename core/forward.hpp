
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_CORE_FORWARD_HPP
#define BDAPI_CORE_FORWARD_HPP
#include "bdapi.hpp"

/* includes */

/* namespaces */
namespace bdapi {

/* bdapi forward declarations */

// audio
namespace audio
{
	struct parameters;

	class channel;
	class raw;

	class echo;
	class reverb;

	class band;
	class buffer;
}

// display
namespace display
{
	struct parameters;

	class mode;
	class monitor;
}

// error
namespace error
{
	struct parameters;

	class message;
}

// gamepad
namespace gamepad
{
	struct parameters;
}

// generation
namespace gen
{
	class distribution;
	class rng;
}

// io
namespace io
{
	class file;
	class folder;
	class path;
}

// keyboard
namespace keyboard
{
	struct parameters;

	struct key;
}

// logging
namespace logging
{
	struct parameters;

	class message;
}

// math
namespace math
{
	class mob2;
	class mob3;
}

// mouse
namespace mouse
{
	struct parameters;

	struct button;
}

// opengl
namespace gl
{
}

// physics
namespace physics
{
	struct aabb;
	struct transform;

	class body;
	class handler;
	class shape;
}

// synthesizer
namespace synth
{
	class engine;
	class lfo;
	class module;
	class operate;
	class oscillator;
	class parameters;
	class voice;

	class engine_parameters;
	class module_parameters;
	class operator_parameters;
	class oscillator_parameters;
}

// system
namespace sys
{
	struct parameters;

	class timedata;
	class timer;
}

// terminal
namespace terminal
{
	struct parameters;
}

// video
namespace video
{
	struct parameters;

	class buffer;
	class color;
	class font;
	class image;
	class palette;
	class pipeline;
	class raw;
	class shader;
	class swatch;
	class vbo;
}

// utilities
namespace util
{
	class base;
	class buffer;
	class performance;
	class state;
	class statehandler;

	template < typename AA, template< typename, typename > class BB, typename CC > class container;
}

// window
namespace window
{
	struct parameters;
}

/* end */

}

#endif
