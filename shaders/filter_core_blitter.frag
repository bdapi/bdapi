
/* bdapi - brain damage api version 0.6.0 */
// filter_core_blitter.frag
#version 120

/* static variable declarations */

// constant variables

// uniform variables

uniform sampler2D frag_texture;
uniform sampler2D swatch_texture;
uniform sampler2D palette_texture;

//uniform vec2 palette_multiplier;

uniform float swatch_index;

// varying variables

varying vec2 tex_coord;

/* function implementations */

// main function implementation
void main()
{
	vec4 swatch_sample = texture2D( swatch_texture, vec2( texture2D( frag_texture, tex_coord ).r,
		swatch_index ) );

	gl_FragColor = texture2D( palette_texture, vec2( swatch_sample.r, swatch_sample.g ) );
}

/* end */
