
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_OPER_HPP
#define BDAPI_YMX_OPER_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "ymx/ymx_lfo.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx operator class declaration ***********************************************************************/



class oper
{

public:

	volatile s32 s32_input;

	volatile s32* s32_output_1;
	volatile s32* s32_output_2;
	volatile s32* s32_output_3;

private:

	struct
	{
		s32 s32_note;
		s32 s32_tl;
		s32 s32_ar;
		s32 s32_d1r;
		s32 s32_d2r;
		s32 s32_rr;
		s32 s32_owf;
		s32 s32_kc;
		s32 s32_kf;
		s32 s32_ame;
	}
	sig;

	struct
	{
		s32 s32_pitch;
		s32 s32_alpha;
		s32 s32_level;
		bl  bl_recalc;
	}
	LFO;

	struct
	{
		s32 s32_ticks;
		s32 s32_delta;
		s32 s32_ar;
	}
	time;

	struct
	{
		s32 s32_val;
		s32 s32_dt1;
		s32 s32_mul;
	}
	pitch;

	struct
	{
		f32 f32_level;
		s32 s32_input;
		s32 s32_output;
	}
	fb;

	struct
	{
		s32 s32_enabled;
		s32 s32_frequency;
		s32 s32_counter;
		s32 s32_step;
		s32 s32_cycle;
		s32 s32_value;
	}
	noise;

	struct
	{
		s32 s32_state;
		s32 s32_el;
		s32 s32_step;
		s32 s32_and;
		s32 s32_cmp;
		s32 s32_add;
		s32 s32_limit;
	}
	xr;

	struct
	{
		s32 s32_val_and;
		s32 s32_val_cmp;
		s32 s32_val_pls;
		s32 s32_val_lim;
	}
	state_table[6];

	s32 s32_sine_buffer;

	lfo* lfo_operator;

	chip* chip_parent;

private:

	void __nullify ();

public:

	oper ();
 ~oper ();

	result initialize ( chip* );
	result discard    (       );

	void set_key_on    (     );
	void set_key_off   (     );
	void set_ne        ( s32 );
	void set_ame       ( s32 );
	void set_tl        ( s32 );
	void set_ar        ( s32 );
	void set_d1r       ( s32 );
	void set_d1l       ( s32 );
	void set_d2r       ( s32 );
	void set_rr        ( s32 );
	void set_owf       ( s32 );
	void set_mul       ( s32 );
	void set_kc        ( s32 );
	void set_kf        ( s32 );
	void set_fb        ( s32 );
	void set_nfq       ( s32 );
	void set_lwf       ( s32 );
	void set_frq       ( s32 );
	void set_amd       ( s32 );
	void set_ams       ( s32 );
	void set_pmd       ( s32 );
	void set_pms       ( s32 );
	void set_lfo_reset (     );
	void set_lfo_start (     );

	void set_envelope ( s32 );

	s32 send_output_1 ();
	s32 send_output_2 ();
	s32 send_output_3 ();

	lfo* get_lfo ();

	s32 __check_output_lfo ();

	s32  __calc_output_waveform (     );
	s32  __calc_output_alpha    (     );
	s32  __calc_output_noise    (     );
	void __calc_output_feedback ( s32 );
	s32  __calc_output_all      (     );

	void __calculate_ar    ();
	void __calculate_d1r   ();
	void __calculate_d2r   ();
	void __calculate_rr    ();
	void __calculate_pitch ();
	void __calculate_noise ();

};



/* end */
}}
#endif
