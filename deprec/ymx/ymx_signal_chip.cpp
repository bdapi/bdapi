
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_SIGNAL_CHIP_CPP
#define BDAPI_YMX_SIGNAL_CHIP_CPP
#include "ymx/ymx_signal.hpp"

/* includes */

// bdapi
#include "ymx/ymx_chip.hpp"
#include "ymx/ymx_core.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx signal class chip function implementations *******************************************************/



// apply key

void signal::apply_key_on ( chip* h, s32 c ) { h->set_command_key_on (c); }
void signal::apply_key_off( chip* h, s32 c ) { h->set_command_key_off(c); }

// apply note

void signal::apply_note_one( chip* h, s32 c, s32 o, s32 n )
{
	chk_O(o);

	if( ns[o] == 1 )
		h->set_command_kc( YMX_KC( kc[0][o] + n ), c, o );
	else
		h->set_command_kc(         kc[0][o],       c, o );
}
void signal::apply_note_all( chip* h, s32 c, s32 n )
{
	fori(4)
		apply_note_one( h, c, i, n );
}



// apply

void signal::apply_alg( chip* h, s32 c        ) {           h->set_command_alg( alg,       c    ); }
void signal::apply_op ( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_op ( op    [o], c, o ); }
void signal::apply_ne ( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_ne ( ne    [o], c, o ); }
void signal::apply_ns ( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_ns ( ns    [o], c, o ); }
void signal::apply_ame( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_ame( ame   [o], c, o ); }
void signal::apply_tl ( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_tl ( tl [0][o], c, o ); }
void signal::apply_ar ( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_ar ( ar [0][o], c, o ); }
void signal::apply_d1r( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_d1r( d1r[0][o], c, o ); }
void signal::apply_d1l( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_d1l( d1l[0][o], c, o ); }
void signal::apply_d2r( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_d2r( d2r[0][o], c, o ); }
void signal::apply_rr ( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_rr ( rr [0][o], c, o ); }
void signal::apply_owf( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_owf( owf   [o], c, o ); }
void signal::apply_mul( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_mul( mul[0][o], c, o ); }
void signal::apply_kc ( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_kc ( kc [0][o], c, o ); }
void signal::apply_kf ( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_kf ( kf [0][o], c, o ); }
void signal::apply_fb ( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_fb ( fb [0][o], c, o ); }
void signal::apply_nfq( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_nfq( nfq[0][o], c, o ); }
void signal::apply_lwf( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_lwf( lwf   [o], c, o ); }
void signal::apply_frq( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_frq( frq[0][o], c, o ); }
void signal::apply_amd( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_amd( amd[0][o], c, o ); }
void signal::apply_ams( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_ams( ams[0][o], c, o ); }
void signal::apply_pmd( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_pmd( pmd[0][o], c, o ); }
void signal::apply_pms( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_pms( pms[0][o], c, o ); }



// apply lfo

void signal::apply_lfo_reset( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_lfo_reset( c, o ); }
void signal::apply_lfo_start( chip* h, s32 c, s32 o ) { chk_O(o); h->set_command_lfo_start( c, o ); }



// apply operator

void signal::apply_operator( chip* h, s32 c, s32 o )
{
	chk_O(o);

	apply_op ( h, c, o );
	apply_ns ( h, c, o );
	apply_ne ( h, c, o );
	apply_ame( h, c, o );

	apply_tl ( h, c, o );
	apply_ar ( h, c, o );
	apply_d1r( h, c, o );
	apply_d1l( h, c, o );
	apply_d2r( h, c, o );
	apply_rr ( h, c, o );

	apply_owf( h, c, o );
	apply_mul( h, c, o );
	apply_kc ( h, c, o );
	apply_kf ( h, c, o );
	apply_fb ( h, c, o );
	apply_nfq( h, c, o );

	apply_lwf( h, c, o );
	apply_frq( h, c, o );
	apply_amd( h, c, o );
	apply_ams( h, c, o );
	apply_pmd( h, c, o );
	apply_pms( h, c, o );
}

// apply all

void signal::apply_all( chip* h, s32 c )
{
	apply_alg( h, c );

	fori(4)
		apply_operator( h, c, i );
}



/* end */
}}
#endif


