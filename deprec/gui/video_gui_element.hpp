
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_GUI_ELEMENT_HPP
#define BDAPI_VIDEO_GUI_ELEMENT_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "video_gui_wrapper.hpp"

// namespaces
namespace bdapi {
namespace video {
namespace gui   {



/* gui element class declaration ************************************************************************/



class element
{

protected:

	protected_data( wrapper*, parent_wrapper, get_wrapper );
	protected_data( group*,   parent_group,   get_group   );

	protected_data( s32, s32_x,      get_x      );
	protected_data( s32, s32_y,      get_y      );
	protected_data( s32, s32_width,  get_width  );
	protected_data( s32, s32_height, get_height );

	protected_data( s32, s32_swatch_gui_1,  get_swatch_gui_1  );
	protected_data( s32, s32_swatch_gui_2,  get_swatch_gui_2  );
	protected_data( s32, s32_swatch_text_1, get_swatch_text_1 );
	protected_data( s32, s32_swatch_text_2, get_swatch_text_2 );

	protected_data( string, string_text, get_text );
	protected_data( string, string_name, get_name );

	protected_set_data( element, s32, s32_draw_var, get_draw_var, set_draw_var );

	bl bl_active;

protected:

	void __nullify ();

public:

	element ();
	element ( wrapper*, group*, s32, s32, s32, s32, s32, s32, s32, s32, string, string, bl );
	element ( const element& );
 ~element () {};

	result initialize ( wrapper*, group*, s32, s32, s32, s32, s32, s32, s32, s32, string, string, bl );

	void set_text     ( cstr, ... );
	void set_activity ( bl        );

	bl mouse_within () const;

	bl is_active  () const;
	bl is_visible () const;

protected:

	friend class group;
	friend class wrapper;
};



/* gui panel class declaration **************************************************************************/



class panel : public element
{

private:

	BD_GET_COPY( s32, s32_style, get_style );

private:

	void __nullify_2 ();

public:

	panel ();
	panel ( wrapper*, group*, s32, s32, s32, s32, s32, s32, string, string );
	panel ( const panel& );
 ~panel () {};
};



/* gui button class declaration *************************************************************************/



class button : public element
{

private:

	void __nullify_2 ();

public:

	button ();
	button ( wrapper*, group*, s32, s32, s32, s32, s32, s32, string, string, bl );
	button ( const button& );
 ~button () {};
};



/* gui slider class declaration *************************************************************************/



class slider : public element
{

private:

	BD_GET_COPY( s32*, s32p_value_pointer, get_value_pointer );

	BD_GET_COPY( s32, s32_min_value,     get_min_value     );
	BD_GET_COPY( s32, s32_current_value, get_current_value );
	BD_GET_COPY( s32, s32_max_value,     get_max_value     );
	BD_GET_COPY( s32, s32_value_range,   get_value_range   );

	BD_GET_COPY_SET( slider, bl, bl_useable, is_useable, set_usability );

private:

	void __nullify_2 ();

public:

	slider ();
	slider ( wrapper*, group*, s32, s32, s32, s32, s32, s32, s32, s32, s32*, s32, string, bl, bl );
	slider ( const slider& );
 ~slider () {};

	void set_value   ( s32 );
	void shift_value ( s32 );

	s32 get_relative_value (     ) const;
	s32 get_relative_plot  (     ) const;
	s32 get_relative_plot  ( s32 ) const;
	s32 get_mouse_plot     ( bl  ) const;
	s32 get_hover_value    (     ) const;

	void read ();
};



/* gui flag class declaration ***************************************************************************/



class flag : public element
{

private:

	BD_GET_COPY( s32*, s32p_value_pointer, get_value_pointer );

	BD_GET_COPY( s32, s32_current_value, get_current_value );

private:

	void __nullify_2 ();

public:

	flag ();
	flag ( wrapper*, group*, s32, s32, s32, s32, s32, s32, s32, s32*, string, string, bl );
	flag ( const flag& );
 ~flag () {};

	void set_flag (     );
	void set_flag ( bl  );
	void set_flag ( s32 );

	void read ();

	bl get_flag () const;
};



/* end */
}}}
#endif
