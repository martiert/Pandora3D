#ifndef MATH_VECTOR3_H_INCLUDED
#define MATH_VECTOR3_H_INCLUDED

#include "vector.h"

namespace Math
{

typedef Vector<float,     3> Vec3f;
typedef Vector<double,    3> Vec3d;
typedef Vector<int,       3> Vec3i;
typedef Vector<uint32_t,  3> Vec3u;

template<typename Real>
Vector<Real, 3> cross_product(const Vector<Real, 3> & left, const Vector<Real, 3> & right);

template<typename Real>
void generate_orthonormal_basis(Vector<Real, 3> & vector1,
                                Vector<Real, 3> & vector2,
                                Vector<Real, 3> & vector3);

#define INCLUDED_FROM_VECTOR3_H
#include "vector3_tmpl.h"
#undef INCLUDED_FROM_VECTOR3_H

}

#endif
