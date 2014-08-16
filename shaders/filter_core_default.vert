
/* bdapi - brain damage api version 0.6.0 */
// filter_core_default.vert
#version 120

/* static variable declarations */

// constant variables

// uniform variables

// varying variables

varying vec2 tex_coord;

/* function implementations */

// main function implementation
void main()
{
	tex_coord   = gl_MultiTexCoord0.xy;
	gl_Position = ftransform();
}

/* end */
