#ifndef MATH_VECTOR3_H_INCLUDED
#define MATH_VECTOR3_H_INCLUDED

#include "config.h"

#include <cassert>
#include <cmath>

namespace Math
{
  template<typename Real>
  struct Vector3
  {
      explicit Vector3();
      explicit Vector3(const Real& x, const Real& y, const Real& z);
      explicit Vector3(const Real data[3]);

      Vector3& operator=(const Real data[3]);

      Real& operator[](const size_t& i);
      Real operator[](const size_t& i) const;

      static const Vector3 ZERO;
      static const Vector3 E1;
      static const Vector3 E2;
      static const Vector3 E3;

    private:
      Real data[3];
  };

  typedef Vector3<float>  Vec3f;
  typedef Vector3<double> Vec3d;
  typedef Vector3<int>    Vec3i;
  typedef Vector3<uint32_t>   Vec3u;

  template<typename Real>   Real dot(const Vector3<Real>& left, const Vector3<Real>& right);
  template<typename Real>   Real length(const Vector3<Real>& vector);
  template<typename Real>   Real lengthSquared(const Vector3<Real>& vector);
  template<typename Real>   void normalize(Vector3<Real>& vector);
  template<typename Real>   Vector3<Real> cross(const Vector3<Real>& left, const Vector3<Real>& right);
  template<typename Real>   void generateOrthonormalBasis(Vector3<Real>& vec1, Vector3<Real>& vec2, Vector3<Real>& vec3);

  template<typename Real>   Vector3<Real>& operator+=(Vector3<Real>& to, const Vector3<Real>& from);
  template<typename Real>   Vector3<Real>& operator-=(Vector3<Real>& to, const Vector3<Real>& from);
  template<typename Real>   Vector3<Real>& operator*=(Vector3<Real>& to, const Vector3<Real>& from);
  template<typename Real>   Vector3<Real>& operator*=(Vector3<Real>& to, const Real& scalar);
  template<typename Real>   Vector3<Real>& operator/=(Vector3<Real>& to, const Real& scalar);

  template<typename Real>   Vector3<Real> operator-(const Vector3<Real>& vec);
  template<typename Real>   Vector3<Real> operator+(const Vector3<Real>& vec1, const Vector3<Real>& vec2);
  template<typename Real>   Vector3<Real> operator-(const Vector3<Real>& vec1, const Vector3<Real>& vec2);
  template<typename Real>   Vector3<Real> operator*(const Vector3<Real>& vec, const Real& scalar);
  template<typename Real>   Vector3<Real> operator*(const Real& scalar, const Vector3<Real>& vec);
  template<typename Real>   Vector3<Real> operator*(const Vector3<Real>& vec1, const Vector3<Real>& vec2);
  template<typename Real>   Vector3<Real> operator/(const Vector3<Real>& vec, const Real& scalar);

  template<typename Real>   bool operator==(const Vector3<Real>& vec1, const Vector3<Real>& vec2);
  template<typename Real>   bool operator!=(const Vector3<Real>& vec1, const Vector3<Real>& vec2);
}

namespace Math
{

// Implementation
template<typename Real>
Vector3<Real>::Vector3()
  : data {0, 0, 0}
{}

template<typename Real>
Vector3<Real>::Vector3(const Real& x, const Real& y, const Real& z)
  : data {x, y, z}
{}

template<typename Real>
Vector3<Real>::Vector3(const Real data[3])
  : data {data[0], data[1], data[2]}
{}

template<typename Real>
Vector3<Real>& Vector3<Real>::operator=(const Real vector[3])
{
  data[0] = vector[0];
  data[1] = vector[1];
  data[2] = vector[2];

  return *this;
}

template<typename Real>
Real& Vector3<Real>::operator[](const size_t& i)
{
  assert(i < 3 && "Index operator out of range");

  return data[i];
}

template<typename Real>
Real Vector3<Real>::operator[](const size_t& i) const
{
  assert(i < 3 && "Index operator out of range");

  return data[i];
}

template<typename Real>
Real dot(const Vector3<Real>& left, const Vector3<Real>& right)
{
  return (left[0] * right[0] + left[1] * right[1] + left[2] * right[2]);
}

template<typename Real>
Real length(const Vector3<Real>& vector)
{
  return std::sqrt(lengthSquared(vector));
}

template<typename Real>
Real lengthSquared(const Vector3<Real>& vector)
{
  return dot(vector, vector);
}

template<typename Real>
void normalize(Vector3<Real>& vector)
{
  Real len = length(vector);

  assert(len != 0 && "Can not normalize zero vector");

  vector /= len;
}

template<typename Real>
Vector3<Real> cross(const Vector3<Real>& left, const Vector3<Real>& right)
{
  Vector3<Real> res;
  res[0] = left[1] * right[2] - left[2] * right[1];
  res[1] = left[2] * right[0] - left[0] * right[2];
  res[2] = left[0] * right[1] - left[1] * right[0];

  return res;
}

template<typename Real>
void generateOrthonormalBasis(Vector3<Real>& vec1, Vector3<Real>& vec2, Vector3<Real>& vec3)
{
  assert(vec1 != Math::Vector3<Real>::ZERO &&
         vec2 != Math::Vector3<Real>::ZERO &&
         vec3 != Math::Vector3<Real>::ZERO &&
         "Can not make orthonormal basis with zero vectors");
  assert(vec1 != vec2 &&
         vec1 != vec3 &&
         vec2 != vec3 &&
         "Can not make orthonormal basis with equal vectors");

  vec2 = cross(vec1, vec3);
  vec3 = cross(vec1, vec2);

  normalize(vec1);
  normalize(vec2);
  normalize(vec3);
}

template<typename Real>
Vector3<Real>& operator+=(Vector3<Real>& to, const Vector3<Real>& from)
{
  for (auto i = 0; i < 3; ++i)
    to[i] += from[i];

  return to;
}

template<typename Real>
Vector3<Real>& operator-=(Vector3<Real>& to, const Vector3<Real>& from)
{
  for (auto i = 0; i < 3; ++i)
    to[i] -= from[i];

  return to;
}

template<typename Real>
Vector3<Real>& operator*=(Vector3<Real>& to, const Vector3<Real>& from)
{
  for (auto i = 0; i < 3; ++i)
    to[i] *= from[i];

  return to;
}

template<typename Real>
Vector3<Real>& operator*=(Vector3<Real>& to, const Real& scalar)
{
  for (auto i = 0; i < 3; ++i)
    to[i] *= scalar;

  return to;
}

template<typename Real>
Vector3<Real>& operator/=(Vector3<Real>& to, const Real& scalar)
{
  assert(scalar != 0 && "Can not divide vector by 0");

  for (auto i = 0; i < 3; ++i)
    to[i] /= scalar;

  return to;
}



template<typename Real>
Vector3<Real> operator-(const Vector3<Real>& vec)
{
  return Vector3<Real>(-vec[0], -vec[1], -vec[2]);
}

template<typename Real>
Vector3<Real> operator+(const Vector3<Real>& vec1, const Vector3<Real>& vec2)
{
  auto tmp = vec1;
  tmp += vec2;
  return tmp;
}

template<typename Real>
Vector3<Real> operator-(const Vector3<Real>& vec1, const Vector3<Real>& vec2)
{
  auto tmp = vec1;
  tmp -= vec2;
  return tmp;
}

template<typename Real>
Vector3<Real> operator*(const Vector3<Real>& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp *= scalar;
  return tmp;
}

template<typename Real>
Vector3<Real> operator*(const Real& scalar, const Vector3<Real>& vec)
{
  return vec * scalar;
}

template<typename Real>
Vector3<Real> operator*(const Vector3<Real>& vec1, const Vector3<Real>& vec2)
{
  auto tmp = vec1;
  tmp *= vec2;
  return tmp;
}

template<typename Real>
Vector3<Real> operator/(const Vector3<Real>& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp /= scalar;
  return tmp;
}

template<typename Real>
bool operator==(const Vector3<Real>& vec1, const Vector3<Real>& vec2)
{
  return (vec1[0] == vec2[0] && vec1[1] == vec2[1] && vec1[2] == vec2[2]);
}

template<typename Real>
bool operator!=(const Vector3<Real>& vec1, const Vector3<Real>& vec2)
{
  return !(vec1 == vec2);
}
}
#endif // MATH_VECTOR3_H_INCLUDED
