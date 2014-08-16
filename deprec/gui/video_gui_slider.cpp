
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_GUI_SLIDER_CPP
#define BDAPI_VIDEO_GUI_SLIDER_CPP
#include "video_gui_element.hpp"

/* includes */

// bdapi
#include "sys_mouse.hpp"
#include "sys_opengl.hpp"
#include "video_blitter.hpp"
#include "video_font.hpp"
#include "video_palette.hpp"
#include "video_swatch.hpp"
#include "video_tiles.hpp"

// namespaces
namespace bdapi {
namespace video {
namespace gui   {



/* gui slider class implementation **********************************************************************/



// private nullify

void slider::__nullify_2()
{
	s32p_value_pointer = NULL;

	s32_min_value     = 0;
	s32_current_value = 0;
	s32_max_value     = 0;
	s32_value_range   = 0;

	bl_useable = false;
}



// constructors

slider::slider() : element()
{
	__nullify_2();
}
slider::slider( wrapper* _parent_wrapper, group* _parent_group, s32 _s32_x, s32 _s32_y, s32 _s32_width,
s32 _s32_height, s32 _s32_swatch_gui_1, s32 _s32_swatch_gui_2, s32 _s32_swatch_text_2, s32 _s32_min_value,
s32* _s32p_value_pointer, s32 _s32_max_value, string _string_name, bl _bl_active, bl _bl_useable )
: element( _parent_wrapper, _parent_group, _s32_x, _s32_y, _s32_width, _s32_height, _s32_swatch_gui_1,
_s32_swatch_gui_2, 0, _s32_swatch_text_2, "", _string_name, _bl_active )
{
	__nullify_2();

	s32p_value_pointer = _s32p_value_pointer;

	s32_min_value     = _s32_min_value;
	s32_current_value = *s32p_value_pointer;
	s32_max_value     = _s32_max_value;
	s32_value_range   = s32_max_value - s32_min_value;

	bl_useable = _bl_useable;
}
slider::slider( const slider& s ) : element( static_cast<const element&>(s) )
{
	__nullify_2();

	s32p_value_pointer = s.s32p_value_pointer;

	s32_min_value     = s.s32_min_value;
	s32_current_value = s.s32_current_value;
	s32_max_value     = s.s32_max_value;
	s32_value_range   = s.s32_value_range;

	bl_useable = s.bl_useable;
}



// set value

void slider::set_value( s32 v )
{
	 s32_current_value   = math<s32>::clamp( s32_min_value, v, s32_max_value );
	*s32p_value_pointer = s32_current_value;
}

// shift value

void slider::shift_value( s32 v )
{
	 s32_current_value   = math<s32>::clamp( s32_min_value, s32_current_value + v, s32_max_value );
	*s32p_value_pointer = s32_current_value;
}



// get relative value

s32 slider::get_relative_value() const
{
	return s32_current_value - s32_min_value;
}

// get relative plot

s32 slider::get_relative_plot() const
{
	return get_relative_plot( get_relative_value() );
}
s32 slider::get_relative_plot( s32 v ) const
{
	f32 normal = math<f32>::inv_lerp( 0.f, math<s32>::clamp( v, s32_value_range ), s32_value_range );

	return round( math<f32>::lerp( parent_wrapper->get_slider_left(), normal,
		s32_width - parent_wrapper->get_slider_right() - 1 ) );
}

// get mouse plot

s32 slider::get_mouse_plot( bl _relative ) const
{
	s32 offset_left  = parent_wrapper->get_slider_left();
	s32 offset_right = parent_wrapper->get_slider_right();

	s32 mouse_pos = mouse::get_current_x() - s32_x + offset_left - offset_right;
	s32 hover_pos = math<s32>::clamp( mouse_pos, s32_width - offset_right );

	f32 mouse_norm = math<f32>::inv_lerp( 0.f, hover_pos, s32_width - offset_right - 1 );

	s32 relative_value = round( math<f32>::lerp( s32_min_value, mouse_norm, s32_max_value ) );

	f32 normal = math<f32>::inv_lerp( s32_min_value, relative_value, s32_max_value );

	if( _relative )
		return round( math<f32>::lerp( 0.f, normal, s32_value_range ) );
	else
		return round( math<f32>::lerp( offset_left, normal, s32_width - offset_right - 1 ) );
}

// get hover value

s32 slider::get_hover_value() const
{
	return math<s32>::clamp( s32_min_value, get_mouse_plot(true) + s32_min_value, s32_max_value );
}



// read

void slider::read()
{
	s32_current_value = *s32p_value_pointer;
}



/* gui slider specific gui wrapper function implementations *********************************************/



// draw slider 1

void wrapper::draw_slider_1( slider* s )
{
	s32 sx = s->get_x();
	s32 sy = s->get_y();
	s32 sw = s->get_width();
	s32 sh = s->get_height();

	s32 w = tilesheet_gui->get_tile_width();
	s32 h = tilesheet_gui->get_tile_height();

	s32 sr = s->get_value_range();

	s32 value_pos    = s->get_relative_plot();
	s32 relative_val = s->get_relative_value();
	s32 hover_pos    = s->get_mouse_plot(false);
	s32 hover_val    = s->get_mouse_plot(true );
	s32 hover_next   = math<s32>::clamp( s->get_min_value(), hover_val + s->get_min_value(),
		s->get_max_value() );

	s32 i = s->get_draw_var();

	gl::blitter::set_swatch( swatch_gui, s->get_swatch_gui_2() );

	gl::begin(QUADS);

	if( i > 0 )
	{
		tilesheet_gui->get( vec2_slider_2[0].x, vec2_slider_2[0].y, 1, 1 ).send( sx, sy );
			gl::vw = sw;
			gl::vh = sh;
			gl::draw();
	}

	switch(i)
	{
		case 0:
		{
			tilesheet_gui->get( vec2_slider_2[0].x, vec2_slider_2[0].y, 1, 1 ).send( sx, sy );
				gl::vx = sx + value_pos;
				gl::vw = 1;
				gl::vh = sh;
				gl::draw();

			break;
		}
		case 1:
		{
			tilesheet_gui->get( vec2_slider_2[1].x, vec2_slider_2[1].y, 1, 1 ).send( sx, sy );
				gl::vw = value_pos;
				gl::vh = sh;
				gl::draw();

			tilesheet_gui->get( vec2_slider_2[3].x, vec2_slider_2[3].y, 1, 1 ).send( sx, sy );
				gl::vx = sx + value_pos;
				gl::vw = 1;
				gl::vh = sh;
				gl::draw();

			break;
		}
		case 2:
		{
			if( value_pos > hover_pos )
			{
				tilesheet_gui->get( vec2_slider_2[2].x, vec2_slider_2[2].y, 1, 1 ).send( sx, sy );
					gl::vw = hover_pos;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[1].x, vec2_slider_2[1].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + hover_pos;
					gl::vw = value_pos - hover_pos;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[3].x, vec2_slider_2[3].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + value_pos;
					gl::vw = 1;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[4].x, vec2_slider_2[4].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + hover_pos;
					gl::vw = 1;
					gl::vh = sh;
					gl::draw();
			}
			else if( value_pos == hover_pos )
			{
				tilesheet_gui->get( vec2_slider_2[2].x, vec2_slider_2[2].y, 1, 1 ).send( sx, sy );
					gl::vw = hover_pos;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[5].x, vec2_slider_2[5].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + hover_pos;
					gl::vw = 1;
					gl::vh = sh;
					gl::draw();
			}
			else
			{
				tilesheet_gui->get( vec2_slider_2[2].x, vec2_slider_2[2].y, 1, 1 ).send( sx, sy );
					gl::vw = value_pos;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[1].x, vec2_slider_2[1].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + value_pos;
					gl::vw = hover_pos - value_pos;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[3].x, vec2_slider_2[3].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + hover_pos;
					gl::vw = 1;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[5].x, vec2_slider_2[5].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + value_pos;
					gl::vw = 1;
					gl::vh = sh;
					gl::draw();
			}
			break;
		}
		case 3:
		{
			if( value_pos > hover_pos )
			{
				tilesheet_gui->get( vec2_slider_2[3].x, vec2_slider_2[3].y, 1, 1 ).send( sx, sy );
					gl::vw = hover_pos;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[2].x, vec2_slider_2[2].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + hover_pos;
					gl::vw = value_pos - hover_pos;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[4].x, vec2_slider_2[4].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + value_pos;
					gl::vw = 1;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[5].x, vec2_slider_2[5].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + hover_pos;
					gl::vw = 1;
					gl::vh = sh;
					gl::draw();
			}
			else if( value_pos == hover_pos )
			{
				tilesheet_gui->get( vec2_slider_2[3].x, vec2_slider_2[3].y, 1, 1 ).send( sx, sy );
					gl::vw = hover_pos;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[5].x, vec2_slider_2[5].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + hover_pos;
					gl::vw = 1;
					gl::vh = sh;
					gl::draw();
			}
			else
			{
				tilesheet_gui->get( vec2_slider_2[3].x, vec2_slider_2[3].y, 1, 1 ).send( sx, sy );
					gl::vw = value_pos;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[2].x, vec2_slider_2[2].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + value_pos;
					gl::vw = hover_pos - value_pos;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[4].x, vec2_slider_2[4].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + hover_pos;
					gl::vw = 1;
					gl::vh = sh;
					gl::draw();

				tilesheet_gui->get( vec2_slider_2[5].x, vec2_slider_2[5].y, 1, 1 ).send( sx, sy );
					gl::vx = sx + value_pos;
					gl::vw = 1;
					gl::vh = sh;
					gl::draw();
			}
			break;
		}
		default:
		{
			break;
	} }

	gl::end();

	s32 j = i;

	if( j == 3 )
		j = 2;

	gl::blitter::set_swatch( swatch_gui, s->get_swatch_gui_1() );

	gl::begin(QUADS);

	tilesheet_gui->get( vec2_slider_1[j][0].x, vec2_slider_1[j][0].y, 1, 1 ).draw( sx,      sy      );
	tilesheet_gui->get( vec2_slider_1[j][1].x, vec2_slider_1[j][1].y, 1, 1 ).send( sx+w,    sy      );
		gl::vw = sw-w*2;
		gl::draw();
	tilesheet_gui->get( vec2_slider_1[j][2].x, vec2_slider_1[j][2].y, 1, 1 ).draw( sx+sw-w, sy      );

	tilesheet_gui->get( vec2_slider_1[j][3].x, vec2_slider_1[j][3].y, 1, 1 ).send( sx,      sy+h    );
		gl::vh = sh-h * 2;
		gl::draw();
	tilesheet_gui->get( vec2_slider_1[j][4].x, vec2_slider_1[j][4].y, 1, 1 ).send( sx+w,    sy+h    );
		gl::vw = sw-w * 2;
		gl::vh = sh-h * 2;
		gl::draw();
	tilesheet_gui->get( vec2_slider_1[j][5].x, vec2_slider_1[j][5].y, 1, 1 ).send( sx+sw-w, sy+h    );
		gl::vh = sh-h * 2;
		gl::draw();

	tilesheet_gui->get( vec2_slider_1[j][6].x, vec2_slider_1[j][6].y, 1, 1 ).draw( sx,      sy+sh-h );
	tilesheet_gui->get( vec2_slider_1[j][7].x, vec2_slider_1[j][7].y, 1, 1 ).send( sx+w,    sy+sh-h );
		gl::vw = sw-w * 2;
		gl::draw();
	tilesheet_gui->get( vec2_slider_1[j][8].x, vec2_slider_1[j][8].y, 1, 1 ).draw( sx+sw-w, sy+sh-h );

	gl::end();

	s->set_draw_var(i);
}

// draw slider 2

void wrapper::draw_slider_2( slider* s )
{
	s32 sx = s->get_x();
	s32 sy = s->get_y();

	switch( s->get_draw_var() )
	{
		case 0:
		{
			font_gui_2->write( sx + s32_text_x + 1, sy + s32_text_y + 1, "~%02i%i",
				s->get_swatch_text_2(),
				s->get_current_value() );

			break;
		}
		case 1:
		{
			font_gui_2->write( sx + s32_text_x + 1, sy + s32_text_y + 1, "~%02i%i",
				s->get_swatch_text_2() + ( font_gui_2->get_swatch()->get_height() / 4 ),
				s->get_current_value() );

			break;
		}
		case 2:
		{
			font_gui_2->write( sx + s32_text_x + 1, sy + s32_text_y + 1, "~%02i%i",
				s->get_swatch_text_2() + ( font_gui_2->get_swatch()->get_height() / 4 ) * 2,
				s->get_current_value() );

			break;
		}
		case 3:
		{
			font_gui_2->write( sx + s32_text_x + 1, sy + s32_text_y + 1, "~%02i%i",
				s->get_swatch_text_2() + ( font_gui_2->get_swatch()->get_height() / 4 ) * 3,
				s->get_hover_value() );

			break;
		}
		default:
		{
			break;
} } }



/* end */
}}}
#endif
