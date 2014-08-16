
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_STATEHANDLER_QUERY_CPP
#define BDAPI_UTIL_STATEHANDLER_QUERY_CPP
#include "util/statehandler.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* state handler singleton query function implementations */

// get name
string statehandler::get_name() const
{
	if( !current_state )
	{
		return "";
	}
	else
	{
		return current_state->get_name();
	}
}
string statehandler::get_name( s32 i ) const
{
	if( is_empty() )
	{
		return "";
	}
	else
	{
		return states[i]->get_name();
	}
}

// get initialize count
s64 statehandler::get_initialize_count() const
{
	if( !current_state )
	{
		return -1;
	}
	else
	{
		return current_state->get_initialize_count();
	}
}
s64 statehandler::get_initialize_count( s32 i ) const
{
	if( is_empty() )
	{
		return -1;
	}
	else
	{
		return states[i]->get_initialize_count();
	}
}

// get resume count
s64 statehandler::get_resume_count() const
{
	if( !current_state )
	{
		return -1;
	}
	else
	{
		return current_state->get_resume_count();
	}
}
s64 statehandler::get_resume_count( s32 i ) const
{
	if( is_empty() )
	{
		return -1;
	}
	else
	{
		return states[i]->get_resume_count();
	}
}

// get iterate count
s64 statehandler::get_iterate_count() const
{
	if( !current_state )
	{
		return -1;
	}
	else
	{
		return current_state->get_iterate_count();
	}
}
s64 statehandler::get_iterate_count( s32 i ) const
{
	if( is_empty() )
	{
		return -1;
	}
	else
	{
		return states[i]->get_iterate_count();
	}
}

// get suspend count
s64 statehandler::get_suspend_count() const
{
	if( !current_state )
	{
		return -1;
	}
	else
	{
		return current_state->get_suspend_count();
	}
}
s64 statehandler::get_suspend_count( s32 i ) const
{
	if( is_empty() )
	{
		return -1;
	}
	else
	{
		return states[i]->get_suspend_count();
	}
}

// get kill count
s64 statehandler::get_kill_count() const
{
	if( !current_state )
	{
		return -1;
	}
	else
	{
		return current_state->get_kill_count();
	}
}
s64 statehandler::get_kill_count( s32 i ) const
{
	if( is_empty() )
	{
		return -1;
	}
	else
	{
		return states[i]->get_kill_count();
	}
}

// get size
s32 statehandler::get_size() const
{
	return states.get_size();
}

// is initialized
bl statehandler::is_initialized() const
{
	if( !current_state )
	{
		return false;
	}
	else
	{
		return current_state->is_initialized();
	}
}
bl statehandler::is_initialized( s32 i ) const
{
	if( is_empty() )
	{
		return false;
	}
	else
	{
		return states[i]->is_initialized();
	}
}

// is active
bl statehandler::is_active() const
{
	if( !current_state )
	{
		return false;
	}
	else
	{
		return current_state->is_active();
	}
}
bl statehandler::is_active( s32 i ) const
{
	if( is_empty() )
	{
		return false;
	}
	else
	{
		return states[i]->is_active();
	}
}

// is empty
bl statehandler::is_empty() const
{
	return states.is_empty();
}

/* end */

}
}

#endif
