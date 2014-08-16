
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_STATEHANDLER_HPP
#define BDAPI_UTIL_STATEHANDLER_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "deque"

// bdapi
#include "util/container.hpp"
#include "util/state.hpp"

/* namespaces */
namespace bdapi {
namespace util  {

/* state handler singleton declaration */

class statehandler
{

private: // private data

	util::container< state*, std::deque > states;

	BD_GET_COPY( private, state*, current_state );

public: // public initialization functions (util_statehandler_init.cpp)

	statehandler () {};
	statehandler ( state* initial_state     );
	statehandler ( const statehandler& copy );
 ~statehandler () {};

	result initialize ( state* initial_state     );
	result initialize ( const statehandler& copy );

public: // public core functions (util_statehandler_core.cpp)

	result do_initialize ();
	result do_resume     ();
	result do_iterate    ();
	result do_suspend    ();
	result do_kill       ();

	result change_state ( state* new_state );
	result end_state    (                  );

public: // public query functions (util_statehandler_query.cpp)

	string get_name (       ) const;
	string get_name ( s32 i ) const;

	s64 get_initialize_count (       ) const;
	s64 get_initialize_count ( s32 i ) const;
	s64 get_resume_count     (       ) const;
	s64 get_resume_count     ( s32 i ) const;
	s64 get_iterate_count    (       ) const;
	s64 get_iterate_count    ( s32 i ) const;
	s64 get_suspend_count    (       ) const;
	s64 get_suspend_count    ( s32 i ) const;
	s64 get_kill_count       (       ) const;
	s64 get_kill_count       ( s32 i ) const;

	s32 get_size () const;

	bl is_initialized (       ) const;
	bl is_initialized ( s32 i ) const;
	bl is_active      (       ) const;
	bl is_active      ( s32 i ) const;

	bl is_empty () const;
};

/* end */

}
}

#endif
