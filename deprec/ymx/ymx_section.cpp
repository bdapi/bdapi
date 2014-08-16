
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_SECTION_CPP
#define BDAPI_YMX_SECTION_CPP
#include "ymx/ymx_section.hpp"

/* includes */

// bdapi
#include "core/math.hpp"
#include "ymx/ymx_chip.hpp"
#include "ymx/ymx_core.hpp"
#include "ymx/ymx_signal.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* static variables *************************************************************************************/



static block __block_YMX_dummy__;



/* ymx section class implementation *********************************************************************/



// private nullify

void section::__nullify()
{
	s32_channels = 0;
	s32_blocks   = 0;

	container_blocks.clear();
}



// constructors

section::section()
{
	__nullify();
}
section::section( s32 _s32_channels, s32 _s32_blocks )
{
	__nullify();

	initialize( _s32_channels, _s32_blocks );
}
section::section( io::file& f )
{
	__nullify();

	initialize(f);
}
section::section( const section& s )
{
	__nullify();

	initialize(s);
}

// destructor

section::~section()
{
	discard();
}



// initializers

result section::initialize( s32 _s32_channels, s32 _s32_blocks )
{
	s32_channels = _s32_channels;
	s32_blocks   = _s32_blocks;

	container_blocks.initialize( s32_channels );

	fori( s32_channels )
		container_blocks[i].initialize( s32_blocks );

	return 1;
}
result section::initialize( io::file& f )
{
	load(f);

	return 1;
}
result section::initialize( const section& s )
{
	s32_channels = s.s32_channels;
	s32_blocks   = s.s32_blocks;

	container_blocks = s.container_blocks;

	return 1;
}

// discard

result section::discard()
{
	__nullify();

	return 1;
}



// load from file

void section::load( io::file& f )
{
	s32_channels = f.out<s32>();
	s32_blocks   = f.out<s32>();

	container_blocks.initialize( s32_channels );

	fori( s32_channels )
		container_blocks[i].initialize( s32_blocks );

	fori( s32_channels )
	{
		forj( s32_blocks )
		{
			block& b = container_blocks[i][j];

			s32 block_size = f.out<s32>();

			if( block_size > 0 )
			{
				b.initialize( block_size );

				fork( block_size )
				{
					b[k].load(f);
			} }
			else
			{
				b.clear();
} } } }

// save to file

void section::save( io::file& f )
{
	f.in<s32>( s32_channels );
	f.in<s32>( s32_blocks   );

	fori( s32_channels )
	{
		forj( s32_blocks )
		{
			block& b = container_blocks[i][j];

			s32 block_size = b.get_size();

			f.in<s32>( block_size );

			if( block_size > 0 )
			{
				fork( block_size )
				{
					b[k].save(f);
} } } } }



// clear block

block& section::clear_block( s32 _s32_channel, s32 _s32_index )
{
	container_blocks[ _s32_channel ][ _s32_index ].clear();

	return container_blocks[ _s32_channel ][ _s32_index ];
}

// clear channel

void section::clear_channel( s32 _s32_channel )
{
	fori( container_blocks[ _s32_channel ].get_size() )
		container_blocks[ _s32_channel ][i].clear();
}

// clear all

void section::clear_all()
{
	fori( s32_channels )
		clear_channel(i);
}



// get block

block& section::get_block( s32 _s32_channel, s32 _s32_index )
{
	return container_blocks[ _s32_channel ][ _s32_index ];
}



// set command

block& section::set_command( s32 _s32_index, s32 _s32_function, s32 _s32_value, s32 _s32_channel,
s32 _s32_operator )
{
	container_blocks[_s32_channel][_s32_index].insert( ymx::command( _s32_function, _s32_value,
		_s32_channel, _s32_operator ) );

	return container_blocks[_s32_channel][_s32_index];
}
block& section::set_command( s32 _s32_index, const ymx::command& c )
{
	container_blocks[ c.get_channel() ][_s32_index].insert(c);

	return container_blocks[ c.get_channel() ][_s32_index];
}



// set commands

block& section::set_command_null( s32 i, s32 c ) {
	return set_command( i, YMX_CMND_NULL, 0, c, 0 ); }

block& section::set_command_key_on ( s32 i, s32 c ) {
	return set_command( i, YMX_CMND_KEY_ON,  0, c, 0 ); }
block& section::set_command_key_off( s32 i, s32 c ) {
	return set_command( i, YMX_CMND_KEY_OFF, 0, c, 0 ); }

block& section::set_command_note_one( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_NOTE_ONE,YMX_KC(v),c,o%4 );}
block& section::set_command_note_all( s32 i, s32 v, s32 c        ) {
	return set_command( i, YMX_CMND_NOTE_ALL,YMX_KC(v),c,0   );}

block& section::set_command_alg( s32 i, s32 v, s32 c ) {
	return set_command( i, YMX_CMND_ALG, YMX_ALG(v), c, 0 ); }

block& section::set_command_op ( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_OP,  YMX_OP( v), c, o%4 ); }
block& section::set_command_ns ( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_NS,  YMX_NS( v), c, o%4 ); }
block& section::set_command_ne ( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_NE,  YMX_NE( v), c, o%4 ); }
block& section::set_command_ame( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_AME, YMX_AME(v), c, o%4 ); }

block& section::set_command_tl ( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_TL,  YMX_TL( v), c, o%4 ); }
block& section::set_command_ar ( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_AR,  YMX_AR( v), c, o%4 ); }
block& section::set_command_d1r( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_D1R, YMX_D1R(v), c, o%4 ); }
block& section::set_command_d1l( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_D1L, YMX_D1L(v), c, o%4 ); }
block& section::set_command_d2r( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_D2R, YMX_D2R(v), c, o%4 ); }
block& section::set_command_rr ( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_RR,  YMX_RR( v), c, o%4 ); }

block& section::set_command_owf( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_OWF, YMX_OP( v), c, o%4 ); }
block& section::set_command_mul( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_MUL, YMX_MUL(v), c, o%4 ); }
block& section::set_command_kc ( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_KC,  YMX_KC( v), c, o%4 ); }
block& section::set_command_kf ( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_KF,  YMX_KF( v), c, o%4 ); }
block& section::set_command_fb ( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_FB,  YMX_FB( v), c, o%4 ); }
block& section::set_command_nfq( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_NFQ, YMX_NFQ(v), c, o%4 ); }

block& section::set_command_lwf( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_LWF, YMX_LWF(v), c, o%4 ); }
block& section::set_command_frq( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_FRQ, YMX_FRQ(v), c, o%4 ); }
block& section::set_command_amd( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_AMD, YMX_AMD(v), c, o%4 ); }
block& section::set_command_ams( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_AMS, YMX_AMS(v), c, o%4 ); }
block& section::set_command_pmd( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_PMD, YMX_PMD(v), c, o%4 ); }
block& section::set_command_pms( s32 i, s32 v, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_PMS, YMX_PMS(v), c, o%4 ); }

block& section::set_command_lfo_reset( s32 i, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_LFO_RESET, 0, c, o%4 ); }
block& section::set_command_lfo_start( s32 i, s32 c, s32 o ) {
	return set_command( i, YMX_CMND_LFO_START, 0, c, o%4 ); }



/* end */
}}
#endif
