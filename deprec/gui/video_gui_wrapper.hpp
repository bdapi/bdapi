
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_GUI_WRAPPER_HPP
#define BDAPI_VIDEO_GUI_WRAPPER_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "deque"

// bdapi 1
#include "util_container.hpp"
#include "util_math.hpp"
#include "util_string.hpp"

// bdapi 2
#include "video_gui_element.hpp"
#include "video_gui_group.hpp"

// namespaces
namespace bdapi {
namespace video {
namespace gui   {



/* gui wrapper class declaration ************************************************************************/



class wrapper
{

private:

	util::container< group, std::deque > container_groups;

	BD_GET_COPY( video::palette*,   palette_gui,   get_palette   );
	BD_GET_COPY( video::swatch*,    swatch_gui,    get_swatch    );
	BD_GET_COPY( video::tilesheet*, tilesheet_gui, get_tilesheet );
	BD_GET_COPY( video::font*,      font_gui_1,    get_font_1    );
	BD_GET_COPY( video::font*,      font_gui_2,    get_font_2    );

	BD_GET_COPY( s32, s32_grid_offset_x, get_grid_offset_x );
	BD_GET_COPY( s32, s32_grid_offset_y, get_grid_offset_y );
	BD_GET_COPY( s32, s32_grid_width,    get_grid_width    );
	BD_GET_COPY( s32, s32_grid_height,   get_grid_height   );

	BD_GET_COPY( s32, s32_text_x, get_text_x );
	BD_GET_COPY( s32, s32_text_y, get_text_y );

	BD_GET_COPY( s32, s32_slider_left,  get_slider_left  );
	BD_GET_COPY( s32, s32_slider_right, get_slider_right );

	BD_GET_COPY( s32, s32_flag_x, get_flag_x );
	BD_GET_COPY( s32, s32_flag_y, get_flag_y );

	math<s32>::vec2 vec2_panel   [6][9];
	math<s32>::vec2 vec2_button  [6][9];
	math<s32>::vec2 vec2_slider_1[6][9];
	math<s32>::vec2 vec2_slider_2[6];
	math<s32>::vec2 vec2_flag_1  [6];
	math<s32>::vec2 vec2_flag_2  [6];

	BD_GET_COPY( button*, current_button, get_current_button );
	BD_GET_COPY( slider*, current_slider, get_current_slider );

	BD_GET_COPY( s32, s32_update_type,  get_update_type  );
	BD_GET_COPY( s32, s32_update_value, get_update_value );

	BD_GET_COPY( string, string_update_group, get_update_group );
	BD_GET_COPY( string, string_update_name,  get_update_name  );

private:

	void __nullify ();

public:

	wrapper ();
	wrapper ( video::palette*, video::swatch*, video::tilesheet*, video::font*, video::font*, s32, s32, s32,
	          s32, s32, s32, s32, s32, s32, s32 );
 ~wrapper ();

	result initialize ( video::palette*, video::swatch*, video::tilesheet*, video::font*, video::font*, s32,
	                    s32, s32, s32, s32, s32, s32, s32, s32, s32 );
	result discard    ();

	math<s32>::vec2& set_tile_panel    ( s32, s32, s32, s32 );
	math<s32>::vec2& set_tile_button   ( s32, s32, s32, s32 );
	math<s32>::vec2& set_tile_slider_1 ( s32, s32, s32, s32 );
	math<s32>::vec2& set_tile_slider_2 ( s32,      s32, s32 );
	math<s32>::vec2& set_tile_flag_1   ( s32,      s32, s32 );
	math<s32>::vec2& set_tile_flag_2   ( s32,      s32, s32 );

	group* add_group ( string, bl, bl );

	void draw_panel_1 ( panel* );
	void draw_panel_2 ( panel* );

	void draw_button_1 ( button* );
	void draw_button_2 ( button* );

	void draw_slider_1 ( slider* );
	void draw_slider_2 ( slider* );

	void draw_flag_1 ( flag* );
	void draw_flag_2 ( flag* );

	void read ();

	void update_button ( group*, button* );
	void update_slider ( group*, slider* );
	void update_flag   ( group*, flag*   );

	void update ();

};



/* gui macro definitions ********************************************************************************/



#define UPDATE_NONE   0
#define UPDATE_BUTTON 1
#define UPDATE_FLAG   2
#define UPDATE_SLIDER 3



/* end */
}}}
#endif
