
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_CORE_HPP
#define BDAPI_YMX_CORE_HPP
#include "bdapi.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx operator notes ***********************************************************************************/


/***********************************************************************************************************

	ALG  x 1 x 1  =    8  :  algorithm

	OP   x 1 x 4  =    1  :  operator mask
	NS   x 1 x 4  =    1  :  note scaling
	NE   x 1 x 4  =    1  :  noise enabled
	AME  x 1 x 4  =    1  :  ams enabled

	TL   x 3 x 4  =  255  :  total level
	AR   x 3 x 4  =   71  :  attack rate
	D1R  x 3 x 4  =   71  :  first decay rate
	D1L  x 3 x 4  =   63  :  first decay level
	D2R  x 3 x 4  =   71  :  second decay rate
	RR   x 3 x 4  =   71  :  release rate

	OWF  x 1 x 4  =    4  :  operator wave form
	MUL  x 3 x 4  =   15  :  phase multiply
	KC   x 3 x 4  =  119  :  key note
	KF   x 3 x 4  =   63  :  key fraction
	FB   x 3 x 4  =  255  :  self feedback level
	NFQ  x 3 x 4  =  255  :  noise frequency

	LWF  x 1 x 4  =    4  :  lfo wave form
	FRQ  x 3 x 4  =  255  :  lfo frequency
	AMD  x 3 x 4  =  255  :  amplitude modulation depth
	AMS  x 3 x 4  =  255  :  amplitude modulation sensitivity
	PMD  x 3 x 4  =  255  :  phase modulation depth
	PMS  x 3 x 4  =  255  :  phase modulation sensitivity

*********************************************************************************************************/


/* ymx signal constant variable declarations ************************************************************/



// limits


const s32 __s32_YMX_limit_alg__ =   8;

const s32 __s32_YMX_limit_op__  =   1;
const s32 __s32_YMX_limit_ns__  =   1;
const s32 __s32_YMX_limit_ne__  =   1;
const s32 __s32_YMX_limit_ame__ =   1;

const s32 __s32_YMX_limit_tl__  = 255;
const s32 __s32_YMX_limit_ar__  =  71;
const s32 __s32_YMX_limit_d1r__ =  71;
const s32 __s32_YMX_limit_d1l__ =  63;
const s32 __s32_YMX_limit_d2r__ =  71;
const s32 __s32_YMX_limit_rr__  =  71;

const s32 __s32_YMX_limit_owf__ =   3;
const s32 __s32_YMX_limit_mul__ =  15;
const s32 __s32_YMX_limit_kc__  = 119;
const s32 __s32_YMX_limit_kf__  =  63;
const s32 __s32_YMX_limit_fb__  = 255;
const s32 __s32_YMX_limit_nfq__ = 255;

const s32 __s32_YMX_limit_lwf__ =   4;
const s32 __s32_YMX_limit_frq__ = 255;
const s32 __s32_YMX_limit_amd__ = 255;
const s32 __s32_YMX_limit_ams__ = 255;
const s32 __s32_YMX_limit_pmd__ = 255;
const s32 __s32_YMX_limit_pms__ = 255;

// safety ranges


const s32 __s32_YMX_safety_tl__ [2] = { 192, 255 }; // 255
const s32 __s32_YMX_safety_ar__ [2] = {   0,  40 }; //  71
const s32 __s32_YMX_safety_d1r__[2] = {   8,  71 }; //  71
const s32 __s32_YMX_safety_d1l__[2] = {   8,  63 }; //  63
const s32 __s32_YMX_safety_d2r__[2] = {   8,  71 }; //  71
const s32 __s32_YMX_safety_rr__ [2] = {   0,  48 }; //  71

const s32 __s32_YMX_safety_mul__[2] = {   1,   5 }; //  15
const s32 __s32_YMX_safety_kc__ [2] = {  12,  48 }; // 119
const s32 __s32_YMX_safety_kf__ [2] = {   0,  63 }; //  63
const s32 __s32_YMX_safety_fb__ [2] = {   0, 224 }; // 255
const s32 __s32_YMX_safety_nfq__[2] = {   0, 255 }; // 255

const s32 __s32_YMX_safety_frq__[2] = { 128, 240 }; // 255
const s32 __s32_YMX_safety_amd__[2] = {   0, 240 }; // 255
const s32 __s32_YMX_safety_ams__[2] = {   0, 240 }; // 255
const s32 __s32_YMX_safety_pmd__[2] = {   0, 240 }; // 255
const s32 __s32_YMX_safety_pms__[2] = {   0, 240 }; // 255



/* ymx command constant variable declarations ***********************************************************/



enum enum_command
{
	cmnd_null,

	cmnd_key_on,
	cmnd_key_off,

	cmnd_note_one,
	cmnd_note_all,

	cmnd_alg,

	cmnd_op,
	cmnd_ns,
	cmnd_ne,
	cmnd_ame,

	cmnd_tl,
	cmnd_ar,
	cmnd_d1r,
	cmnd_d1l,
	cmnd_d2r,
	cmnd_rr,

	cmnd_owf,
	cmnd_mul,
	cmnd_kc,
	cmnd_kf,
	cmnd_fb,
	cmnd_nfq,

	cmnd_lwf,
	cmnd_frq,
	cmnd_amd,
	cmnd_ams,
	cmnd_pmd,
	cmnd_pms,

	cmnd_lfo_reset,
	cmnd_lfo_start
};



/* ymx signal macro definitions *************************************************************************/



// limits


#define YMX_LIMIT_ALG ymx::__s32_YMX_limit_alg__

#define YMX_LIMIT_OP  ymx::__s32_YMX_limit_op__
#define YMX_LIMIT_NS  ymx::__s32_YMX_limit_ns__
#define YMX_LIMIT_NE  ymx::__s32_YMX_limit_ne__
#define YMX_LIMIT_AME ymx::__s32_YMX_limit_ame__

#define YMX_LIMIT_TL  ymx::__s32_YMX_limit_tl__
#define YMX_LIMIT_AR  ymx::__s32_YMX_limit_ar__
#define YMX_LIMIT_D1R ymx::__s32_YMX_limit_d1r__
#define YMX_LIMIT_D1L ymx::__s32_YMX_limit_d1l__
#define YMX_LIMIT_D2R ymx::__s32_YMX_limit_d2r__
#define YMX_LIMIT_RR  ymx::__s32_YMX_limit_rr__

#define YMX_LIMIT_OWF ymx::__s32_YMX_limit_owf__
#define YMX_LIMIT_MUL ymx::__s32_YMX_limit_mul__
#define YMX_LIMIT_KC  ymx::__s32_YMX_limit_kc__
#define YMX_LIMIT_KF  ymx::__s32_YMX_limit_kf__
#define YMX_LIMIT_FB  ymx::__s32_YMX_limit_fb__
#define YMX_LIMIT_NFQ ymx::__s32_YMX_limit_nfq__

#define YMX_LIMIT_LWF ymx::__s32_YMX_limit_lwf__
#define YMX_LIMIT_FRQ ymx::__s32_YMX_limit_frq__
#define YMX_LIMIT_AMD ymx::__s32_YMX_limit_amd__
#define YMX_LIMIT_AMS ymx::__s32_YMX_limit_ams__
#define YMX_LIMIT_PMD ymx::__s32_YMX_limit_pmd__
#define YMX_LIMIT_PMS ymx::__s32_YMX_limit_pms__

// safety ranges


#define YMX1TL  ymx::__s32_YMX_safety_tl__ [0]
#define YMX1AR  ymx::__s32_YMX_safety_ar__ [0]
#define YMX1D1R ymx::__s32_YMX_safety_d1r__[0]
#define YMX1D1L ymx::__s32_YMX_safety_d1l__[0]
#define YMX1D2R ymx::__s32_YMX_safety_d2r__[0]
#define YMX1RR  ymx::__s32_YMX_safety_rr__ [0]

#define YMX1MUL ymx::__s32_YMX_safety_mul__[0]
#define YMX1KC  ymx::__s32_YMX_safety_kc__ [0]
#define YMX1KF  ymx::__s32_YMX_safety_kf__ [0]
#define YMX1FB  ymx::__s32_YMX_safety_fb__ [0]
#define YMX1NFQ ymx::__s32_YMX_safety_nfq__[0]

#define YMX1FRQ ymx::__s32_YMX_safety_frq__[0]
#define YMX1AMD ymx::__s32_YMX_safety_amd__[0]
#define YMX1AMS ymx::__s32_YMX_safety_ams__[0]
#define YMX1PMD ymx::__s32_YMX_safety_pmd__[0]
#define YMX1PMS ymx::__s32_YMX_safety_pms__[0]

#define YMX2TL  ymx::__s32_YMX_safety_tl__ [1]
#define YMX2AR  ymx::__s32_YMX_safety_ar__ [1]
#define YMX2D1R ymx::__s32_YMX_safety_d1r__[1]
#define YMX2D1L ymx::__s32_YMX_safety_d1l__[1]
#define YMX2D2R ymx::__s32_YMX_safety_d2r__[1]
#define YMX2RR  ymx::__s32_YMX_safety_rr__ [1]

#define YMX2MUL ymx::__s32_YMX_safety_mul__[1]
#define YMX2KC  ymx::__s32_YMX_safety_kc__ [1]
#define YMX2KF  ymx::__s32_YMX_safety_kf__ [1]
#define YMX2FB  ymx::__s32_YMX_safety_fb__ [1]
#define YMX2NFQ ymx::__s32_YMX_safety_nfq__[1]

#define YMX2FRQ ymx::__s32_YMX_safety_frq__[1]
#define YMX2AMD ymx::__s32_YMX_safety_amd__[1]
#define YMX2AMS ymx::__s32_YMX_safety_ams__[1]
#define YMX2PMD ymx::__s32_YMX_safety_pmd__[1]
#define YMX2PMS ymx::__s32_YMX_safety_pms__[1]



/* ymx command macro definitions ************************************************************************/



#define YMX_CMND_NULL        ymx::enum_command::cmnd_null

#define YMX_CMND_KEY_ON      ymx::enum_command::cmnd_key_on
#define YMX_CMND_KEY_OFF     ymx::enum_command::cmnd_key_off

#define YMX_CMND_NOTE_ONE    ymx::enum_command::cmnd_note_one
#define YMX_CMND_NOTE_ALL    ymx::enum_command::cmnd_note_all

#define YMX_CMND_ALG         ymx::enum_command::cmnd_alg

#define YMX_CMND_OP          ymx::enum_command::cmnd_op
#define YMX_CMND_NS          ymx::enum_command::cmnd_ns
#define YMX_CMND_NE          ymx::enum_command::cmnd_ne
#define YMX_CMND_AME         ymx::enum_command::cmnd_ame

#define YMX_CMND_TL          ymx::enum_command::cmnd_tl
#define YMX_CMND_AR          ymx::enum_command::cmnd_ar
#define YMX_CMND_D1R         ymx::enum_command::cmnd_d1r
#define YMX_CMND_D1L         ymx::enum_command::cmnd_d1l
#define YMX_CMND_D2R         ymx::enum_command::cmnd_d2r
#define YMX_CMND_RR          ymx::enum_command::cmnd_rr

#define YMX_CMND_OWF         ymx::enum_command::cmnd_owf
#define YMX_CMND_MUL         ymx::enum_command::cmnd_mul
#define YMX_CMND_KC          ymx::enum_command::cmnd_kc
#define YMX_CMND_KF          ymx::enum_command::cmnd_kf
#define YMX_CMND_FB          ymx::enum_command::cmnd_fb
#define YMX_CMND_NFQ         ymx::enum_command::cmnd_nfq

#define YMX_CMND_LWF         ymx::enum_command::cmnd_lwf
#define YMX_CMND_FRQ         ymx::enum_command::cmnd_frq
#define YMX_CMND_AMD         ymx::enum_command::cmnd_amd
#define YMX_CMND_AMS         ymx::enum_command::cmnd_ams
#define YMX_CMND_PMD         ymx::enum_command::cmnd_pmd
#define YMX_CMND_PMS         ymx::enum_command::cmnd_pms

#define YMX_CMND_LFO_RESET   ymx::enum_command::cmnd_lfo_reset
#define YMX_CMND_LFO_START   ymx::enum_command::cmnd_lfo_start



/* ymx core function macro definitions 1 ****************************************************************/



// ymx limit function declaration macro

#define YMX_LIMIT_FUNC_DECL(AA)\
s32 __limit_##AA( s32 )\

// ymx limit function implementation macro

#define YMX_LIMIT_FUNC_IMPL(AA)\
s32 __limit_##AA( s32 v )\
{\
	if( v < 0 )\
		return 0;\
	else if( v > __s32_YMX_limit_##AA##__ )\
		return __s32_YMX_limit_##AA##__;\
	else\
		return v;\
}



/* ymx core function declarations 1 *********************************************************************/



YMX_LIMIT_FUNC_DECL( alg );

YMX_LIMIT_FUNC_DECL( op  );
YMX_LIMIT_FUNC_DECL( ns  );
YMX_LIMIT_FUNC_DECL( ne  );
YMX_LIMIT_FUNC_DECL( ame );

YMX_LIMIT_FUNC_DECL( tl  );
YMX_LIMIT_FUNC_DECL( ar  );
YMX_LIMIT_FUNC_DECL( d1r );
YMX_LIMIT_FUNC_DECL( d1l );
YMX_LIMIT_FUNC_DECL( d2r );
YMX_LIMIT_FUNC_DECL( rr  );

YMX_LIMIT_FUNC_DECL( owf );
YMX_LIMIT_FUNC_DECL( mul );
YMX_LIMIT_FUNC_DECL( kc  );
YMX_LIMIT_FUNC_DECL( kf  );
YMX_LIMIT_FUNC_DECL( fb  );
YMX_LIMIT_FUNC_DECL( nfq );

YMX_LIMIT_FUNC_DECL( lwf );
YMX_LIMIT_FUNC_DECL( frq );
YMX_LIMIT_FUNC_DECL( amd );
YMX_LIMIT_FUNC_DECL( ams );
YMX_LIMIT_FUNC_DECL( pmd );
YMX_LIMIT_FUNC_DECL( pms );

#undef YMX_LIMIT_FUNC_DECL




/* ymx core function macro definitions 2 ****************************************************************/



// ymx limit function quick macros

#define YMX_ALG(AA) ymx::__limit_alg (AA)

#define YMX_OP(AA)  ymx::__limit_op  (AA)
#define YMX_NS(AA)  ymx::__limit_ns  (AA)
#define YMX_NE(AA)  ymx::__limit_ne  (AA)
#define YMX_AME(AA) ymx::__limit_ame (AA)

#define YMX_TL(AA)  ymx::__limit_tl  (AA)
#define YMX_AR(AA)  ymx::__limit_ar  (AA)
#define YMX_D1R(AA) ymx::__limit_d1r (AA)
#define YMX_D1L(AA) ymx::__limit_d1l (AA)
#define YMX_D2R(AA) ymx::__limit_d2r (AA)
#define YMX_RR(AA)  ymx::__limit_rr  (AA)

#define YMX_OWF(AA) ymx::__limit_owf (AA)
#define YMX_MUL(AA) ymx::__limit_mul (AA)
#define YMX_KC(AA)  ymx::__limit_kc  (AA)
#define YMX_KF(AA)  ymx::__limit_kf  (AA)
#define YMX_FB(AA)  ymx::__limit_fb  (AA)
#define YMX_NFQ(AA) ymx::__limit_nfq (AA)

#define YMX_LWF(AA) ymx::__limit_lwf (AA)
#define YMX_FRQ(AA) ymx::__limit_frq (AA)
#define YMX_AMD(AA) ymx::__limit_amd (AA)
#define YMX_AMS(AA) ymx::__limit_ams (AA)
#define YMX_PMD(AA) ymx::__limit_pmd (AA)
#define YMX_PMS(AA) ymx::__limit_pms (AA)



/* ymx extern declarations ******************************************************************************/



extern s32 __s32_YMX_step_table_1__[8448];
extern s32 __s32_YMX_step_table_2__[ 768];

extern s32 __s32_YMX_alpha_table__[4097];

extern s32 __s32_YMX_waveform_table__[3][4][1024];

extern s32 __s32_YMX_state_value_and__[180];
extern s32 __s32_YMX_state_value_pls__[180];



extern s32 __s32_YMX_xr_next_state__ [ 6];
extern s32 __s32_YMX_xr_max_state__  [ 6];
extern s32 __s32_YMX_key_code_table__[12];



/* ymx core function declarations 2 *********************************************************************/



result init_ymx_alpha    ();
result init_ymx_sine     ();
result init_ymx_triangle ();
result init_ymx_saw      ();
result init_ymx_square   ();
result init_ymx_step     ();
result init_ymx_all      ();

u32 YMX_generate ();



/* end */
}}
#endif
