
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_RAW_QUERY_CPP
#define BDAPI_VIDEO_RAW_QUERY_CPP
#include "video/raw.hpp"

/* includes */

// bdapi


// namespaces
namespace bdapi {
namespace video {

/* raw image class query function implementations */

// get integer 1
s32 raw::get_u8( s32 i ) const
{
	return data[i];
}
s32 raw::get_u8( s32 i, s32 j ) const
{
	return get_u8( ( i * channels ) + ( j % channels ) );
}
s32 raw::get_u8( s32 x, s32 y, s32 j ) const
{
	return get_u8( x + y * width, j );
}

// get integer 2
s32 raw::get_u8_r( s32 i ) const
{
	return get_u8( i, 0 );
}
s32 raw::get_u8_g( s32 i ) const
{
	return get_u8( i, 1 );
}
s32 raw::get_u8_b( s32 i ) const
{
	return get_u8( i, 2 );
}
s32 raw::get_u8_a( s32 i ) const
{
	return get_u8( i, 3 );
}

// get integer 3
s32 raw::get_u8_r( s32 x, s32 y ) const
{
	return get_u8( x, y, 0 );
}
s32 raw::get_u8_g( s32 x, s32 y ) const
{
	return get_u8( x, y, 1 );
}
s32 raw::get_u8_b( s32 x, s32 y ) const
{
	return get_u8( x, y, 2 );
}
s32 raw::get_u8_a( s32 x, s32 y ) const
{
	return get_u8( x, y, 3 );
}

// get float 1
f32 raw::get_f32( s32 i ) const
{
	return (f32)get_u8(i)         / 255.f;
}
f32 raw::get_f32( s32 i, s32 j ) const
{
	return (f32)get_u8( i, j )    / 255.f;
}
f32 raw::get_f32( s32 x, s32 y, s32 j ) const
{
	return (f32)get_u8( x, y, j ) / 255.f;
}

// get float 2
f32 raw::get_f32_r( s32 i ) const
{
	return (f32)get_u8_r(i) / 255.f;
}
f32 raw::get_f32_g( s32 i ) const
{
	return (f32)get_u8_g(i) / 255.f;
}
f32 raw::get_f32_b( s32 i ) const
{
	return (f32)get_u8_b(i) / 255.f;
}
f32 raw::get_f32_a( s32 i ) const
{
	return (f32)get_u8_a(i) / 255.f;
}

// get float 3
f32 raw::get_f32_r( s32 x, s32 y ) const
{
	return (f32)get_u8_r( x, y ) / 255.f;
}
f32 raw::get_f32_g( s32 x, s32 y ) const
{
	return (f32)get_u8_g( x, y ) / 255.f;
}
f32 raw::get_f32_b( s32 x, s32 y ) const
{
	return (f32)get_u8_b( x, y ) / 255.f;
}
f32 raw::get_f32_a( s32 x, s32 y ) const
{
	return (f32)get_u8_a( x, y ) / 255.f;
}

// get color
color raw::get_color( s32 i ) const
{
	switch( channels )
	{
		case 1:
		{
			return color::by_u8(
				get_u8_r(i) );
		}
		case 2:
		{
			return color::by_u8(
				get_u8_r(i),
				get_u8_g(i) );
		}
		case 3:
		{
			return color::by_u8(
				get_u8_r(i),
				get_u8_g(i),
				get_u8_b(i) );
		}
		case 4:
		{
			return color::by_u8(
				get_u8_r(i),
				get_u8_g(i),
				get_u8_b(i),
				get_u8_a(i) );
		}
		default:
		{
			return color();
		}
	}
}
color raw::get_color( s32 x, s32 y ) const
{
	return get_color( x + y * width );
}

// get data
u8* raw::get_data()
{
	return data.get_data();
}

/* end */

}
}

#endif
