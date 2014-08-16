
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYS_TIMER_CORE_CPP
#define BDAPI_SYS_TIMER_CORE_CPP
#include "sys/timer.hpp"

/* includes */

// bdapi
#include "string/core.hpp"

/* namespaces */
namespace bdapi {
namespace sys   {

/* timer class class core function implementations */

// private get time
f64 timer::private_get_time()
{
	return (f64)boost_timer.elapsed().wall / 1000000000.0;
}

// start timer
f64 timer::start()
{
	if( is_on() )
	{
		boost_timer.stop();
	}

	boost_timer.elapsed().clear();

	f64 old_saved_time = saved_time;

	saved_time = -1.0;

	paused = false;

	boost_timer.start();

	return old_saved_time;
}

// stop timer
f64 timer::stop()
{
	if( is_on() )
	{
		boost_timer.stop();

		paused = false;

		return save();
	}

	return -1.0;
}

// pause timer
f64 timer::pause()
{
	if( is_on() && !is_paused() )
	{
		boost_timer.stop();

		paused = true;

		return private_get_time();
	}

	return -1.0;
}

// stop timer
f64 timer::resume()
{
	if( is_off() && is_paused() )
	{
		boost_timer.resume();

		paused = false;

		return private_get_time();
	}

	return -1.0;
}

// save time
f64 timer::save()
{
	return saved_time = private_get_time();
}

// get time
f64 timer::get_time()
{
	if( is_on() )
	{
		return private_get_time();
	}
	else if( is_paused() )
	{
		return private_get_time();
	}
	else
	{
		return saved_time;
	}
}

// get stopped time
f64 timer::get_stopped() const
{
	if( is_off() && !is_paused() )
	{
		return saved_time;
	}
	else
	{
		return -1.0;
	}
}

// get elapsed time
f64 timer::get_elapsed()
{
	if( is_on() || is_paused() )
	{
		return private_get_time();
	}
	else
	{
		return -1.0;
	}
}

// get time string
string timer::get_time_string()
{
	return get_str( get_time() );
}

// get stopped string
string timer::get_stopped_string() const
{
	if( is_off() && !is_paused() )
	{
		return get_str(saved_time);
	}
	else
	{
		return "~X08.";
	}
}

// get elapsed string
string timer::get_elapsed_string()
{
	if( is_on() || is_paused() )
	{
		return get_time_string();
	}
	else
	{
		return "~X08.";
	}
}

// is on
bl timer::is_on() const
{
	return !boost_timer.is_stopped();
}

// is off
bl timer::is_off() const
{
	return boost_timer.is_stopped();
}

// is paused
bl timer::is_paused() const
{
	return paused;
}

// static get string
string timer::get_str( f64 time_number )
{
	if( time_number < 0.0 )
	{
		return "";
	}

	string time_string = str::format ( "%.3f", time_number * 1000.0   );
	       time_string = str::replace( time_string,  ".",   "~F8.~FF" );
	       time_string = str::replace( time_string,  "+",   "~F8+~FF" );
		     time_string = str::replace( time_string,  "-",   "~F8-~FF" );
		     time_string = str::replace( time_string,  "e",   "~F8e~FF" );

	return str::format( "~X08 (~FF%s ~F7ms~F8)", time_string.c_str() );
}

/* end */

}
}

#endif
