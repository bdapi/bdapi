
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_RAW_CORE_CPP
#define BDAPI_VIDEO_RAW_CORE_CPP
#include "video/raw.hpp"

/* includes */

// bdapi


// namespaces
namespace bdapi {
namespace video {

/* raw image class core function implementations */

// extract raw image from channel
raw_u8_vector raw::extract_channel( s32 channel_index ) const
{
	channel_index %= channels;

	raw_u8_vector u8_data( pixels );

	switch( channel_index )
	{
		case 0:
		{
			fori( pixels )
			{
				u8_data[i] = get_u8_r(i);
			}

			break;
		}
		case 1:
		{
			fori( pixels )
			{
				u8_data[i] = get_u8_g(i);
			}

			break;
		}
		case 2:
		{
			fori( pixels )
			{
				u8_data[i] = get_u8_b(i);
			}

			break;
		}
		case 3:
		{
			fori( pixels )
			{
				u8_data[i] = get_u8_a(i);
			}

			break;
		}
		default:
		{
			break;
		}
	}

	return u8_data;
}

// flip horizontally
raw& raw::flip_horizontally()
{
	raw   temp_raw( *this );
	color temp_color;

	s32 z = width - 1;

	forx( width )
	{
		fory( height )
		{
			temp_color = temp_raw.get_color( x, y );

			set_color( z, y, temp_color );
		}

		z--;
	}

	return *this;
}

// flip vertically
raw& raw::flip_vertically()
{
	raw   temp_raw( *this );
	color temp_color;

	s32 z = height - 1;

	fory( height )
	{
		forx( width )
		{
			temp_color = temp_raw.get_color( x, y );

			set_color( x, z, temp_color );
		}

		z--;
	}

	return *this;
}

// rgb to bgr
raw& raw::rgb_to_bgr()
{
	if( channels >= 3 )
	{
		u8 red;
		u8 blue;

		fori( pixels )
		{
			red  = get_u8_r(i);
			blue = get_u8_b(i);

			set_u8_r( i, blue );
			set_u8_b( i, red  );
		}
	}

	return *this;
}

// bgr to rgb
raw& raw::bgr_to_rgb()
{
	return rgb_to_bgr();
}

// replace
raw& raw::replace( const color& old_color, const color& new_color )
{
	fori( pixels )
	{
		if( get_color(i) == old_color )
		{
			set_color( i, new_color );
		}
	}

	return *this;
}

// get converted data
raw_f32_vector raw::get_f32_data() const
{
	raw_f32_vector f32_data( size );

	switch( channels )
	{
		case 1:
		{
			for( s32 i = 0; i < size; i += 1 )
			{
				f32_data[i] = get_f32_r(i);
			}

			break;
		}
		case 2:
		{
			for( s32 i = 0; i < size; i += 2 )
			{
				f32_data[i+0] = get_f32_r(i);
				f32_data[i+1] = get_f32_g(i);
			}

			break;
		}
		case 3:
		{
			for( s32 i = 0; i < size; i += 3 )
			{
				f32_data[i+0] = get_f32_r(i);
				f32_data[i+1] = get_f32_g(i);
				f32_data[i+2] = get_f32_b(i);
			}

			break;
		}
		case 4:
		{
			for( s32 i = 0; i < size; i += 4 )
			{
				f32_data[i+0] = get_f32_r(i);
				f32_data[i+1] = get_f32_g(i);
				f32_data[i+2] = get_f32_b(i);
				f32_data[i+3] = get_f32_a(i);
			}

			break;
		}
		default:
		{
			break;
		}
	}

	return f32_data;
}
raw_color_vector raw::get_color_data() const
{
	raw_color_vector color_data( pixels );

	fori( pixels )
	{
		color_data[i] = get_color(i);
	}

	return color_data;
}

/* end */

}
}

#endif
