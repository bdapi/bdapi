
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_MAP2D_HPP
#define BDAPI_ENG2D_MAP2D_HPP
#include "bdapi.hpp"

/* includes */

// standard
#include "vector"

// bdapi
#include "eng2d_dynamic.hpp"

// namespaces
namespace bdapi {
namespace eng2d {
namespace map2d {



/* 2d engine map tile class declaration *****************************************************************/



class tile
{

private:

	BD_GET_COPY( layer*, layer_parent, get_layer );

	BD_GET_COPY( s32, s32_index_x, get_index_x );
	BD_GET_COPY( s32, s32_index_y, get_index_y );

	BD_GET_COPY( s32, s32_x, get_x );
	BD_GET_COPY( s32, s32_y, get_y );

	BD_GET_COPY_SET( tile, f32, f32_friction,    get_friction,    set_friction    );
	BD_GET_COPY_SET( tile, f32, f32_restitution, get_restitution, set_restitution );

	BD_GET_COPY( s32, s32_type, get_type );

	polygon   polygon_tile;
	multiline multiline_tile;

private:

	tile ( layer* );

	result __initialize ( s32, s32 );

public:

	tile ( const tile& );
 ~tile () {};

	      layer& L ();
	const layer& L () const;

	      layer& operator () ();
	const layer& operator () () const;

	vector get_position () const;

	const line&    get_line_type ()    const;
	const polygon& get_polygon_type () const;

	tile& set_type ( s32 );

	tile& reset_multiline ();

	const polygon&   get_polygon   () const;
	const multiline& get_multiline () const;

private:

	friend class layer;

};



/* 2d engine map layer class declaration ****************************************************************/



class layer
{

private:

	util::container< util::container< tile, std::vector >, std::vector > container_tiles;

	BD_GET_COPY( s32, s32_x, get_x );
	BD_GET_COPY( s32, s32_y, get_y );

	BD_GET_COPY( s32, s32_w, get_w );
	BD_GET_COPY( s32, s32_h, get_h );

	BD_GET_COPY( s32, s32_tile_w, get_tile_w );
	BD_GET_COPY( s32, s32_tile_h, get_tile_h );

	BD_GET_COPY_SET( layer, f32, f32_default_friction,    get_default_friction,    set_default_friction    );
	BD_GET_COPY_SET( layer, f32, f32_default_restitution, get_default_restitution, set_default_restitution );

	BD_GET_COPY_SET( layer, f32, f32_gravity, get_gravity, set_gravity );

	util::container< line,    std::vector > container_line_types;
	util::container< polygon, std::vector > container_polygon_types;

private:

	void __nullify ();

public:

	layer (                                             );
	layer (           s32, s32, s32, s32                );
	layer (           s32, s32, s32, s32,           f32 );
	layer (           s32, s32, s32, s32, f32, f32      );
	layer (           s32, s32, s32, s32, f32, f32, f32 );
	layer ( s32, s32, s32, s32, s32, s32                );
	layer ( s32, s32, s32, s32, s32, s32,           f32 );
	layer ( s32, s32, s32, s32, s32, s32, f32, f32      );
	layer ( s32, s32, s32, s32, s32, s32, f32, f32, f32 );
	layer ( const layer&                                );
 ~layer (                                             );

	result initialize (           s32, s32, s32, s32                );
	result initialize (           s32, s32, s32, s32,           f32 );
	result initialize (           s32, s32, s32, s32, f32, f32      );
	result initialize (           s32, s32, s32, s32, f32, f32, f32 );
	result initialize ( s32, s32, s32, s32, s32, s32                );
	result initialize ( s32, s32, s32, s32, s32, s32,           f32 );
	result initialize ( s32, s32, s32, s32, s32, s32, f32, f32      );
	result initialize ( s32, s32, s32, s32, s32, s32, f32, f32, f32 );
	result discard    (                                             );

	      util::container< tile, std::vector >& operator [] ( s32 );
	const util::container< tile, std::vector >& operator [] ( s32 ) const;

	      util::container< tile, std::vector >& get ( s32 );
	const util::container< tile, std::vector >& get ( s32 ) const;

	      tile& get ( s32, s32 );
	const tile& get ( s32, s32 ) const;

	      tile& get ( const vector& );
	const tile& get ( const vector& ) const;

	      math<s32>::vec2 get_index ( const vector& );
	const math<s32>::vec2 get_index ( const vector& ) const;

	const line&    get_line_type    ( s32 ) const;
	const polygon& get_polygon_type ( s32 ) const;

};



/* end */
}}}
#endif
