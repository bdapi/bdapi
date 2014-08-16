
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_CONV_HPP
#define BDAPI_MATH_CONV_HPP
#include "bdapi.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace math  {

/* math conversion function declarations */

template< typename AA, typename BB > BB to   ( AA );
template< typename AA, typename BB > AA from ( BB );

template<typename T> u8  to_u8  ( T );
template<typename T> u16 to_u16 ( T );
template<typename T> u32 to_u32 ( T );
template<typename T> u64 to_u64 ( T );
template<typename T> s8  to_s8  ( T );
template<typename T> s16 to_s16 ( T );
template<typename T> s32 to_s32 ( T );
template<typename T> s64 to_s64 ( T );
template<typename T> f32 to_f32 ( T );
template<typename T> f64 to_f64 ( T );

template<typename T> T from_u8  ( u8  );
template<typename T> T from_u16 ( u16 );
template<typename T> T from_u32 ( u32 );
template<typename T> T from_u64 ( u64 );
template<typename T> T from_s8  ( s8  );
template<typename T> T from_s16 ( s16 );
template<typename T> T from_s32 ( s32 );
template<typename T> T from_s64 ( s64 );
template<typename T> T from_f32 ( f32 );
template<typename T> T from_f64 ( f64 );

// u8
u8   u8_2_u8  ( u8  );
u8  u16_2_u8  ( u16 );
u8  u32_2_u8  ( u32 );
u8  u64_2_u8  ( u64 );
u8   s8_2_u8  ( s8  );
u8  s16_2_u8  ( s16 );
u8  s32_2_u8  ( s32 );
u8  s64_2_u8  ( s64 );
u8  f32_2_u8  ( f32 );
u8  f64_2_u8  ( f64 );

// u16
u16  u8_2_u16 ( u8  );
u16 u16_2_u16 ( u16 );
u16 u32_2_u16 ( u32 );
u16 u64_2_u16 ( u64 );
u16  s8_2_u16 ( s8  );
u16 s16_2_u16 ( s16 );
u16 s32_2_u16 ( s32 );
u16 s64_2_u16 ( s64 );
u16 f32_2_u16 ( f32 );
u16 f64_2_u16 ( f64 );

// u32
u32  u8_2_u32 ( u8  );
u32 u16_2_u32 ( u16 );
u32 u32_2_u32 ( u32 );
u32 u64_2_u32 ( u64 );
u32  s8_2_u32 ( s8  );
u32 s16_2_u32 ( s16 );
u32 s32_2_u32 ( s32 );
u32 s64_2_u32 ( s64 );
u32 f32_2_u32 ( f32 );
u32 f64_2_u32 ( f64 );

// u64
u64  u8_2_u64 ( u8  );
u64 u16_2_u64 ( u16 );
u64 u32_2_u64 ( u32 );
u64 u64_2_u64 ( u64 );
u64  s8_2_u64 ( s8  );
u64 s16_2_u64 ( s16 );
u64 s32_2_u64 ( s32 );
u64 s64_2_u64 ( s64 );
u64 f32_2_u64 ( f32 );
u64 f64_2_u64 ( f64 );

// s8
s8   u8_2_s8  ( u8  );
s8  u16_2_s8  ( u16 );
s8  u32_2_s8  ( u32 );
s8  u64_2_s8  ( u64 );
s8   s8_2_s8  ( s8  );
s8  s16_2_s8  ( s16 );
s8  s32_2_s8  ( s32 );
s8  s64_2_s8  ( s64 );
s8  f32_2_s8  ( f32 );
s8  f64_2_s8  ( f64 );

// s16
s16  u8_2_s16 ( u8  );
s16 u16_2_s16 ( u16 );
s16 u32_2_s16 ( u32 );
s16 u64_2_s16 ( u64 );
s16  s8_2_s16 ( s8  );
s16 s16_2_s16 ( s16 );
s16 s32_2_s16 ( s32 );
s16 s64_2_s16 ( s64 );
s16 f32_2_s16 ( f32 );
s16 f64_2_s16 ( f64 );

// s32
s32  u8_2_s32 ( u8  );
s32 u16_2_s32 ( u16 );
s32 u32_2_s32 ( u32 );
s32 u64_2_s32 ( u64 );
s32  s8_2_s32 ( s8  );
s32 s16_2_s32 ( s16 );
s32 s32_2_s32 ( s32 );
s32 s64_2_s32 ( s64 );
s32 f32_2_s32 ( f32 );
s32 f64_2_s32 ( f64 );

// s64
s64  u8_2_s64 ( u8  );
s64 u16_2_s64 ( u16 );
s64 u32_2_s64 ( u32 );
s64 u64_2_s64 ( u64 );
s64  s8_2_s64 ( s8  );
s64 s16_2_s64 ( s16 );
s64 s32_2_s64 ( s32 );
s64 s64_2_s64 ( s64 );
s64 f32_2_s64 ( f32 );
s64 f64_2_s64 ( f64 );

// f32
f64  u8_2_f32 ( u8  );
f64 u16_2_f32 ( u16 );
f64 u32_2_f32 ( u32 );
f64 u64_2_f32 ( u64 );
f64  s8_2_f32 ( s8  );
f64 s16_2_f32 ( s16 );
f64 s32_2_f32 ( s32 );
f64 s64_2_f32 ( s64 );
f64 f32_2_f32 ( f32 );
f64 f64_2_f32 ( f64 );

// f64
f64  u8_2_f64 ( u8  );
f64 u16_2_f64 ( u16 );
f64 u32_2_f64 ( u32 );
f64 u64_2_f64 ( u64 );
f64  s8_2_f64 ( s8  );
f64 s16_2_f64 ( s16 );
f64 s32_2_f64 ( s32 );
f64 s64_2_f64 ( s64 );
f64 f32_2_f64 ( f32 );
f64 f64_2_f64 ( f64 );

/* end */

}
}

#endif
