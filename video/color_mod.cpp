
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_COLOR_MOD_CPP
#define BDAPI_VIDEO_COLOR_MOD_CPP
#include "video/color.hpp"

/* includes */

// bdapi


/* namespaces */
namespace bdapi {
namespace video {

/* color class modification function implementations */

// set float
color& color::set_f32( s32 i, f32 c )
{
	data[i%4] = c;

	RETHIS;
}
color& color::set_f32_r( f32 red )
{
	return set_f32( 0, red );
}
color& color::set_f32_g( f32 green )
{
	return set_f32( 1, green );
}
color& color::set_f32_b( f32 blue )
{
	return set_f32( 2, blue );
}
color& color::set_f32_a( f32 alpha )
{
	return set_f32( 3, alpha );
}

// set integer
color& color::set_u8( s32 i, s32 c )
{
	return set_f32( i, (f32)c / 255.f );
}
color& color::set_u8_r( s32 red )
{
	return set_u8( 0, red );
}
color& color::set_u8_g( s32 green )
{
	return set_u8( 1, green );
}
color& color::set_u8_b( s32 blue )
{
	return set_u8( 2, blue );
}
color& color::set_u8_a( s32 alpha )
{
	return set_u8( 3, alpha );
}

// set color
color& color::set_color( const color& other )
{
	fori(4)
	{
		data[i] = other.data[i];
	}

	RETHIS;
}

/* end */

}
}

#endif
