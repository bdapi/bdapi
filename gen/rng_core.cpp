
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_GEN_RNG_CORE_CPP
#define BDAPI_GEN_RNG_CORE_CPP
#include "gen/rng.hpp"

/* includes */

// bdapi
#include "gen/distribution.hpp"
#include "math/const.hpp"

/* namespaces */
namespace bdapi {
namespace gen   {

/* static variable declarations */

static distribution def_dist;

/* random number generator class core function implementations */

// generate u8
template<> u8 rng::get()
{
	return def_dist( &engine ) * math::u8_2<f64>();
}
template<> u8 rng::get( u8 max )
{
	return def_dist( &engine ) * (f64)max;
}
template<> u8 rng::get( u8 min, u8 max )
{
	return def_dist( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}
template<> u8 rng::get( distribution* distributor )
{
	return distributor->dist_func( &engine ) * math::u8_2<f64>();
}
template<> u8 rng::get( distribution* distributor, u8 max )
{
	return distributor->dist_func( &engine ) * (f64)max;
}
template<> u8 rng::get( distribution* distributor, u8 min, u8 max )
{
	return distributor->dist_func( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}

// generate u16
template<> u16 rng::get()
{
	return def_dist( &engine ) * math::u16_2<f64>();
}
template<> u16 rng::get( u16 max )
{
	return def_dist( &engine ) * (f64)max;
}
template<> u16 rng::get( u16 min, u16 max )
{
	return def_dist( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}
template<> u16 rng::get( distribution* distributor )
{
	return distributor->dist_func( &engine ) * math::u16_2<f64>();
}
template<> u16 rng::get( distribution* distributor, u16 max )
{
	return distributor->dist_func( &engine ) * (f64)max;
}
template<> u16 rng::get( distribution* distributor, u16 min, u16 max )
{
	return distributor->dist_func( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}

// generate u32
template<> u32 rng::get()
{
	return def_dist( &engine ) * math::u32_2<f64>();
}
template<> u32 rng::get( u32 max )
{
	return def_dist( &engine ) * (f64)max;
}
template<> u32 rng::get( u32 min, u32 max )
{
	return def_dist( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}
template<> u32 rng::get( distribution* distributor )
{
	return distributor->dist_func( &engine ) * math::u32_2<f64>();
}
template<> u32 rng::get( distribution* distributor, u32 max )
{
	return distributor->dist_func( &engine ) * (f64)max;
}
template<> u32 rng::get( distribution* distributor, u32 min, u32 max )
{
	return distributor->dist_func( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}

// generate u64
template<> u64 rng::get()
{
	return def_dist( &engine ) * math::u64_2<f64>();
}
template<> u64 rng::get( u64 max )
{
	return def_dist( &engine ) * (f64)max;
}
template<> u64 rng::get( u64 min, u64 max )
{
	return def_dist( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}
template<> u64 rng::get( distribution* distributor )
{
	return distributor->dist_func( &engine ) * math::u64_2<f64>();
}
template<> u64 rng::get( distribution* distributor, u64 max )
{
	return distributor->dist_func( &engine ) * (f64)max;
}
template<> u64 rng::get( distribution* distributor, u64 min, u64 max )
{
	return distributor->dist_func( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}

// generate s8
template<> s8 rng::get()
{
	return math::s8_0<f64>() + def_dist( &engine ) * math::u8_2<f64>();
}
template<> s8 rng::get( s8 max )
{
	return def_dist( &engine ) * (f64)max;
}
template<> s8 rng::get( s8 min, s8 max )
{
	return def_dist( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}
template<> s8 rng::get( distribution* distributor )
{
	return math::s8_0<f64>() + distributor->dist_func( &engine ) * math::u8_2<f64>();
}
template<> s8 rng::get( distribution* distributor, s8 max )
{
	return distributor->dist_func( &engine ) * (f64)max;
}
template<> s8 rng::get( distribution* distributor, s8 min, s8 max )
{
	return distributor->dist_func( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}

// generate s16
template<> s16 rng::get()
{
	return math::s16_0<f64>() + def_dist( &engine ) * math::u16_2<f64>();
}
template<> s16 rng::get( s16 max )
{
	return def_dist( &engine ) * (f64)max;
}
template<> s16 rng::get( s16 min, s16 max )
{
	return def_dist( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}
template<> s16 rng::get( distribution* distributor )
{
	return math::s16_0<f64>() + distributor->dist_func( &engine ) * math::u16_2<f64>();
}
template<> s16 rng::get( distribution* distributor, s16 max )
{
	return distributor->dist_func( &engine ) * (f64)max;
}
template<> s16 rng::get( distribution* distributor, s16 min, s16 max )
{
	return distributor->dist_func( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}

// generate s32
template<> s32 rng::get()
{
	return math::s32_0<f64>() + def_dist( &engine ) * math::u32_2<f64>();
}
template<> s32 rng::get( s32 max )
{
	return def_dist( &engine ) * (f64)max;
}
template<> s32 rng::get( s32 min, s32 max )
{
	return def_dist( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}
template<> s32 rng::get( distribution* distributor )
{
	return math::s32_0<f64>() + distributor->dist_func( &engine ) * math::u32_2<f64>();
}
template<> s32 rng::get( distribution* distributor, s32 max )
{
	return distributor->dist_func( &engine ) * (f64)max;
}
template<> s32 rng::get( distribution* distributor, s32 min, s32 max )
{
	return distributor->dist_func( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}

// generate s64
template<> s64 rng::get()
{
	return math::s64_0<f64>() + def_dist( &engine ) * math::u64_2<f64>();
}
template<> s64 rng::get( s64 max )
{
	return def_dist( &engine ) * (f64)max;
}
template<> s64 rng::get( s64 min, s64 max )
{
	return def_dist( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}
template<> s64 rng::get( distribution* distributor )
{
	return math::s64_0<f64>() + distributor->dist_func( &engine ) * math::u64_2<f64>();
}
template<> s64 rng::get( distribution* distributor, s64 max )
{
	return distributor->dist_func( &engine ) * (f64)max;
}
template<> s64 rng::get( distribution* distributor, s64 min, s64 max )
{
	return distributor->dist_func( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}

// generate f32
template<> f32 rng::get()
{
	return def_dist( &engine );
}
template<> f32 rng::get( f32 max )
{
	return def_dist( &engine ) * (f64)max;
}
template<> f32 rng::get( f32 min, f32 max )
{
	return def_dist( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}
template<> f32 rng::get( distribution* distributor )
{
	return distributor->dist_func( &engine );
}
template<> f32 rng::get( distribution* distributor, f32 max )
{
	return distributor->dist_func( &engine ) * (f64)max;
}
template<> f32 rng::get( distribution* distributor, f32 min, f32 max )
{
	return distributor->dist_func( &engine ) * ( (f64)max - (f64)min ) + (f64)min;
}

// generate f64
template<> f64 rng::get()
{
	return def_dist( &engine );
}
template<> f64 rng::get( f64 max )
{
	return def_dist( &engine ) * max;
}
template<> f64 rng::get( f64 min, f64 max )
{
	return def_dist( &engine ) * ( max - min ) + min;
}
template<> f64 rng::get( distribution* distributor )
{
	return distributor->dist_func( &engine );
}
template<> f64 rng::get( distribution* distributor, f64 max )
{
	return distributor->dist_func( &engine ) * max;
}
template<> f64 rng::get( distribution* distributor, f64 min, f64 max )
{
	return distributor->dist_func( &engine ) * ( max - min ) + min;
}

// generate seed
u32 rng::generate_seed()
{
	return get<u32>();
}
u32 rng::generate_seed( distribution* distributor )
{
	return get<u32>( distributor );
}

// get chance
bl rng::get_chance( f64 chance )
{
	if( get<f64>() <= chance )
	{
		return true;
	}

	return false;
}
bl rng::get_chance( distribution* distributor, f64 chance )
{
	if( get<f64>( distributor ) <= chance )
	{
		return true;
	}

	return false;
}

/* end */

}
}

#endif
