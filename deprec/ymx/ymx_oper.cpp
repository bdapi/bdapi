
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_OPER_CPP
#define BDAPI_YMX_OPER_CPP
#include "ymx/ymx_oper.hpp"

/* includes */

// bdapi
#include "core/math.hpp"
#include "ymx/ymx_core.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* static variables *************************************************************************************/



//const static s32 __s32_YMX_xr_next_state__ [ 6] = { 1, 2, 3, 3, 5, 5                       };
//const static s32 __s32_YMX_xr_max_state__  [ 6] = { 0, 3, 3, 3, 5, 5                       };
//const static s32 __s32_YMX_key_code_table__[12] = { 0, 1, 2, 4, 5, 6, 8, 9, 10, 12, 13, 14 };



/* ymx operator class implementation ********************************************************************/



// is zero closs function macro

#define IS_ZERO_CLOSS(AA,BB) ( ( AA < 0 && BB >= 0 ) || ( AA > 0 && BB <= 0 ) )



// private nullify

void oper::__nullify()
{
	s32_input = 0;

	s32_output_1 = NULL;
	s32_output_2 = NULL;
	s32_output_3 = NULL;

	sig.s32_note = 0;
	sig.s32_tl   = 0;
	sig.s32_ar   = 0;
	sig.s32_d1r  = 0;
	sig.s32_d2r  = 0;
	sig.s32_rr   = 0;
	sig.s32_owf  = 0;
	sig.s32_kc   = 0;
	sig.s32_kf   = 0;
	sig.s32_ame  = 0;

	LFO.s32_alpha = 0;
	LFO.s32_pitch = 0;
	LFO.s32_level = 0;
	LFO.bl_recalc = false;

	time.s32_ticks = 0;
	time.s32_delta = 0;
	time.s32_ar    = 0;

	pitch.s32_val = 0;
	pitch.s32_dt1 = 0;
	pitch.s32_mul = 0;

	fb.f32_level  = 0.f;
	fb.s32_input  = 0;
	fb.s32_output = 0;

	noise.s32_enabled   = 0;
	noise.s32_frequency = 0;
	noise.s32_counter   = 0;
	noise.s32_step      = 0;
	noise.s32_cycle     = 0;
	noise.s32_value     = 0;

	xr.s32_state = 0;
	xr.s32_el    = 0;
	xr.s32_step  = 0;
	xr.s32_and   = 0;
	xr.s32_cmp   = 0;
	xr.s32_add   = 0;
	xr.s32_limit = 0;

	fori(6)
	{
		state_table[i].s32_val_and = 0;
		state_table[i].s32_val_cmp = 0;
		state_table[i].s32_val_pls = 0;
		state_table[i].s32_val_lim = 0;
	}

	s32_sine_buffer = 0;

	lfo_operator = NULL;

	chip_parent = NULL;
}



// constructor

oper::oper()
{
	__nullify();
}

// destructor

oper::~oper()
{
	discard();
}



// initialize

result oper::initialize( chip* _chip_parent )
{
	LFO.s32_pitch = -1;
	LFO.s32_level = -1;
	LFO.bl_recalc = true;

	noise.s32_step = s64( 1 << 26 ) * 0.03125f;

	xr.s32_el = 1024;

	set_nfq(0);

	noise.s32_value = 1;

	state_table[2].s32_val_lim = 63;
	state_table[3].s32_val_lim = 63;
	state_table[4].s32_val_lim = 63;
	state_table[5].s32_val_lim = 63;

	state_table[3].s32_val_and = 4097;
	state_table[3].s32_val_cmp = 2048;
	state_table[5].s32_val_and = 4097;
	state_table[5].s32_val_cmp = 2048;

	xr.s32_state = 5;
	xr.s32_and   = state_table[ xr.s32_state ].s32_val_and;
	xr.s32_cmp   = state_table[ xr.s32_state ].s32_val_cmp;
	xr.s32_add   = state_table[ xr.s32_state ].s32_val_pls;
	xr.s32_limit = state_table[ xr.s32_state ].s32_val_lim;

	lfo_operator = new lfo();

	lfo_operator->initialize();

	chip_parent = _chip_parent;

	__calculate_ar();
	__calculate_d1r();
	__calculate_d2r();
	__calculate_rr();
	__calculate_pitch();
	__calculate_noise();

	return 1;
}

// discard

result oper::discard()
{
	delete lfo_operator;

	return 1;
}



// set key on

void oper::set_key_on()
{
	if( xr.s32_state >= 4 )
	{
		time.s32_ticks = 0;

		if( xr.s32_el == 0 )
		{
			xr.s32_state = 1;
			xr.s32_and   = state_table[ xr.s32_state ].s32_val_and;
			xr.s32_cmp   = state_table[ xr.s32_state ].s32_val_cmp;
			xr.s32_add   = state_table[ xr.s32_state ].s32_val_pls;
			xr.s32_limit = state_table[ xr.s32_state ].s32_val_lim;

			if( ( xr.s32_el >> 4 ) == xr.s32_limit )
			{
				xr.s32_state = __s32_YMX_xr_next_state__[ xr.s32_state ];
				xr.s32_and   =               state_table[ xr.s32_state ].s32_val_and;
				xr.s32_cmp   =               state_table[ xr.s32_state ].s32_val_cmp;
				xr.s32_add   =               state_table[ xr.s32_state ].s32_val_pls;
				xr.s32_limit =               state_table[ xr.s32_state ].s32_val_lim;
			}
		}
		else
		{
			xr.s32_state = 0;
			xr.s32_and   = state_table[ xr.s32_state ].s32_val_and;
			xr.s32_cmp   = state_table[ xr.s32_state ].s32_val_cmp;
			xr.s32_add   = state_table[ xr.s32_state ].s32_val_pls;
			xr.s32_limit = state_table[ xr.s32_state ].s32_val_lim;
} } }

// set key off

void oper::set_key_off()
{
	xr.s32_state = 4;
	xr.s32_and   = state_table[ xr.s32_state ].s32_val_and;
	xr.s32_cmp   = state_table[ xr.s32_state ].s32_val_cmp;
	xr.s32_add   = state_table[ xr.s32_state ].s32_val_pls;
	xr.s32_limit = state_table[ xr.s32_state ].s32_val_lim;

	if( ( xr.s32_el >> 4 ) >= 63 )
	{
		xr.s32_el    = 1024;
		xr.s32_state = __s32_YMX_xr_max_state__[ xr.s32_state ];
		xr.s32_and   =              state_table[ xr.s32_state ].s32_val_and;
		xr.s32_cmp   =              state_table[ xr.s32_state ].s32_val_cmp;
		xr.s32_add   =              state_table[ xr.s32_state ].s32_val_pls;
		xr.s32_limit =              state_table[ xr.s32_state ].s32_val_lim;
} }

// set ne

void oper::set_ne( s32 n )
{
	noise.s32_enabled = YMX_NE(n);

	if( noise.s32_enabled == 1 )
	{
		LFO.bl_recalc = true;
	}

	__calculate_noise();
}

// set ame

void oper::set_ame( s32 n )
{
	sig.s32_ame = 0;

	if( YMX_AME(n) == 1 )
	{
		sig.s32_ame = -1;
} }

// set tl

void oper::set_tl( s32 n )
{
	sig.s32_tl = YMX_TL(n) << 2;

	LFO.bl_recalc = true;
}

// set ar

void oper::set_ar( s32 n )
{
	sig.s32_ar = YMX_LIMIT_AR - YMX_AR(n) + 40;

	__calculate_ar();
}

// set d1r

void oper::set_d1r( s32 n )
{
	sig.s32_d1r = YMX_D1R(n) + 48;

	__calculate_d1r();
}

// set d1l

void oper::set_d1l( s32 n )
{
	state_table[1].s32_val_lim = YMX_D1L(n);

	if( xr.s32_state == 1 )
	{
		xr.s32_limit = state_table[1].s32_val_lim;
} }

// set d2r

void oper::set_d2r( s32 n )
{
	sig.s32_d2r = YMX_D2R(n) + 56;

	__calculate_d2r();

	LFO.s32_pitch = -1;
}

// set rr

void oper::set_rr( s32 n )
{
	sig.s32_rr = YMX_LIMIT_RR - YMX_RR(n) + 80;

	__calculate_rr();
}

// set owf

void oper::set_owf( s32 n )
{
	sig.s32_owf = YMX_OWF(n);
}

// set mul

void oper::set_mul( s32 n )
{
	pitch.s32_mul = YMX_MUL(n) << 1;

	if( pitch.s32_mul == 0 )
	{
		pitch.s32_mul = 1;
	}

	LFO.s32_pitch = -1;
}

// set kc

void oper::set_kc( s32 n )
{
	s32 v = YMX_KC(n);

	sig.s32_kc = __s32_YMX_key_code_table__[ v % 12 ] + v / 12 * 16;

	s32 m = sig.s32_kc & 15;

	sig.s32_note = ( ( sig.s32_kc >> 4 ) + 1 ) * 12 + m - ( m >> 2 );

	sig.s32_kc++;

	__calculate_pitch();

	LFO.s32_pitch = -1;

	__calculate_ar();
	__calculate_d1r();
	__calculate_d2r();
	__calculate_rr();
}

// set kf

void oper::set_kf( s32 n )
{
	sig.s32_kf = YMX_KF(n);

	__calculate_pitch();

	LFO.s32_pitch = -1;
}

// set fb

void oper::set_fb( s32 n )
{
	fb.f32_level = 1.f / f32( YMX_LIMIT_FB - YMX_FB(n) + 1 );
}

// set nfq

void oper::set_nfq( s32 n )
{
	noise.s32_frequency = YMX_LIMIT_NFQ - YMX_NFQ(n);

	__calculate_noise();
}

// set lwf

void oper::set_lwf( s32 n )
{
	lfo_operator->set_lwf(n);
}

// set frq

void oper::set_frq( s32 n )
{
	lfo_operator->set_frq(n);
}

// set amd

void oper::set_amd( s32 n )
{
	lfo_operator->set_amd(n);
}

// set ams

void oper::set_ams( s32 n )
{
	lfo_operator->set_ams(n);
}

// set pmd

void oper::set_pmd( s32 n )
{
	lfo_operator->set_pmd(n);
}

// set pms

void oper::set_pms( s32 n )
{
	lfo_operator->set_pms(n);
}

// set lfo reset

void oper::set_lfo_reset()
{
	lfo_operator->set_lfo_reset();
}

// set lfo start

void oper::set_lfo_start()
{
	lfo_operator->set_lfo_start();
}



// set envelope

void oper::set_envelope( s32 e )
{
	if( xr.s32_state == 5 )
	{
		return;
	}

	if( ( e & xr.s32_and ) == xr.s32_cmp )
	{
		if( xr.s32_state == 0 )
		{
			xr.s32_step +=    xr.s32_add;
			xr.s32_el   += ( ~xr.s32_el * ( xr.s32_step >> 3 ) ) >> 4;

			LFO.bl_recalc = true;

			xr.s32_step &= 7;

			if( xr.s32_el <= 0 )
			{
				xr.s32_el    = 0;
				xr.s32_state = 1;
				xr.s32_and   = state_table[ xr.s32_state ].s32_val_and;
				xr.s32_cmp   = state_table[ xr.s32_state ].s32_val_cmp;
				xr.s32_add   = state_table[ xr.s32_state ].s32_val_pls;
				xr.s32_limit = state_table[ xr.s32_state ].s32_val_lim;

				if( ( xr.s32_el >> 4 ) == xr.s32_limit )
				{
					xr.s32_state = __s32_YMX_xr_next_state__[ xr.s32_state ];
					xr.s32_and   =               state_table[ xr.s32_state ].s32_val_and;
					xr.s32_cmp   =               state_table[ xr.s32_state ].s32_val_cmp;
					xr.s32_add   =               state_table[ xr.s32_state ].s32_val_pls;
					xr.s32_limit =               state_table[ xr.s32_state ].s32_val_lim;
		} } }
		else
		{
			xr.s32_step += xr.s32_add;
			xr.s32_el   += xr.s32_step >> 3;

			LFO.bl_recalc = true;

			xr.s32_step &= 7;

			s32 f = xr.s32_el >> 4;

			if( f == 63 )
			{
				xr.s32_el    = 1024;
				xr.s32_state = __s32_YMX_xr_max_state__[ xr.s32_state ];
				xr.s32_and   =              state_table[ xr.s32_state ].s32_val_and;
				xr.s32_cmp   =              state_table[ xr.s32_state ].s32_val_cmp;
				xr.s32_add   =              state_table[ xr.s32_state ].s32_val_pls;
				xr.s32_limit =              state_table[ xr.s32_state ].s32_val_lim;
			}
			else if( f == xr.s32_limit )
			{
				xr.s32_state = __s32_YMX_xr_next_state__[ xr.s32_state ];
				xr.s32_and   =               state_table[ xr.s32_state ].s32_val_and;
				xr.s32_cmp   =               state_table[ xr.s32_state ].s32_val_cmp;
				xr.s32_add   =               state_table[ xr.s32_state ].s32_val_pls;
				xr.s32_limit =               state_table[ xr.s32_state ].s32_val_lim;
} } } }



// send output 1

s32 oper::send_output_1()
{
	s32 output_data = __calc_output_all();

	*s32_output_1 = output_data;
	*s32_output_2 = output_data;
	*s32_output_3 = output_data;

	return output_data;
}

// send output 2

s32 oper::send_output_2()
{
	s32 output_data = __calc_output_all();

	*s32_output_1 += output_data;

	return output_data;
}

// send output 3

s32 oper::send_output_3()
{
	s32 output_data = __calc_output_all();

	*s32_output_1  += output_data;
	*s32_output_1 >>= 7;

	return output_data;
}



// get lfo

lfo* oper::get_lfo()
{
	return lfo_operator;
}



// private check output lfo

s32 oper::__check_output_lfo()
{
	if( LFO.s32_pitch != lfo_operator->get_pm() )
	{
		time.s32_delta = ( ( __s32_YMX_step_table_1__[ pitch.s32_val + lfo_operator->get_pm() ] )
			* pitch.s32_mul ) >> 7;

		LFO.s32_pitch  = lfo_operator->get_pm();
	}

	time.s32_ticks += time.s32_delta;

	return 0;
}



// private calculate output waveform

s32 oper::__calc_output_waveform()
{
	#if 0

	if( sig.s32_owf < 2 )
	{
		return __s32_YMX_waveform_table__[0][sig.s32_owf]
			[ ( ( time.s32_ticks + fb.s32_output + s32_input ) >> 10 ) & 1023 ];
	}
	else
	{
		return __s32_YMX_waveform_table__[0][sig.s32_owf]
			[   ( time.s32_ticks                               >> 10 ) & 1023 ];
	}

	#else

	return __s32_YMX_waveform_table__[0][sig.s32_owf][ ( time.s32_ticks >> 10 ) & 1023 ];

	#endif
}

// private calculate output alpha

s32 oper::__calc_output_alpha()
{
	s32 sine          = __calc_output_waveform();
	s32 lfo_level_ame = lfo_operator->get_am() & sig.s32_ame;

	if( ( LFO.s32_level != lfo_level_ame || LFO.bl_recalc ) && IS_ZERO_CLOSS( s32_sine_buffer, sine ) )
	{
		LFO.s32_alpha = __s32_YMX_alpha_table__[ 3072 + sig.s32_tl - xr.s32_el - lfo_level_ame ];
		LFO.s32_level = lfo_level_ame;
		LFO.bl_recalc = false;
	}

	s32_sine_buffer = sine;

	return LFO.s32_alpha * sine;
}

// private calculate output noise

s32 oper::__calc_output_noise()
{
	s32 sine          = __calc_output_waveform();
	s32 lfo_level_ame = lfo_operator->get_am() & sig.s32_ame;

	noise.s32_counter -= noise.s32_step;

	if( noise.s32_counter <= 0 )
	{
		noise.s32_value    = s32( ( YMX_generate() >> 30 ) & 2 ) - 1;
		noise.s32_counter += noise.s32_cycle;
	}

	if( ( LFO.s32_level != lfo_level_ame || LFO.bl_recalc ) && IS_ZERO_CLOSS( s32_sine_buffer, sine ) )
	{
		LFO.s32_alpha = __s32_YMX_alpha_table__[ 3072 + sig.s32_tl - xr.s32_el - lfo_level_ame ];
		LFO.s32_level = lfo_level_ame;
		LFO.bl_recalc = false;
	}

	s32_sine_buffer = sine;

	return LFO.s32_alpha * noise.s32_value * sine;
}

// private calculate output feedback

void oper::__calc_output_feedback( s32 _output_data )
{
	fb.s32_output = f32( _output_data + fb.s32_input ) * fb.f32_level;
	fb.s32_input  =      _output_data;
}

// private calculate output all

s32 oper::__calc_output_all()
{
	s32 output_data = __check_output_lfo();

	if( xr.s32_state != 5 )
	{
		if( noise.s32_enabled == 0 )
		{
			output_data = __calc_output_alpha();
		}
		else
		{
			output_data = __calc_output_noise();
	} }

	__calc_output_feedback( output_data );

	return output_data;
}



// private calculate ar

void oper::__calculate_ar()
{
	state_table[0].s32_val_and = __s32_YMX_state_value_and__[ sig.s32_ar ];
	state_table[0].s32_val_cmp = __s32_YMX_state_value_and__[ sig.s32_ar ] >> 1;
	state_table[0].s32_val_pls = __s32_YMX_state_value_pls__[ sig.s32_ar ];

	if( xr.s32_state == 0 )
	{
		xr.s32_and = state_table[0].s32_val_and;
		xr.s32_cmp = state_table[0].s32_val_cmp;
		xr.s32_add = state_table[0].s32_val_pls;
} }

// private calculate d1r

void oper::__calculate_d1r()
{
	state_table[1].s32_val_and = __s32_YMX_state_value_and__[ sig.s32_d1r ];
	state_table[1].s32_val_cmp = __s32_YMX_state_value_and__[ sig.s32_d1r ] >> 1;
	state_table[1].s32_val_pls = __s32_YMX_state_value_pls__[ sig.s32_d1r ];

	if( xr.s32_state == 1 )
	{
		xr.s32_and = state_table[1].s32_val_and;
		xr.s32_cmp = state_table[1].s32_val_cmp;
		xr.s32_add = state_table[1].s32_val_pls;
} }

// private calculate d2r

void oper::__calculate_d2r()
{
	state_table[2].s32_val_and = __s32_YMX_state_value_and__[ sig.s32_d2r ];
	state_table[2].s32_val_cmp = __s32_YMX_state_value_and__[ sig.s32_d2r ] >> 1;
	state_table[2].s32_val_pls = __s32_YMX_state_value_pls__[ sig.s32_d2r ];

	if( xr.s32_state == 2 )
	{
		xr.s32_and = state_table[2].s32_val_and;
		xr.s32_cmp = state_table[2].s32_val_cmp;
		xr.s32_add = state_table[2].s32_val_pls;
} }

// private calculate rr

void oper::__calculate_rr()
{
	state_table[4].s32_val_and = __s32_YMX_state_value_and__[ sig.s32_rr ];
	state_table[4].s32_val_cmp = __s32_YMX_state_value_and__[ sig.s32_rr ] >> 1;
	state_table[4].s32_val_pls = __s32_YMX_state_value_pls__[ sig.s32_rr ];

	if( xr.s32_state == 4 )
	{
		xr.s32_and = state_table[4].s32_val_and;
		xr.s32_cmp = state_table[4].s32_val_cmp;
		xr.s32_add = state_table[4].s32_val_pls;
} }

// private calculate val

void oper::__calculate_pitch()
{
	pitch.s32_val = ( sig.s32_note << 6 ) + sig.s32_kf;
}

// private calculate noise

void oper::__calculate_noise()
{
	if( noise.s32_enabled == 1 )
	{
		noise.s32_cycle = noise.s32_frequency << 23;

		if( noise.s32_cycle < noise.s32_step )
		{
			noise.s32_cycle = noise.s32_step;
		}

		noise.s32_counter = noise.s32_cycle;
	}
	else
	{
		noise.s32_cycle = 0;
} }



/* end */
}}
#endif
