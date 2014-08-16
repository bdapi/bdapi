
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_CORE_MACROS_2_HPP
#define BDAPI_CORE_MACROS_2_HPP
#include "bdapi.hpp"

/* class member data management macro definitions */

// get
#define BD_GET_COPY(AA,BB,CC) \
AA: BB CC; \
public:       BB   get_##CC () const     { return  CC; }; \
AA:
#define BD_GET_REFR(AA,BB,CC) \
AA: BB CC; \
public:       BB&  get_##CC ()           { return  CC; }; \
	      const BB&  get_##CC () const     { return  CC; }; \
AA:
#define BD_GET_PNTR(AA,BB,CC) \
AA: BB CC; \
public:       BB*  get_##CC ()           { return &CC; }; \
	      const BB*  get_##CC () const     { return &CC; }; \
AA:
#define BD_GET_CONST_REFR(AA,BB,CC) \
AA: BB CC; \
public: const BB&  get_##CC () const     { return  CC; }; \
AA:
#define BD_GET_CONST_PNTR(AA,BB,CC) \
AA: BB CC; \
public: const BB*  get_##CC () const     { return &CC; }; \
AA:

// get init
#define BD_GET_COPY_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB   get_##CC () const     { return  CC; }; \
AA:
#define BD_GET_REFR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB&  get_##CC ()           { return  CC; }; \
	      const BB&  get_##CC () const     { return  CC; }; \
AA:
#define BD_GET_PNTR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB*  get_##CC ()           { return &CC; }; \
	      const BB*  get_##CC () const     { return &CC; }; \
AA:
#define BD_GET_CONST_REFR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB&  get_##CC () const     { return  CC; }; \
AA:
#define BD_GET_CONST_PNTR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB*  get_##CC () const     { return &CC; }; \
AA:

// get copy set
#define BD_GET_COPY_SET(AA,BB,CC) \
AA: BB CC; \
public:       BB   get_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_GET_REFR_SET(AA,BB,CC) \
AA: BB CC; \
public:       BB&  get_##CC ()           { return  CC; }; \
	      const BB&  get_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_GET_PNTR_SET(AA,BB,CC) \
AA: BB CC; \
public:       BB*  get_##CC ()           { return &CC; }; \
	      const BB*  get_##CC () const     { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_GET_CONST_REFR_SET(AA,BB,CC) \
AA: BB CC; \
public: const BB&  get_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_GET_CONST_PNTR_SET(AA,BB,CC) \
AA: BB CC; \
public: const BB*  get_##CC () const     { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:

// get copy init set
#define BD_GET_COPY_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB   get_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_GET_REFR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB&  get_##CC ()           { return  CC; }; \
	      const BB&  get_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_GET_PNTR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB*  get_##CC ()           { return &CC; }; \
	      const BB*  get_##CC () const     { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_GET_CONST_REFR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB&  get_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_GET_CONST_PNTR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB*  get_##CC () const     { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:

// is
#define BD_IS_COPY(AA,BB,CC) \
AA: BB CC; \
public:       BB   is_##CC () const      { return  CC; }; \
AA:
#define BD_IS_REFR(AA,BB,CC) \
AA: BB CC; \
public:       BB&  is_##CC ()            { return  CC; }; \
	      const BB&  is_##CC () const      { return  CC; }; \
AA:
#define BD_IS_PNTR(AA,BB,CC) \
AA: BB CC; \
public:       BB*  is_##CC ()            { return &CC; }; \
	      const BB*  is_##CC () const      { return &CC; }; \
AA:
#define BD_IS_CONST_REFR(AA,BB,CC) \
AA: BB CC; \
public: const BB&  is_##CC () const      { return  CC; }; \
AA:
#define BD_IS_CONST_PNTR(AA,BB,CC) \
AA: BB CC; \
public: const BB*  is_##CC () const      { return &CC; }; \
AA:

// is init
#define BD_IS_COPY_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB   is_##CC () const      { return  CC; }; \
AA:
#define BD_IS_REFR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB&  is_##CC ()            { return  CC; }; \
	      const BB&  is_##CC () const      { return  CC; }; \
AA:
#define BD_IS_PNTR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB*  is_##CC ()            { return &CC; }; \
	      const BB*  is_##CC () const      { return &CC; }; \
AA:
#define BD_IS_CONST_REFR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB&  is_##CC () const      { return  CC; }; \
AA:
#define BD_IS_CONST_PNTR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB*  is_##CC () const      { return &CC; }; \
AA:

// is copy set
#define BD_IS_COPY_SET(AA,BB,CC) \
AA: BB CC; \
public:       BB   is_##CC () const      { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_IS_REFR_SET(AA,BB,CC) \
AA: BB CC; \
public:       BB&  is_##CC ()            { return  CC; }; \
	      const BB&  is_##CC () const      { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_IS_PNTR_SET(AA,BB,CC) \
AA: BB CC; \
public:       BB*  is_##CC ()            { return &CC; }; \
	      const BB*  is_##CC () const      { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_IS_CONST_REFR_SET(AA,BB,CC) \
AA: BB CC; \
public: const BB&  is_##CC () const      { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_IS_CONST_PNTR_SET(AA,BB,CC) \
AA: BB CC; \
public: const BB*  is_##CC () const      { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:

// is copy init set
#define BD_IS_COPY_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB   is_##CC () const      { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_IS_REFR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB&  is_##CC ()            { return  CC; }; \
	      const BB&  is_##CC () const      { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_IS_PNTR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB*  is_##CC ()            { return &CC; }; \
	      const BB*  is_##CC () const      { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_IS_CONST_REFR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB&  is_##CC () const      { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_IS_CONST_PNTR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB*  is_##CC () const      { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:

// has
#define BD_HAS_COPY(AA,BB,CC) \
AA: BB CC; \
public:       BB   has_##CC () const     { return  CC; }; \
AA:
#define BD_HAS_REFR(AA,BB,CC) \
AA: BB CC; \
public:       BB&  has_##CC ()           { return  CC; }; \
	      const BB&  has_##CC () const     { return  CC; }; \
AA:
#define BD_HAS_PNTR(AA,BB,CC) \
AA: BB CC; \
public:       BB*  has_##CC ()           { return &CC; }; \
	      const BB*  has_##CC () const     { return &CC; }; \
AA:
#define BD_HAS_CONST_REFR(AA,BB,CC) \
AA: BB CC; \
public: const BB&  has_##CC () const     { return  CC; }; \
AA:
#define BD_HAS_CONST_PNTR(AA,BB,CC) \
AA: BB CC; \
public: const BB*  has_##CC () const     { return &CC; }; \
AA:

// has init
#define BD_HAS_COPY_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB   has_##CC () const     { return  CC; }; \
AA:
#define BD_HAS_REFR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB&  has_##CC ()           { return  CC; }; \
	      const BB&  has_##CC () const     { return  CC; }; \
AA:
#define BD_HAS_PNTR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB*  has_##CC ()           { return &CC; }; \
	      const BB*  has_##CC () const     { return &CC; }; \
AA:
#define BD_HAS_CONST_REFR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB&  has_##CC () const     { return  CC; }; \
AA:
#define BD_HAS_CONST_PNTR_INIT(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB*  has_##CC () const     { return &CC; }; \
AA:

// has copy set
#define BD_HAS_COPY_SET(AA,BB,CC) \
AA: BB CC; \
public:       BB   has_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_HAS_REFR_SET(AA,BB,CC) \
AA: BB CC; \
public:       BB&  has_##CC ()           { return  CC; }; \
	      const BB&  has_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_HAS_PNTR_SET(AA,BB,CC) \
AA: BB CC; \
public:       BB*  has_##CC ()           { return &CC; }; \
	      const BB*  has_##CC () const     { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_HAS_CONST_REFR_SET(AA,BB,CC) \
AA: BB CC; \
public: const BB&  has_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_HAS_CONST_PNTR_SET(AA,BB,CC) \
AA: BB CC; \
public: const BB*  has_##CC () const     { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:

// has copy init set
#define BD_HAS_COPY_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB   has_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_HAS_REFR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB&  has_##CC ()           { return  CC; }; \
	      const BB&  has_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_HAS_PNTR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public:       BB*  has_##CC ()           { return &CC; }; \
	      const BB*  has_##CC () const     { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_HAS_CONST_REFR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB&  has_##CC () const     { return  CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:
#define BD_HAS_CONST_PNTR_INIT_SET(AA,BB,CC,DD) \
AA: BB CC = DD; \
public: const BB*  has_##CC () const     { return &CC; }; \
	            void set_##CC ( BB _##CC ) { CC = _##CC; }; \
AA:

/* end */

#endif
