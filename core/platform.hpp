
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_CORE_PLATFORM_HPP
#define BDAPI_CORE_PLATFORM_HPP
#include "bdapi.hpp"

/* includes */

#if WIN

#undef MOUSE_MOVED
#undef ERROR

#include "windows.h"
#include "commctrl.h"

#undef MOUSE_MOVED
#undef ERROR

#elif MAC
#warning "Macintosh platform headers unspecified."
#elif NIX
#warning "Unix platform headers unspecified."
#elif PS4
#warning "PlayStation 4 platform headers unspecified."
#elif XBO
#warning "Xbox One platform headers unspecified."
#elif WII
#warning "Wii platform headers unspecified."
#endif

/* platform specific snippets */

#if 0

#if WIN
#warning "Windows XXXXXXXX unspecified."
#elif MAC
#warning "Macintosh XXXXXXXX unspecified."
#elif NIX
#warning "Unix XXXXXXXX unspecified."
#elif PS4
#warning "PlayStation 4 XXXXXXXX unspecified."
#elif XBO
#warning "Xbox One XXXXXXXX unspecified."
#elif WII
#warning "Wii XXXXXXXX unspecified."
#endif

#endif

/* end */

#endif
