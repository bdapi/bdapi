
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ERROR_MESSAGE_INIT_CPP
#define BDAPI_ERROR_MESSAGE_INIT_CPP
#include "error/message.hpp"

/* includes */

// bdapi
#include "io/path.hpp"
#include "string/core.hpp"
#include "sys/timer.hpp"

/* namespaces */
namespace bdapi {
namespace error {

/* error message class initialization function implementations */

// constructors
message::message( string function, string file, s32 line, cstr input, ... )
{
	STR_FORMAT;

	initialize( true, -1.0, function, file, line, input );
}
message::message( bl fatal, string function, string file, s32 line, cstr input, ... )
{
	STR_FORMAT;

	initialize( fatal, -1.0, function, file, line, input );
}
message::message( f64 stopped_time, string function, string file, s32 line, cstr input, ... )
{
	STR_FORMAT;

	initialize( true, stopped_time, function, file, line, input );
}
message::message( bl fatal, f64 stopped_time, string function, string file, s32 line, cstr input, ... )
{
	STR_FORMAT;

	initialize( fatal, stopped_time, function, file, line, input );
}
message::message( const message& copy )
{
	fatal = copy.fatal;

	stopped_time = copy.stopped_time;

	function = copy.function;
	file     = copy.file;

	line = copy.line;

	input  = copy.input;
	output = copy.output;
}

// private initialize
message& message::initialize( bl fatal, f64 stopped_time, string function, string file, s32 line,
string input )
{
	this->fatal = fatal;

	this->stopped_time = stopped_time;

	this->function = function;

	this->file = io::path(file).get_filename();

	this->line = line;

	this->input = input;

	if( this->stopped_time > 0.0 )
	{
		this->output = str::format( "%s ~X07in function ~FE\"%s\"~F8:~FF%i~F8:~X8F%s~X08() ...%s",
			this->input.c_str(), this->file.c_str(), this->line, this->function.c_str(),
			sys::timer::get_str( this->stopped_time ).c_str() );
	}
	else
	{
		this->output = str::format( "%s ~X07in function ~FE\"%s\"~F8:~FF%i~F8:~X8F%s~X08()",
			this->input.c_str(), this->file.c_str(), this->line, this->function.c_str() );
	}

	RETHIS;
}

/* end */

}
}

#endif
