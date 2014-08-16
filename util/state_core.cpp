
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_STATE_CORE_CPP
#define BDAPI_UTIL_STATE_CORE_CPP
#include "util/state.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"

/* namespaces */
namespace bdapi {
namespace util  {

/* state class core function implementations */

// do initialize
result state::do_initialize()
{
	if( !initialized )
	{
		result initialize_result = (*function_initialize)();

		if( !initialize_result )
		{
			WRITE_ERROR( "Failed to initialize state ~FE\"%s\" "
				"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8]",
				name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

			return 0;
		}
		else
		{
			initialize_count++;

			initialized = true;

			return do_resume();
		}
	}

	WRITE_ERROR( "Failed to initialize state ~FE\"%s\" "
		"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8] "
		"~F7as it has already been initialized",
		name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

	return 0;
}

// do resume
result state::do_resume()
{
	if( !initialized )
	{
		WRITE_ERROR( "Failed to resume state ~FE\"%s\" "
			"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8] "
			"~F7as it has not been initialized",
			name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

		return 0;
	}

	if( !active )
	{
		result resume_result = (*function_resume)();

		if( !resume_result )
		{
			WRITE_ERROR( "Failed to resume state ~FE\"%s\" "
				"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8]",
				name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

			return 0;
		}
		else
		{
			resume_count++;

			active = true;

			return resume_result;
		}
	}

	WRITE_ERROR( "Failed to resume state ~FE\"%s\" "
		"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8] "
		"~F7as it is active",
		name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

	return 0;
}

// do iterate
result state::do_iterate()
{
	if( !initialized )
	{
		WRITE_ERROR( "Failed to iterate state ~FE\"%s\" "
			"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8] "
			"~F7as it has not been initialized",
			name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

		return 0;
	}

	if( !active )
	{
		WRITE_ERROR( "Failed to iterate state ~FE\"%s\" "
			"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8] "
			"~F7as it inactive",
			name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

		return 0;
	}

	result iterate_result = (*function_iterate)();

	if( !iterate_result )
	{
		WRITE_ERROR( "Failed to iterate state ~FE\"%s\" "
			"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8]",
			name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

		return 0;
	}
	else
	{
		iterate_count++;

		return iterate_result;
	}
}

// do suspend
result state::do_suspend()
{
	if( !initialized )
	{
		WRITE_ERROR( "Failed to suspend state ~FE\"%s\" "
			"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8] "
			"~F7as it has not been initialized",
			name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

		return 0;
	}

	if( !active )
	{
		WRITE_ERROR( "Failed to suspend state ~FE\"%s\" "
			"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8] "
			"~F7as it inactive",
			name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

		return 0;
	}

	result suspend_result = (*function_suspend)();

	if( !suspend_result )
	{
		WRITE_ERROR( "Failed to suspend state ~FE\"%s\" "
			"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8]",
			name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

		return 0;
	}
	else
	{
		suspend_count++;

		active = false;

		return suspend_result;
	}
}

// do kill
result state::do_kill()
{
	if( !initialized )
	{
		WRITE_ERROR( "Failed to terminate state ~FE\"%s\" "
			"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8] "
			"~F7as it has not been initialized",
			name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

		return 0;
	}

	if( !do_suspend() )
	{
		WRITE_ERROR( "Failed to terminate state ~FE\"%s\" "
			"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8] "
			"~F7as it is active",
			name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

		return 0;
	}

	result result_kill = (*function_kill)();

	if( !result_kill )
	{
		WRITE_ERROR( "Failed to terminate state ~FE\"%s\" "
			"~F8[~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8.~FF%u~F8]",
			name.c_str(), initialize_count, resume_count, iterate_count, suspend_count, kill_count );

		return 0;
	}
	else
	{
		kill_count++;

		initialized = false;
		active      = false;

		return result_kill;
	}
}

/* end */

}
}

#endif
