
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_GEN_DISTRIBUTION_INIT_CPP
#define BDAPI_GEN_DISTRIBUTION_INIT_CPP
#include "gen/distribution.hpp"

/* includes */

/* namespaces */
namespace bdapi {
namespace gen   {

/* distribution class initialization function implementations */

// constructors
distribution::distribution()
{
	set_uniform();
}
distribution::distribution( const distribution& copy )
{
	#define DIST_COPY(AA) if( copy.D_##AA ) D_##AA = new AA( *copy.D_##AA )

	DIST_COPY( cauchy      );
	DIST_COPY( chisquared  );
	DIST_COPY( constant    );
	DIST_COPY( exponential );
	DIST_COPY( extreme     );
	DIST_COPY( fisher      );
	DIST_COPY( gamma       );
	DIST_COPY( linear      );
	DIST_COPY( lognormal   );
	DIST_COPY( normal      );
	DIST_COPY( poisson     );
	DIST_COPY( student     );
	DIST_COPY( triangle    );
	DIST_COPY( uniform     );
	DIST_COPY( weibull     );

	#undef DIST_COPY

	dist_func = copy.dist_func;
}

// destructor
distribution::~distribution()
{
	delete D_cauchy;
	delete D_chisquared;
	delete D_constant;
	delete D_exponential;
	delete D_extreme;
	delete D_fisher;
	delete D_gamma;
	delete D_linear;
	delete D_lognormal;
	delete D_normal;
	delete D_poisson;
	delete D_student;
	delete D_triangle;
	delete D_uniform;
	delete D_weibull;
}

// set distribution cauchy
distribution& distribution::set_cauchy()
{
	delete D_cauchy;

	D_cauchy = new cauchy();

	dist_func = std::bind( &distribution::get_cauchy, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution chisquared
distribution& distribution::set_chisquared()
{
	delete D_chisquared;

	D_chisquared = new chisquared();

	dist_func = std::bind( &distribution::get_chisquared, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution constant
distribution& distribution::set_constant()
{
	delete D_constant;

	D_constant = new constant();

	dist_func = std::bind( &distribution::get_constant, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution exponential
distribution& distribution::set_exponential()
{
	delete D_exponential;

	D_exponential = new exponential();

	dist_func = std::bind( &distribution::get_exponential, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution extreme
distribution& distribution::set_extreme()
{
	delete D_extreme;

	D_extreme = new extreme();

	dist_func = std::bind( &distribution::get_extreme, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution fisher
distribution& distribution::set_fisher()
{
	delete D_fisher;

	D_fisher = new fisher();

	dist_func = std::bind( &distribution::get_fisher, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution gamma
distribution& distribution::set_gamma()
{
	delete D_gamma;

	D_gamma = new gamma();

	dist_func = std::bind( &distribution::get_gamma, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution linear
distribution& distribution::set_linear()
{
	delete D_linear;

	D_linear = new linear();

	dist_func = std::bind( &distribution::get_linear, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution lognormal
distribution& distribution::set_lognormal()
{
	delete D_lognormal;

	D_lognormal = new lognormal();

	dist_func = std::bind( &distribution::get_lognormal, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution normal
distribution& distribution::set_normal()
{
	delete D_normal;

	D_normal = new normal();

	dist_func = std::bind( &distribution::get_normal, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution poisson
distribution& distribution::set_poisson()
{
	delete D_poisson;

	D_poisson = new poisson();

	dist_func = std::bind( &distribution::get_poisson, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution student
distribution& distribution::set_student()
{
	delete D_student;

	D_student = new student();

	dist_func = std::bind( &distribution::get_student, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution triangle
distribution& distribution::set_triangle()
{
	delete D_triangle;

	D_triangle = new triangle();

	dist_func = std::bind( &distribution::get_triangle, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution uniform
distribution& distribution::set_uniform()
{
	delete D_uniform;

	D_uniform = new uniform();

	dist_func = std::bind( &distribution::get_uniform, this, std::placeholders::_1 );

	RETHIS;
}

// set distribution weibull
distribution& distribution::set_weibull()
{
	delete D_weibull;

	D_weibull = new weibull();

	dist_func = std::bind( &distribution::get_weibull, this, std::placeholders::_1 );

	RETHIS;
}

/* end */

}
}

#endif
