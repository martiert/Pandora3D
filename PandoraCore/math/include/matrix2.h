#ifndef MATH_MATRIX2_H_INCLUDED
#define MATH_MATRIX2_H_INCLUDED

#include "matrix.h"

namespace Math
{
  typedef Matrix<float,     2> Matrix2f;
  typedef Matrix<double,    2> Matrix2d;
  typedef Matrix<int,       2> Matrix2i;
  typedef Matrix<uint32_t,  2> Matrix2u;

  template<typename Real>
  Real matrix_determinant(const Matrix<Real, 2>& matrix)
  {
    return matrix(0,0) * matrix(1,1) - matrix(0,1) * matrix(1,0);
  }

  template<typename Real>
  Matrix<Real, 2> matrix_adjugate(const Matrix<Real, 2>& matrix)
  {
    return Matrix<Real, 2>({matrix[3], -matrix[1],
                            -matrix[2], matrix[0]});
  }
}

#endif // MATH_MATRIX2_H_INCLUDED
