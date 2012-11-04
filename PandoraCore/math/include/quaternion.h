#ifndef MATH_QUATERNION_H_INCLUDED
#define MATH_QUATERNION_H_INCLUDED

#include "config.h"
#include "vector3.h"
#include "matrix4.h"

#include <cassert>
#include <cmath>

namespace Math
{
  template<typename Real>
  class Quaternion
  {
    public:
      explicit Quaternion();

      explicit Quaternion(const Real& w, const Real& x, const Real& y, const Real& z);

      explicit Quaternion(const Real array[4]);

      explicit Quaternion(const Real& scalar, const Vector3<Real>& imaginary_vector);

      explicit Quaternion(const Vector3<Real>& axis, const Real& angle);

      explicit Quaternion(const Matrix4<Real>& matrix);

      Real& w();
      Real& x();
      Real& y();
      Real& z();

      Real w() const;
      Real x() const;
      Real y() const;
      Real z() const;

      Quaternion operator+=(const Quaternion& other);
      Quaternion operator-=(const Quaternion& other);
      Quaternion operator*=(const Real& scalar);
      Quaternion operator/=(const Real& scalar);

      Matrix4<Real> create_matrix() const;

      Real norm() const;
      void normalize();

      Quaternion conjugate() const;
      Quaternion inverse() const;

      static Quaternion slerp(const Quaternion& from, const Quaternion& to, const Real& t);

    public:
      Real real;
      Vector3<Real> imag;

    protected:
      Matrix4<Real> create_matrix_with_scale(const Real& s) const;

      void create_quaternion_from_matrix_with_largest_u(const Matrix4<Real>& matrix);
      void create_quaternion_from_matrix_with_smallest_u(const Matrix4<Real>& matrix);
  };

  template<typename Real>
  Quaternion<Real> operator+(const Quaternion<Real>& left, const Quaternion<Real>& right);

  template<typename Real>
  Quaternion<Real> operator-(const Quaternion<Real>& left, const Quaternion<Real>& right);

  template<typename Real>
  Quaternion<Real> operator*(const Quaternion<Real>& left, const Quaternion<Real>& right);

  template<typename Real>
  Quaternion<Real> operator*(const Quaternion<Real>& quaternion, const Real& scalar);

  template<typename Real>
  Quaternion<Real> operator*(const Real& scalar, const Quaternion<Real>& quaternion);

  template<typename Real>
  Quaternion<Real> operator/(const Quaternion<Real>& quaternion, const Real& scalar);
}

// Implemenation
template<typename Real>
Math::Quaternion<Real>::Quaternion()
  : real(1)
{ }

template<typename Real>
Math::Quaternion<Real>::Quaternion(const Real& w, const Real& x, const Real& y, const Real& z)
  : real(w), imag(x, y, z)
{ }

template<typename Real>
Math::Quaternion<Real>::Quaternion(const Real array[4])
  : real(array[0]), imag(array[1], array[2], array[3])
{ }

template<typename Real>
Math::Quaternion<Real>::Quaternion(const Real& real, const Vector3<Real>& imaginary_vector)
  : real(real), imag(imaginary_vector)
{ }

template<typename Real>
Math::Quaternion<Real>::Quaternion(const Vector3<Real>& axis, const Real& angle)
  : real(std::cos(angle)), imag(axis * std::sin(angle))
{ }

template<typename Real>
Math::Quaternion<Real>::Quaternion(const Matrix4<Real>& matrix)
  : real(0.5 * std::sqrt(matrix.trace()))
{
  const auto u = matrix.trace() - 1;
  if (u > matrix(0,0) && u > matrix(1,1) && u > matrix(2,2))
    create_quaternion_from_matrix_with_largest_u(matrix);
  else
    create_quaternion_from_matrix_with_smallest_u(matrix);
}

template<typename Real>
Real& Math::Quaternion<Real>::w()
{
  return real;
}

template<typename Real>
Real Math::Quaternion<Real>::w() const
{
  return real;
}

template<typename Real>
Real& Math::Quaternion<Real>::x()
{
  return imag.x;
}

template<typename Real>
Real Math::Quaternion<Real>::x() const
{
  return imag.x;
}

template<typename Real>
Real& Math::Quaternion<Real>::y()
{
  return imag.y;
}

template<typename Real>
Real Math::Quaternion<Real>::y() const
{
  return imag.y;
}

template<typename Real>
Real& Math::Quaternion<Real>::z()
{
  return imag.z;
}

template<typename Real>
Real Math::Quaternion<Real>::z() const
{
  return imag.z;
}

template<typename Real>
Math::Quaternion<Real> Math::Quaternion<Real>::operator+=(const Quaternion<Real>& other)
{
  real += other.real;
  imag += other.imag;
  return *this;
}

template<typename Real>
Math::Quaternion<Real> Math::Quaternion<Real>::operator-=(const Quaternion<Real>& other)
{
  real -= other.real;
  imag -= other.imag;
  return *this;
}

template<typename Real>
Math::Quaternion<Real> Math::Quaternion<Real>::operator*=(const Real& scalar)
{
  real *= scalar;
  imag *= scalar;
  return *this;
}

template<typename Real>
Math::Quaternion<Real> Math::Quaternion<Real>::operator/=(const Real& scalar)
{
  assert(scalar != 0 && "Ca not divide quaternion by zero");

  real /= scalar;
  imag /= scalar;
  return *this;
}

template<typename Real>
Math::Matrix4<Real> Math::Quaternion<Real>::create_matrix() const
{
  const auto quat_norm = norm();

  assert(quat_norm != 0 && "Can not make matrix from zero quaternion");

  const auto s = 2.0 / quat_norm;
  return create_matrix_with_scale(s);
}

template<typename Real>
Math::Matrix4<Real> Math::Quaternion<Real>::create_matrix_with_scale(const Real& s) const
{
  Matrix4<Real> result;

  result(0,0) -= s *(imag.y * imag.y + imag.z * imag.z);
  result(0,1) += s *(imag.x * imag.y - real * imag.z);
  result(0,2) += s *(imag.x * imag.z + real * imag.y);

  result(1,0) += s *(imag.x * imag.y + real * imag.z);
  result(1,1) -= s *(imag.x * imag.x + imag.z * imag.z);
  result(1,2) += s *(imag.y * imag.z - real * imag.x);

  result(2,0) += s *(imag.x * imag.z - real * imag.y);
  result(2,1) += s *(imag.y * imag.z + real * imag.x);
  result(2,2) -= s *(imag.x * imag.x + imag.y * imag.y);

  return result;
}

template<typename Real>
Real Math::Quaternion<Real>::norm() const
{
  return std::sqrt(imag.dot(imag) + real * real);
}

template<typename Real>
void Math::Quaternion<Real>::normalize()
{
  auto scale = norm();

  assert(scale != 0 && "Can not normalize zero quaternion");

  real /= scale;
  imag /= scale;
}

template<typename Real>
Math::Quaternion<Real> Math::Quaternion<Real>::conjugate() const
{
  return Quaternion<Real>(real, -imag);
}

template<typename Real>
Math::Quaternion<Real> Math::Quaternion<Real>::inverse() const
{
  const auto normsquared = imag.lengthSquared() +(real * real);

  return conjugate() / normsquared;
}

template<typename Real>
Math::Quaternion<Real> Math::Quaternion<Real>::slerp(const Quaternion<Real>& from, const Quaternion<Real>& to, const Real& t)
{
  const auto angle = std::acos(from.real * to.real + from.imag.dot(to.imag));
  const auto from_scale = std::sin(angle *(1 - t))/std::sin(angle);
  const auto to_scale = std::sin(angle * t)/std::sin(angle);
  return from_scale * from + to_scale * to;
}

template<typename Real>
Math::Quaternion<Real> Math::operator+(const Quaternion<Real>& left, const Quaternion<Real>& right)
{
  Quaternion<Real> res = left;
  res += right;
  return res;
}

template<typename Real>
Math::Quaternion<Real> Math::operator-(const Quaternion<Real>& left, const Quaternion<Real>& right)
{
  Quaternion<Real> res = left;
  res -= right;
  return res;
}

template<typename Real>
Math::Quaternion<Real> Math::operator*(const Quaternion<Real>& left, const Quaternion<Real>& right)
{
  return Quaternion<Real>(left.w() * right.w() - left.imag.dot(right.imag),
      left.imag.cross(right.imag) + left.real * right.imag + right.real * left.imag);
}

template<typename Real>
Math::Quaternion<Real> Math::operator*(const Quaternion<Real>& quaternion, const Real& scalar)
{
  Quaternion<Real> res = quaternion;
  res *= scalar;
  return res;
}

template<typename Real>
Math::Quaternion<Real> Math::operator*(const Real& scalar, const Quaternion<Real>& quaternion)
{
  return quaternion * scalar;
}

template<typename Real>
Math::Quaternion<Real> Math::operator/(const Quaternion<Real>& quaternion, const Real& scalar)
{
  Quaternion<Real> res = quaternion;
  res /= scalar;
  return res;
}

template<typename Real>
void Math::Quaternion<Real>::create_quaternion_from_matrix_with_largest_u(const Matrix4<Real>& matrix)
{
  imag.x = matrix(2,1) - matrix(1,2);
  imag.y = matrix(0,2) - matrix(2,0);
  imag.z = matrix(1,0) - matrix(0,1);

  imag /=(4 * real);
}

template<typename Real>
void Math::Quaternion<Real>::create_quaternion_from_matrix_with_smallest_u(const Matrix4<Real>& matrix)
{
  imag.x = std::sqrt(matrix(0,0) - matrix(1,1) - matrix(2,2) + matrix(3,3));
  imag.y = std::sqrt(-matrix(0,0) + matrix(1,1) - matrix(2,2) + matrix(3,3));
  imag.z = std::sqrt(-matrix(0,0) - matrix(1,1) + matrix(2,2) + matrix(3,3));

  imag *= 0.5;
}
#endif // MATH_QUATERNION_H_INCLUDED
