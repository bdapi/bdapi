
/* bdapi - brain damage api version 0.6.0 */
// filter_core_composite.frag
#version 120

/* static variable declarations */

// constant variables

const float filter[9] = float[9](
	 0.0019,  0.0031, -0.0108,
	 0.0000,  0.0407, -0.0445,
	-0.0807,  0.2913,  0.5982 );

// uniform variables

uniform sampler2D frag_texture;

uniform vec2 frag_texture_size;

uniform float frag_frame_count;

// varying variables

varying vec2 tex_coord;

varying vec2 pixel_number;

/* function implementations */

// fetch offset
vec3 fetch_offset( float offset, float inv_x )
{
	 return texture2D( frag_texture, tex_coord + vec2( offset * inv_x, 0.0 ) ).xyz;
}

// main function implementation
void main()
{
	float inv_x = 1.0 / frag_texture_size.x;

	float sig = 0.0;

	for( int i = 0; i < 8; i++ )
	{
		float offset = float(i);

		float sums =
			dot( fetch_offset( offset - 8.0, inv_x ), vec3(1.0) ) +
			dot( fetch_offset( 8.0 - offset, inv_x ), vec3(1.0) );

		sig += sums * filter[i];
	}

	sig += dot( texture2D( frag_texture, tex_coord ).xyz, vec3(1.0) ) * filter[8];

	float chroma_phase = 2.0945 * mod( pixel_number.y + frag_frame_count, 3.0 );

	float mod_phase = chroma_phase + pixel_number.x * 1.2566;

	vec3 out_color = vec3(sig) * vec3( 1.0, 2.0 * cos( mod_phase ), 2.0 * sin( mod_phase ) );

	gl_FragColor = vec4( out_color, 1.0 );
}

/* end */
