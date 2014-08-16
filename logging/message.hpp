
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_LOGGING_MESSAGE_HPP
#define BDAPI_LOGGING_MESSAGE_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "string/string.hpp"

// namespaces
namespace bdapi   {
namespace logging {

/* logging message class declaration */

class message
{

private: // private data

	BD_IS_COPY( private, bl, fatal    );
	BD_IS_COPY( private, bl, buffered );

	BD_GET_COPY( private, s32, verbosity );

	BD_GET_COPY( private, string, function );
	BD_GET_COPY( private, string, file );

	BD_GET_COPY( private, s32, line );

	BD_GET_COPY( private, string, object  );
	BD_GET_COPY( private, string, init    );
	BD_GET_COPY( private, string, success );
	BD_GET_COPY( private, string, failure );

	BD_HAS_COPY( private, bl, failed );
	BD_HAS_COPY( private, bl, sent   );

	BD_GET_COPY( private, sys::timer*, entry_timer );

public: // public initialization functions (logging_message_init.cpp)

	message ( bl fatal, bl buffered, cstr function, cstr file, s32 line, cstr object,
	                        cstr failure );
	message ( bl fatal, bl buffered, cstr function, cstr file, s32 line, cstr object, cstr init,
	                        cstr failure );
	message ( bl fatal, bl buffered, cstr function, cstr file, s32 line, cstr object, cstr init,
		        cstr success, cstr failure );
 ~message ();

private: // private initialization functions (logging_message_init.cpp)

	void initialize ( bl fatal, bl buffered, cstr function, cstr file, s32 line, cstr object, cstr init,
	                  cstr success, cstr failure );

public: // public core functions (logging_message_core.cpp)

	result set_result ( bl     success );
	result set_result ( result success );

private: // public private functions (logging_message_core.cpp)

	result execute ();

public: // public operator functions (logging_message_oper.cpp)

	result operator  = ( bl     success );
	result operator  = ( result success );
	result operator () ( bl     success );
	result operator () ( result success );
	result operator () (                );

};

/* logging message function macro definitions */

#define LOG_MSG BD_FUNC,BD_FILE,BD_LINE

#define LOG_ERROR(AA,BB,...)       logging::message LE_##AA(true, false,LOG_MSG,BB,__VA_ARGS__)
#define LOG_WARN(AA,BB,...)        logging::message LE_##AA(false,false,LOG_MSG,BB,__VA_ARGS__)
#define LOG_WARNING(AA,BB,...)     logging::message LE_##AA(false,false,LOG_MSG,BB,__VA_ARGS__)
#define LOG_ERROR_BUF(AA,BB,...)   logging::message LE_##AA(true, true, LOG_MSG,BB,__VA_ARGS__)
#define LOG_WARN_BUF(AA,BB,...)    logging::message LE_##AA(false,true, LOG_MSG,BB,__VA_ARGS__)
#define LOG_WARNING_BUF(AA,BB,...) logging::message LE_##AA(false,true, LOG_MSG,BB,__VA_ARGS__)

#define LOG_RECEIVE(AA,...) LE_##AA=__VA_ARGS__;if(!LE_##AA())
#define LOG_RETURN(AA,...)  LE_##AA=__VA_ARGS__;if(!LE_##AA()&&LE_##AA.is_fatal())return 0
#define LOG_FAIL(AA)        LE_##AA=false
#define LOG_SEND(AA)        LE_##AA=true

#define LOG_FAILED(AA)     (!LE_##AA())
#define LOG_FAILURE(AA)    (!LE_##AA())
#define LOG_SUCCESS(AA)    ( LE_##AA())
#define LOG_SUCCEEDED(AA)  ( LE_##AA())
#define LOG_SUCCESSFUL(AA) ( LE_##AA())

#define IF_FAIL(AA)       if(!LE_##AA())
#define IF_FAILED(AA)     if(!LE_##AA())
#define IF_SUCCEEDED(AA)  if( LE_##AA())
#define IF_SUCCESS(AA)    if( LE_##AA())
#define IF_SUCCESSFUL(AA) if( LE_##AA())

#define LOG_ERROR_1(AA,BB,...)       {LOG_ERROR(LE,AA,BB);      LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARN_1(AA,BB,...)        {LOG_WARN(LE,AA,BB);       LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARNING_1(AA,BB,...)     {LOG_WARNING(LE,AA,BB);    LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_ERROR_BUF_1(AA,BB,...)   {LOG_ERROR_BUF(LE,AA,BB);  LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARN_BUF_1(AA,BB,...)    {LOG_WARN_BUF(LE,AA,BB);   LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARNING_BUF_1(AA,BB,...) {LOG_WARNING_BUF(LE,AA,BB);LOG_RETURN(LE,__VA_ARGS__);}

#define LOG_ERROR_2(AA,BB,CC,...)       {LOG_ERROR(LE,AA,BB,CC);      LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARN_2(AA,BB,CC,...)        {LOG_WARN(LE,AA,BB,CC);       LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARNING_2(AA,BB,CC,...)     {LOG_WARNING(LE,AA,BB,CC);    LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_ERROR_BUF_2(AA,BB,CC,...)   {LOG_ERROR_BUF(LE,AA,BB,CC);  LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARN_BUF_2(AA,BB,CC,...)    {LOG_WARN_BUF(LE,AA,BB,CC);   LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARNING_BUF_2(AA,BB,CC,...) {LOG_WARNING_BUF(LE,AA,BB,CC);LOG_RETURN(LE,__VA_ARGS__);}

#define LOG_ERROR_3(AA,BB,CC,DD,...)       {LOG_ERROR(LE,AA,BB,CC,DD);      LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARN_3(AA,BB,CC,DD,...)        {LOG_WARN(LE,AA,BB,CC,DD);       LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARNING_3(AA,BB,CC,DD,...)     {LOG_WARNING(LE,AA,BB,CC,DD);    LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_ERROR_BUF_3(AA,BB,CC,DD,...)   {LOG_ERROR_BUF(LE,AA,BB,CC,DD);  LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARN_BUF_3(AA,BB,CC,DD,...)    {LOG_WARN_BUF(LE,AA,BB,CC,DD);   LOG_RETURN(LE,__VA_ARGS__);}
#define LOG_WARNING_BUF_3(AA,BB,CC,DD,...) {LOG_WARNING_BUF(LE,AA,BB,CC,DD);LOG_RETURN(LE,__VA_ARGS__);}

/* end */

}
}

#endif
