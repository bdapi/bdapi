
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_COLOR_INIT_CPP
#define BDAPI_VIDEO_COLOR_INIT_CPP
#include "video/color.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace video {

/* color class initialization function implementations */

// constructors
color::color( f32 red )
{
	set_f32_r( red );
}
color::color( f32 red, f32 green )
{
	set_f32_r( red   );
	set_f32_g( green );
}
color::color( f32 red, f32 green, f32 blue )
{
	set_f32_r( red   );
	set_f32_g( green );
	set_f32_b( blue  );
}
color::color( f32 red, f32 green, f32 blue, f32 alpha )
{
	set_f32_r( red   );
	set_f32_g( green );
	set_f32_b( blue  );
	set_f32_a( alpha );
}
color::color( const color& copy )
{
	set_color( copy );
}

// static constructor by floats
color color::by_f32( f32 red )
{
	color c;

	c.set_f32_r( red );

	return c;
}
color color::by_f32( f32 red, f32 green )
{
	color c;

	c.set_f32_r( red   );
	c.set_f32_g( green );

	return c;
}
color color::by_f32( f32 red, f32 green, f32 blue )
{
	color c;

	c.set_f32_r( red   );
	c.set_f32_g( green );
	c.set_f32_b( blue  );

	return c;
}
color color::by_f32( f32 red, f32 green, f32 blue, f32 alpha )
{
	color c;

	c.set_f32_r( red   );
	c.set_f32_g( green );
	c.set_f32_b( blue  );
	c.set_f32_a( alpha );

	return c;
}

// static constructors by integers
color color::by_u8( s32 red )
{
	color c;

	c.set_u8_r( red );

	return c;
}
color color::by_u8( s32 red, s32 green )
{
	color c;

	c.set_u8_r( red   );
	c.set_u8_g( green );

	return c;
}
color color::by_u8( s32 red, s32 green, s32 blue )
{
	color c;

	c.set_u8_r( red   );
	c.set_u8_g( green );
	c.set_u8_b( blue  );

	return c;
}
color color::by_u8( s32 red, s32 green, s32 blue, s32 alpha )
{
	color c;

	c.set_u8_r( red   );
	c.set_u8_g( green );
	c.set_u8_b( blue  );
	c.set_u8_a( alpha );

	return c;
}

/* end */

}
}

#endif
