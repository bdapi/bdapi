
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_OPERATE_HPP
#define BDAPI_SYNTH_OPERATE_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "synth/oscillator.hpp"
#include "synth/parameters.hpp"
#include "sys/threading.hpp"

// forward declarations
namespace stk
{
	class ADSR;
	//class Blit;
	//class BlitSaw;
	//class BlitSquare;
	//class SineWave;
}

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer operator class declaration */

class operate
{

private: // private core data

	// descriptors
	BD_GET_COPY_INIT( private, synth::engine*, parent_engine, NULL );
	BD_GET_COPY_INIT( private, synth::module*, parent_module, NULL );
	BD_GET_COPY_INIT( private, synth::voice*,  parent_voice,  NULL );
	BD_GET_COPY_INIT( private, s32,            engine_index,    -1 );
	BD_GET_COPY_INIT( private, s32,            module_index,    -1 );
	BD_GET_COPY_INIT( private, s32,            voice_index,     -1 );
	BD_GET_COPY_INIT( private, s32,            operator_index,  -1 );

	// parameters
	BD_GET_REFR( private, synth::operator_parameters, params );

	// outputs
	BD_GET_COPY_INIT( private, audio::raw*, operator_output, NULL );

	// threading
	BD_GET_COPY_INIT( private, boost::mutex*, operator_mutex, NULL );

	// generators
	BD_GET_COPY_INIT( private, synth::oscillator*, oscillator_frequency,     NULL );
	BD_GET_COPY_INIT( private, synth::oscillator*, oscillator_lfo_amplitude, NULL );
	BD_GET_COPY_INIT( private, synth::oscillator*, oscillator_lfo_pulse,     NULL );
	BD_GET_COPY_INIT( private, stk::ADSR*,         adsr,                     NULL );

	// state
	BD_GET_COPY_INIT( private, state, operator_state, BD_STATE_READY );

	f32 feedback_in  = 0.f;
	f32 feedback_out = 0.f;

public: // public initialization functions (synth_operate_init.cpp)

	operate () {};
 ~operate ();

	result initialize ( synth::engine* parent_engine, synth::module* parent_module, synth::voice* parent_voice,
	                    s32 engine_index, s32 module_index, s32 voice_index, s32 operator_index );

public: // public core functions (synth_operate_core.cpp)

	void key_on  ( s32 note, f32 velocity );
	void key_off (                        );

	void update_state ();

	void reset ();

	void reset_oscillator ();
	void reset_lfo        ();
	void reset_asdr       ();

public: // public iteration functions (synth_operate_iterate.cpp)

	f32 iterate (                );
	f32 iterate ( f32 modulation );

public: // public modification functions (synth_operate_mod.cpp)

	void set_parameters ( const synth::operator_parameters& params );

	void apply_parameters (                                          );
	void apply_parameters ( const synth::operator_parameters& params );

	void set_attack_target ( f32 target );
	void set_attack_time   ( f32 time   );
	void set_decay_time    ( f32 time   );
	void set_sustain_level ( f32 level  );
	void set_release_time  ( f32 time   );

public: // public query functions (synth_operate_query.cpp)

	synth::operator_parameters* get_parameters ();

	s32 get_adsr_state () const;

};

/* end */

}
}

#endif
