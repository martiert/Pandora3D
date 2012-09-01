#ifndef MATH_VECTOR2_H_INCLUDED
#define MATH_VECTOR2_H_INCLUDED

#include "config.h"

#include <exception>
#include <sstream>
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
      Vector2 ();
      Vector2 (const Real x, const Real y);
      Vector2 (const Real data[2]);

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

    public:
      class can_not_make_orthonormal_basis_from_equal_vectors_exception : public std::exception
      { };

      class can_not_make_orthonormal_basis_with_zero_vector_exception : public std::exception
      { };

      class can_not_normalize_zero_vector_exception : public std::exception
      { };

      class division_by_zero_exception : public std::exception
      { };

      class index_operator_out_of_range_exception : public std::exception
      {
        public:
          index_operator_out_of_range_exception (const size_t& i);

          virtual const char* what () const throw ();
        private:
          size_t index;
      };
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
Real& Math::Vector2<Real>::operator[] (const size_t& i)
{
  if (i > 1)
    throw index_operator_out_of_range_exception (i);

  return (&x)[i];
}

template<typename Real>
Real Math::Vector2<Real>::operator[] (const size_t& i) const
{
  if (i > 1)
    throw index_operator_out_of_range_exception (i);

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
  if (!scalar)
    throw division_by_zero_exception ();

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

  if (len == 0)
    throw can_not_normalize_zero_vector_exception ();

  *this /= len;
}

template<typename Real>
void Math::Vector2<Real>::generateOrthonormalBasis (Vector2<Real>& vec1, Vector2<Real>& vec2)
{
  if ((vec1.x == 0 && vec1.y == 0) || (vec2.x == 0 && vec2.y == 0))
    throw can_not_make_orthonormal_basis_with_zero_vector_exception ();

  if (vec1 == vec2)
    throw can_not_make_orthonormal_basis_from_equal_vectors_exception () ;

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

template<typename Real>
Math::Vector2<Real>::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& i)
  : index (i)
{}

template<typename Real>
const char* Math::Vector2<Real>::index_operator_out_of_range_exception::what () const throw ()
{
  std::stringstream out;
  out << "Tried to access index: " << index;
  return out.str ().c_str ();
}

#endif // MATH_VECTOR2_H_INCLUDED
