
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_CORE_MACROS_3_HPP
#define BDAPI_CORE_MACROS_3_HPP
#include "bdapi.hpp"

/* class member data management macro definitions */

// get
#define BD_COPY(AA,BB,CC) \
protected:    AA   BB; \
public:       AA   CC () const     { return  BB; }; \
protected:
#define BD_REFR(AA,BB,CC) \
protected:    AA   BB; \
public:       AA&  CC ()           { return  BB; }; \
	   const    AA&  CC () const     { return  BB; }; \
protected:
#define BD_PNTR(AA,BB,CC) \
protected:    AA   BB; \
public:       AA*  CC ()           { return &BB; }; \
	      const AA*  CC () const     { return &BB; }; \
protected:
#define BD_CREFR(AA,BB,CC) \
protected:    AA   BB; \
public: const AA&  CC () const     { return  BB; }; \
protected:
#define BD_CPNTR(AA,BB,CC) \
protected:    AA   BB; \
public: const AA*  CC () const     { return &BB; }; \
protected:

// get init
#define BD_COPY_INIT(AA,BB,CC,EE) \
protected:    AA   BB = EE; \
public:       AA   CC () const     { return  BB; }; \
protected:
#define BD_REFR_INIT(AA,BB,CC,EE) \
protected:    AA   BB = EE; \
public:       AA&  CC ()           { return  BB; }; \
	      const AA&  CC () const     { return  BB; }; \
protected:
#define BD_PNTR_INIT(AA,BB,CC,EE) \
protected:    AA   BB = EE; \
public:       AA*  CC ()           { return &BB; }; \
	      const AA*  CC () const     { return &BB; }; \
protected:
#define BD_CREFR_INIT(AA,BB,CC,EE) \
protected:    AA   BB = EE; \
public: const AA&  CC () const     { return  BB; }; \
protected:
#define BD_CPNTR_INIT(AA,BB,CC,EE) \
protected:    AA   BB = EE; \
public: const AA*  CC () const     { return &BB; }; \
protected:

// get copy set
#define BD_COPY_SET(AA,BB,CC,DD) \
protected:    AA   BB; \
public:       AA   CC () const     { return  BB; }; \
	            void DD ( AA _##BB ) { BB = _##BB; }; \
protected:
#define BD_REFR_SET(AA,BB,CC,DD) \
protected:    AA   BB; \
public:       AA&  CC ()           { return  BB; }; \
	      const AA&  CC () const     { return  BB; }; \
	            void DD ( AA _##BB ) { BB = _##BB; }; \
protected:
#define BD_PNTR_SET(AA,BB,CC,DD) \
protected:    AA   BB; \
public:       AA*  CC ()           { return &BB; }; \
	      const AA*  CC () const     { return &BB; }; \
	            void DD ( AA _##BB ) { BB = _##BB; }; \
protected:
#define BD_CREFR_SET(AA,BB,CC,DD) \
protected:    AA   BB; \
public: const AA&  CC () const     { return  BB; }; \
	            void DD ( AA _##BB ) { BB = _##BB; }; \
protected:
#define BD_CPNTR_SET(AA,BB,CC,DD) \
protected:    AA   BB; \
public: const AA*  CC () const     { return &BB; }; \
	            void DD ( AA _##BB ) { BB = _##BB; }; \
protected:

// get copy init set
#define BD_COPY_INIT_SET(AA,BB,CC,DD,EE) \
protected:    AA   BB = EE; \
public:       AA   CC () const     { return  BB; }; \
	            void DD ( AA _##BB ) { BB = _##BB; }; \
protected:
#define BD_REFR_INIT_SET(AA,BB,CC,DD,EE) \
protected:    AA   BB = EE; \
public:       AA&  CC ()           { return  BB; }; \
	      const AA&  CC () const     { return  BB; }; \
	            void DD ( AA _##BB ) { BB = _##BB; }; \
protected:
#define BD_PNTR_INIT_SET(AA,BB,CC,DD,EE) \
protected:    AA   BB = EE; \
public:       AA*  CC ()           { return &BB; }; \
	      const AA*  CC () const     { return &BB; }; \
	            void DD ( AA _##BB ) { BB = _##BB; }; \
protected:
#define BD_CREFR_INIT_SET(AA,BB,CC,DD,EE) \
protected:    AA   BB = EE; \
public: const AA&  CC () const     { return  BB; }; \
	            void DD ( AA _##BB ) { BB = _##BB; }; \
protected:
#define BD_CPNTR_INIT_SET(AA,BB,CC,DD,EE) \
protected:    AA   BB = EE; \
public: const AA*  CC () const     { return &BB; }; \
	            void DD ( AA _##BB ) { BB = _##BB; }; \
protected:

/* end */

#endif
