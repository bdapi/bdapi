
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_PERFORMANCE_HPP
#define BDAPI_UTIL_PERFORMANCE_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "sys/timer.hpp"

// namespaces
namespace bdapi {
namespace util  {

/* performance monitor class declaration */

class performance
{

private: // private core data

	BD_GET_REFR( private, sys::timer, performance_timer );

private: // private descriptor data

	BD_GET_COPY_INIT( private, u32, update_count, 0 );

	BD_GET_COPY_INIT( private, f64, accrued_time, 0.0 );

public: // public initialization functions (util_performance_init.cpp)

	performance () {};
	performance ( const performance& copy );
 ~performance () {};

public: // public core functions (util_performance_core.cpp)

	void start ();
	void stop  ();

public: // public query functions (util_performance_query.cpp)

	f64 get_seconds      () const;
	f64 get_milliseconds () const;
	f64 get_microseconds () const;

public: // public operator functions (util_performance_oper.cpp)

	void operator ++ ();
	void operator -- ();

	f64 operator () () const;

};

/* end */

}
}

#endif
