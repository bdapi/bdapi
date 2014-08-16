
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_TRACK_CPP
#define BDAPI_YMX_TRACK_CPP
#include "ymx/ymx_track.hpp"

/* includes */

// bdapi
#include "audio/handler.hpp"
#include "io/file.hpp"
#include "core/math.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx track class implementation ***********************************************************************/



// private nullify

void track::__nullify()
{
	rng_track = NULL;

	bl_music = false;

	s32_channels    = 0;
	s32_bpm_default = 0;
	s32_bpm_current = 0;

	f64_sleep_time      = 0.0;
	f64_half_sleep_time = 0.0;

	f32_fade_time = 0.f;

	bl_looping     = false;
	s32_loop_index =     0;

	container_signal_length.clear();
	container_signal_string.clear();

	container_signal_default.clear();
	container_signal_current.clear();

	container_sections.clear();
}



// private calculate bpm

void track::__calculate_bpm()
{
	f64_sleep_time      = 1.0 / (f64)s32_bpm_current;
	f64_half_sleep_time = f64_sleep_time * 0.5;
}



// constructors

track::track()
{
	__nullify();
}
track::track( gen::rng* _rng_track, bl _bl_music, s32 _s32_channels, s32 _s32_bpm, f32 _f32_fade_time,
bl _bl_looping, s32 _s32_loop_index )
{
	initialize( _rng_track, _bl_music, _s32_channels, _s32_bpm, _f32_fade_time, _bl_looping,
		_s32_loop_index );
}
track::track( gen::rng* _rng_track, string _string_filename )
{
	initialize( _rng_track, _string_filename );
}
track::track( const track& t )
{
	initialize(t);
}

// destructor

track::~track()
{
	discard();
}



// initializers

result track::initialize( gen::rng* _rng_track, bl _bl_music, s32 _s32_channels, s32 _s32_bpm,
f32 _f32_fade_time, bl _bl_looping, s32 _s32_loop_index )
{
	__nullify();

	rng_track = _rng_track;

	bl_music = _bl_music;

	if( bl_music )
	{
		if( _s32_channels > 12 )
			s32_channels = 12;
		else
			s32_channels = _s32_channels;
	}
	else
	{
		if( _s32_channels > 4 )
			s32_channels = 4;
		else
			s32_channels = _s32_channels;
	}

	s32_bpm_default = _s32_bpm;
	s32_bpm_current = s32_bpm_default;

	__calculate_bpm();

	f32_fade_time = _f32_fade_time;

	bl_looping     = _bl_looping;
	s32_loop_index = _s32_loop_index;

	container_signal_length.initialize( s32_channels, 0 );
	container_signal_string.initialize( s32_channels    );

	container_signal_default.initialize( s32_channels, signal( rng_track ) );
	container_signal_current.initialize( s32_channels, signal( rng_track ) );

	return 1;
}
result track::initialize( gen::rng* _rng_track, string _string_filename )
{
	__nullify();

	rng_track = _rng_track;

	if( !load( _string_filename ) )
	{
		return 0;
	}

	return 1;
}
result track::initialize( const track& t )
{
	rng_track = t.rng_track;

	bl_music = t.bl_music;

	s32_channels    = t.s32_channels;
	s32_bpm_default = t.s32_bpm_default;
	s32_bpm_current = t.s32_bpm_current;

	f64_sleep_time      = t.f64_sleep_time;
	f64_half_sleep_time = t.f64_half_sleep_time;

	f32_fade_time = t.f32_fade_time;

	bl_looping     = t.bl_looping;
	s32_loop_index = t.s32_loop_index;

	container_signal_length = t.container_signal_length;
	container_signal_string = t.container_signal_string;

	container_signal_default = t.container_signal_default;
	container_signal_current = t.container_signal_current;

	container_sections = t.container_sections;

	return 1;
}

// discard

result track::discard()
{
	return 1;
}



// load from file

result track::load( string _string_filename )
{
	io::file file_ymt( _string_filename );

	if( !file_ymt.read( true ) )
	{
		return 0;
	}

	bl_music = file_ymt.out<bl>();

	s32_channels    = file_ymt.out<s32>();
	s32_bpm_default = file_ymt.out<s32>();
	s32_bpm_current = s32_bpm_default;

	__calculate_bpm();

	f32_fade_time = file_ymt.out<f32>();

	bl_looping     = file_ymt.out<bl>();
	s32_loop_index = file_ymt.out<s32>();

	container_signal_length.initialize( s32_channels, 0 );
	container_signal_string.initialize( s32_channels    );

	fori( s32_channels )
		container_signal_length[i] = file_ymt.out<s32>();

	fori( s32_channels )
		if( container_signal_length[i] > 0 )
			container_signal_string[i] = file_ymt.out<string>();

	container_signal_default.initialize( s32_channels, signal( rng_track ) );
	container_signal_current.initialize( s32_channels, signal( rng_track ) );

	fori( s32_channels )
	{
		if( container_signal_length[i] > 0 )
		{
			if( !container_signal_default[i].load( rng_track, container_signal_string[i] ) )
			{
				return 0;
		} }
		else
		{
			if( !container_signal_default[i].load( rng_track, file_ymt ) )
			{
				return 0;
		} }

		container_signal_current[i] = container_signal_default[i];
	}

	s32 section_amount = file_ymt.out<s32>();

	container_sections.initialize( section_amount );

	fori( section_amount )
		container_sections[i].load( file_ymt );

	return 1;
}

// save to file

result track::save( string _string_filename )
{
	io::file file_ymt( _string_filename );

	file_ymt.in<bl>( bl_music );

	file_ymt.in<s32>( s32_channels    );
	file_ymt.in<s32>( s32_bpm_default );

	file_ymt.in<f32>( f32_fade_time );

	file_ymt.in<bl> ( bl_looping     );
	file_ymt.in<s32>( s32_loop_index );

	fori( s32_channels )
		file_ymt.in<s32>( container_signal_length[i] );

	fori( s32_channels )
		if( container_signal_length[i] > 0 )
			file_ymt.in<string>( container_signal_string[i] );

	fori( s32_channels )
	{
		if( container_signal_length[i] == 0 )
		{
			if( !container_signal_default[i].save( file_ymt ) )
			{
				return 0;
	} } }

	s32 section_amount = container_sections.get_size();

	file_ymt.in<s32>( section_amount );

	fori( section_amount )
		container_sections[i].save( file_ymt );

	if( !file_ymt.save( true ) )
	{
		return 0;
	}

	return 1;
}



// set signal

result track::set_signal( s32 i )
{
	if( math<s32>::within( i, s32_channels ) )
	{
		container_signal_current[i] = container_signal_default[i];

		return 1;
	}

	return 0;
}
result track::set_signal( s32 i, const signal& s )
{
	if( math<s32>::within( i, s32_channels ) )
	{
		container_signal_default[i] = s;

		set_signal(i);

		container_signal_length[i] = 0;
		container_signal_string[i].clear();

		return 1;
	}

	return 0;
}
result track::set_signal( s32 i, string _string_filename )
{
	if( math<s32>::within( i, s32_channels ) )
	{
		if( !container_signal_default[i].load( _string_filename ) )
		{
			return 0;
		}

		set_signal(i);

		container_signal_length[i] = _string_filename.size();
		container_signal_string[i] = _string_filename;

		return 1;
	}

	return 0;
}



// get default signal

signal* track::get_signal_default( s32 i )
{
	if( math<s32>::within( i, s32_channels ) )
		return &container_signal_default[i];
	else
		return NULL;
}

// get current signal

signal* track::get_signal_current( s32 i )
{
	if( math<s32>::within( i, s32_channels ) )
		return &container_signal_current[i];
	else
		return NULL;
}



// add section

result track::add_section( const section& s )
{
	if( s.get_channels() != s32_channels )
	{
		return 0;
	}

	container_sections.insert(s);

	return 1;
}



// get section

section* track::get_section( s32 i )
{
	if( math<s32>::within( i, container_sections.get_size() ) )
		return &container_sections[i];
	else
		return NULL;
}



// get sections

s32 track::get_sections() const
{
	return container_sections.get_size();
}



// set bpm

track& track::set_bpm()
{
	return set_bpm( s32_bpm_default );
}
track& track::set_bpm( s32 i )
{
	if( i > 0 )
	{
		s32_bpm_current = i;

		__calculate_bpm();
	}

	return *this;
}

// shift bpm

track& track::shift_bpm( s32 i )
{
	return set_bpm( s32_bpm_current + i );
}



/* end */
}}
#endif
