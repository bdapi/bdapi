
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_LOGGING_HANDLER_INIT_CPP
#define BDAPI_LOGGING_HANDLER_INIT_CPP
#define BD_DATA_LOGGING
#include "logging/handler.hpp"

/* includes */

// bdapi
#include "logging/message.hpp"

// bdapi
#include "string/core.hpp"
#include "sys/handler.hpp"
#include "sys/timedata.hpp"
#include "terminal/handler.hpp"
#include "video/palette.hpp"

/* namespaces */
namespace bdapi   {
namespace logging {

/* static variables */

static bool handler_instance = false;

/* logging handler singleton initialization function implementations */

// private initializers
result initialize( parameters* handler_parameters )
{
	LOG_ERROR_1( "~F6subsystem", "~~ has already been initialized", !handler_instance );

	handler_instance = true;

	LOG_ERROR_1( "~F6subsystem parameters", "failed to read ~~", handler_parameters );

	logging::handler_parameters = handler_parameters;

	subsystem_state = SUBSYS_INITIALIZED;

	LOG_ERROR_2(
		"~FEterminal ~F6interface",
		"connecting ~~",
		"failed to connect ~~",
		init_terminal() );

	LOG_ERROR_1(
		"~FElog ~F6directory",
		"failed to create ~~",
		init_directory() );

	LOG_ERROR_1(
		"~FElog ~F6text file",
		"failed to create ~~",
		init_text_file() );

	LOG_ERROR_1(
		"~FElog ~F6HTML file",
		"failed to create ~~" ,
		init_html_file() );

	LOG_ERROR_1(
		"~FElog ~F6buffer",
		"failed to initialize ~~",
		init_buffer() );

	subsystem_state = SUBSYS_ACTIVE;

	return 1;
}

// private shutdown
result shutdown()
{
	subsystem_state = SUBSYS_SUSPENDED;

	if( text_file_output )
	{
		if( text_file->is_open() )
		{
			text_file->flush();
			text_file->close();
		}

		delete text_file;

		text_file = NULL;
	}

	if( html_file_output )
	{
		if( html_file->is_open() )
		{
			html_file->flush();
			html_file->close();
		}

		delete html_file;

		html_file = NULL;
	}

	subsystem_state = SUBSYS_SHUTDOWN;

	return 1;
}

// private initialize logging terminal
result init_terminal()
{
	terminal_output = handler_parameters->terminal_output;

	if( terminal_output )
	{
		if( !USING_TERMINAL )
		{
			terminal_output = false;

			return 1;
		}
	}

	return 1;
}

// private initialize logging directory
result init_directory()
{
	log_folder_path = "/logs/";

	if( !log_folder_path.exists() )
	{
		string tmp_string = str::format( "~F6directory ~FE\"%s\"", log_folder_path().c_str() );

		LOG_ERROR(  1, tmp_string.c_str(), "creating ~~", "failed to create ~~" );

		log_folder_path.create_folder();

		LOG_RETURN( 1, log_folder_path.exists() );
	}

	return 1;
}

// private initialize logging text file
result init_text_file()
{
	text_file_output = handler_parameters->text_file_output;

	if( !text_file_output )
	{
		return 1;
	}

	string text_filename = str::format( "%s_%s.txt",
		sys::get_start_time()->get_date_string().c_str(),
		sys::get_start_time()->get_safe_time_string().c_str() );

	text_file_path = log_folder_path.branch( text_filename );

	string tmp_string = str::format( "~F6text file ~FE\"%s\"", text_file_path().c_str() );

	LOG_ERROR(   1, tmp_string.c_str(), "creating ~~", "failed to create ~~" );

	text_file = new std::ofstream();

	text_file->open( text_file_path() );

	LOG_RECEIVE( 1, text_file->is_open() )
	{
		DEL( text_file );

		return 0;
	}

	return 1;
}

// private initialize logging html file
result init_html_file()
{
	html_file_output = handler_parameters->html_file_output;

	if( !html_file_output )
	{
		return 1;
	}

	string html_filename = str::format( "%s_%s.html",
		sys::get_start_time()->get_date_string().c_str(),
		sys::get_start_time()->get_safe_time_string().c_str() );

	html_file_path = log_folder_path.branch( html_filename );

	string tmp_string = str::format( "~F6HTML file ~FE\"%s\"", html_file_path().c_str() );

	LOG_ERROR(   1, tmp_string.c_str(), "creating ~~", "failed to create ~~" );

	html_file = new std::ofstream();

	html_file->open( html_file_path() );

	LOG_RECEIVE( 1, html_file->is_open() )
	{
		DEL( html_file );

		return 0;
	}

	html_palette = handler_parameters->html_palette;

	if( html_palette == NULL )
	{
		html_palette = new video::palette(16);

		html_palette->set(  0, video::color::by_u8(   0,   0,   0 ) );
		html_palette->set(  1, video::color::by_u8(   0,   0, 168 ) );
		html_palette->set(  2, video::color::by_u8(   0, 168,   0 ) );
		html_palette->set(  3, video::color::by_u8(   0, 168, 168 ) );
		html_palette->set(  4, video::color::by_u8( 168,   0,   0 ) );
		html_palette->set(  5, video::color::by_u8( 168,   0, 168 ) );
		html_palette->set(  6, video::color::by_u8( 168,  84,   0 ) );
		html_palette->set(  7, video::color::by_u8( 168, 168, 168 ) );
		html_palette->set(  8, video::color::by_u8(  84,  84,  84 ) );
		html_palette->set(  9, video::color::by_u8(  84,  84, 252 ) );
		html_palette->set( 10, video::color::by_u8(  84, 252,  84 ) );
		html_palette->set( 11, video::color::by_u8(  84, 252, 252 ) );
		html_palette->set( 12, video::color::by_u8( 252,  84,  84 ) );
		html_palette->set( 13, video::color::by_u8( 252,  84, 252 ) );
		html_palette->set( 14, video::color::by_u8( 252, 252,  84 ) );
		html_palette->set( 15, video::color::by_u8( 252, 252, 252 ) );
	}

	xml_encoding  = "utf-8";
	html_encoding = "utf-8";

	std::ofstream& html_output = *html_file;

	html_output << "<?xml version='1.0' encoding='";
	html_output << xml_encoding;
	html_output << "'?>"
		"<!DOCTYPE html PUBLIC '-//W3C//DTD XHTML 1.0 Transitional//EN' "
		"'http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd'>"
		"<html xmlns='http://www.w3.org/1999/xhtml' xml:lang='en' lang='en'>"
		"<head>"
		"<meta http-equiv='Content-Type' content='text/html; charset=";
	html_output << html_encoding;
	html_output << "' />";

	html_output << "<title>";
	html_output << sys::get_game_full_title();
	html_output << " Log File for ";
	html_output << sys::get_start_time()->get_date_string();
	html_output << " @ ";
	html_output << sys::get_start_time()->get_time_string();
	html_output << "</title>";

	html_output << "<meta name='author' content='Brain Damage' />";
	html_output << "<meta name='description' content='";
	html_output << sys::get_game_full_title();
	html_output << " log file generated on ";
	html_output << sys::get_start_time()->get_date_string();
	html_output << " at ";
	html_output << sys::get_start_time()->get_time_string();
	html_output << ".' />";
	html_output << "<meta name='generator' content='";
	html_output << sys::get_engine_full_title();
	html_output << "' />";

	html_output << "<style type='text/css'>";
	html_output << "<!--";
	html_output << "@font-face{font-family:";
	html_output << "'Perfect DOS VGA 437';";
	html_output << "src:url(";
	html_output << "'../data/font_log.eot'";
	html_output << ");}";
	html_output << "@font-face{font-family:'";
	html_output << "Perfect DOS VGA 437';";
	html_output << "src:url(";
	html_output << "'../data/font_log.svg#dos'";
	html_output << ") format('svg'),";
	html_output << "url(";
	html_output << "'../data/font_log.ttf'";
	html_output << ") format('truetype');}";

	html_output << "body{background-color:#";
	html_output << html_palette->get(0).create_html_color();
	html_output << ";color:#";
	html_output << html_palette->get(7).create_html_color();

	html_output << ";font-family:";
	html_output << "'Perfect DOS VGA 437',";
	html_output << "'Fixedsys',";
	html_output << "'Fixedsys Regular',";
	html_output << "'Fixedsys Excelsior 3.01 Regular',";
	html_output << "'Terminal',";
	html_output << "'Courier New',";
	html_output << "'Courier';";

	html_output << "font-size:12pt;";
	html_output << "font-weight:normal;";
	html_output << "text-align:left;";
	html_output << "text-decoration:none;";
	html_output << "line-height:16px;";
	html_output << "letter-spacing:-1px;";

	html_output << "margin-top:8px;";
	html_output << "margin-left:8px;";
	html_output << "margin-bottom:8px;";
	html_output << "margin-right:8px};";

	forb(16)
	{
		forf(16)
		{
			html_output << str::format( ".C%x%x{background-color:#%s;color:#%s;}", b, f,
				html_palette->get(b).create_html_color().c_str(),
				html_palette->get(f).create_html_color().c_str() );
		}
	}

	html_output << "-->";
	html_output << "</style>";
	html_output << "</head>";
	html_output << "<body>";

	html_output.flush();

	return 1;
}

// private initialize logging buffer
result init_buffer()
{
	if( terminal_output )
	{
		for_i( log_strings )
		{
			write_terminal(*i);
		}
	}

	if( text_file_output )
	{
		for_i( log_strings )
		{
			write_text(*i);
		}
	}

	if( html_file_output )
	{
		for_i( log_strings )
		{
			write_html(*i);
		}
	}

	return 1;
}

/* end */

}
}

#endif
