#ifndef MATH_VECTOR2_H_INCLUDED
#define MATH_VECTOR2_H_INCLUDED

#include "vector.h"

#include <cassert>
#include <cmath>

namespace Math
{

typedef Vector<float,    2> Vec2f;
typedef Vector<double,   2> Vec2d;
typedef Vector<int,      2> Vec2i;
typedef Vector<uint32_t, 2> Vec2u;

template<typename Real>
Vector<Real, 2> perp_vector(const Vector<Real, 2> & vector);

template<typename Real>
void generate_orthonormal_basis(Vector<Real, 2> & vector1, Vector<Real, 2> & vector2);

#define INCLUDED_FROM_VECTOR2_H
#include "vector2_tmpl.h"
#undef INCLUDED_FROM_VECTOR2_H

}

#endif
