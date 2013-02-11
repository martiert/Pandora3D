#ifndef MATH_MATRIX_H_INCLUDED
#define MATH_MATRIX_H_INCLUDED

#include "config.h"
#include "vector.h"

#include <array>
#include <initializer_list>
#include <algorithm>

namespace Math
{

template<typename Real, size_t dim>
struct Matrix
{
public:
    Matrix();
    Matrix(const std::initializer_list<Real> & elements);
    Matrix(const Real array[dim*dim]);

    Real & operator[](const size_t & i);
    Real operator[](const size_t & i) const;

    Real & operator()(const size_t & i, const size_t & j);
    Real operator()(const size_t & i, const size_t & j) const;
private:
    std::array<Real, dim*dim> data;
};

// Non intrusive functions
template<typename Real, size_t dim>
Real matrix_determinant(const Matrix<Real, dim> & matrix);

template<typename Real, size_t dim>
Matrix<Real, dim> matrix_transpose(const Matrix<Real, dim> & matrix);

template<typename Real, size_t dim>
Real matrix_trace(const Matrix<Real, dim> & matrix);

template<typename Real, size_t dim>
Matrix<Real, dim> matrix_adjugate(const Matrix<Real, dim> & matrix);

template<typename Real, size_t dim>
Matrix<Real, dim> matrix_inverse(const Matrix<Real, dim> & matrix);


// Inline arithmetic operations
template<typename Real, size_t dim>
Matrix<Real, dim> & operator+=(Matrix<Real, dim> & to, const Matrix<Real, dim> & from);

template<typename Real, size_t dim>
Matrix<Real, dim> & operator-=(Matrix<Real, dim> & to, const Matrix<Real, dim> & from);

template<typename Real, size_t dim>
Matrix<Real, dim> & operator*=(Matrix<Real, dim> & matrix, const Real & scalar);

template<typename Real, size_t dim>
Matrix<Real, dim> & operator/=(Matrix<Real, dim> & matrix, const Real & scalar);


// Arithmetic operations
template<typename Real, size_t dim>
Matrix<Real, dim> operator+(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right);

template<typename Real, size_t dim>
Matrix<Real, dim> operator-(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right);

template<typename Real, size_t dim>
Matrix<Real, dim> operator*(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right);

template<typename Real, size_t dim>
Vector<Real, dim> operator*(const Matrix<Real, dim> & matrix, const Vector<Real, dim> & vector);

template<typename Real, size_t dim>
Vector<Real, dim> operator*(const Vector<Real, dim> & vector, const Matrix<Real, dim> & matrix);

template<typename Real, size_t dim>
Matrix<Real, dim> operator*(const Matrix<Real, dim> & matrix, const Real & scalar);

template<typename Real, size_t dim>
Matrix<Real, dim> operator*(const Real & scalar, const Matrix<Real, dim> & matrix);

template<typename Real, size_t dim>
Matrix<Real, dim> operator/(const Matrix<Real, dim> & matrix, const Real & scalar);


// Matrix comparison
template<typename Real, size_t dim>
bool operator==(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right);

template<typename Real, size_t dim>
bool operator!=(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right);

#define INCLUDED_FROM_MATRIX_H
#include "matrix_tmpl.h"
#undef INCLUDED_FROM_MATRIX_H

}
#endif
