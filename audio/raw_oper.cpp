
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_RAW_OPER_CPP
#define BDAPI_AUDIO_RAW_OPER_CPP
#include "audio/raw.hpp"

/* includes */

// bdapi
#include "math/core.hpp"

// namespaces
namespace bdapi {
namespace audio {

/* audio raw data class operator function implementations */

// operator [] s32
f32& raw::operator [] ( s32 i )
{
	return data[ i % size ];
}

// operator () s32
f32& raw::operator () ( s32 i )
{
	return data[ i % size ];
}

// operator = f32*
raw& raw::operator = ( f32* data )
{
	s32 k;

	forj( channels )
	{
		fori( size )
		{
			k = i * channels % size + j;

			this->data[k] = data[k];
		}
	}

	RETHIS;
}

// operator = raw
raw& raw::operator = ( const raw& other )
{
	s32 k;

	forj( channels )
	{
		fori( size )
		{
			k = i * channels % size + j;

			data[k] = other.data[k];
		}
	}

	RETHIS;
}

// operator += raw
raw& raw::operator += ( const raw& other )
{
	s32 k;

	forj( channels )
	{
		fori( size )
		{
			k = i * channels % size + j;

			data[k] += other.data[k];
		}
	}

	RETHIS;
}

// operator -= raw
raw& raw::operator -= ( const raw& other )
{
	s32 k;

	forj( channels )
	{
		fori( size )
		{
			k = i * channels % size + j;

			data[k] -= other.data[k];
		}
	}

	RETHIS;
}

// operator *= raw
raw& raw::operator *= ( const raw& other )
{
	s32 k;

	forj( channels )
	{
		fori( size )
		{
			k = i * channels % size + j;

			data[k] *= other.data[k];
		}
	}

	RETHIS;
}

// operator /= raw
raw& raw::operator /= ( const raw& other )
{
	s32 k;

	forj( channels )
	{
		fori( size )
		{
			k = i * channels % size + j;

			data[k] = math::divide<f32>( data[k], other.data[k] );
		}
	}

	RETHIS;
}

// operator + raw
raw raw::operator + ( const raw& other )
{
	raw r( samples, channels );

	r += other;

	return r;
}

// operator - raw
raw raw::operator - ( const raw& other )
{
	raw r( samples, channels );

	r -= other;

	return r;
}

// operator * raw
raw raw::operator * ( const raw& other )
{
	raw r( samples, channels );

	r *= other;

	return r;
}

// operator / raw
raw raw::operator / ( const raw& other )
{
	raw r( samples, channels );

	r /= other;

	return r;
}

/* end */

}
}

#endif
