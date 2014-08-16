
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ERROR_HANDLER_HPP
#define BDAPI_ERROR_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "deque"

// bdapi
#include "error/message.hpp"
#include "string/string.hpp"
#include "util/container.hpp"

/* namespaces */
namespace bdapi {
namespace error {

/* error handler parameters struct declaration */

struct parameters
{
	bl log_errors   = true;
	bl log_warnings = true;

	bl shutdown_report = true;
};

/* error handler typedef declarations */

typedef util::container< message, std::deque > error_message_deque;

/* error handler singleton declaration */

#ifdef  BD_DATA_ERROR
#define BD_DATA_EXTERN
#endif
#include "core/local_open.hpp"

// initialization data

BD_DATA_GET_COPY_INIT_SET( subsys, subsystem_state, SUBSYS_UNUSED );

BD_DATA_GET_COPY( parameters*, handler_parameters );

// list data

BD_DATA_GET_REFR( error_message_deque, error_list   );
BD_DATA_GET_REFR( error_message_deque, warning_list );
BD_DATA_GET_REFR( error_message_deque, any_list     );

// core data

BD_DATA_GET_COPY( string, report );

// initialization functions (error_handler_init.cpp)

result initialize ( parameters* handler_parameters );
result shutdown   ();

// core functions (error_handler_core.cpp)

void write (                             string function, string file, s32 line, cstr input, ... );
void write ( bl fatal,                   string function, string file, s32 line, cstr input, ... );
void write (           f64 stopped_time, string function, string file, s32 line, cstr input, ... );
void write ( bl fatal, f64 stopped_time, string function, string file, s32 line, cstr input, ... );
void write ( const message& input );

void generate_report ();

// query functions (error_handler_query.cpp)

const message& get_last_error   ();
const message& get_last_warning ();
const message& get_last_any     ();

s32 get_error_count   ();
s32 get_warning_count ();
s32 get_any_count     ();

bl error_exists   ();
bl warning_exists ();
bl any_exists     ();

#include "core/local_close.hpp"

/* error handling function macro definitions */

#define USING_ERROR ( error::get_subsystem_state() != SUBSYS_UNUSED )

#define WRITE_ERROR(...)   { if( USING_ERROR ) { \
error::write( true,  BD_FUNC, BD_FILE, BD_LINE, __VA_ARGS__ ); } }

#define WRITE_WARN(...)    { if( USING_ERROR ) { \
error::write( false, BD_FUNC, BD_FILE, BD_LINE, __VA_ARGS__ ); } }

#define WRITE_WARNING(...) { if( USING_ERROR ) { \
error::write( false, BD_FUNC, BD_FILE, BD_LINE, __VA_ARGS__ ); } }

#define ERROR_EXISTS   ( USING_ERROR && error::error_exists()   )
#define WARN_EXISTS    ( USING_ERROR && error::warning_exists() )
#define WARNING_EXISTS ( USING_ERROR && error::warning_exists() )
#define ANY_EXISTS     ( USING_ERROR && error::any_exists()     )

#define IF_ERROR   if( ERROR_EXISTS   )
#define IF_WARN    if( WARN_EXISTS    )
#define IF_WARNING if( WARNING_EXISTS )
#define IF_ANY     if( ANY_EXISTS     )

/* end */

}
}

#endif
