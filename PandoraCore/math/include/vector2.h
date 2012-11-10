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
  Vector<Real, 2> perp_vector(const Vector<Real, 2>& vector);

  template<typename Real>
  void generate_orthonormal_basis(Vector<Real, 2>& vector1, Vector<Real, 2>& vector2);

  template<typename Real>
  Vector<Real, 2> perp_vector(const Vector<Real, 2>& vector)
  {
    return Vector<Real, 2>({vector[1], -vector[0]});
  }

  template<typename Real>
  void generate_orthonormal_basis(Vector<Real, 2>& vector1, Vector<Real, 2>& vector2)
  {
    Vector<Real, 2> zero_vector;
    assert(vector1 != vector2 &&
           "Can not make orthonormal basis from equal vectors");

    assert(vector1 != zero_vector &&
           vector2 != zero_vector &&
           "Can not make orthonormal basis from a zero vector");

    normalize_vector(vector1);
    vector2 = perp_vector(vector1);
  }
}

#endif // MATH_VECTOR2_H_INCLUDED
