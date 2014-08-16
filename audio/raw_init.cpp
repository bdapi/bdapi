
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_RAW_INIT_CPP
#define BDAPI_AUDIO_RAW_INIT_CPP
#include "audio/raw.hpp"

/* includes */

// bdapi
#include "audio/handler.hpp"

// namespaces
namespace bdapi {
namespace audio {

/* audio raw data class initialization function implementations */

// constructors
raw::raw( s32 channels )
{
	initialize( channels );
}
raw::raw( f32* data, s32 channels )
{
	initialize( data, channels );
}
raw::raw( s32 samples, s32 channels )
{
	initialize( samples, channels );
}
raw::raw( f32* data, s32 samples, s32 channels )
{
	initialize( data, samples, channels );
}

// destructor
raw::~raw()
{
	if( !external )
	{
		DESTRUCT( data );
	}
}

// initializers
result raw::initialize()
{
	return initialize( NULL, audio::get_chunk_size(), 1 );
}
result raw::initialize( s32 channels )
{
	return initialize( NULL, audio::get_chunk_size(), channels );
}
result raw::initialize( f32* data, s32 channels )
{
	return initialize( data, audio::get_chunk_size(), channels );
}
result raw::initialize( s32 samples, s32 channels )
{
	return initialize( NULL, samples, channels );
}
result raw::initialize( f32* data, s32 samples, s32 channels )
{
	this->samples  = samples;
	this->channels = channels;
	      seconds  = (f32)this->samples / (f32)audio::get_frequency();

	size = this->samples * this->channels;

	if( data )
	{
		external = true;

		this->data = data;
	}
	else
	{
		external = false;

		this->data = new f32[ size ]();
	}

	return 1;
}

/* end */

}
}

#endif
