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
struct Quaternion
{
public:
    explicit Quaternion();

    explicit Quaternion(const Real & w, const Real & x, const Real & y, const Real & z);

    explicit Quaternion(const Real array[4]);

    explicit Quaternion(const Real & scalar, const Vector<Real, 3> & imaginary_vector);

    explicit Quaternion(const Vector<Real, 3> & axis, const Real & angle);

    explicit Quaternion(const Matrix<Real, 4> & matrix);

    Vector<Real,3> get_imag() const;
    Vector<Real,3> & get_imag();

    Real & w();
    Real & x();
    Real & y();
    Real & z();

    Real w() const;
    Real x() const;
    Real y() const;
    Real z() const;
public:
    Real real;
    Vector<Real, 3> imag;

    void create_quaternion_from_matrix_with_largest_u(const Matrix<Real, 4> & matrix);
    void create_quaternion_from_matrix_with_smallest_u(const Matrix<Real, 4> & matrix);
};

template<typename Real>
Quaternion<Real> & operator+=(Quaternion<Real> & to, const Quaternion<Real> & other);

template<typename Real>
Quaternion<Real> & operator-=(Quaternion<Real> & to, const Quaternion<Real> & other);

template<typename Real>
Quaternion<Real> & operator*=(Quaternion<Real> & to, const Real & scalar);

template<typename Real>
Quaternion<Real> & operator/=(Quaternion<Real> & to, const Real & scalar);

template<typename Real>
Quaternion<Real> operator+(const Quaternion<Real> & left, const Quaternion<Real> & right);

template<typename Real>
Quaternion<Real> operator-(const Quaternion<Real> & left, const Quaternion<Real> & right);

template<typename Real>
Quaternion<Real> operator*(const Quaternion<Real> & left, const Quaternion<Real> & right);

template<typename Real>
Quaternion<Real> operator*(const Quaternion<Real> & quaternion, const Real & scalar);

template<typename Real>
Quaternion<Real> operator*(const Real & scalar, const Quaternion<Real> & quaternion);

template<typename Real>
Quaternion<Real> operator/(const Quaternion<Real> & quaternion, const Real & scalar);

template<typename Real>
Matrix<Real, 4> quaternion_to_matrix(const Quaternion<Real> & quaternion);

template<typename Real>
Real quaternion_norm(const Quaternion<Real> & quaternion);

template<typename Real>
void quaternion_normalize(Quaternion<Real> & quaternion);

template<typename Real>
Quaternion<Real> quaternion_conjugate(const Quaternion<Real> & quaternion);

template<typename Real>
Quaternion<Real> quaternion_inverse(const Quaternion<Real> & quaternion);

template<typename Real>
Quaternion<Real> quaternion_slerp(const Quaternion<Real> & from, const Quaternion<Real> & to, const Real & t);

#define INCLUDED_FROM_QUATERNION_H
#include "quaternion_tmpl.h"
#undef INCLUDED_FROM_QUATERNION_H

}
#endif
