
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_UTIL_BUFFER_CORE_CPP
#define BDAPI_UTIL_BUFFER_CORE_CPP
#include "util/buffer.hpp"

/* includes */

// bdapi
#include "string/string.hpp"

/* namespaces */
namespace bdapi {
namespace util  {

/* buffer class core function implementations */

// reset index
buffer& buffer::reset_index()
{
	index = 0;

	RETHIS;
}

// set index
buffer& buffer::set_index( s32 i )
{
	index = i;

	RETHIS;
}

// shift index
buffer& buffer::shift_index( s32 i )
{
	index += i;

	RETHIS;
}

// inherit
buffer_u8_vector buffer::inherit()
{
	return static_cast< buffer_u8_vector& >( *this );
}
const buffer_u8_vector buffer::inherit() const
{
	return static_cast< const buffer_u8_vector& >( *this );
}

// get pointer
u8* buffer::get_pointer()
{
	return get_pointer( false );
}
u8* buffer::get_pointer( bl indexed )
{
	if( indexed )
	{
		return get_data( index );
	}
	else
	{
		return get_data();
	}
}

// in
template<> buffer& buffer::in<u8>( u8 i )
{
	insert(i);

	RETHIS;
}
template<> buffer& buffer::in<u16>( u16 i )
{
	u8* j = reinterpret_cast<u8*>( &i );

	kfor(2)
	{
		in<u8>( j[k] );
	}

	RETHIS;
}
template<> buffer& buffer::in<u32>( u32 i )
{
	u8* j = reinterpret_cast<u8*>( &i );

	kfor(4)
	{
		in<u8>( j[k] );
	}

	RETHIS;
}
template<> buffer& buffer::in<u64>( u64 i )
{
	u8* j = reinterpret_cast<u8*>( &i );

	kfor(8)
	{
		in<u8>( j[k] );
	}

	RETHIS;
}
template<> buffer& buffer::in<s8>( s8 i )
{
	insert(i);

	RETHIS;
}
template<> buffer& buffer::in<s16>( s16 i )
{
	u8* j = reinterpret_cast<u8*>( &i );

	kfor(2)
	{
		in<u8>( j[k] );
	}

	RETHIS;
}
template<> buffer& buffer::in<s32>( s32 i )
{
	u8* j = reinterpret_cast<u8*>( &i );

	kfor(4)
	{
		in<u8>( j[k] );
	}

	RETHIS;
}
template<> buffer& buffer::in<s64>( s64 i )
{
	u8* j = reinterpret_cast<u8*>( &i );

	kfor(8)
	{
		in<u8>( j[k] );
	}

	RETHIS;
}
template<> buffer& buffer::in<f32>( f32 i )
{
	u8* j = reinterpret_cast<u8*>( &i );

	kfor(4)
	{
		in<u8>( j[k] );
	}

	RETHIS;
}
template<> buffer& buffer::in<f64>( f64 i )
{
	u8* j = reinterpret_cast<u8*>( &i );

	kfor(8)
	{
		in<u8>( j[k] );
	}

	RETHIS;
}
template<> buffer& buffer::in<string>( string i )
{
	forj( i.size() )
	{
		in<u8>( i[j] );
	}

	in<u8>(0);

	RETHIS;
}
template<> buffer& buffer::in<bl>( bl i )
{
	if(i)
	{
		in<u8>(1);
	}
	else
	{
		in<u8>(0);
	}

	RETHIS;
}

// out
template<> u8 buffer::out<u8>()
{
	u8 i = get_data()[index];

	index++;

	return i;
}
template<> u16 buffer::out<u16>()
{
	u8 i[2];

	jfor(2)
	{
		i[j] = out<u8>();
	}

	return *reinterpret_cast<u16*>(i);
}
template<> u32 buffer::out<u32>()
{
	u8 i[4];

	jfor(4)
	{
		i[j] = out<u8>();
	}

	return *reinterpret_cast<u32*>(i);
}
template<> u64 buffer::out<u64>()
{
	u8 i[8];

	jfor(8)
	{
		i[j] = out<u8>();
	}

	return *reinterpret_cast<u64*>(i);
}
template<> s8 buffer::out<s8>()
{
	u8 i = get_data()[index];

	index++;

	return i;
}
template<> s16 buffer::out<s16>()
{
	u8 i[2];

	jfor(2)
	{
		i[j] = out<u8>();
	}

	return *reinterpret_cast<s16*>(i);
}
template<> s32 buffer::out<s32>()
{
	u8 i[4];

	jfor(4)
	{
		i[j] = out<u8>();
	}

	return *reinterpret_cast<s32*>(i);
}
template<> s64 buffer::out<s64>()
{
	u8 i[8];

	jfor(8)
	{
		i[j] = out<u8>();
	}

	return *reinterpret_cast<s64*>(i);
}
template<> f32 buffer::out<f32>()
{
	u8 i[4];

	jfor(4)
	{
		i[j] = out<u8>();
	}

	return *reinterpret_cast<f32*>(i);
}
template<> f64 buffer::out<f64>()
{
	u8 i[8];

	jfor(8)
	{
		i[j] = out<u8>();
	}

	return *reinterpret_cast<f64*>(i);
}
template<> string buffer::out<string>()
{
	string i;

	char j = out<u8>();

	while( j != 0 )
	{
		i += j;

		j = out<u8>();
	}

	return i;
}
template<> bl buffer::out<bl>()
{
	if( out<u8>() == 0 )
	{
		return false;
	}
	else
	{
		return true;
	}
}

/* end */

}
}

#endif
