
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_MAP2D_LAYER_CPP
#define BDAPI_ENG2D_MAP2D_LAYER_CPP
#include "eng2d_map2d.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace eng2d {
namespace map2d {



/* 2d engine map layer class implementation *************************************************************/



// private nullify

void layer::__nullify()
{
	container_tiles.clear();

	s32_x = 0;
	s32_y = 0;

	s32_w = 0;
	s32_h = 0;

	s32_tile_w = 0;
	s32_tile_h = 0;

	f32_default_friction    = 0.f;
	f32_default_restitution = 0.f;

	f32_gravity = 0.f;

	container_line_types.clear();
	container_polygon_types.clear();
}



// constructors

layer::layer()
{
	__nullify();
}
layer::layer( s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h )
{
	__nullify();

	initialize( _s32_w, _s32_h, _s32_tile_w, _s32_tile_h );
}
layer::layer( s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h, f32 _f32_gravity )
{
	__nullify();

	initialize( _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, _f32_gravity );
}
layer::layer( s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h, f32 _f32_default_friction,
f32 _f32_default_restitution )
{
	__nullify();

	initialize( _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, _f32_default_friction, _f32_default_restitution );
}
layer::layer( s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h, f32 _f32_default_friction,
f32 _f32_default_restitution, f32 _f32_gravity )
{
	__nullify();

	initialize( _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, _f32_default_friction, _f32_default_restitution,
		_f32_gravity );
}
layer::layer( s32 _s32_x, s32 _s32_y, s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h )
{
	__nullify();

	initialize( _s32_x, _s32_y, _s32_w, _s32_h, _s32_tile_w, _s32_tile_h );
}
layer::layer( s32 _s32_x, s32 _s32_y, s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h,
f32 _f32_gravity )
{
	__nullify();

	initialize( _s32_x, _s32_y, _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, _f32_gravity );
}
layer::layer( s32 _s32_x, s32 _s32_y, s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h,
f32 _f32_default_friction, f32 _f32_default_restitution )
{
	__nullify();

	initialize( _s32_x, _s32_y, _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, _f32_default_friction,
		_f32_default_restitution );
}
layer::layer( s32 _s32_x, s32 _s32_y, s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h,
f32 _f32_default_friction, f32 _f32_default_restitution, f32 _f32_gravity )
{
	__nullify();

	initialize( _s32_x, _s32_y, _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, _f32_default_friction,
		_f32_default_restitution, _f32_gravity );
}
layer::layer( const layer& _layer )
{
	container_tiles = _layer.container_tiles;

	s32_x = _layer.s32_x;
	s32_y = _layer.s32_y;

	s32_w = _layer.s32_w;
	s32_h = _layer.s32_h;

	s32_tile_w = _layer.s32_tile_w;
	s32_tile_h = _layer.s32_tile_h;

	f32_default_friction    = _layer.f32_default_friction;
	f32_default_restitution = _layer.f32_default_restitution;

	f32_gravity = _layer.f32_gravity;

	container_line_types    = _layer.container_line_types;
	container_polygon_types = _layer.container_polygon_types;
}

// destructor

layer::~layer()
{
	discard();
}



// initializers

result layer::initialize( s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h )
{
	return initialize( 0, 0, _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, 0.5f, 0.5f, 1.f );
}
result layer::initialize( s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h, f32 _f32_gravity )
{
	return initialize( 0, 0, _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, 0.5f, 0.5f, _f32_gravity );
}
result layer::initialize( s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h,
f32 _f32_default_friction, f32 _f32_default_restitution )
{
	return initialize( 0, 0, _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, _f32_default_friction,
		_f32_default_restitution, 1.f );
}
result layer::initialize( s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h,
f32 _f32_default_friction, f32 _f32_default_restitution, f32 _f32_gravity )
{
	return initialize( 0, 0, _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, _f32_default_friction,
		_f32_default_restitution, _f32_gravity );
}
result layer::initialize( s32 _s32_x, s32 _s32_y, s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h )
{
	return initialize( _s32_x, _s32_y, _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, 0.5f, 0.5f, 1.f );
}
result layer::initialize( s32 _s32_x, s32 _s32_y, s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h,
f32 _f32_gravity )
{
	return initialize( _s32_x, _s32_y, _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, 0.5f, 0.5f, _f32_gravity );
}
result layer::initialize( s32 _s32_x, s32 _s32_y, s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h,
f32 _f32_default_friction, f32 _f32_default_restitution )
{
	return initialize( _s32_x, _s32_y, _s32_w, _s32_h, _s32_tile_w, _s32_tile_h, _f32_default_friction,
		_f32_default_restitution, 1.f );
}
result layer::initialize( s32 _s32_x, s32 _s32_y, s32 _s32_w, s32 _s32_h, s32 _s32_tile_w, s32 _s32_tile_h,
f32 _f32_default_friction, f32 _f32_default_restitution, f32 _f32_gravity )
{
	s32_x = _s32_x;
	s32_y = _s32_y;

	s32_w = _s32_w;
	s32_h = _s32_h;

	s32_tile_w = _s32_tile_w;
	s32_tile_h = _s32_tile_h;

	f32_default_friction    = _f32_default_friction;
	f32_default_restitution = _f32_default_restitution;

	f32_gravity = _f32_gravity;

	f32 f32_px1 = 0.f;
	f32 f32_px2 = (f32)s32_tile_w * 0.5f;
	f32 f32_px3 = (f32)s32_tile_w;

	f32 f32_py1 = 0.f;
	f32 f32_py2 = (f32)s32_tile_h * 0.5f;
	f32 f32_py3 = (f32)s32_tile_h;

	vector vector_11( f32_px1, f32_py1 );
	vector vector_12( f32_px1, f32_py2 );
	vector vector_13( f32_px1, f32_py3 );

	vector vector_21( f32_px2, f32_py1 );
	vector vector_22( f32_px2, f32_py2 );
	vector vector_23( f32_px2, f32_py3 );

	vector vector_31( f32_px3, f32_py1 );
	vector vector_32( f32_px3, f32_py2 );
	vector vector_33( f32_px3, f32_py3 );

	container_line_types.initialize(22);

	container_line_types[ 0] = line( vector_11, vector_21 );
	container_line_types[ 1] = line( vector_11, vector_31 );
	container_line_types[ 2] = line( vector_21, vector_31 );
	container_line_types[ 3] = line( vector_31, vector_32 );
	container_line_types[ 4] = line( vector_31, vector_33 );
	container_line_types[ 5] = line( vector_32, vector_33 );
	container_line_types[ 6] = line( vector_23, vector_13 );
	container_line_types[ 7] = line( vector_33, vector_13 );
	container_line_types[ 8] = line( vector_33, vector_23 );
	container_line_types[ 9] = line( vector_12, vector_11 );
	container_line_types[10] = line( vector_13, vector_11 );
	container_line_types[11] = line( vector_13, vector_12 );
	container_line_types[12] = line( vector_13, vector_32 );
	container_line_types[13] = line( vector_12, vector_31 );
	container_line_types[14] = line( vector_11, vector_32 );
	container_line_types[15] = line( vector_12, vector_33 );
	container_line_types[16] = line( vector_13, vector_31 );
	container_line_types[17] = line( vector_11, vector_33 );
	container_line_types[18] = line( vector_23, vector_31 );
	container_line_types[19] = line( vector_11, vector_23 );
	container_line_types[20] = line( vector_13, vector_21 );
	container_line_types[21] = line( vector_21, vector_33 );

	container_polygon_types.initialize(22);

	container_polygon_types[ 0] = polygon(                                            );
	container_polygon_types[ 1] = polygon( vector_11, vector_31, vector_33, vector_13 );
	container_polygon_types[ 2] = polygon( vector_13, vector_32, vector_33            );
	container_polygon_types[ 3] = polygon( vector_12, vector_31, vector_33, vector_13 );
	container_polygon_types[ 4] = polygon( vector_11, vector_32, vector_33, vector_13 );
	container_polygon_types[ 5] = polygon( vector_12, vector_33, vector_13            );
	container_polygon_types[ 6] = polygon( vector_11, vector_31, vector_32            );
	container_polygon_types[ 7] = polygon( vector_11, vector_31, vector_33, vector_12 );
	container_polygon_types[ 8] = polygon( vector_11, vector_31, vector_32, vector_13 );
	container_polygon_types[ 9] = polygon( vector_11, vector_31, vector_12            );
	container_polygon_types[10] = polygon( vector_13, vector_31, vector_33            );
	container_polygon_types[11] = polygon( vector_11, vector_33, vector_13            );
	container_polygon_types[12] = polygon( vector_11, vector_31, vector_33            );
	container_polygon_types[13] = polygon( vector_11, vector_31, vector_13            );
	container_polygon_types[14] = polygon( vector_23, vector_31, vector_33            );
	container_polygon_types[15] = polygon( vector_11, vector_23, vector_13            );
	container_polygon_types[16] = polygon( vector_21, vector_31, vector_33            );
	container_polygon_types[17] = polygon( vector_11, vector_21, vector_13            );
	container_polygon_types[18] = polygon( vector_21, vector_31, vector_33, vector_13 );
	container_polygon_types[19] = polygon( vector_11, vector_21, vector_33, vector_13 );
	container_polygon_types[20] = polygon( vector_11, vector_31, vector_33, vector_23 );
	container_polygon_types[21] = polygon( vector_11, vector_31, vector_23, vector_13 );

	container_tiles.initialize( s32_w );

	fori( s32_w )
		container_tiles[i].initialize( s32_h, tile(this) );

	forx( s32_w )
		fory( s32_h )
			container_tiles[x][y].__initialize( x, y );

	return 1;
}

// discard

result layer::discard()
{
	return 1;
}



// operator [] s32

util::container< tile, std::vector >& layer::operator [] ( s32 i )
{
	return container_tiles[i];
}
const util::container< tile, std::vector >& layer::operator [] ( s32 i ) const
{
	return container_tiles[i];
}



// get column

util::container< tile, std::vector >& layer::get( s32 i )
{
	return container_tiles[i];
}
const util::container< tile, std::vector >& layer::get( s32 i ) const
{
	return container_tiles[i];
}



// get tile by index

tile& layer::get( s32 _s32_x, s32 _s32_y )
{
	return container_tiles[ _s32_x ][ _s32_y ];
}
const tile& layer::get( s32 _s32_x, s32 _s32_y ) const
{
	return container_tiles[ _s32_x ][ _s32_y ];
}



// get tile by actual position

tile& layer::get( const vector& _vector )
{
	return container_tiles[ ( _vector.x / s32_tile_w ) - s32_x ][ ( _vector.y / s32_tile_h ) - s32_y ];
}
const tile& layer::get( const vector& _vector ) const
{
	return container_tiles[ ( _vector.x / s32_tile_w ) - s32_x ][ ( _vector.y / s32_tile_h ) - s32_y ];
}



// get vector index by actual position

math<s32>::vec2 layer::get_index( const vector& _vector )
{
	return math<s32>::vec2( ( _vector.x / s32_tile_w ) - s32_x, ( _vector.y / s32_tile_h ) - s32_y );
}
const math<s32>::vec2 layer::get_index( const vector& _vector ) const
{
	return math<s32>::vec2( ( _vector.x / s32_tile_w ) - s32_x, ( _vector.y / s32_tile_h ) - s32_y );
}



// get line type

const line& layer::get_line_type( s32 i ) const
{
	return container_line_types[i];
}

// get polygon type

const polygon& layer::get_polygon_type( s32 i ) const
{
	return container_polygon_types[i];
}



/* end */
}}}
#endif
