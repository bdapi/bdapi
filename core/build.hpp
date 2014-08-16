
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_CORE_BUILD_HPP
#define BDAPI_CORE_BUILD_HPP
#include "bdapi.hpp"

/* bdapi build configuration macro definitions */

// build type macro definitions
#define DEBUG    (  defined (_DEBUG) || defined (BUILD_DEBUG)   )
#define RELEASE_ ( !defined (_DEBUG) || defined (BUILD_RELEASE) )

// build type check
#if !DEBUG && !RELEASE_
#error "No build type defined at compile time."
#endif

// windows macro definition
#ifdef _WIN32
#ifndef WINVER
#define WINVER 0x0502
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0502
#endif
#ifndef _WIN32_IE
#define _WIN32_IE 0x0600
#endif
#define BUILD_WINDOWS
#define WIN 1
#else
#define WIN 0
#endif

// macintosh macro definition
#ifdef __MACH__
#define BUILD_MACINTOSH
#define MAC 1
#else
#define MAC 0
#endif

// unix macro definition
#ifdef __linux__
#define BUILD_LINUX
#define NIX 1
#else
#define NIX 0
#endif

// ps4 macro definition
#ifdef __PS4__
#define BUILD_PS4
#define PS4 1
#else
#define PS4 0
#endif

// xbox one macro definition
#ifdef __XBONE__
#define BUILD_XBONE
#define XBO 1
#else
#define XBO 0
#endif

// wii macro definition
#ifdef __WII__
#define BUILD_WII
#define WII 1
#else
#define WII 0
#endif

// pc macro definition
#if defined (BUILD_WINDOWS) || defined (BUILD_MACINTOSH) || defined (BUILD_LINUX)
#define BUILD_PC
#define PC 1
#else
#define PC 0
#endif

// console macro definition
#if defined (BUILD_PS4) || defined (BUILD_XBONE) || defined (BUILD_WII)
#define BUILD_CONSOLE
#define CONSOLE 1
#else
#define CONSOLE 0
#endif

/* end */

#endif
