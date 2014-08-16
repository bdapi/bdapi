
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_PALETTE_HPP
#define BDAPI_VIDEO_PALETTE_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "io/path.hpp"
#include "video/color.hpp"

/* namespaces */
namespace bdapi {
namespace video {

/* palette typedef declarations */

typedef util::container< color, std::vector > palette_color_vector;

/* palette class declaration */

class palette : public palette_color_vector
{

private: // private core data

	BD_GET_COPY_INIT( private, image*, palette_image, NULL );

private: // private descriptor data

	BD_GET_COPY_INIT( private, s32, width,  1 );
	BD_GET_COPY_INIT( private, s32, height, 1 );

public: // public initialization functions (video_palette_init.cpp)

	palette ();
	palette ( s32 size              );
	palette ( s32 width, s32 height );
	palette ( io::path filename     );
	palette ( const raw& raw_image  );
 ~palette () {};

	result initialize ( io::path filename    );
	result initialize ( const raw& raw_image );

private: // private core functions (video_palette_core.cpp)

	raw*   create_raw   () const;
	image* create_image () const;

public: // public core functions (video_palette_core.cpp)

	image* compile ();

public: // public query functions (video_palette_query.cpp)

	color& get ( s32 i        );
	color& get ( s32 x, s32 y );

	const color& get ( s32 i        ) const;
	const color& get ( s32 x, s32 y ) const;

	s32 get_swatch ( const color& c ) const;

};

/* end */

}
}

#endif
