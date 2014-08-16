
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_CHIP_INIT_CPP
#define BDAPI_YMX_CHIP_INIT_CPP
#include "ymx/ymx_chip.hpp"

/* includes */

// bdapi
#include "ymx/audio_band.hpp"
#include "ymx/audio_buffer.hpp"
#include "ymx/audio_reverb.hpp"
#include "ymx/ymx_signal.hpp"

#include "audio/handler.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx chip class initialization function implementations ***********************************************/



// private nullify

void chip::__nullify()
{
	s16pp_operator_buffers = NULL;

	s16p_output_buffer = NULL;

	s32_mixer_channel = -1;

	buffer_chip = NULL;

	s32_channels = 0;

	f32_volume = 0.f;

	f32_fade_strength = 0.f;
	f32_fade_mod      = 0.f;

	bl_debug = false;

	container_operators.clear();
	container_active.clear();

	s32p_operator_output = NULL;

	container_commands.clear();

	fori(3)
	{
		s32a_opm_execute_buffer[i] = 0;
		s32a_opm_return_buffer [i] = 0;
	}

	fori(2)
	{
		s32a_envelope_counter[i] = 0;
	}

	reverb_filter = NULL;

	bl_reverb = false;

	thread_track = NULL;

	track_current       = NULL;
	s32_current_section =    0;
	s32_current_command =    0;

	bl_track_playing  = false;
	bl_track_interput = false;

	u32_play_count = 0;

	s32_algorithm = 0;

	band_chip = NULL;
}



// constructor

chip::chip()
{
	__nullify();
}
chip::chip( s32 _s32_mixer_channel, s32 _s32_channels, bl _bl_using_reverb )
{
	__nullify();

	initialize( _s32_mixer_channel, _s32_channels, _bl_using_reverb );
}

// destructor

chip::~chip()
{
	discard();
}



// initialize

result chip::initialize( s32 _s32_mixer_channel, s32 _s32_channels, bl _bl_using_reverb )
{
	s16pp_operator_buffers = new s16*[4];

	fori(4)
	{
		s16pp_operator_buffers[i] = new s16[ audio::get_chunk_size() ];

		memset( s16pp_operator_buffers[i], 0, audio::get_chunk_size() * sizeof(s16) );
	}

	s16p_output_buffer = new s16[ audio::get_chunk_size() ];

	memset( s16p_output_buffer, 0, audio::get_chunk_size() * sizeof(s16) );

	s32_mixer_channel = _s32_mixer_channel;

	buffer_chip = new audio::buffer( audio::get_chunk_size() );

	s32_channels = _s32_channels;

	f32_volume = 1.f;

	f32_fade_strength = 1.f;
	f32_fade_mod      = 0.f;

	bl_debug = false;

	container_operators.initialize( s32_channels );
	container_active.initialize(    s32_channels );

	fori( s32_channels )
	{
		container_operators[i].initialize(4);

		container_active[i].initialize(4);

		forj(4)
		{
			container_operators[i][j].initialize(this);

			container_active[i][j] = 1;
	} }

	s32p_operator_output = new volatile s32[ s32_channels ];

	fori( s32_channels )
	{
		signal().apply_all( this, i );
	}

	if( _bl_using_reverb )
	{
		reverb_filter = new audio::reverb( audio::get_chunk_size() );
	}

	bl_reverb = false;

	band_chip = new audio::band( audio::get_chunk_size() );

	reset();

	return 1;
}

// discard

result chip::discard()
{
	delete buffer_chip;

	fori(4)
	{
		delete[] s16pp_operator_buffers[i];
	}

	delete[] s16p_output_buffer;

	delete[] s16pp_operator_buffers;

	delete reverb_filter; reverb_filter = NULL;

	delete[] s32p_operator_output;

	delete band_chip;

	return 1;
}



/* end */
}}
#endif
