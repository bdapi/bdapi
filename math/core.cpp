
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_CORE_CPP
#define BDAPI_MATH_CORE_CPP
#include "math/core.hpp"

/* includes */

// standard
#include "math.h"

// boost
#include "boost/algorithm/clamp.hpp"

// bdapi
#include "math/const.hpp"
#include "math/limits.hpp"

// glm
#include "glm/glm.hpp"

/* namespaces */
namespace bdapi {
namespace math  {

/* math core templated function declarations */

template<typename T> inline bl _equals (      T b        );
template<typename T> inline bl _equals ( T a, T b        );
template<typename T> inline bl _equals ( T a, T b, T eps );

template<typename T> inline bl _within  (        T val, T max );
template<typename T> inline bl _within  ( T min, T val, T max );
template<typename T> inline bl _with_in (        T val, T max );
template<typename T> inline bl _with_in ( T min, T val, T max );
template<typename T> inline bl _with_ex (        T val, T max );
template<typename T> inline bl _with_ex ( T min, T val, T max );

template<typename T> inline T _wrap (        T val, T max );
template<typename T> inline T _wrap ( T min, T val, T max );

template<typename T> inline T _wrap_index (        T val, T max );
template<typename T> inline T _wrap_index ( T min, T val, T max );

template<typename T> inline T _clamp (        T val, T max );
template<typename T> inline T _clamp ( T min, T val, T max );

template<typename T> inline T _clamp_degrees ( T degrees );
template<typename T> inline T _clamp_radians ( T radians );

template<typename T> inline T _lesser  ( T val, T comp );
template<typename T> inline T _greater ( T val, T comp );

template<typename T> inline T _nearest ( T min, T val, T max );

template<typename T> inline T _divide ( T a, T b );

template<typename T> inline T _diff         ( T a, T b );
template<typename T> inline T _diff_degrees ( T a, T b );
template<typename T> inline T _diff_radians ( T a, T b );

template<typename T> inline T _lerp        ( T floor, T val, T ceil               );
template<typename T> inline T _inv_lerp    ( T min,   T val, T max                );
template<typename T> inline T _lerp_ex     ( T floor, T val, T ceil, T min, T max );
template<typename T> inline T _inv_lerp_ex ( T floor, T val, T ceil, T min, T max );

template<typename T> inline T _inv_sqrt ( T n );

template<typename T> inline T _square_lesser  ( T n );
template<typename T> inline T _square_greater ( T n );

template<typename T> inline T _to_degrees ( T radians );
template<typename T> inline T _to_radians ( T degress );

/* math core templated function implementations */

// equals
template<typename T> inline bl _equals( T b )
{
	return _equals( (T)0, b, precision<T>() );
}
template<typename T> inline bl _equals( T a, T b )
{
	return _equals( a, b, precision<T>() );
}
template<typename T> inline bl _equals( T a, T b, T eps )
{
	return ( a + eps >= b ) && ( a - eps <= b );
}

// within
template<typename T> inline bl _within( T val, T max )
{
	return _with_in( (T)0, val, max );
}
template<typename T> inline bl _within( T min, T val, T max )
{
	return _with_in( min, val, max );
}
template<typename T> inline bl _with_in( T val, T max )
{
	return _with_in( (T)0, val, max );
}
template<typename T> inline bl _with_in( T min, T val, T max )
{
	return val >= min && val < max;
}
template<typename T> inline bl _with_ex( T val, T max )
{
	return _with_ex( (T)0, val, max );
}
template<typename T> inline bl _with_ex( T min, T val, T max )
{
	return val >= min && val <= max;
}

// wrap
template<typename T> inline T _wrap( T val, T max )
{
	return _wrap( (T)0, val, max );
}
template<typename T> inline T _wrap( T min, T val, T max )
{
	while( val < min )
	{
		val += max;
	}

	while( val >= max )
	{
		val -= max;
	}

	return val;
}

// wrap around index
template<typename T> inline T _wrap_index( T val, T max )
{
	while( val < (T)0 )
	{
		val += max;
	}

	return val % max;
}
template<typename T> inline T _wrap_index( T min, T val, T max )
{
	return _wrap_index( val - min, max - min ) + min;
}

// clamp
template<typename T> inline T _clamp( T val, T max )
{
	return boost::algorithm::clamp<T>( val, (T)0, max );
}
template<typename T> inline T _clamp( T min, T val, T max )
{
	return boost::algorithm::clamp<T>( val, min, max );
}

// clamp degrees
template<typename T> inline T _clamp_degrees( T degrees )
{
	while( degrees <= (T)-180 )
	{
		degrees += (T)360;
	}

	while( degrees >  (T) 180 )
	{
		degrees -= (T)360;
	}

	return degrees;
}

// clamp radians
template<typename T> inline T _clamp_radians( T radians )
{
	while( radians <= -pi<T>() )
	{
		radians += pi_2<T>();
	}

	while( radians >   pi<T>() )
	{
		radians -= pi_2<T>();
	}

	return radians;
}

// lesser
template<typename T> inline T _lesser( T val, T comp )
{
	if( val < comp )
	{
		return val;
	}
	else
	{
		return comp;
	}
}

// greater
template<typename T> inline T _greater( T val, T comp )
{
	if( val > comp )
	{
		return val;
	}
	else
	{
		return comp;
	}
}

// nearest
template<typename T> inline T _nearest( T min, T val, T max )
{
	if( fabs( val - min ) <= fabs( val - max ) )
	{
		return min;
	}
	else
	{
		return max;
	}
}

// divide
template<typename T> inline T _divide( T a, T b )
{
	if( _equals(b) )
	{
		return a;
	}
	else
	{
		return a / b;
	}
}

// difference
template<typename T> inline T _diff( T a, T b )
{
	return fabs( a - b );
}

// difference degrees
template<typename T> inline T _diff_degrees( T a, T b )
{
	return _clamp_degrees( glm::degrees( a - b ) );
}

// difference radians
template<typename T> inline T _diff_radians( T a, T b )
{
	return _clamp_radians( a - b );
}

// linear interpolation
template<typename T> inline T _lerp( T floor, T val, T ceil )
{
	return floor + val * ( ceil - floor );
}

// inversed linear interpolation
template<typename T> inline T _inv_lerp( T min, T val, T max )
{
	return _divide( val - min, max - min );
}

// extended linear interpolation
template<typename T> inline T _lerp_ex( T floor, T val, T ceil, T min, T max )
{
	return _inv_lerp( min, lerp( floor, val, ceil ), max );
}

// extended inversed linear interpolation
template<typename T> inline T _inv_lerp_ex( T floor, T val, T ceil, T min, T max )
{
	return _lerp( min, inv_lerp( floor, val, ceil ), max );
}

// recursive square root
template<typename T> inline T _inv_sqrt( T n )
{
	return _divide( (T)1, (T)sqrt(n) );
}

// lesser square
template<typename T> inline T _square_lesser( T n )
{
	T s = (T)2;

	while( s * (T)2 < n )
	{
		s *= (T)2;
	}

	return s;
}

// greater square
template<typename T> inline T _square_greater( T n )
{
	T s = (T)2;

	while( s < n )
	{
		s *= (T)2;
	}

	return s;
}

// to degrees
template<typename T> inline T _to_degrees( T radians )
{
	glm::degrees( radians );
}

// to radians
template<typename T> inline T _to_radians( T degress )
{
	glm::radians( degress );
}

/* math core function implementations */

#define BDT template<>

#define BD_MATH_CORE_IMPL_1(T) \
BDT bl equals ( T b ) { return _equals<T>( b ); } \
BDT bl equals ( T a, T b ) { return _equals<T>( a, b ); } \
BDT bl equals ( T a, T b, T eps ) { return _equals<T>( a, b, eps ); } \
BDT bl within ( T val, T max ) { return _within<T> ( val, max ); } \
BDT bl within ( T min, T val, T max ) { return _within<T> ( min, val, max ); } \
BDT bl with_in ( T val, T max ) { return _with_in<T> ( val, max ); } \
BDT bl with_in ( T min, T val, T max ) { return _with_in<T> ( min, val, max ); } \
BDT bl with_ex ( T val, T max ) { return _with_ex<T> ( val, max ); } \
BDT bl with_ex ( T min, T val, T max ) { return _with_ex<T> ( min, val, max ); } \
BDT T wrap ( T val, T max ) { return _wrap<T> ( val, max ); } \
BDT T wrap ( T min, T val, T max ) { return _wrap<T> ( min, val, max ); } \
BDT T clamp ( T val, T max ) { return _clamp<T> ( val, max ); } \
BDT T clamp ( T min, T val, T max ) { return _clamp<T> ( min, val, max ); } \
BDT T lesser ( T val, T comp ) { return _lesser<T> ( val, comp ); } \
BDT T greater ( T val, T comp ) { return _greater<T> ( val, comp ); } \
BDT T nearest ( T min, T val, T max ) { return _nearest<T> ( min, val, max ); } \
BDT T divide ( T a, T b ) { return _divide<T> ( a, b ); } \
BDT T diff ( T a, T b ) { return _diff<T> ( a, b ); } \
BDT T lerp ( T floor, T val, T ceil ) { return _lerp<T> ( floor, val, ceil ); } \
BDT T inv_lerp ( T min, T val, T max ) { return _inv_lerp<T> ( min, val, max ); } \
BDT T lerp_ex ( T floor, T val, T ceil, T min, T max ) \
{ return _lerp_ex<T> ( floor, val, ceil, min, max ); } \
BDT T inv_lerp_ex ( T floor, T val, T ceil, T min, T max ) \
{ return _inv_lerp_ex<T> ( floor, val, ceil, min, max ); } \
BDT T inv_sqrt ( T n ) { return _inv_sqrt<T> (n); } \
BDT T square_lesser ( T n ) { return _square_lesser<T> (n); } \
BDT T square_greater ( T n ) { return _square_greater<T> (n); } \

#define BD_MATH_CORE_IMPL_2(T) \
BDT T wrap_index ( T val, T max ) { return _wrap_index<T> ( val, max ); } \
BDT T wrap_index ( T min, T val, T max ) { return _wrap_index<T> ( min, val, max ); } \

#define BD_MATH_CORE_IMPL_3(T) \
BDT T clamp_degrees ( T degrees ) { return _clamp_degrees<T> ( degrees ); } \
BDT T clamp_radians ( T radians ) { return _clamp_radians<T> ( radians ); } \
BDT T diff_degrees ( T a, T b ) { return _diff_degrees<T> ( a, b ); } \
BDT T diff_radians ( T a, T b ) { return _diff_radians<T> ( a, b ); } \
BDT T to_degrees ( T radians ) { return _to_degrees<T> (radians); } \
BDT T to_radians ( T degress ) { return _to_radians<T> (degress); } \

BD_MATH_CORE_IMPL_1( u8  )
BD_MATH_CORE_IMPL_1( u16 )
BD_MATH_CORE_IMPL_1( u32 )
BD_MATH_CORE_IMPL_1( u64 )
BD_MATH_CORE_IMPL_1( s8  )
BD_MATH_CORE_IMPL_1( s16 )
BD_MATH_CORE_IMPL_1( s32 )
BD_MATH_CORE_IMPL_1( s64 )
BD_MATH_CORE_IMPL_1( f32 )
BD_MATH_CORE_IMPL_1( f64 )

BD_MATH_CORE_IMPL_2( u8  )
BD_MATH_CORE_IMPL_2( u16 )
BD_MATH_CORE_IMPL_2( u32 )
BD_MATH_CORE_IMPL_2( u64 )
BD_MATH_CORE_IMPL_2( s8  )
BD_MATH_CORE_IMPL_2( s16 )
BD_MATH_CORE_IMPL_2( s32 )
BD_MATH_CORE_IMPL_2( s64 )

BD_MATH_CORE_IMPL_3( f32 )
BD_MATH_CORE_IMPL_3( f64 )

#undef BDT
#undef BD_MATH_CORE_IMPL_1
#undef BD_MATH_CORE_IMPL_2
#undef BD_MATH_CORE_IMPL_3

/* end */

}
}

#endif
