#ifndef MATH_VECTOR4_H_INCLUDED
#define MATH_VECTOR4_H_INCLUDED

#include "config.h"
#include "vector3.h"

#include <cassert>
#include <cmath>

namespace Math
{
  template<typename Real>
  class Vector4
  {
    public:
      Real x;
      Real y;
      Real z;
      Real w;

    public:
      explicit Vector4();
      explicit Vector4(const Real& x, const Real& y, const Real& z, const Real& w);
      explicit Vector4(const Real data[4]);
      explicit Vector4(const Vector3<Real>& vec);

      Vector4& operator=(const Real data[4]);
      Vector4& operator=(const Vector3<Real>& vec);

      Real& operator[](const size_t& i);
      Real operator[](const size_t& i) const;
      operator Real*();
      operator const Real*() const;

      Vector4& operator+=(const Vector4& vec);
      Vector4& operator-=(const Vector4& vec);
      Vector4& operator*=(const Vector4& vec);

      Vector4& operator*=(const Real& scalar);
      Vector4& operator/=(const Real& scalar);

      Real length() const;
      Real lengthSquared() const;

      Real dot(const Vector4& vec) const;

      Vector4& normalize();

      static const Vector4 ZERO;
      static const Vector4 E1;
      static const Vector4 E2;
      static const Vector4 E3;
      static const Vector4 E4;
  };

  typedef Vector4<float>  Vec4f;
  typedef Vector4<double> Vec4d;
  typedef Vector4<int>    Vec4i;
  typedef Vector4<uint>   Vec4u;

  template<typename Real>
  Vector4<Real> operator-(const Vector4<Real>& vec);

  template<typename Real>
  Vector4<Real> operator+(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2);

  template<typename Real>
  Vector4<Real> operator-(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2);

  template<typename Real>
  Vector4<Real> operator*(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2);

  template<typename Real>
  Vector4<Real> operator*(const Vector4<Real>& vec, const Real& scalar);

  template<typename Real>
  Vector4<Real> operator*(const Real& scalar, const Vector4<Real>& vec);

  template<typename Real>
  Vector4<Real> operator/(const Vector4<Real>& vec, const Real& scalar);

  template<typename Real>
  bool operator==(const Vector4<Real>& vec1, const Vector4<Real>& vec2);

  template<typename Real>
  bool operator!=(const Vector4<Real>& vec1, const Vector4<Real>& vec2);
}


// Implementation
template<typename Real>
Math::Vector4<Real>::Vector4()
  : x(0), y(0), z(0), w(0)
{ }

template<typename Real>
Math::Vector4<Real>::Vector4(const Real& x, const Real& y, const Real& z, const Real& w)
  : x(x), y(y), z(z), w(w)
{ }

template<typename Real>
Math::Vector4<Real>::Vector4(const Real data[4])
  : x(data[0]), y(data[1]), z(data[2]), w(data[3])
{ }

template<typename Real>
Math::Vector4<Real>::Vector4(const Vector3<Real>& vec)
  : x(vec[0]), y(vec[1]), z(vec[2]), w(1)
{ }

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator=(const Real data[4])
{
  x = data[0];
  y = data[1];
  z = data[2];
  w = data[3];

  return *this;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator=(const Vector3<Real>& vec)
{
  x = vec[0];
  y = vec[1];
  z = vec[2];
  w = 1;

  return *this;
}

template<typename Real>
Real& Math::Vector4<Real>::operator[](const size_t& i)
{
  assert(i < 4 && "Index operator out of range");

  return(&x)[i];
}

template<typename Real>
Real Math::Vector4<Real>::operator[](const size_t& i) const
{
  assert(i < 4 && "Index operator out of range");

  return(&x)[i];
}

template<typename Real>
Math::Vector4<Real>::operator Real*()
{
  return &x;
}

template<typename Real>
Math::Vector4<Real>::operator const Real*() const
{
  return &x;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator+=(const Vector4<Real>& vec)
{
  x += vec.x;
  y += vec.y;
  z += vec.z;
  w += vec.w;

  return *this;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator-=(const Vector4<Real>& vec)
{
  x -= vec.x;
  y -= vec.y;
  z -= vec.z;
  w -= vec.w;

  return *this;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator*=(const Vector4<Real>& vec)
{
  x *= vec.x;
  y *= vec.y;
  z *= vec.z;
  w *= vec.w;

  return *this;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator*=(const Real& scalar)
{
  x *= scalar;
  y *= scalar;
  z *= scalar;
  w *= scalar;

  return *this;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator/=(const Real& scalar)
{
  assert(scalar != 0 && "Can not divide vector by zero");

  x /= scalar;
  y /= scalar;
  z /= scalar;
  w /= scalar;

  return *this;
}

template<typename Real>
Real Math::Vector4<Real>::length() const
{
  return std::sqrt(this->lengthSquared());
}

template<typename Real>
Real Math::Vector4<Real>::lengthSquared() const
{
  return dot(*this);
}

template<typename Real>
Real Math::Vector4<Real>::dot(const Vector4<Real>& vec) const
{
  return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::normalize()
{
  Real len = length();

  assert(len != 0 && "Can not normalize zero vector");

  return *this /= len;
}

template<typename Real>
Math::Vector4<Real> Math::operator-(const Vector4<Real>& vec)
{
  return Vector4<Real>(-vec.x, -vec.y, -vec.z, -vec.w);
}

template<typename Real>
Math::Vector4<Real> Math::operator+(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2)
{
  auto result = vec_1;
  result += vec_2;
  return result;
}

template<typename Real>
Math::Vector4<Real> Math::operator-(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2)
{
  auto result = vec_1;
  result -= vec_2;
  return result;
}

template<typename Real>
Math::Vector4<Real> Math::operator*(const Vector4<Real>& vec_1, const Vector4<Real>& vec_2)
{
  auto tmp = vec_1;
  tmp *= vec_2;
  return tmp;
}

template<typename Real>
Math::Vector4<Real> Math::operator*(const Vector4<Real>& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp *= scalar;
  return tmp;
}

template<typename Real>
Math::Vector4<Real> Math::operator*(const Real& scalar, const Vector4<Real>& vec)
{
  return vec * scalar;
}

template<typename Real>
Math::Vector4<Real> Math::operator/(const Vector4<Real>& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp /= scalar;
  return tmp;
}

template<typename Real>
bool Math::operator==(const Vector4<Real>& vec1, const Vector4<Real>& vec2)
{
  return(vec1.x == vec2.x &&
      vec1.y == vec2.y &&
      vec1.z == vec2.z &&
      vec1.w == vec2.w);
}

template<typename Real>
bool Math::operator!=(const Vector4<Real>& vec1, const Vector4<Real>& vec2)
{
  return !(vec1 == vec2);
}

#endif // MATH_VECTOR4_H_INCLUDED
