
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_GEN_RNG_HPP
#define BDAPI_GEN_RNG_HPP
#include "bdapi.hpp"

/* includes */

// boost
#include "boost/random/mersenne_twister.hpp"

/* namespaces */
namespace bdapi {
namespace gen   {

/* random number generator class declaration */

class rng
{

private: // private data

	BD_GET_COPY( private, u32, seed );

	BD_GET_REFR( private, boost::mt11213b, engine );

public: // public initialization functions (gen_rng_init.cpp)

	rng ();
	rng (       u32  seed );
	rng ( const rng& copy );
 ~rng () {};

	rng& set_seed ( u32  seed  );
	rng& set_seed ( rng& other );

	rng& reset ();

public: // public core functions (gen_rng_core.cpp)

	template<typename AA> AA get (                                           );
	template<typename AA> AA get (                                    AA max );
	template<typename AA> AA get (                            AA min, AA max );
	template<typename AA> AA get ( distribution* distributor                 );
	template<typename AA> AA get ( distribution* distributor,         AA max );
	template<typename AA> AA get ( distribution* distributor, AA min, AA max );

	u32 generate_seed (                           );
	u32 generate_seed ( distribution* distributor );

	bl get_chance (                            f64 chance );
	bl get_chance ( distribution* distributor, f64 chance );

};

/* end */

}
}

#endif
