
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_CONV_CPP
#define BDAPI_MATH_CONV_CPP
#include "math/conv.hpp"

/* includes */

// bdapi
#include "math/limits.hpp"

/* namespaces */
namespace bdapi {
namespace math  {

/* math conversion function implementations */

// u8
u8 u8_2_u8( u8 n )
{
	return n;
}
u8 u16_2_u8( u16 n )
{
	return n >> 8;
}
u8 u32_2_u8( u32 n )
{
	return n >> 24;
}
u8 u64_2_u8( u64 n )
{
	return n >> 56;
}
u8 s8_2_u8( s8 n )
{
	return n - min<s8>();
}
u8 s16_2_u8( s16 n )
{
	return n - min<s16>() >> 8;
}
u8 s32_2_u8( s32 n )
{
	return n - min<s32>() >> 24;
}
u8 s64_2_u8( s64 n )
{
	return n - min<s64>() >> 56;
}
u8 f32_2_u8( f32 n )
{
	return n * (f64)max<u8>();
}
u8 f64_2_u8( f64 n )
{
	return f64_2_f32(n) * (f64)max<u8>();
}

// u16
u16 u8_2_u16( u8 n )
{
	return u8_2_f32(n) * (f64)max<u16>();
}
u16 u16_2_u16( u16 n )
{
	return n;
}
u16 u32_2_u16( u32 n )
{
	return n >> 16;
}
u16 u64_2_u16( u64 n )
{
	return n >> 48;
}
u16 s8_2_u16( s8 n )
{
	return s8_2_f32(n) * (f64)max<u16>();
}
u16 s16_2_u16( s16 n )
{
	return n - min<s16>();
}
u16 s32_2_u16( s32 n )
{
	return n - min<s32>() >> 16;
}
u16 s64_2_u16( s64 n )
{
	return n - min<s64>() >> 48;
}
u16 f32_2_u16( f32 n )
{
	return n * (f64)max<u16>();
}
u16 f64_2_u16( f64 n )
{
	return f64_2_f32(n) * (f64)max<u16>();
}

// u32
u32 u8_2_u32( u8 n )
{
	return u8_2_f32(n) * (f64)max<u32>();
}
u32 u16_2_u32( u16 n )
{
	return u16_2_f32(n) * (f64)max<u32>();
}
u32 u32_2_u32( u32 n )
{
	return n;
}
u32 u64_2_u32( u64 n )
{
	return n >> 32;
}
u32 s8_2_u32( s8 n )
{
	return s8_2_f32(n) * (f64)max<u32>();
}
u32 s16_2_u32( s16 n )
{
	return s16_2_f32(n) * (f64)max<u32>();
}
u32 s32_2_u32( s32 n )
{
	return n - min<s32>();
}
u32 s64_2_u32( s64 n )
{
	return n - min<s64>() >> 32;
}
u32 f32_2_u32( f32 n )
{
	return n * (f64)max<u32>();
}
u32 f64_2_u32( f64 n )
{
	return f64_2_f32(n) * (f64)max<u32>();
}

// u64
u64 u8_2_u64( u8 n )
{
	return (f64)u8_2_f32(n) * (f64)max<u64>();
}
u64 u16_2_u64( u16 n )
{
	return (f64)u16_2_f32(n) * (f64)max<u64>();
}
u64 u32_2_u64( u32 n )
{
	return (f64)u32_2_f32(n) * (f64)max<u64>();
}
u64 u64_2_u64( u64 n )
{
	return n;
}
u64 s8_2_u64( s8 n )
{
	return (f64)s8_2_f32(n) * (f64)max<u64>();
}
u64 s16_2_u64( s16 n )
{
	return (f64)s16_2_f32(n) * (f64)max<u64>();
}
u64 s32_2_u64( s32 n )
{
	return (f64)s32_2_f32(n) * (f64)max<u64>();
}
u64 s64_2_u64( s64 n )
{
	return n - min<s64>();
}
u64 f32_2_u64( f32 n )
{
	return (f64)n * (f64)max<u64>();
}
u64 f64_2_u64( f64 n )
{
	return f64_2_f32(n) * (f64)max<u64>();
}

// s8
s8 u8_2_s8( u8 n )
{
	return n - min<s8>();
}
s8 u16_2_s8( u16 n )
{
	return n - min<s16>() >> 8;
}
s8 u32_2_s8( u32 n )
{
	return n - min<s32>() >> 24;
}
s8 u64_2_s8( u64 n )
{
	return n - min<s64>() >> 56;
}
s8 s8_2_s8( s8 n )
{
	return n;
}
s8 s16_2_s8( s16 n )
{
	return n >> 8;
}
s8 s32_2_s8( s32 n )
{
	return n >> 24;
}
s8 s64_2_s8( s64 n )
{
	return n >> 56;
}
s8 f32_2_s8( f32 n )
{
	return n * (f64)max<u8>() + min<s8>();
}
s8 f64_2_s8( f64 n )
{
	return f64_2_f32(n) * (f64)max<u8>() + min<s8>();
}

// s16
s16 u8_2_s16( u8 n )
{
	return u8_2_f32(n) * (f64)max<u16>() + min<s16>();
}
s16 u16_2_s16( u16 n )
{
	return n + min<s16>();
}
s16 u32_2_s16( u32 n )
{
	return n + min<s32>() >> 16;
}
s16 u64_2_s16( u64 n )
{
	return n + min<s64>() >> 48;
}
s16 s8_2_s16( s8 n )
{
	return s8_2_f32(n) * (f64)max<u16>() + min<s16>();
}
s16 s16_2_s16( s16 n )
{
	return n;
}
s16 s32_2_s16( s32 n )
{
	return n >> 16;
}
s16 s64_2_s16( s64 n )
{
	return n >> 48;
}
s16 f32_2_s16( f32 n )
{
	return n * (f64)max<u16>() + min<s16>();
}
s16 f64_2_s16( f64 n )
{
	return f64_2_f32(n) * (f64)max<u16>() + min<s16>();
}

// s32
s32 u8_2_s32( u8 n )
{
	return u8_2_f32(n) * (f64)max<u32>() + min<s32>();
}
s32 u16_2_s32( u16 n )
{
	return u16_2_f32(n) * (f64)max<u32>() + min<s32>();
}
s32 u32_2_s32( u32 n )
{
	return n + min<s32>();
}
s32 u64_2_s32( u64 n )
{
	return n + min<s64>() >> 32;
}
s32 s8_2_s32( s8 n )
{
	return s8_2_f32(n) * (f64)max<u32>() + min<s32>();
}
s32 s16_2_s32( s16 n )
{
	return s16_2_f32(n) * (f64)max<u32>() + min<s32>();
}
s32 s32_2_s32( s32 n )
{
	return n;
}
s32 s64_2_s32( s64 n )
{
	return n >> 32;
}
s32 f32_2_s32( f32 n )
{
	return n * (f64)max<u32>() + min<s32>();
}
s32 f64_2_s32( f64 n )
{
	return f64_2_f32(n) * (f64)max<u32>() + min<s32>();
}

// s64
s64 u8_2_s64( u8 n )
{
	return u8_2_f32(n) * (f64)max<u64>() + min<s64>();
}
s64 u16_2_s64( u16 n )
{
	return u16_2_f32(n) * (f64)max<u64>() + min<s64>();
}
s64 u32_2_s64( u32 n )
{
	return u32_2_f32(n) * (f64)max<u64>() + min<s64>();
}
s64 u64_2_s64( u64 n )
{
	return n + min<s64>();
}
s64 s8_2_s64( s8 n )
{
	return s8_2_f32(n) * (f64)max<u64>() + min<s64>();
}
s64 s16_2_s64( s16 n )
{
	return s16_2_f32(n) * (f64)max<u64>() + min<s64>();
}
s64 s32_2_s64( s32 n )
{
	return s32_2_f32(n) * (f64)max<u64>() + min<s64>();
}
s64 s64_2_s64( s64 n )
{
	return n;
}
s64 f32_2_s64( f32 n )
{
	return n * (f64)max<u64>() + min<s64>();
}
s64 f64_2_s64( f64 n )
{
	return f64_2_f32(n) * (f64)max<u64>() + min<s64>();
}

// f32
f64 u8_2_f32( u8 n )
{
	return (f64)n / (f64)max<u8>();
}
f64 u16_2_f32( u16 n )
{
	return (f64)n / (f64)max<u16>();
}
f64 u32_2_f32( u32 n )
{
	return (f64)n / (f64)max<u32>();
}
f64 u64_2_f32( u64 n )
{
	return (f64)n / (f64)max<u64>();
}
f64 s8_2_f32( s8 n )
{
	return f64( u8( n + min<s8>() ) ) / (f64)max<u8>();
}
f64 s16_2_f32( s16 n )
{
	return f64( u16( n + min<s16>() ) ) / (f64)max<u16>();
}
f64 s32_2_f32( s32 n )
{
	return f64( u32( n + min<s32>() ) ) / (f64)max<u32>();
}
f64 s64_2_f32( s64 n )
{
	return f64( u64( n + min<s64>() ) ) / (f64)max<u64>();
}
f64 f32_2_f32( f32 n )
{
	return n;
}
f64 f64_2_f32( f64 n )
{
	return n * 0.5 + 0.5;
}

// f64
f64 u8_2_f64( u8 n )
{
	return u8_2_f32(n) * 2.0 - 1.0;
}
f64 u16_2_f64( u16 n )
{
	return u16_2_f32(n) * 2.0 - 1.0;
}
f64 u32_2_f64( u32 n )
{
	return u32_2_f32(n) * 2.0 - 1.0;
}
f64 u64_2_f64( u64 n )
{
	return u64_2_f32(n) * 2.0 - 1.0;
}
f64 s8_2_f64( s8 n )
{
	return s8_2_f32(n) * 2.0 - 1.0;
}
f64 s16_2_f64( s16 n )
{
	return s16_2_f32(n) * 2.0 - 1.0;
}
f64 s32_2_f64( s32 n )
{
	return s32_2_f32(n) * 2.0 - 1.0;
}
f64 s64_2_f64( s64 n )
{
	return s64_2_f32(n) * 2.0 - 1.0;
}
f64 f32_2_f64( f32 n )
{
	return n * 2.f - 1.f;
}
f64 f64_2_f64( f64 n )
{
	return n;
}

#define BD_MATH_CONV_IMPL_1(AA,BB)\
template <> BB   to_##BB( AA n ) { return AA##_2_##BB(n); } \
template <> AA from_##BB( BB n ) { return BB##_2_##AA(n); } \
template <> BB   to     ( AA n ) { return AA##_2_##BB(n); } \
template <> AA from     ( BB n ) { return BB##_2_##AA(n); } \

#define BD_MATH_CONV_IMPL_2(AA) \
BD_MATH_CONV_IMPL_1( AA, u8  ) \
BD_MATH_CONV_IMPL_1( AA, u16 ) \
BD_MATH_CONV_IMPL_1( AA, u32 ) \
BD_MATH_CONV_IMPL_1( AA, u64 ) \
BD_MATH_CONV_IMPL_1( AA, s8  ) \
BD_MATH_CONV_IMPL_1( AA, s16 ) \
BD_MATH_CONV_IMPL_1( AA, s32 ) \
BD_MATH_CONV_IMPL_1( AA, s64 ) \
BD_MATH_CONV_IMPL_1( AA, f32 ) \
BD_MATH_CONV_IMPL_1( AA, f64 ) \

BD_MATH_CONV_IMPL_2( u8  )
BD_MATH_CONV_IMPL_2( u16 )
BD_MATH_CONV_IMPL_2( u32 )
BD_MATH_CONV_IMPL_2( u64 )
BD_MATH_CONV_IMPL_2( s8  )
BD_MATH_CONV_IMPL_2( s16 )
BD_MATH_CONV_IMPL_2( s32 )
BD_MATH_CONV_IMPL_2( s64 )
BD_MATH_CONV_IMPL_2( f32 )
BD_MATH_CONV_IMPL_2( f64 )

#undef BD_MATH_CONV_IMPL_1
#undef BD_MATH_CONV_IMPL_2

/* end */

}
}

#endif
