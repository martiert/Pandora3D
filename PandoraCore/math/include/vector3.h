#ifndef MATH_VECTOR3_H_INCLUDED
#define MATH_VECTOR3_H_INCLUDED

#include "config.h"

#include <cassert>
#include <cmath>

namespace Math
{
  template<typename Real>
  class Vector3
  {
    public:
      Real x;
      Real y;
      Real z;

    public:
      explicit Vector3 ();
      explicit Vector3 (const Real& x, const Real& y, const Real& z);
      explicit Vector3 (const Real data[3]);

      Vector3& operator= (const Real data[3]);

      Real& operator[] (const size_t& i);
      Real operator[] (const size_t& i) const;
      operator Real* ();
      operator const Real* () const;

      Vector3& operator+= (const Vector3& vec);
      Vector3& operator-= (const Vector3& vec);
      Vector3& operator*= (const Vector3& vec);
      Vector3& operator*= (const Real& scalar);
      Vector3& operator/= (const Real& scalar);

      Real dot (const Vector3& vec) const;

      Real length () const;
      Real lengthSquared () const;

      void normalize ();

      Vector3 cross (const Vector3& other) const;

      static void generateOrthonormalBasis (Vector3& vec1, Vector3& vec2, Vector3& vec3);

      static const Vector3 ZERO;
      static const Vector3 E1;
      static const Vector3 E2;
      static const Vector3 E3;
  };

  typedef Vector3<float>  Vec3f;
  typedef Vector3<double> Vec3d;
  typedef Vector3<int>    Vec3i;
  typedef Vector3<uint>   Vec3u;

  template<typename Real>
  Vector3<Real> operator- (const Vector3<Real>& vec);

  template<typename Real>
  Vector3<Real> operator+ (const Vector3<Real>& vec1, const Vector3<Real>& vec2);

  template<typename Real>
  Vector3<Real> operator- (const Vector3<Real>& vec1, const Vector3<Real>& vec2);

  template<typename Real>
  Vector3<Real> operator* (const Vector3<Real>& vec, const Real& scalar);

  template<typename Real>
  Vector3<Real> operator* (const Real& scalar, const Vector3<Real>& vec);

  template<typename Real>
  Vector3<Real> operator* (const Vector3<Real>& vec1, const Vector3<Real>& vec2);

  template<typename Real>
  Vector3<Real> operator/ (const Vector3<Real>& vec, const Real& scalar);

  template<typename Real>
  bool operator== (const Vector3<Real>& vec1, const Vector3<Real>& vec2);

  template<typename Real>
  bool operator!= (const Vector3<Real>& vec1, const Vector3<Real>& vec2);
}

// Implementation
template<typename Real>
Math::Vector3<Real>::Vector3 ()
  : x (0), y (0), z (0)
{}

template<typename Real>
Math::Vector3<Real>::Vector3 (const Real& x, const Real& y, const Real& z)
  : x (x), y (y), z (z)
{}

template<typename Real>
Math::Vector3<Real>::Vector3 (const Real data[3])
  : x (data[0]), y (data[1]), z (data[2])
{}

template<typename Real>
Math::Vector3<Real>& Math::Vector3<Real>::operator= (const Real data[3])
{
  x = data[0];
  y = data[1];
  z = data[2];
  return *this;
}

template<typename Real>
Real& Math::Vector3<Real>::operator[] (const size_t& i)
{
  assert (i < 3 && "Index operator out of range");

  return (&x)[i];
}

template<typename Real>
Real Math::Vector3<Real>::operator[] (const size_t& i) const
{
  assert (i < 3 && "Index operator out of range");

  return (&x)[i];
}

template<typename Real>
Math::Vector3<Real>::operator Real* ()
{
  return &x;
}

template<typename Real>
Math::Vector3<Real>::operator const Real* () const
{
  return &x;
}

template<typename Real>
Math::Vector3<Real>& Math::Vector3<Real>::operator+= (const Math::Vector3<Real>& vec)
{
  x += vec.x;
  y += vec.y;
  z += vec.z;

  return *this;
}

template<typename Real>
Math::Vector3<Real>& Math::Vector3<Real>::operator-= (const Math::Vector3<Real>& vec)
{
  x -= vec.x;
  y -= vec.y;
  z -= vec.z;

  return *this;
}

template<typename Real>
Math::Vector3<Real>& Math::Vector3<Real>::operator*= (const Math::Vector3<Real>& vec)
{
  x *= vec.x;
  y *= vec.y;
  z *= vec.z;

  return *this;
}

template<typename Real>
Math::Vector3<Real>& Math::Vector3<Real>::operator*= (const Real& scalar)
{
  x *= scalar;
  y *= scalar;
  z *= scalar;

  return *this;
}

template<typename Real>
Math::Vector3<Real>& Math::Vector3<Real>::operator/= (const Real& scalar)
{
  assert (scalar != 0 && "Can not divide vector by 0");

  x /= scalar;
  y /= scalar;
  z /= scalar;

  return *this;
}

template<typename Real>
Real Math::Vector3<Real>::dot (const Math::Vector3<Real>& vec) const
{
  return (x * vec.x + y * vec.y + z * vec.z);
}

template<typename Real>
Real Math::Vector3<Real>::length () const
{
  return std::sqrt (lengthSquared ());
}

template<typename Real>
Real Math::Vector3<Real>::lengthSquared () const
{
  return dot (*this);
}

template<typename Real>
void Math::Vector3<Real>::normalize ()
{
  float len = length ();

  assert (len != 0 && "Can not normalize zero vector");

  *this /= len;
}

template<typename Real>
Math::Vector3<Real> Math::Vector3<Real>::cross (const Math::Vector3<Real>& other) const
{
  Vector3<Real> res;
  res.x = y * other.z - z * other.y;
  res.y = z * other.x - x * other.z;
  res.z = x * other.y - y * other.x;

  return res;
}

template<typename Real>
void Math::Vector3<Real>::generateOrthonormalBasis (Vector3<Real>& vec1, Vector3<Real>& vec2, Vector3<Real>& vec3)
{
  assert (vec1 != ZERO && vec2 != ZERO && vec3 != ZERO && "Can not make orthonormal basis with zero vectors");
  assert (vec1 != vec2 && vec1 != vec3 && vec2 != vec3 && "Can not make orthonormal basis with equal vectors");

  vec2 = vec1.cross (vec3);
  vec3 = vec1.cross (vec2);

  vec1.normalize ();
  vec2.normalize ();
  vec3.normalize ();
}

template<typename Real>
Math::Vector3<Real> Math::operator- (const Vector3<Real>& vec)
{
  return Vector3<Real> (-vec.x, -vec.y, -vec.z);
}

template<typename Real>
Math::Vector3<Real> Math::operator+ (const Vector3<Real>& vec1, const Vector3<Real>& vec2)
{
  auto tmp = vec1;
  tmp += vec2;
  return tmp;
}

template<typename Real>
Math::Vector3<Real> Math::operator- (const Vector3<Real>& vec1, const Vector3<Real>& vec2)
{
  auto tmp = vec1;
  tmp -= vec2;
  return tmp;
}

template<typename Real>
Math::Vector3<Real> Math::operator* (const Vector3<Real>& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp *= scalar;
  return tmp;
}

template<typename Real>
Math::Vector3<Real> Math::operator* (const Real& scalar, const Vector3<Real>& vec)
{
  return vec * scalar;
}

template<typename Real>
Math::Vector3<Real> Math::operator* (const Vector3<Real>& vec1, const Vector3<Real>& vec2)
{
  auto tmp = vec1;
  tmp *= vec2;
  return tmp;
}

template<typename Real>
Math::Vector3<Real> Math::operator/ (const Vector3<Real>& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp /= scalar;
  return tmp;
}

template<typename Real>
bool Math::operator== (const Vector3<Real>& vec1, const Vector3<Real>& vec2)
{
  return (vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z);
}

template<typename Real>
bool Math::operator!= (const Vector3<Real>& vec1, const Vector3<Real>& vec2)
{
  return !(vec1 == vec2);
}

#endif // MATH_VECTOR3_H_INCLUDED
