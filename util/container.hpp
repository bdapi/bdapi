
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_CONTAINER_HPP
#define BDAPI_UTIL_CONTAINER_HPP
#include "bdapi.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* declaration macro definitions */

#define TMP template < template< typename, typename > class DD, typename EE >

/* container class declaration */

template < typename AA, template< typename, typename > class BB, typename CC = std::allocator<AA> >
class container
{

public: // public iterator typedefs

		typedef typename BB<AA,CC>::iterator           itr;
		typedef typename BB<AA,CC>::const_iterator   c_itr;
		typedef typename BB<AA,CC>::reverse_iterator r_itr;

public: // public core data

		BB<AA,CC> data;

public: // public initialization functions (util_container_init.cc)

		container<AA,BB,CC> (                                 ) {};
		container<AA,BB,CC> ( s32 size                        );
		container<AA,BB,CC> ( s32 size, const AA& aa          );
		container<AA,BB,CC> ( AA* aa, s32 size                );
TMP container<AA,BB,CC> ( const container<AA,DD,EE>& copy );
	 ~container<AA,BB,CC> (                                 ) {};

		container<AA,BB,CC>& initialize ( s32 size                        );
		container<AA,BB,CC>& initialize ( s32 size, const AA& aa          );
		container<AA,BB,CC>& initialize ( AA* aa, s32 size                );
TMP container<AA,BB,CC>& initialize ( const container<AA,DD,EE>& copy );

public: // public core functions (util_container_core.cc)

		result set       ( s32 i, const AA& aa );
		result set_back  (        const AA& aa );
		result set_back  ( s32 i, const AA& aa );
		result set_front (        const AA& aa );
		result set_front ( s32 i, const AA& aa );

		AA&                  insert (                                              );
		AA&                  insert (             const AA& aa                     );
		container<AA,BB,CC>& insert ( s32 amount, const AA& aa                     );
TMP container<AA,BB,CC>& insert (             const container<AA,DD,EE>& other );
TMP container<AA,BB,CC>& insert ( s32 amount, const container<AA,DD,EE>& other );

		AA&                  insert_at ( s32 i                                               );
		AA&                  insert_at ( s32 i,             const AA& aa                     );
		container<AA,BB,CC>& insert_at ( s32 i, s32 amount, const AA& aa                     );
TMP container<AA,BB,CC>& insert_at ( s32 i,             const container<AA,DD,EE>& other );
TMP container<AA,BB,CC>& insert_at ( s32 i, s32 amount, const container<AA,DD,EE>& other );

		container<AA,BB,CC>& reserve ( s32 size );

		AA* copy_to  (                        ) const;
		AA* copy_to  ( s32 offset             ) const;
		AA* copy_to  ( s32 offset, s32 amount ) const;

		AA* mem_copy (                        ) const;
		AA* mem_copy ( s32 offset             ) const;
		AA* mem_copy ( s32 offset, s32 amount ) const;

		container<AA,BB,CC>& copy_from ( AA* aa,        s32 size );
		container<AA,BB,CC>& copy_from ( AA* aa, s32 i, s32 size );

		result erase ( s32 i           );
		result erase ( s32 i, s32 size );

		container<AA,BB,CC>& pop_front ();
		container<AA,BB,CC>& pop_back  ();

		container<AA,BB,CC>& clear ();

public: // public query functions (util_container_query.cc)

		      AA* get_data (       );
		      AA* get_data ( s32 i );
		const AA* get_data (       ) const;
		const AA* get_data ( s32 i ) const;

		      AA& get       ( s32 i );
		      AA& get_back  (       );
		      AA& get_back  ( s32 i );
		      AA& get_front (       );
		      AA& get_front ( s32 i );
		const AA& get       ( s32 i ) const;
		const AA& get_back  (       ) const;
		const AA& get_back  ( s32 i ) const;
		const AA& get_front (       ) const;
		const AA& get_front ( s32 i ) const;

		bl is_empty  (       ) const;
		bl is_within ( s32 i ) const;

		s32 get_elements     (          ) const;
		s32 get_element_size (          ) const;
		s32 get_size         (          ) const;
		s32 get_size         ( bl bytes ) const;
		s32 get_bytes        (          ) const;

public: // public iterator functions (util_container_iter.cc)

		  itr get_begin (       );
		  itr get_begin ( s32 i );
		  itr get_end   (       );
		  itr get_end   ( s32 i );

		c_itr get_cbegin (       ) const;
		c_itr get_cbegin ( s32 i ) const;
		c_itr get_cend   (       ) const;
		c_itr get_cend   ( s32 i ) const;

		r_itr get_rbegin (       );
		r_itr get_rbegin ( s32 i );
		r_itr get_rend   (       );
		r_itr get_rend   ( s32 i );

public: // public operator functions (util_container_oper.cc)

		      AA& operator [] ( s32 i );
		const AA& operator [] ( s32 i ) const;

TMP bl operator == ( const container<AA,DD,EE>& other ) const;
TMP bl operator != ( const container<AA,DD,EE>& other ) const;

		container<AA,BB,CC>& operator << ( const AA& aa                     );
TMP container<AA,BB,CC>& operator << ( const container<AA,DD,EE>& other );

		container<AA,BB,CC>& operator , ( const AA& aa                     );
TMP container<AA,BB,CC>& operator , ( const container<AA,DD,EE>& other );

};

/* declaration macro undefs */

#undef TMP

}
}

/* templated implementation includes */

#include "util/container_macros.hpp"
#include "util/container_init.cc"
#include "util/container_core.cc"
#include "util/container_query.cc"
#include "util/container_iterate.cc"
#include "util/container_oper.cc"

/* end */

#endif
