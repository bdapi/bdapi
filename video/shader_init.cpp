
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_SHADER_INIT_CPP
#define BDAPI_VIDEO_SHADER_INIT_CPP
#include "video/shader.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"
#include "io/file.hpp"
#include "logging/handler.hpp"
#include "video/opengl.hpp"

// namespaces
namespace bdapi {
namespace video {

/* shader class initialization function implementations */

// constructors
shader::shader( const io::path vert_filename, const io::path frag_filename )
{
	initialize( vert_filename, frag_filename );
}
shader::shader( const io::path vert_filename, const shader* frag_shader )
{
	initialize( vert_filename, frag_shader );
}
shader::shader( const shader* vert_shader, const io::path frag_filename )
{
	initialize( vert_shader, frag_filename );
}
shader::shader( const shader* vert_shader, const shader* frag_shader )
{
	initialize( vert_shader, frag_shader );
}

// destructor
shader::~shader()
{
	if( is_active() )
	{
		stop();
	}

	if( handle )
	{
		glDeleteShader( handle );
	}
}

// initializers
result shader::initialize( const io::path vert_filename, const io::path frag_filename )
{
	this->vert_filename = vert_filename;
	this->frag_filename = frag_filename;

	if( !load_shader_from_file( vert_source, this->vert_filename ) )
	{
		return 0;
	}

	if( !load_shader_from_file( frag_source, this->frag_filename ) )
	{
		return 0;
	}

	return link();
}
result shader::initialize( const io::path vert_filename, const shader* frag_shader )
{
	this->vert_filename = vert_filename;

	if( !load_shader_from_file( vert_source, this->vert_filename ) )
	{
		return 0;
	}

	frag_source   = frag_shader->frag_source;
	frag_filename = frag_shader->frag_filename;

	return link();
}
result shader::initialize( const shader* vert_shader, const io::path frag_filename )
{
	vert_source   = vert_shader->vert_source;
	vert_filename = vert_shader->vert_filename;

	this->frag_filename = frag_filename;

	if( !load_shader_from_file( frag_source, this->frag_filename ) )
	{
		return 0;
	}

	return link();
}
result shader::initialize( const shader* vert_shader, const shader* frag_shader )
{
	vert_source   = vert_shader->vert_source;
	vert_filename = vert_shader->vert_filename;

	frag_source   = frag_shader->frag_source;
	frag_filename = frag_shader->frag_filename;

	return link();
}

// private load shader from file
result shader::load_shader_from_file( string& source, const io::path filename )
{
	if( !filename.exists() )
	{
		return 0;
	}
	else if( !filename.is_file() )
	{
		return 0;
	}

	io::file shader_file( filename );

	if( !shader_file.read( true ) )
	{
		return 0;
	}

	source.clear();

	s32 size = shader_file.get_size();

	fori( size )
	{
		source.push_back( shader_file.out<u8>() );
	}

	return 1;
}

// private compile shader
result shader::compile( u32 handle, string type, string filename )
{
	s32 info_length = 0;
	s32 info_chars  = 0;

	char* info_log;

	glGetObjectParameterivARB( handle, OBJECT_INFO_LOG_LENGTH_ARB, &info_length );

	if( info_length > 0 )
	{
		info_log = new char[ info_length + 1 ];

		glGetInfoLogARB( handle, info_length, &info_chars, info_log );

		if( info_chars > 11 )
		{
			util::container< string, std::vector > info_strings = str::split( info_log, '\n' );

			delete[] info_log;

			if( filename.empty() )
			{
				WRITE_ERROR( "Unknown %s compilation error", type.c_str() );
			}
			else
			{
				WRITE_ERROR( "Compilation error in %s ~FE\"%s\"", type.c_str(), filename.c_str() );
			}

			LOG_OPEN();

			for( s32 i = 1; i < info_strings.get_size() - 2; i++ )
			{
				info_strings[i] = str::remove( info_strings[i], "ERROR: " );

				info_strings[i] = str::replace( info_strings[i], " '",      " ~FE\""    );
				info_strings[i] = str::replace( info_strings[i], "' ",      "\"~F7 "    );
				info_strings[i] = str::replace( info_strings[i], ":",       "~F8:~FF"   );
				info_strings[i] = str::replace( info_strings[i], "error(#", "~FCerror(" );
				info_strings[i] = str::replace( info_strings[i], "(",       "~F8(~FF"   );
				info_strings[i] = str::replace( info_strings[i], ")",       "~F8)~F7"   );

				LOG( "~FF%s~F8.", info_strings[i].c_str() );
			}

			LOG_CLOSE();

			return 0;
		}
		else
		{
			delete[] info_log;

			return 1;
		}
	}

	return 1;
}

// private link shader
result shader::link()
{
	handle = glCreateProgramObjectARB();

	GLhandleARB vertex_shader   = glCreateShaderObjectARB( VERTEX_SHADER_ARB   );
	GLhandleARB fragment_shader = glCreateShaderObjectARB( FRAGMENT_SHADER_ARB );

	cstr vert_source_cstr = vert_source.c_str();
	cstr frag_source_cstr = frag_source.c_str();

	glShaderSourceARB( vertex_shader,   1, (const GLchar**)&vert_source_cstr, NULL );
	glShaderSourceARB( fragment_shader, 1, (const GLchar**)&frag_source_cstr, NULL );

	glCompileShaderARB( vertex_shader   );
	glCompileShaderARB( fragment_shader );

	if( !compile( vertex_shader, "vertex shader", vert_filename() ) )
	{
		WRITE_ERROR( "Vertex shader ~FE\"%s\" ~F7compilation failed", vert_filename().c_str() );

		return 0;
	}

	if( !compile( fragment_shader, "fragment shader", frag_filename() ) )
	{
		WRITE_ERROR( "Fragment shader ~FE\"%s\" ~F7compilation failed", frag_filename().c_str() );

		return 0;
	}

	glAttachObjectARB( handle, vertex_shader   );
	glAttachObjectARB( handle, fragment_shader );

	glLinkProgramARB( handle );

	if( !compile( handle, "shader", "" ) )
	{
		WRITE_ERROR( "Shader compilation failed" );

		return 0;
	}

	glDeleteObjectARB( vertex_shader   );
	glDeleteObjectARB( fragment_shader );

	return 1;
}

/* end */

}
}

#endif
