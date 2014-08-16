
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_PIPELINE_HPP
#define BDAPI_VIDEO_PIPELINE_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "vector"

// bdapi
#include "string/string.hpp"
#include "util/container.hpp"

// namespaces
namespace bdapi {
namespace video {

/* pipeline typedef declarations */

typedef util::container< buffer*, std::vector > pipeline_buffer_vector;
typedef util::container< shader*, std::vector > pipeline_shader_vector;

/* pipeline class declaration */

class pipeline
{

private: // private core data

	BD_GET_REFR( private, pipeline_buffer_vector, buffers );
	BD_GET_REFR( private, pipeline_shader_vector, shaders );

	BD_GET_COPY( private, buffer*, current_buffer );
	BD_GET_COPY( private, shader*, current_shader );

	BD_GET_COPY( private, s32, current_index );

public: // public initialization functions (video_pipeline_init.cpp)

	pipeline () {};
 ~pipeline () {};

	result add_buffer ( buffer* pipeline_buffer );
	result add_shader ( shader* pipeline_shader );

public: // public core functions (video_pipeline_core.cpp)

	void begin  (                       );
	void next   (                       );
	void next   ( image* pipeline_image );
	void draw   (                       );
	void finish (                       );
	void finish ( image* pipeline_image );

	void activate   ();
	void deactivate ();

	void start ();
	void stop  ();

	void bind   ();
	void unbind ();

public: // public query functions (video_pipeline_query.cpp)

	s32 get_width    () const;
	s32 get_height   () const;
	s32 get_channels () const;

	bl is_filtered  () const;
	bl is_mipmapped () const;
	bl is_clamped   () const;

	bl is_buffer_active () const;
	bl is_shader_active () const;

	      image& get_image ();
	const image& get_image () const;

public: // public shader functions (video_pipeline_shader.cpp)

	void set_int  ( string parameter, s32 x                                 );
	void set_int  ( string parameter, s32 x, s32 y                          );
	void set_int  ( string parameter, s32 x, s32 y, s32 z                   );
	void set_int  ( string parameter, s32 x, s32 y, s32 z, s32 w            );
	void set_ints ( string parameter, s32 size, const s32* data, s32 amount );

	void set_float  ( string parameter, f32 x                                 );
	void set_float  ( string parameter, f32 x, f32 y                          );
	void set_float  ( string parameter, f32 x, f32 y, f32 z                   );
	void set_float  ( string parameter, f32 x, f32 y, f32 z, f32 w            );
	void set_floats ( string parameter, s32 size, const f32* data, s32 amount );

	void set_color ( string parameter, const color* shader_color );

	void set_texture ( string parameter, s32 index, const image* shader_image );

	void set_palette (            const palette* shader_palette );
	void set_palette ( s32 index, const palette* shader_palette );

	void set_swatch (                    const swatch* shader_swatch                   );
	void set_swatch ( s32 texture_index, const swatch* shader_swatch                   );
	void set_swatch (                    const swatch* shader_swatch, s32 swatch_index );
	void set_swatch ( s32 texture_index, const swatch* shader_swatch, s32 swatch_index );

	void set_swatch_index ( const swatch* shader_swatch, s32 swatch_index );

};

/* end */

}
}

#endif
