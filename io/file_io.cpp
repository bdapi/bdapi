
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_IO_FILE_IO_CPP
#define BDAPI_IO_FILE_IO_CPP
#include "io/file.hpp"

/* includes */

// standard
#include "fstream"

// zlib
namespace zlib
{
#include <zlib.h>
}

// bdapi
#include "error/handler.hpp"
#include "gen/rng.hpp"
#include "string/core.hpp"

/* namespaces */
namespace bdapi {
namespace io    {

/* file class input/output function implementations */

// read
result file::read()
{
	return read( false );
}
result file::read( bl bdfile )
{
	reset_index();

	std::ifstream input;

	input.open( file_path().c_str(), std::ios::binary );

	if( !input.is_open() )
	{
		WRITE_ERROR( "File ~FE\"%s\" ~F7could not be opened for reading", file_path().c_str() );

		input.close();

		return 0;
	}

	input.seekg( 0, std::ios::end );

	u32 input_size = input.tellg();

	input.seekg( 0, std::ios::beg );

	if( file_path.get_size() != input_size || ( bdfile && input_size <= 16 ) )
	{
		WRITE_ERROR( corruption_error(0).c_str() );

		input.close();

		return 0;
	}

	u8* input_data = new u8[ input_size ];

	input.read( (char*)input_data, input_size );
	input.close();

	if( bdfile )
	{
		if( input_data[0] != 'B' || input_data[1] != 'D' )
		{
			WRITE_ERROR( corruption_error(1).c_str() );

			delete[] input_data;

			return 0;
		}

		if( ( !isdigit( input_data[2] ) && !isupper( input_data[2] ) )
		||  ( !isdigit( input_data[3] ) && !isupper( input_data[3] ) )
		||  ( !isdigit( input_data[4] ) && !isupper( input_data[4] ) ) )
		{
			WRITE_ERROR( corruption_error(2).c_str() );

			delete[] input_data;

			return 0;
		}

		string input_extension = file_path.get_extension();

		string input_extension_lower;

		fori(5)
		{
			input_extension_lower += tolower( input_data[i] );
		}

		if( input_extension != input_extension_lower )
		{
			WRITE_ERROR( corruption_error(3).c_str() );

			delete[] input_data;

			return 0;
		}

		u8* buffer_data = input_data + 16;
		u32 buffer_size = input_size - 16;

		if( !isdigit( input_data[5] ) || !isdigit( input_data[6] ) || !isdigit( input_data[7] ) )
		{
			WRITE_ERROR( corruption_error(4).c_str() );

			delete[] input_data;

			return 0;
		}

		if( input_data[14] != 251 || input_data[15] != 250 )
		{
			WRITE_ERROR( corruption_error(5).c_str() );

			delete[] input_data;

			return 0;
		}

		if( input_data[8] == 254 )
		{
			gen::rng decryption_rng( get_key() );

			fori( buffer_size )
			{
				buffer_data[i] -= decryption_rng.get<u8>() - i;
			}
		}
		else
		{
			WRITE_ERROR( corruption_error(6).c_str() );

			delete[] input_data;

			return 0;
		}

		if( input_data[9] == 253 )
		{
			zlib::uLongf expansion_size = 0;

			expansion_size += (u32)input_data[10] << 24;
			expansion_size += (u32)input_data[11] << 16;
			expansion_size += (u32)input_data[12] <<  8;
			expansion_size += (u32)input_data[13];

			u8* expansion_data = new u8[ expansion_size ];

			s32 expansion_result = zlib::uncompress( expansion_data, &expansion_size, buffer_data,
				buffer_size );

			if( expansion_result != Z_OK )
			{
				if( expansion_result == Z_MEM_ERROR )
				{
					WRITE_ERROR( "Deflation memory error" );
				}
				else if( expansion_result == Z_BUF_ERROR )
				{
					WRITE_ERROR( "Deflation buffer error" );
				}
				else if( expansion_result == Z_DATA_ERROR )
				{
					WRITE_ERROR( "Deflation input_data error" );
				}
				else
				{
					WRITE_ERROR( "Unknown deflation error" );
				}

				WRITE_ERROR( corruption_error(7).c_str() );

				delete[] input_data;
				delete[] expansion_data;

				return 0;
			}

			clear();

			fori( expansion_size )
			{
				in<u8>( expansion_data[i] );
			}

			delete[] input_data;
			delete[] expansion_data;

			reset_index();

			return 1;
		}
		else if( input_data[9] == 252 )
		{
			clear();

			fori( buffer_size )
			{
				in<u8>( buffer_data[i] );
			}

			delete[] input_data;

			reset_index();

			return 1;
		}
		else
		{
			WRITE_ERROR( corruption_error(8).c_str() );

			delete[] input_data;

			reset_index();

			return 0;
		}
	}
	else
	{
		clear();

		fori( input_size )
		{
			in<u8>( input_data[i] );
		}

		delete[] input_data;

		reset_index();

		return 1;
	}
}

// save
result file::save()
{
	return save(false);
}
result file::save( bl bdfile )
{
	reset_index();

	if(bdfile)
	{
		string extension = file_path.get_extension();

		if( extension.size() != 5 )
		{
			WRITE_ERROR( extension_error(0).c_str() );

			return 0;
		}

		if( extension[0] != 'b'
		||  extension[1] != 'd' )
		{
			WRITE_ERROR( extension_error(1).c_str() );

			return 0;
		}

		if( ( !isdigit( extension[2] ) && !islower( extension[2] ) )
		||  ( !isdigit( extension[3] ) && !islower( extension[3] ) )
		||  ( !isdigit( extension[4] ) && !islower( extension[4] ) ) )
		{
			WRITE_ERROR( extension_error(2).c_str() );

			return 0;
		}

		std::ofstream output;

		output.open( file_path().c_str(), std::ios::binary );

		if( !output.is_open() )
		{
			WRITE_ERROR( "File ~FE\"%s\" ~F7could not be opened for writing", file_path().c_str() );

			output.close();

			return 0;
		}

		u8* buffer_data = file_buffer.get_data();
		u32 buffer_size = file_buffer.get_size();

		fori(5)
		{
			output << (char)toupper( extension[i] );
		}

		string output_version = str::format( "%i%i%i", BDAPI_VERSION_MAJOR, BDAPI_VERSION_MINOR,
			BDAPI_VERSION_PATCH );

		fori(3)
		{
			output << output_version[i];
		}

		output << u8(254);

		u8* compression_data = new u8[ buffer_size * 2 ]();

		zlib::uLongf compression_size = buffer_size;

		s32 compression_result = zlib::compress2( compression_data, &compression_size, buffer_data,
			buffer_size, Z_BEST_COMPRESSION );

		if( compression_result == Z_OK && compression_size < buffer_size * 2 )
		{
			output << u8(253);

			output << u8(   buffer_size         >> 24 );
			output << u8( ( buffer_size <<  8 ) >> 24 );
			output << u8( ( buffer_size << 16 ) >> 24 );
			output << u8( ( buffer_size << 24 ) >> 24 );

			output << u8(251);
			output << u8(250);

			gen::rng encryption_rng( get_key() );

			fori( compression_size )
			{
				output << u8( compression_data[i] + ( encryption_rng.get<u8>() - i ) );
			}
		}
		else
		{
			output << u8(252);

			output << u8(   buffer_size         >> 24 );
			output << u8( ( buffer_size <<  8 ) >> 24 );
			output << u8( ( buffer_size << 16 ) >> 24 );
			output << u8( ( buffer_size << 24 ) >> 24 );

			output << u8(251);
			output << u8(250);

			gen::rng encryption_rng( get_key() );

			fori( buffer_size )
			{
				output << u8( buffer_data[i] + encryption_rng.get<u8>() - i );
			}
		}

		output.close();

		delete[] compression_data;

		reset_index();

		return 1;
	}
	else
	{
		std::ofstream output;

		output.open( file_path().c_str(), std::ios::binary );

		if( !output.is_open() )
		{
			WRITE_ERROR( "File ~FE\"%s\" ~F7could not be opened for writing", file_path().c_str() );

			output.close();

			return 0;
		}

		u8* buffer_data = file_buffer.get_data();
		u32 buffer_size = file_buffer.get_size();

		fori( buffer_size )
		{
			output << buffer_data[i];
		}

		output.close();

		reset_index();

		return 1;
	}
}

// private write corruption error
string file::corruption_error( s32 code )
{
	return str::format( "File ~FE\"%s\" ~F7is corrupt ~F8(~FF%i~F8)", file_path().c_str(), code );
}

// private write extension error
string file::extension_error( s32 code )
{
	return str::format( "File extension ~F8(~FF%i~F8) ~F7in file ~FE\"%s\" ~F7is invalid", code,
		file_path().c_str() );
}

/* end */

}
}

#endif
