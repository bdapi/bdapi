
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_GEN_RNG_INIT_CPP
#define BDAPI_GEN_RNG_INIT_CPP
#include "gen/rng.hpp"

/* includes */

// standard
#include "ctime"

// bdapi

/* namespaces */
namespace bdapi {
namespace gen   {

/* static variable declarations */

static u32 seed_offset = 0;

/* random number generator class initialization function implementations */

// constructors
rng::rng()
{
	set_seed( time(NULL) + seed_offset++ );
}
rng::rng( u32 seed )
{
	set_seed( seed );
}
rng::rng( const rng& copy )
{
	seed = copy.seed;

	engine = copy.engine;
}

// set seed
rng& rng::set_seed( u32 seed )
{
	this->seed = seed;

	return reset();
}
rng& rng::set_seed( rng& other )
{
	seed = other.generate_seed();

	return reset();
}

// reset
rng& rng::reset()
{
	engine.seed( seed );

	RETHIS;
}

/* end */

}
}

#endif
