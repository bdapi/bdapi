
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_SIGNAL_HPP
#define BDAPI_YMX_SIGNAL_HPP
#include "bdapi.hpp"

/* includes */

// bdapi
#include "io/file.hpp"
#include "core/string.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx signal class declaration *************************************************************************/



class signal
{

public:

	s32 alg;

	s32 op     [4];
	s32 ns     [4];
	s32 ne     [4];
	s32 ame    [4];

	s32 tl  [3][4];
	s32 ar  [3][4];
	s32 d1r [3][4];
	s32 d1l [3][4];
	s32 d2r [3][4];
	s32 rr  [3][4];

	s32 owf    [4];
	s32 mul [3][4];
	s32 kc  [3][4];
	s32 kf  [3][4];
	s32 fb  [3][4];
	s32 nfq [3][4];

	s32 lwf    [4];
	s32 frq [3][4];
	s32 amd [3][4];
	s32 ams [3][4];
	s32 pmd [3][4];
	s32 pms [3][4];

private:

	private_data( gen::rng*, rng_sig, get_generator );

public: // ymx_signal_init.cpp -----------------------------------------------------------------------------

	signal (                          );
	signal ( gen::rng*                );
	signal (            string        );
	signal ( gen::rng*, string        );
	signal (            const signal& );
	signal ( gen::rng*, const signal& );
 ~signal () {};

	result load (            io::file& );
	result load ( gen::rng*, io::file& );
	result load (            string      );
	result load ( gen::rng*, string      );

	result set_generator ( gen::rng* );

	result save ( io::file& );
	result save ( string      );

public: // ymx_signal_core.cpp -----------------------------------------------------------------------------

	signal& reset (         );
	signal& reset (      bl );
	signal& reset ( s32, bl );

	signal& check (     );
	signal& check ( s32 );

	bl operator == ( const signal& ) const;
	bl operator != ( const signal& ) const;

private:

	s32& chk_C  ( s32&       );
	s32& chk_O  (       s32& );
	void chk_CO ( s32&, s32& );

	s32 chk_R ( s32 );

	s32 rnd (          );
	s32 rnd (      s32 );
	s32 rnd ( s32, s32 );

	s32 rnd_X ( s32      );
	s32 rnd_Y ( s32, s32 );

public: // ymx_signal_mod.cpp ------------------------------------------------------------------------------

	s32 shift_alg (      s32 );
	s32 shift_op  ( s32, s32 );
	s32 shift_ns  ( s32, s32 );
	s32 shift_ne  ( s32, s32 );
	s32 shift_ame ( s32, s32 );
	s32 shift_tl  ( s32, s32 );
	s32 shift_ar  ( s32, s32 );
	s32 shift_d1r ( s32, s32 );
	s32 shift_d1l ( s32, s32 );
	s32 shift_d2r ( s32, s32 );
	s32 shift_rr  ( s32, s32 );
	s32 shift_owf ( s32, s32 );
	s32 shift_mul ( s32, s32 );
	s32 shift_kc  ( s32, s32 );
	s32 shift_kf  ( s32, s32 );
	s32 shift_fb  ( s32, s32 );
	s32 shift_nfq ( s32, s32 );
	s32 shift_lwf ( s32, s32 );
	s32 shift_frq ( s32, s32 );
	s32 shift_amd ( s32, s32 );
	s32 shift_ams ( s32, s32 );
	s32 shift_pmd ( s32, s32 );
	s32 shift_pms ( s32, s32 );

	s32 shift_tl  ( s32, s32, s32 );
	s32 shift_ar  ( s32, s32, s32 );
	s32 shift_d1r ( s32, s32, s32 );
	s32 shift_d1l ( s32, s32, s32 );
	s32 shift_d2r ( s32, s32, s32 );
	s32 shift_rr  ( s32, s32, s32 );
	s32 shift_mul ( s32, s32, s32 );
	s32 shift_kc  ( s32, s32, s32 );
	s32 shift_kf  ( s32, s32, s32 );
	s32 shift_fb  ( s32, s32, s32 );
	s32 shift_nfq ( s32, s32, s32 );
	s32 shift_frq ( s32, s32, s32 );
	s32 shift_amd ( s32, s32, s32 );
	s32 shift_ams ( s32, s32, s32 );
	s32 shift_pmd ( s32, s32, s32 );
	s32 shift_pms ( s32, s32, s32 );

public: // ymx_signal_gen.cpp ------------------------------------------------------------------------------

	s32 gen_alg (     );
	s32 gen_op  ( s32 );
	s32 gen_ns  ( s32 );
	s32 gen_ne  ( s32 );
	s32 gen_ame ( s32 );
	s32 gen_tl  ( s32 );
	s32 gen_ar  ( s32 );
	s32 gen_d1r ( s32 );
	s32 gen_d1l ( s32 );
	s32 gen_d2r ( s32 );
	s32 gen_rr  ( s32 );
	s32 gen_owf ( s32 );
	s32 gen_mul ( s32 );
	s32 gen_kc  ( s32 );
	s32 gen_kf  ( s32 );
	s32 gen_fb  ( s32 );
	s32 gen_nfq ( s32 );
	s32 gen_lwf ( s32 );
	s32 gen_frq ( s32 );
	s32 gen_amd ( s32 );
	s32 gen_ams ( s32 );
	s32 gen_pmd ( s32 );
	s32 gen_pms ( s32 );

	s32 gen_tl  ( s32, s32 );
	s32 gen_ar  ( s32, s32 );
	s32 gen_d1r ( s32, s32 );
	s32 gen_d1l ( s32, s32 );
	s32 gen_d2r ( s32, s32 );
	s32 gen_rr  ( s32, s32 );
	s32 gen_mul ( s32, s32 );
	s32 gen_kc  ( s32, s32 );
	s32 gen_kf  ( s32, s32 );
	s32 gen_fb  ( s32, s32 );
	s32 gen_nfq ( s32, s32 );
	s32 gen_frq ( s32, s32 );
	s32 gen_amd ( s32, s32 );
	s32 gen_ams ( s32, s32 );
	s32 gen_pmd ( s32, s32 );
	s32 gen_pms ( s32, s32 );

	s32 gen_alg (           s32 );
	s32 gen_op  (      s32, s32 );
	s32 gen_ns  (      s32, s32 );
	s32 gen_ne  (      s32, s32 );
	s32 gen_ame (      s32, s32 );
	s32 gen_tl  ( s32, s32, s32 );
	s32 gen_ar  ( s32, s32, s32 );
	s32 gen_d1r ( s32, s32, s32 );
	s32 gen_d1l ( s32, s32, s32 );
	s32 gen_d2r ( s32, s32, s32 );
	s32 gen_rr  ( s32, s32, s32 );
	s32 gen_owf (      s32, s32 );
	s32 gen_mul ( s32, s32, s32 );
	s32 gen_kc  ( s32, s32, s32 );
	s32 gen_kf  ( s32, s32, s32 );
	s32 gen_fb  ( s32, s32, s32 );
	s32 gen_nfq ( s32, s32, s32 );
	s32 gen_lwf (      s32, s32 );
	s32 gen_frq ( s32, s32, s32 );
	s32 gen_amd ( s32, s32, s32 );
	s32 gen_ams ( s32, s32, s32 );
	s32 gen_pmd ( s32, s32, s32 );
	s32 gen_pms ( s32, s32, s32 );

	s32 gen_alg (           s32, s32 );
	s32 gen_op  (      s32, s32, s32 );
	s32 gen_ns  (      s32, s32, s32 );
	s32 gen_ne  (      s32, s32, s32 );
	s32 gen_ame (      s32, s32, s32 );
	s32 gen_tl  ( s32, s32, s32, s32 );
	s32 gen_ar  ( s32, s32, s32, s32 );
	s32 gen_d1r ( s32, s32, s32, s32 );
	s32 gen_d1l ( s32, s32, s32, s32 );
	s32 gen_d2r ( s32, s32, s32, s32 );
	s32 gen_rr  ( s32, s32, s32, s32 );
	s32 gen_owf (      s32, s32, s32 );
	s32 gen_mul ( s32, s32, s32, s32 );
	s32 gen_kc  ( s32, s32, s32, s32 );
	s32 gen_kf  ( s32, s32, s32, s32 );
	s32 gen_fb  ( s32, s32, s32, s32 );
	s32 gen_nfq ( s32, s32, s32, s32 );
	s32 gen_lwf (      s32, s32, s32 );
	s32 gen_frq ( s32, s32, s32, s32 );
	s32 gen_amd ( s32, s32, s32, s32 );
	s32 gen_ams ( s32, s32, s32, s32 );
	s32 gen_pmd ( s32, s32, s32, s32 );
	s32 gen_pms ( s32, s32, s32, s32 );

	s32 shf_tl  ( s32 );
	s32 shf_ar  ( s32 );
	s32 shf_d1r ( s32 );
	s32 shf_d1l ( s32 );
	s32 shf_d2r ( s32 );
	s32 shf_rr  ( s32 );
	s32 shf_mul ( s32 );
	s32 shf_kc  ( s32 );
	s32 shf_kf  ( s32 );
	s32 shf_fb  ( s32 );
	s32 shf_nfq ( s32 );
	s32 shf_frq ( s32 );
	s32 shf_amd ( s32 );
	s32 shf_ams ( s32 );
	s32 shf_pmd ( s32 );
	s32 shf_pms ( s32 );

	s32 shf_alg (          );
	s32 shf_op  (      s32 );
	s32 shf_ns  (      s32 );
	s32 shf_ne  (      s32 );
	s32 shf_ame (      s32 );
	s32 shf_tl  ( s32, s32 );
	s32 shf_ar  ( s32, s32 );
	s32 shf_d1r ( s32, s32 );
	s32 shf_d1l ( s32, s32 );
	s32 shf_d2r ( s32, s32 );
	s32 shf_rr  ( s32, s32 );
	s32 shf_owf (      s32 );
	s32 shf_mul ( s32, s32 );
	s32 shf_kc  ( s32, s32 );
	s32 shf_kf  ( s32, s32 );
	s32 shf_fb  ( s32, s32 );
	s32 shf_nfq ( s32, s32 );
	s32 shf_lwf (      s32 );
	s32 shf_frq ( s32, s32 );
	s32 shf_amd ( s32, s32 );
	s32 shf_ams ( s32, s32 );
	s32 shf_pmd ( s32, s32 );
	s32 shf_pms ( s32, s32 );

	s32 safe_alg (     );
	s32 safe_op  ( s32 );
	s32 safe_ns  ( s32 );
	s32 safe_ne  ( s32 );
	s32 safe_ame ( s32 );
	s32 safe_tl  ( s32 );
	s32 safe_ar  ( s32 );
	s32 safe_d1r ( s32 );
	s32 safe_d1l ( s32 );
	s32 safe_d2r ( s32 );
	s32 safe_rr  ( s32 );
	s32 safe_owf ( s32 );
	s32 safe_mul ( s32 );
	s32 safe_kc  ( s32 );
	s32 safe_kf  ( s32 );
	s32 safe_fb  ( s32 );
	s32 safe_nfq ( s32 );
	s32 safe_lwf ( s32 );
	s32 safe_frq ( s32 );
	s32 safe_amd ( s32 );
	s32 safe_ams ( s32 );
	s32 safe_pmd ( s32 );
	s32 safe_pms ( s32 );

	s32 safe_tl  ( s32, s32 );
	s32 safe_ar  ( s32, s32 );
	s32 safe_d1r ( s32, s32 );
	s32 safe_d1l ( s32, s32 );
	s32 safe_d2r ( s32, s32 );
	s32 safe_rr  ( s32, s32 );
	s32 safe_mul ( s32, s32 );
	s32 safe_kc  ( s32, s32 );
	s32 safe_kf  ( s32, s32 );
	s32 safe_fb  ( s32, s32 );
	s32 safe_nfq ( s32, s32 );
	s32 safe_frq ( s32, s32 );
	s32 safe_amd ( s32, s32 );
	s32 safe_ams ( s32, s32 );
	s32 safe_pmd ( s32, s32 );
	s32 safe_pms ( s32, s32 );

	signal& gen_all (     );
	signal& gen_all ( s32 );

	signal& shf_all (     );
	signal& shf_all ( s32 );

	signal& safe_all (     );
	signal& safe_all ( s32 );

public: // ymx_signal_dis.cpp ------------------------------------------------------------------------------

	s32 dis_tl  ( s32 );
	s32 dis_ar  ( s32 );
	s32 dis_d1r ( s32 );
	s32 dis_d1l ( s32 );
	s32 dis_d2r ( s32 );
	s32 dis_rr  ( s32 );
	s32 dis_mul ( s32 );
	s32 dis_kc  ( s32 );
	s32 dis_kf  ( s32 );
	s32 dis_fb  ( s32 );
	s32 dis_nfq ( s32 );
	s32 dis_frq ( s32 );
	s32 dis_amd ( s32 );
	s32 dis_ams ( s32 );
	s32 dis_pmd ( s32 );
	s32 dis_pms ( s32 );

	s32 dis_tl  ( s32, bl );
	s32 dis_ar  ( s32, bl );
	s32 dis_d1r ( s32, bl );
	s32 dis_d1l ( s32, bl );
	s32 dis_d2r ( s32, bl );
	s32 dis_rr  ( s32, bl );
	s32 dis_mul ( s32, bl );
	s32 dis_kc  ( s32, bl );
	s32 dis_kf  ( s32, bl );
	s32 dis_fb  ( s32, bl );
	s32 dis_nfq ( s32, bl );
	s32 dis_frq ( s32, bl );
	s32 dis_amd ( s32, bl );
	s32 dis_ams ( s32, bl );
	s32 dis_pmd ( s32, bl );
	s32 dis_pms ( s32, bl );

	signal& dis_op  ( s32     );
	signal& dis_op  ( s32, bl );
	signal& dis_all (         );
	signal& dis_all (      bl );

public: // ymx_signal_chip.cpp -----------------------------------------------------------------------------

	void apply_key_on    ( chip*, s32           );
	void apply_key_off   ( chip*, s32           );

	void apply_note_one  ( chip*, s32, s32, s32 );
	void apply_note_all  ( chip*, s32,      s32 );

	void apply_alg ( chip*, s32      );
	void apply_op  ( chip*, s32, s32 );
	void apply_ne  ( chip*, s32, s32 );
	void apply_ns  ( chip*, s32, s32 );
	void apply_ame ( chip*, s32, s32 );
	void apply_tl  ( chip*, s32, s32 );
	void apply_ar  ( chip*, s32, s32 );
	void apply_d1r ( chip*, s32, s32 );
	void apply_d1l ( chip*, s32, s32 );
	void apply_d2r ( chip*, s32, s32 );
	void apply_rr  ( chip*, s32, s32 );
	void apply_owf ( chip*, s32, s32 );
	void apply_mul ( chip*, s32, s32 );
	void apply_kc  ( chip*, s32, s32 );
	void apply_kf  ( chip*, s32, s32 );
	void apply_fb  ( chip*, s32, s32 );
	void apply_nfq ( chip*, s32, s32 );
	void apply_lwf ( chip*, s32, s32 );
	void apply_frq ( chip*, s32, s32 );
	void apply_amd ( chip*, s32, s32 );
	void apply_ams ( chip*, s32, s32 );
	void apply_pmd ( chip*, s32, s32 );
	void apply_pms ( chip*, s32, s32 );

	void apply_lfo_reset ( chip*, s32, s32 );
	void apply_lfo_start ( chip*, s32, s32 );

	void apply_operator ( chip*, s32, s32 );
	void apply_all      ( chip*, s32      );

};



/* end */
}}
#endif
