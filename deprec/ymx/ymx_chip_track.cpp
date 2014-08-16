
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_CHIP_TRACK_CPP
#define BDAPI_YMX_CHIP_TRACK_CPP
#include "ymx/ymx_chip.hpp"

/* includes */

// bdapi
#include "sys/handler.hpp"
#include "ymx/ymx_core.hpp"
#include "ymx/ymx_section.hpp"
#include "ymx/ymx_track.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* static function declarations *************************************************************************/



static void __chip_thread_func( chip* );



/* static function implementations **********************************************************************/


// static chip thread function

void __chip_thread_func( chip* _chip )
{
	s32 current_play_count = _chip->get_play_count();

	while( _chip->is_track_playing()
	&& current_play_count == _chip->get_play_count()
	&& !_chip->is_track_interupted()
	&& sys::get_subsystem_state() == SUBSYS_INITIALIZED )
	{
		_chip->execute_block();
} }


/* ymx chip class track function implementations ********************************************************/


// prepare next command

void chip::prepare_next_command( s32 _s32_channel, const command& _command )
{
	if( _command.get_function() == YMX_CMND_KEY_ON )
	{
		track_current->get_signal_current( _s32_channel )->apply_key_off( this, _s32_channel );
} }

// execute command

void chip::execute_command( s32 _s32_channel, const command& _command )
{
	s32 f = _command.get_function();
	s32 o = _command.get_operator();
	s32 v = _command.get_value();

	signal& s = *track_current->get_signal_current( _s32_channel );

	switch(f)
	{
		case YMX_CMND_NULL:
			break;

		case YMX_CMND_KEY_ON:    s.apply_key_on  ( this, _s32_channel );break;
		case YMX_CMND_KEY_OFF:   s.apply_key_off ( this, _s32_channel );break;

		case YMX_CMND_NOTE_ONE:  s.apply_note_one( this, _s32_channel, o%4, v%YMX_LIMIT_KC );break;
		case YMX_CMND_NOTE_ALL:  s.apply_note_all( this, _s32_channel,      v%YMX_LIMIT_KC );break;

		case YMX_CMND_ALG:       s.alg        =v%YMX_LIMIT_ALG;s.apply_alg( this, _s32_channel      );break;

		case YMX_CMND_OP:        s.op    [o%4]=v%YMX_LIMIT_OP; s.apply_op ( this, _s32_channel, o%4 );break;
		case YMX_CMND_NS:        s.ns    [o%4]=v%YMX_LIMIT_NS; s.apply_ns ( this, _s32_channel, o%4 );break;
		case YMX_CMND_NE:        s.ne    [o%4]=v%YMX_LIMIT_NE; s.apply_ne ( this, _s32_channel, o%4 );break;
		case YMX_CMND_AME:       s.ame   [o%4]=v%YMX_LIMIT_AME;s.apply_ame( this, _s32_channel, o%4 );break;

		case YMX_CMND_TL:        s.tl [0][o%4]=v%YMX_LIMIT_TL; s.apply_tl ( this, _s32_channel, o%4 );break;
		case YMX_CMND_AR:        s.ar [0][o%4]=v%YMX_LIMIT_AR; s.apply_ar ( this, _s32_channel, o%4 );break;
		case YMX_CMND_D1R:       s.d1r[0][o%4]=v%YMX_LIMIT_D1R;s.apply_d1r( this, _s32_channel, o%4 );break;
		case YMX_CMND_D1L:       s.d1l[0][o%4]=v%YMX_LIMIT_D1L;s.apply_d1l( this, _s32_channel, o%4 );break;
		case YMX_CMND_D2R:       s.d2r[0][o%4]=v%YMX_LIMIT_D2R;s.apply_d2r( this, _s32_channel, o%4 );break;
		case YMX_CMND_RR:        s.rr [0][o%4]=v%YMX_LIMIT_RR; s.apply_rr ( this, _s32_channel, o%4 );break;

		case YMX_CMND_OWF:       s.owf   [o%4]=v%YMX_LIMIT_OWF;s.apply_owf( this, _s32_channel, o%4 );break;
		case YMX_CMND_MUL:       s.mul[0][o%4]=v%YMX_LIMIT_MUL;s.apply_mul( this, _s32_channel, o%4 );break;
		case YMX_CMND_KC:        s.kc [0][o%4]=v%YMX_LIMIT_KC; s.apply_kc ( this, _s32_channel, o%4 );break;
		case YMX_CMND_KF:        s.kf [0][o%4]=v%YMX_LIMIT_KF; s.apply_kf ( this, _s32_channel, o%4 );break;
		case YMX_CMND_FB:        s.fb [0][o%4]=v%YMX_LIMIT_FB; s.apply_fb ( this, _s32_channel, o%4 );break;
		case YMX_CMND_NFQ:       s.nfq[0][o%4]=v%YMX_LIMIT_NFQ;s.apply_nfq( this, _s32_channel, o%4 );break;

		case YMX_CMND_LWF:       s.lwf   [o%4]=v%YMX_LIMIT_LWF;s.apply_lwf( this, _s32_channel, o%4 );break;
		case YMX_CMND_FRQ:       s.frq[0][o%4]=v%YMX_LIMIT_FRQ;s.apply_frq( this, _s32_channel, o%4 );break;
		case YMX_CMND_AMD:       s.amd[0][o%4]=v%YMX_LIMIT_AMD;s.apply_amd( this, _s32_channel, o%4 );break;
		case YMX_CMND_AMS:       s.ams[0][o%4]=v%YMX_LIMIT_AMS;s.apply_ams( this, _s32_channel, o%4 );break;
		case YMX_CMND_PMD:       s.pmd[0][o%4]=v%YMX_LIMIT_PMD;s.apply_pmd( this, _s32_channel, o%4 );break;
		case YMX_CMND_PMS:       s.pms[0][o%4]=v%YMX_LIMIT_PMS;s.apply_pms( this, _s32_channel, o%4 );break;

		case YMX_CMND_LFO_RESET: s.apply_lfo_reset( this, _s32_channel, o%4 );break;
		case YMX_CMND_LFO_START: s.apply_lfo_start( this, _s32_channel, o%4 );break;

		default:
			break;
} }

// execute block

void chip::execute_block()
{
	boost::lock_guard<boost::mutex>_( mutex_chip );

	if( s32_current_section >= track_current->get_sections() )
	{
		bl_track_playing = false;

		return;
	}

	section* p = track_current->get_section( s32_current_section );

	if( !p )
	{
		bl_track_playing = false;

		return;
	}

	section& s = *p;

	s32 section_channels = s.get_channels();

	fori( section_channels )
	{
		block& b = s.get_block( i, s32_current_command );

		forj( b.get_size() )
		{
			command& c = b.get(j);

			execute_command( i, c );
	} }

	s32_current_command++;

	if( s32_current_command >= s.get_blocks() )
	{
		s32_current_command = 0;

		s32_current_section++;

		if( s32_current_section >= track_current->get_sections() )
		{
			if( track_current->is_looping() )
			{
				s32_current_section = track_current->get_loop_index();
			}
			else
			{
				s32_current_section = 0;

				fade_out_track();

				// continue playing?

				bl_track_playing = false;

				return;
	} } }

	if( bl_track_playing )
	{
		p = track_current->get_section( s32_current_section );

		if(p)
		{
			s = *p;

			mutex_chip.unlock();

			thread_track->sleep( boost::get_system_time() + boost::posix_time::milliseconds(
				track_current->get_half_sleep_time() * 1000.0 ) );

			mutex_chip.lock();

			if( bl_track_interput || !bl_track_playing )
			{
				bl_track_playing = false;

				return;
			}

			section_channels = s.get_channels();

			fori( section_channels )
			{
				block& b = s.get_block( i, s32_current_command );

				forj( b.get_size() )
				{
					command& c = b.get(j);

					prepare_next_command( i, c );
			} }

			mutex_chip.unlock();

			thread_track->sleep( boost::get_system_time() + boost::posix_time::milliseconds(
				track_current->get_half_sleep_time() * 1000.0 ) );

			mutex_chip.lock();

			if( bl_track_interput || !bl_track_playing )
			{
				bl_track_playing = false;

				return;
		} }
		else
		{
			bl_track_playing = false;

			return;
} } }



// play track

result chip::play_track( track* _track )
{
	u32_play_count++;

	stop_track();

	delete thread_track;

	boost::lock_guard<boost::mutex>_( mutex_chip );

	f32_fade_strength = 1.f;
	f32_fade_mod      = 0.f;

	track_current = _track;

	s32_current_section = 0;
	s32_current_command = 0;

	reset();

	fori( track_current->get_channels() )
		track_current->get_signal_current(i)->apply_all( this, i );

	bl_track_playing  = true;
	bl_track_interput = false;

	thread_track = new boost::thread( __chip_thread_func, this );

	return 1;
}

// fade out track

result chip::fade_out_track()
{
	if( track_current && bl_track_playing )
	{
		fade( track_current->get_fade_time() );
	}

	return 1;
}

// stop track

result chip::stop_track()
{
	if( track_current && bl_track_playing )
	{
		bl_track_interput = true;

		boost::lock_guard<boost::mutex>_( mutex_chip );

		fade_out_track();

		bl_track_playing = false;
	}

	return 1;
}


/* end */
}}
#endif
