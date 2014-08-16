
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_BUFFER_HPP
#define BDAPI_UTIL_BUFFER_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "vector"

// bdapi
#include "util/container.hpp"

/* namespaces */
namespace bdapi {
namespace util  {

/* buffer typedef declarations */

typedef util::container< u8, std::vector > buffer_u8_vector;

/* buffer class declaration */

class buffer : public buffer_u8_vector
{

private: // private data

	BD_GET_COPY( private, s32, index );

public: // public initialization functions (util_buffer_init.cpp)

	buffer () {};
	buffer ( const buffer& copy );
 ~buffer () {};

	buffer& initialize ( const buffer& copy );

public: // public core functions (util_buffer_core.cpp)

	buffer& reset_index (       );
	buffer& set_index   ( s32 i );
	buffer& shift_index ( s32 i );

	      buffer_u8_vector inherit ();
	const buffer_u8_vector inherit () const;

	u8* get_pointer (            );
	u8* get_pointer ( bl indexed );

	template<typename T> buffer& in ( T i );

	template<typename T> T out ();

public: // public operator functions (util_buffer_oper.cpp)

	s32 operator  = ( s32 i );
	s32 operator += ( s32 i );
	s32 operator -= ( s32 i );
	s32 operator ++ (       );
	s32 operator -- (       );

};

/* end */

}
}

#endif
