
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ERROR_HANDLER_CORE_CPP
#define BDAPI_ERROR_HANDLER_CORE_CPP
#define BD_DATA_ERROR
#include "error/handler.hpp"

/* includes */

// standard
#include "iostream"

// bdapi
#include "core/platform.hpp"
#include "logging/handler.hpp"
#include "string/core.hpp"
#include "sys/handler.hpp"

/* namespaces */
namespace bdapi {
namespace error {

/* error handler singleton core function implementations */

// write error message
void write( string function, string file, s32 line, cstr input, ... )
{
	STR_FORMAT;

	write( message( true, function, file, line, input ) );
}
void write( bl fatal, string function, string file, s32 line, cstr input, ... )
{
	STR_FORMAT;

	write( message( fatal, function, file, line, input ) );
}
void write( f64 stopped_time, string function, string file, s32 line, cstr input, ... )
{
	STR_FORMAT;

	write( message( true, stopped_time, function, file, line, input ) );
}
void write( bl fatal, f64 stopped_time, string function, string file, s32 line, cstr input, ... )
{
	STR_FORMAT;

	write( message( fatal, stopped_time, function, file, line, input ) );
}
void write( const message& input )
{
	any_list << input;

	if( input.is_fatal() )
	{
		error_list << input;

		if( handler_parameters->log_errors )
		{
			if( USING_LOGGING && logging::get_subsystem_state() == SUBSYS_ACTIVE )
			{
				logging::write( "~X4EERROR~X08: ~F7%s", input.get_output().c_str() );
			}
			else
			{
				std::cout << "ERROR: " << str::strip_codes( input.get_output() ) << std::endl;
			}
		}
	}
	else
	{
		warning_list << input;

		if( handler_parameters->log_warnings )
		{
			if( USING_LOGGING && logging::get_subsystem_state() == SUBSYS_ACTIVE )
			{
				logging::write( "~X6EWARNING~X08: ~F7%s", input.get_output().c_str() );
			}
			else
			{
				std::cout << "WARNING: " << str::strip_codes( input.get_output() ) << std::endl;
			}
		}
	}
}

// generate error report
void generate_report()
{
	IF_ERROR
	{
		string log_filename;

		if( USING_LOGGING )
		{
			if( logging::has_html_file_output() )
			{
				log_filename = logging::get_html_file_path()();
			}
			else if( logging::has_text_file_output() )
			{
				log_filename = logging::get_text_file_path()();
			}
			else
			{
				report = str::format( "%s has been terminated due to the following error:\n\n\"%s\"",
					sys::get_game_title().c_str(), error_list.get_front().c_str() );
			}
		}
		else
		{
			report = str::format( "%s has been terminated due to the following error:\n\n\"%s\"",
				sys::get_game_title().c_str(), error_list.get_front().c_str() );
		}

		if( !log_filename.empty() )
		{
			report = str::format( "%s has been terminated due to the following error:\n\n\"%s\"\n\n"
				"Refer to log file \"%s\" for further information.", sys::get_game_title().c_str(),
				error_list.get_front().c_str(), log_filename.c_str() );
		}

		report = str::strip_codes( report );

		#if WIN

		MessageBox( NULL, report.c_str(), sys::get_engine_full_title().c_str(), MB_OK | MB_ICONHAND );

		#elif MAC
		#warning "Macintosh message box function unspecified."
		#elif NIX
		#warning "Unix message box function unspecified."
		#elif PS4
		#warning "PlayStation 4 message box function unspecified."
		#elif XBO
		#warning "Xbox One message box function unspecified."
		#elif WII
		#warning "Wii message box function unspecified."
		#endif
	}
}

/* end */

}
}

#endif