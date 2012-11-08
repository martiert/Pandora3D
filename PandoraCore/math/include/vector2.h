#ifndef MATH_VECTOR2_H_INCLUDED
#define MATH_VECTOR2_H_INCLUDED

#include "config.h"

#include <cassert>
#include <cmath>

namespace Math
{
  template<typename Real>
  struct Vector2
  {
      explicit Vector2();
      explicit Vector2(const Real x, const Real y);
      explicit Vector2(const Real data[2]);
      Vector2& operator=(const Real data[2]);

      Real& operator[](const size_t& i);
      Real operator[](const size_t& i) const;

      static const Vector2 ZERO;
      static const Vector2 E1;
      static const Vector2 E2;
    private:
      Real data[2];
  };

  typedef Vector2<float>    Vec2f;
  typedef Vector2<double>   Vec2d;
  typedef Vector2<int>      Vec2i;
  typedef Vector2<uint>     Vec2u;

  template<typename Real>   Real length(const Vector2<Real>& vector);
  template<typename Real>   Real lengthSquared(const Vector2<Real>& vector);
  template<typename Real>   Real dot(const Vector2<Real>& left, const Vector2<Real>& right);
  template<typename Real>   Vector2<Real> perp(const Vector2<Real>& vector);
  template<typename Real>   void normalize(Vector2<Real>& vector);
  template<typename Real>   void generateOrthonormalBasis(Vector2<Real>& vec1, Vector2<Real>& vec2);

  template<typename Real>   Vector2<Real>& operator+=(Vector2<Real>& to, const Vector2<Real>& from);
  template<typename Real>   Vector2<Real>& operator-=(Vector2<Real>& to, const Vector2<Real>& from);
  template<typename Real>   Vector2<Real>& operator*=(Vector2<Real>& to, const Vector2<Real>& from);
  template<typename Real>   Vector2<Real>& operator*=(Vector2<Real>& to, const Real& scalar);
  template<typename Real>   Vector2<Real>& operator/=(Vector2<Real>& to, const Real& scalar);

  template<typename Real>   Vector2<Real> operator-(const Vector2<Real>& vec);
  template<typename Real>   Vector2<Real> operator+(const Vector2<Real>& vec1, const Vector2<Real>& vec2);
  template<typename Real>   Vector2<Real> operator-(const Vector2<Real>& vec1, const Vector2<Real>& vec2);
  template<typename Real>   Vector2<Real> operator*(const Vector2<Real>& vec1, const Vector2<Real>& vec2);
  template<typename Real>   Vector2<Real> operator*(const Vector2<Real>& vec, const Real real);
  template<typename Real>   Vector2<Real> operator*(const Real real, const Vector2<Real>& vec);
  template<typename Real>   Vector2<Real> operator/(const Vector2<Real>& vec, const Real real);

  template<typename Real>   bool operator==(const Vector2<Real>& vec1, const Vector2<Real>& vec2);
  template<typename Real>   bool operator!=(const Vector2<Real>& vec1, const Vector2<Real>& vec2);
}

// Implementation

namespace Math
{
template<typename Real>
Vector2<Real>::Vector2()
  : data {0, 0}
{ }

template<typename Real>
Vector2<Real>::Vector2(const Real x, const Real y)
  : data {x, y}
{ }

template<typename Real>
Vector2<Real>::Vector2(const Real array[2])
  : data {array[0], array[1]}
{ }

template<typename Real>
Vector2<Real>& Vector2<Real>::operator=(const Real array[2])
{
  data[0] = array[0];
  data[1] = array[1];

  return *this;
}

template<typename Real>
Real& Vector2<Real>::operator[](const size_t& i)
{
  assert(i < 2 && "Index operator out of range");

  return data[i];
}

template<typename Real>
Real Vector2<Real>::operator[](const size_t& i) const
{
  assert(i < 2 && "Index operator out of range");

  return data[i];
}

template<typename Real>
Real length(const Vector2<Real>& vector)
{
  return std::sqrt(lengthSquared(vector));
}

template<typename Real>
Real lengthSquared(const Vector2<Real>& vector)
{
  return dot(vector, vector);
}

template<typename Real>
Real dot(const Vector2<Real>& left, const Vector2<Real>& right)
{
  return left[0] * right[0] + left[1] * right[1];
}

template<typename Real>
Vector2<Real> perp(const Vector2<Real>& perp)
{
  return Vector2<Real>(perp[1], -perp[0]);
}

template<typename Real>
void normalize(Vector2<Real>& vector)
{
  Real len = length(vector);

  assert(len != 0 && "Can not normalize zero vector");

  vector /= len;
}

template<typename Real>
void generateOrthonormalBasis(Vector2<Real>& vec1, Vector2<Real>& vec2)
{
  assert(vec1 != Vector2<Real>::ZERO &&
         vec2 != Vector2<Real>::ZERO &&
         "Can not make orthonormal basis from a zero vector");
  assert(vec1 != vec2 && "Can not make orthonormal basis from equal vectors");

  normalize(vec1);
  vec2 = vec2 -(dot(vec1, vec2)) * vec1;
  normalize(vec2);
}

template<typename Real>
Vector2<Real>& operator+=(Vector2<Real>& to, const Vector2<Real>& from)
{
  to[0] += from[0];
  to[1] += from[1];

  return to;
}

template<typename Real>
Vector2<Real>& operator-=(Vector2<Real>& to, const Vector2<Real>& from)
{
  to[0] -= from[0];
  to[1] -= from[1];

  return to;
}

template<typename Real>
Vector2<Real>& operator*=(Vector2<Real>& to, const Vector2<Real>& from)
{
  to[0] *= from[0];
  to[1] *= from[1];

  return to;
}

template<typename Real>
Vector2<Real>& operator*=(Vector2<Real>& to, const Real& scalar)
{
  to[0] *= scalar;
  to[1] *= scalar;

  return to;
}

template<typename Real>
Vector2<Real>& operator/=(Vector2<Real>& to, const Real& scalar)
{
  assert(scalar != 0 && "Can not divide vector by zero");

  to[0] /= scalar;
  to[1] /= scalar;

  return to;
}



template<typename Real>
Vector2<Real> operator-(const Vector2<Real>& vec)
{
  return Vector2<Real>(-vec[0], -vec[1]);
}

template<typename Real>
Vector2<Real> operator+(const Vector2<Real>& vec1, const Vector2<Real>& vec2)
{
  auto result = vec1;
  result += vec2;
  return result;
}

template<typename Real>
Vector2<Real> operator-(const Vector2<Real>& vec1, const Vector2<Real>& vec2)
{
  auto result = vec1;
  result -= vec2;
  return result;
}

template<typename Real>
Vector2<Real> operator*(const Vector2<Real>& vec1, const Vector2<Real>& vec2)
{
  auto result = vec1;
  result *= vec2;
  return result;
}

template<typename Real>
Vector2<Real> operator*(const Vector2<Real>& vec, const Real scalar)
{
  auto result = vec;
  result *= scalar;
  return result;
}

template<typename Real>
Vector2<Real> operator/(const Vector2<Real>& vec, const Real scalar)
{
  auto res = vec;
  res /= scalar;
  return res;
}

template<typename Real>
Vector2<Real> operator*(const Real scalar, const Vector2<Real>& vec)
{
  return vec * scalar;
}

template<typename Real>
bool operator==(const Vector2<Real>& vec1, const Vector2<Real>& vec2)
{
  return(vec1[0] == vec2[0] && vec1[1] == vec2[1]);
}

template<typename Real>
bool operator!=(const Vector2<Real>& vec1, const Vector2<Real>& vec2)
{
  return !(vec1 == vec2);
}
}

#endif // MATH_VECTOR2_H_INCLUDED
