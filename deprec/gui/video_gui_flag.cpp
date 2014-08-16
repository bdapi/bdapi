
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_GUI_FLAG_CPP
#define BDAPI_VIDEO_GUI_FLAG_CPP
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



/* gui flag class implementation ************************************************************************/



// private nullify

void flag::__nullify_2()
{
	s32p_value_pointer = NULL;

	s32_current_value = 0;
}



// constructors

flag::flag() : element()
{
	__nullify_2();
}
flag::flag( wrapper* _parent_wrapper, group* _parent_group, s32 _s32_x, s32 _s32_y, s32 _s32_width,
s32 _s32_height, s32 _s32_swatch_gui_1, s32 _s32_swatch_gui_2, s32 _s32_swatch_text_1,
s32* _s32p_value_pointer, string _string_text, string _string_name, bl _bl_active )
: element( _parent_wrapper, _parent_group, _s32_x, _s32_y, _s32_width, _s32_height, _s32_swatch_gui_1,
_s32_swatch_gui_2, _s32_swatch_text_1, 0, _string_text, _string_name, _bl_active )
{
	__nullify_2();

	s32p_value_pointer = _s32p_value_pointer;

	read();
}
flag::flag( const flag& f ) : element( static_cast<const element&>(f) )
{
	__nullify_2();

	s32p_value_pointer = f.s32p_value_pointer;

	s32_current_value = f.s32_current_value;
}



// set flag

void flag::set_flag()
{
	set_flag( !get_flag() );
}
void flag::set_flag( s32 _on )
{
	if( _on != 0 )
		set_flag( true  );
	else
		set_flag( false );
}
void flag::set_flag( bl _on )
{
	if( _on )
		s32_current_value = 1;
	else
		s32_current_value = 0;

	*s32p_value_pointer = s32_current_value;
}



// read

void flag::read()
{
	if( *s32p_value_pointer != 0 )
		s32_current_value = 1;
	else
		s32_current_value = 0;
}



// get flag

bl flag::get_flag() const
{
	if( s32_current_value != 0 )
		return true;
	else
		return false;
}



/* gui flag specific gui wrapper function implementations ***********************************************/



// draw flag 1

void wrapper::draw_flag_1( flag* f )
{
	s32 fx = f->get_x();
	s32 fy = f->get_y();

	s32 w = tilesheet_gui->get_tile_width();
	s32 h = tilesheet_gui->get_tile_height();

	s32 fo = 0;

	if( f->get_current_value() )
		fo = 3;

	s32 i = f->get_draw_var();
	s32 j = 0;

	if( i != 0 )
		j = 1;

	gl::blitter::set_swatch( swatch_gui, f->get_swatch_gui_1() );

	gl::begin(QUADS);

	tilesheet_gui->get( vec2_flag_1[j].x, vec2_flag_1[j].y, 3, 3 ).draw( fx + s32_flag_x, fy + s32_flag_y );

	gl::end();

	gl::blitter::set_swatch( swatch_gui, f->get_swatch_gui_2() );

	gl::begin(QUADS);

	tilesheet_gui->get( vec2_flag_2[i+fo].x, vec2_flag_2[i+fo].y, 3, 3 ).draw( fx + s32_flag_x,
		 fy + s32_flag_y );

	gl::end();

	f->set_draw_var(i);
}

// draw flag 2

void wrapper::draw_flag_2( flag* f )
{
	if( !f->get_text().empty() )
	{
		s32 fx = f->get_x();
		s32 fy = f->get_y();

		font_gui_1->write( fx + s32_text_x + 1 + tilesheet_gui->get_tile_width() * 3, fy + s32_text_y + 1,
			"~%02i%s", f->get_swatch_text_1(), f->get_text().c_str() );
} }



/* end */
}}}
#endif
