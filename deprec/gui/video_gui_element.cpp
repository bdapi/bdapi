
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_GUI_ELEMENT_CPP
#define BDAPI_VIDEO_GUI_ELEMENT_CPP
#include "video_gui_element.hpp"

/* includes */

// bdapi
#include "sys_mouse.hpp"

// namespaces
namespace bdapi {
namespace video {
namespace gui   {



/* gui element class implementation *********************************************************************/



// protected nullify

void element::__nullify()
{
	parent_wrapper = NULL;
	parent_group   = NULL;

	s32_x      = 0;
	s32_y      = 0;
	s32_width  = 0;
	s32_height = 0;

	s32_swatch_gui_1  = 0;
	s32_swatch_gui_2  = 0;
	s32_swatch_text_1 = 0;
	s32_swatch_text_2 = 0;

	string_text.clear();
	string_name.clear();

	s32_draw_var = 0;

	bl_active = false;
}



// constructors

element::element()
{
	__nullify();
}
element::element( wrapper* _parent_wrapper, group* _parent_group, s32 _s32_x, s32 _s32_y, s32 _s32_width,
s32 _s32_height, s32 _s32_swatch_gui_1, s32 _s32_swatch_gui_2, s32 _s32_swatch_text_1,
s32 _s32_swatch_text_2, string _string_text, string _string_name, bl _bl_active )
{
	__nullify();

	initialize( _parent_wrapper, _parent_group, _s32_x, _s32_y, _s32_width, _s32_height, _s32_swatch_gui_1,
		_s32_swatch_gui_2, _s32_swatch_text_1, _s32_swatch_text_2, _string_text, _string_name, _bl_active );
}
element::element( const element& e )
{
	__nullify();

	parent_wrapper = e.parent_wrapper;
	parent_group   = e.parent_group;

	s32_x      = e.s32_x;
	s32_y      = e.s32_y;
	s32_width  = e.s32_width;
	s32_height = e.s32_height;

	s32_swatch_gui_1  = e.s32_swatch_gui_1;
	s32_swatch_gui_2  = e.s32_swatch_gui_2;
	s32_swatch_text_1 = e.s32_swatch_text_1;
	s32_swatch_text_2 = e.s32_swatch_text_2;

	string_text = e.string_text;
	string_name = e.string_name;

	s32_draw_var = e.s32_draw_var;

	bl_active = e.bl_active;
}



// initializers

result element::initialize( wrapper* _parent_wrapper, group* _parent_group, s32 _s32_x, s32 _s32_y,
s32 _s32_width, s32 _s32_height, s32 _s32_swatch_gui_1, s32 _s32_swatch_gui_2, s32 _s32_swatch_text_1,
s32 _s32_swatch_text_2, string _string_text, string _string_name, bl _bl_active )
{
	parent_wrapper = _parent_wrapper;
	parent_group   = _parent_group;

	s32_x      = _s32_x;
	s32_y      = _s32_y;
	s32_width  = _s32_width;
	s32_height = _s32_height;

	s32_swatch_gui_1  = _s32_swatch_gui_1;
	s32_swatch_gui_2  = _s32_swatch_gui_2;
	s32_swatch_text_1 = _s32_swatch_text_1;
	s32_swatch_text_2 = _s32_swatch_text_2;

	string_text = _string_text;
	string_name = _string_name;

	bl_active = _bl_active;

	return 1;
}



// set text

void element::set_text( cstr input, ... )
{
	STR_FORMAT;

	string_text = input;
}

// set activity

void element::set_activity( bl _active )
{
	bl_active = _active;
}



// mouse within

bl element::mouse_within() const
{
	if( math<s32>::within( s32_x, mouse::get_current_x(), s32_x + s32_width  )
	&&  math<s32>::within( s32_y, mouse::get_current_y(), s32_y + s32_height ) )
		return true;
	else
		return false;
}



// is active

bl element::is_active() const
{
	if( !parent_group->is_active() )
		return false;
	else
		return bl_active;
}

// is visible

bl element::is_visible() const
{
	return parent_group->is_visible();
}



/* end */
}}}
#endif
