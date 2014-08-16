
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_CHIP_HPP
#define BDAPI_YMX_CHIP_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "vector"

// bdapi
#include "util/container.hpp"
#include "sys/threading.hpp"
#include "ymx/ymx_command.hpp"
#include "ymx/ymx_oper.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx chip class declaration ***************************************************************************/



class chip
{

public:

	s16** s16pp_operator_buffers;

	s16* s16p_output_buffer;

private:

	private_data( s32, s32_mixer_channel, get_mixer_channel );

	private_data( audio::buffer*, buffer_chip, get_buffer );

	private_data( s32, s32_channels, get_channels );

	private_set_data( chip, f32, f32_volume, get_volume, set_volume );

	private_data( f32, f32_fade_strength, get_fade_strength );
	private_data( f32, f32_fade_mod,      get_fade_mod      );

	private_set_data( chip, bl, bl_debug, is_debug, set_debug );

	util::container< util::container< oper, std::vector >, std::vector > container_operators;
	util::container< util::container<  s32, std::vector >, std::vector > container_active;

	volatile s32* s32p_operator_output;

	util::container< command, std::vector > container_commands;

	s32 s32a_opm_execute_buffer[3];
	s32 s32a_opm_return_buffer [3];

	s32	s32a_envelope_counter[2];

	private_data( audio::reverb*, reverb_filter, get_reverb_filter );

	private_set_data( chip, bl, bl_reverb, get_reverb, set_reverb );

	private_data( boost::thread*, thread_track, get_thread );

	private_data( ymx::track*, track_current,       get_current_track   );
	private_data( s32,         s32_current_section, get_current_section );
	private_data( s32,         s32_current_command, get_current_command );

	private_data( bl, bl_track_playing, is_track_playing );

	private_set_data( chip, bl, bl_track_interput, is_track_interupted, set_track_interput );

	private_data( u32, u32_play_count, get_play_count );

	boost::mutex mutex_chip;

	private_data( s32, s32_algorithm, get_algorithm );

	private_data( audio::band*, band_chip, get_band_chip );

private: // ymx_chip_init.cpp

	void __nullify ();

private: // ymx_chip_core.cpp

	void __fill  ();

	void __set_alg ( s32, s32 );

	void __execute_command ( s32                );
	void __execute_command ( s32, s32, s32, s32 );

public: // ymx_chip_init.cpp

	chip (              );
	chip ( s32, s32, bl );
 ~chip (              );

	result initialize ( s32, s32, bl );
	result discard    (              );

public: // ymx_chip_core.cpp

	void start         ();
	void play          ();
	void reset         ();
	void set_force_off ();

	void fade ( f32 );

	void run ( s32, s16*                  );
	void run ( s32, s16*,             f32 );
	void run ( s32, s16*, s32, s16**      );
	void run ( s32, s16*, s32, s16**, f32 );

public: // ymx_chip_command.cpp

	void clear_commands ();

	void set_command ( s32, s32, s32, s32 );
	void set_command ( const command&     );

	void set_command_null        (               );

	void set_command_key_on      (      s32      );
	void set_command_key_off     (      s32      );

	void set_command_note_one    ( s32, s32, s32 );
	void set_command_note_all    ( s32, s32      );

	void set_command_alg         ( s32, s32      );

	void set_command_op          ( s32, s32, s32 );
	void set_command_ns          ( s32, s32, s32 );
	void set_command_ne          ( s32, s32, s32 );
	void set_command_ame         ( s32, s32, s32 );

	void set_command_tl          ( s32, s32, s32 );
	void set_command_ar          ( s32, s32, s32 );
	void set_command_d1r         ( s32, s32, s32 );
	void set_command_d1l         ( s32, s32, s32 );
	void set_command_d2r         ( s32, s32, s32 );
	void set_command_rr          ( s32, s32, s32 );

	void set_command_owf         ( s32, s32, s32 );
	void set_command_mul         ( s32, s32, s32 );
	void set_command_kc          ( s32, s32, s32 );
	void set_command_kf          ( s32, s32, s32 );
	void set_command_fb          ( s32, s32, s32 );
	void set_command_nfq         ( s32, s32, s32 );

	void set_command_lwf         ( s32, s32, s32 );
	void set_command_frq         ( s32, s32, s32 );
	void set_command_amd         ( s32, s32, s32 );
	void set_command_ams         ( s32, s32, s32 );
	void set_command_pmd         ( s32, s32, s32 );
	void set_command_pms         ( s32, s32, s32 );

	void set_command_lfo_reset   (      s32, s32 );
	void set_command_lfo_start   (      s32, s32 );

public: // ymx_chip_track.cpp

	void prepare_next_command ( s32, const command& );
	void execute_command      ( s32, const command& );
	void execute_block        (                     );

	result play_track     ( track* );
	result fade_out_track (        );
	result stop_track     (        );

};



/* end */
}}
#endif
