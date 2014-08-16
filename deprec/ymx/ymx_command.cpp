
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_COMMAND_CPP
#define BDAPI_YMX_COMMAND_CPP
#include "ymx/ymx_command.hpp"

/* includes */

// bdapi
#include "ymx/ymx_core.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx command class implementation *********************************************************************/



// constructors

command::command()
{
	clear();
}
command::command( s32 _s32_function, s32 _s32_value, s32 _s32_channel, s32 _s32_operator )
{
	set_command( _s32_function, _s32_value, _s32_channel, _s32_operator );
}
command::command( u8* _u8p_data )
{
	set_command( _u8p_data );
}
command::command( const command& c )
{
	set_command(c);
}



// load from file

void command::load( io::file& _uf )
{
	fori(4)
		commands[i] = _uf.out<u8>();
}

// save to file

void command::save( io::file& _uf )
{
	fori(4)
		_uf.in<u8>( commands[i] );
}



// operator [] s32

s32& command::operator [] ( s32 i )
{
	return commands[ i % 4 ];
}

// const operator [] s32

const s32& command::operator [] ( s32 i ) const
{
	return commands[ i % 4 ];
}



// operator == command

bl command::operator == ( const command& c ) const
{
	fori(4)
		if( commands[i] != c.commands[i] )
			return false;

	return true;
}

// operator != command

bl command::operator != ( const command& c ) const
{
	return !( *this == c );
}



// operator == s32

bl command::operator == ( s32 v ) const
{
	if( commands[0] == v )
		return true;

	return false;
}

// operator != s32

bl command::operator != ( s32 v ) const
{
	return !( *this == v );
}



// clear

command& command::clear()
{
	fori(4)
		commands[i] = 0;

	return *this;
}



// set command

command& command::set_command( s32 _s32_function, s32 _s32_value, s32 _s32_channel, s32 _s32_operator )
{
	commands[0] = _s32_function;
	commands[1] = _s32_value;
	commands[2] = _s32_channel;
	commands[3] = _s32_operator;

	return *this;
}
command& command::set_command( u8* _u8p_ptr )
{
	commands[0] = _u8p_ptr[0];
	commands[1] = _u8p_ptr[1];
	commands[2] = _u8p_ptr[2];
	commands[3] = _u8p_ptr[3];

	return *this;
}
command& command::set_command( const command& c )
{
	commands[0] = c.commands[0];
	commands[1] = c.commands[1];
	commands[2] = c.commands[2];
	commands[3] = c.commands[3];

	return *this;
}



// set commands

command& command::set_command_null() {
	return set_command( YMX_CMND_NULL, 0, 0, 0 ); }

command& command::set_command_key_on ( s32 c ) {
	return set_command( YMX_CMND_KEY_ON,  0, c, 0 ); }
command& command::set_command_key_off( s32 c ) {
	return set_command( YMX_CMND_KEY_OFF, 0, c, 0 ); }

command& command::set_command_note_one( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_NOTE_ONE,YMX_KC(v),c,o%4 );}
command& command::set_command_note_all( s32 v, s32 c        ) {
	return set_command( YMX_CMND_NOTE_ALL,YMX_KC(v),c,0   );}

command& command::set_command_alg( s32 v, s32 c ) {
	return set_command( YMX_CMND_ALG, YMX_ALG(v), c, 0 ); }

command& command::set_command_op ( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_OP,  YMX_OP( v), c, o%4 ); }
command& command::set_command_ns ( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_NS,  YMX_NS( v), c, o%4 ); }
command& command::set_command_ne ( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_NE,  YMX_NE( v), c, o%4 ); }
command& command::set_command_ame( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_AME, YMX_AME(v), c, o%4 ); }

command& command::set_command_tl ( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_TL,  YMX_TL( v), c, o%4 ); }
command& command::set_command_ar ( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_AR,  YMX_AR( v), c, o%4 ); }
command& command::set_command_d1r( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_D1R, YMX_D1R(v), c, o%4 ); }
command& command::set_command_d1l( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_D1L, YMX_D1L(v), c, o%4 ); }
command& command::set_command_d2r( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_D2R, YMX_D2R(v), c, o%4 ); }
command& command::set_command_rr ( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_RR,  YMX_RR( v), c, o%4 ); }

command& command::set_command_owf( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_OWF, YMX_OP( v), c, o%4 ); }
command& command::set_command_mul( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_MUL, YMX_MUL(v), c, o%4 ); }
command& command::set_command_kc ( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_KC,  YMX_KC( v), c, o%4 ); }
command& command::set_command_kf ( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_KF,  YMX_KF( v), c, o%4 ); }
command& command::set_command_fb ( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_FB,  YMX_FB( v), c, o%4 ); }
command& command::set_command_nfq( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_NFQ, YMX_NFQ(v), c, o%4 ); }

command& command::set_command_lwf( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_LWF, YMX_LWF(v), c, o%4 ); }
command& command::set_command_frq( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_FRQ, YMX_FRQ(v), c, o%4 ); }
command& command::set_command_amd( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_AMD, YMX_AMD(v), c, o%4 ); }
command& command::set_command_ams( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_AMS, YMX_AMS(v), c, o%4 ); }
command& command::set_command_pmd( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_PMD, YMX_PMD(v), c, o%4 ); }
command& command::set_command_pms( s32 v, s32 c, s32 o ) {
	return set_command( YMX_CMND_PMS, YMX_PMS(v), c, o%4 ); }

command& command::set_command_lfo_reset( s32 c, s32 o ) {
	return set_command( YMX_CMND_LFO_RESET, 0, c, o%4 ); }
command& command::set_command_lfo_start( s32 c, s32 o ) {
	return set_command( YMX_CMND_LFO_START, 0, c, o%4 ); }



// get command parameter

s32 command::get_parameter( s32 i ) const
{
	return commands[ i % 4 ];
}

// get command function

s32 command::get_function() const
{
	return commands[0];
}

// get command value

s32 command::get_value() const
{
	return commands[1];
}

// get command channel

s32 command::get_channel() const
{
	return commands[2];
}

// get command operator

s32 command::get_operator() const
{
	return commands[3];
}



/* end */
}}
#endif
