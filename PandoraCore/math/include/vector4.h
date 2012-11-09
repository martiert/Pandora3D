#ifndef MATH_VECTOR4_H_INCLUDED
#define MATH_VECTOR4_H_INCLUDED

#include "config.h"
#include "vector3.h"

#include <cassert>
#include <cmath>

namespace Math
{
  template<typename Real>
  struct Vector4
  {
    public:
      explicit Vector4();
      explicit Vector4(const Real& x, const Real& y, const Real& z, const Real& w);
      explicit Vector4(const Real data[4]);

      Vector4& operator=(const Real data[4]);

      Real& operator[](const size_t& i);
      Real operator[](const size_t& i) const;

      static const Vector4 ZERO;
      static const Vector4 E1;
      static const Vector4 E2;
      static const Vector4 E3;
      static const Vector4 E4;
    private:
      Real data[4];
  };

  typedef Vector4<float>  Vec4f;
  typedef Vector4<double> Vec4d;
  typedef Vector4<int>    Vec4i;
  typedef Vector4<uint>   Vec4u;

  template<typename Real>   Real length(const Vector4<Real>& vector);
  template<typename Real>   Real lengthSquared(const Vector4<Real>& vector);
  template<typename Real>   Real dot(const Vector4<Real>& left, const Vector4<Real>& right);
  template<typename Real>   Vector4<Real>& normalize(Vector4<Real>& vector);

  template<typename Real>   Vector4<Real>& operator+=(Vector4<Real>& to, const Vector4<Real>& from);
  template<typename Real>   Vector4<Real>& operator-=(Vector4<Real>& to, const Vector4<Real>& from);
  template<typename Real>   Vector4<Real>& operator*=(Vector4<Real>& to, const Vector4<Real>& from);
  template<typename Real>   Vector4<Real>& operator*=(Vector4<Real>& to, const Real scalar);
  template<typename Real>   Vector4<Real>& operator/=(Vector4<Real>& to, const Real scalar);

  template<typename Real>   Vector4<Real> operator-(const Vector4<Real>& vec);
  template<typename Real>   Vector4<Real> operator+(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2);
  template<typename Real>   Vector4<Real> operator-(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2);
  template<typename Real>   Vector4<Real> operator*(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2);
  template<typename Real>   Vector4<Real> operator*(const Vector4<Real>& vec, const Real& scalar);
  template<typename Real>   Vector4<Real> operator*(const Real& scalar, const Vector4<Real>& vec);
  template<typename Real>   Vector4<Real> operator/(const Vector4<Real>& vec, const Real& scalar);

  template<typename Real>   bool operator==(const Vector4<Real>& vec1, const Vector4<Real>& vec2);
  template<typename Real>   bool operator!=(const Vector4<Real>& vec1, const Vector4<Real>& vec2);
}

namespace Math
{

// Implementation
template<typename Real>
Vector4<Real>::Vector4()
  : data {0, 0, 0, 0}
{ }

template<typename Real>
Vector4<Real>::Vector4(const Real& x, const Real& y, const Real& z, const Real& w)
  : data {x, y, z, w}
{ }

template<typename Real>
Vector4<Real>::Vector4(const Real vector[4])
  : data {vector[0], vector[1], vector[2], vector[3]}
{ }

template<typename Real>
Vector4<Real>& Vector4<Real>::operator=(const Real vector[4])
{
  data[0] = vector[0];
  data[1] = vector[0];
  data[2] = vector[0];
  data[3] = vector[0];

  return *this;
}

template<typename Real>
Real& Vector4<Real>::operator[](const size_t& i)
{
  assert(i < 4 && "Index operator out of range");

  return data[i];
}

template<typename Real>
Real Vector4<Real>::operator[](const size_t& i) const
{
  assert(i < 4 && "Index operator out of range");

  return data[i];
}

template<typename Real>
Vector4<Real>& operator+=(Vector4<Real>& to, const Vector4<Real>& from)
{
  for (auto i = 0; i < 4; ++i)
    to[i] += from[i];
  return to;
}

template<typename Real>
Vector4<Real>& operator-=(Vector4<Real>& to, const Vector4<Real>& from)
{
  for (auto i = 0; i < 4; ++i)
    to[i] -= from[i];
  return to;
}

template<typename Real>
Vector4<Real>& operator*=(Vector4<Real>& to, const Vector4<Real>& from)
{
  for (auto i = 0; i < 4; ++i)
    to[i] *= from[i];
  return to;
}

template<typename Real>
Vector4<Real>& operator*=(Vector4<Real>& to, const Real scalar)
{
  for (auto i = 0; i < 4; ++i)
    to[i] *= scalar;
  return to;
}

template<typename Real>
Vector4<Real>& operator/=(Vector4<Real>& to, const Real scalar)
{
  assert(scalar != 0 && "Can not divide vector by zero");
  for (auto i = 0; i < 4; ++i)
    to[i] /= scalar;
  return to;
}

template<typename Real>
Real length(const Vector4<Real>& vector)
{
  return std::sqrt(lengthSquared(vector));
}

template<typename Real>
Real lengthSquared(const Vector4<Real>& vector)
{
  return dot(vector, vector);
}

template<typename Real>
Real dot(const Vector4<Real>& left, const Vector4<Real>& right)
{
  return left[0] * right[0] + left[1] * right[1] + left[2] * right[2] + left[3] * right[3];
}

template<typename Real>
Vector4<Real>& normalize(Vector4<Real>& vector)
{
  Real len = length(vector);

  assert(len != 0 && "Can not normalize zero vector");

  vector /= len;
  return vector;
}

template<typename Real>
Vector4<Real> operator-(const Vector4<Real>& vec)
{
  return Vector4<Real>(-vec[0], -vec[1], -vec[2], -vec[3]);
}

template<typename Real>
Vector4<Real> operator+(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2)
{
  auto result = vec_1;
  result += vec_2;
  return result;
}

template<typename Real>
Vector4<Real> operator-(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2)
{
  auto result = vec_1;
  result -= vec_2;
  return result;
}

template<typename Real>
Vector4<Real> operator*(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2)
{
  auto tmp = vec_1;
  tmp *= vec_2;
  return tmp;
}

template<typename Real>
Vector4<Real> operator*(const Vector4<Real>& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp *= scalar;
  return tmp;
}

template<typename Real>
Vector4<Real> operator*(const Real& scalar, const Vector4<Real>& vec)
{
  return vec * scalar;
}

template<typename Real>
Vector4<Real> operator/(const Vector4<Real>& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp /= scalar;
  return tmp;
}

template<typename Real>
bool operator==(const Vector4<Real>& vec1, const Vector4<Real>& vec2)
{
  return (vec1[0] == vec2[0] &&
          vec1[1] == vec2[1] &&
          vec1[2] == vec2[2] &&
          vec1[3] == vec2[3]);
}

template<typename Real>
bool operator!=(const Vector4<Real>& vec1, const Vector4<Real>& vec2)
{
  return !(vec1 == vec2);
}
}

#endif // MATH_VECTOR4_H_INCLUDED
