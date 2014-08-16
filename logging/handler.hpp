
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_LOGGING_HANDLER_HPP
#define BDAPI_LOGGING_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "deque"
#include "fstream"

// bdapi
#include "io/path.hpp"
#include "string/core.hpp"
#include "util/container.hpp"

/* namespaces */
namespace bdapi   {
namespace logging {

/* logging handler parameters struct declaration */

struct parameters
{
	bl terminal_output;
	bl text_file_output;
	bl html_file_output;

	video::palette* html_palette;
};

/* logging handler typedef declarations */

typedef util::container<               string, std::deque > logging_string_deque;
typedef util::container< logging_string_deque, std::deque > logging_string_deque_deque;

/* logging handler singleton declaration */

#ifdef  BD_DATA_LOGGING
#define BD_DATA_EXTERN
#endif
#include "core/local_open.hpp"

// initialization data

BD_DATA_GET_COPY_INIT_SET( subsys, subsystem_state, SUBSYS_UNUSED );

BD_DATA_GET_COPY( parameters*, handler_parameters );

// output parameter data

BD_DATA_HAS_COPY( bl, terminal_output  );
BD_DATA_HAS_COPY( bl, text_file_output );
BD_DATA_HAS_COPY( bl, html_file_output );

BD_DATA_GET_COPY( video::palette*, html_palette );

// core data

BD_DATA_GET_REFR( logging_string_deque, log_strings );

BD_DATA_GET_REFR( logging_string_deque_deque, log_buffer );

BD_DATA_GET_COPY_INIT( std::ofstream*, text_file, NULL );
BD_DATA_GET_COPY_INIT( std::ofstream*, html_file, NULL );

// descriptor data

BD_DATA_GET_COPY( io::path, log_folder_path );
BD_DATA_GET_COPY( io::path, text_file_path  );
BD_DATA_GET_COPY( io::path, html_file_path  );

BD_DATA_GET_COPY_INIT( s32, branch_depth, 0 );

BD_DATA_GET_COPY_INIT( string, branch_string, "[~F9*~F8] " );

BD_DATA_GET_COPY( string, xml_encoding  );
BD_DATA_GET_COPY( string, html_encoding );

// initialization functions (logging_handler_init.cpp)

result initialize ( parameters* handler_parameters );
result shutdown   ();

result init_terminal  ();
result init_directory ();
result init_text_file ();
result init_html_file ();
result init_buffer    ();

// core functions (logging_handler_core.cpp)

void write ( cstr input, ... );

void add_break (           );
void add_break ( s32 depth );

void set_depth      ( s32 index );
void shift_depth    ( s32 index );
void increase_depth (           );
void increase_depth ( s32 index );
void decrease_depth (           );
void decrease_depth ( s32 index );

void     add_buffer ();
void execute_buffer ();
void   clear_buffer ();

s32    get_log_amount (           );
string get_log_back   ( s32 index );
string get_log_front  ( s32 index );

// core functions (logging_handler_core.cpp)

void set_branch_string ();

string get_line_string ();

void write_buffer   ( string input );
void write_terminal ( string input );
void write_text     ( string input );
void write_html     ( string input );
void write_all      ( string input );

#include "core/local_close.hpp"

/* logging handling function macro definitions */

// log handling subsystem

#define USING_LOGGING ( logging::get_subsystem_state() != SUBSYS_UNUSED )

#define LOG(...)       { if( USING_LOGGING ) { logging::write(__VA_ARGS__);       } }
#define LOG_SET(...)   { if( USING_LOGGING ) { logging::set_depth(__VA_ARGS__);   } }
#define LOG_SHIFT(...) { if( USING_LOGGING ) { logging::shift_depth(__VA_ARGS__); } }

#define LOG_OPEN(...)  { if( USING_LOGGING ) { logging::increase_depth(__VA_ARGS__); } }
#define LOG_CLOSE(...) { if( USING_LOGGING ) { logging::decrease_depth(__VA_ARGS__); } }
#define LOG_BREAK(...) { if( USING_LOGGING ) { logging::add_break(__VA_ARGS__);      } }

#define LOG_U32(AA) { if( USING_LOGGING ) { logging::write( "~F2" #AA "~F8: ~FA%u", AA ); } }
#define LOG_S32(AA) { if( USING_LOGGING ) { logging::write( "~F2" #AA "~F8: ~FA%i", AA ); } }
#define LOG_F32(AA) { if( USING_LOGGING ) { logging::write( "~F2" #AA "~F8: ~FA%f", AA ); } }

/* end */

}
}

#endif
