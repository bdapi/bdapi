
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_CHIP_COMMAND_CPP
#define BDAPI_YMX_CHIP_COMMAND_CPP
#include "ymx/ymx_chip.hpp"

/* includes */

// bdapi
#include "ymx/ymx_core.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx chip class command function implementations ******************************************************/


// clear commands

void chip::clear_commands()
{
	container_commands.clear();
}



// set command

void chip::set_command( s32 _function, s32 _value, s32 _channel, s32 _operator )
{
	set_command( command( _function, _value, _channel, _operator ) );
}
void chip::set_command( const ymx::command& c )
{
	if( c.get_channel() >= 0 && c.get_channel() < s32_channels )
		container_commands << c;
}



// set commands

void chip::set_command_null() { set_command( YMX_CMND_NULL, 0, 0, 0 ); }

void chip::set_command_key_on ( s32 c ) { set_command( YMX_CMND_KEY_ON,  0, c, 0 ); }
void chip::set_command_key_off( s32 c ) { set_command( YMX_CMND_KEY_OFF, 0, c, 0 ); }

void chip::set_command_note_one( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_NOTE_ONE,YMX_KC(v),c,o%4 );}
void chip::set_command_note_all( s32 v, s32 c        ) { set_command( YMX_CMND_NOTE_ALL,YMX_KC(v),c,0   );}

void chip::set_command_alg( s32 v, s32 c ) { set_command( YMX_CMND_ALG, YMX_ALG(v), c, 0 ); }

void chip::set_command_op ( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_OP,  YMX_OP( v), c, o%4 ); }
void chip::set_command_ns ( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_NS,  YMX_NS( v), c, o%4 ); }
void chip::set_command_ne ( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_NE,  YMX_NE( v), c, o%4 ); }
void chip::set_command_ame( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_AME, YMX_AME(v), c, o%4 ); }

void chip::set_command_tl ( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_TL,  YMX_TL( v), c, o%4 ); }
void chip::set_command_ar ( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_AR,  YMX_AR( v), c, o%4 ); }
void chip::set_command_d1r( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_D1R, YMX_D1R(v), c, o%4 ); }
void chip::set_command_d1l( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_D1L, YMX_D1L(v), c, o%4 ); }
void chip::set_command_d2r( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_D2R, YMX_D2R(v), c, o%4 ); }
void chip::set_command_rr ( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_RR,  YMX_RR( v), c, o%4 ); }

void chip::set_command_owf( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_OWF, YMX_OWF(v), c, o%4 ); }
void chip::set_command_mul( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_MUL, YMX_MUL(v), c, o%4 ); }
void chip::set_command_kc ( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_KC,  YMX_KC( v), c, o%4 ); }
void chip::set_command_kf ( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_KF,  YMX_KF( v), c, o%4 ); }
void chip::set_command_fb ( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_FB,  YMX_FB( v), c, o%4 ); }
void chip::set_command_nfq( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_NFQ, YMX_NFQ(v), c, o%4 ); }

void chip::set_command_lwf( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_LWF, YMX_LWF(v), c, o%4 ); }
void chip::set_command_frq( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_FRQ, YMX_FRQ(v), c, o%4 ); }
void chip::set_command_amd( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_AMD, YMX_AMD(v), c, o%4 ); }
void chip::set_command_ams( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_AMS, YMX_AMS(v), c, o%4 ); }
void chip::set_command_pmd( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_PMD, YMX_PMD(v), c, o%4 ); }
void chip::set_command_pms( s32 v, s32 c, s32 o ) { set_command( YMX_CMND_PMS, YMX_PMS(v), c, o%4 ); }

void chip::set_command_lfo_reset( s32 c, s32 o ) { set_command( YMX_CMND_LFO_RESET, 0, c, o%4 ); }
void chip::set_command_lfo_start( s32 c, s32 o ) { set_command( YMX_CMND_LFO_START, 0, c, o%4 ); }



/* end */
}}
#endif
