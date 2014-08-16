
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OSCILLATOR_HPP
#define BDAPI_SYNTH_OSCILLATOR_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "audio/synth.hpp"
#include "synth/parameters.hpp"
#include "sys/threading.hpp"

// forward declarations
namespace stk
{
	//class Blit;
	//class BlitSaw;
	//class BlitSquare;
	class SineWave;
}

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer oscillator class declaration */

class oscillator
{
	BD_GET_REFR( private, synth::oscillator_parameters, params );

	BD_GET_COPY_INIT( private, stk::SineWave*,   sine,   NULL );
	//BD_GET_COPY_INIT( private, stk::BlitSquare*, square, NULL );
	//BD_GET_COPY_INIT( private, stk::BlitSaw*,    saw,    NULL );
	//BD_GET_COPY_INIT( private, stk::Blit*,       blit,   NULL );

	BD_GET_COPY_INIT( private, boost::mutex*, oscillator_mutex, new boost::mutex() );

public: // public initialization functions (synth_oscillator_init.cpp)

	oscillator ();
 ~oscillator ();

public: // public core functions (synth_oscillator_core.cpp)

	void reset ();

	void reset_sine   ();
	//void reset_square ();
	//void reset_saw    ();
	//void reset_blit   ();

public: // public iteration functions (synth_oscillator_iterate.cpp)

	f32 iterate (                );
	f32 iterate ( f32 modulation );

public: // public modification functions (synth_oscillator_mod.cpp)

	void set_parameters ( const synth::oscillator_parameters& params );

	void apply_parameters (                                            );
	void apply_parameters ( const synth::oscillator_parameters& params );

	void set_volume    ( f32 volume    );
	void set_frequency ( f32 frequency );
	//void set_harmonics (               );
	//void set_harmonics ( s32 harmonics );
	//void set_phase     (               );
	//void set_phase     ( f32 phase     );

public: // public query functions (synth_oscillator_query.cpp)

	synth::oscillator_parameters* get_parameters ();

};

/* end */

}
}

#endif
