
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_FUNCTIONS_HPP
#define BDAPI_VIDEO_FUNCTIONS_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "io/path.hpp"
#include "video/color.hpp"

// namespaces
namespace bdapi {
namespace video {

/* video function declaration */

// initialization functions (video_functions_init.cpp)
result init_magick ();

// io functions (video_functions_io.cpp)
video::raw* load_from_native_file ( const io::path filename );

/* end */

}
}

#endif
