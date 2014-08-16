
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_RAW_MOD_CPP
#define BDAPI_VIDEO_RAW_MOD_CPP
#include "video/raw.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace video {

/* raw image class modification function implementations */

// set integer 1
raw& raw::set_u8( s32 i, s32 c )
{
	data[i] = c;

	RETHIS;
}
raw& raw::set_u8( s32 i, s32 j, s32 c )
{
	return set_u8( ( i * channels ) + ( j % channels ), c );
}
raw& raw::set_u8( s32 x, s32 y, s32 j, s32 c )
{
	return set_u8( x + y * width, j, c );
}

// set integer 2
raw& raw::set_u8_r( s32 i, s32 red )
{
	return set_u8( i, 0, red );
}
raw& raw::set_u8_g( s32 i, s32 green )
{
	return set_u8( i, 1, green );
}
raw& raw::set_u8_b( s32 i, s32 blue )
{
	return set_u8( i, 2, blue );
}
raw& raw::set_u8_a( s32 i, s32 alpha )
{
	return set_u8( i, 3, alpha );
}

// set integer 3
raw& raw::set_u8_r( s32 x, s32 y, s32 red )
{
	return set_u8( x, y, 0, red );
}
raw& raw::set_u8_g( s32 x, s32 y, s32 green )
{
	return set_u8( x, y, 1, green );
}
raw& raw::set_u8_b( s32 x, s32 y, s32 blue )
{
	return set_u8( x, y, 2, blue );
}
raw& raw::set_u8_a( s32 x, s32 y, s32 alpha )
{
	return set_u8( x, y, 3, alpha );
}

// set float 1
raw& raw::set_f32( s32 i, f32 c )
{
	return set_u8( i,       c * 255.f );
}
raw& raw::set_f32( s32 i, s32 j, f32 c )
{
	return set_u8( i,    j, c * 255.f );
}
raw& raw::set_f32( s32 x, s32 y, s32 j, f32 c )
{
	return set_u8( x, y, j, c * 255.f );
}

// set float 2
raw& raw::set_f32_r( s32 i, f32 red )
{
	return set_u8_r( i, red   * 255.f );
}
raw& raw::set_f32_g( s32 i, f32 green )
{
	return set_u8_g( i, green * 255.f );
}
raw& raw::set_f32_b( s32 i, f32 blue )
{
	return set_u8_b( i, blue  * 255.f );
}
raw& raw::set_f32_a( s32 i, f32 alpha )
{
	return set_u8_a( i, alpha * 255.f );
}

// set float 3
raw& raw::set_f32_r( s32 x, s32 y, f32 red )
{
	return set_u8_r( x, y, red   * 255.f );
}
raw& raw::set_f32_g( s32 x, s32 y, f32 green )
{
	return set_u8_g( x, y, green * 255.f );
}
raw& raw::set_f32_b( s32 x, s32 y, f32 blue )
{
	return set_u8_b( x, y, blue  * 255.f );
}
raw& raw::set_f32_a( s32 x, s32 y, f32 alpha )
{
	return set_u8_a( x, y, alpha * 255.f );
}

// set color
raw& raw::set_color( s32 i, const color& c )
{
	switch( channels )
	{
		case 1:
		{
			return set_u8_r( i, c.get_u8_r() );
		}
		case 2:
		{
			set_u8_r( i, c.get_u8_r() );
			set_u8_g( i, c.get_u8_g() );

			RETHIS;
		}
		case 3:
		{
			set_u8_r( i, c.get_u8_r() );
			set_u8_g( i, c.get_u8_g() );
			set_u8_b( i, c.get_u8_b() );

			RETHIS;
		}
		case 4:
		{
			set_u8_r( i, c.get_u8_r() );
			set_u8_g( i, c.get_u8_g() );
			set_u8_b( i, c.get_u8_b() );
			set_u8_a( i, c.get_u8_a() );

			RETHIS;
		}
		default:
		{
			RETHIS;
		}
	}
}
raw& raw::set_color( s32 x, s32 y, const color& c )
{
	return set_color( x + y * width, c );
}

/* end */

}
}

#endif
