
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_GUI_GROUP_CPP
#define BDAPI_VIDEO_GUI_GROUP_CPP
#include "video_gui_group.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace video {
namespace gui   {



/* gui group class implementation ***********************************************************************/



// private nullify

void group::__nullify()
{
	wrapper_parent = NULL;

	string_name.clear();

	bl_active  = false;
	bl_visible = false;

	container_panels.clear();
	container_buttons.clear();
	container_sliders.clear();
	container_flags.clear();
}



// constructors

group::group()
{
	__nullify();
}
group::group( wrapper* _wrapper_parent, string _string_name, bl _bl_active, bl _bl_visible )
{
	__nullify();

	initialize( _wrapper_parent, _string_name, _bl_active, _bl_visible );
}
group::group( const group& g )
{
	__nullify();

	wrapper_parent = g.wrapper_parent;

	string_name = g.string_name;

	bl_active  = g.bl_active;
	bl_visible = g.bl_visible;

	container_panels  = g.container_panels;
	container_buttons = g.container_buttons;
	container_sliders = g.container_sliders;
	container_flags   = g.container_flags;
}

// destructor

group::~group()
{
	discard();
}



// initializers

result group::initialize( wrapper* _wrapper_parent, string _string_name, bl _bl_active, bl _bl_visible )
{
	wrapper_parent = _wrapper_parent;

	string_name = _string_name;

	bl_active  = _bl_active;
	bl_visible = _bl_visible;

	return 1;
}

// discard

result group::discard()
{
	return 1;
}



// add panel

panel* group::add_panel( s32 _s32_x, s32 _s32_y, s32 _s32_width, s32 _s32_height, s32 _s32_swatch_gui_1,
s32 _s32_style, string _string_name )
{
	return add_panel( _s32_x, _s32_y, _s32_width, _s32_height, _s32_swatch_gui_1, _s32_style, " ",
		_string_name );
}
panel* group::add_panel( s32 _s32_x, s32 _s32_y, s32 _s32_width, s32 _s32_height, s32 _s32_swatch_gui_1,
s32 _s32_style, string _string_text, string _string_name )
{
	_s32_x *= wrapper_parent->get_grid_width();
	_s32_y *= wrapper_parent->get_grid_height();

	_s32_width  *= wrapper_parent->get_grid_width();
	_s32_height *= wrapper_parent->get_grid_height();

	_s32_x += wrapper_parent->get_grid_offset_x();
	_s32_y += wrapper_parent->get_grid_offset_y();

	container_panels.insert( panel( wrapper_parent, this, _s32_x, _s32_y, _s32_width, _s32_height,
		_s32_swatch_gui_1, _s32_style, _string_text, _string_name ) );

	return &container_panels.get_back();
}

// add button

button* group::add_button( s32 _s32_x, s32 _s32_y, s32 _s32_width, s32 _s32_height, s32 _s32_swatch_gui_1,
string _string_text, string _string_name )
{
	return add_button( _s32_x, _s32_y, _s32_width, _s32_height, _s32_swatch_gui_1, _s32_swatch_gui_1,
		_string_text, _string_name );
}
button* group::add_button( s32 _s32_x, s32 _s32_y, s32 _s32_width, s32 _s32_height, s32 _s32_swatch_gui_1,
s32 _s32_swatch_text_1, string _string_text, string _string_name )
{
	_s32_x *= wrapper_parent->get_grid_width();
	_s32_y *= wrapper_parent->get_grid_height();

	_s32_width  *= wrapper_parent->get_grid_width();
	_s32_height *= wrapper_parent->get_grid_height();

	_s32_x += wrapper_parent->get_grid_offset_x();
	_s32_y += wrapper_parent->get_grid_offset_y();

	container_buttons.insert( button( wrapper_parent, this, _s32_x, _s32_y, _s32_width, _s32_height,
		_s32_swatch_gui_1, _s32_swatch_text_1, _string_text, _string_name, true ) );

	return &container_buttons.get_back();
}

// add slider

slider* group::add_slider( s32 _s32_x, s32 _s32_y, s32 _s32_width, s32 _s32_height, s32 _s32_swatch_gui_1,
s32 _s32_swatch_gui_2, s32 _s32_swatch_text_2, s32* _s32p_value_pointer, s32 _s32_max_value,
string _string_name )
{
	return add_slider( _s32_x, _s32_y, _s32_width, _s32_height, _s32_swatch_gui_1, _s32_swatch_gui_2,
		_s32_swatch_text_2, 0, _s32p_value_pointer, _s32_max_value, _string_name, true );
}
slider* group::add_slider( s32 _s32_x, s32 _s32_y, s32 _s32_width, s32 _s32_height, s32 _s32_swatch_gui_1,
s32 _s32_swatch_gui_2, s32 _s32_swatch_text_2, s32 _s32_min_value, s32* _s32p_value_pointer,
s32 _s32_max_value, string _string_name )
{
	return add_slider( _s32_x, _s32_y, _s32_width, _s32_height, _s32_swatch_gui_1, _s32_swatch_gui_2,
		_s32_swatch_text_2, _s32_min_value, _s32p_value_pointer, _s32_max_value, _string_name, true );
}
slider* group::add_slider( s32 _s32_x, s32 _s32_y, s32 _s32_width, s32 _s32_height, s32 _s32_swatch_gui_1,
s32 _s32_swatch_gui_2, s32 _s32_swatch_text_2, s32* _s32p_value_pointer, s32 _s32_max_value,
string _string_name, bl _bl_useable )
{
	return add_slider( _s32_x, _s32_y, _s32_width, _s32_height, _s32_swatch_gui_1, _s32_swatch_gui_2,
		_s32_swatch_text_2, 0, _s32p_value_pointer, _s32_max_value, _string_name, _bl_useable );
}
slider* group::add_slider( s32 _s32_x, s32 _s32_y, s32 _s32_width, s32 _s32_height, s32 _s32_swatch_gui_1,
s32 _s32_swatch_gui_2, s32 _s32_swatch_text_2, s32 _s32_min_value, s32* _s32p_value_pointer,
s32 _s32_max_value, string _string_name, bl _bl_useable )
{
	_s32_x *= wrapper_parent->get_grid_width();
	_s32_y *= wrapper_parent->get_grid_height();

	_s32_width  *= wrapper_parent->get_grid_width();
	_s32_height *= wrapper_parent->get_grid_height();

	_s32_x += wrapper_parent->get_grid_offset_x();
	_s32_y += wrapper_parent->get_grid_offset_y();

	container_sliders.insert( slider( wrapper_parent, this, _s32_x, _s32_y, _s32_width, _s32_height,
		_s32_swatch_gui_1, _s32_swatch_gui_2, _s32_swatch_text_2, _s32_min_value, _s32p_value_pointer,
		_s32_max_value, _string_name, true, _bl_useable ) );

	return &container_sliders.get_back();
}

// add flag

flag* group::add_flag( s32 _s32_x, s32 _s32_y, s32 _s32_width, s32 _s32_height, s32 _s32_swatch_gui_1,
s32 _s32_swatch_gui_2, s32* _s32p_value_pointer, string _string_name )
{
	return add_flag( _s32_x, _s32_y, _s32_width, _s32_height, _s32_swatch_gui_1, _s32_swatch_gui_2, 0,
		_s32p_value_pointer, "", _string_name );
}
flag* group::add_flag( s32 _s32_x, s32 _s32_y, s32 _s32_width, s32 _s32_height, s32 _s32_swatch_gui_1,
s32 _s32_swatch_gui_2, s32 _s32_swatch_text_1, s32* _s32p_value_pointer, string _string_text,
string _string_name )
{
	_s32_x *= wrapper_parent->get_grid_width();
	_s32_y *= wrapper_parent->get_grid_height();

	_s32_width  *= wrapper_parent->get_grid_width();
	_s32_height *= wrapper_parent->get_grid_height();

	_s32_x += wrapper_parent->get_grid_offset_x();
	_s32_y += wrapper_parent->get_grid_offset_y();

	container_flags.insert( flag( wrapper_parent, this, _s32_x, _s32_y, _s32_width, _s32_height,
		_s32_swatch_gui_1, _s32_swatch_gui_2, _s32_swatch_text_1, _s32p_value_pointer, _string_text,
		_string_name, true ) );

	return &container_flags.get_back();
}



// get panel by name

panel* group::get_panel( string _name )
{
	for_i( panel, std::deque, container_panels )
		if( str::find( i->get_name(), _name ) != -1 )
			return &*i;

	return NULL;
}

// get button by name

button* group::get_button( string _name )
{
	for_i( button, std::deque, container_buttons )
		if( str::find( i->get_name(), _name ) != -1 )
			return &*i;

	return NULL;
}

// get slider by name

slider* group::get_slider( string _name )
{
	for_i( slider, std::deque, container_sliders )
		if( str::find( i->get_name(), _name ) != -1)
			return &*i;

	return NULL;
}

// get flag by name

flag* group::get_flag( string _name )
{
	for_i( flag, std::deque, container_flags )
		if( str::find( i->get_name(), _name ) != -1 )
			return &*i;

	return NULL;
}



// get container panels

util::container< panel, std::deque >& group::get_container_panels()
{
	return container_panels;
}

// get container buttons

util::container< button, std::deque >& group::get_container_buttons()
{
	return container_buttons;
}

// get container sliders

util::container< slider, std::deque >& group::get_container_sliders()
{
	return container_sliders;
}

// get container flags

util::container< flag, std::deque >& group::get_container_flags()
{
	return container_flags;
}



// read

void group::read()
{
	for_s( slider, std::deque, container_sliders )
		s->read();

	for_f( flag,   std::deque, container_flags   )
		f->read();
}



/* end */
}}}
#endif
