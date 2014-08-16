
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_TERMINAL_HANDLER_CORE_CPP
#define BDAPI_TERMINAL_HANDLER_CORE_CPP
#define BD_DATA_TERMINAL
#include "terminal/handler.hpp"

/* includes */

// bdapi
#include "core/platform.hpp"
#include "error/handler.hpp"
#include "string/core.hpp"

/* namespaces */
namespace bdapi    {
namespace terminal {

/* terminal handler singleton core function implementations */

// scroll
void scroll()
{
	scroll(1);
}
void scroll( s32 amount )
{
	curses::scrollok( curses::stdscr, true );

	curses::scrl( amount );

	curses::scrollok( curses::stdscr, scrolling );
}

// set automatic
void set_automatic( bl automatic )
{
	terminal::automatic = automatic;
}

// set scrolling
void set_scrolling( bl scrolling )
{
	terminal::scrolling = scrolling;

	curses::scrollok( curses::stdscr, scrolling );
}

// clear
void clear()
{
	curses::clear();
}

// refresh
void refresh()
{
	curses::refresh();
}

// set color
void set_color()
{
	set_color( 0, 7 );
}
void set_color( s32 foreground )
{
	set_color( background_color, foreground );
}
void set_color( s32 background, s32 foreground )
{
	background_color = background % 16;
	foreground_color = foreground % 16;

	curses::attrset( chtype_color_pairs[ foreground_color ][ background_color ] );
}

// move
void move()
{
	if( cursor_x < 0 )
	{
		cursor_x = width  + cursor_x;
	}

	if( cursor_y < 0 )
	{
		cursor_y = height + cursor_y;
	}

	curses::move( cursor_y, cursor_x );
}
void move( s32 x, s32 y )
{
	cursor_x = x;
	cursor_y = y;

	move();
}

// shift x
void shift_x( s32 x )
{
	cursor_x += x;

	move();
}

// shift y
void shift_y( s32 y )
{
	cursor_y += y;

	move();
}

// shift
void shift( s32 x, s32 y )
{
	cursor_x += x;
	cursor_y += y;

	move();
}

// draw
void draw( s32 c )
{
	move();

	curses::addrawch(c);
}
void draw( s32 x, s32 y, s32 c )
{
	move( x, y );

	curses::addrawch(c);
}
void draw( s32 x, s32 y, s32 b, s32 f, s32 c )
{
	set_color( b, f );

	draw( x, y, c );
}

// write
void write( cstr input, ... )
{
	STR_FORMAT;

	scroll(1);

	write( 0, height - 1, input );
}
void write( s32 x, s32 y, cstr input, ... )
{
	STR_FORMAT;

	s32 size = strlen(input);

	move( x, y );

	set_color();

	fori( size )
	{
		if( input[i] == '~' )
		{
			if( ( input[i+1] == 'B' || input[i+1] == 'F' )
			&& isxdigit( input[i+2] ) )
			{
				if(      input[i+1] == 'B' )
				{
					background_color = str::hex_2_dec( input, i+2, 1 );
				}
				else if( input[i+1] == 'F' )
				{
					foreground_color = str::hex_2_dec( input, i+2, 1 );
				}

				set_color( background_color, foreground_color );

				i += 2;
			}
			else
			if( ( input[i+1] == 'C' || input[i+1] == 'X' )
			&& isxdigit( input[i+2] ) && isxdigit( input[i+3] ) )
			{
				if( input[i+1] == 'C' )
				{
					draw( str::hex_2_dec( input, i+2, 2 ) );

					shift_x(1);
				}
				else if( input[i+1] == 'X' )
				{
					background_color = str::hex_2_dec( input, i+2, 1 );
					foreground_color = str::hex_2_dec( input, i+3, 1 );

					set_color( background_color, foreground_color );
				}

				i += 3;
			}
			else
			{
				draw( input[i] );

				shift_x(1);
			}
		}
		else
		{
			draw( input[i] );

			shift_x(1);
		}
	}

	set_color();
}

/* end */

}
}

#endif