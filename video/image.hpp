
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_IMAGE_HPP
#define BDAPI_VIDEO_IMAGE_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "io/path.hpp"

// namespaces
namespace bdapi {
namespace video {

/* image class declaration */

class image
{

private: // private core data

	BD_GET_COPY( private, u32, handle );

private: // private descriptor data

	BD_GET_COPY( private, s32, width    );
	BD_GET_COPY( private, s32, height   );
	BD_GET_COPY( private, s32, channels );

	BD_IS_COPY( private, bl, default_filtered  );
	BD_IS_COPY( private, bl, default_mipmapped );
	BD_IS_COPY( private, bl, default_clamped   );

	BD_IS_COPY( private, bl, filtered  );
	BD_IS_COPY( private, bl, mipmapped );
	BD_IS_COPY( private, bl, clamped   );

public: // public initialization functions (video_image_init.cpp)

	image () {};
 ~image ();

	#define INIT result initialize

	INIT ( const io::path filename                                                                    );
	INIT ( const io::path filename,                             bl filtered, bl mipmapped, bl clamped );
	INIT ( raw& raw_image                                                                             );
	INIT ( raw& raw_image,                                      bl filtered, bl mipmapped, bl clamped );
	INIT ( u8* data,       s32 width, s32 height, s32 channels                                        );
	INIT ( u8* data,       s32 width, s32 height, s32 channels, bl filtered, bl mipmapped, bl clamped );
	INIT ( s32 x, s32 y,   s32 width, s32 height, s32 channels                                        );
	INIT ( s32 x, s32 y,   s32 width, s32 height, s32 channels, bl filtered, bl mipmapped, bl clamped );

	#undef INIT

	#define LOAD result load_from_buffer

	LOAD ( s32 x, s32 y, s32 width, s32 height, s32 channels                                        );
	LOAD ( s32 x, s32 y, s32 width, s32 height, s32 channels, bl filtered, bl mipmapped, bl clamped );

	#undef LOAD

private: // private initialization functions (video_image_init.cpp)

	void initialize_image ( s32 width, s32 height, s32 channels, bl filtered, bl mipmapped, bl clamped );

	void image_open  ();
	void image_close ();

public: // public core functions (video_image_core.cpp)

	image& bind   ();
	image& unbind ();

public: // public modification functions (video_image_mod.cpp)

	image& set_filtered  (              );
	image& set_filtered  ( bl filtered  );
	image& set_mipmapped (              );
	image& set_mipmapped ( bl mipmapped );
	image& set_clamped   (              );
	image& set_clamped   ( bl clamped   );

public: // public query functions (video_image_query.cpp)

	bl is_active () const;

	static s32 get_filter_params   (  bl filtered, bl mipmapped );
	static s32 get_clamping_params (  bl clamped                );
	static s32 get_internal_format ( s32 channels               );
	static s32 get_internal_format ( s32 channels, bl is_buffer );
	static s32 get_external_format ( s32 channels               );
	static s32 get_data_format     (                            );
	static s32 get_data_format     (               bl is_buffer );

private: // private friends

	friend class buffer;
	friend class shader;

};

/* end */

}
}

#endif
