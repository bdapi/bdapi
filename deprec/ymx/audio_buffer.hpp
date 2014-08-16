
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_AUDIO_BUFFER_HPP
#define BDAPI_AUDIO_BUFFER_HPP
#include "bdapi.hpp"

/* includes */

// sdl
#include "SDL_mixer.h"

// namespaces
namespace bdapi {
namespace audio {



/* audio buffer class declaration ***********************************************************************/



class buffer
{

private:

	private_data( Mix_Chunk*, sdl_chunk_previous, get_previous );
	private_data( Mix_Chunk*, sdl_chunk_current,  get_current  );
	private_data( Mix_Chunk*, sdl_chunk_next,     get_next     );

	private_data( s32, s32_samples, get_samples );

	private_data( s32, s32_channel, get_channel );

private:

	void __nullify ();

public:

	buffer (     );
	buffer ( s32 );
 ~buffer (     );

	result initialize ( s32 );
	result discard    (     );

	s16* fill ();

	result play ( s32 );

};



/* end */
}}
#endif
