
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_TERMINAL_HANDLER_INIT_CPP
#define BDAPI_TERMINAL_HANDLER_INIT_CPP
#define BD_DATA_TERMINAL
#include "terminal/handler.hpp"

/* includes */

// bdapi
#include "core/platform.hpp"
#include "error/handler.hpp"
#include "logging/message.hpp"
#include "sys/handler.hpp"

/* namespaces */
namespace bdapi    {
namespace terminal {

/* static variables */

static bool handler_instance = false;

/* terminal handler singleton initialization function implementations */

// private initializers
result initialize( parameters* handler_parameters )
{
	LOG_ERROR_1( "~F6subsystem", "~~ has already been initialized", !handler_instance );

	handler_instance = true;

	LOG_ERROR_1( "~F6subsystem parameters", "failed to read ~~", handler_parameters );

	terminal::handler_parameters = handler_parameters;

	subsystem_state = SUBSYS_INITIALIZED;

	LOG_ERROR_1(
		"~FEterminal ~F6handle",
		"failed to create ~~",
		init_handle() );

	LOG_ERROR_1(
		"~FEterminal ~F6parameters",
		"failed to read ~~",
		init_params() );

	LOG_ERROR_1(
		"~FEterminal ~F6color",
		"failed to initialize ~~",
		init_color() );

	LOG_ERROR_1(
		"~FEterminal ~F6title",
		"failed to assign ~~",
		init_title() );

	subsystem_state = SUBSYS_ACTIVE;

	return 1;
}

// private shutdown
result shutdown()
{
	subsystem_state = SUBSYS_SUSPENDED;

	frame_finish();

	scroll();

	write( "~F8Press any key to continue ..." );

	scroll();

	refresh();

	if( USING_ERROR && !ERROR_EXISTS )
	{
		using namespace curses;

		curses::nodelay( curses::stdscr, false );

		curses::getch();
	}

	fori(16)
	{
		delete[] chtype_color_pairs[i];
	}

	delete[] chtype_color_pairs;

	subsystem_state = SUBSYS_SHUTDOWN;

	return 1;
}

// private initialize terminal handle
result init_handle()
{
	#if WIN

	if( !AllocConsole() )
	{
		return 0;
	}

	#elif MAC
	#warning "Macintosh terminal initialization function unspecified."
	#elif NIX
	#warning "Unix terminal initialization function unspecified."
	#elif PS4
	#warning "PlayStation 4 terminal initialization function unspecified."
	#elif XBO
	#warning "Xbox One terminal initialization function unspecified."
	#elif WII
	#warning "Wii terminal initialization function unspecified."
	#endif

	curses::initscr();
	curses::curs_set(0);
	curses::nocbreak();
	curses::noecho();
	curses::nonl();
	curses::raw();

	curses::immedok ( curses::stdscr, false );
	curses::keypad  ( curses::stdscr, true  );
	curses::scrollok( curses::stdscr, false );
	curses::syncok  ( curses::stdscr, false );
	curses::nodelay ( curses::stdscr, true  );

	set_automatic( handler_parameters->automatic );
	set_scrolling( handler_parameters->scrolling );

	return 1;
}

// private initialize terminal parameters
result init_params()
{
	width  = handler_parameters->width;
	height = handler_parameters->height;

	if( width > 0 && height > 0 )
	{
		curses::resize_term( height, width );
	}

	width  = curses::COLS;
	height = curses::LINES;

	curses::mouse_on( ALL_MOUSE_EVENTS );
	curses::mouseinterval(0);

	move( 0, -1 );

	return 1;
}

// private initialize terminal color
result init_color()
{
	curses::start_color();
	curses::assume_default_colors( 7, 0 );

	chtype_color_pairs = new curses::chtype*[16]();

	fori(16)
	{
		chtype_color_pairs[i] = new curses::chtype[16]();
	}

	s32 b = 0;
	s32 f = 0;
	s32 q = 1;
	s32 x = 0;
	s32 y = 0;

	fory(16)
	{
		forx(16)
		{
			if( f > 7 )
			{
				if( b > 7 )
				{
					curses::init_pair( q, f - 8, b - 8 );

					using namespace curses;

					chtype_color_pairs[x][y] = COLOR_PAIR(q) | A_BOLD | A_BLINK;
				}
				else
				{
					curses::init_pair( q, f - 8, b );

					using namespace curses;

					chtype_color_pairs[x][y] = COLOR_PAIR(q) | A_BOLD;
				}
			}
			else
			{
				if( b > 7 )
				{
					curses::init_pair( q, f, b - 8 );

					using namespace curses;

					chtype_color_pairs[x][y] = COLOR_PAIR(q) | A_BLINK;
				}
				else
				{
					curses::init_pair( q, f, b );

					using namespace curses;

					chtype_color_pairs[x][y] = COLOR_PAIR(q);
				}
			}

			q++;
			f++;

			if( f > 15 )
			{
				f = 0;
			}
		}

		b++;

		if( b > 15 )
		{
			b = 0;
		}
	}

	return 1;
}

// private initialize terminal title
result init_title()
{
	#if WIN

	curses::PDC_set_title( sys::get_game_full_title().c_str() );

	#elif MAC
	#warning "Macintosh terminal title function unspecified."
	#elif NIX
	#warning "Unix terminal title function unspecified."
	#elif PS4
	#warning "PlayStation 4 terminal title function unspecified."
	#elif XBO
	#warning "Xbox One terminal title function unspecified."
	#elif WII
	#warning "Wii terminal title function unspecified."
	#endif

	return 1;
}

/* end */

}
}

#endif
