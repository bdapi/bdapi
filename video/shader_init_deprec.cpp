
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_SHADER_INIT_DEPREC_CPP
#define BDAPI_VIDEO_SHADER_INIT_DEPREC_CPP
#include "video/shader.hpp"

/* includes */

// bdapi
#include "error/handler.hpp"
#include "logging/handler.hpp"
#include "video/opengl.hpp"

// namespaces
namespace bdapi {
namespace video {

/* shader class deprecated initialization function implementations */

// private deprecated compile shader
result shader::compile_deprec__( u32 handle, string type, const io::path filename )
{
	s32 info_length = 0;
	s32 info_chars  = 0;

	char* info_log;

	glGetObjectParameterivARB( handle, OBJECT_INFO_LOG_LENGTH_ARB, &info_length );

	info_log = new char[ info_length + 1 ];

	glGetShaderInfoLog( handle, info_length, &info_chars, info_log );

	LOG_U32( info_length );

	if( strlen( info_log ) > 0 && str::find( info_log, "shader was successfully" ) == string::npos )
	{
		util::container< string, std::vector > info_strings = str::split( info_log, '\n' );

		delete[] info_log;

		WRITE_ERROR( "%s shader compilation error in shader ~FE\"%s\"", type.c_str(), filename().c_str() );

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

// private deprecated link shader
result shader::link_deprec__()
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

	if( !compile_deprec__( vertex_shader, "Vertex", vert_filename ) )
	{
		WRITE_ERROR( "Vertex shader ~FE\"%s\" ~F7compilation failed", vert_filename().c_str() );

		return 0;
	}

	if( !compile_deprec__( fragment_shader, "Fragment", frag_filename ) )
	{
		WRITE_ERROR( "Fragment shader ~FE\"%s\" ~F7compilation failed", frag_filename().c_str() );

		return 0;
	}

	glAttachObjectARB( handle, vertex_shader   );
	glAttachObjectARB( handle, fragment_shader );

	glDeleteObjectARB( vertex_shader   );
	glDeleteObjectARB( fragment_shader );

	glLinkProgramARB( handle );

	return 1;
}

/* end */

}
}

#endif
