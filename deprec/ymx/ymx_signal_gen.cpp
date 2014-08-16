
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_SIGNAL_GEN_CPP
#define BDAPI_YMX_SIGNAL_GEN_CPP
#include "ymx/ymx_signal.hpp"

/* includes */

// bdapi
#include "gen/rng.hpp"
#include "ymx/ymx_core.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx signal class generation function implementations *************************************************/



// generate alg 1

s32 signal::gen_alg() { return alg = rnd(YMX_LIMIT_ALG); }

// generate primary 1

s32 signal::gen_op ( s32 o ) { chk_O(o); return op [o] = rnd(YMX_LIMIT_OP ); }
s32 signal::gen_ns ( s32 o ) { chk_O(o); return ns [o] = rnd(YMX_LIMIT_NS ); }
s32 signal::gen_ne ( s32 o ) { chk_O(o); return ne [o] = rnd(YMX_LIMIT_NE ); }
s32 signal::gen_ame( s32 o ) { chk_O(o); return ame[o] = rnd(YMX_LIMIT_AME); }

// generate secondary 1

s32 signal::gen_tl ( s32 o ) { return gen_tl ( 1, o ); }
s32 signal::gen_ar ( s32 o ) { return gen_ar ( 1, o ); }
s32 signal::gen_d1r( s32 o ) { return gen_d1r( 1, o ); }
s32 signal::gen_d1l( s32 o ) { return gen_d1l( 1, o ); }
s32 signal::gen_d2r( s32 o ) { return gen_d2r( 1, o ); }
s32 signal::gen_rr ( s32 o ) { return gen_rr ( 1, o ); }
s32 signal::gen_mul( s32 o ) { return gen_mul( 1, o ); }
s32 signal::gen_kc ( s32 o ) { return gen_kc ( 1, o ); }
s32 signal::gen_kf ( s32 o ) { return gen_kf ( 1, o ); }
s32 signal::gen_fb ( s32 o ) { return gen_fb ( 1, o ); }
s32 signal::gen_nfq( s32 o ) { return gen_nfq( 1, o ); }
s32 signal::gen_frq( s32 o ) { return gen_frq( 1, o ); }
s32 signal::gen_amd( s32 o ) { return gen_amd( 1, o ); }
s32 signal::gen_ams( s32 o ) { return gen_ams( 1, o ); }
s32 signal::gen_pmd( s32 o ) { return gen_pmd( 1, o ); }
s32 signal::gen_pms( s32 o ) { return gen_pms( 1, o ); }

// generate wf 1

s32 signal::gen_owf( s32 o ) { chk_O(o); return owf[o] = rnd(YMX_LIMIT_OWF); }
s32 signal::gen_lwf( s32 o ) { chk_O(o); return lwf[o] = rnd(YMX_LIMIT_LWF); }



// generate secondary 2

s32 signal::gen_tl ( s32 c, s32 o ) { chk_CO(c,o); return tl [c][o] = rnd(YMX_LIMIT_TL ); }
s32 signal::gen_ar ( s32 c, s32 o ) { chk_CO(c,o); return ar [c][o] = rnd(YMX_LIMIT_AR ); }
s32 signal::gen_d1r( s32 c, s32 o ) { chk_CO(c,o); return d1r[c][o] = rnd(YMX_LIMIT_D1R); }
s32 signal::gen_d1l( s32 c, s32 o ) { chk_CO(c,o); return d1l[c][o] = rnd(YMX_LIMIT_D1L); }
s32 signal::gen_d2r( s32 c, s32 o ) { chk_CO(c,o); return d2r[c][o] = rnd(YMX_LIMIT_D2R); }
s32 signal::gen_rr ( s32 c, s32 o ) { chk_CO(c,o); return rr [c][o] = rnd(YMX_LIMIT_RR ); }
s32 signal::gen_mul( s32 c, s32 o ) { chk_CO(c,o); return mul[c][o] = rnd(YMX_LIMIT_MUL); }
s32 signal::gen_kc ( s32 c, s32 o ) { chk_CO(c,o); return kc [c][o] = rnd(YMX_LIMIT_KC ); }
s32 signal::gen_kf ( s32 c, s32 o ) { chk_CO(c,o); return kf [c][o] = rnd(YMX_LIMIT_KF ); }
s32 signal::gen_fb ( s32 c, s32 o ) { chk_CO(c,o); return fb [c][o] = rnd(YMX_LIMIT_FB ); }
s32 signal::gen_nfq( s32 c, s32 o ) { chk_CO(c,o); return nfq[c][o] = rnd(YMX_LIMIT_NFQ); }
s32 signal::gen_frq( s32 c, s32 o ) { chk_CO(c,o); return frq[c][o] = rnd(YMX_LIMIT_FRQ); }
s32 signal::gen_amd( s32 c, s32 o ) { chk_CO(c,o); return amd[c][o] = rnd(YMX_LIMIT_AMD); }
s32 signal::gen_ams( s32 c, s32 o ) { chk_CO(c,o); return ams[c][o] = rnd(YMX_LIMIT_AMS); }
s32 signal::gen_pmd( s32 c, s32 o ) { chk_CO(c,o); return pmd[c][o] = rnd(YMX_LIMIT_PMD); }
s32 signal::gen_pms( s32 c, s32 o ) { chk_CO(c,o); return pms[c][o] = rnd(YMX_LIMIT_PMS); }



// generate alg 2

s32 signal::gen_alg( s32 r ) { return alg = YMX_ALG( rnd(r) ); }

// generate primary 2

s32 signal::gen_op ( s32 o, s32 r ) { chk_O(o); return op [o] = YMX_OP ( rnd(r) ); }
s32 signal::gen_ns ( s32 o, s32 r ) { chk_O(o); return ns [o] = YMX_NS ( rnd(r) ); }
s32 signal::gen_ne ( s32 o, s32 r ) { chk_O(o); return ne [o] = YMX_NE ( rnd(r) ); }
s32 signal::gen_ame( s32 o, s32 r ) { chk_O(o); return ame[o] = YMX_AME( rnd(r) ); }

// generate secondary 3

s32 signal::gen_tl ( s32 c, s32 o, s32 r ) { chk_CO(c,o); return tl [c][o] = YMX_TL ( rnd(r) ); }
s32 signal::gen_ar ( s32 c, s32 o, s32 r ) { chk_CO(c,o); return ar [c][o] = YMX_AR ( rnd(r) ); }
s32 signal::gen_d1r( s32 c, s32 o, s32 r ) { chk_CO(c,o); return d1r[c][o] = YMX_D1R( rnd(r) ); }
s32 signal::gen_d1l( s32 c, s32 o, s32 r ) { chk_CO(c,o); return d1l[c][o] = YMX_D1L( rnd(r) ); }
s32 signal::gen_d2r( s32 c, s32 o, s32 r ) { chk_CO(c,o); return d2r[c][o] = YMX_D2R( rnd(r) ); }
s32 signal::gen_rr ( s32 c, s32 o, s32 r ) { chk_CO(c,o); return rr [c][o] = YMX_RR ( rnd(r) ); }
s32 signal::gen_mul( s32 c, s32 o, s32 r ) { chk_CO(c,o); return mul[c][o] = YMX_MUL( rnd(r) ); }
s32 signal::gen_kc ( s32 c, s32 o, s32 r ) { chk_CO(c,o); return kc [c][o] = YMX_KC ( rnd(r) ); }
s32 signal::gen_kf ( s32 c, s32 o, s32 r ) { chk_CO(c,o); return kf [c][o] = YMX_KF ( rnd(r) ); }
s32 signal::gen_fb ( s32 c, s32 o, s32 r ) { chk_CO(c,o); return fb [c][o] = YMX_FB ( rnd(r) ); }
s32 signal::gen_nfq( s32 c, s32 o, s32 r ) { chk_CO(c,o); return nfq[c][o] = YMX_NFQ( rnd(r) ); }
s32 signal::gen_frq( s32 c, s32 o, s32 r ) { chk_CO(c,o); return frq[c][o] = YMX_FRQ( rnd(r) ); }
s32 signal::gen_amd( s32 c, s32 o, s32 r ) { chk_CO(c,o); return amd[c][o] = YMX_AMD( rnd(r) ); }
s32 signal::gen_ams( s32 c, s32 o, s32 r ) { chk_CO(c,o); return ams[c][o] = YMX_AMS( rnd(r) ); }
s32 signal::gen_pmd( s32 c, s32 o, s32 r ) { chk_CO(c,o); return pmd[c][o] = YMX_PMD( rnd(r) ); }
s32 signal::gen_pms( s32 c, s32 o, s32 r ) { chk_CO(c,o); return pms[c][o] = YMX_PMS( rnd(r) ); }

// generate wf 2

s32 signal::gen_owf( s32 o, s32 r ) { chk_O(o); return owf[o] = YMX_OWF( rnd(r) ); }
s32 signal::gen_lwf( s32 o, s32 r ) { chk_O(o); return lwf[o] = YMX_LWF( rnd(r) ); }



// generate alg 3

s32 signal::gen_alg( s32 b, s32 r ) { return alg = YMX_ALG( rnd(b,r) ); }

// generate primary 3

s32 signal::gen_op ( s32 o, s32 b, s32 r ) { chk_O(o); return op [o] = YMX_OP ( rnd(b,r) ); }
s32 signal::gen_ns ( s32 o, s32 b, s32 r ) { chk_O(o); return ns [o] = YMX_NS ( rnd(b,r) ); }
s32 signal::gen_ne ( s32 o, s32 b, s32 r ) { chk_O(o); return ne [o] = YMX_NE ( rnd(b,r) ); }
s32 signal::gen_ame( s32 o, s32 b, s32 r ) { chk_O(o); return ame[o] = YMX_AME( rnd(b,r) ); }

// generate secondary 4

s32 signal::gen_tl ( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return tl [c][o] = YMX_TL ( rnd(b,r) ); }
s32 signal::gen_ar ( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return ar [c][o] = YMX_AR ( rnd(b,r) ); }
s32 signal::gen_d1r( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return d1r[c][o] = YMX_D1R( rnd(b,r) ); }
s32 signal::gen_d1l( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return d1l[c][o] = YMX_D1L( rnd(b,r) ); }
s32 signal::gen_d2r( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return d2r[c][o] = YMX_D2R( rnd(b,r) ); }
s32 signal::gen_rr ( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return rr [c][o] = YMX_RR ( rnd(b,r) ); }
s32 signal::gen_mul( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return mul[c][o] = YMX_MUL( rnd(b,r) ); }
s32 signal::gen_kc ( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return kc [c][o] = YMX_KC ( rnd(b,r) ); }
s32 signal::gen_kf ( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return kf [c][o] = YMX_KF ( rnd(b,r) ); }
s32 signal::gen_fb ( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return fb [c][o] = YMX_FB ( rnd(b,r) ); }
s32 signal::gen_nfq( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return nfq[c][o] = YMX_NFQ( rnd(b,r) ); }
s32 signal::gen_frq( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return frq[c][o] = YMX_FRQ( rnd(b,r) ); }
s32 signal::gen_amd( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return amd[c][o] = YMX_AMD( rnd(b,r) ); }
s32 signal::gen_ams( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return ams[c][o] = YMX_AMS( rnd(b,r) ); }
s32 signal::gen_pmd( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return pmd[c][o] = YMX_PMD( rnd(b,r) ); }
s32 signal::gen_pms( s32 c, s32 o, s32 b, s32 r ) { chk_CO(c,o); return pms[c][o] = YMX_PMS( rnd(b,r) ); }

// generate wf 3

s32 signal::gen_owf( s32 o, s32 b, s32 r ) { chk_O(o); return owf[o] = YMX_OWF( rnd(b,r) ); }
s32 signal::gen_lwf( s32 o, s32 b, s32 r ) { chk_O(o); return lwf[o] = YMX_LWF( rnd(b,r) ); }



// shuffle 1

s32 signal::shf_tl ( s32 o ) { return shf_tl ( 1, o ); }
s32 signal::shf_ar ( s32 o ) { return shf_ar ( 1, o ); }
s32 signal::shf_d1r( s32 o ) { return shf_d1r( 1, o ); }
s32 signal::shf_d1l( s32 o ) { return shf_d1l( 1, o ); }
s32 signal::shf_d2r( s32 o ) { return shf_d2r( 1, o ); }
s32 signal::shf_rr ( s32 o ) { return shf_rr ( 1, o ); }
s32 signal::shf_mul( s32 o ) { return shf_mul( 1, o ); }
s32 signal::shf_kc ( s32 o ) { return shf_kc ( 1, o ); }
s32 signal::shf_kf ( s32 o ) { return shf_kf ( 1, o ); }
s32 signal::shf_fb ( s32 o ) { return shf_fb ( 1, o ); }
s32 signal::shf_nfq( s32 o ) { return shf_nfq( 1, o ); }
s32 signal::shf_frq( s32 o ) { return shf_frq( 1, o ); }
s32 signal::shf_amd( s32 o ) { return shf_amd( 1, o ); }
s32 signal::shf_ams( s32 o ) { return shf_ams( 1, o ); }
s32 signal::shf_pmd( s32 o ) { return shf_pmd( 1, o ); }
s32 signal::shf_pms( s32 o ) { return shf_pms( 1, o ); }

// shuffle 2

s32 signal::shf_alg(              ) { return shift_alg(       rnd_X(YMX_LIMIT_ALG) ); }
s32 signal::shf_op (        s32 o ) { return shift_op (    o, rnd_X(YMX_LIMIT_OP ) ); }
s32 signal::shf_ns (        s32 o ) { return shift_ns (    o, rnd_X(YMX_LIMIT_NS ) ); }
s32 signal::shf_ne (        s32 o ) { return shift_ne (    o, rnd_X(YMX_LIMIT_NE ) ); }
s32 signal::shf_ame(        s32 o ) { return shift_ame(    o, rnd_X(YMX_LIMIT_AME) ); }
s32 signal::shf_tl ( s32 c, s32 o ) { return shift_tl ( c, o, rnd_X(YMX_LIMIT_TL ) ); }
s32 signal::shf_ar ( s32 c, s32 o ) { return shift_ar ( c, o, rnd_X(YMX_LIMIT_AR ) ); }
s32 signal::shf_d1r( s32 c, s32 o ) { return shift_d1r( c, o, rnd_X(YMX_LIMIT_D1R) ); }
s32 signal::shf_d1l( s32 c, s32 o ) { return shift_d1l( c, o, rnd_X(YMX_LIMIT_D1L) ); }
s32 signal::shf_d2r( s32 c, s32 o ) { return shift_d2r( c, o, rnd_X(YMX_LIMIT_D2R) ); }
s32 signal::shf_rr ( s32 c, s32 o ) { return shift_rr ( c, o, rnd_X(YMX_LIMIT_RR ) ); }
s32 signal::shf_owf(        s32 o ) { return shift_owf(    o, rnd_X(YMX_LIMIT_OWF) ); }
s32 signal::shf_mul( s32 c, s32 o ) { return shift_mul( c, o, rnd_X(YMX_LIMIT_MUL) ); }
s32 signal::shf_kc ( s32 c, s32 o ) { return shift_kc ( c, o, rnd_X(YMX_LIMIT_KC ) ); }
s32 signal::shf_kf ( s32 c, s32 o ) { return shift_kf ( c, o, rnd_X(YMX_LIMIT_KF ) ); }
s32 signal::shf_fb ( s32 c, s32 o ) { return shift_fb ( c, o, rnd_X(YMX_LIMIT_FB ) ); }
s32 signal::shf_nfq( s32 c, s32 o ) { return shift_nfq( c, o, rnd_X(YMX_LIMIT_NFQ) ); }
s32 signal::shf_lwf(        s32 o ) { return shift_lwf(    o, rnd_X(YMX_LIMIT_LWF) ); }
s32 signal::shf_frq( s32 c, s32 o ) { return shift_frq( c, o, rnd_X(YMX_LIMIT_FRQ) ); }
s32 signal::shf_amd( s32 c, s32 o ) { return shift_amd( c, o, rnd_X(YMX_LIMIT_AMD) ); }
s32 signal::shf_ams( s32 c, s32 o ) { return shift_ams( c, o, rnd_X(YMX_LIMIT_AMS) ); }
s32 signal::shf_pmd( s32 c, s32 o ) { return shift_pmd( c, o, rnd_X(YMX_LIMIT_PMD) ); }
s32 signal::shf_pms( s32 c, s32 o ) { return shift_pms( c, o, rnd_X(YMX_LIMIT_PMS) ); }



// safely generate alg 1

s32 signal::safe_alg() { return gen_alg(); }

// safely generate primary 1

s32 signal::safe_op ( s32 o ) { return gen_op (o); }
s32 signal::safe_ns ( s32 o ) { return gen_ns (o); }
s32 signal::safe_ne ( s32 o ) { return gen_ne (o); }
s32 signal::safe_ame( s32 o ) { return gen_ame(o); }

// safely generate secondary 1

s32 signal::safe_tl ( s32 o ) { return safe_tl ( 1, o ); }
s32 signal::safe_ar ( s32 o ) { return safe_ar ( 1, o ); }
s32 signal::safe_d1r( s32 o ) { return safe_d1r( 1, o ); }
s32 signal::safe_d1l( s32 o ) { return safe_d1l( 1, o ); }
s32 signal::safe_d2r( s32 o ) { return safe_d2r( 1, o ); }
s32 signal::safe_rr ( s32 o ) { return safe_rr ( 1, o ); }
s32 signal::safe_mul( s32 o ) { return safe_mul( 1, o ); }
s32 signal::safe_kc ( s32 o ) { return safe_kc ( 1, o ); }
s32 signal::safe_kf ( s32 o ) { return safe_kf ( 1, o ); }
s32 signal::safe_fb ( s32 o ) { return safe_fb ( 1, o ); }
s32 signal::safe_nfq( s32 o ) { return safe_nfq( 1, o ); }
s32 signal::safe_frq( s32 o ) { return safe_frq( 1, o ); }
s32 signal::safe_amd( s32 o ) { return safe_amd( 1, o ); }
s32 signal::safe_ams( s32 o ) { return safe_ams( 1, o ); }
s32 signal::safe_pmd( s32 o ) { return safe_pmd( 1, o ); }
s32 signal::safe_pms( s32 o ) { return safe_pms( 1, o ); }

// safely generate wf 1

s32 signal::safe_owf( s32 o ) { return gen_owf(o); }
s32 signal::safe_lwf( s32 o ) { return gen_lwf(o); }



// safely generate secondary 2

s32 signal::safe_tl ( s32 c, s32 o ) { chk_CO(c,o); return tl [c][o] = YMX_TL (rnd_Y(YMX1TL ,YMX2TL ) ); }
s32 signal::safe_ar ( s32 c, s32 o ) { chk_CO(c,o); return ar [c][o] = YMX_AR (rnd_Y(YMX1AR ,YMX2AR ) ); }
s32 signal::safe_d1r( s32 c, s32 o ) { chk_CO(c,o); return d1r[c][o] = YMX_D1R(rnd_Y(YMX1D1R,YMX2D1R) ); }
s32 signal::safe_d1l( s32 c, s32 o ) { chk_CO(c,o); return d1l[c][o] = YMX_D1L(rnd_Y(YMX1D1L,YMX2D1L) ); }
s32 signal::safe_d2r( s32 c, s32 o ) { chk_CO(c,o); return d2r[c][o] = YMX_D2R(rnd_Y(YMX1D2R,YMX2D2R) ); }
s32 signal::safe_rr ( s32 c, s32 o ) { chk_CO(c,o); return rr [c][o] = YMX_RR (rnd_Y(YMX1RR ,YMX2RR ) ); }
s32 signal::safe_mul( s32 c, s32 o ) { chk_CO(c,o); return mul[c][o] = YMX_MUL(rnd_Y(YMX1MUL,YMX2MUL) ); }
s32 signal::safe_kc ( s32 c, s32 o ) { chk_CO(c,o); return kc [c][o] = YMX_KC (rnd_Y(YMX1KC ,YMX2KC ) ); }
s32 signal::safe_kf ( s32 c, s32 o ) { chk_CO(c,o); return kf [c][o] = YMX_KF (rnd_Y(YMX1KF ,YMX2KF ) ); }
s32 signal::safe_fb ( s32 c, s32 o ) { chk_CO(c,o); return fb [c][o] = YMX_FB (rnd_Y(YMX1FB ,YMX2FB ) ); }
s32 signal::safe_nfq( s32 c, s32 o ) { chk_CO(c,o); return nfq[c][o] = YMX_NFQ(rnd_Y(YMX1NFQ,YMX2NFQ) ); }
s32 signal::safe_frq( s32 c, s32 o ) { chk_CO(c,o); return frq[c][o] = YMX_FRQ(rnd_Y(YMX1FRQ,YMX2FRQ) ); }
s32 signal::safe_amd( s32 c, s32 o ) { chk_CO(c,o); return amd[c][o] = YMX_AMD(rnd_Y(YMX1AMD,YMX2AMD) ); }
s32 signal::safe_ams( s32 c, s32 o ) { chk_CO(c,o); return ams[c][o] = YMX_AMS(rnd_Y(YMX1AMS,YMX2AMS) ); }
s32 signal::safe_pmd( s32 c, s32 o ) { chk_CO(c,o); return pmd[c][o] = YMX_PMD(rnd_Y(YMX1PMD,YMX2PMD) ); }
s32 signal::safe_pms( s32 c, s32 o ) { chk_CO(c,o); return pms[c][o] = YMX_PMS(rnd_Y(YMX1PMS,YMX2PMS) ); }



// generate all

signal& signal::gen_all()
{
	fori(4)
		gen_all(i);

	return *this;
}
signal& signal::gen_all( s32 o )
{
	gen_alg (   );
	gen_op  (o%4);
	gen_ns  (o%4);
	gen_ne  (o%4);
	gen_ame (o%4);
	gen_tl  (o%4);
	gen_ar  (o%4);
	gen_d1r (o%4);
	gen_d1l (o%4);
	gen_d2r (o%4);
	gen_rr  (o%4);
	gen_owf (o%4);
	gen_mul (o%4);
	gen_kc  (o%4);
	gen_kf  (o%4);
	gen_fb  (o%4);
	gen_nfq (o%4);
	gen_lwf (o%4);
	gen_frq (o%4);
	gen_amd (o%4);
	gen_ams (o%4);
	gen_pmd (o%4);
	gen_pms (o%4);

	return *this;
}



// shuffle all

signal& signal::shf_all()
{
	fori(4)
		shf_all(i);

	return *this;
}
signal& signal::shf_all( s32 o )
{
	shf_alg (   );
	shf_op  (o%4);
	shf_ns  (o%4);
	shf_ne  (o%4);
	shf_ame (o%4);
	shf_tl  (o%4);
	shf_ar  (o%4);
	shf_d1r (o%4);
	shf_d1l (o%4);
	shf_d2r (o%4);
	shf_rr  (o%4);
	shf_owf (o%4);
	shf_mul (o%4);
	shf_kc  (o%4);
	shf_kf  (o%4);
	shf_fb  (o%4);
	shf_nfq (o%4);
	shf_lwf (o%4);
	shf_frq (o%4);
	shf_amd (o%4);
	shf_ams (o%4);
	shf_pmd (o%4);
	shf_pms (o%4);

	return *this;
}



// safely generate all

signal& signal::safe_all()
{
	fori(4)
		safe_all(i);

	return *this;
}
signal& signal::safe_all( s32 o )
{
	safe_alg (   );
	safe_op  (o%4);
	safe_ns  (o%4);
	safe_ne  (o%4);
	safe_ame (o%4);
	safe_tl  (o%4);
	safe_ar  (o%4);
	safe_d1r (o%4);
	safe_d1l (o%4);
	safe_d2r (o%4);
	safe_rr  (o%4);
	safe_owf (o%4);
	safe_mul (o%4);
	safe_kc  (o%4);
	safe_kf  (o%4);
	safe_fb  (o%4);
	safe_nfq (o%4);
	safe_lwf (o%4);
	safe_frq (o%4);
	safe_amd (o%4);
	safe_ams (o%4);
	safe_pmd (o%4);
	safe_pms (o%4);

	return *this;
}



/* end */
}}
#endif

