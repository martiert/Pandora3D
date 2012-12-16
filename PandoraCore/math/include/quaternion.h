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

      explicit Quaternion(const Real& scalar, const Vector<Real, 3>& imaginary_vector);

      explicit Quaternion(const Vector<Real, 3>& axis, const Real& angle);

      explicit Quaternion(const Matrix<Real, 4>& matrix);

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

      Matrix<Real, 4> create_matrix() const;

      Real norm() const;
      void normalize();

      Quaternion conjugate() const;
      Quaternion inverse() const;

      static Quaternion slerp(const Quaternion& from, const Quaternion& to, const Real& t);

    public:
      Real real;
      Vector<Real, 3> imag;

    protected:
      Matrix<Real, 4> create_matrix_with_scale(const Real& s) const;

      void create_quaternion_from_matrix_with_largest_u(const Matrix<Real, 4>& matrix);
      void create_quaternion_from_matrix_with_smallest_u(const Matrix<Real, 4>& matrix);
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
  : real(w), imag({x, y, z})
{ }

template<typename Real>
Math::Quaternion<Real>::Quaternion(const Real array[4])
  : real(array[0]), imag({array[1], array[2], array[3]})
{ }

template<typename Real>
Math::Quaternion<Real>::Quaternion(const Real& real, const Vector<Real, 3>& imaginary_vector)
  : real(real), imag(imaginary_vector)
{ }

template<typename Real>
Math::Quaternion<Real>::Quaternion(const Vector<Real, 3>& axis, const Real& angle)
  : real(std::cos(angle)), imag(axis * std::sin(angle))
{ }

template<typename Real>
Math::Quaternion<Real>::Quaternion(const Matrix<Real, 4>& matrix)
  : real(0.5 * std::sqrt(matrix_trace(matrix)))
{
  const auto u = matrix_trace(matrix) - 1;
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
  return imag[0];
}

template<typename Real>
Real Math::Quaternion<Real>::x() const
{
  return imag[0];
}

template<typename Real>
Real& Math::Quaternion<Real>::y()
{
  return imag[1];
}

template<typename Real>
Real Math::Quaternion<Real>::y() const
{
  return imag[1];
}

template<typename Real>
Real& Math::Quaternion<Real>::z()
{
  return imag[2];
}

template<typename Real>
Real Math::Quaternion<Real>::z() const
{
  return imag[2];
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
Math::Matrix<Real, 4> Math::Quaternion<Real>::create_matrix() const
{
  const auto quat_norm = norm();

  assert(quat_norm != 0 && "Can not make matrix from zero quaternion");

  const auto s = 2.0 / quat_norm;
  return create_matrix_with_scale(s);
}

template<typename Real>
Math::Matrix<Real, 4> Math::Quaternion<Real>::create_matrix_with_scale(const Real& s) const
{
  Matrix<Real, 4> result;

  result(0,0) -= s *(imag[1] * imag[1] + imag[2] * imag[2]);
  result(0,1) += s *(imag[0] * imag[1] - real * imag[2]);
  result(0,2) += s *(imag[0] * imag[2] + real * imag[1]);

  result(1,0) += s *(imag[0] * imag[1] + real * imag[2]);
  result(1,1) -= s *(imag[0] * imag[0] + imag[2] * imag[2]);
  result(1,2) += s *(imag[1] * imag[2] - real * imag[0]);

  result(2,0) += s *(imag[0] * imag[2] - real * imag[1]);
  result(2,1) += s *(imag[1] * imag[2] + real * imag[0]);
  result(2,2) -= s *(imag[0] * imag[0] + imag[1] * imag[1]);

  return result;
}

template<typename Real>
Real Math::Quaternion<Real>::norm() const
{
  return std::sqrt(dot_product(imag, imag) + real * real);
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
  const auto normsquared = vector_length_squared(imag) +(real * real);

  return conjugate() / normsquared;
}

template<typename Real>
Math::Quaternion<Real> Math::Quaternion<Real>::slerp(const Quaternion<Real>& from, const Quaternion<Real>& to, const Real& t)
{
  const auto angle = std::acos(from.real * to.real + dot_product(from.imag, to.imag));
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
  return Quaternion<Real>(left.w() * right.w() - dot_product(left.imag, right.imag),
      cross_product(left.imag, right.imag) + left.real * right.imag + right.real * left.imag);
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
void Math::Quaternion<Real>::create_quaternion_from_matrix_with_largest_u(const Matrix<Real, 4>& matrix)
{
  imag[0] = matrix(2,1) - matrix(1,2);
  imag[1] = matrix(0,2) - matrix(2,0);
  imag[2] = matrix(1,0) - matrix(0,1);

  imag /=(4 * real);
}

template<typename Real>
void Math::Quaternion<Real>::create_quaternion_from_matrix_with_smallest_u(const Matrix<Real, 4>& matrix)
{
  imag[0] = std::sqrt(matrix(0,0) - matrix(1,1) - matrix(2,2) + matrix(3,3));
  imag[1] = std::sqrt(-matrix(0,0) + matrix(1,1) - matrix(2,2) + matrix(3,3));
  imag[2] = std::sqrt(-matrix(0,0) - matrix(1,1) + matrix(2,2) + matrix(3,3));

  imag *= 0.5;
}
#endif // MATH_QUATERNION_H_INCLUDED
