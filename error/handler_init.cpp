
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ERROR_HANDLER_INIT_CPP
#define BDAPI_ERROR_HANDLER_INIT_CPP
#define BD_DATA_ERROR
#include "error/handler.hpp"

/* includes */

// bdapi
#include "logging/message.hpp"

/* namespaces */
namespace bdapi {
namespace error {

/* static variables */

static bool handler_instance = false;

/* error handler singleton initialization function implementations */

// private initializers
result initialize( parameters* handler_parameters )
{
	LOG_ERROR_1( "~F6subsystem", "~~ has already been initialized", !handler_instance );

	handler_instance = true;

	LOG_ERROR_1( "~F6subsystem parameters", "failed to read ~~", handler_parameters );

	error::handler_parameters = handler_parameters;

	subsystem_state = SUBSYS_INITIALIZED;

	subsystem_state = SUBSYS_ACTIVE;

	return 1;
}

// private shutdown
result shutdown()
{
	subsystem_state = SUBSYS_SUSPENDED;

	subsystem_state = SUBSYS_SHUTDOWN;

	return 1;
}

/* end */

}
}

#endif
