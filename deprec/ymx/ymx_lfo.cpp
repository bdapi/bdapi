
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_LFO_CPP
#define BDAPI_YMX_LFO_CPP
#include "ymx/ymx_lfo.hpp"

/* includes */

// bdapi
#include "ymx/ymx_core.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx lfo class implementation *************************************************************************/



// private nullify

void lfo::__nullify()
{
	am_output = 0;
	pm_output = 0;

	am_table_value = 0;
	pm_table_value = 0;

	amd = 0;
	ams = 0.f;

	pmd = 0;
	pms = 0.f;

	lfo_start_flag = 0;
	lfo_overflow   = 0;
	lfo_time       = 0;
	lfo_add        = 0;
	lfo_index      = 0;
	lfo_counter    = 0;
	lfo_step       = 0;
	lfo_frequency  = 0;
	lfo_waveform   = 0;
}



// calculate am value

void lfo::__calc_am_value()
{
	am_output = ( ( am_table_value * amd ) >> 7 ) * ams;
}

// private calculate pm value

void lfo::__calc_pm_value()
{
	pm_output = ( ( abs( pm_table_value ) * pmd ) >> 12 ) * pms;

	if( pm_table_value < 0 )
		pm_output = -pm_output;
}



// constructors

lfo::lfo()
{
	__nullify();
}

// destructor

lfo::~lfo()
{
	discard();
}



// initialize

result lfo::initialize()
{
	lfo_add = 4096;

	set_lwf(0);
	set_frq(0);
	set_amd(0);
	set_ams(0);
	set_pmd(0);
	set_pms(0);

	set_lfo_reset();
	set_lfo_start();

	return 1;
}

// discard

result lfo::discard()
{
	return 1;
}



// set wf

void lfo::set_lwf( s32 n )
{
	lfo_waveform = YMX_LWF(n);

	__calc_am_value();
	__calc_pm_value();
}

// set frq

void lfo::set_frq( s32 n )
{
	lfo_frequency = YMX_FRQ(n);

	lfo_step = 16 + ( lfo_frequency & 15 );

	s32	shift = 15 - ( lfo_frequency >> 4 );

	if( shift == 0 )
	{
		shift      = 1;
		lfo_step <<= 1;
	}

	lfo_overflow = ( 8 << shift ) * 4096;

	lfo_time = 0;
}

// set amd

void lfo::set_amd( s32 n )
{
	amd = YMX_AMD(n) * 2;

	__calc_am_value();
}

// set ams

void lfo::set_ams( s32 n )
{
	ams = 1.f + f32( YMX_AMS(n) ) / 128.f;

	__calc_am_value();
}

// set pmd

void lfo::set_pmd( s32 n )
{
	pmd = YMX_PMD(n) * 32;

	__calc_pm_value();
}

// set pms

void lfo::set_pms( s32 n )
{
	pms = 1.f + f32( YMX_PMS(n) ) / 128.f;

	__calc_pm_value();
}

// set lfo reset

void lfo::set_lfo_reset()
{
	lfo_start_flag = 0;
	lfo_index      = 0;

	__calc_am_value();
	__calc_pm_value();
}

// set lfo start

void lfo::set_lfo_start()
{
	lfo_start_flag = 1;
}



// update

void lfo::update()
{
	if( lfo_start_flag == 0 )
		return;

	lfo_time += lfo_add;

	s32 index_add;

	while( lfo_time >= lfo_overflow )
	{
		lfo_time    -= lfo_overflow;
		lfo_counter += lfo_step;

		if( lfo_waveform == 4 )
		{
			lfo_index = YMX_generate() >> 22;

			am_table_value = __s32_YMX_waveform_table__[1][3][lfo_index];
			pm_table_value = __s32_YMX_waveform_table__[2][3][lfo_index];
		}
		else
		{
			index_add =   lfo_counter >> 4;
			lfo_index = ( lfo_index + index_add ) & 1023;

			am_table_value = __s32_YMX_waveform_table__[1][lfo_waveform][lfo_index];
			pm_table_value = __s32_YMX_waveform_table__[2][lfo_waveform][lfo_index];
		}

		lfo_counter &= 15;

		__calc_am_value();
		__calc_pm_value();
} }



/* end */
}}
#endif
