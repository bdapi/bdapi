
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_TIMER_HPP
#define BDAPI_SYS_TIMER_HPP
#include "bdapi.hpp"

/* includes */

// boost
#include "boost/timer/timer.hpp"

// bdapi
#include "string/string.hpp"

/* namespaces */
namespace bdapi {
namespace sys   {

/* timer class declaration */

class timer
{

private: // private data

	boost::timer::cpu_timer boost_timer;

	f64 saved_time = -1.0;

	bl paused;

private: // private core functions (util_timer_core.cpp)

	f64 private_get_time ();

public: // public initialization functions (util_timer_init.cpp)

	timer () {};
	timer ( const timer& copy );
 ~timer () {};

public: // public core functions (util_timer_core.cpp)

	f64 start  ();
	f64 stop   ();
	f64 pause  ();
	f64 resume ();
	f64 save   ();

	f64 get_time    ();
	f64 get_stopped () const;
	f64 get_elapsed ();

	string get_time_string    ();
	string get_stopped_string () const;
	string get_elapsed_string ();

	bl is_on     () const;
	bl is_off    () const;
	bl is_paused () const;

public: // public static core functions (util_timer_core.cpp)

	static string get_str ( f64 time_number );

};

/* end */

}
}

#endif
