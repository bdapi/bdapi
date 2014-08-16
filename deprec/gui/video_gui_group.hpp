
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_GUI_GROUP_HPP
#define BDAPI_VIDEO_GUI_GROUP_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "video_gui_wrapper.hpp"

// namespaces
namespace bdapi {
namespace video {
namespace gui   {



/* gui group class declaration **************************************************************************/



class group
{

private:

	BD_GET_COPY( wrapper*, wrapper_parent, get_wrapper );

	BD_GET_COPY( string, string_name, get_name );

	BD_GET_COPY( bl, bl_active,  is_active  );
	BD_GET_COPY( bl, bl_visible, is_visible );

	util::container< panel,  std::deque > container_panels;
	util::container< button, std::deque > container_buttons;
	util::container< slider, std::deque > container_sliders;
	util::container< flag,   std::deque > container_flags;

private:

	void __nullify ();

public:

	group (                          );
	group ( wrapper*, string, bl, bl );
	group ( const group&             );
 ~group (                          );

	result initialize ( wrapper*, string, bl, bl );
	result discard    (                          );

	panel* add_panel ( s32, s32, s32, s32, s32, s32, string         );
	panel* add_panel ( s32, s32, s32, s32, s32, s32, string, string );

	button* add_button ( s32, s32, s32, s32, s32,      string, string );
	button* add_button ( s32, s32, s32, s32, s32, s32, string, string );

	slider* add_slider ( s32, s32, s32, s32, s32, s32, s32,      s32*, s32, string     );
	slider* add_slider ( s32, s32, s32, s32, s32, s32, s32, s32, s32*, s32, string     );
	slider* add_slider ( s32, s32, s32, s32, s32, s32, s32,      s32*, s32, string, bl );
	slider* add_slider ( s32, s32, s32, s32, s32, s32, s32, s32, s32*, s32, string, bl );

	flag* add_flag ( s32, s32, s32, s32, s32, s32,      s32*, string         );
	flag* add_flag ( s32, s32, s32, s32, s32, s32, s32, s32*, string, string );

	panel*  get_panel  ( string );
	button* get_button ( string );
	slider* get_slider ( string );
	flag*   get_flag   ( string );

	util::container< panel,  std::deque >& get_container_panels  ();
	util::container< button, std::deque >& get_container_buttons ();
	util::container< slider, std::deque >& get_container_sliders ();
	util::container< flag,   std::deque >& get_container_flags   ();

	void read ();

private:

	friend class wrapper;

};



/* end */
}}}
#endif
