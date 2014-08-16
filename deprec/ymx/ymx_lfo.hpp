
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_LFO_HPP
#define BDAPI_YMX_LFO_HPP
#include "bdapi.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx lfo class declaration ****************************************************************************/



class lfo
{

private:

	private_data( s32, am_output, get_am );
	private_data( s32, pm_output, get_pm );

private:

	s32 am_table_value;
	s32	pm_table_value;

	s32	amd;
	f32	ams;

	s32	pmd;
	f32 pms;

	s32 lfo_start_flag;
	s32	lfo_overflow;
	s32	lfo_time;
	s32	lfo_add;
	s32 lfo_index;
	s32 lfo_counter;
	s32 lfo_step;
	s32	lfo_frequency;
	s32	lfo_waveform;

private:

	void __nullify ();

	void __calc_am_value ();
	void __calc_pm_value ();

public:

	lfo ();
 ~lfo ();

	result initialize ();
	result discard    ();

	void set_lwf       ( s32 );
	void set_frq       ( s32 );
	void set_amd       ( s32 );
	void set_ams       ( s32 );
	void set_pmd       ( s32 );
	void set_pms       ( s32 );
	void set_lfo_reset (     );
	void set_lfo_start (     );

	void update();

};



/* end */
}}
#endif
