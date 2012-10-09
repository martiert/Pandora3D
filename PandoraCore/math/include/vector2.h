#ifndef MATH_VECTOR2_H_INCLUDED
#define MATH_VECTOR2_H_INCLUDED

#include "config.h"

#include <cassert>
#include <cmath>

namespace Math
{
  template<typename Real>
  class Vector2
  {
    public:
      Real x;
      Real y;

    public:
      explicit Vector2 ();
      explicit Vector2 (const Real x, const Real y);
      explicit Vector2 (const Real data[2]);

      Vector2& operator= (const Real data[2]);

      Real& operator[] (const size_t& i);
      Real operator[] (const size_t& i) const;
      operator Real* ();
      operator const Real* () const;

      Vector2& operator+= (const Vector2& other);
      Vector2& operator-= (const Vector2& other);
      Vector2& operator*= (const Vector2& other);
      Vector2& operator*= (const Real& scalar);
      Vector2& operator/= (const Real& scalar);

      Real length () const;
      Real lengthSquared () const;

      Real dot (const Vector2& other) const;
      Vector2 perp () const;

      void normalize ();

      static void generateOrthonormalBasis (Vector2& vec1, Vector2& vec2);

      static const Vector2 ZERO;
      static const Vector2 E1;
      static const Vector2 E2;
  };

  typedef Vector2<float>    Vec2f;
  typedef Vector2<double>   Vec2d;
  typedef Vector2<int>      Vec2i;
  typedef Vector2<uint>     Vec2u;

  template<typename Real>
  Vector2<Real> operator- (const Vector2<Real>& vec);

  template<typename Real>
  Vector2<Real> operator+ (const Vector2<Real>& vec1, const Vector2<Real>& vec2);

  template<typename Real>
  Vector2<Real> operator- (const Vector2<Real>& vec1, const Vector2<Real>& vec2);

  template<typename Real>
  Vector2<Real> operator* (const Vector2<Real>& vec1, const Vector2<Real>& vec2);

  template<typename Real>
  Vector2<Real> operator* (const Vector2<Real>& vec, const Real real);

  template<typename Real>
  Vector2<Real> operator* (const Real real, const Vector2<Real>& vec);

  template<typename Real>
  Vector2<Real> operator/ (const Vector2<Real>& vec, const Real real);

  template<typename Real>
  bool operator== (const Vector2<Real>& vec1, const Vector2<Real>& vec2);

  template<typename Real>
  bool operator!= (const Vector2<Real>& vec1, const Vector2<Real>& vec2);
}

// Implementation
template<typename Real>
Math::Vector2<Real>::Vector2 ()
  : x (0), y (0)
{ }

template<typename Real>
Math::Vector2<Real>::Vector2 (const Real x, const Real y)
  : x (x), y (y)
{ }

template<typename Real>
Math::Vector2<Real>::Vector2 (const Real array[2])
  : x (array[0]), y (array[1])
{ }

template<typename Real>
Math::Vector2<Real>& Math::Vector2<Real>::operator= (const Real data[2])
{
  x = data[0];
  y = data[1];

  return *this;
}

template<typename Real>
Real& Math::Vector2<Real>::operator[] (const size_t& i)
{
  assert (i < 2 && "Index operator is out of range");

  return (&x)[i];
}

template<typename Real>
Real Math::Vector2<Real>::operator[] (const size_t& i) const
{
  assert (i < 2 && "Index operator is out of range");

  return (&x)[i];
}

template<typename Real>
Math::Vector2<Real>::operator Real* ()
{
  return &x;
}

template<typename Real>
Math::Vector2<Real>::operator const Real* () const
{
  return &x;
}

template<typename Real>
Math::Vector2<Real>& Math::Vector2<Real>::operator+= (const Math::Vector2<Real>& other)
{
  x += other.x;
  y += other.y;

  return (*this);
}

template<typename Real>
Math::Vector2<Real>& Math::Vector2<Real>::operator-= (const Math::Vector2<Real>& other)
{
  x -= other.x;
  y -= other.y;

  return (*this);
}

template<typename Real>
Math::Vector2<Real>& Math::Vector2<Real>::operator*= (const Math::Vector2<Real>& other)
{
  x *= other.x;
  y *= other.y;

  return (*this);
}

template<typename Real>
Math::Vector2<Real>& Math::Vector2<Real>::operator*= (const Real& scalar)
{
  x *= scalar;
  y *= scalar;

  return (*this);
}

template<typename Real>
Math::Vector2<Real>& Math::Vector2<Real>::operator/= (const Real& scalar)
{
  assert (scalar != 0 && "Can not divide vector by zero");

  x /= scalar;
  y /= scalar;

  return (*this);
}

template<typename Real>
Real Math::Vector2<Real>::lengthSquared () const
{
  return dot (*this);
}

template<typename Real>
Real Math::Vector2<Real>::length () const
{
  return std::sqrt (lengthSquared ());
}

template<typename Real>
Real Math::Vector2<Real>::dot (const Math::Vector2<Real>& other) const
{
  return x * other.x + y * other.y;
}

template<typename Real>
Math::Vector2<Real> Math::Vector2<Real>::perp () const
{
  return Vector2<Real> (y, -x);
}

template<typename Real>
void Math::Vector2<Real>::normalize ()
{
  Real len = length ();

  assert (len != 0 && "Can not normalize zero vector");

  *this /= len;
}

template<typename Real>
void Math::Vector2<Real>::generateOrthonormalBasis (Vector2<Real>& vec1, Vector2<Real>& vec2)
{
  assert (vec1 != ZERO && vec2 != ZERO && "Can not make orthonormal basis from a zero vector");
  assert (vec1 != vec2 && "Can not make orthonormal basis from equal vector");

  vec1.normalize ();
  vec2 = vec2 - (vec1.dot (vec2)) * vec1;
  vec2.normalize ();
}

template<typename Real>
Math::Vector2<Real> Math::operator- (const Vector2<Real>& vec)
{
  return Vector2<Real> (-vec.x, -vec.y);
}

template<typename Real>
Math::Vector2<Real> Math::operator+ (const Vector2<Real>& vec1, const Vector2<Real>& vec2)
{
  return Vector2<Real> (vec1.x + vec2.x, vec1.y + vec2.y);
}

template<typename Real>
Math::Vector2<Real> Math::operator- (const Vector2<Real>& vec1, const Vector2<Real>& vec2)
{
  return Vector2<Real> (vec1.x - vec2.x, vec1.y - vec2.y);
}

template<typename Real>
Math::Vector2<Real> Math::operator* (const Vector2<Real>& vec1, const Vector2<Real>& vec2)
{
  return Vector2<Real> (vec1.x * vec2.x, vec1.y * vec2.y);
}

template<typename Real>
Math::Vector2<Real> Math::operator* (const Vector2<Real>& vec, const Real real)
{
  return Vector2<Real> (vec.x * real, vec.y * real);
}

template<typename Real>
Math::Vector2<Real> Math::operator/ (const Vector2<Real>& vec, const Real real)
{
  auto res = vec;
  res /= real;
  return res;
}

template<typename Real>
Math::Vector2<Real> Math::operator* (const Real real, const Vector2<Real>& vec)
{
  return Vector2<Real> (vec.x * real, vec.y * real);
}

template<typename Real>
bool Math::operator== (const Vector2<Real>& vec1, const Vector2<Real>& vec2)
{
  return (vec1.x == vec2.x && vec1.y == vec2.y);
}

template<typename Real>
bool Math::operator!= (const Vector2<Real>& vec1, const Vector2<Real>& vec2)
{
  return !(vec1 == vec2);
}

#endif // MATH_VECTOR2_H_INCLUDED
