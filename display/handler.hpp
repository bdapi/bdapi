
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_DISPLAY_HANDLER_HPP
#define BDAPI_DISPLAY_HANDLER_HPP
#include "bdapi.hpp"

/* includes */

/* namespaces */
namespace bdapi   {
namespace display {

/* display handler parameters struct declaration */

struct parameters
{
};

/* display handler singleton declaration */

#ifdef  BD_DATA_DISPLAY
#define BD_DATA_EXTERN
#endif
#include "core/local_open.hpp"

// initialization data

BD_DATA_GET_COPY_INIT_SET( subsys, subsystem_state, SUBSYS_UNUSED );

BD_DATA_GET_COPY_INIT( parameters*, handler_parameters, NULL );

// core data

BD_DATA_GET_COPY( s32, monitor_amount );

BD_DATA_GET_COPY_INIT( display::monitor*, monitors, NULL ); // internal

// reflection data

BD_DATA_GET_COPY_INIT( display::monitor*, primary_monitor, NULL );

BD_DATA_GET_COPY( s32, width  );
BD_DATA_GET_COPY( s32, height );

BD_DATA_GET_COPY( f32, aspect_ratio );

BD_DATA_GET_COPY( s32, refresh_rate );
BD_DATA_GET_COPY( s32, pixel_format );

// initialization functions (display_handler_init.cpp)

result initialize ( parameters* handler_parameters );
result shutdown   ();

result init_sdl         ();
result init_monitors    ();
result init_diagnostics ();

// core functions (display_handler_core.cpp)

result refresh ();

// query functions (display_handler_query.cpp)

display::monitor* get_monitor ( s32 i );

#include "core/local_close.hpp"

/* display handling function macro definitions */

#define USING_DISPLAY ( display::get_subsystem_state() != SUBSYS_UNUSED )

/* end */

}
}

#endif
