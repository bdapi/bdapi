
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_OPENGL_CORE_CPP
#define BDAPI_VIDEO_OPENGL_CORE_CPP
#include "bdapi.hpp"

#if WIN
#include "windows.h"
#include "winuser.h"
#endif

#include "video/opengl.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"
#include "math/core.hpp"
//#include "math/mob2.hpp"
//#include "math/mob3.hpp"
#include "video/raw.hpp"

/* namespaces */
namespace bdapi {
namespace gl    {

/* opengl handling subsystem variable declarations */

f32 vx = 0.f;
f32 vy = 0.f;
f32 vw = 0.f;
f32 vh = 0.f;

f32 tx = 0.f;
f32 ty = 0.f;
f32 tw = 0.f;
f32 th = 0.f;

/* static variable declarations */

static GLenum gl_blend_func_val[15];

static video::image*  current_image  = NULL;
static video::buffer* current_buffer = NULL;
static video::shader* current_shader = NULL;

/* opengl handling subsystem core function implementations */

// initialize
void initialize()
{
	gl_blend_func_val[ 0] = ZERO;
	gl_blend_func_val[ 1] = ONE;
	gl_blend_func_val[ 2] = SRC_COLOR;
	gl_blend_func_val[ 3] = ONE_MINUS_SRC_COLOR;
	gl_blend_func_val[ 4] = DST_COLOR;
	gl_blend_func_val[ 5] = ONE_MINUS_DST_COLOR;
	gl_blend_func_val[ 6] = SRC_ALPHA;
	gl_blend_func_val[ 7] = ONE_MINUS_SRC_ALPHA;
	gl_blend_func_val[ 8] = DST_ALPHA;
	gl_blend_func_val[ 9] = ONE_MINUS_DST_ALPHA;
	gl_blend_func_val[10] = CONSTANT_COLOR;
	gl_blend_func_val[11] = ONE_MINUS_CONSTANT_COLOR;
	gl_blend_func_val[12] = CONSTANT_ALPHA;
	gl_blend_func_val[13] = ONE_MINUS_CONSTANT_ALPHA;
	gl_blend_func_val[14] = SRC_ALPHA_SATURATE;

	clear_color( 0.f, 0.f, 0.f, 1.f );
	clear_depth( 1.f );

	depth_test(true);
	depth_func(LEQUAL);
	depth_mask(true);

	perspective_hint(NICEST);

	shade_model(true);
}

// reset
void reset()
{
	reset(true);
}
void reset( bl texture )
{
	load_identity();

	if( texture )
	{
		vx = 0.f;
		vy = 0.f;
		vw = 0.f;
		vh = 0.f;

		tx = 0.f;
		ty = 0.f;
		tw = 0.f;
		th = 0.f;
	}
}

// view 2d
void view_2d()
{
	if( current_buffer )
	{
		view_2d( *current_buffer );
	}
	else
	{
		projection_matrix();
		//matrix_mode(PROJECTION);

		view( 0, 0, display::get_width(), display::get_height() );
		ortho(      display::get_width(), display::get_height() );

		model_matrix();
		//matrix_mode(MODELVIEW);
	}
}
void view_2d( const video::buffer& buffer )
{
	view_2d( buffer.get_width(), buffer.get_height() );
}
void view_2d( s32 width, s32 height )
{
	projection_matrix();
	//matrix_mode(PROJECTION);

	view(  width, height );
	ortho( width, height );

	model_matrix();
	//matrix_mode(MODELVIEW);
}

// view 3d
//void view_3d( const math::mob3& mob, f32 fov, f32 distance )
//{
//	mob.view( fov, distance );
//}

// blend function
void blend_func( u8 func )
{
	u8 b =     func >> 4;
	u8 c = u8( func << 4 ) >> 4;

	blend( gl_blend_func_val[b], gl_blend_func_val[c] );
};

// set fog parameters
void set_fog_params( const video::color& c, f32 strength )
{
	glFogi ( FOG_MODE,    EXP2         );
	glFogfv( FOG_COLOR,   c.get_data() );
	glFogf ( FOG_DENSITY, strength     );
	glHint ( FOG_HINT,    NICEST       );
}

// set current image
void set_current_image( video::image* video_image )
{
	current_image = video_image;
}

// set current buffer
void set_current_buffer( video::buffer* video_buffer )
{
	current_buffer = video_buffer;
}

// set current shader
void set_current_shader( video::shader* video_shader )
{
	current_shader = video_shader;
}

// get current image
video::image* get_current_image()
{
	return current_image;
}

// get current buffer
video::buffer* get_current_buffer()
{
	return current_buffer;
}

// get current shader
video::shader* get_current_shader()
{
	return current_shader;
}

// get pipeline
video::pipeline* get_pipeline()
{
	return video::get_pipe();
}

// save pixel data
video::raw* save_pixel_data( s32 x, s32 y, s32 width, s32 height )
{
	if( current_buffer )
	{
		s32 channels = current_buffer->get_channels();

		s32 internal_format;

		switch( channels )
		{
			case 1:
			{
				internal_format = GL_RED;

				break;
			}
			case 2:
			{
				internal_format = GL_RG;

				break;
			}
			case 3:
			{
				internal_format = GL_RGB;

				break;
			}
			case 4:
			{
				internal_format = GL_RGBA;

				break;
			}
			default:
			{
				internal_format = GL_RGB;
			}
		}

		s32 size = width * height * channels;

		f32* pixel_data = new f32[ size ];

		glReadPixels( x, y, width, height, internal_format, GL_FLOAT, pixel_data );

		video::raw* raw_image = new video::raw( pixel_data, width, height, channels );

		delete[] pixel_data;

		if( !raw_image )
		{
			return NULL;
		}

		return raw_image;
	}
	else
	{
		u8* pixel_data = new u8[ width * height * 3 ];

		glReadPixels( x, y, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixel_data );

		video::raw* raw_image = new video::raw( pixel_data, width, height, 3 );

		delete[] pixel_data;

		if( !raw_image )
		{
			return NULL;
		}

		return raw_image;
	}
}
video::raw* save_pixel_data( s32 width, s32 height )
{
	return save_pixel_data( 0, 0, width, height );
}
video::raw* save_pixel_data()
{
	if( current_buffer )
	{
		return save_pixel_data( 0, 0, current_buffer->get_width(), current_buffer->get_height() );
	}
	else
	{
		return save_pixel_data( 0, 0, display::get_width(), display::get_height() );
	}
}

// print screen
video::raw* print_screen()
{
	video::raw* screen_data = save_pixel_data();

	#if WIN

	if( !OpenClipboard( NULL ) )
	{
		WRITE_WARNING( "Could not open the clipboard" );

		delete screen_data;

		return NULL;
	}

	if( !EmptyClipboard() )
	{
		WRITE_WARNING( "Could not empty the clipboard" );

		delete screen_data;

		return NULL;
	}

	BITMAPINFOHEADER header_bmp;

	header_bmp.biSize          = sizeof(BITMAPINFOHEADER);
	header_bmp.biWidth         = screen_data->get_width();
	header_bmp.biHeight        = screen_data->get_height();
	header_bmp.biPlanes        = 1;
	header_bmp.biBitCount      = screen_data->get_channels() * 8;
	header_bmp.biCompression   = 0;
	header_bmp.biSizeImage     = 0;
	header_bmp.biXPelsPerMeter = 0;
	header_bmp.biYPelsPerMeter = 0;
	header_bmp.biClrUsed       = 0;
	header_bmp.biClrImportant  = 0;

	HANDLE handle_bmp = GlobalAlloc( GHND, sizeof(BITMAPINFOHEADER) + screen_data->get_size() );

	if( !handle_bmp )
	{
		WRITE_WARNING( "Could not allocate memory for clipboard data" );

		delete screen_data;

		return NULL;
	}

	screen_data->bgr_to_rgb();

	u8* data_bmp = (u8*)GlobalLock( handle_bmp );

	if( !data_bmp )
	{
		WRITE_WARNING( "Could not assign clipboard data" );

		delete screen_data;

		return NULL;
	}

	memcpy( data_bmp, &header_bmp, sizeof(BITMAPINFOHEADER) );

	memcpy( data_bmp + sizeof(BITMAPINFOHEADER), screen_data->get_data(), screen_data->get_size() );

	GlobalUnlock( handle_bmp );

	if( !SetClipboardData( CF_DIB, handle_bmp ) )
	{
		WRITE_WARNING( "Could not write data to clipboard" );

		delete screen_data;

		return NULL;
	}

	CloseClipboard();

	screen_data->rgb_to_bgr();

	#elif MAC
	#warning "Macintosh print screen function unspecified."
	#elif NIX
	#warning "Unix print screen function unspecified."
	#elif PS4
	#warning "PlayStation 4 print screen function unspecified."
	#elif XBO
	#warning "Xbox One print screen function unspecified."
	#elif WII
	#warning "Wii print screen function unspecified."
	#endif

	return screen_data;
}

/* end */

}
}

#endif
