
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_STATEHANDLER_CORE_CPP
#define BDAPI_UTIL_STATEHANDLER_CORE_CPP
#include "util/statehandler.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"

/* namespaces */
namespace bdapi {
namespace util  {

/* state handler singleton core function implementations */

// do initialize
result statehandler::do_initialize()
{
	if( !current_state )
	{
		WRITE_ERROR( "Initial state has not been allocated" );

		return 0;
	}

	return current_state->do_initialize();
}

// do resume
result statehandler::do_resume()
{
	if( !current_state )
	{
		WRITE_ERROR( "Initial state has not been allocated" );

		return 0;
	}

	return current_state->do_resume();
}

// do iterate
result statehandler::do_iterate()
{
	if( !current_state )
	{
		WRITE_ERROR( "Initial state has not been allocated" );

		return 0;
	}

	return current_state->do_iterate();
}

// do suspend
result statehandler::do_suspend()
{
	if( !current_state )
	{
		WRITE_ERROR( "Initial state has not been allocated" );

		return 0;
	}

	return current_state->do_suspend();
}

// do kill
result statehandler::do_kill()
{
	if( !current_state )
	{
		WRITE_ERROR( "Initial state has not been allocated" );

		return 0;
	}

	return current_state->do_kill();
}

// change state
result statehandler::change_state( state* new_state )
{
	if( !new_state )
	{
		WRITE_ERROR( "New state has not been allocated" );

		return 0;
	}

	if( !is_empty() )
	{
		if( !do_suspend() )
		{
			WRITE_ERROR( "Failed to suspend current state" );

			return 0;
		}

		for_i( states )
		{
			if( new_state == *i )
			{
				states.insert( new_state );

				current_state = states.get_back();

				return do_resume();
			}
		}
	}

	states.insert( new_state );

	current_state = states.get_back();

	return do_initialize();
}

// end state
result statehandler::end_state()
{
	if( is_empty() )
	{
		WRITE_ERROR( "State handler is empty" );

		return 0;
	}

	if( !do_kill() )
	{
		WRITE_ERROR( "Failed to terminate current state" );

		return 0;
	}

	states.pop_back();

	if( is_empty() )
	{
		current_state = NULL;

		return 1;
	}

	while( !states.get_back()->is_initialized() )
	{
		states.pop_back();

		if( is_empty() )
		{
			current_state = NULL;

			return 1;
		}
	}

	current_state = states.get_back();

	return do_resume();
}

/* end */

}
}

#endif
