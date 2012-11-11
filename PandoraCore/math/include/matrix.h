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
      Matrix(const std::initializer_list<Real>& elements);
      Matrix(const Real array[dim*dim]);

      Real& operator[](const size_t& i);
      Real operator[](const size_t& i) const;

      Real& operator()(const size_t& i, const size_t& j);
      Real operator()(const size_t& i, const size_t& j) const;
    private:
      std::array<Real, dim*dim> data;
  };

  // Non intrusive functions
  template<typename Real, size_t dim>
  Real matrix_determinant(const Matrix<Real, dim>& matrix);

  template<typename Real, size_t dim>
  Matrix<Real, dim> matrix_transpose(const Matrix<Real, dim>& matrix);

  template<typename Real, size_t dim>
  Real matrix_trace(const Matrix<Real, dim>& matrix);

  template<typename Real, size_t dim>
  Matrix<Real, dim> matrix_adjugate(const Matrix<Real, dim>& matrix);

  template<typename Real, size_t dim>
  Matrix<Real, dim> matrix_inverse(const Matrix<Real, dim>& matrix);


  // Inline arithmetic operations
  template<typename Real, size_t dim>
  Matrix<Real, dim>& operator+=(Matrix<Real, dim>& to, const Matrix<Real, dim>& from);

  template<typename Real, size_t dim>
  Matrix<Real, dim>& operator-=(Matrix<Real, dim>& to, const Matrix<Real, dim>& from);

  template<typename Real, size_t dim>
  Matrix<Real, dim>& operator*=(Matrix<Real, dim>& matrix, const Real& scalar);

  template<typename Real, size_t dim>
  Matrix<Real, dim>& operator/=(Matrix<Real, dim>& matrix, const Real& scalar);


  // Arithmetic operations
  template<typename Real, size_t dim>
  Matrix<Real, dim> operator+(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right);

  template<typename Real, size_t dim>
  Matrix<Real, dim> operator-(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right);

  template<typename Real, size_t dim>
  Matrix<Real, dim> operator*(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right);

  template<typename Real, size_t dim>
  Vector<Real, dim> operator*(const Matrix<Real, dim>& matrix, const Vector<Real, dim>& vector);

  template<typename Real, size_t dim>
  Vector<Real, dim> operator*(const Vector<Real, dim>& vector, const Matrix<Real, dim>& matrix);

  template<typename Real, size_t dim>
  Matrix<Real, dim> operator*(const Matrix<Real, dim>& matrix, const Real& scalar);

  template<typename Real, size_t dim>
  Matrix<Real, dim> operator*(const Real& scalar, const Matrix<Real, dim>& matrix);

  template<typename Real, size_t dim>
  Matrix<Real, dim> operator/(const Matrix<Real, dim>& matrix, const Real& scalar);


  // Matrix comparison
  template<typename Real, size_t dim>
  bool operator==(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right);

  template<typename Real, size_t dim>
  bool operator!=(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right);


  //=================================
  // Implementations.
  //=================================
  template<typename Real, size_t dim>
  Matrix<Real, dim>::Matrix()
    : data {{0,}}
  {
    for (size_t i = 0; i < dim; ++i)
      data[i*dim+i] = 1;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim>::Matrix(const std::initializer_list<Real>& elements)
  {
    std::copy(elements.begin(), elements.end(), data.begin());
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim>::Matrix(const Real array[dim*dim])
  {
    std::copy(array, array + dim*dim, data.begin());
  }

  template<typename Real, size_t dim>
  Real& Matrix<Real, dim>::operator[](const size_t& i)
  {
    assert(i < dim*dim && "Index operator out of range");
    return data[i];
  }

  template<typename Real, size_t dim>
  Real Matrix<Real, dim>::operator[](const size_t& i) const
  {
    assert(i < dim*dim && "Index operator out of range");
    return data[i];
  }

  template<typename Real, size_t dim>
  Real& Matrix<Real, dim>::operator()(const size_t& i, const size_t& j)
  {
    assert(i < dim && j < dim && "Index operator out of range");
    return data[i*dim + j];
  }

  template<typename Real, size_t dim>
  Real Matrix<Real, dim>::operator()(const size_t& i, const size_t& j) const
  {
    assert(i < dim && j < dim && "Index operator out of range");
    return data[i*dim + j];
  }

  template<typename Real, size_t dim>
  Real matrix_determinant(const Matrix<Real, dim>& matrix)
  {
    Real result = 1;
    for (size_t i = 0; i < dim; ++i)
      result *= matrix(i,i);
    return result;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim> matrix_transpose(const Matrix<Real, dim>& matrix)
  {
    Matrix<Real, dim> result;
    for (size_t i = 0; i < dim; ++i)
      for (size_t j = 0; j < dim; ++j)
        result(i,j) = matrix(j,i);
    return result;
  }

  template<typename Real, size_t dim>
  Real matrix_trace(const Matrix<Real, dim>& matrix)
  {
    Real result = 0;
    for (size_t i = 0; i < dim; ++i)
      result += matrix(i,i);
    return result;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim> matrix_adjugate(const Matrix<Real, dim>& matrix)
  {
    return matrix;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim> matrix_inverse(const Matrix<Real, dim>& matrix)
  {
    return matrix_adjugate(matrix) / matrix_determinant(matrix);
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim>& operator+=(Matrix<Real, dim>& to, const Matrix<Real, dim>& from)
  {
    for (size_t i = 0; i < dim*dim; ++i)
      to[i] += from[i];
    return to;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim>& operator-=(Matrix<Real, dim>& to, const Matrix<Real, dim>& from)
  {
    for (size_t i = 0; i < dim*dim; ++i)
      to[i] -= from[i];
    return to;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim>& operator*=(Matrix<Real, dim>& matrix, const Real& scalar)
  {
    for (size_t i = 0; i < dim*dim; ++i)
      matrix[i] *= scalar;
    return matrix;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim>& operator/=(Matrix<Real, dim>& matrix, const Real& scalar)
  {
    matrix *= (1./scalar);
    return matrix;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim> operator+(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right)
  {
    auto result (left);
    result += right;
    return result;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim> operator-(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right)
  {
    auto result (left);
    result -= right;
    return result;
  }

  template<typename Real, size_t dim>
  Real calculate_element(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right,
                         const size_t& i, const size_t& j);

  template<typename Real, size_t dim>
  Matrix<Real, dim> operator*(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right)
  {
    Matrix<Real, dim> result;
    for (size_t i = 0; i < dim; ++i)
      for (size_t j = 0; j < dim; ++j)
        result(i,j) = calculate_element(left, right, i, j);
    return result;
  }

  template<typename Real, size_t dim>
  Vector<Real, dim> operator*(const Matrix<Real, dim>& matrix, const Vector<Real, dim>& vector)
  {
    Vector<Real, dim> result;
    for (size_t i = 0; i < dim; ++i)
      for (size_t j = 0; j < dim; ++j)
        result[i] += matrix(i,j) * vector[j];
    return result;
  }

  template<typename Real, size_t dim>
  Vector<Real, dim> operator*(const Vector<Real, dim>& vector, const Matrix<Real, dim>& matrix)
  {
    return matrix_transpose(matrix) * vector;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim> operator*(const Matrix<Real, dim>& matrix, const Real& scalar)
  {
    auto result (matrix);
    result *= scalar;
    return result;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim> operator*(const Real& scalar, const Matrix<Real, dim>& matrix)
  {
    return matrix * scalar;
  }

  template<typename Real, size_t dim>
  Matrix<Real, dim> operator/(const Matrix<Real, dim>& matrix, const Real& scalar)
  {
    auto result (matrix);
    result /= scalar;
    return result;
  }

  template<typename Real, size_t dim>
  bool operator==(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right)
  {
    for (size_t i = 0; i < dim*dim; ++i)
      if (left[i] != right[i])
        return false;
    return true;
  }

  template<typename Real, size_t dim>
  bool operator!=(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right)
  {
    return !(left == right);
  }

  template<typename Real, size_t dim>
  Real calculate_element(const Matrix<Real, dim>& left, const Matrix<Real, dim>& right,
                         const size_t& i, const size_t& j)
  {
    Real element = 0;
    for (size_t k = 0; k < dim; ++k)
      element += left(i,k) * right(k,j);
    return element;
  }
}
#endif
