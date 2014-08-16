
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_SIGNAL_DIS_CPP
#define BDAPI_YMX_SIGNAL_DIS_CPP
#include "ymx/ymx_signal.hpp"

/* includes */

// bdapi
#include "ymx/ymx_core.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx signal class dispatching function implementations ************************************************/



// dispatch secondary 1

s32 signal::dis_tl ( s32 o ) { chk_O(o); return tl [0][o] = YMX_TL ( rnd( tl [1][o], tl [2][o] ) ); }
s32 signal::dis_ar ( s32 o ) { chk_O(o); return ar [0][o] = YMX_AR ( rnd( ar [1][o], ar [2][o] ) ); }
s32 signal::dis_d1r( s32 o ) { chk_O(o); return d1r[0][o] = YMX_D1R( rnd( d1r[1][o], d1r[2][o] ) ); }
s32 signal::dis_d1l( s32 o ) { chk_O(o); return d1l[0][o] = YMX_D1L( rnd( d1l[1][o], d1l[2][o] ) ); }
s32 signal::dis_d2r( s32 o ) { chk_O(o); return d2r[0][o] = YMX_D2R( rnd( d2r[1][o], d2r[2][o] ) ); }
s32 signal::dis_rr ( s32 o ) { chk_O(o); return rr [0][o] = YMX_RR ( rnd( rr [1][o], rr [2][o] ) ); }
s32 signal::dis_mul( s32 o ) { chk_O(o); return mul[0][o] = YMX_MUL( rnd( mul[1][o], mul[2][o] ) ); }
s32 signal::dis_kc ( s32 o ) { chk_O(o); return kc [0][o] = YMX_KC ( rnd( kc [1][o], kc [2][o] ) ); }
s32 signal::dis_kf ( s32 o ) { chk_O(o); return kf [0][o] = YMX_KF ( rnd( kf [1][o], kf [2][o] ) ); }
s32 signal::dis_fb ( s32 o ) { chk_O(o); return fb [0][o] = YMX_FB ( rnd( fb [1][o], fb [2][o] ) ); }
s32 signal::dis_nfq( s32 o ) { chk_O(o); return nfq[0][o] = YMX_NFQ( rnd( nfq[1][o], nfq[2][o] ) ); }
s32 signal::dis_frq( s32 o ) { chk_O(o); return frq[0][o] = YMX_FRQ( rnd( frq[1][o], frq[2][o] ) ); }
s32 signal::dis_amd( s32 o ) { chk_O(o); return amd[0][o] = YMX_AMD( rnd( amd[1][o], amd[2][o] ) ); }
s32 signal::dis_ams( s32 o ) { chk_O(o); return ams[0][o] = YMX_AMS( rnd( ams[1][o], ams[2][o] ) ); }
s32 signal::dis_pmd( s32 o ) { chk_O(o); return pmd[0][o] = YMX_PMD( rnd( pmd[1][o], pmd[2][o] ) ); }
s32 signal::dis_pms( s32 o ) { chk_O(o); return pms[0][o] = YMX_PMS( rnd( pms[1][o], pms[2][o] ) ); }



// dispatch secondary 2

s32 signal::dis_tl ( s32 o, bl g ) { if(g) return dis_tl (o); chk_O(o); return tl [0][o] = tl [1][o]; }
s32 signal::dis_ar ( s32 o, bl g ) { if(g) return dis_ar (o); chk_O(o); return ar [0][o] = ar [1][o]; }
s32 signal::dis_d1r( s32 o, bl g ) { if(g) return dis_d1r(o); chk_O(o); return d1r[0][o] = d1r[1][o]; }
s32 signal::dis_d1l( s32 o, bl g ) { if(g) return dis_d1l(o); chk_O(o); return d1l[0][o] = d1l[1][o]; }
s32 signal::dis_d2r( s32 o, bl g ) { if(g) return dis_d2r(o); chk_O(o); return d2r[0][o] = d2r[1][o]; }
s32 signal::dis_rr ( s32 o, bl g ) { if(g) return dis_rr (o); chk_O(o); return rr [0][o] = rr [1][o]; }
s32 signal::dis_mul( s32 o, bl g ) { if(g) return dis_mul(o); chk_O(o); return mul[0][o] = mul[1][o]; }
s32 signal::dis_kc ( s32 o, bl g ) { if(g) return dis_kc (o); chk_O(o); return kc [0][o] = kc [1][o]; }
s32 signal::dis_kf ( s32 o, bl g ) { if(g) return dis_kf (o); chk_O(o); return kf [0][o] = kf [1][o]; }
s32 signal::dis_fb ( s32 o, bl g ) { if(g) return dis_fb (o); chk_O(o); return fb [0][o] = fb [1][o]; }
s32 signal::dis_nfq( s32 o, bl g ) { if(g) return dis_nfq(o); chk_O(o); return nfq[0][o] = nfq[1][o]; }
s32 signal::dis_frq( s32 o, bl g ) { if(g) return dis_frq(o); chk_O(o); return frq[0][o] = frq[1][o]; }
s32 signal::dis_amd( s32 o, bl g ) { if(g) return dis_amd(o); chk_O(o); return amd[0][o] = amd[1][o]; }
s32 signal::dis_ams( s32 o, bl g ) { if(g) return dis_ams(o); chk_O(o); return ams[0][o] = ams[1][o]; }
s32 signal::dis_pmd( s32 o, bl g ) { if(g) return dis_pmd(o); chk_O(o); return pmd[0][o] = pmd[1][o]; }
s32 signal::dis_pms( s32 o, bl g ) { if(g) return dis_pms(o); chk_O(o); return pms[0][o] = pms[1][o]; }



// dispatch operator

signal& signal::dis_op( s32 o )
{
	chk_O(o);

	dis_tl (o);
	dis_ar (o);
	dis_d1r(o);
	dis_d1l(o);
	dis_d2r(o);
	dis_rr (o);

	dis_mul(o);
	dis_kc (o);
	dis_kf (o);
	dis_fb (o);
	dis_nfq(o);

	dis_frq(o);
	dis_amd(o);
	dis_ams(o);
	dis_pmd(o);
	dis_pms(o);

	return *this;
}
signal& signal::dis_op( s32 o, bl _generate )
{
	if( _generate )
		return dis_op(o);

	chk_O(o);

	dis_tl ( o, false );
	dis_ar ( o, false );
	dis_d1r( o, false );
	dis_d1l( o, false );
	dis_d2r( o, false );
	dis_rr ( o, false );

	dis_mul( o, false );
	dis_kc ( o, false );
	dis_kf ( o, false );
	dis_fb ( o, false );
	dis_nfq( o, false );

	dis_frq( o, false );
	dis_amd( o, false );
	dis_ams( o, false );
	dis_pmd( o, false );
	dis_pms( o, false );

	return *this;
}

// dispatch all

signal& signal::dis_all()
{
	fori(4)
		dis_op(i);

	return *this;
}
signal& signal::dis_all( bl _generate )
{
	if( _generate )
		return dis_all();

	fori(4)
		dis_op( i, false );

	return *this;
}



/* end */
}}
#endif

