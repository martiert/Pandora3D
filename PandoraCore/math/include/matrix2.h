#ifndef MATH_MATRIX2_H_INCLUDED
#define MATH_MATRIX2_H_INCLUDED

#include "config.h"
#include "vector2.h"

#include <array>
#include <cassert>
#include <algorithm>

namespace Math
{
  template<typename Real>
  class Matrix2
  {
    public:
      explicit Matrix2 ();
      explicit Matrix2 (const Real& m00, const Real& m01, const Real& m10, const Real&  m11);
      explicit Matrix2 (const std::array<Real, 4> data);

      Real& operator[] (const size_t& i);
      Real operator[] (const size_t& i) const;

      Real& operator () (const size_t& i, const size_t& j);
      Real operator () (const size_t& i, const size_t& j) const;

      std::array<Real, 4>& get_data ();
      std::array<Real, 4> get_data () const;

      Matrix2& operator+= (const Matrix2& matrix);
      Matrix2& operator-= (const Matrix2& matrix);
      Matrix2& operator*= (const Real& scalar);
      Matrix2& operator/= (const Real& scalar);

      Real determinant () const;
      Matrix2 transpose () const;
      Matrix2 inverse () const;

      const static Matrix2 IDENTITY;
      const static Matrix2 ZERO;
    private:
      std::array<Real, 4> data;
  };

  typedef Matrix2<float>          Matrix2f;
  typedef Matrix2<double>         Matrix2d;
  typedef Matrix2<int>            Matrix2i;
  typedef Matrix2<unsigned int>   Matrix2u;

  template<typename Real>
  Matrix2<Real> operator+ (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix);

  template<typename Real>
  Matrix2<Real> operator- (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix);

  template<typename Real>
  Matrix2<Real> operator* (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix);

  template<typename Real>
  Matrix2<Real> operator* (const Matrix2<Real>& matrix, const Real& scalar);

  template<typename Real>
  Vector2<Real> operator* (const Matrix2<Real>& matrix, const Vector2<Real>& vector);

  template<typename Real>
  Vector2<Real> operator* (const Vector2<Real>& vector, const Matrix2<Real>& matrix);

  template<typename Real>
  Matrix2<Real> operator* (const Real& scalar, const Matrix2<Real>& matrix);

  template<typename Real>
  Matrix2<Real> operator/ (const Matrix2<Real>& matrix, const Real& scalar);

  template<typename Real>
  bool operator== (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix);

  template<typename Real>
  bool operator!= (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix);
}

// Implementation
template<typename Real>
Math::Matrix2<Real>::Matrix2 ()
  : data {{1,0,0,1}}
{ }

template<typename Real>
Math::Matrix2<Real>::Matrix2 (const Real& m00, const Real& m01,
                              const Real& m10, const Real&  m11)
  : data {{m00, m01, m10, m11}}
{ }

template<typename Real>
Math::Matrix2<Real>::Matrix2 (const std::array<Real, 4> data)
  : data (data)
{ }

template<typename Real>
Real& Math::Matrix2<Real>::operator[] (const size_t& i)
{
  assert (i < 4 && "Index operator out of range");

  return data[i];
}

template<typename Real>
Real Math::Matrix2<Real>::operator[] (const size_t& i) const
{
  assert (i < 4 && "Index operator out of range");

  return data[i];
}

template<typename Real>
Real& Math::Matrix2<Real>::operator () (const size_t& i, const size_t& j)
{
  assert (i < 2 && j < 2 && "Index operator out of range");

  return data[i*2 + j];
}

template<typename Real>
Real Math::Matrix2<Real>::operator () (const size_t& i, const size_t& j) const
{
  assert (i < 2 && j < 2 && "Index operator out of range");

  return data[i*2 + j];
}

template<typename Real>
std::array<Real, 4>& Math::Matrix2<Real>::get_data ()
{
  return data;
}

template<typename Real>
std::array<Real, 4> Math::Matrix2<Real>::get_data () const
{
  return data;
}

template<typename Real>
Math::Matrix2<Real>& Math::Matrix2<Real>::operator+= (const Math::Matrix2<Real>& matrix)
{
  data[0] += matrix (0,0);
  data[1] += matrix (0,1);
  data[2] += matrix (1,0);
  data[3] += matrix (1,1);

  return *this;
}

template<typename Real>
Math::Matrix2<Real>& Math::Matrix2<Real>::operator-= (const Math::Matrix2<Real>& matrix)
{
  data[0] -= matrix (0,0);
  data[1] -= matrix (0,1);
  data[2] -= matrix (1,0);
  data[3] -= matrix (1,1);

  return *this;
}

template<typename Real>
Math::Matrix2<Real>& Math::Matrix2<Real>::operator*= (const Real& scalar)
{
  data[0] *= scalar;
  data[1] *= scalar;
  data[2] *= scalar;
  data[3] *= scalar;

  return *this;
}

template<typename Real>
Math::Matrix2<Real>& Math::Matrix2<Real>::operator/= (const Real& scalar)
{
  assert (scalar != 0 && "Can not divide matrix by zero");

  data[0] /= scalar;
  data[1] /= scalar;
  data[2] /= scalar;
  data[3] /= scalar;

  return *this;
}

template<typename Real>
Real Math::Matrix2<Real>::determinant () const
{
  return data[0]*data[3] - data[1]*data[2];
}

template<typename Real>
Math::Matrix2<Real> Math::Matrix2<Real>::transpose () const
{
  return Matrix2<Real> (data[0], data[2], data[1], data[3]);
}

template<typename Real>
Math::Matrix2<Real> Math::Matrix2<Real>::inverse () const
{
  Real det = determinant ();

  assert (det != 0 && "Inversion of singular matrix does not exist");

  Real scale = 1.0/det;

  Matrix2<Real> result (data[3], -data[1],
      -data[2], data[0]);

  return result * scale;
}

template<typename Real>
Math::Matrix2<Real> Math::operator+ (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix)
{
  auto result = lmatrix;
  result += rmatrix;
  return result;
}

template<typename Real>
Math::Matrix2<Real> Math::operator- (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix)
{
  auto result = lmatrix;
  result -= rmatrix;
  return result;
}

template<typename Real>
Math::Matrix2<Real> Math::operator* (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix)
{
  Matrix2<Real> res;
  res (0,0) = lmatrix (0,0) * rmatrix (0,0) + lmatrix (0,1) * rmatrix (1,0);
  res (0,1) = lmatrix (0,0) * rmatrix (0,1) + lmatrix (0,1) * rmatrix (1,1);
  res (1,0) = lmatrix (1,0) * rmatrix (0,0) + lmatrix (1,1) * rmatrix (1,0);
  res (1,1) = lmatrix (1,0) * rmatrix (0,1) + lmatrix (1,1) * rmatrix (1,1);

  return res;
}

template<typename Real>
Math::Matrix2<Real> Math::operator* (const Matrix2<Real>& matrix, const Real& scalar)
{
  auto result = matrix;
  result *= scalar;
  return result;
}

template<typename Real>
Math::Matrix2<Real> Math::operator* (const Real& scalar, const Matrix2<Real>& matrix)
{
  return matrix * scalar;
}

template<typename Real>
Math::Vector2<Real> Math::operator* (const Matrix2<Real>& matrix, const Vector2<Real>& vector)
{
  return Vector2<Real> (matrix[0] * vector.x + matrix[1] * vector.y,
      matrix[2] * vector.x + matrix[3] * vector.y);
}

template<typename Real>
Math::Vector2<Real> Math::operator* (const Vector2<Real>& vector, const Matrix2<Real>& matrix)
{
  return Vector2<Real> (matrix[0] * vector.x + matrix[2] * vector.y,
      matrix[1] * vector.x + matrix[3] * vector.y);
}

template<typename Real>
Math::Matrix2<Real> Math::operator/ (const Matrix2<Real>& matrix, const Real& scalar)
{
  auto result = matrix;
  result /= scalar;
  return result;
}

template<typename Real>
bool Math::operator== (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix)
{
  return lmatrix.get_data () == rmatrix.get_data ();
}

template<typename Real>
bool Math::operator!= (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix)
{
  return !(lmatrix == rmatrix);
}

#endif // MATH_MATRIX2_H_INCLUDED
