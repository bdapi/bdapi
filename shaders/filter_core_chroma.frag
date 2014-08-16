
/* bdapi - brain damage api version 0.6.0 */
// filter_core_chroma.frag
#version 120

/* static variable declarations */

// constant variables

const mat3 rgb_2_yiq_mat = mat3(
	 0.299000,  0.595716,  0.211456,
	 0.587000, -0.274453, -0.522591,
	 0.114000, -0.321263,  0.311135 );

// uniform variables

uniform sampler2D frag_texture;

uniform vec2 frag_texture_size;

uniform float frag_frame_count;

// varying variables

varying vec2 tex_coord;

varying vec2 pixel_number;

/* function implementations */

// rgb 2 yiq
vec3 rgb_2_yiq( vec3 rgb )
{
	return rgb_2_yiq_mat * rgb;
}

// main function implementation
void main()
{
	//vec3 frag_color = texture2D( frag_texture, tex_coord ).rgb;

	/*** TEMP BEGIN ***/

	vec3 frag_color = texture2D( frag_texture, tex_coord ).rgb + 0.00390625;

	/*** TEMP FINISHED ***/

	vec3 frag_yiq = rgb_2_yiq( pow( frag_color, vec3(0.4545) ) );

	float chroma_phase = 2.0945 * mod( pixel_number.y + frag_frame_count, 3.0 );

	float mod_phase = chroma_phase + pixel_number.x * 1.2566;

	gl_FragColor = vec4( frag_yiq.x, frag_yiq.y * cos( mod_phase ), frag_yiq.z * sin( mod_phase ), 1.0 );
}

/* end */
