
/* bdapi - brain damage api version 0.6.0 */
// filter_core_index.frag
#version 120

/* static variable declarations */

// constant variables

// varying variables

varying vec2 tex_coord;

// uniform variables

uniform sampler2D frag_texture;
uniform sampler2D index_texture;

/* function implementations */

// round to int
int round_to_int( float x )
{
	return int( x + 0.5 );
}

// modulus
int modulus( int x, int y )
{
	return x - ( y * ( x / y ) );
}

// main function implementation
void main()
{
	vec4 frag_src = texture2D( frag_texture, tex_coord );

	int red_i   = round_to_int( frag_src.r * 63.0 );
	int green_i = round_to_int( frag_src.g * 63.0 );
	int blue_i  = round_to_int( frag_src.b * 63.0 );

	int x_i = red_i   + modulus( blue_i,  8 ) * 64;
	int y_i = green_i +          blue_i / 8   * 64;

	vec2 frag_dst;

	frag_dst.x = float(x_i) / 512.0;
	frag_dst.y = float(y_i) / 512.0;

	vec4 palette_src = texture2D( index_texture, frag_dst );

	palette_src.a = frag_src.a;

	gl_FragColor = palette_src;
}

/* end */
