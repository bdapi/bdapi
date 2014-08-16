
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_RAW_INIT_CPP
#define BDAPI_VIDEO_RAW_INIT_CPP
#include "video/raw.hpp"

/* includes */

// bdapi
#include "io/file.hpp"

// namespaces
namespace bdapi {
namespace video {

/* raw image class initialization function implementations */

// constructors
raw::raw( io::path filename )
{
	initialize( filename );
}
raw::raw( io::path filename, bl bdfile )
{
	initialize( filename, bdfile );
}
raw::raw( raw_color_vector& data, s32 width, s32 height, s32 channels )
{
	initialize( data, width, height, channels );
}
raw::raw( raw_f32_vector& data, s32 width, s32 height, s32 channels )
{
	initialize( data, width, height, channels );
}
raw::raw( raw_u8_vector& data, s32 width, s32 height, s32 channels )
{
	initialize( data, width, height, channels );
}
raw::raw( color* data, s32 width, s32 height, s32 channels )
{
	initialize( data, width, height, channels );
}
raw::raw( f32* data, s32 width, s32 height, s32 channels )
{
	initialize( data, width, height, channels );
}
raw::raw( u8* data, s32 width, s32 height, s32 channels )
{
	initialize( data, width, height, channels );
}
raw::raw( s32 width, s32 height, s32 channels )
{
	initialize( width, height, channels );
}
raw::raw( const raw& copy )
{
	data = copy.data;

	width    = copy.width;
	height   = copy.height;
	channels = copy.channels;

	pixels = copy.pixels;
	size   = copy.size;
}

// initializers
result raw::initialize( io::path filename )
{
	return initialize( filename, true );
}
result raw::initialize( io::path filename, bl bdfile )
{
	if( !filename.exists() )
	{
		return 0;
	}
	else if( !filename.is_file() )
	{
		return 0;
	}

	io::file raw_file( filename );

	if( !raw_file.read( bdfile ) )
	{
		return 0;
	}

	s32 file_width    = raw_file.out<s32>();
	s32 file_height   = raw_file.out<s32>();
	s32 file_channels = raw_file.out<u8>();

	return initialize( (u8*)raw_file.get_data(true), file_width, file_height, file_channels );
}
result raw::initialize( raw_color_vector& data, s32 width, s32 height, s32 channels )
{
	return initialize( data.get_data(), width, height, channels );
}
result raw::initialize( raw_f32_vector& data, s32 width, s32 height, s32 channels )
{
	return initialize( data.get_data(), width, height, channels );
}
result raw::initialize( raw_u8_vector& data, s32 width, s32 height, s32 channels )
{
	return initialize( data.get_data(), width, height, channels );
}
result raw::initialize( color* data, s32 width, s32 height, s32 channels )
{
	if( !data )
	{
		return 0;
	}

	if( !initialize( width, height, channels ) )
	{
		return 0;
	}

	switch( this->channels )
	{
		case 1:
		{
			fori( this->pixels )
			{
				set_u8_r( i, data[i].get_u8_r() );
			}

			return 1;
		}
		case 2:
		{
			fori( this->pixels )
			{
				set_u8_r( i, data[i].get_u8_r() );
				set_u8_g( i, data[i].get_u8_g() );
			}

			return 1;
		}
		case 3:
		{
			fori( this->pixels )
			{
				set_u8_r( i, data[i].get_u8_r() );
				set_u8_g( i, data[i].get_u8_g() );
				set_u8_b( i, data[i].get_u8_b() );
			}

			return 1;
		}
		case 4:
		{
			fori( this->pixels )
			{
				set_u8_r( i, data[i].get_u8_r() );
				set_u8_g( i, data[i].get_u8_g() );
				set_u8_b( i, data[i].get_u8_b() );
				set_u8_a( i, data[i].get_u8_a() );
			}

			return 1;
		}
		default:
		{
			return 0;
		}
	}
}
result raw::initialize( f32* data, s32 width, s32 height, s32 channels )
{
	if( !data )
	{
		return 0;
	}

	if( !initialize( width, height, channels ) )
	{
		return 0;
	}

	switch( this->channels )
	{
		case 1:
		{
			fori( this->pixels )
			{
				set_f32_r( i, data[i*1+0] );
			}

			return 1;
		}
		case 2:
		{
			fori( this->pixels )
			{
				set_f32_r( i, data[i*2+0] );
				set_f32_g( i, data[i*2+1] );
			}

			return 1;
		}
		case 3:
		{
			fori( this->pixels )
			{
				set_f32_r( i, data[i*3+0] );
				set_f32_g( i, data[i*3+1] );
				set_f32_b( i, data[i*3+2] );
			}

			return 1;
		}
		case 4:
		{
			fori( this->pixels )
			{
				set_f32_r( i, data[i*4+0] );
				set_f32_g( i, data[i*4+1] );
				set_f32_b( i, data[i*4+2] );
				set_f32_a( i, data[i*4+3] );
			}

			return 1;
		}
		default:
		{
			return 0;
		}
	}
}
result raw::initialize( u8* data, s32 width, s32 height, s32 channels )
{
	if( !data )
	{
		return 0;
	}

	if( !initialize( width, height, channels ) )
	{
		return 0;
	}

	switch( this->channels )
	{
		case 1:
		{
			fori( this->pixels )
			{
				set_u8_r( i, data[i*1+0] );
			}

			return 1;
		}
		case 2:
		{
			fori( this->pixels )
			{
				set_u8_r( i, data[i*2+0] );
				set_u8_g( i, data[i*2+1] );
			}

			return 1;
		}
		case 3:
		{
			fori( this->pixels )
			{
				set_u8_r( i, data[i*3+0] );
				set_u8_g( i, data[i*3+1] );
				set_u8_b( i, data[i*3+2] );
			}

			return 1;
		}
		case 4:
		{
			fori( this->pixels )
			{
				set_u8_r( i, data[i*4+0] );
				set_u8_g( i, data[i*4+1] );
				set_u8_b( i, data[i*4+2] );
				set_u8_a( i, data[i*4+3] );
			}

			return 1;
		}
		default:
		{
			return 0;
		}
	}
}
result raw::initialize( s32 width, s32 height, s32 channels )
{
	this->width  = width;
	this->height = height;

	if( channels < 1 || channels > 4 )
	{
		return 0;
	}

	this->channels = channels;

	pixels = this->width  * this->height;
	size   =       pixels * this->channels;

	data.initialize( size );

	return 1;
}

/* end */

}
}

#endif
