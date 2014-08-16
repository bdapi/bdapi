


/* bdapi - brain damage api version 0.6.0 */
// filter_core_luma.frag



#version 120



/* static variable declarations */



// constant variables

const float luma_fltr[9] = float[9](
	 0.0019,  0.0052,  0.0035,
	-0.0163, -0.0407, -0.0118,
	 0.1111,  0.2729,  0.3489 );

const float chroma_fltr[9] = float[9](
	 0.0025,  0.0057,  0.0147,
	 0.0315,  0.0555,  0.0834,
	 0.1099,  0.1289,  0.1358 );

const mat3 yiq_2_rgb_mat = mat3(
	 1.0000,  1.0000,  1.0000,
	 0.9563, -0.2721, -1.1070,
	 0.6210, -0.6474,  1.7046 );

// uniform variables

uniform sampler2D frag_texture;

uniform vec2 frag_texture_size;

// varying variables

varying vec2 tex_coord;



/* function implementations */



// yiq to rgb

vec3 yiq_2_rgb( vec3 yiq )
{
	 return yiq_2_rgb_mat * yiq;
}

// fetch offset

vec3 fetch_offset( float offset, float inv_x )
{
	 return texture2D( frag_texture, tex_coord + vec2( offset * inv_x, 0.0 ) ).xyz;
}

// main

void main()
{
	float inv_x = 1.0 / frag_texture_size.x;

	vec3 sig = vec3(0.0);

	for( int i = 0; i < 8; i++ )
	{
		float off = float(i);

		vec3 sums = fetch_offset( off - 8.0, inv_x ) + fetch_offset( 8.0 - off, inv_x );

		sig += sums * vec3( luma_fltr[i], chroma_fltr[i], chroma_fltr[i] );
	}

	sig += texture2D( frag_texture, tex_coord ).xyz * vec3( luma_fltr[8], chroma_fltr[8], chroma_fltr[8] );

	vec3 rgb = pow( yiq_2_rgb(sig), vec3(2.2) );

	gl_FragColor = vec4( rgb, 1.0 );
}



/* end */


