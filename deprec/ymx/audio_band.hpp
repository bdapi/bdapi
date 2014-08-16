
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_BAND_HPP
#define BDAPI_AUDIO_BAND_HPP
#include "bdapi.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace audio {



/* audio band limiter class declaration *****************************************************************/



class band
{

public:

	s16* s16p_data;

private:

	private_data( s32, s32_size, get_size );

	private_data( s32, s32_phase_count, get_phase_count );
	private_data( s32, s32_step_width,  get_step_width  );

	private_data( f32, f32_low_pass,  get_low_pass  );
	private_data( f32, f32_high_pass, get_high_pass );

	private_data( f32**, f32pp_steps, get_steps );

private:

	void __nullify ();

public:

	band (                         );
	band ( s32                     );
	band ( s32, s32, s32, f32, f32 );
	band ( const band&             );
 ~band (                         );

	result initialize ( s32                     );
	result initialize ( s32, s32, s32, f32, f32 );
	result discard    (                         );

	result run ( s16* );

};



/* end */
}}
#endif
