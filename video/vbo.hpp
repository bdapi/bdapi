
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_VBO_HPP
#define BDAPI_VIDEO_VBO_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "deque"

// bdapi
#include "math/typedefs.hpp"
#include "util/container.hpp"
#include "video/color.hpp"

// namespaces
namespace bdapi {
namespace video {

/* vertex buffer object typedef declarations */

typedef util::container< math::vec2, std::deque > vbo_vec2_deque;
typedef util::container< math::vec3, std::deque > vbo_vec3_deque;
typedef util::container< color,      std::deque > vbo_color_deque;

/* vertex buffer object class declaration */

class vbo
{

private: // private core data

	BD_GET_COPY_INIT( private, u32, handle,      0 );
	BD_GET_COPY_INIT( private, u32, buffer_size, 0 );
	BD_GET_COPY_INIT( private, s32, vertex_size, 0 );

	BD_GET_COPY_INIT( private, s32, update_mode, 0 );
	BD_GET_COPY_INIT( private, s32, draw_mode,   0 );

	BD_IS_COPY_INIT( private, bl, using_normals,  false );
	BD_IS_COPY_INIT( private, bl, using_colors,   false );
	BD_IS_COPY_INIT( private, bl, using_textures, false );

	BD_IS_COPY_INIT( private, bl, linked, false );
	BD_IS_COPY_INIT( private, bl, active, false );

private: // private internal data

	BD_GET_REFR( private, vbo_vec2_deque,  vec2s    );
	BD_GET_REFR( private, vbo_vec3_deque,  vec3s    );
	BD_GET_REFR( private, vbo_vec3_deque,  normals  );
	BD_GET_REFR( private, vbo_color_deque, colors   );
	BD_GET_REFR( private, vbo_vec2_deque,  textures );

	BD_IS_COPY_INIT( private, f32*, array_vecs,     NULL );
	BD_IS_COPY_INIT( private, f32*, array_normals,  NULL );
	BD_IS_COPY_INIT( private, f32*, array_colors,   NULL );
	BD_IS_COPY_INIT( private, f32*, array_textures, NULL );

	BD_IS_COPY_INIT( private, u32, position_normals,  0 );
	BD_IS_COPY_INIT( private, u32, position_colors,   0 );
	BD_IS_COPY_INIT( private, u32, position_textures, 0 );

public: // public initialization functions (video_vbo_init.cpp)

	vbo () {};
	vbo ( s32 vertex_size, bl using_normals, bl using_colors, bl using_textures, s32 update_mode,
	      s32 draw_mode );
 ~vbo ();

	result initialize ( s32 vertex_size, bl using_normals, bl using_colors, bl using_textures, s32 update_mode,
	                    s32 draw_mode );

public: // public core functions (video_vbo_core.cpp)

	result   link ();
	result unlink ();

	result   activate ();
	result deactivate ();

	vbo& draw (               );
	vbo& draw ( s32 draw_mode );

public: // public modification functions (video_vbo_mod.cpp)

	vbo& in_vec2    (       f32 x, f32 y               );
	vbo& in_vec2    ( const math::vec2& v              );
	vbo& in_vec3    (       f32 x, f32 y, f32 z        );
	vbo& in_vec3    ( const math::vec3& v              );
	vbo& in_normal  (       f32 x, f32 y, f32 z        );
	vbo& in_normal  ( const math::vec3& n              );
	vbo& in_color   (       f32 r                      );
	vbo& in_color   (       f32 r, f32 g               );
	vbo& in_color   (       f32 r, f32 g, f32 b        );
	vbo& in_color   (       f32 r, f32 g, f32 b, f32 a );
	vbo& in_color   ( const color& c                   );
	vbo& in_texture (       f32 x, f32 y               );
	vbo& in_texture ( const math::vec2& t              );

	vbo& clear_vec2s    ();
	vbo& clear_vec3s    ();
	vbo& clear_vecs     ();
	vbo& clear_normals  ();
	vbo& clear_colors   ();
	vbo& clear_textures ();
	vbo& clear          ();

public: // public query functions (video_vbo_query.cpp)

	s32 get_vec2s_size    () const;
	s32 get_vec3s_size    () const;
	s32 get_vecs_size     () const;
	s32 get_normals_size  () const;
	s32 get_colors_size   () const;
	s32 get_textures_size () const;
	s32 get_size          () const;

	bl is_empty () const;

};

/* vertex buffer object class notes

STREAM_DRAW,  STREAM_READ,  STREAM_COPY,
STATIC_DRAW,  STATIC_READ,  STATIC_COPY,
DYNAMIC_DRAW, DYNAMIC_READ, DYNAMIC_COPY

// STORE MODE
// ----------------------------------------------------------------------------------------------------------
// STREAM:  The data store contents will be modified once and used at most a few times.
// STATIC:  The data store contents will be modified once and used many times.
// DYNAMIC: The data store contents will be modified repeatedly and used many times.
// ----------------------------------------------------------------------------------------------------------

// READ MODE
// ----------------------------------------------------------------------------------------------------------
// DRAW:    The data store contents are modified by the application, and used as the source for GL drawing
//          and image specification commands.
// READ:    The data store contents are modified by reading data from the GL, and used to return that data
//          when queried by the application.
// COPY:    The data store contents are modified by reading data from the GL, and used as the source for GL
//          drawing and image specification commands.
// ----------------------------------------------------------------------------------------------------------

/* end */

}
}

#endif
