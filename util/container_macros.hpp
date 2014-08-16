
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_CONTAINER_MACROS_HPP
#define BDAPI_UTIL_CONTAINER_MACROS_HPP
#include "util/container.hpp"

/* includes */

/* namespaces */

/* container class macro definitions */

// iterator based loop macros

#define FOR_ITERATOR_IMPL(AA,BB) \
for( auto AA = BB.get_begin(); AA != BB.get_end(); AA++ )

#define for_a(AA) FOR_ITERATOR_IMPL( a, AA )
#define for_b(BB) FOR_ITERATOR_IMPL( b, BB )
#define for_c(CC) FOR_ITERATOR_IMPL( c, CC )
#define for_d(DD) FOR_ITERATOR_IMPL( d, DD )
#define for_e(EE) FOR_ITERATOR_IMPL( e, EE )
#define for_f(FF) FOR_ITERATOR_IMPL( f, FF )
#define for_g(GG) FOR_ITERATOR_IMPL( g, GG )
#define for_h(HH) FOR_ITERATOR_IMPL( h, HH )
#define for_i(II) FOR_ITERATOR_IMPL( i, II )
#define for_j(JJ) FOR_ITERATOR_IMPL( j, JJ )
#define for_k(KK) FOR_ITERATOR_IMPL( k, KK )
#define for_l(LL) FOR_ITERATOR_IMPL( l, LL )
#define for_m(MM) FOR_ITERATOR_IMPL( m, MM )
#define for_n(NN) FOR_ITERATOR_IMPL( n, NN )
#define for_o(OO) FOR_ITERATOR_IMPL( o, OO )
#define for_p(PP) FOR_ITERATOR_IMPL( p, PP )
#define for_q(QQ) FOR_ITERATOR_IMPL( q, QQ )
#define for_r(RR) FOR_ITERATOR_IMPL( r, RR )
#define for_s(SS) FOR_ITERATOR_IMPL( s, SS )
#define for_t(TT) FOR_ITERATOR_IMPL( t, TT )
#define for_u(UU) FOR_ITERATOR_IMPL( u, UU )
#define for_v(VV) FOR_ITERATOR_IMPL( v, VV )
#define for_w(WW) FOR_ITERATOR_IMPL( w, WW )
#define for_x(XX) FOR_ITERATOR_IMPL( x, XX )
#define for_y(YY) FOR_ITERATOR_IMPL( y, YY )
#define for_z(ZZ) FOR_ITERATOR_IMPL( z, ZZ )

// const iterator based loop macros

#define FOR_CONST_ITERATOR_IMPL(AA,BB) \
for( auto AA = BB.get_cbegin(); AA != BB.get_cend(); AA++ )

#define c_for_a(AA) FOR_CONST_ITERATOR_IMPL( a, AA )
#define c_for_b(BB) FOR_CONST_ITERATOR_IMPL( b, BB )
#define c_for_c(CC) FOR_CONST_ITERATOR_IMPL( c, CC )
#define c_for_d(DD) FOR_CONST_ITERATOR_IMPL( d, DD )
#define c_for_e(EE) FOR_CONST_ITERATOR_IMPL( e, EE )
#define c_for_f(FF) FOR_CONST_ITERATOR_IMPL( f, FF )
#define c_for_g(GG) FOR_CONST_ITERATOR_IMPL( g, GG )
#define c_for_h(HH) FOR_CONST_ITERATOR_IMPL( h, HH )
#define c_for_i(II) FOR_CONST_ITERATOR_IMPL( i, II )
#define c_for_j(JJ) FOR_CONST_ITERATOR_IMPL( j, JJ )
#define c_for_k(KK) FOR_CONST_ITERATOR_IMPL( k, KK )
#define c_for_l(LL) FOR_CONST_ITERATOR_IMPL( l, LL )
#define c_for_m(MM) FOR_CONST_ITERATOR_IMPL( m, MM )
#define c_for_n(NN) FOR_CONST_ITERATOR_IMPL( n, NN )
#define c_for_o(OO) FOR_CONST_ITERATOR_IMPL( o, OO )
#define c_for_p(PP) FOR_CONST_ITERATOR_IMPL( p, PP )
#define c_for_q(QQ) FOR_CONST_ITERATOR_IMPL( q, QQ )
#define c_for_r(RR) FOR_CONST_ITERATOR_IMPL( r, RR )
#define c_for_s(SS) FOR_CONST_ITERATOR_IMPL( s, SS )
#define c_for_t(TT) FOR_CONST_ITERATOR_IMPL( t, TT )
#define c_for_u(UU) FOR_CONST_ITERATOR_IMPL( u, UU )
#define c_for_v(VV) FOR_CONST_ITERATOR_IMPL( v, VV )
#define c_for_w(WW) FOR_CONST_ITERATOR_IMPL( w, WW )
#define c_for_x(XX) FOR_CONST_ITERATOR_IMPL( x, XX )
#define c_for_y(YY) FOR_CONST_ITERATOR_IMPL( y, YY )
#define c_for_z(ZZ) FOR_CONST_ITERATOR_IMPL( z, ZZ )

// reverse iterator based loop macros

#define FOR_REVERSE_ITERATOR_IMPL(AA,BB) \
for( auto AA = BB.get_rbegin(); AA != BB.get_rend(); AA++ )

#define a_for(AA) FOR_REVERSE_ITERATOR_IMPL( a, AA )
#define b_for(BB) FOR_REVERSE_ITERATOR_IMPL( b, BB )
#define c_for(CC) FOR_REVERSE_ITERATOR_IMPL( c, CC )
#define d_for(DD) FOR_REVERSE_ITERATOR_IMPL( d, DD )
#define e_for(EE) FOR_REVERSE_ITERATOR_IMPL( e, EE )
#define f_for(FF) FOR_REVERSE_ITERATOR_IMPL( f, FF )
#define g_for(GG) FOR_REVERSE_ITERATOR_IMPL( g, GG )
#define h_for(HH) FOR_REVERSE_ITERATOR_IMPL( h, HH )
#define i_for(II) FOR_REVERSE_ITERATOR_IMPL( i, II )
#define j_for(JJ) FOR_REVERSE_ITERATOR_IMPL( j, JJ )
#define k_for(KK) FOR_REVERSE_ITERATOR_IMPL( k, KK )
#define l_for(LL) FOR_REVERSE_ITERATOR_IMPL( l, LL )
#define m_for(MM) FOR_REVERSE_ITERATOR_IMPL( m, MM )
#define n_for(NN) FOR_REVERSE_ITERATOR_IMPL( n, NN )
#define o_for(OO) FOR_REVERSE_ITERATOR_IMPL( o, OO )
#define p_for(PP) FOR_REVERSE_ITERATOR_IMPL( p, PP )
#define q_for(QQ) FOR_REVERSE_ITERATOR_IMPL( q, QQ )
#define r_for(RR) FOR_REVERSE_ITERATOR_IMPL( r, RR )
#define s_for(SS) FOR_REVERSE_ITERATOR_IMPL( s, SS )
#define t_for(TT) FOR_REVERSE_ITERATOR_IMPL( t, TT )
#define u_for(UU) FOR_REVERSE_ITERATOR_IMPL( u, UU )
#define v_for(VV) FOR_REVERSE_ITERATOR_IMPL( v, VV )
#define w_for(WW) FOR_REVERSE_ITERATOR_IMPL( w, WW )
#define x_for(XX) FOR_REVERSE_ITERATOR_IMPL( x, XX )
#define y_for(YY) FOR_REVERSE_ITERATOR_IMPL( y, YY )
#define z_for(ZZ) FOR_REVERSE_ITERATOR_IMPL( z, ZZ )

/* end */

#endif
