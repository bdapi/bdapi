
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_CONST_CPP
#define BDAPI_MATH_CONST_CPP
#include "math/const.hpp"

/* includes */

// standard
#include "climits"

/* namespaces */
namespace bdapi {
namespace math  {

/* math const constant variable declarations */

// f64

const f64 f64_u8_0        =             0.0;
const f64 f64_u8_1        =       UCHAR_MAX;
const f64 f64_u8_2        =  f64_u8_1 + 1.0;

const f64 f64_u16_0       =             0.0;
const f64 f64_u16_1       =       USHRT_MAX;
const f64 f64_u16_2       = f64_u16_1 + 1.0;

const f64 f64_u32_0       =             0.0;
const f64 f64_u32_1       =       ULONG_MAX;
const f64 f64_u32_2       = f64_u32_1 + 1.0;

const f64 f64_u64_0       =             0.0;
const f64 f64_u64_1       =      ULLONG_MAX;
const f64 f64_u64_2       = f64_u64_1 + 1.0;

const f64 f64_s8_0        =       SCHAR_MIN;
const f64 f64_s8_1        =       SCHAR_MAX;
const f64 f64_s8_2        =  f64_s8_1 + 1.0;

const f64 f64_s16_0       =        SHRT_MIN;
const f64 f64_s16_1       =        SHRT_MAX;
const f64 f64_s16_2       = f64_s16_1 + 1.0;

const f64 f64_s32_0       =        LONG_MIN;
const f64 f64_s32_1       =        LONG_MAX;
const f64 f64_s32_2       = f64_s32_1 + 1.0;

const f64 f64_s64_0       =       LLONG_MIN;
const f64 f64_s64_1       =       LLONG_MAX;
const f64 f64_s64_2       = f64_s64_1 + 1.0;

const f64 f64_f32_0       =            -1.0;
const f64 f64_f32_1       =             0.0;
const f64 f64_f32_2       =             1.0;

const f64 f64_f64_0       =            -1.0;
const f64 f64_f64_1       =             0.0;
const f64 f64_f64_2       =             1.0;

const f64 f64_root_2      = 1.41421356237309504880168872420969807856967187538L;
const f64 f64_inv_root_2  = 2.0L - f64_root_2;

const f64 f64_pi          = 3.14159265358979323846264338327950288419716939938L;
const f64 f64_pi_025      = f64_pi * 0.25L;
const f64 f64_pi_05       = f64_pi * 0.50L;
const f64 f64_pi_075      = f64_pi * 0.75L;
const f64 f64_pi_15       = f64_pi * 1.50L;
const f64 f64_pi_2        = f64_pi * 2.00L;
const f64 f64_rec_pi      =   1.0L / f64_pi;

const f64 f64_degrees     =               360.00L;
const f64 f64_degrees_025 = f64_degrees *   0.25L;
const f64 f64_degrees_05  = f64_degrees *   0.50L;
const f64 f64_degrees_075 = f64_degrees *   0.75L;
const f64 f64_degrees_15  = f64_degrees *   1.50L;
const f64 f64_degrees_2   = f64_degrees *   2.00L;

const f64 f64_radians     = f64_pi_2;
const f64 f64_radians_025 = f64_radians *   0.25L;
const f64 f64_radians_05  = f64_radians *   0.50L;
const f64 f64_radians_075 = f64_radians *   0.75L;
const f64 f64_radians_15  = f64_radians *   1.50L;
const f64 f64_radians_2   = f64_radians *   2.00L;

// f32

const f32 f32_u8_0        = f64_u8_0;
const f32 f32_u8_1        = f64_u8_1;
const f32 f32_u8_2        = f64_u8_2;

const f32 f32_u16_0       = f64_u16_0;
const f32 f32_u16_1       = f64_u16_1;
const f32 f32_u16_2       = f64_u16_2;

const f32 f32_u32_0       = f64_u32_0;
const f32 f32_u32_1       = f64_u32_1;
const f32 f32_u32_2       = f64_u32_2;

const f32 f32_u64_0       = f64_u64_0;
const f32 f32_u64_1       = f64_u64_1;
const f32 f32_u64_2       = f64_u64_2;

const f32 f32_s8_0        = f64_s8_0;
const f32 f32_s8_1        = f64_s8_1;
const f32 f32_s8_2        = f64_s8_2;

const f32 f32_s16_0       = f64_s16_0;
const f32 f32_s16_1       = f64_s16_1;
const f32 f32_s16_2       = f64_s16_2;

const f32 f32_s32_0       = f64_s32_0;
const f32 f32_s32_1       = f64_s32_1;
const f32 f32_s32_2       = f64_s32_2;

const f32 f32_s64_0       = f64_s64_0;
const f32 f32_s64_1       = f64_s64_1;
const f32 f32_s64_2       = f64_s64_2;

const f32 f32_f32_0       = f64_f32_0;
const f32 f32_f32_1       = f64_f32_1;
const f32 f32_f32_2       = f64_f32_2;

const f32 f32_f64_0       = f64_f64_0;
const f32 f32_f64_1       = f64_f64_1;
const f32 f32_f64_2       = f64_f64_2;

const f32 f32_root_2      = f64_root_2;
const f32 f32_inv_root_2  = f64_inv_root_2;

const f32 f32_pi          = f64_pi;
const f32 f32_pi_025      = f64_pi_025;
const f32 f32_pi_05       = f64_pi_05;
const f32 f32_pi_075      = f64_pi_075;
const f32 f32_pi_15       = f64_pi_15;
const f32 f32_pi_2        = f64_pi_2;
const f32 f32_rec_pi      = f64_rec_pi;

const f32 f32_degrees     = f64_degrees;
const f32 f32_degrees_025 = f64_degrees_025;
const f32 f32_degrees_05  = f64_degrees_05;
const f32 f32_degrees_075 = f64_degrees_075;
const f32 f32_degrees_15  = f64_degrees_15;
const f32 f32_degrees_2   = f64_degrees_2;

const f32 f32_radians     = f64_radians;
const f32 f32_radians_025 = f64_radians_025;
const f32 f32_radians_05  = f64_radians_05;
const f32 f32_radians_075 = f64_radians_075;
const f32 f32_radians_15  = f64_radians_15;
const f32 f32_radians_2   = f64_radians_2;

/* math constants function implementations */

#define BD_MATH_CONST_IMPL_1(AA,BB) \
template<> AA BB() { return AA##_##BB; } \

#define BD_MATH_CONST_IMPL_2(AA) \
BD_MATH_CONST_IMPL_1( AA, u8_0        ) \
BD_MATH_CONST_IMPL_1( AA, u8_1        ) \
BD_MATH_CONST_IMPL_1( AA, u8_2        ) \
BD_MATH_CONST_IMPL_1( AA, u16_0       ) \
BD_MATH_CONST_IMPL_1( AA, u16_1       ) \
BD_MATH_CONST_IMPL_1( AA, u16_2       ) \
BD_MATH_CONST_IMPL_1( AA, u32_0       ) \
BD_MATH_CONST_IMPL_1( AA, u32_1       ) \
BD_MATH_CONST_IMPL_1( AA, u32_2       ) \
BD_MATH_CONST_IMPL_1( AA, u64_0       ) \
BD_MATH_CONST_IMPL_1( AA, u64_1       ) \
BD_MATH_CONST_IMPL_1( AA, u64_2       ) \
BD_MATH_CONST_IMPL_1( AA, s8_0        ) \
BD_MATH_CONST_IMPL_1( AA, s8_1        ) \
BD_MATH_CONST_IMPL_1( AA, s8_2        ) \
BD_MATH_CONST_IMPL_1( AA, s16_0       ) \
BD_MATH_CONST_IMPL_1( AA, s16_1       ) \
BD_MATH_CONST_IMPL_1( AA, s16_2       ) \
BD_MATH_CONST_IMPL_1( AA, s32_0       ) \
BD_MATH_CONST_IMPL_1( AA, s32_1       ) \
BD_MATH_CONST_IMPL_1( AA, s32_2       ) \
BD_MATH_CONST_IMPL_1( AA, s64_0       ) \
BD_MATH_CONST_IMPL_1( AA, s64_1       ) \
BD_MATH_CONST_IMPL_1( AA, s64_2       ) \
BD_MATH_CONST_IMPL_1( AA, f32_0       ) \
BD_MATH_CONST_IMPL_1( AA, f32_1       ) \
BD_MATH_CONST_IMPL_1( AA, f32_2       ) \
BD_MATH_CONST_IMPL_1( AA, f64_0       ) \
BD_MATH_CONST_IMPL_1( AA, f64_1       ) \
BD_MATH_CONST_IMPL_1( AA, f64_2       ) \
BD_MATH_CONST_IMPL_1( AA, root_2      ) \
BD_MATH_CONST_IMPL_1( AA, inv_root_2  ) \
BD_MATH_CONST_IMPL_1( AA, pi          ) \
BD_MATH_CONST_IMPL_1( AA, pi_025      ) \
BD_MATH_CONST_IMPL_1( AA, pi_05       ) \
BD_MATH_CONST_IMPL_1( AA, pi_075      ) \
BD_MATH_CONST_IMPL_1( AA, pi_15       ) \
BD_MATH_CONST_IMPL_1( AA, pi_2        ) \
BD_MATH_CONST_IMPL_1( AA, rec_pi      ) \
BD_MATH_CONST_IMPL_1( AA, degrees     ) \
BD_MATH_CONST_IMPL_1( AA, degrees_025 ) \
BD_MATH_CONST_IMPL_1( AA, degrees_05  ) \
BD_MATH_CONST_IMPL_1( AA, degrees_075 ) \
BD_MATH_CONST_IMPL_1( AA, degrees_15  ) \
BD_MATH_CONST_IMPL_1( AA, degrees_2   ) \
BD_MATH_CONST_IMPL_1( AA, radians     ) \
BD_MATH_CONST_IMPL_1( AA, radians_025 ) \
BD_MATH_CONST_IMPL_1( AA, radians_05  ) \
BD_MATH_CONST_IMPL_1( AA, radians_075 ) \
BD_MATH_CONST_IMPL_1( AA, radians_15  ) \
BD_MATH_CONST_IMPL_1( AA, radians_2   ) \

BD_MATH_CONST_IMPL_2(f32)
BD_MATH_CONST_IMPL_2(f64)

#undef BD_MATH_CONST_IMPL_1
#undef BD_MATH_CONST_IMPL_2

/* end */

}
}

#endif
