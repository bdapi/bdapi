
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_SIGNAL_CORE_CPP
#define BDAPI_YMX_SIGNAL_CORE_CPP
#include "ymx/ymx_signal.hpp"

/* includes */

// bdapi
#include "gen/rng.hpp"
#include "ymx/ymx_core.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx signal class core function implementations *******************************************************/



// reset

signal& signal::reset()
{
	return reset(true);
}
signal& signal::reset( bl _primary )
{
	for( s32 i = 1; i < 3; i++ )
		reset( i, _primary );

	dis_all(false);

	return *this;
}
signal& signal::reset( s32 c, bl _primary )
{
	chk_C(c);

	if( _primary )
		alg = 7;

	fori(4)
	{
		if( _primary )
		{
			op [i] = 1;
			ns [i] = 1;
			ne [i] = 0;

			if( i == 3 )
				ame[i] = 1;
			else
				ame[i] = 0;
		}

		if( c != 2 )
			tl[c][i] = 255;
		else
			tl[c][i] =   0;

		ar [c][i] = 0;
		d1r[c][i] = 0;
		d1l[c][i] = 0;
		d2r[c][i] = 0;
		rr [c][i] = 0;

		mul[c][i] = 0;
		kc [c][i] = 0;
		kf [c][i] = 0;
		fb [c][i] = 0;
		nfq[c][i] = 0;

		frq[c][i] = 0;
		amd[c][i] = 0;
		ams[c][i] = 0;
		pmd[c][i] = 0;
		pms[c][i] = 0;

		if( _primary )
		{
			owf[i] = 0;
			lwf[i] = 0;
	} }

	return *this;
}

// check

signal& signal::check()
{
	fori(3)
		check(i);

	return *this;
}
signal& signal::check( s32 c )
{
	chk_C(c);

	alg = YMX_ALG( alg );

	fori(4)
	{
		op    [i] = YMX_OP ( op    [i] );
		ns    [i] = YMX_NS ( ns    [i] );
		ne    [i] = YMX_NE ( ne    [i] );
		ame   [i] = YMX_AME( ame   [i] );

		tl [c][i] = YMX_TL ( tl [c][i] );
		ar [c][i] = YMX_AR ( ar [c][i] );
		d1r[c][i] = YMX_D1R( d1r[c][i] );
		d1l[c][i] = YMX_D1L( d1l[c][i] );
		d2r[c][i] = YMX_D2R( d2r[c][i] );
		rr [c][i] = YMX_RR ( rr [c][i] );

		owf   [i] = YMX_OWF( owf   [i] );
		mul[c][i] = YMX_MUL( mul[c][i] );
		kc [c][i] = YMX_KC ( kc [c][i] );
		kf [c][i] = YMX_KF ( kf [c][i] );
		fb [c][i] = YMX_FB ( fb [c][i] );
		nfq[c][i] = YMX_NFQ( nfq[c][i] );

		lwf   [i] = YMX_LWF( lwf   [i] );
		frq[c][i] = YMX_FRQ( frq[c][i] );
		amd[c][i] = YMX_AMD( amd[c][i] );
		ams[c][i] = YMX_AMS( ams[c][i] );
		pmd[c][i] = YMX_PMD( pmd[c][i] );
		pms[c][i] = YMX_PMS( pms[c][i] );
	}

	return *this;
}



// operator == signal

bl signal::operator == ( const signal& s ) const
{
	if( alg != s.alg ) { return false; }

	fori(4)
	{
		if( op [i] != s.op [i] ) { return false; }
		if( ns [i] != s.ns [i] ) { return false; }
		if( ne [i] != s.ne [i] ) { return false; }
		if( ame[i] != s.ame[i] ) { return false; }

		forj(3)
		{
			if( tl [j][i] != s.tl [j][i] ) { return false; }
			if( ar [j][i] != s.ar [j][i] ) { return false; }
			if( d1r[j][i] != s.d1r[j][i] ) { return false; }
			if( d1l[j][i] != s.d1l[j][i] ) { return false; }
			if( d2r[j][i] != s.d2r[j][i] ) { return false; }
			if( rr [j][i] != s.rr [j][i] ) { return false; }

			if( mul[j][i] != s.mul[j][i] ) { return false; }
			if( kc [j][i] != s.kc [j][i] ) { return false; }
			if( kf [j][i] != s.kf [j][i] ) { return false; }
			if( fb [j][i] != s.fb [j][i] ) { return false; }
			if( nfq[j][i] != s.nfq[j][i] ) { return false; }

			if( frq[j][i] != s.frq[j][i] ) { return false; }
			if( amd[j][i] != s.amd[j][i] ) { return false; }
			if( ams[j][i] != s.ams[j][i] ) { return false; }
			if( pmd[j][i] != s.pmd[j][i] ) { return false; }
			if( pms[j][i] != s.pms[j][i] ) { return false; }
		}

		if( owf[i] != s.owf[i] ) { return false; }
		if( lwf[i] != s.lwf[i] ) { return false; }
	}

	return true;
}

// operator != signal

bl signal::operator != ( const signal& s ) const
{
	return !( *this == s );
}



// private check column

s32& signal::chk_C( s32& c )
{
	if( c < 0 )
		return c = 0;
	else if( c > 2 )
		return c = 2;
	else
		return c;
}

// private check operator

s32& signal::chk_O( s32& o )
{
	if( o < 0 )
		return o = 0;
	else if( o > 3 )
		return o = 3;
	else
		return o;
}

// private check column and operator

void signal::chk_CO( s32& c, s32& o )
{
	chk_C(c);
	chk_O(o);
}



// private check range

s32 signal::chk_R( s32 r )
{
	if( r / 16 == 0 )
		return 1;
	else
		return r / 16;
}



// private generate random number

s32 signal::rnd()
{
	return rng_sig->get<s32>(256);
}
s32 signal::rnd( s32 _range )
{
	return rng_sig->get<s32>( _range + 1 );
}
s32 signal::rnd( s32 _base, s32 _range )
{
	return rng_sig->get<s32>( _base, _base + _range + 1 );
}



// private generate special random number x

s32 signal::rnd_X( s32 x )
{
	return rng_sig->get<s32>( -chk_R(x), chk_R(x) + 1 );
}

// private generate special random number y

s32 signal::rnd_Y( s32 x, s32 y )
{
	return rng_sig->get<s32>( x, y + 1 );
}



/* end */
}}
#endif

