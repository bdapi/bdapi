
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_CORE_TYPEDEFS_HPP
#define BDAPI_CORE_TYPEDEFS_HPP
#include "bdapi.hpp"

/* includes */

/* namespaces */
namespace bdapi {

/* bdapi typedef declarations */

// numerical 1
typedef unsigned char          u8;
typedef unsigned short int     u16;
typedef unsigned int           u32;
typedef unsigned long long int u64;
typedef signed char            s8;
typedef signed short int       s16;
typedef signed int             s32;
typedef signed long long int   s64;
typedef float                  f32;
typedef double                 f64;

// string
typedef char         chr;
typedef const char* cstr;

// special
typedef bool           bl;
typedef signed int result;

/* bdapi enumerator declarations */

// subsystem status enumerator
enum subsys
{
	SUBSYS_UNUSED      = 0,
	SUBSYS_USED        = 1,
	SUBSYS_INITIALIZED = 2,
	SUBSYS_ACTIVE      = 3,
	SUBSYS_SUSPENDED   = 4,
	SUBSYS_SHUTDOWN    = 5
};

/* bdapi typedef macro definitions */

// numerical
#define BD_NV_0 u8
#define BD_NV_1 u16
#define BD_NV_2 u32
#define BD_NV_3 u64
#define BD_NV_4 s8
#define BD_NV_5 s16
#define BD_NV_6 s32
#define BD_NV_7 s64
#define BD_NV_8 f32
#define BD_NV_9 f64

/* end */

}

#endif
