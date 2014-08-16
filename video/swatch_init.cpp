
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_SWATCH_INIT_CPP
#define BDAPI_VIDEO_SWATCH_INIT_CPP
#include "video/swatch.hpp"

/* includes */

// bdapi
#include "io/file.hpp"
#include "video/image.hpp"
#include "video/raw.hpp"

// namespaces
namespace bdapi {
namespace video {

/* swatch class initialization function implementations */

// constructors
swatch::swatch( io::path filename )
{
	initialize( filename );
}

// destructor
swatch::~swatch()
{
	delete swatch_raw;
	delete swatch_image;
}

// initializers
result swatch::initialize( io::path filename )
{
	if( !filename.exists() )
	{
		return 0;
	}
	else if( !filename.is_file() )
	{
		return 0;
	}

	io::file swatch_file( filename );

	if( !swatch_file.read(true) )
	{
		return 0;
	}

	width  = swatch_file.out<s32>();
	height = swatch_file.out<s32>();

	swatch_raw = new raw();

	if( !swatch_raw->initialize( 256, 256, 2 ) )
	{
		delete swatch_raw;

		return 0;
	}

	fory( height )
	{
		forx( width )
		{
			swatch_raw->set_u8_r( x, y, swatch_file.out<u8>() );
			swatch_raw->set_u8_g( x, y, swatch_file.out<u8>() );
		}
	}

	swatch_image = new image();

	if( !swatch_image->initialize( *swatch_raw, false, false, true ) )
	{
		delete swatch_raw;
		delete swatch_image;

		return 0;
	}

	return 1;
}

/* end */

}
}

#endif
