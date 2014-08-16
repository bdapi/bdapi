
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_STATE_INIT_CPP
#define BDAPI_UTIL_STATE_INIT_CPP
#include "util/state.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* state class initialization function implementations */

// constructors
state::state( string name, result(*function_initialize)(), result(*function_resume)(),
result(*function_iterate)(), result(*function_suspend)(), result(*function_kill)() )
{
	initialize( name, function_initialize, function_resume, function_iterate, function_suspend,
		function_kill );
}
state::state( const state& copy )
{
	initialize( copy );
}

// initializers
result state::initialize( string name, result(*function_initialize)(), result(*function_resume)(),
result(*function_iterate)(), result(*function_suspend)(), result(*function_kill)() )
{
	this->function_initialize = function_initialize;
	this->function_resume     = function_resume;
	this->function_iterate    = function_iterate;
	this->function_suspend    = function_suspend;
	this->function_kill       = function_kill;

	this->name = name;

	initialized = false;
	active      = false;

	return 1;
}
result state::initialize( const state& copy )
{
	this->function_initialize = copy.function_initialize;
	this->function_resume     = copy.function_resume;
	this->function_iterate    = copy.function_iterate;
	this->function_suspend    = copy.function_suspend;
	this->function_kill       = copy.function_kill;

	this->name = copy.name;

	initialized = copy.initialized;
	active      = copy.active;

	initialize_count = copy.initialize_count;
	resume_count     = copy.resume_count;
	iterate_count    = copy.iterate_count;
	suspend_count    = copy.suspend_count;
	kill_count       = copy.kill_count;

	return 1;
}

/* end */

}
}

#endif
