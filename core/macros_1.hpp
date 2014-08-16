
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_CORE_MACROS_1_HPP
#define BDAPI_CORE_MACROS_1_HPP
#include "bdapi.hpp"

/* bdapi constant macro definitions */

// versioning information macros
#define BDAPI_VERSION_MAJOR 0
#define BDAPI_VERSION_MINOR 6
#define BDAPI_VERSION_PATCH 0

// compiler function macros
#define BD_FUNC     __FUNCTION__
#define BD_FUNC_DEC __FUNCDNAME__
#define BD_FUNC_SIG __FUNCSIG__
#define BD_FILE     __FILE__
#define BD_DATE     __DATE__
#define BD_LINE     __LINE__
#define BD_TIME     __TIME__

/* bdapi function macro definitions */

// binary macro
#define BINARY(AA) 0b##AA

// return macros
#define RETHIS return *this
#define RENULL return NULL

// delete macros
#define DEL(AA)   if( AA != NULL ) { delete   AA; AA = NULL; }
#define DEL_X(AA) if( AA != NULL ) { delete[] AA; AA = NULL; }

// destructor macros
#define DESTRUCT(AA)   if( AA != NULL ) { delete   AA; }
#define DESTRUCT_X(AA) if( AA != NULL ) { delete[] AA; }

// safe new
#define NEW(AA,BB)      delete   BB; BB = new AA    ()
#define NEW_X(AA,BB,CC) delete[] BB; BB = new AA[CC]()

/* loop function macro definitions */

// numerical loop macros

#define FOR_IMPL(AA,BB)    for( s32 AA = 0; AA < (s32)BB; AA++ )

#define fora(AA) FOR_IMPL( a, AA )
#define forb(BB) FOR_IMPL( b, BB )
#define forc(CC) FOR_IMPL( c, CC )
#define ford(DD) FOR_IMPL( d, DD )
#define fore(EE) FOR_IMPL( e, EE )
#define forf(FF) FOR_IMPL( f, FF )
#define forg(GG) FOR_IMPL( g, GG )
#define forh(HH) FOR_IMPL( h, HH )
#define fori(II) FOR_IMPL( i, II )
#define forj(JJ) FOR_IMPL( j, JJ )
#define fork(KK) FOR_IMPL( k, KK )
#define forl(LL) FOR_IMPL( l, LL )
#define form(MM) FOR_IMPL( m, MM )
#define forn(NN) FOR_IMPL( n, NN )
#define foro(OO) FOR_IMPL( o, OO )
#define forp(PP) FOR_IMPL( p, PP )
#define forq(QQ) FOR_IMPL( q, QQ )
#define forr(RR) FOR_IMPL( r, RR )
#define fors(SS) FOR_IMPL( s, SS )
#define fort(TT) FOR_IMPL( t, TT )
#define foru(UU) FOR_IMPL( u, UU )
#define forv(VV) FOR_IMPL( v, VV )
#define forw(WW) FOR_IMPL( w, WW )
#define forx(XX) FOR_IMPL( x, XX )
#define fory(YY) FOR_IMPL( y, YY )
#define forz(ZZ) FOR_IMPL( z, ZZ )

// reverse loop macros

#define FOR_REVERSE_IMPL(AA,BB) for( s32 AA = (s32)BB - 1; AA >= 0; AA-- )

#define afor(AA) FOR_REVERSE_IMPL( a, AA )
#define bfor(BB) FOR_REVERSE_IMPL( b, BB )
#define cfor(CC) FOR_REVERSE_IMPL( c, CC )
#define dfor(DD) FOR_REVERSE_IMPL( d, DD )
#define efor(EE) FOR_REVERSE_IMPL( e, EE )
#define ffor(FF) FOR_REVERSE_IMPL( f, FF )
#define gfor(GG) FOR_REVERSE_IMPL( g, GG )
#define hfor(HH) FOR_REVERSE_IMPL( h, HH )
#define ifor(II) FOR_REVERSE_IMPL( i, II )
#define jfor(JJ) FOR_REVERSE_IMPL( j, JJ )
#define kfor(KK) FOR_REVERSE_IMPL( k, KK )
#define lfor(LL) FOR_REVERSE_IMPL( l, LL )
#define mfor(MM) FOR_REVERSE_IMPL( m, MM )
#define nfor(NN) FOR_REVERSE_IMPL( n, NN )
#define ofor(OO) FOR_REVERSE_IMPL( o, OO )
#define pfor(PP) FOR_REVERSE_IMPL( p, PP )
#define qfor(QQ) FOR_REVERSE_IMPL( q, QQ )
#define rfor(RR) FOR_REVERSE_IMPL( r, RR )
#define sfor(SS) FOR_REVERSE_IMPL( s, SS )
#define tfor(TT) FOR_REVERSE_IMPL( t, TT )
#define ufor(UU) FOR_REVERSE_IMPL( u, UU )
#define vfor(VV) FOR_REVERSE_IMPL( v, VV )
#define wfor(WW) FOR_REVERSE_IMPL( w, WW )
#define xfor(XX) FOR_REVERSE_IMPL( x, XX )
#define yfor(YY) FOR_REVERSE_IMPL( y, YY )
#define zfor(ZZ) FOR_REVERSE_IMPL( z, ZZ )

/* end */

#endif
