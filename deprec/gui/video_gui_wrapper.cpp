
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_GUI_WRAPPER_CPP
#define BDAPI_VIDEO_GUI_WRAPPER_CPP
#include "video_gui_wrapper.hpp"

/* includes */

// bdapi
#include "sys_keyboard.hpp"
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



/* gui wrapper class implementation *********************************************************************/



// protected nullify

void wrapper::__nullify()
{
	container_groups.clear();

	palette_gui   = NULL;
	swatch_gui    = NULL;
	tilesheet_gui = NULL;
	font_gui_1    = NULL;
	font_gui_2    = NULL;

	s32_grid_offset_x = 0;
	s32_grid_offset_y = 0;
	s32_grid_width    = 0;
	s32_grid_height   = 0;

	s32_text_x = 0;
	s32_text_y = 0;

	s32_slider_left  = 0;
	s32_slider_right = 0;

	s32_flag_x = 0;
	s32_flag_y = 0;

	fory(6)
	{
		forx(9)
		{
			set_tile_panel   ( x, y, 0, 0 );
			set_tile_button  ( x, y, 0, 0 );
			set_tile_slider_1( x, y, 0, 0 );
	} }

	fori(6)
	{
		set_tile_slider_2( i, 0, 0 );
		set_tile_flag_1  ( i, 0, 0 );
		set_tile_flag_2  ( i, 0, 0 );
	}

	current_button = NULL;
	current_slider = NULL;

	s32_update_type  = UPDATE_NONE;
	s32_update_value = 0;

	string_update_group.clear();
	string_update_name.clear();
}



// constructors

wrapper::wrapper()
{
	__nullify();
}
wrapper::wrapper( video::palette* _palette_gui, video::swatch* _swatch_gui,
video::tilesheet* _tilesheet_gui, video::font* _font_gui_1, video::font* _font_gui_2,
s32 _s32_grid_offset_x, s32 _s32_grid_offset_y, s32 _s32_grid_width, s32 _s32_grid_height,
s32 _s32_text_x, s32 _s32_text_y, s32 _s32_slider_left, s32 _s32_slider_right, s32 _s32_flag_x,
s32 _s32_flag_y )
{
	__nullify();

	initialize( _palette_gui, _swatch_gui, _tilesheet_gui, _font_gui_1, _font_gui_2, _s32_grid_offset_x,
		_s32_grid_offset_y, _s32_grid_width, _s32_grid_height, _s32_text_x, _s32_text_y,
		_s32_slider_left, _s32_slider_right, _s32_flag_x, _s32_flag_y );
}

// destructor

wrapper::~wrapper()
{
	discard();
}



// initializers

result wrapper::initialize( video::palette* _palette_gui, video::swatch* _swatch_gui,
video::tilesheet* _tilesheet_gui, video::font* _font_gui_1, video::font* _font_gui_2,
s32 _s32_grid_offset_x, s32 _s32_grid_offset_y, s32 _s32_grid_width, s32 _s32_grid_height,
s32 _s32_text_x, s32 _s32_text_y, s32 _s32_slider_left, s32 _s32_slider_right, s32 _s32_flag_x,
s32 _s32_flag_y )
{
	if( !_palette_gui )
	{
		return 0;
	}

	palette_gui = _palette_gui;

	if( !_swatch_gui )
	{
		return 0;
	}

	swatch_gui = _swatch_gui;

	if( !_tilesheet_gui )
	{
		return 0;
	}

	tilesheet_gui = _tilesheet_gui;

	if( !_font_gui_1 )
	{
		return 0;
	}

	font_gui_1 = _font_gui_1;

	if( !_font_gui_2 )
	{
		return 0;
	}

	font_gui_2 = _font_gui_2;

	s32_grid_offset_x = _s32_grid_offset_x;
	s32_grid_offset_y = _s32_grid_offset_y;
	s32_grid_width    = _s32_grid_width;
	s32_grid_height   = _s32_grid_height;

	s32_text_x = _s32_text_x;
	s32_text_y = _s32_text_y;

	s32_slider_left  = _s32_slider_left;
	s32_slider_right = _s32_slider_right;

	s32_flag_x = _s32_flag_x;
	s32_flag_y = _s32_flag_y;

	return 1;
}

// discard

result wrapper::discard()
{
	return 1;
}



// set panel tile

math<s32>::vec2& wrapper::set_tile_panel( s32 i, s32 j, s32 x, s32 y )
{
	return vec2_panel   [i%6][j%9] = math<s32>::vec2( x, y );
}

// set button tile

math<s32>::vec2& wrapper::set_tile_button( s32 i, s32 j, s32 x, s32 y )
{
	return vec2_button  [i%6][j%9] = math<s32>::vec2( x, y );
}

// set slider tile 1

math<s32>::vec2& wrapper::set_tile_slider_1( s32 i, s32 j, s32 x, s32 y )
{
	return vec2_slider_1[i%6][j%9] = math<s32>::vec2( x, y );
}

// set slider tile 2

math<s32>::vec2& wrapper::set_tile_slider_2( s32 i, s32 x, s32 y )
{
	return vec2_slider_2[i%6]      = math<s32>::vec2( x, y );
}

// set flag tile 1

math<s32>::vec2& wrapper::set_tile_flag_1( s32 i, s32 x, s32 y )
{
	return vec2_flag_1  [i%6]      = math<s32>::vec2( x, y );
}

// set flag tile 2

math<s32>::vec2& wrapper::set_tile_flag_2( s32 i, s32 x, s32 y )
{
	return vec2_flag_2  [i%6]      = math<s32>::vec2( x, y );
}



// add group

group* wrapper::add_group( string _string_name, bl _bl_active, bl _bl_visible )
{
	container_groups.insert( group( this, _string_name, _bl_active, _bl_visible ) );

	return &container_groups.get_back();
}



// read

void wrapper::read()
{
	for_i( group, std::deque, container_groups )
		i->read();
}



// update button

void wrapper::update_button( group* g, button* b )
{
	if( b->is_active() )
	{
		if( b->mouse_within() )
		{
			if( mouse::pressed(MB_LEFT) && current_button == NULL && current_slider == NULL )
			{
				current_button = &*b;

				b->set_draw_var(3);
			}
			else if( mouse::released(MB_LEFT) && current_button == &*b )
			{
				current_button = NULL;

				s32_update_type     = UPDATE_BUTTON;
				string_update_group = g->get_name();
				string_update_name  = b->get_name();

				b->set_draw_var(2);
			}
			else if( mouse::held(MB_LEFT) && current_button == &*b )
			{
				b->set_draw_var(3);
			}
			else
			{
				if( ( current_button == NULL || current_button == &*b ) && current_slider == NULL )
				{
					b->set_draw_var(2);
				}
				else
				{
					b->set_draw_var(1);
		} } }
		else
		{
			if( mouse::held(MB_LEFT) && current_button == &*b )
			{
				b->set_draw_var(3);
			}
			else if( mouse::released(MB_LEFT) && current_button == &*b )
			{
				current_button = NULL;

				b->set_draw_var(1);
			}
			else
			{
				b->set_draw_var(1);
	} } }
	else
	{
		b->set_draw_var(0);
	}

	draw_button_1( &*b );
}

// update slider

void wrapper::update_slider( group* g, slider* s )
{
	if( s->is_active() )
	{
		if( s->mouse_within() && s->is_useable() )
		{
			if( mouse::pressed(MB_LEFT) && current_button == NULL && current_slider == NULL )
			{
				current_slider = &*s;

				s->set_draw_var(3);
			}
			else if( mouse::released(MB_LEFT) && current_slider == &*s )
			{
				current_slider = NULL;

				s->set_value( s->get_hover_value() );

				s32_update_type     = UPDATE_SLIDER;
				s32_update_value    = s->get_current_value();
				string_update_group = g->get_name();
				string_update_name  = s->get_name();

				s->set_draw_var(2);
			}
			else if( mouse::held(MB_LEFT) && current_slider == &*s )
			{
				s->set_draw_var(3);
			}
			else if( mouse::get_rotation() != 0 && !mouse::held(MB_LEFT) )
			{
				current_slider = NULL;

				if( keyboard::held(KEY_LCTRL) || keyboard::held(KEY_RCTRL) )
					s->shift_value( mouse::get_rotation() * 10 );
				else
					s->shift_value( mouse::get_rotation() );

				s32_update_type     = UPDATE_SLIDER;
				s32_update_value    = s->get_current_value();
				string_update_group = g->get_name();
				string_update_name  = s->get_name();

				s->set_draw_var(2);
			}
			else
			{
				if( ( current_slider == NULL || current_slider == &*s ) && current_button == NULL )
				{
					s->set_draw_var(2);
				}
				else
				{
					s->set_draw_var(1);
		} } }
		else
		{
			if( mouse::held(MB_LEFT) && current_slider == &*s )
			{
				s->set_draw_var(3);
			}
			else if( mouse::released(MB_LEFT) && current_slider == &*s )
			{
				current_slider = NULL;

				s->set_value( s->get_hover_value() );

				s32_update_type     = UPDATE_SLIDER;
				s32_update_value    = s->get_current_value();
				string_update_group = g->get_name();
				string_update_name  = s->get_name();

				s->set_draw_var(1);
			}
			else
			{
				s->set_draw_var(1);
	} } }
	else
	{
		s->set_draw_var(0);
	}

	draw_slider_1( &*s );
}

// update flag

void wrapper::update_flag( group* g, flag* f )
{
	if( f->is_active() )
	{
		if( f->mouse_within() )
		{
			if( mouse::pressed(MB_LEFT) )
			{
				f->set_flag();

				s32_update_type     = UPDATE_FLAG;
				string_update_group = g->get_name();
				string_update_name  = f->get_name();

				f->set_draw_var(2);
			}
			else
			{
				if( current_slider == NULL && current_button == NULL )
				{
					f->set_draw_var(2);
				}
				else
				{
					f->set_draw_var(1);
		} } }
		else
		{
			f->set_draw_var(1);
	} }
	else
	{
		f->set_draw_var(0);
	}

	draw_flag_1( &*f );
}



// update

void wrapper::update()
{
	s32_update_type  = UPDATE_NONE;
	s32_update_value = 0;

	string_update_group.clear();
	string_update_name.clear();

	bl deactivate = false;

	if( gl::blitter::is_active() )
	{
		gl::blitter::set_palette( palette_gui );
		gl::blitter::set_swatch( swatch_gui );
	}
	else
	{
		gl::blitter::start( palette_gui, swatch_gui );

		deactivate = true;
	}

	tilesheet_gui->bind();

	for_g( group, std::deque, container_groups )
	{
		if( g->is_visible() )
		{
			for_p( panel,  std::deque, g->get_container_panels()   )
				draw_panel_1( &*p );

			for_b( button, std::deque, g->get_container_buttons() )
				update_button( &*g, &*b );

			for_s( slider, std::deque, g->get_container_sliders() )
				update_slider( &*g, &*s );

			for_f( flag,   std::deque, g->get_container_flags()     )
				update_flag( &*g, &*f );
	} }

	for_g( group, std::deque, container_groups )
	{
		if( g->is_visible() )
		{
			for_p( panel,  std::deque, g->get_container_panels()  )
				draw_panel_2( &*p );

			for_b( button, std::deque, g->get_container_buttons() )
				draw_button_2( &*b );

			for_s( slider, std::deque, g->get_container_sliders() )
				draw_slider_2( &*s );

			for_f( flag,   std::deque, g->get_container_flags()   )
				draw_flag_2( &*f );
	} }

	if( deactivate )
		gl::blitter::stop();
}



/* end */
}}}
#endif
