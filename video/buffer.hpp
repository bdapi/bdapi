
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_BUFFER_HPP
#define BDAPI_VIDEO_BUFFER_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "video/image.hpp"

// namespaces
namespace bdapi {
namespace video {

/* frame buffer class declaration */

class buffer
{

private: // private data

	BD_GET_COPY( private, u32, frame_handle  );
	BD_GET_COPY( private, u32, render_handle );

	BD_GET_REFR( private, image, buffer_image );

public: // public initialization functions (video_buffer_init.cpp)

	buffer () {};
	buffer ( s32 width, s32 height, s32 channels                                        );
	buffer ( s32 width, s32 height, s32 channels, bl filtered, bl mipmapped, bl clamped );
 ~buffer ();

	result initialize ( s32 width, s32 height, s32 channels                                        );
	result initialize ( s32 width, s32 height, s32 channels, bl filtered, bl mipmapped, bl clamped );

private: // private initialization functions (video_buffer_init.cpp)

	void buffer_open  ();
	void buffer_close ();

public: // public core functions (video_buffer_core.cpp)

	buffer& activate   ();
	buffer& deactivate ();

	buffer& bind   ();
	buffer& unbind ();

	      image& get_image ();
	const image& get_image () const;

public: // public query functions (video_buffer_query.cpp)

	s32 get_width    () const;
	s32 get_height   () const;
	s32 get_channels () const;

	bl is_filtered  () const;
	bl is_mipmapped () const;
	bl is_clamped   () const;

	bl is_active () const;

};

/* end */

}
}

#endif
