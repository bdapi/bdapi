
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_YMX_COMMAND_HPP
#define BDAPI_YMX_COMMAND_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "deque"

// bdapi
#include "util/container.hpp"
#include "io/file.hpp"

// namespaces
namespace bdapi {
namespace ymx   {



/* ymx command class declaration ************************************************************************/



class command
{

public:

	s32 commands[4];

public:

	command (                    );
	command ( s32, s32, s32, s32 );
	command ( u8*                );
	command ( const command&     );
 ~command () {};

	void load ( io::file& );
	void save ( io::file& );

	      s32& operator [] ( s32 );
	const s32& operator [] ( s32 ) const;

	bl operator == ( const command& ) const;
	bl operator != ( const command& ) const;

	bl operator == ( s32 ) const;
	bl operator != ( s32 ) const;

	command& clear ();

	command& set_command ( s32, s32, s32, s32 );
	command& set_command ( u8*                );
	command& set_command ( const command&     );

	command& set_command_null        (               );

	command& set_command_key_on      (      s32      );
	command& set_command_key_off     (      s32      );

	command& set_command_note_one    ( s32, s32, s32 );
	command& set_command_note_all    ( s32, s32      );

	command& set_command_alg         ( s32, s32      );

	command& set_command_op          ( s32, s32, s32 );
	command& set_command_ns          ( s32, s32, s32 );
	command& set_command_ne          ( s32, s32, s32 );
	command& set_command_ame         ( s32, s32, s32 );

	command& set_command_tl          ( s32, s32, s32 );
	command& set_command_ar          ( s32, s32, s32 );
	command& set_command_d1r         ( s32, s32, s32 );
	command& set_command_d1l         ( s32, s32, s32 );
	command& set_command_d2r         ( s32, s32, s32 );
	command& set_command_rr          ( s32, s32, s32 );

	command& set_command_owf         ( s32, s32, s32 );
	command& set_command_mul         ( s32, s32, s32 );
	command& set_command_kc          ( s32, s32, s32 );
	command& set_command_kf          ( s32, s32, s32 );
	command& set_command_fb          ( s32, s32, s32 );
	command& set_command_nfq         ( s32, s32, s32 );

	command& set_command_lwf         ( s32, s32, s32 );
	command& set_command_frq         ( s32, s32, s32 );
	command& set_command_amd         ( s32, s32, s32 );
	command& set_command_ams         ( s32, s32, s32 );
	command& set_command_pmd         ( s32, s32, s32 );
	command& set_command_pms         ( s32, s32, s32 );

	command& set_command_lfo_reset   (      s32, s32 );
	command& set_command_lfo_start   (      s32, s32 );

	s32 get_parameter ( s32 ) const;
	s32 get_function  (     ) const;
	s32 get_value     (     ) const;
	s32 get_channel   (     ) const;
	s32 get_operator  (     ) const;

};



/* ymx block typedef declaration ************************************************************************/



typedef util::container< command, std::deque > block;



/* end */
}}
#endif












