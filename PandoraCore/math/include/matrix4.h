#ifndef MATH_MATRIX4_H_INCLUDED
#define MATH_MATRIX4_H_INCLUDED

#include "config.h"
#include "vector4.h"
#include "matrix3.h"

#include <array>
#include <cassert>
#include <algorithm>

namespace Math
{
  template<typename Real>
  class Matrix4
  {
    public:
      explicit Matrix4();

      explicit Matrix4(const Real& a00, const Real& a01, const Real& a02, const Real& a03,
                        const Real& a10, const Real& a11, const Real& a12, const Real& a13,
                        const Real& a20, const Real& a21, const Real& a22, const Real& a23,
                        const Real& a30, const Real& a31, const Real& a32, const Real& a33);

      explicit Matrix4(const std::array<Real, 16>& array);
      explicit Matrix4(const Matrix3<Real>& matrix);

      Matrix4& operator=(const std::array<Real, 16>& array);
      Matrix4& operator=(const Matrix3<Real>& matrix);

      Real& operator()(const size_t& i, const size_t& j);
      Real operator()(const size_t& i, const size_t& j) const;

      Real& operator[](const size_t& i);
      Real operator[](const size_t& i) const;

      std::array<Real, 16>& get_data();
      std::array<Real, 16> get_data() const;

      Matrix4& operator*=(const Real& scalar);
      Matrix4& operator/=(const Real& scalar);
      Matrix4& operator+=(const Matrix4 other);
      Matrix4& operator-=(const Matrix4 other);

      Matrix4 transpose() const;
      Matrix4 inverse() const;

      Real trace() const;
      Real determinant() const;

      const static Matrix4 IDENTITY;
      const static Matrix4 ZERO;
    private:
      std::array<Real, 16> data;

      Real calculate_sub_determinant(const size_t& row, const size_t& column) const;
  };

  typedef Matrix4<float>        Matrix4f;
  typedef Matrix4<double>       Matrix4d;
  typedef Matrix4<int>          Matrix4i;
  typedef Matrix4<unsigned int> Matrix4u;

  template<typename Real>
  Matrix4<Real> operator*(const Matrix4<Real>& matrix, const Real& scalar);

  template<typename Real>
  Matrix4<Real> operator*(const Real& scalar, const Matrix4<Real>& matrix);

  template<typename Real>
  Vector<Real, 4> operator*(const Matrix4<Real>& matrix, const Vector<Real, 4>& vector);

  template<typename Real>
  Vector<Real, 4> operator*(const Vector<Real, 4>& vector, const Matrix4<Real>& matrix);

  template<typename Real>
  Matrix4<Real> operator*(const Matrix4<Real>& left, const Matrix4<Real>& right);

  template<typename Real>
  Matrix4<Real> operator/(const Matrix4<Real>& matrix, const Real& scalar);

  template<typename Real>
  Matrix4<Real> operator+(const Matrix4<Real>& left, const Matrix4<Real>& right);

  template<typename Real>
  Matrix4<Real> operator-(const Matrix4<Real>& left, const Matrix4<Real>& right);

  template<typename Real>
  bool operator==(const Matrix4<Real>& left, const Matrix4<Real>& right);

  template<typename Real>
  bool operator!=(const Matrix4<Real>& left, const Matrix4<Real>& right);
}

// Implementation
template<typename Real>
Math::Matrix4<Real>::Matrix4()
  : data {{1, 0, 0, 0,
           0, 1, 0, 0,
           0, 0, 1, 0,
           0, 0, 0, 1}}
{ }

template<typename Real>
Math::Matrix4<Real>::Matrix4(const Real& a00, const Real& a01, const Real& a02, const Real& a03,
                              const Real& a10, const Real& a11, const Real& a12, const Real& a13,
                              const Real& a20, const Real& a21, const Real& a22, const Real& a23,
                              const Real& a30, const Real& a31, const Real& a32, const Real& a33)
  : data {{a00, a01, a02, a03,
           a10, a11, a12, a13,
           a20, a21, a22, a23,
           a30, a31, a32, a33}}
{ }

template<typename Real>
Math::Matrix4<Real>::Matrix4(const std::array<Real,16>& array)
  : data(array)
{ }

template<typename Real>
Math::Matrix4<Real>::Matrix4(const Matrix3<Real>& matrix)
  : data {{matrix[0], matrix[1], matrix[2], 0,
           matrix[3], matrix[4], matrix[5], 0,
           matrix[6], matrix[7], matrix[8], 0,
           0,         0,         0,         1}}
{ }

template<typename Real>
Math::Matrix4<Real>& Math::Matrix4<Real>::operator=(const std::array<Real, 16>& array)
{
  data = array;

  return *this;
}

template<typename Real>
Math::Matrix4<Real>& Math::Matrix4<Real>::operator=(const Matrix3<Real>& matrix)
{
  data[0] = matrix[0];
  data[1] = matrix[1];
  data[2] = matrix[2];
  data[4] = matrix[3];
  data[5] = matrix[4];
  data[6] = matrix[5];
  data[8] = matrix[6];
  data[9] = matrix[7];
  data[10] = matrix[8];
  data[3] = data[7] = data[11] = data[12] = data[13] = data[14] = 0;
  data[15] = 1;

  return *this;
}

template<typename Real>
Real& Math::Matrix4<Real>::operator()(const size_t& i, const size_t& j)
{
  assert(i < 4 && j < 4 && "Index operator out of range");

  return data[i*4 + j];
}

template<typename Real>
Real Math::Matrix4<Real>::operator()(const size_t& i, const size_t& j) const
{
  assert(i < 4 && j < 4 && "Index operator out of range");

  return data[i*4 + j];
}

template<typename Real>
Real& Math::Matrix4<Real>::operator[](const size_t& i)
{
  assert(i < 16 && "Index operator out of range");

  return data[i];
}

template<typename Real>
Real Math::Matrix4<Real>::operator[](const size_t& i) const
{
  assert(i < 16 && "Index operator out of range");

  return data[i];
}

template<typename Real>
std::array<Real, 16>& Math::Matrix4<Real>::get_data()
{
  return data;
}

template<typename Real>
std::array<Real, 16> Math::Matrix4<Real>::get_data() const
{
  return data;
}

template<typename Real>
Math::Matrix4<Real>& Math::Matrix4<Real>::operator*=(const Real& scalar)
{
  for (auto i = 0; i < 16; ++i)
    data[i] *= scalar;

  return *this;
}

template<typename Real>
Math::Matrix4<Real>& Math::Matrix4<Real>::operator/=(const Real& scalar)
{
  assert(scalar != 0 && "Can not divide matrix by zero");

  for (auto i = 0; i < 16; ++i)
    data[i] /= scalar;

  return *this;
}

template<typename Real>
Math::Matrix4<Real>& Math::Matrix4<Real>::operator+=(const Matrix4<Real> other)
{
  for (auto i = 0; i < 16; ++i)
    data[i] += other[i];
  return *this;
}

template<typename Real>
Math::Matrix4<Real>& Math::Matrix4<Real>::operator-=(const Matrix4<Real> other)
{
  for (auto i = 0; i < 16; ++i)
    data[i] -= other[i];
  return *this;
}

template<typename Real>
Math::Matrix4<Real> Math::Matrix4<Real>::transpose() const
{
  Matrix4<Real> res;
  for (auto i = 0; i < 4; ++i)
    for (auto j = 0; j < 4; ++j)
      res(j,i) = data[i*4 + j];

  return res;
}

// Code from the MESA implementation of gluInvertMatrix.
template<typename Real>
Math::Matrix4<Real> Math::Matrix4<Real>::inverse() const
{
  Real det = determinant();

  assert(det != 0 && "Can not find inverse of singular matrix");

  Matrix4<Real> res;

  res[0] = data[5]  * data[10] * data[15] -
    data[5]  * data[11] * data[14] -
    data[9]  * data[6]  * data[15] +
    data[9]  * data[7]  * data[14] +
    data[13] * data[6]  * data[11] -
    data[13] * data[7]  * data[10];

  res[4] = -data[4]  * data[10] * data[15] +
    data[4]  * data[11] * data[14] +
    data[8]  * data[6]  * data[15] -
    data[8]  * data[7]  * data[14] -
    data[12] * data[6]  * data[11] +
    data[12] * data[7]  * data[10];

  res[8] = data[4]  * data[9] * data[15] -
    data[4]  * data[11] * data[13] -
    data[8]  * data[5] * data[15] +
    data[8]  * data[7] * data[13] +
    data[12] * data[5] * data[11] -
    data[12] * data[7] * data[9];

  res[12] = -data[4]  * data[9] * data[14] +
    data[4]  * data[10] * data[13] +
    data[8]  * data[5] * data[14] -
    data[8]  * data[6] * data[13] -
    data[12] * data[5] * data[10] +
    data[12] * data[6] * data[9];

  res[1] = -data[1]  * data[10] * data[15] +
    data[1]  * data[11] * data[14] +
    data[9]  * data[2] * data[15] -
    data[9]  * data[3] * data[14] -
    data[13] * data[2] * data[11] +
    data[13] * data[3] * data[10];

  res[5] = data[0]  * data[10] * data[15] -
    data[0]  * data[11] * data[14] -
    data[8]  * data[2] * data[15] +
    data[8]  * data[3] * data[14] +
    data[12] * data[2] * data[11] -
    data[12] * data[3] * data[10];

  res[9] = -data[0]  * data[9] * data[15] +
    data[0]  * data[11] * data[13] +
    data[8]  * data[1] * data[15] -
    data[8]  * data[3] * data[13] -
    data[12] * data[1] * data[11] +
    data[12] * data[3] * data[9];

  res[13] = data[0]  * data[9] * data[14] -
    data[0]  * data[10] * data[13] -
    data[8]  * data[1] * data[14] +
    data[8]  * data[2] * data[13] +
    data[12] * data[1] * data[10] -
    data[12] * data[2] * data[9];

  res[2] = data[1]  * data[6] * data[15] -
    data[1]  * data[7] * data[14] -
    data[5]  * data[2] * data[15] +
    data[5]  * data[3] * data[14] +
    data[13] * data[2] * data[7] -
    data[13] * data[3] * data[6];

  res[6] = -data[0]  * data[6] * data[15] +
    data[0]  * data[7] * data[14] +
    data[4]  * data[2] * data[15] -
    data[4]  * data[3] * data[14] -
    data[12] * data[2] * data[7] +
    data[12] * data[3] * data[6];

  res[10] = data[0]  * data[5] * data[15] -
    data[0]  * data[7] * data[13] -
    data[4]  * data[1] * data[15] +
    data[4]  * data[3] * data[13] +
    data[12] * data[1] * data[7] -
    data[12] * data[3] * data[5];

  res[14] = -data[0]  * data[5] * data[14] +
    data[0]  * data[6] * data[13] +
    data[4]  * data[1] * data[14] -
    data[4]  * data[2] * data[13] -
    data[12] * data[1] * data[6] +
    data[12] * data[2] * data[5];

  res[3] = -data[1] * data[6] * data[11] +
    data[1] * data[7] * data[10] +
    data[5] * data[2] * data[11] -
    data[5] * data[3] * data[10] -
    data[9] * data[2] * data[7] +
    data[9] * data[3] * data[6];

  res[7] = data[0] * data[6] * data[11] -
    data[0] * data[7] * data[10] -
    data[4] * data[2] * data[11] +
    data[4] * data[3] * data[10] +
    data[8] * data[2] * data[7] -
    data[8] * data[3] * data[6];

  res[11] = -data[0] * data[5] * data[11] +
    data[0] * data[7] * data[9] +
    data[4] * data[1] * data[11] -
    data[4] * data[3] * data[9] -
    data[8] * data[1] * data[7] +
    data[8] * data[3] * data[5];

  res[15] = data[0] * data[5] * data[10] -
    data[0] * data[6] * data[9] -
    data[4] * data[1] * data[10] +
    data[4] * data[2] * data[9] +
    data[8] * data[1] * data[6] -
    data[8] * data[2] * data[5];

  det = 1.0 / det;
  return res * det;
}

template<typename Real>
Real Math::Matrix4<Real>::trace() const
{
  return data[0] + data[5] + data[10] + data[15];
}

template<typename Real>
Real Math::Matrix4<Real>::determinant() const
{
  const Real sub1 = calculate_sub_determinant(0,0);
  const Real sub2 = calculate_sub_determinant(0,1);
  const Real sub3 = calculate_sub_determinant(0,2);
  const Real sub4 = calculate_sub_determinant(0,3);

  return data[0] * sub1 - data[1] * sub2 + data[2] * sub3 - data[3] * sub4;
}

template<typename Real>
Math::Matrix4<Real> Math::operator*(const Matrix4<Real>& matrix, const Real& scalar)
{
  Matrix4<Real> result = matrix;
  for (auto i = 0; i < 16; ++i)
    result[i] *= scalar;
  return result;
}

template<typename Real>
Math::Matrix4<Real> Math::operator*(const Real& scalar, const Matrix4<Real>& matrix)
{
  return matrix * scalar;
}

template<typename Real>
Math::Vector<Real, 4> Math::operator*(const Matrix4<Real>& matrix, const Vector<Real, 4>& vector)
{
  Vector<Real, 4> res;
  for (auto i = 0; i < 4; ++i)
    for (auto j = 0; j < 4; ++j)
      res[i] += matrix(i,j) * vector[j];

  return res;
}

template<typename Real>
Math::Vector<Real, 4> Math::operator*(const Vector<Real, 4>& vector, const Matrix4<Real>& matrix)
{
  Vector<Real, 4> res;
  for (auto i = 0; i < 4; ++i)
    for (auto j = 0; j < 4; ++j)
      res[i] += vector[j] * matrix(j,i);

  return res;
}

template<typename Real>
Math::Matrix4<Real> Math::operator/(const Matrix4<Real>& matrix, const Real& scalar)
{
  auto result = matrix;
  result /= scalar;
  return result;
}

template<typename Real>
Math::Matrix4<Real> Math::operator+(const Matrix4<Real>& left, const Matrix4<Real>& right)
{
  Matrix4<Real> result;
  for (auto i = 0; i < 16; ++i)
    result[i] = left[i] + right[i];
  return result;
}

template<typename Real>
Math::Matrix4<Real> Math::operator-(const Matrix4<Real>& left, const Matrix4<Real>& right)
{
  Matrix4<Real> result;
  for (auto i = 0; i < 16; ++i)
    result[i] = left[i] - right[i];
  return result;
}

template<typename Real>
Math::Matrix4<Real> Math::operator*(const Matrix4<Real>& left, const Matrix4<Real>& right)
{
  Matrix4<Real> result;
  for (auto i = 0; i < 4; ++i) {
    for (auto j = 0; j < 4; ++j) {
      Real element = 0;
      for (auto k = 0; k < 4; ++k)
        element += left(i,k) * right(k,j);
      result(i,j) = element;
    }
  }
  return result;
}

template<typename Real>
bool Math::operator==(const Matrix4<Real>& left, const Matrix4<Real>& right)
{
  return left.get_data() == right.get_data();
}

template<typename Real>
bool Math::operator!=(const Matrix4<Real>& left, const Matrix4<Real>& right)
{
  return !(left == right);
}

template<typename Real>
Real Math::Matrix4<Real>::calculate_sub_determinant(const size_t& row, const size_t& column) const
{
  Matrix3<Real> matrix;
  size_t index = 0;
  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 0; j < 4; ++j) {
      if (i != row && j != column) {
        matrix[index] = data[i * 4 + j];
        ++index;
      }
    }
  }

  return matrix.determinant();
}

#endif // MATH_MATRIX4_H_INCLUDED
