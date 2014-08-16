
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_COLOR_CORE_CPP
#define BDAPI_VIDEO_COLOR_CORE_CPP
#include "video/color.hpp"

/* includes */

// bdapi
#include "math/core.hpp"
#include "string/core.hpp"
#include "video/opengl.hpp"

/* namespaces */
namespace bdapi {
namespace video {

/* color class core function implementations */

// invert
color& color::invert()
{
	set_f32_r( 1.f - get_f32_r() );
	set_f32_g( 1.f - get_f32_g() );
	set_f32_b( 1.f - get_f32_b() );

	RETHIS;
}
color& color::invert( bl color_flag )
{
	if( color_flag )
	{
		f32 red   = get_f32_r();
		f32 green = get_f32_g();
		f32 blue  = get_f32_b();

		f32 max = red;

		if( green > max )
		{
			max = green;
		}

		if( blue > max )
		{
			max = blue;
		}

		f32 x = 1.f - max;

		set_f32_r( red   + x );
		set_f32_g( green + x );
		set_f32_b( blue  + x );

		RETHIS;
	}

	return invert();
}
color& color::invert( bl color_flag, bl alpha_flag )
{
	if( alpha_flag )
	{
		set_f32_a( 1.f - get_f32_a() );

		if( color_flag )
		{
			return invert(true);
		}

		RETHIS;
	}

	return invert( color_flag );
}

// bind opengl color
color& color::bind()
{
	glColor4fv( data );

	RETHIS;
}

// bind opengl clear color
color& color::bind_clear()
{
	glClearColor(
		get_f32_r(),
		get_f32_g(),
		get_f32_b(),
		get_f32_a() );

	RETHIS;
}

// get container
util::container< u8, std::vector > color::get_u8_data() const
{
	util::container< u8, std::vector > u8_data;

	u8_data.insert( get_u8_r() );
	u8_data.insert( get_u8_g() );
	u8_data.insert( get_u8_b() );
	u8_data.insert( get_u8_a() );

	return u8_data;
}
util::container< f32, std::vector > color::get_f32_data() const
{
	util::container< f32, std::vector > f32_data;

	f32_data.insert( get_f32_r() );
	f32_data.insert( get_f32_g() );
	f32_data.insert( get_f32_b() );
	f32_data.insert( get_f32_a() );

	return f32_data;
}

// create html color string
string color::create_html_color() const
{
	return str::format( "%02x%02x%02x",
		u8( math::clamp<s32>( 0, get_u8_r(), 255 ) ),
		u8( math::clamp<s32>( 0, get_u8_g(), 255 ) ),
		u8( math::clamp<s32>( 0, get_u8_b(), 255 ) ) );
}

// to xyz
color color::to_xyz() const
{
	color xyz( *this );

	fori(3)
	{
		if( xyz.data[i] > 0.04045 )
		{
			xyz.data[i] = pow( ( ( xyz.data[i] + 0.055f ) / 1.055f ), 2.4f );
		}
		else
		{
			xyz.data[i] /= 12.92f;
		}

		xyz.data[i] *= 100;
	}

	return color(
		xyz.data[0] * 0.4124f + xyz.data[1] * 0.3576f + xyz.data[2] * 0.1805,
		xyz.data[0] * 0.2126f + xyz.data[1] * 0.7152f + xyz.data[2] * 0.0722,
		xyz.data[0] * 0.0193f + xyz.data[1] * 0.1192f + xyz.data[2] * 0.9505 );
}

// to hunter lab
color color::to_hunter_lab() const
{
	color xyz = to_xyz();

	return color(
		10.0f * sqrt( xyz.data[1] ),
		17.5f * ( ( ( 1.020f * xyz.data[0] ) - xyz.data[1] ) / sqrt( xyz.data[1] ) ),
		 7.0f * ( ( xyz.data[1] - ( 0.847f * xyz.data[2] ) ) / sqrt( xyz.data[1] ) ) );
}

// to cie lab
color color::to_cie_lab() const
{
	color xyz = to_xyz();

	xyz.data[0] /=  95.047f;
	xyz.data[1] /= 100.000f;
	xyz.data[2] /= 108.883f;

	fori(3)
	{
		if( xyz.data[i] > 0.008856f )
		{
			xyz.data[i] = pow( xyz.data[i], ( 1.f / 3.f ) );
		}
		else
		{
			xyz.data[i] = ( 7.787f * xyz.data[i] ) + ( 16.f / 116.f );
		}
	}

	return color(
		( 116.f *   xyz.data[1] ) - 16.f,
			500.f * ( xyz.data[0]   - xyz.data[1] ),
			200.f * ( xyz.data[1]   - xyz.data[2] ) );
}

// get distance
f32 color::get_distance( const color& other ) const
{
	color lab_1 =       to_cie_lab();
	color lab_2 = other.to_cie_lab();

	return sqrt(
		pow( lab_1.data[0] - lab_2.data[0], 2.f ) +
		pow( lab_1.data[1] - lab_2.data[1], 2.f ) +
		pow( lab_1.data[2] - lab_2.data[2], 2.f ) );
}

/* end */

}
}

#endif
