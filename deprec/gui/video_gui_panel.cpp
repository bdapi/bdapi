
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_GUI_PANEL_CPP
#define BDAPI_VIDEO_GUI_PANEL_CPP
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



/* gui panel class implementation ***********************************************************************/



// private nullify

void panel::__nullify_2()
{
	s32_style = 0;
}



// constructors

panel::panel() : element()
{
	__nullify_2();
}
panel::panel( wrapper* _parent_wrapper, group* _parent_group, s32 _s32_x, s32 _s32_y, s32 _s32_width,
s32 _s32_height, s32 _s32_swatch_gui_1, s32 _s32_style, string _string_text, string _string_name )
: element( _parent_wrapper, _parent_group, _s32_x, _s32_y, _s32_width, _s32_height, _s32_swatch_gui_1, 0,
_s32_swatch_gui_1, 0, _string_text, _string_name, true )
{
	__nullify_2();

	s32_style = _s32_style % 6;
}
panel::panel( const panel& p ) : element( static_cast<const element&>(p) )
{
	__nullify_2();

	s32_style = p.s32_style;
}



/* gui panel specific gui wrapper function implementations **********************************************/



// draw panel 1

void wrapper::draw_panel_1( panel* p )
{
	s32 px = p->get_x();
	s32 py = p->get_y();
	s32 pw = p->get_width();
	s32 ph = p->get_height();

	s32 w = tilesheet_gui->get_tile_width();
	s32 h = tilesheet_gui->get_tile_height();

	s32 i = p->get_style();

	gl::blitter::set_index( swatch_gui, p->get_swatch_gui_1() );

	gl::begin(QUADS);

	tilesheet_gui->get( vec2_panel[i][0].x, vec2_panel[i][0].y, 1, 1 ).draw( px,      py      );
	tilesheet_gui->get( vec2_panel[i][1].x, vec2_panel[i][1].y, 1, 1 ).send( px+w,    py      );
		gl::vw = pw-w*2;
		gl::draw();
	tilesheet_gui->get( vec2_panel[i][2].x, vec2_panel[i][2].y, 1, 1 ).draw( px+pw-w, py      );

	tilesheet_gui->get( vec2_panel[i][3].x, vec2_panel[i][3].y, 1, 1 ).send( px,      py+h    );
		gl::vh = ph-h * 2;
		gl::draw();
	tilesheet_gui->get( vec2_panel[i][4].x, vec2_panel[i][4].y, 1, 1 ).send( px+w,    py+h    );
		gl::vw = pw-w * 2;
		gl::vh = ph-h * 2;
		gl::draw();
	tilesheet_gui->get( vec2_panel[i][5].x, vec2_panel[i][5].y, 1, 1 ).send( px+pw-w, py+h    );
		gl::vh = ph-h * 2;
		gl::draw();

	tilesheet_gui->get( vec2_panel[i][6].x, vec2_panel[i][6].y, 1, 1 ).draw( px,      py+ph-h );
	tilesheet_gui->get( vec2_panel[i][7].x, vec2_panel[i][7].y, 1, 1 ).send( px+w,    py+ph-h );
		gl::vw = pw-w * 2;
		gl::draw();
	tilesheet_gui->get( vec2_panel[i][8].x, vec2_panel[i][8].y, 1, 1 ).draw( px+pw-w, py+ph-h );

	gl::end();
}

// draw panel 2

void wrapper::draw_panel_2( panel* p )
{
	if( !p->get_text().empty() )
	{
		s32 px = p->get_x();
		s32 py = p->get_y();

		font_gui_1->write( px + s32_text_x + 1, py + s32_text_y + 1, "~%02i%s",
			p->get_swatch_text_1() + ( font_gui_1->get_swatch()->get_height() / 4 )
			* ( ( p->get_style() ) / 2 ), p->get_text().c_str() );
} }



/* end */
}}}
#endif
