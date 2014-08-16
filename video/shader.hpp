
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_SHADER_HPP
#define BDAPI_VIDEO_SHADER_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "io/path.hpp"
#include "string/string.hpp"

// namespaces
namespace bdapi {
namespace video {

/* shader class declaration */

class shader
{

private: // private core data

	BD_GET_COPY( private, u32, handle );

	BD_GET_COPY( private, string, vert_source );
	BD_GET_COPY( private, string, frag_source );

private: // private descriptor data

	BD_GET_REFR( private, io::path, vert_filename );
	BD_GET_REFR( private, io::path, frag_filename );

public: // public initialization functions (video_shader_init.cpp)

	shader () {};
	shader ( const io::path vert_filename, const io::path frag_filename );
	shader ( const io::path vert_filename, const shader*  frag_shader   );
	shader ( const shader*  vert_shader,   const io::path frag_filename );
	shader ( const shader*  vert_shader,   const shader*  frag_shader   );
 ~shader ();

	result initialize ( const io::path vert_filename, const io::path frag_filename );
	result initialize ( const io::path vert_filename, const shader*  frag_shader   );
	result initialize ( const shader*  vert_shader,   const io::path frag_filename );
	result initialize ( const shader*  vert_shader,   const shader*  frag_shader   );

private: // private initialization functions (video_shader_init.cpp)

	result load_shader_from_file ( string& source, const io::path filename );

	result compile ( u32 shader_handle, string type, string filename );

	result link ();

private: // private deprecated initialization functions (video_shader_init_deprec.cpp)

	result compile_deprec__ ( u32 handle, string type, const io::path filename );

	result link_deprec__ ();

public: // public core functions (video_shader_core.cpp)

	shader& start ();
	shader& stop  ();

public: // public modification functions (video_shader_mod.cpp)

	shader& set_int  ( string parameter, s32 x                                 );
	shader& set_int  ( string parameter, s32 x, s32 y                          );
	shader& set_int  ( string parameter, s32 x, s32 y, s32 z                   );
	shader& set_int  ( string parameter, s32 x, s32 y, s32 z, s32 w            );
	shader& set_ints ( string parameter, s32 size, const s32* data, s32 amount );

	shader& set_float  ( string parameter, f32 x                                 );
	shader& set_float  ( string parameter, f32 x, f32 y                          );
	shader& set_float  ( string parameter, f32 x, f32 y, f32 z                   );
	shader& set_float  ( string parameter, f32 x, f32 y, f32 z, f32 w            );
	shader& set_floats ( string parameter, s32 size, const f32* data, s32 amount );

	shader& set_color ( string parameter, const color* shader_color );

	shader& set_texture ( string parameter, s32 index, const image* shader_image );

	shader& set_palette (            const palette* shader_palette );
	shader& set_palette ( s32 index, const palette* shader_palette );

	shader& set_swatch (                    const swatch* shader_swatch                   );
	shader& set_swatch ( s32 texture_index, const swatch* shader_swatch                   );
	shader& set_swatch (                    const swatch* shader_swatch, s32 swatch_index );
	shader& set_swatch ( s32 texture_index, const swatch* shader_swatch, s32 swatch_index );

	shader& set_swatch_index ( const swatch* shader_swatch, s32 swatch_index );

public: // public query functions (video_shader_query.cpp)

	bl is_active () const;

};

/* end */

}
}

#endif
