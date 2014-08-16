
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_GEN_DISTRIBUTION_HPP
#define BDAPI_GEN_DISTRIBUTION_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "functional"

// boost
#include "boost/random/cauchy_distribution.hpp"
#include "boost/random/chi_squared_distribution.hpp"
#include "boost/random/exponential_distribution.hpp"
#include "boost/random/extreme_value_distribution.hpp"
#include "boost/random/fisher_f_distribution.hpp"
#include "boost/random/gamma_distribution.hpp"
#include "boost/random/lognormal_distribution.hpp"
#include "boost/random/normal_distribution.hpp"
#include "boost/random/piecewise_constant_distribution.hpp"
#include "boost/random/poisson_distribution.hpp"
#include "boost/random/piecewise_linear_distribution.hpp"
#include "boost/random/student_t_distribution.hpp"
#include "boost/random/triangle_distribution.hpp"
#include "boost/random/uniform_01.hpp"
#include "boost/random/weibull_distribution.hpp"

// bdapi
#include "gen/rng.hpp"

/* namespaces */
namespace bdapi {
namespace gen   {

/* distribution typedef declarations */

typedef boost::        cauchy_distribution<f64>                 cauchy;
typedef boost::random::chi_squared_distribution<f64>            chisquared;
typedef boost::random::piecewise_constant_distribution<f64,f64> constant;
typedef boost::        exponential_distribution<f64>            exponential;
typedef boost::random::extreme_value_distribution<f64>          extreme;
typedef boost::random::fisher_f_distribution<f64>               fisher;
typedef boost::        gamma_distribution<f64>                  gamma;
typedef boost::random::piecewise_linear_distribution<f64>       linear;
typedef boost::        lognormal_distribution<f64>              lognormal;
typedef boost::        normal_distribution<f64>                 normal;
typedef boost::        poisson_distribution<s32,f64>            poisson;
typedef boost::random::student_t_distribution<f64>              student;
typedef boost::random::triangle_distribution<f64>               triangle;
typedef boost::        uniform_01<f64>                          uniform;
typedef boost::random::weibull_distribution<f64>                weibull;

/* distribution class declaration */

class distribution
{

private: // private distribution data

	cauchy*      D_cauchy;
	chisquared*  D_chisquared;
	constant*    D_constant;
	exponential* D_exponential;
	extreme*     D_extreme;
	fisher*      D_fisher;
	gamma*       D_gamma;
	linear*      D_linear;
	lognormal*   D_lognormal;
	normal*      D_normal;
	poisson*     D_poisson;
	student*     D_student;
	triangle*    D_triangle;
	uniform*     D_uniform;
	weibull*     D_weibull;

private: // private function pointer data

	std::function< f64( boost::mt11213b* ) > dist_func;

private: // private friends

	friend class rng;

public: // public initialization functions (gen_distribution_init.cpp)

	distribution ();
	distribution ( const distribution& copy );
 ~distribution ();

	distribution& set_cauchy      ();
	distribution& set_chisquared  ();
	distribution& set_constant    ();
	distribution& set_exponential ();
	distribution& set_extreme     ();
	distribution& set_fisher      ();
	distribution& set_gamma       ();
	distribution& set_linear      ();
	distribution& set_lognormal   ();
	distribution& set_normal      ();
	distribution& set_poisson     ();
	distribution& set_student     ();
	distribution& set_triangle    ();
	distribution& set_uniform     ();
	distribution& set_weibull     ();

private: // private core functions (gen_distribution_core.cpp)

	f64 get_cauchy      ( boost::mt11213b* engine );
	f64 get_chisquared  ( boost::mt11213b* engine );
	f64 get_constant    ( boost::mt11213b* engine );
	f64 get_exponential ( boost::mt11213b* engine );
	f64 get_extreme     ( boost::mt11213b* engine );
	f64 get_fisher      ( boost::mt11213b* engine );
	f64 get_gamma       ( boost::mt11213b* engine );
	f64 get_linear      ( boost::mt11213b* engine );
	f64 get_lognormal   ( boost::mt11213b* engine );
	f64 get_normal      ( boost::mt11213b* engine );
	f64 get_poisson     ( boost::mt11213b* engine );
	f64 get_student     ( boost::mt11213b* engine );
	f64 get_triangle    ( boost::mt11213b* engine );
	f64 get_uniform     ( boost::mt11213b* engine );
	f64 get_weibull     ( boost::mt11213b* engine );

public: // public inlined operator functions

	inline f64 operator () ( boost::mt11213b* engine ) { return dist_func( engine ); };

};

/* end */

}
}

#endif
