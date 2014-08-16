
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_BLITTER_HPP
#define BDAPI_VIDEO_BLITTER_HPP
#include "bdapi.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace gl    {

/* static blitter shader singleton struct function declarations */

struct blitter
{
	static void start ( const video::palette* blitter_palette, const video::swatch* blitter_swatch  );
	static void start ( const video::palette* blitter_palette, const video::swatch* blitter_swatch,
	                    s32 swatch_index );
	static void stop  ();

	static void set_palette ( const video::palette* blitter_palette       );
	//static void set_palette ( const video::image*   blitter_palette_image );

	static void set_swatch ( const video::swatch* blitter_swatch                   );
	static void set_swatch ( const video::swatch* blitter_swatch, s32 swatch_index );

	static void set_index ( const video::swatch* blitter_swatch, s32 swatch_index );

	static bl is_active ();

};

/* end */

}
}

#endif
