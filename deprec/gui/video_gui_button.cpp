
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_GUI_BUTTON_CPP
#define BDAPI_VIDEO_GUI_BUTTON_CPP
#include "video_gui_element.hpp"

/* includes */

// bdapi
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



/* gui button class implementation **********************************************************************/



// private nullify

void button::__nullify_2()
{
}



// constructors

button::button() : element()
{
	__nullify_2();
}
button::button( wrapper* _parent_wrapper, group* _parent_group, s32 _s32_x, s32 _s32_y, s32 _s32_width,
s32 _s32_height, s32 _s32_swatch_gui_1, s32 _s32_swatch_text_1, string _string_text, string _string_name,
bl _bl_active )
: element( _parent_wrapper, _parent_group, _s32_x, _s32_y, _s32_width, _s32_height, _s32_swatch_gui_1, 0,
_s32_swatch_text_1, 0, _string_text, _string_name, _bl_active )
{
	__nullify_2();
}
button::button( const button& b ) : element( static_cast<const element&>(b) )
{
	__nullify_2();
}



/* gui button specific gui wrapper function implementations *********************************************/



// draw button 1

void wrapper::draw_button_1( button* b )
{
	s32 bx = b->get_x();
	s32 by = b->get_y();
	s32 bw = b->get_width();
	s32 bh = b->get_height();

	s32 w = tilesheet_gui->get_tile_width();
	s32 h = tilesheet_gui->get_tile_height();

	s32 i = b->get_draw_var();

	gl::blitter::set_index( swatch_gui, b->get_swatch_gui_1() );

	gl::begin(QUADS);

	tilesheet_gui->get( vec2_button[i][0].x, vec2_button[i][0].y, 1, 1 ).draw( bx,      by      );
	tilesheet_gui->get( vec2_button[i][1].x, vec2_button[i][1].y, 1, 1 ).send( bx+w,    by      );
		gl::vw = bw-w*2;
		gl::draw();
	tilesheet_gui->get( vec2_button[i][2].x, vec2_button[i][2].y, 1, 1 ).draw( bx+bw-w, by      );

	tilesheet_gui->get( vec2_button[i][3].x, vec2_button[i][3].y, 1, 1 ).send( bx,      by+h    );
		gl::vh = bh-h * 2;
		gl::draw();
	tilesheet_gui->get( vec2_button[i][4].x, vec2_button[i][4].y, 1, 1 ).send( bx+w,    by+h    );
		gl::vw = bw-w * 2;
		gl::vh = bh-h * 2;
		gl::draw();
	tilesheet_gui->get( vec2_button[i][5].x, vec2_button[i][5].y, 1, 1 ).send( bx+bw-w, by+h    );
		gl::vh = bh-h * 2;
		gl::draw();

	tilesheet_gui->get( vec2_button[i][6].x, vec2_button[i][6].y, 1, 1 ).draw( bx,      by+bh-h );
	tilesheet_gui->get( vec2_button[i][7].x, vec2_button[i][7].y, 1, 1 ).send( bx+w,    by+bh-h );
		gl::vw = bw-w * 2;
		gl::draw();
	tilesheet_gui->get( vec2_button[i][8].x, vec2_button[i][8].y, 1, 1 ).draw( bx+bw-w, by+bh-h );

	gl::end();

	b->set_draw_var(i);
}

// draw button 2

void wrapper::draw_button_2( button* b )
{
	if( !b->get_text().empty() )
	{
		s32 bx = b->get_x();
		s32 by = b->get_y();

		s32 temp_text_color = b->get_swatch_text_1();
		s32 temp_x_offset   = 0;
		s32 temp_y_offset   = 0;

		switch( b->get_draw_var() )
		{
			case 1:
				temp_text_color +=   font_gui_1->get_swatch()->get_height() / 4;
				break;
			case 2:
				temp_text_color += ( font_gui_1->get_swatch()->get_height() / 4 ) * 2;
				break;
			case 3:
				temp_text_color += ( font_gui_1->get_swatch()->get_height() / 4 ) * 3;
				temp_x_offset    = 1;
				temp_y_offset    = 1;
				break;
			default:
				break;
		}

		font_gui_1->write( bx + s32_text_x + temp_x_offset, by + s32_text_y + temp_y_offset,
			"~%02i%s", temp_text_color, b->get_text().c_str() );
} }



/* end */
}}}
#endif
