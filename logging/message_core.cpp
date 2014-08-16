
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_LOGGING_MESSAGE_CORE_CPP
#define BDAPI_LOGGING_MESSAGE_CORE_CPP
#include "logging/message.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"
#include "logging/handler.hpp"
#include "string/core.hpp"
#include "sys/timer.hpp"
#include "terminal/handler.hpp"

// namespaces
namespace bdapi   {
namespace logging {

/* logging message class core function implementation */

// set result
result message::set_result( bl success )
{
	if( !sent )
	{
		failed = !success;

		return execute();
	}
	else
	{
		if( failed )
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
result message::set_result( result success )
{
	if( success != 1 )
	{
		return set_result(false);
	}
	else
	{
		return set_result(true);
	}
}

// private execute
result message::execute()
{
	if( !sent )
	{
		entry_timer->stop();

		if( failed )
		{
			if( verbosity == 2 || this->buffered )
			{
				LOG_CLOSE();
			}

			error::write( fatal, entry_timer->get_stopped(), function.c_str(), file.c_str(), line,
				str::capitalize_first( str::replace( failure, "~~", object ) ).c_str() );

			if( buffered )
			{
				logging::execute_buffer();
			}
		}
		else
		{
			if( verbosity == 2 )
			{
				LOG_CLOSE();

				LOG( "%s%s", str::capitalize_first( str::replace( success, "~~", object ) ).c_str(),
					entry_timer->get_stopped_string().c_str() );

				if( buffered )
				{
					logging::execute_buffer();
				}
			}
			else if( verbosity == 1 )
			{
				if( buffered )
				{
					LOG_CLOSE();
				}

				LOG( "%s ~X08...%s", str::capitalize_first( str::replace( init, "~~", object ) ).c_str(),
					entry_timer->get_stopped_string().c_str() );

				if( buffered )
				{
					logging::clear_buffer();
				}
			}
		}

		if( USING_TERMINAL
		&&  terminal::get_subsystem_state() >= SUBSYS_ACTIVE
		&& !terminal::is_automatic() )
		{
			terminal::refresh();
		}

		sent = true;
	}

	if( failed )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/* end */

}
}

#endif
