
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_COLOR_QUERY_CPP
#define BDAPI_VIDEO_COLOR_QUERY_CPP
#include "video/color.hpp"

/* includes */

// bdapi


/* namespaces */
namespace bdapi {
namespace video {

/* color class query function implementations */

// get float
f32 color::get_f32( s32 i ) const
{
	return data[i%4];
}
f32 color::get_f32_r() const
{
	return get_f32(0);
}
f32 color::get_f32_g() const
{
	return get_f32(1);
}
f32 color::get_f32_b() const
{
	return get_f32(2);
}
f32 color::get_f32_a() const
{
	return get_f32(3);
}

// get integer
s32 color::get_u8( s32 i ) const
{
	return get_f32(i) * 255.f;
}
s32 color::get_u8_r() const
{
	return get_u8(0);
}
s32 color::get_u8_g() const
{
	return get_u8(1);
}
s32 color::get_u8_b() const
{
	return get_u8(2);
}
s32 color::get_u8_a() const
{
	return get_u8(3);
}

// get data pointer
const f32* color::get_data() const
{
	return data;
}

/* end */

}
}

#endif
