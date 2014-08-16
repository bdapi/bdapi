
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_SECTION_HPP
#define BDAPI_YMX_SECTION_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "deque"

// bdapi
#include "util/container.hpp"
#include "io/file.hpp"
#include "ymx/ymx_command.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx section class declaration ************************************************************************/



class section
{

private:

	private_data( s32, s32_channels, get_channels );
	private_data( s32, s32_blocks,   get_blocks   );

	util::container< util::container< block, std::deque >, std::deque > container_blocks;

private:

	void __nullify ();

public:

	section (                );
	section ( s32, s32       );
	section ( io::file&    );
	section ( const section& );
 ~section (                );

	result initialize ( s32, s32       );
	result initialize ( io::file&    );
	result initialize ( const section& );
	result discard    (                );

	void load ( io::file& );
	void save ( io::file& );

	block& clear_block   ( s32, s32 );
	void   clear_channel ( s32      );
	void   clear_all     (          );

	block& get_block ( s32, s32 );

	block& set_command ( s32, s32, s32, s32, s32 );
	block& set_command ( s32, const command&     );

	block& set_command_null        ( s32,      s32      );

	block& set_command_key_on      ( s32,      s32      );
	block& set_command_key_off     ( s32,      s32      );

	block& set_command_note_one    ( s32, s32, s32, s32 );
	block& set_command_note_all    ( s32, s32, s32      );

	block& set_command_alg         ( s32, s32, s32      );

	block& set_command_op          ( s32, s32, s32, s32 );
	block& set_command_ns          ( s32, s32, s32, s32 );
	block& set_command_ne          ( s32, s32, s32, s32 );
	block& set_command_ame         ( s32, s32, s32, s32 );

	block& set_command_tl          ( s32, s32, s32, s32 );
	block& set_command_ar          ( s32, s32, s32, s32 );
	block& set_command_d1r         ( s32, s32, s32, s32 );
	block& set_command_d1l         ( s32, s32, s32, s32 );
	block& set_command_d2r         ( s32, s32, s32, s32 );
	block& set_command_rr          ( s32, s32, s32, s32 );

	block& set_command_owf         ( s32, s32, s32, s32 );
	block& set_command_mul         ( s32, s32, s32, s32 );
	block& set_command_kc          ( s32, s32, s32, s32 );
	block& set_command_kf          ( s32, s32, s32, s32 );
	block& set_command_fb          ( s32, s32, s32, s32 );
	block& set_command_nfq         ( s32, s32, s32, s32 );

	block& set_command_lwf         ( s32, s32, s32, s32 );
	block& set_command_frq         ( s32, s32, s32, s32 );
	block& set_command_amd         ( s32, s32, s32, s32 );
	block& set_command_ams         ( s32, s32, s32, s32 );
	block& set_command_pmd         ( s32, s32, s32, s32 );
	block& set_command_pms         ( s32, s32, s32, s32 );

	block& set_command_lfo_reset   ( s32,      s32, s32 );
	block& set_command_lfo_start   ( s32,      s32, s32 );

};



/* end */
}}
#endif
