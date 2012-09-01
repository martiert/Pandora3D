#ifndef MATH_VECTOR4_H_INCLUDED
#define MATH_VECTOR4_H_INCLUDED

#include "config.h"
#include "vector3.h"

#include <exception>
#include <sstream>
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
      Vector4 ();
      Vector4 (const Real& x, const Real& y, const Real& z, const Real& w);
      Vector4 (const Real data[4]);
      Vector4 (const Vector3<Real>& vec);

      Real& operator[] (const size_t& i);
      Real operator[] (const size_t& i) const;
      operator Real* ();
      operator const Real* () const;

      Vector4& operator+= (const Vector4& vec);
      Vector4& operator-= (const Vector4& vec);
      Vector4& operator*= (const Vector4& vec);

      Vector4& operator*= (const Real& scalar);
      Vector4& operator/= (const Real& scalar);

      Real length () const;
      Real lengthSquared () const;

      Real dot (const Vector4& vec) const;

      Vector4& normalize ();

      static const Vector4 ZERO;
      static const Vector4 E1;
      static const Vector4 E2;
      static const Vector4 E3;
      static const Vector4 E4;

    public:
      class normalizing_zero_vector_exception : public std::exception {};

      class division_by_zero_exception : public std::exception { };

      class index_operator_out_of_range_exception : public std::exception
    {
      public:
        index_operator_out_of_range_exception (const size_t& i);

        virtual const char* what () const throw ();

      private:
        size_t index;
    };
  };

  typedef Vector4<float>  Vec4f;
  typedef Vector4<double> Vec4d;
  typedef Vector4<int>    Vec4i;
  typedef Vector4<uint>   Vec4u;

  template<typename Real>
  Vector4<Real> operator- (const Vector4<Real>& vec);

  template<typename Real>
  Vector4<Real> operator+ (const Vector4<Real>& vec_1, const Vector4<Real>& vec_2);

  template<typename Real>
  Vector4<Real> operator- (const Vector4<Real>& vec_1, const Vector4<Real>& vec_2);

  template<typename Real>
  Vector4<Real> operator* (const Vector4<Real>& vec_1, const Vector4<Real>& vec_2);

  template<typename Real>
  Vector4<Real> operator* (const Vector4<Real>& vec, const Real& scalar);

  template<typename Real>
  Vector4<Real> operator* (const Real& scalar, const Vector4<Real>& vec);

  template<typename Real>
  Vector4<Real> operator/ (const Vector4<Real>& vec, const Real& scalar);

  template<typename Real>
  bool operator== (const Vector4<Real>& vec1, const Vector4<Real>& vec2);

  template<typename Real>
  bool operator!= (const Vector4<Real>& vec1, const Vector4<Real>& vec2);
}


// Implementation
template<typename Real>
Math::Vector4<Real>::Vector4 ()
  : x (0), y (0), z (0), w (0)
{ }

template<typename Real>
Math::Vector4<Real>::Vector4 (const Real& x, const Real& y, const Real& z, const Real& w)
  : x (x), y (y), z (z), w (w)
{ }

template<typename Real>
Math::Vector4<Real>::Vector4 (const Real data[4])
  : x (data[0]), y (data[1]), z (data[2]), w (data[3])
{ }

template<typename Real>
Math::Vector4<Real>::Vector4 (const Vector3<Real>& vec)
  : x (vec.x), y (vec.y), z (vec.z), w (1)
{ }

template<typename Real>
Real& Math::Vector4<Real>::operator[] (const size_t& i)
{
  if (i > 3)
    throw index_operator_out_of_range_exception (i);

  return (&x)[i];
}

template<typename Real>
Real Math::Vector4<Real>::operator[] (const size_t& i) const
{
  if (i > 3)
    throw index_operator_out_of_range_exception (i);

  return (&x)[i];
}

template<typename Real>
Math::Vector4<Real>::operator Real* ()
{
  return &x;
}

template<typename Real>
Math::Vector4<Real>::operator const Real* () const
{
  return &x;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator+= (const Vector4<Real>& vec)
{
  x += vec.x;
  y += vec.y;
  z += vec.z;
  w += vec.w;

  return *this;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator-= (const Vector4<Real>& vec)
{
  x -= vec.x;
  y -= vec.y;
  z -= vec.z;
  w -= vec.w;

  return *this;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator*= (const Vector4<Real>& vec)
{
  x *= vec.x;
  y *= vec.y;
  z *= vec.z;
  w *= vec.w;

  return *this;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator*= (const Real& scalar)
{
  x *= scalar;
  y *= scalar;
  z *= scalar;
  w *= scalar;

  return *this;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::operator/= (const Real& scalar)
{
  if (scalar == 0)
    throw division_by_zero_exception ();

  x /= scalar;
  y /= scalar;
  z /= scalar;
  w /= scalar;

  return *this;
}

template<typename Real>
Real Math::Vector4<Real>::length () const
{
  return std::sqrt (this->lengthSquared ());
}

template<typename Real>
Real Math::Vector4<Real>::lengthSquared () const
{
  return dot (*this);
}

template<typename Real>
Real Math::Vector4<Real>::dot (const Vector4<Real>& vec) const
{
  return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
}

template<typename Real>
Math::Vector4<Real>& Math::Vector4<Real>::normalize ()
{
  Real len = length ();

  if (len == 0)
    throw normalizing_zero_vector_exception ();

  return *this /= len;
}

template<typename Real>
Math::Vector4<Real> Math::operator- (const Vector4<Real>& vec)
{
  return Vector4<Real> (-vec.x, -vec.y, -vec.z, -vec.w);
}

template<typename Real>
Math::Vector4<Real> Math::operator+ (const Vector4<Real>& vec_1, const Vector4<Real>& vec_2)
{
  auto result = vec_1;
  result += vec_2;
  return result;
}

template<typename Real>
Math::Vector4<Real> Math::operator- (const Vector4<Real>& vec_1, const Vector4<Real>& vec_2)
{
  auto result = vec_1;
  result -= vec_2;
  return result;
}

template<typename Real>
Math::Vector4<Real> Math::operator* (const Vector4<Real>& vec_1, const Vector4<Real>& vec_2)
{
  auto tmp = vec_1;
  tmp *= vec_2;
  return tmp;
}

template<typename Real>
Math::Vector4<Real> Math::operator* (const Vector4<Real>& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp *= scalar;
  return tmp;
}

template<typename Real>
Math::Vector4<Real> Math::operator* (const Real& scalar, const Vector4<Real>& vec)
{
  return vec * scalar;
}

template<typename Real>
Math::Vector4<Real> Math::operator/ (const Vector4<Real>& vec, const Real& scalar)
{
  auto tmp = vec;
  tmp /= scalar;
  return tmp;
}

template<typename Real>
bool Math::operator== (const Vector4<Real>& vec1, const Vector4<Real>& vec2)
{
  return (vec1.x == vec2.x &&
      vec1.y == vec2.y &&
      vec1.z == vec2.z &&
      vec1.w == vec2.w);
}

template<typename Real>
bool Math::operator!= (const Vector4<Real>& vec1, const Vector4<Real>& vec2)
{
  return !(vec1 == vec2);
}

template<typename Real>
Math::Vector4<Real>::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& i)
  : index (i)
{ }

template<typename Real>
const char* Math::Vector4<Real>::index_operator_out_of_range_exception::what () const throw ()
{
  std::stringstream out;
  out << "Tried to access index: " << index;
  return out.str ().c_str ();
}
#endif // MATH_VECTOR4_H_INCLUDED
