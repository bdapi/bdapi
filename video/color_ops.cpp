
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_COLOR_OPS_CPP
#define BDAPI_VIDEO_COLOR_OPS_CPP
#include "video/color.hpp"

/* includes */

// bdapi
#include "math/core.hpp"

/* namespaces */
namespace bdapi {
namespace video {

/* color class operator function implementations */

// operator + color
color color::operator + ( const color& other ) const
{
	color new_color(*this);

	new_color += other;

	return new_color;
}

// operator - color
color color::operator - ( const color& other ) const
{
	color new_color(*this);

	new_color -= other;

	return new_color;
}

// operator * color
color color::operator * ( const color& other ) const
{
	color new_color(*this);

	new_color *= other;

	return new_color;
}

// operator / color
color color::operator / ( const color& other ) const
{
	color new_color(*this);

	new_color /= other;

	return new_color;
}

// operator += color
color& color::operator += ( const color& other )
{
	fori(4)
	{
		data[i] += other.data[i];
	}

	RETHIS;
}

// operator -= color
color& color::operator -= ( const color& other )
{
	fori(4)
	{
		data[i] -= other.data[i];
	}

	RETHIS;
}

// operator *= color
color& color::operator *= ( const color& other )
{
	fori(4)
	{
		data[i] *= other.data[i];
	}

	RETHIS;
}

// operator /= color
color& color::operator /= ( const color& other )
{
	fori(4)
	{
		data[i] /= other.data[i];
	}

	RETHIS;
}

// operator == color
bl color::operator == ( const color& other ) const
{
	fori(4)
	{
		if( !math::equals<f32>( data[i], other.data[i] ) )
		{
			return false;
		}
	}

	return true;
}

// operator != color
bl color::operator != ( const color& other ) const
{
	return !( *this == other );
}

// operator () s32
f32 color::operator () ( s32 i ) const
{
	return data[i%4];
}

// operator [] s32
f32& color::operator [] ( s32 i )
{
	return data[i%4];
}

/* end */

}
}

#endif
