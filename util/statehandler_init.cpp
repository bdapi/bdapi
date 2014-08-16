
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_STATEHANDLER_INIT_CPP
#define BDAPI_UTIL_STATEHANDLER_INIT_CPP
#include "util/statehandler.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"

/* namespaces */
namespace bdapi {
namespace util  {

/* state handler singleton initialization function implementations */

// constructors
statehandler::statehandler( state* initial_state )
{
	initialize( initial_state );
}
statehandler::statehandler( const statehandler& copy )
{
	initialize( copy );
}

// initializers
result statehandler::initialize( state* initial_state )
{
	if( !initial_state )
	{
		WRITE_ERROR( "Initial state has not been allocated" );

		return 0;
	}

	states.insert( initial_state );

	current_state = states.get_back();

	return 1;
}
result statehandler::initialize( const statehandler& copy )
{
	states = copy.states;

	current_state = copy.current_state;

	return 1;
}

/* end */

}
}

#endif
