
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_REVERB_HPP
#define BDAPI_AUDIO_REVERB_HPP
#include "bdapi.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace audio {



/* audio reverb typedef declarations ********************************************************************/



typedef s32 comb_param[2][4];



/* audio reverb class declaration ***********************************************************************/



class reverb
{

private:

	s32 max_delay;

public:

	struct
	{
		s32 band_pole;
		s32 band_gain;

		s32 comb_delay[2][4];
		s32 comb_gain;

		s32 allpass_delay;
		s32 allpass_gain;

		s32 vol_dry_left;
		s32 vol_dry_right;

		s32 vol_wet_left;
		s32 vol_wet_right;

	} r_param;

private:

	s32  yp;

	s16*  y[2][4];
	s16*  x[2];
	s16* ax[2];
	s16* ay[2];

	s16 bx1[2][2];
	s16 by1[2];

	s16* s16p_buffer;

private:

	void __nullify ();

public:

	reverb (     );
	reverb ( s32 );
 ~reverb (     );

	result initialize ( s32 );
	result discard    (     );

	void process ( s16*, u32 );

	void reset ();

private:

	void __calc_bandpass ( s16*,                                               u32 );
	void __calc_allpass  ( s16*, s16*, comb_param&, s32, s32, s32, f32*, f32*, u32 );
	void __calc_reverb   ( s16*, s16*,                                         u32 );

};



/* end */
}}
#endif
