#ifndef MATH_VECTOR_H_INCLUDED
#define MATH_VECTOR_H_INCLUDED

#include "config.h"

#include <assert.h>
#include <array>
#include <initializer_list>
#include <algorithm>

namespace Math
{

template<typename Real, size_t dim>
struct Vector
{
public:
    explicit Vector();
    explicit Vector(std::initializer_list<Real> arguments);
    explicit Vector(const Real array[dim]);

    Vector& operator=(const Real array[dim]);

    const Real* begin() const;
    const Real* end() const;
    Real* begin();
    Real* end();

    Real & operator[](const size_t & i);
    Real operator[](const size_t & i) const;
private:
    std::array<Real, dim> data;
};

template<typename Real, size_t dim>
Real vector_length(const Vector<Real, dim> & vector);

template<typename Real, size_t dim>
Real vector_length_squared(const Vector<Real, dim> & vector);

template<typename Real, size_t dim>
Vector<Real, dim> normalize_vector(Vector<Real, dim> & vector);

template<typename Real, size_t dim>
Real dot_product(const Vector<Real, dim> & left, const Vector<Real, dim> & right);

template<typename Real, size_t dim>
Vector<Real, dim> & operator+=(Vector<Real, dim> & to, const Vector<Real, dim> & from);

template<typename Real, size_t dim>
Vector<Real, dim> & operator-=(Vector<Real, dim> & to, const Vector<Real, dim> & from);

template<typename Real, size_t dim>
Vector<Real, dim> & operator*=(Vector<Real, dim> & to, const Vector<Real, dim> & from);

template<typename Real, size_t dim>
Vector<Real, dim> & operator*=(Vector<Real, dim> & to, const Real & scalar);

template<typename Real, size_t dim>
Vector<Real, dim> & operator/=(Vector<Real, dim> & to, const Real & scalar);

template<typename Real, size_t dim>
Vector<Real, dim> operator-(const Vector<Real, dim> & vector);

template<typename Real, size_t dim>
Vector<Real, dim> operator+(const Vector<Real, dim> & left, const Vector<Real, dim> & right);
template<typename Real, size_t dim>
Vector<Real, dim> operator-(const Vector<Real, dim> & left, const Vector<Real, dim> & right);

template<typename Real, size_t dim>
Vector<Real, dim> operator*(const Vector<Real, dim> & left, const Vector<Real, dim> & right);

template<typename Real, size_t dim>
Vector<Real, dim> operator*(const Vector<Real, dim> & vector, const Real & scalar);

template<typename Real, size_t dim>
Vector<Real, dim> operator*(const Real & scalar, const Vector<Real, dim> & vector);

template<typename Real, size_t dim>
Vector<Real, dim> operator/(const Vector<Real, dim> & vector, const Real & scalar);


template<typename Real, size_t dim>
bool operator==(const Vector<Real, dim> & left, const Vector<Real, dim> & right);

template<typename Real, size_t dim>
bool operator!=(const Vector<Real, dim> & left, const Vector<Real, dim> & right);

#define INCLUDED_FROM_VECTOR_H
#include "vector_tmpl.h"
#undef INCLUDED_FROM_VECTOR_H

}

#endif
