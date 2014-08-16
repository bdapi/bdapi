
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_VOICE_MOD_CPP
#define BDAPI_SYNTH_VOICE_MOD_CPP
#include "synth/voice.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer voice class modification function implementations */

// set parameters
void voice::set_parameters( const synth::module_parameters& params )
{
	//BD_MUTEX( voice_mutex );

	this->params = params;
}

// apply parameters
void voice::apply_parameters()
{
	apply_parameters( params );
}
void voice::apply_parameters( const synth::module_parameters& params )
{
}

/* end */

}
}

#endif
