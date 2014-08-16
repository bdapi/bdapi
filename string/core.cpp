
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_STRING_CORE_CPP
#define BDAPI_STRING_CORE_CPP
#include "string/core.hpp"

/* includes */

// boost
#include "boost/algorithm/string/classification.hpp"
#include "boost/algorithm/string/erase.hpp"
#include "boost/algorithm/string/replace.hpp"
#include "boost/algorithm/string/split.hpp"

/* namespaces */
namespace bdapi {
namespace str   {

/* string function implementations */

// create formatted string
string format( cstr input, ... )
{
	STR_FORMAT;

	return input;
}

// remove substring from string
string remove( string input, string substr )
{
	return boost::erase_all_copy( input, substr );
}

// strip brain damage codes from string
string strip_codes( string input )
{
	fori( input.size() )
	{
		if( input[i] == '~' )
		{
			if( ( input[i+1] == 'B' || input[i+1] == 'F' )
			&& isxdigit( input[i+2] ) )
			{
				input.erase( i, 3 );

				i--;
			}
			else
			if( ( input[i+1] == 'C' || input[i+1] == 'X' )
			&& isxdigit( input[i+2] ) && isxdigit( input[i+3] ) )
			{
				if( input[i+1] == 'C' )
				{
					input.insert( i, format( "$0x(%c%c)", input[i+2], input[i+3] ) );

					input.erase( i + 7, 4 );
				}
				else if( input[i+1] == 'X' )
				{
					input.erase( i, 4 );
				}

				i--;
			}
		}
	}

	return input;
}

// strip extension from filename string
string strip_extension( string input )
{
	s32 period_position = 0;
	bl  period_present  = false;

	fori( input.size() )
	{
		if( input[i] == '.' )
		{
			period_position = i;
			period_present  = true;
		}
	}

	if( period_present )
	{
		input.erase( period_position, input.size() - period_position );
	}

	return input;
}

// strip filename from path string
string strip_file( string input )
{
	s32 slash_position = 0;
	bl  slash_present  = false;

	ifor( input.size() )
	{
		if( input[i] == '/' || input[i] == '\\' )
		{
			slash_position = i;
			slash_present  = true;

			break;
		}
	}

	if( slash_present )
	{
		input.erase( slash_position + 1, input.size() - slash_position );
	}

	return input;
}

// strip path from filename string
string strip_path( string input )
{
	s32 slash_position = 0;
	bl  slash_present  = false;

	fori( input.size() )
	{
		if( input[i] == '/' || input[i] == '\\' )
		{
			slash_position = i;
			slash_present  = true;
		}
	}

	if( slash_present )
	{
		input.erase( 0, slash_position + 1 );
	}

	return input;
}

// change filename string extension
string change_extension( string input, string extension )
{
	s32 period_position = 0;
	bl  period_present  = false;

	fori( input.size() )
	{
		if( input[i] == '.' )
		{
			period_position = i;
			period_present  = true;
		}
	}

	if( period_present )
	{
		input.replace( period_position + 1, input.size() - period_position + 1, extension );
	}

	return input;
}

// capitalize first letter in string
string capitalize_first( string input )
{
	fori( input.size() )
	{
		if( input[i] == '~' )
		{
			if( ( input[i+1] == 'B' || input[i+1] == 'F' )
			&& isxdigit( input[i+2] ) )
			{
				i += 2;
			}
			else
			if( ( input[i+1] == 'C' || input[i+1] == 'X' )
			&& isxdigit( input[i+2] ) && isxdigit( input[i+3] ) )
			{
				i += 3;
			}
		}
		else if( isalpha( input[i] ) && islower( input[i] ) )
		{
			input[i] = toupper( input[i] );

			break;
		}
		else
		{
			break;
		}
	}

	return input;
}

// to lower
string to_lower( string input )
{
	fori( input.size() )
	{
		input[i] = tolower( input[i] );
	}

	return input;
}

// to upper
string to_upper( string input )
{
	fori( input.size() )
	{
		input[i] = toupper( input[i] );
	}

	return input;
}

// create substring from string
string substring( string input, s32 index, s32 size )
{
	return input.substr( index, size );
}

// replace substring in string
string replace( string input, string old_substr, string new_substr )
{
	return boost::replace_all_copy( input, old_substr, new_substr );
}
string replace( string input, string old_substr, string tmp_substr, string new_substr )
{
	return replace( replace( input, old_substr, tmp_substr ), tmp_substr, new_substr );
}

// find character in string
s32 find( string input, chr character )
{
	return input.find( character, 0 );
}
s32 find( string input, chr character, s32 position )
{
	return input.find( character, position );
}

// find substring in string
s32 find( string input, string substr )
{
	return input.find( substr, 0 );
}
s32 find( string input, string substr, s32 position )
{
	return input.find( substr, position );
}

// get filename extension
string get_extension( string input )
{
	s32 period_position = 0;
	s32 substr_size     = 0;
	bl  period_present  = false;

	fori( input.size() )
	{
		substr_size++;

		if( input[i] == '.' )
		{
			period_position = i;
			period_present  = true;

			substr_size = 0;
		}
	}

	if( period_present )
	{
		return input.substr( period_position + 1, substr_size );
	}

	return string();
}

// get filename path
string get_path( string input )
{
	s32 slash_position = 0;
	bl  slash_present  = false;

	fori( input.size() )
	{
		if( input[i] == '/' || input[i] == '\\' )
		{
			slash_position = i;
			slash_present  = true;
		}
	}

	if( slash_present )
	{
		input.erase( slash_position + 1, input.size() - slash_position );

		return input;
	}
	else
	{
		return string();
	}
}

// split
util::container< string, std::vector > split( string input, chr character )
{
	return split( input, format( "%c", character ) );
}
util::container< string, std::vector > split( string input, string substr )
{
	util::container< string, std::vector > string_list;

	s32 pos = find( input, substr );

	while( pos != string::npos )
	{
		string_list.insert( substring( input, 0, pos ) );

		input.erase( 0, pos + substr.size() );

		pos = find( input, substr );
	}

	string_list.insert( input );

	return string_list;
}

// convert hexidecimal substring to decimal number
s32 hex_2_dec( string input, s32 index, s32 size )
{
	string substr = substring( input, index, size );

	s32 decimal = -1;

	if( !is_xdigit( substr ) )
	{
		return decimal;
	}

	decimal = strtol( substr.c_str(), NULL, 16 );

	return decimal;
}

// comparison
#define STR_COMP_IMPL(AA) \
bl is_##AA( string i ) { \
	forj( i.size() ) \
		if( !is##AA( i[j] ) ) \
			return false; \
	return true; }

STR_COMP_IMPL(alnum)
STR_COMP_IMPL(alpha)
STR_COMP_IMPL(cntrl)
STR_COMP_IMPL(digit)
STR_COMP_IMPL(graph)
STR_COMP_IMPL(lower)
STR_COMP_IMPL(print)
STR_COMP_IMPL(punct)
STR_COMP_IMPL(space)
STR_COMP_IMPL(upper)
STR_COMP_IMPL(xdigit)

/* end */

}
}

#endif
