
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_TRACK_HPP
#define BDAPI_YMX_TRACK_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "deque"
#include "vector"

// bdapi
#include "util/container.hpp"
#include "core/string.hpp"
#include "ymx/ymx_section.hpp"
#include "ymx/ymx_signal.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx track class declaration **************************************************************************/



class track
{

private:

	private_data( gen::rng*, rng_track, get_generator );

	private_data( bl, bl_music, is_music );

	private_data( s32, s32_channels,    get_channels    );
	private_data( s32, s32_bpm_default, get_bpm_default );
	private_data( s32, s32_bpm_current, get_bpm_current );

	private_data( f64, f64_sleep_time,      get_sleep_time      );
	private_data( f64, f64_half_sleep_time, get_half_sleep_time );

	private_data( f32, f32_fade_time, get_fade_time );

	private_data( bl,  bl_looping,     is_looping     );
	private_data( s32, s32_loop_index, get_loop_index );

	util::container< s32,    std::vector > container_signal_length;
	util::container< string, std::vector > container_signal_string;

	util::container< signal, std::vector > container_signal_default;
	util::container< signal, std::vector > container_signal_current;

	util::container< section, std::deque > container_sections;

private:

	void __nullify ();

	void __calculate_bpm ();

public:

	track (                                       );
	track ( gen::rng*, bl, s32, s32, f32, bl, s32 );
	track ( gen::rng*, string                     );
	track ( const track&                          );
 ~track (                                       );

	result initialize ( gen::rng*, bl, s32, s32, f32, bl, s32 );
	result initialize ( gen::rng*, string                     );
	result initialize ( const track&                          );
	result discard    (                                       );

	result load ( string );
	result save ( string );

	result set_signal ( s32                );
	result set_signal ( s32, const signal& );
	result set_signal ( s32, string        );

	signal* get_signal_default ( s32 );
	signal* get_signal_current ( s32 );

	result add_section ( const section& );

	section* get_section ( s32 );

	s32 get_sections () const;

	track&   set_bpm (     );
	track&   set_bpm ( s32 );
	track& shift_bpm ( s32 );

};



/* end */
}}
#endif
