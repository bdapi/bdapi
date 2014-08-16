
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_LIMITS_CPP
#define BDAPI_MATH_LIMITS_CPP
#include "math/limits.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace math  {

/* math limit function implementations */

#define BD_MATH_LIMITS_IMPL_1(AA,BB,CC) \
template<> BB CC<AA>() { return std::numeric_limits<AA>::CC; } \

#define BD_MATH_LIMITS_IMPL_2(AA,BB,CC) \
template<> BB CC<AA>() { return std::numeric_limits<AA>::CC(); } \

#define BD_MATH_LIMITS_IMPL_3(AA) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      has_denorm_loss   ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      has_infinity      ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      has_quiet_NaN     ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      has_signaling_NaN ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      is_bounded        ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      is_exact          ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      is_iec559         ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      is_integer        ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      is_modulo         ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      is_signed         ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      is_specialized    ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      tinyness_before   ) \
BD_MATH_LIMITS_IMPL_1( AA, bl,                      traps             ) \
BD_MATH_LIMITS_IMPL_2( AA, AA,                      min               ) \
BD_MATH_LIMITS_IMPL_2( AA, AA,                      max               ) \
BD_MATH_LIMITS_IMPL_2( AA, AA,                      denorm_min        ) \
BD_MATH_LIMITS_IMPL_2( AA, AA,                      epsilon           ) \
BD_MATH_LIMITS_IMPL_2( AA, AA,                      infinity          ) \
BD_MATH_LIMITS_IMPL_2( AA, AA,                      quiet_NaN         ) \
BD_MATH_LIMITS_IMPL_2( AA, AA,                      round_error       ) \
BD_MATH_LIMITS_IMPL_2( AA, AA,                      signaling_NaN     ) \
BD_MATH_LIMITS_IMPL_1( AA, s32,                     digits            ) \
BD_MATH_LIMITS_IMPL_1( AA, s32,                     digits10          ) \
BD_MATH_LIMITS_IMPL_1( AA, s32,                     min_exponent      ) \
BD_MATH_LIMITS_IMPL_1( AA, s32,                     min_exponent10    ) \
BD_MATH_LIMITS_IMPL_1( AA, s32,                     max_exponent      ) \
BD_MATH_LIMITS_IMPL_1( AA, s32,                     max_exponent10    ) \
BD_MATH_LIMITS_IMPL_1( AA, s32,                     radix             ) \
BD_MATH_LIMITS_IMPL_1( AA, std::float_denorm_style, has_denorm        ) \
BD_MATH_LIMITS_IMPL_1( AA, std::float_round_style,  round_style       ) \

BD_MATH_LIMITS_IMPL_3( u8  )
BD_MATH_LIMITS_IMPL_3( u16 )
BD_MATH_LIMITS_IMPL_3( u32 )
BD_MATH_LIMITS_IMPL_3( u64 )
BD_MATH_LIMITS_IMPL_3( s8  )
BD_MATH_LIMITS_IMPL_3( s16 )
BD_MATH_LIMITS_IMPL_3( s32 )
BD_MATH_LIMITS_IMPL_3( s64 )
BD_MATH_LIMITS_IMPL_3( f32 )
BD_MATH_LIMITS_IMPL_3( f64 )

#define BD_MATH_LIMITS_IMPL_4(AA,BB) \
template<> AA precision() { return BB; } \

BD_MATH_LIMITS_IMPL_4( u8,  0          )
BD_MATH_LIMITS_IMPL_4( u16, 0          )
BD_MATH_LIMITS_IMPL_4( u32, 0          )
BD_MATH_LIMITS_IMPL_4( u64, 0          )
BD_MATH_LIMITS_IMPL_4( s8,  0          )
BD_MATH_LIMITS_IMPL_4( s16, 0          )
BD_MATH_LIMITS_IMPL_4( s32, 0          )
BD_MATH_LIMITS_IMPL_4( s64, 0          )
BD_MATH_LIMITS_IMPL_4( f32, 0.000001f  )
BD_MATH_LIMITS_IMPL_4( f64, 0.00000001 )

#undef BD_MATH_LIMITS_IMPL_1
#undef BD_MATH_LIMITS_IMPL_2
#undef BD_MATH_LIMITS_IMPL_3
#undef BD_MATH_LIMITS_IMPL_4

/* end */

}
}

#endif
