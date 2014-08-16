
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_STRING_CORE_HPP
#define BDAPI_STRING_CORE_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "vector"

// bdapi
#include "string/string.hpp"
#include "util/container.hpp"

// namespaces 1
namespace bdapi {

// typedefs
typedef std::string string;

// namespaces 2
namespace str {

/* string function declarations */

// formatting
string format ( cstr input, ... );

// stripping
string remove          ( string input, string substr );
string strip_codes     ( string input                );
string strip_extension ( string input                );
string strip_file      ( string input                );
string strip_path      ( string input                );

// alteration
string change_extension ( string input, string extension );
string capitalize_first ( string input                   );
string to_lower         ( string input                   );
string to_upper         ( string input                   );

// substitution
string substring ( string input, s32 index,         s32 size                             );
string replace   ( string input, string old_substr,                    string new_substr );
string replace   ( string input, string old_substr, string tmp_substr, string new_substr );

// searching
s32 find ( string input, chr character               );
s32 find ( string input, chr character, s32 position );
s32 find ( string input, string substr               );
s32 find ( string input, string substr, s32 position );

string get_extension ( string input );
string get_path      ( string input );

util::container< string, std::vector > split ( string input, chr character );
util::container< string, std::vector > split ( string input, string substr );

// conversion
s32 hex_2_dec ( string input, s32 index, s32 size );

// comparison
#define STR_COMP_DECL(AA) \
bl is_##AA( string );

STR_COMP_DECL(alnum)
STR_COMP_DECL(alpha)
STR_COMP_DECL(cntrl)
STR_COMP_DECL(digit)
STR_COMP_DECL(graph)
STR_COMP_DECL(lower)
STR_COMP_DECL(print)
STR_COMP_DECL(punct)
STR_COMP_DECL(space)
STR_COMP_DECL(upper)
STR_COMP_DECL(xdigit)

/* string function macro definitions */

// formatted string parameter macro
#define STR_FORMAT\
	char    char_buffer[1024];\
	va_list args;\
	va_start ( args,              input       );\
	vsnprintf( char_buffer, 1024, input, args );\
	va_end   ( args                           );\
	input = char_buffer

// value printing macro
#define WRITE_U32(AA) str::format( "~F3%s ~F8: ~FB%u", #AA, AA ).c_str()
#define WRITE_S32(AA) str::format( "~F3%s ~F8: ~FB%i", #AA, AA ).c_str()
#define WRITE_F32(AA) str::format( "~F3%s ~F8: ~FB%f", #AA, AA ).c_str()
#define WRITE_STR(AA) str::format( "~F3%s ~F8: ~FB%s", #AA, AA ).c_str()

/* end */

}
}

#endif
