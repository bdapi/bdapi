
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_GAMEPAD_HANDLER_HPP
#define BDAPI_GAMEPAD_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

/* namespaces */
namespace bdapi   {
namespace gamepad {

/* gamepad handler parameters struct declaration */

struct parameters
{

};

/* gamepad handler singleton declaration */

#ifdef  BD_DATA_GAMEPAD
#define BD_DATA_EXTERN
#endif
#include "core/local_open.hpp"

// initialization data

BD_DATA_GET_COPY_INIT_SET( subsys, subsystem_state, SUBSYS_UNUSED );

BD_DATA_GET_COPY_INIT( parameters*, handler_parameters, NULL );

// initialization functions (gamepad_handler_init.cpp)

result initialize ( parameters* handler_parameters );
result shutdown   ();

// iteration functions (gamepad_handler_iterate.cpp)

result frame_begin  ();
result frame_finish ();

#include "core/local_close.hpp"

/* gamepad handling function macro definitions */

#define USING_GAMEPAD ( gamepad::get_subsystem_state() != SUBSYS_UNUSED )

/* end */

}
}

#endif
