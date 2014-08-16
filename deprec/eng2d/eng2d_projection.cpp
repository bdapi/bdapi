
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_ENG2D_PROJECTION_CPP
#define BDAPI_ENG2D_PROJECTION_CPP
#include "eng2d_primitive.hpp"

/* includes */

// namespaces
namespace bdapi {
namespace eng2d {



/* 2d engine projection class implementation ************************************************************/



// constructors

projection::projection()
{
	clear();
}
projection::projection( const polygon& _polygon, const vector& _vector_axis )
{
	get_projection( _polygon, _vector_axis );
}
projection::projection( const projection& _projection )
{
	min = _projection.min;
	max = _projection.max;
}



// operator < projection

bl projection::operator < ( const projection& _projection ) const
{
	if( max < _projection.min )
		return true;

	return false;
}

// operator <= projection

bl projection::operator <= ( const projection& _projection ) const
{
	if( *this < _projection || *this == _projection )
		return true;

	return false;
}

// operator == projection

bl projection::operator == ( const projection& _projection ) const
{
	if( ( min >= _projection.min && max <= _projection.max )
	||  ( _projection.min >= min && _projection.max <= max ) )
	{
		return true;
	}

	return false;
}

// operator >= projection

bl projection::operator >= ( const projection& _projection ) const
{
	if( *this > _projection || *this == _projection )
		return true;

	return false;
}

// operator > projection

bl projection::operator > ( const projection& _projection ) const
{
	if( min > _projection.max )
		return true;

	return false;
}



// does projection overlap another projection

bl projection::overlaps( const projection& _projection ) const
{
	if( ( _projection.min <   max           && _projection.min >   min           )
	||  ( _projection.max <   max           && _projection.max >   min           )
	||  (             min < _projection.min &&             max > _projection.max )
	||  ( _projection.min <   min           && _projection.max >   max           ) )
	{
		return true;
	}

	return false;
}



// get overlap

f32 projection::get_overlap() const
{
	return max - min;
}
f32 projection::get_overlap( const projection& _projection ) const
{
	return merge( _projection ).get_overlap();
}

// get minimum difference

f32 projection::get_min_diff( const projection& _projection ) const
{
	return _projection.min - min;
}

// get maximum difference

f32 projection::get_max_diff( const projection& _projection ) const
{
	return _projection.max - max;
}



// clear

projection& projection::clear()
{
	min = 0.f;
	max = 0.f;

	return *this;
}



// get projection from polygon

projection& projection::get_projection( const polygon& _polygon, const vector& _vector_axis )
{
	if( _polygon.is_empty() )
		return clear();

	util::container< f32, std::deque > container_points;

	c_for_i( line, std::deque, _polygon )
		container_points.insert( i->p1.get_projection( _vector_axis ).get_dot_product( _vector_axis ) );

	min = container_points[0];
	max = min;

	for( s32 i = 1; i < container_points.get_size(); i++ )
	{
		if( container_points[i] < min )
			min = container_points[i];

		if( container_points[i] > max )
			max = container_points[i];
	}

	return *this;
}



// merge

projection projection::merge( const projection& _projection ) const
{
	projection projection_merge;

	projection_merge.min = math<f32>::greater( min, _projection.min );
	projection_merge.max = math<f32>::lesser(  max, _projection.max );

	return projection_merge;
}



/* end */
}}
#endif
