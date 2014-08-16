
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_CORE_HPP
#define BDAPI_MATH_CORE_HPP
#include "bdapi.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace math  {

/* math core function declarations */

template<typename T> bl equals (      T b        );
template<typename T> bl equals ( T a, T b        );
template<typename T> bl equals ( T a, T b, T eps );

template<typename T> bl within  (        T val, T max );
template<typename T> bl within  ( T min, T val, T max );
template<typename T> bl with_in (        T val, T max );
template<typename T> bl with_in ( T min, T val, T max );
template<typename T> bl with_ex (        T val, T max );
template<typename T> bl with_ex ( T min, T val, T max );

template<typename T> T wrap (        T val, T max );
template<typename T> T wrap ( T min, T val, T max );

template<typename T> T wrap_index (        T val, T max );
template<typename T> T wrap_index ( T min, T val, T max );

template<typename T> T clamp (        T val, T max );
template<typename T> T clamp ( T min, T val, T max );

template<typename T> T clamp_degrees ( T degrees );
template<typename T> T clamp_radians ( T radians );

template<typename T> T lesser  ( T val, T comp );
template<typename T> T greater ( T val, T comp );

template<typename T> T nearest ( T min, T val, T max );

template<typename T> T divide ( T a, T b );

template<typename T> T diff         ( T a, T b );
template<typename T> T diff_degrees ( T a, T b );
template<typename T> T diff_radians ( T a, T b );

template<typename T> T lerp        ( T floor, T val, T ceil               );
template<typename T> T inv_lerp    ( T min,   T val, T max                );
template<typename T> T lerp_ex     ( T floor, T val, T ceil, T min, T max );
template<typename T> T inv_lerp_ex ( T floor, T val, T ceil, T min, T max );

template<typename T> T inv_sqrt ( T n );

template<typename T> T square_lesser  ( T n );
template<typename T> T square_greater ( T n );

template<typename T> T to_degrees ( T radians );
template<typename T> T to_radians ( T degress );

/* end */

}
}

#endif
