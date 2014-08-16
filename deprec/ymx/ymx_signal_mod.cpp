
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_SIGNAL_MOD_CPP
#define BDAPI_YMX_SIGNAL_MOD_CPP
#include "ymx/ymx_signal.hpp"

/* includes */

// bdapi
#include "ymx/ymx_core.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx signal class modification function implementations ***********************************************/



// shift alg

s32 signal::shift_alg( s32 v ) { return alg = YMX_ALG( alg + v ); }

// shift primary

s32 signal::shift_op ( s32 o, s32 v ) { chk_O(o); return op [o] = YMX_OP ( op [o] + v ); }
s32 signal::shift_ns ( s32 o, s32 v ) { chk_O(o); return ns [o] = YMX_NS ( ns [o] + v ); }
s32 signal::shift_ne ( s32 o, s32 v ) { chk_O(o); return ne [o] = YMX_NE ( ne [o] + v ); }
s32 signal::shift_ame( s32 o, s32 v ) { chk_O(o); return ame[o] = YMX_AME( ame[o] + v ); }

// shift secondary 1

s32 signal::shift_tl ( s32 o, s32 v ) { return shift_tl ( 1, o, v ); }
s32 signal::shift_ar ( s32 o, s32 v ) { return shift_ar ( 1, o, v ); }
s32 signal::shift_d1r( s32 o, s32 v ) { return shift_d1r( 1, o, v ); }
s32 signal::shift_d1l( s32 o, s32 v ) { return shift_d1l( 1, o, v ); }
s32 signal::shift_d2r( s32 o, s32 v ) { return shift_d2r( 1, o, v ); }
s32 signal::shift_rr ( s32 o, s32 v ) { return shift_rr ( 1, o, v ); }
s32 signal::shift_mul( s32 o, s32 v ) { return shift_mul( 1, o, v ); }
s32 signal::shift_kc ( s32 o, s32 v ) { return shift_kc ( 1, o, v ); }
s32 signal::shift_kf ( s32 o, s32 v ) { return shift_kf ( 1, o, v ); }
s32 signal::shift_fb ( s32 o, s32 v ) { return shift_fb ( 1, o, v ); }
s32 signal::shift_nfq( s32 o, s32 v ) { return shift_nfq( 1, o, v ); }
s32 signal::shift_frq( s32 o, s32 v ) { return shift_frq( 1, o, v ); }
s32 signal::shift_amd( s32 o, s32 v ) { return shift_amd( 1, o, v ); }
s32 signal::shift_ams( s32 o, s32 v ) { return shift_ams( 1, o, v ); }
s32 signal::shift_pmd( s32 o, s32 v ) { return shift_pmd( 1, o, v ); }
s32 signal::shift_pms( s32 o, s32 v ) { return shift_pms( 1, o, v ); }

// shift wf 1

s32 signal::shift_owf( s32 o, s32 v ) { chk_O(o); return owf[o] = YMX_OWF( owf[o] + v ); }
s32 signal::shift_lwf( s32 o, s32 v ) { chk_O(o); return lwf[o] = YMX_LWF( lwf[o] + v ); }



// shift secondary 2

s32 signal::shift_tl ( s32 c, s32 o, s32 v ) { chk_CO(c,o); return tl [c][o] = YMX_TL ( tl [c][o] + v ); }
s32 signal::shift_ar ( s32 c, s32 o, s32 v ) { chk_CO(c,o); return ar [c][o] = YMX_AR ( ar [c][o] + v ); }
s32 signal::shift_d1r( s32 c, s32 o, s32 v ) { chk_CO(c,o); return d1r[c][o] = YMX_D1R( d1r[c][o] + v ); }
s32 signal::shift_d1l( s32 c, s32 o, s32 v ) { chk_CO(c,o); return d1l[c][o] = YMX_D1L( d1l[c][o] + v ); }
s32 signal::shift_d2r( s32 c, s32 o, s32 v ) { chk_CO(c,o); return d2r[c][o] = YMX_D2R( d2r[c][o] + v ); }
s32 signal::shift_rr ( s32 c, s32 o, s32 v ) { chk_CO(c,o); return rr [c][o] = YMX_RR ( rr [c][o] + v ); }
s32 signal::shift_mul( s32 c, s32 o, s32 v ) { chk_CO(c,o); return mul[c][o] = YMX_MUL( mul[c][o] + v ); }
s32 signal::shift_kc ( s32 c, s32 o, s32 v ) { chk_CO(c,o); return kc [c][o] = YMX_KC ( kc [c][o] + v ); }
s32 signal::shift_kf ( s32 c, s32 o, s32 v ) { chk_CO(c,o); return kf [c][o] = YMX_KF ( kf [c][o] + v ); }
s32 signal::shift_fb ( s32 c, s32 o, s32 v ) { chk_CO(c,o); return fb [c][o] = YMX_FB ( fb [c][o] + v ); }
s32 signal::shift_nfq( s32 c, s32 o, s32 v ) { chk_CO(c,o); return nfq[c][o] = YMX_NFQ( nfq[c][o] + v ); }
s32 signal::shift_frq( s32 c, s32 o, s32 v ) { chk_CO(c,o); return frq[c][o] = YMX_FRQ( frq[c][o] + v ); }
s32 signal::shift_amd( s32 c, s32 o, s32 v ) { chk_CO(c,o); return amd[c][o] = YMX_AMD( amd[c][o] + v ); }
s32 signal::shift_ams( s32 c, s32 o, s32 v ) { chk_CO(c,o); return ams[c][o] = YMX_AMS( ams[c][o] + v ); }
s32 signal::shift_pmd( s32 c, s32 o, s32 v ) { chk_CO(c,o); return pmd[c][o] = YMX_PMD( pmd[c][o] + v ); }
s32 signal::shift_pms( s32 c, s32 o, s32 v ) { chk_CO(c,o); return pms[c][o] = YMX_PMS( pms[c][o] + v ); }



/* end */
}}
#endif
