
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_CORE_LOCAL_OPEN_HPP
#define BDAPI_CORE_LOCAL_OPEN_HPP

#ifdef BDAPI_CORE_LOCAL_CLOSE_HPP
#error "ERROR: bdapi_local_close.hpp has already been included."
#endif

/* local opening macro definitions */

// global

#if defined BD_DATA_GLOBAL

#define BD_DATA_DECL(        A,B  ) A B
#define BD_DATA_INIT(        A,B,C) A B=C
#define BD_DATA_COPY(      X,A,B  ) A X##_##B(){return B;}
#define BD_DATA_REFR(      X,A,B  ) A& X##_##B(){return B;}
#define BD_DATA_PNTR(      X,A,B  ) A* X##_##B(){return &B;}
#define BD_DATA_CONST_REFR(X,A,B  ) const A& X##_##B(){return B;}
#define BD_DATA_CONST_PNTR(X,A,B  ) const A* X##_##B(){return &B;}
#define BD_DATA_SET(         A,B  ) void set_##B( A _##B ){B=_##B;}

// extern

#elif defined BD_DATA_EXTERN

#define BD_DATA_DECL(        A,B  ) extern A B
#define BD_DATA_INIT(        A,B,C) extern A B
#define BD_DATA_COPY(      X,A,B  ) A X##_##B()
#define BD_DATA_REFR(      X,A,B  ) A& X##_##B()
#define BD_DATA_PNTR(      X,A,B  ) A* X##_##B()
#define BD_DATA_CONST_REFR(X,A,B  ) const A& X##_##B()
#define BD_DATA_CONST_PNTR(X,A,B  ) const A* X##_##B()
#define BD_DATA_SET(         A,B  ) void set_##B( A _##B )

// header

#else

#define BD_DATA_DECL(        A,B  )
#define BD_DATA_INIT(        A,B,C)
#define BD_DATA_COPY(      X,A,B  ) A X##_##B()
#define BD_DATA_REFR(      X,A,B  ) A& X##_##B()
#define BD_DATA_PNTR(      X,A,B  ) A* X##_##B()
#define BD_DATA_CONST_REFR(X,A,B  ) const A& X##_##B()
#define BD_DATA_CONST_PNTR(X,A,B  ) const A* X##_##B()
#define BD_DATA_SET(         A,B  ) void set_##B( A _##B )

#endif

// get

#define BD_DATA_GET_COPY(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_COPY(get,A,B)

#define BD_DATA_GET_REFR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_REFR(get,A,B)

#define BD_DATA_GET_PNTR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_PNTR(get,A,B)

#define BD_DATA_GET_CONST_REFR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_REFR(get,A,B)

#define BD_DATA_GET_CONST_PNTR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_PNTR(get,A,B)

#define BD_DATA_GET_COPY_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_COPY(get,A,B)

#define BD_DATA_GET_REFR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_REFR(get,A,B)

#define BD_DATA_GET_PNTR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_PNTR(get,A,B)

#define BD_DATA_GET_CONST_REFR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_REFR(get,A,B)

#define BD_DATA_GET_CONST_PNTR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_PNTR(get,A,B)

#define BD_DATA_GET_COPY_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_COPY(get,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_GET_REFR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_REFR(get,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_GET_PNTR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_PNTR(get,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_GET_CONST_REFR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_REFR(get,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_GET_CONST_PNTR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_PNTR(get,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_GET_COPY_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_COPY(get,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_GET_REFR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_REFR(get,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_GET_PNTR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_PNTR(get,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_GET_CONST_REFR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_REFR(get,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_GET_CONST_PNTR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_PNTR(get,A,B); \
BD_DATA_SET(A,B)

// is

#define BD_DATA_IS_COPY(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_COPY(is,A,B)

#define BD_DATA_IS_REFR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_REFR(is,A,B)

#define BD_DATA_IS_PNTR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_PNTR(is,A,B)

#define BD_DATA_IS_CONST_REFR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_REFR(is,A,B)

#define BD_DATA_IS_CONST_PNTR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_PNTR(is,A,B)

#define BD_DATA_IS_COPY_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_COPY(is,A,B)

#define BD_DATA_IS_REFR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_REFR(is,A,B)

#define BD_DATA_IS_PNTR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_PNTR(is,A,B)

#define BD_DATA_IS_CONST_REFR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_REFR(is,A,B)

#define BD_DATA_IS_CONST_PNTR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_PNTR(is,A,B)

#define BD_DATA_IS_COPY_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_COPY(is,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_IS_REFR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_REFR(is,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_IS_PNTR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_PNTR(is,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_IS_CONST_REFR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_REFR(is,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_IS_CONST_PNTR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_PNTR(is,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_IS_COPY_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_COPY(is,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_IS_REFR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_REFR(is,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_IS_PNTR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_PNTR(is,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_IS_CONST_REFR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_REFR(is,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_IS_CONST_PNTR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_PNTR(is,A,B); \
BD_DATA_SET(A,B)

// has

#define BD_DATA_HAS_COPY(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_COPY(has,A,B)

#define BD_DATA_HAS_REFR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_REFR(has,A,B)

#define BD_DATA_HAS_PNTR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_PNTR(has,A,B)

#define BD_DATA_HAS_CONST_REFR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_REFR(has,A,B)

#define BD_DATA_HAS_CONST_PNTR(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_PNTR(has,A,B)

#define BD_DATA_HAS_COPY_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_COPY(has,A,B)

#define BD_DATA_HAS_REFR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_REFR(has,A,B)

#define BD_DATA_HAS_PNTR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_PNTR(has,A,B)

#define BD_DATA_HAS_CONST_REFR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_REFR(has,A,B)

#define BD_DATA_HAS_CONST_PNTR_INIT(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_PNTR(has,A,B)

#define BD_DATA_HAS_COPY_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_COPY(has,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_HAS_REFR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_REFR(has,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_HAS_PNTR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_PNTR(has,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_HAS_CONST_REFR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_REFR(has,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_HAS_CONST_PNTR_SET(A,B)\
BD_DATA_DECL(A,B); \
BD_DATA_CONST_PNTR(has,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_HAS_COPY_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_COPY(has,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_HAS_REFR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_REFR(has,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_HAS_PNTR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_PNTR(has,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_HAS_CONST_REFR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_REFR(has,A,B); \
BD_DATA_SET(A,B)

#define BD_DATA_HAS_CONST_PNTR_INIT_SET(A,B,C)\
BD_DATA_INIT(A,B,C); \
BD_DATA_CONST_PNTR(has,A,B); \
BD_DATA_SET(A,B)

/* end */
#endif
