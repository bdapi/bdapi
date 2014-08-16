
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_CONTAINER_CORE_CC
#define BDAPI_UTIL_CONTAINER_CORE_CC
#include "util/container.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace util  {

/* implementation macro definitions */

#define TMP1 template < typename AA, template< typename, typename > class BB, typename CC >
#define TMP2 template < template< typename, typename > class DD, typename EE >

/* container class core function implementations */

// set element
TMP1 result container<AA,BB,CC>::set( s32 i, const AA& aa )
{
	return set_front( i, aa );
}

// set element at back
TMP1 result container<AA,BB,CC>::set_back( const AA& aa )
{
	if( !is_empty() )
	{
		data.back() = aa;

		return 1;
	}

	return 0;
}
TMP1 result container<AA,BB,CC>::set_back( s32 i, const AA& aa )
{
	if( !is_empty() )
	{
		get_back(i) = aa;

		return 1;
	}

	return 0;
}

// set element at front
TMP1 result container<AA,BB,CC>::set_front( const AA& aa )
{
	if( !is_empty() )
	{
		data.front() = aa;

		return 1;
	}

	return 0;
}
TMP1 result container<AA,BB,CC>::set_front( s32 i, const AA& aa )
{
	if( !is_empty() )
	{
		get_front(i) = aa;

		return 1;
	}

	return 0;
}

// insert element
TMP1 AA& container<AA,BB,CC>::insert()
{
	data.push_back( AA() );

	return get_back();
}
TMP1 AA& container<AA,BB,CC>::insert( const AA& aa )
{
	data.push_back(aa);

	return get_back();
}
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::insert( s32 amount, const AA& aa )
{
	fori( amount )
	{
		insert(aa);
	}

	RETHIS;
}

// insert container
TMP1 TMP2 container<AA,BB,CC>& container<AA,BB,CC>::insert( const container<AA,DD,EE>& other )
{
	c_for_i( other )
	{
		insert(i);
	}

	RETHIS;
}
TMP1 TMP2 container<AA,BB,CC>& container<AA,BB,CC>::insert( s32 amount, const container<AA,DD,EE>& other )
{
	fori( amount )
	{
		insert(other);
	}

	RETHIS;
}

// insert element at
TMP1 AA& container<AA,BB,CC>::insert_at( s32 i )
{
	if( !is_empty() )
	{
		itr it = get_begin(i);

		data.insert( it, AA() );

		return *it;
	}
	else
	{
		return insert();
	}
}
TMP1 AA& container<AA,BB,CC>::insert_at( s32 i, const AA& aa )
{
	if( !is_empty() )
	{
		itr it = get_begin(i);

		data.insert( it, aa );

		return *it;
	}
	else
	{
		return insert(aa);
	}
}
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::insert_at( s32 i, s32 amount, const AA& aa )
{
	if( !is_empty() )
	{
		itr it = get_begin(i);

		forj( amount )
		{
			data.insert( it, aa );

			it++;
		}
	}
	else
	{
		insert( amount, aa );
	}

	RETHIS;
}

// insert container at
TMP1 TMP2 container<AA,BB,CC>& container<AA,BB,CC>::insert_at( s32 i, const container<AA,DD,EE>& other )
{
	if( !is_empty() )
	{
		itr it = get_begin(i);

		for_j( other )
		{
			data.insert( it, *j );

			it++;
		}
	}
	else
	{
		insert(other);
	}

	RETHIS;
}
TMP1 TMP2 container<AA,BB,CC>& container<AA,BB,CC>::insert_at( s32 i, s32 amount,
const container<AA,DD,EE>& other )
{
	if( !is_empty() )
	{
		fork( amount )
		{
			itr it = get_begin( i + k * other.get_size() );

			for_j( other )
			{
				data.insert( it, *j );

				it++;
			}
		}
	}
	else
	{
		insert( amount, other );
	}

	RETHIS;
}

// reserve
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::reserve( s32 size )
{
	data.reserve( size );

	RETHIS;
}

// copy to
TMP1 AA* container<AA,BB,CC>::copy_to() const
{
	return copy_to( 0, get_size() );
}
TMP1 AA* container<AA,BB,CC>::copy_to( s32 offset ) const
{
	return copy_to( offset, get_size() - offset );
}
TMP1 AA* container<AA,BB,CC>::copy_to( s32 offset, s32 amount ) const
{
	if( amount > get_size() - offset )
	{
		amount = get_size() - offset;
	}

	AA* data_copy = new AA[ amount ];

	s32 j = 0;

	for( c_itr i = get_cbegin(offset); i != get_cend() && j < amount; i++ )
	{
		data_copy[j++] = *i;
	}

	return data_copy;
}

// mem copy
TMP1 AA* container<AA,BB,CC>::mem_copy() const
{
	return mem_copy( 0, get_size() );
}
TMP1 AA* container<AA,BB,CC>::mem_copy( s32 offset ) const
{
	return mem_copy( offset, get_size() - offset );
}
TMP1 AA* container<AA,BB,CC>::mem_copy( s32 offset, s32 amount ) const
{
	if( amount > get_size() - offset )
	{
		amount = get_size() - offset;
	}

	AA* data_copy = new AA[ amount ];

	memcpy( data_copy, get_data(offset), amount * get_element_size() );

	return data_copy;
}

// copy from
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::copy_from( AA* aa, s32 size )
{
	fori( size )
	{
		insert( aa[i] );
	}

	RETHIS;
}
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::copy_from( AA* aa, s32 i, s32 size )
{
	if( !is_empty() )
	{
		itr it = get_begin(i);

		forj( size )
		{
			data.insert( it, aa[j] );

			it++;
		}
	}
	else
	{
		copy_from( aa, size );
	}

	RETHIS;
}

// erase
TMP1 result container<AA,BB,CC>::erase( s32 i )
{
	if( i < get_size() )
	{
		data.erase( get_begin() + i );

		return 1;
	}
	else
	{
		return 0;
	}
}
TMP1 result container<AA,BB,CC>::erase( s32 i, s32 size )
{
	if( i < size && i + size <= get_size() )
	{
		data.erase( get_begin() + i, get_begin() + i + size );

		return 1;
	}
	else
	{
		return 0;
	}
}

// pop front
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::pop_front()
{
	data.pop_front();

	RETHIS;
}

// pop back
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::pop_back()
{
	data.pop_back();

	RETHIS;
}

// clear
TMP1 container<AA,BB,CC>& container<AA,BB,CC>::clear()
{
	data.clear();

	RETHIS;
}

/* implementation macro undefs */

#undef TMP1
#undef TMP2

/* end */

}
}

#endif
