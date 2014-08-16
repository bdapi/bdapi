
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_GEN_DISTRIBUTION_CORE_CPP
#define BDAPI_GEN_DISTRIBUTION_CORE_CPP
#include "gen/distribution.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace gen   {

/* distribution class core function implementations */

// private get cauchy
f64 distribution::get_cauchy( boost::mt11213b* engine )
{
	return D_cauchy->operator()( *engine );
}

// private get chisquared
f64 distribution::get_chisquared( boost::mt11213b* engine )
{
	return D_chisquared->operator()( *engine );
}

// private get constant
f64 distribution::get_constant( boost::mt11213b* engine )
{
	return D_constant->operator()( *engine );
}

// private get exponential
f64 distribution::get_exponential( boost::mt11213b* engine )
{
	return D_exponential->operator()( *engine );
}

// private get extreme
f64 distribution::get_extreme( boost::mt11213b* engine )
{
	return D_extreme->operator()( *engine );
}

// private get fisher
f64 distribution::get_fisher( boost::mt11213b* engine )
{
	return D_fisher->operator()( *engine );
}

// private get gamma
f64 distribution::get_gamma( boost::mt11213b* engine )
{
	return D_gamma->operator()( *engine );
}

// private get linear
f64 distribution::get_linear( boost::mt11213b* engine )
{
	return D_linear->operator()( *engine );
}

// private get lognormal
f64 distribution::get_lognormal( boost::mt11213b* engine )
{
	return D_lognormal->operator()( *engine );
}

// private get normal
f64 distribution::get_normal( boost::mt11213b* engine )
{
	return D_normal->operator()( *engine );
}

// private get poisson
f64 distribution::get_poisson( boost::mt11213b* engine )
{
	return D_poisson->operator()( *engine );
}

// private get student
f64 distribution::get_student( boost::mt11213b* engine )
{
	return D_student->operator()( *engine );
}

// private get triangle
f64 distribution::get_triangle( boost::mt11213b* engine )
{
	return D_triangle->operator()( *engine );
}

// private get uniform
f64 distribution::get_uniform( boost::mt11213b* engine )
{
	return D_uniform->operator()( *engine );
}

// private get weibull
f64 distribution::get_weibull( boost::mt11213b* engine )
{
	return D_weibull->operator()( *engine );
}

/* end */

}
}

#endif
