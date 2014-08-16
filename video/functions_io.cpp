
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_FUNCTIONS_IO_CPP
#define BDAPI_VIDEO_FUNCTIONS_IO_CPP
#include "video/functions.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"
#include "logging/handler.hpp"
#include "video/raw.hpp"

// magick
#include "Magick++.h"

// namespaces
namespace bdapi {
namespace video {

/* video io function implementations */

// load from native file
video::raw* load_from_native_file( const io::path filename )
{
	if( !filename.exists() )
	{
		return NULL;
	}

	if( !filename.is_file() )
	{
		return NULL;
	}

	init_magick();

	Magick::Image magick_image;

	try
	{
		magick_image.read( filename() );
	}
	catch( Magick::Exception &exception )
	{
		return NULL;
	}

	if( !magick_image.isValid() )
	{
		return NULL;
	}

	Magick::ImageType magick_image_type = magick_image.type();

	s32 magick_channels;

	switch( magick_image_type )
	{
		case Magick::GrayscaleType:
		{
			magick_channels = 1;

			break;
		}
		case Magick::TrueColorType:
		{
			magick_channels = 3;

			break;
		}
		case Magick::TrueColorMatteType:
		{
			magick_channels = 4;

			break;
		}
		default:
		{
			return NULL;
		}
	}

	s32 magick_width  = magick_image.columns();
	s32 magick_height = magick_image.rows();
	s32 magick_depth  = magick_image.depth();

	if( magick_depth != 8 )
	{
		return NULL;
	}

	video::raw* raw_image = new video::raw();

	if( !raw_image->initialize( magick_width, magick_height, magick_channels ) )
	{
		delete raw_image;

		return NULL;
	}

	Magick::Color magick_image_color;

	switch( magick_channels )
	{
		case 1:
		{
			fory( magick_height )
			{
				forx( magick_width )
				{
					magick_image_color = magick_image.pixelColor( x, y );

					raw_image->set_color( x, y, color::by_u8(
						magick_image_color.redQuantum() ) );
				}
			}

			break;
		}
		case 2:
		{
			fory( magick_height )
			{
				forx( magick_width )
				{
					magick_image_color = magick_image.pixelColor( x, y );

					raw_image->set_color( x, y, color::by_u8(
						magick_image_color.redQuantum(),
						magick_image_color.greenQuantum() ) );
				}
			}

			break;
		}
		case 3:
		{
			fory( magick_height )
			{
				forx( magick_width )
				{
					magick_image_color = magick_image.pixelColor( x, y );

					raw_image->set_color( x, y, color::by_u8(
						magick_image_color.redQuantum(),
						magick_image_color.greenQuantum(),
						magick_image_color.blueQuantum() ) );
				}
			}

			break;
		}
		case 4:
		{
			fory( magick_height )
			{
				forx( magick_width )
				{
					magick_image_color = magick_image.pixelColor( x, y );

					raw_image->set_color( x, y, color::by_u8(
						      magick_image_color.redQuantum(),
						      magick_image_color.greenQuantum(),
						      magick_image_color.blueQuantum(),
						255 - magick_image_color.alphaQuantum() ) );
				}
			}

			break;
		}
		default:
		{
			delete raw_image;

			return NULL;
		}
	}

	return raw_image;
}

/* end */

}
}

#endif
