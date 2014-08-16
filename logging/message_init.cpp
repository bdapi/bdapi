
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_LOGGING_MESSAGE_INIT_CPP
#define BDAPI_LOGGING_MESSAGE_INIT_CPP
#include "logging/message.hpp"

/* includes */

// bdapi
#include "logging/handler.hpp"
#include "sys/timer.hpp"

// namespaces
namespace bdapi   {
namespace logging {

/* logging message class initialization function implementation */

// constructors
message::message( bl fatal, bl buffered, cstr function, cstr file, s32 line, cstr object, cstr failure )
{
	initialize( fatal, buffered, function, file, line, object, NULL, NULL, failure );
}
message::message( bl fatal, bl buffered, cstr function, cstr file, s32 line, cstr object, cstr init,
cstr failure )
{
	initialize( fatal, buffered, function, file, line, object, init, NULL, failure );
}
message::message( bl fatal, bl buffered, cstr function, cstr file, s32 line, cstr object, cstr init,
cstr success, cstr failure )
{
	initialize( fatal, buffered, function, file, line, object, init, success, failure );
}

// destructor
message::~message()
{
	if( !sent )
	{
		execute();
	}

	DEL( entry_timer );
}

// private initialize
void message::initialize( bl fatal, bl buffered, cstr function, cstr file, s32 line, cstr object,
cstr init, cstr success, cstr failure )
{
	if( !success )
	{
		success = "";

		if( !init )
		{
			init = "";

			verbosity = 0;
		}
		else
		{
			verbosity = 1;
		}
	}
	else
	{
		this->success = success;

		verbosity = 2;
	}

	this->fatal    = fatal;

	this->function = function;
	this->file     = file;
	this->line     = line;

	failed = false;
	sent   = false;

	this->object  = object;
	this->object += "~X07";

	this->failure = failure;

	if( verbosity > 0 )
	{
		this->buffered = buffered;

		if( this->buffered )
		{
			logging::add_buffer();
		}

		this->init = init;

		if( verbosity == 2 || this->buffered )
		{
			LOG( "%s ~X08...", str::capitalize_first( str::replace( init, "~~", object ) ).c_str() );

			LOG_OPEN();
		}
	}
	else
	{
		this->buffered = false;
	}

	entry_timer = new sys::timer();
}

/* end */

}
}

#endif
