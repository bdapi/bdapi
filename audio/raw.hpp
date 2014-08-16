
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_RAW_HPP
#define BDAPI_AUDIO_RAW_HPP
#include "bdapi.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace audio {

/* audio raw data class declaration */

class raw
{

private: // private core data

	BD_GET_COPY_INIT( private, f32*, data, NULL );

private: // private descriptor data

	BD_GET_COPY_INIT( private, s32, samples,  0   );
	BD_GET_COPY_INIT( private, s32, channels, 0   );
	BD_GET_COPY_INIT( private, f32, seconds,  0.f );

	BD_GET_COPY_INIT( private, s32, size, 0 );

	BD_IS_COPY_INIT( private, bl, external, false );

public: // public initialization functions (audio_raw_init.cpp)

	raw () {};
	raw (                         s32 channels );
	raw ( f32* data,              s32 channels );
	raw (            s32 samples, s32 channels );
	raw ( f32* data, s32 samples, s32 channels );
 ~raw ();

	result initialize (                                      );
	result initialize (                         s32 channels );
	result initialize ( f32* data,              s32 channels );
	result initialize (            s32 samples, s32 channels );
	result initialize ( f32* data, s32 samples, s32 channels );

public: // public core functions (audio_raw_core.cpp)

	void clear ();

	f32* copy ();

public: // public modification functions (audio_raw_mod.cpp)

	f32& set (        s32 i, f32 d );
	f32& set ( s32 c, s32 i, f32 d );

public: // public query functions (audio_raw_query.cpp)

	f32& get (        s32 i );
	f32& get ( s32 c, s32 i );

public: // public operator functions (audio_raw_oper.cpp)

	f32& operator [] ( s32 i );
	f32& operator () ( s32 i );

	raw& operator  = ( f32* data );

	raw& operator  = ( const raw& other );
	raw& operator += ( const raw& other );
	raw& operator -= ( const raw& other );
	raw& operator *= ( const raw& other );
	raw& operator /= ( const raw& other );
	raw  operator +  ( const raw& other );
	raw  operator -  ( const raw& other );
	raw  operator *  ( const raw& other );
	raw  operator /  ( const raw& other );

};

/* end */

}
}

#endif
