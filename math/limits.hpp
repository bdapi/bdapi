
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_MATH_LIMITS_HPP
#define BDAPI_MATH_LIMITS_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "limits"

/* namespaces */
namespace bdapi {
namespace math  {

/* math limit function declarations */

template<typename T> bl has_denorm_loss   ();
template<typename T> bl has_infinity      ();
template<typename T> bl has_quiet_NaN     ();
template<typename T> bl has_signaling_NaN ();

template<typename T> bl is_bounded     ();
template<typename T> bl is_exact       ();
template<typename T> bl is_iec559      ();
template<typename T> bl is_integer     ();
template<typename T> bl is_modulo      ();
template<typename T> bl is_signed      ();
template<typename T> bl is_specialized ();

template<typename T> bl tinyness_before ();
template<typename T> bl traps           ();

template<typename T> T min ();
template<typename T> T max ();

template<typename T> T denorm_min    ();
template<typename T> T epsilon       ();
template<typename T> T infinity      ();
template<typename T> T quiet_NaN     ();
template<typename T> T round_error   ();
template<typename T> T signaling_NaN ();

template<typename T> s32 digits   ();
template<typename T> s32 digits10 ();

template<typename T> s32 min_exponent   ();
template<typename T> s32 min_exponent10 ();
template<typename T> s32 max_exponent   ();
template<typename T> s32 max_exponent10 ();

template<typename T> s32 radix ();

template<typename T> std::float_denorm_style has_denorm  ();
template<typename T> std::float_round_style  round_style ();

template<typename T> T precision ();

/* end */

}
}

#endif
