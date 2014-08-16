
/* bdapi - brain damage api version 0.6.0 */
// filter_core_chroma.vert
#version 120

/* static variable declarations */

// constant variables

// uniform variables

uniform vec2 frag_texture_size;
uniform vec2 frag_output_size;

// varying variables

varying vec2 tex_coord;

varying vec2 pixel_number;

/* function implementations */

// main function implementation
void main()
{
	tex_coord = gl_MultiTexCoord0.xy;

	pixel_number = tex_coord * frag_texture_size * ( frag_output_size / frag_texture_size );

	gl_Position = ftransform();
}

/* end */
