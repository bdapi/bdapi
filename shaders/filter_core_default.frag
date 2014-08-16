
/* bdapi - brain damage api version 0.6.0 */
// filter_core_default.frag
#version 120

/* static variable declarations */

// constant variables

// uniform variables

uniform sampler2D frag_texture;

// varying variables

varying vec2 tex_coord;

/* function implementations */

// main function implementation
void main()
{
	gl_FragColor = texture2D( frag_texture, tex_coord );
}

/* end */
