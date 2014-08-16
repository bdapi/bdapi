
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_SYNTH_MODULE_CORE_CPP
#define BDAPI_SYNTH_MODULE_CORE_CPP
#include "synth/module.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace synth {

/* synthesizer module class core function implementations */

// key on
void module::key_on( s32 note, f32 velocity )
{
	key_on( note, velocity, 0.f );
}
void module::key_on( s32 note, f32 velocity, f32 duration )
{
	BD_MUTEX( module_mutex );

	s32 next = get_next();

	if( next < 0 )
	{
		return;
	}

	last_voice_index = next;

	synth::voice& v = voices[ voice_indices.insert( next ) ];

	v.reset();

	v.set_parameters( params );

	v.apply_parameters();

	v.key_on( note, velocity, duration );
}

// key off
void module::key_off()
{
	BD_MUTEX( module_mutex );

	fori( voice_indices.get_size() )
	{
		voices[ voice_indices[i] ].key_off();
	}
}
void module::key_off( s32 i )
{
	BD_MUTEX( module_mutex );

	forj( voice_indices.get_size() )
	{
		if( voice_indices[j] == i )
		{
			voices[ voice_indices[j] ].key_off();
		}
	}
}

/* end */

}
}

#endif
