
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_SIGNAL_INIT_CPP
#define BDAPI_YMX_SIGNAL_INIT_CPP
#include "ymx/ymx_signal.hpp"

/* includes */

// bdapi
#include "gen/rng.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx signal class initialization function implementations *********************************************/



// constructors

signal::signal()
{
	reset();

	rng_sig = NULL;
}
signal::signal( gen::rng* _rng_sig )
{
	reset();

	if( !set_generator( _rng_sig ) )
		rng_sig = NULL;
}
signal::signal( string _string_filename )
{
	reset();

	rng_sig = NULL;

	if( !load( _string_filename ) )
		*this = signal();
}
signal::signal( gen::rng* _rng_sig, string _string_filename )
{
	reset();

	if( !load( _rng_sig, _string_filename ) )
		*this = signal();
}
signal::signal( const signal& s )
{
	alg = s.alg;

	fori(4)
	{
		op [i] = s.op [i];
		ns [i] = s.ns [i];
		ne [i] = s.ne [i];
		ame[i] = s.ame[i];

		forj(3)
		{
			tl [j][i] = s.tl [j][i];
			ar [j][i] = s.ar [j][i];
			d1r[j][i] = s.d1r[j][i];
			d1l[j][i] = s.d1l[j][i];
			d2r[j][i] = s.d2r[j][i];
			rr [j][i] = s.rr [j][i];

			mul[j][i] = s.mul[j][i];
			kc [j][i] = s.kc [j][i];
			kf [j][i] = s.kf [j][i];
			fb [j][i] = s.fb [j][i];
			nfq[j][i] = s.nfq[j][i];

			frq[j][i] = s.frq[j][i];
			amd[j][i] = s.amd[j][i];
			ams[j][i] = s.ams[j][i];
			pmd[j][i] = s.pmd[j][i];
			pms[j][i] = s.pms[j][i];
		}

		owf[i] = s.owf[i];
		lwf[i] = s.lwf[i];
	}

	rng_sig = s.rng_sig;
}
signal::signal( gen::rng* _rng_sig, const signal& s )
{
	*this = s;

	if( !set_generator( _rng_sig ) )
		rng_sig = NULL;
}



// load from file

result signal::load( io::file& _file_yms )
{
	alg = _file_yms.out<u8>();

	fori(4)
	{
		op [i] = _file_yms.out<u8>();
		ns [i] = _file_yms.out<u8>();
		ne [i] = _file_yms.out<u8>();
		ame[i] = _file_yms.out<u8>();

		for( s32 j = 1; j < 3; j++ )
		{
			tl [j][i] = _file_yms.out<u8>();
			ar [j][i] = _file_yms.out<u8>();
			d1r[j][i] = _file_yms.out<u8>();
			d1l[j][i] = _file_yms.out<u8>();
			d2r[j][i] = _file_yms.out<u8>();
			rr [j][i] = _file_yms.out<u8>();

			mul[j][i] = _file_yms.out<u8>();
			kc [j][i] = _file_yms.out<u8>();
			kf [j][i] = _file_yms.out<u8>();
			fb [j][i] = _file_yms.out<u8>();
			nfq[j][i] = _file_yms.out<u8>();

			frq[j][i] = _file_yms.out<u8>();
			amd[j][i] = _file_yms.out<u8>();
			ams[j][i] = _file_yms.out<u8>();
			pmd[j][i] = _file_yms.out<u8>();
			pms[j][i] = _file_yms.out<u8>();
		}

		owf[i] = _file_yms.out<u8>();
		lwf[i] = _file_yms.out<u8>();
	}

	dis_all(true);

	return 1;
}
result signal::load( gen::rng* _rng_sig, io::file& _file_yms )
{
	if( !set_generator( _rng_sig ) )
	{
		return 0;
	}

	return load( _file_yms );
}
result signal::load( string _string_filename )
{
	io::file file_yms( _string_filename );

	if( !file_yms.read( true ) )
	{
		return 0;
	}

	return load( file_yms );
}
result signal::load( gen::rng* _rng_sig, string _string_filename )
{
	if( !set_generator( _rng_sig ) )
	{
		return 0;
	}

	return load( _string_filename );
}



// set generator

result signal::set_generator( gen::rng* _rng_sig )
{
	if( !_rng_sig )
	{
		return 0;
	}

	rng_sig = _rng_sig;

	return 1;
}



// save

result signal::save( io::file& file_yms )
{
	check();

	file_yms.in<u8>( alg );

	fori(4)
	{
		file_yms.in<u8>( op [i] );
		file_yms.in<u8>( ns [i] );
		file_yms.in<u8>( ne [i] );
		file_yms.in<u8>( ame[i] );

		for( s32 j = 1; j < 3; j++ )
		{
			file_yms.in<u8>( tl [j][i] );
			file_yms.in<u8>( ar [j][i] );
			file_yms.in<u8>( d1r[j][i] );
			file_yms.in<u8>( d1l[j][i] );
			file_yms.in<u8>( d2r[j][i] );
			file_yms.in<u8>( rr [j][i] );

			file_yms.in<u8>( mul[j][i] );
			file_yms.in<u8>( kc [j][i] );
			file_yms.in<u8>( kf [j][i] );
			file_yms.in<u8>( fb [j][i] );
			file_yms.in<u8>( nfq[j][i] );

			file_yms.in<u8>( frq[j][i] );
			file_yms.in<u8>( amd[j][i] );
			file_yms.in<u8>( ams[j][i] );
			file_yms.in<u8>( pmd[j][i] );
			file_yms.in<u8>( pms[j][i] );
		}

		file_yms.in<u8>( owf[i] );
		file_yms.in<u8>( lwf[i] );
	}

	if( !file_yms.save( true ) )
	{
		return 0;
	}

	return 1;
}
result signal::save( string _string_filename )
{
	io::file file_yms( _string_filename );

	return save( file_yms );
}



/* end */
}}
#endif
