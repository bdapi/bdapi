
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_LOGGING_HANDLER_CORE_CPP
#define BDAPI_LOGGING_HANDLER_CORE_CPP
#define BD_DATA_LOGGING
#include "logging/handler.hpp"

/* includes */

// standard
#include "vector"

// bdapi
#include "terminal/handler.hpp"

/* namespaces */
namespace bdapi   {
namespace logging {

/* logging handler singleton core function implementations */

// write
void write( cstr input, ... )
{
	STR_FORMAT;

	s32 position = str::find( input, '\n' );

	if( position != string::npos )
	{
		util::container< string, std::vector > log_list = str::split( input, '\n' );

		fori( log_list.get_size() )
		{
			string log_string = str::format( "%s~F8%s~F7%s", get_line_string().c_str(), branch_string.c_str(),
				log_list[i].c_str() );

			write_all( log_string );
		}
	}
	else
	{
		string log_string = str::format( "%s~F8%s~F7%s", get_line_string().c_str(), branch_string.c_str(),
			input );

		write_all( log_string );
	}
}

// add break
void add_break()
{
	add_break(1);
}
void add_break( s32 depth )
{
	branch_depth -= depth;

	string branch = " | ";

	fori( branch_depth )
	{
		branch += " | ";
	}

	string break_string = str::format( "%s~F8%s", get_line_string().c_str(), branch_string.c_str() );

	write_all( break_string );

	branch_depth += depth;
}

// set depth
void set_depth( s32 index )
{
	branch_depth = index;

	set_branch_string();
}

// shift depth
void shift_depth( s32 index )
{
	branch_depth += index;

	set_branch_string();
}

// increase depth
void increase_depth()
{
	branch_depth++;

	set_branch_string();
}
void increase_depth( s32 index )
{
	branch_depth += index;

	set_branch_string();
}

// decrease depth
void decrease_depth()
{
	branch_depth--;

	set_branch_string();
}
void decrease_depth( s32 index )
{
	branch_depth -= index;

	set_branch_string();
}

// add log buffer
void add_buffer()
{
	log_buffer.insert( logging_string_deque() );
}

// execute log buffer
void execute_buffer()
{
	if( !log_buffer.is_empty() )
	{
		logging_string_deque buffer( log_buffer.get_back() );

		log_buffer.pop_back();

		for_i( buffer )
		{
			write_all( *i );
		}
	}
}

// clear log buffer
void clear_buffer()
{
	if( !log_buffer.is_empty() )
	{
		log_buffer.pop_back();
	}
}

// get log amount
s32 get_log_amount()
{
	return log_strings.get_size();
}

// get log from back
string get_log_back( s32 index )
{
	return log_strings.get_back( index );
}

// get log from front
string get_log_front( s32 index )
{
	return log_strings.get_front( index );
}

// private get branch string
void set_branch_string()
{
	s32    branch_color_number = branch_depth % 6;
	string branch_color_string;

	switch( branch_color_number )
	{
		case 0: branch_color_string = "[~F9*~F8] "; break;
		case 1: branch_color_string = "[~F3*~F8] "; break;
		case 2: branch_color_string = "[~F2*~F8] "; break;
		case 3: branch_color_string = "[~F6*~F8] "; break;
		case 4: branch_color_string = "[~F4*~F8] "; break;
		case 5: branch_color_string = "[~F5*~F8] "; break;
	}

	if( branch_depth <= 0 )
	{
		branch_string = branch_color_string;
	}
	else if( branch_depth == 1 )
	{
		branch_string  = " +-";
		branch_string += branch_color_string;
	}
	else
	{
		branch_string = " | ";

		fori( branch_depth - 2 )
		{
			branch_string += " | ";
		}

		branch_string += " +-";
		branch_string += branch_color_string;
	}
}

// private get line string
string get_line_string()
{
	s32 log_size = ( log_strings.get_size() + 1 ) % 10000;

	if(      log_size < 10 )
	{
		return str::format( "~F8000~FF%i ", log_size );
	}
	else if( log_size < 100 )
	{
		return str::format( "~F800~FF%i ",  log_size );
	}
	else if( log_size < 1000 )
	{
		return str::format( "~F80~FF%i ",   log_size );
	}
	else
	{
		return str::format( "~FF%i ",       log_size );
	}
}

// private write buffer
void write_buffer( string input )
{
	if( !log_buffer.is_empty() )
	{
		log_buffer.get_back() << input;
	}
	else
	{
		log_strings << input;
	}
}

// private write terminal
void write_terminal( string input )
{
	if( terminal_output )
	{
		terminal::set_scrolling(true);
		terminal::write( input.c_str() );
		terminal::set_scrolling(false);

		if( terminal::is_automatic() )
		{
			terminal::refresh();
		}
	}
}

// private write text file
void write_text( string input )
{
	std::ofstream& text_output = *text_file;

	if( !text_output.is_open() )
	{
		return;
	}

	string text_input = str::strip_codes( input );

	text_output.write( text_input.c_str(), text_input.size() );
	text_output << "\n";
	text_output.flush();
}

// private write html
void write_html( string input )
{
	std::ofstream& html_output = *html_file;

	if( !html_output.is_open() )
	{
		return;
	}

	s32 size = input.size();

	s32 background_color = 0;
	s32 foreground_color = 7;

	bl span = false;

	fori( size )
	{
		if( input[i] == '~' )
		{
			if( ( input[i+1] == 'B' || input[i+1] == 'F' ) && isxdigit( input[i+2] ) )
			{
				if( span )
				{
					html_output << "</span>";
				}

				if( input[i+1] == 'B' )
				{
					background_color = str::hex_2_dec( input, i+2, 1 );
				}
				else if( input[i+1] == 'F' )
				{
					foreground_color = str::hex_2_dec( input, i+2, 1 );
				}

				html_output << str::format( "<span class='C%x%x'>", background_color, foreground_color );

				span = true;
					i += 2;
			}
			else
			if( ( input[i+1] == 'C' || input[i+1] == 'X' ) && isxdigit( input[i+2] ) && isxdigit( input[i+3] ) )
			{
				if( input[i+1] == 'C' )
				{
					html_output << str::format( "$0x(%c%c)", input[i+2], input[i+3] );
				}
				else if( input[i+1] == 'X' )
				{
					if( span )
					{
						html_output << "</span>";
					}

					background_color = str::hex_2_dec( input, i+2, 1 );
					foreground_color = str::hex_2_dec( input, i+3, 1 );

					html_output << str::format( "<span class='C%x%x'>", background_color, foreground_color );

					span = true;
				}

				i += 3;
			}
			else
			{
				html_output.put( input[i] );
			}
		}
		else if( input[i] == ' ' )
		{
			html_output << "&nbsp";
		}
		else
		{
			html_output.put( input[i] );
		}
	}

	if( span )
	{
		html_output << "</span>";
	}

	html_output << "<br />";
	html_output.flush();
}

// private write all
void write_all( string input )
{
	write_buffer(input);

	if( subsystem_state >= SUBSYS_ACTIVE && log_buffer.is_empty() )
	{
		if( terminal_output )
		{
			write_terminal(input);
		}

		if( text_file_output )
		{
			write_text(input);
		}

		if( html_file_output )
		{
			write_html(input);
		}
	}
}

/* end */

}
}

#endif