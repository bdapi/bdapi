
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_MAP2D_TILE_CPP
#define BDAPI_ENG2D_MAP2D_TILE_CPP
#include "eng2d_map2d.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace eng2d {
namespace map2d {



/* 2d engine map tile class implementation **************************************************************/



// private constructor

tile::tile( layer* _layer )
{
	layer_parent = _layer;
}



// private initialize

result tile::__initialize( s32 _s32_index_x, s32 _s32_index_y )
{
	s32_index_x = _s32_index_x;
	s32_index_y = _s32_index_y;

	s32_x = ( L().get_x() + s32_index_x ) * L().get_tile_w();
	s32_y = ( L().get_y() + s32_index_y ) * L().get_tile_h();

	f32_friction    = L().get_default_friction();
	f32_restitution = L().get_default_restitution();

	s32_type = 0;

	return 1;
}



// public constructors

tile::tile( const tile& _tile )
{
	layer_parent = _tile.layer_parent;

	s32_index_x = _tile.s32_index_x;
	s32_index_y = _tile.s32_index_y;

	s32_x = _tile.s32_x;
	s32_y = _tile.s32_y;

	f32_friction    = _tile.f32_friction;
	f32_restitution = _tile.f32_restitution;

	s32_type = _tile.s32_type;

	polygon_tile = _tile.polygon_tile;
}



// get parent layer

layer& tile::L()
{
	return *layer_parent;
}
const layer& tile::L() const
{
	return *layer_parent;
}



// operator ()

layer& tile::operator () ()
{
	return *layer_parent;
}
const layer& tile::operator () () const
{
	return *layer_parent;
}



// get position

vector tile::get_position() const
{
	return vector( s32_x, s32_y );
}



// get line type

const line& tile::get_line_type() const
{
	return L().get_line_type( s32_type );
}

// get polygon type

const polygon& tile::get_polygon_type() const
{
	return L().get_polygon_type( s32_type );
}



// set type

tile& tile::set_type( s32 _s32_type )
{
	s32_type = _s32_type % 22;

	polygon_tile = get_polygon_type() + vector( s32_x, s32_y );

	reset_multiline();

	map2d::layer* layer_tile = get_layer();

	s32 x = get_index_x();
	s32 y = get_index_y();

	s32 w = layer_tile->get_w();
	s32 h = layer_tile->get_h();

	if( math<s32>::within( y-1, h ) ) layer_tile->get( x,   y-1 ).reset_multiline();
	if( math<s32>::within( x+1, w ) ) layer_tile->get( x+1, y   ).reset_multiline();
	if( math<s32>::within( y+1, h ) ) layer_tile->get( x,   y+1 ).reset_multiline();
	if( math<s32>::within( x-1, w ) ) layer_tile->get( x-1, y   ).reset_multiline();

	return *this;
}



// reset multiline

tile& tile::reset_multiline()
{
	multiline_tile.set_tile( *this );

	return *this;
}



// get polygon

const polygon& tile::get_polygon() const
{
	return polygon_tile;
}

// get multiline

const multiline& tile::get_multiline() const
{
	return multiline_tile;
}



/* end */
}}}
#endif
