#ifndef MATH_MATRIX2_H_INCLUDED
#define MATH_MATRIX2_H_INCLUDED

#include "config.h"
#include "vector2.h"

#include <exception>
#include <algorithm>
#include <sstream>

namespace Math
{
  template<typename Real>
  class Matrix2
  {
    public:
      explicit Matrix2 ();
      explicit Matrix2 (const Real& m00, const Real& m01, const Real& m10, const Real&  m11);
      explicit Matrix2 (const Real array[4]);

      Real& operator[] (const size_t& i);
      Real operator[] (const size_t& i) const;

      Real& operator () (const size_t& i, const size_t& j);
      Real operator () (const size_t& i, const size_t& j) const;

      operator Real* ();
      operator const Real* () const;

      Matrix2& operator+= (const Matrix2& matrix);
      Matrix2& operator-= (const Matrix2& matrix);
      Matrix2& operator*= (const Real& scalar);
      Matrix2& operator/= (const Real& scalar);

      Real determinant () const;
      Matrix2 transpose () const;
      Matrix2 inverse () const;

      const static Matrix2 IDENTITY;
      const static Matrix2 ZERO;
    private:
      Real data[4];

    public:
      class division_by_zero_exception : public std::exception { };

      class inverse_of_singular_matrix_exception : public std::exception { };

      class index_operator_out_of_range_exception : public std::exception
      {
        public:
          index_operator_out_of_range_exception (const size_t& row, const size_t& col);
          index_operator_out_of_range_exception (const size_t& index);

          virtual const char* what () const throw ();
        private:
          const char* create_message_from_index () const;
          const char* create_message_from_row_col () const;
        private:
          size_t index;
          size_t row;
          size_t col;
      };
  };

  template<typename Real>
  Matrix2<Real> operator+ (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix);

  template<typename Real>
  Matrix2<Real> operator- (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix);

  template<typename Real>
  Matrix2<Real> operator* (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix);

  template<typename Real>
  Matrix2<Real> operator* (const Matrix2<Real>& matrix, const Real& scalar);

  template<typename Real>
  Vector2<Real> operator* (const Matrix2<Real>& matrix, const Vector2<Real>& vector);

  template<typename Real>
  Vector2<Real> operator* (const Vector2<Real>& vector, const Matrix2<Real>& matrix);

  template<typename Real>
  Matrix2<Real> operator* (const Real& scalar, const Matrix2<Real>& matrix);

  template<typename Real>
  Matrix2<Real> operator/ (const Matrix2<Real>& matrix, const Real& scalar);

  template<typename Real>
  bool operator== (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix);

  template<typename Real>
  bool operator!= (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix);
}

// Implementation
template<typename Real>
Math::Matrix2<Real>::Matrix2 ()
  : data {1,0,0,1}
{ }

template<typename Real>
Math::Matrix2<Real>::Matrix2 (const Real& m00, const Real& m01,
                              const Real& m10, const Real&  m11)
  : data {m00, m01, m10, m11}
{ }

template<typename Real>
Math::Matrix2<Real>::Matrix2 (const Real array[4])
  : data {array[0], array[1], array[2], array[3]}
{ }

template<typename Real>
Real& Math::Matrix2<Real>::operator[] (const size_t& i)
{
  if (i > 3)
    throw index_operator_out_of_range_exception (i);

  return data[i];
}

template<typename Real>
Real Math::Matrix2<Real>::operator[] (const size_t& i) const
{
  if (i > 3)
    throw index_operator_out_of_range_exception (i);

  return data[i];
}

template<typename Real>
Real& Math::Matrix2<Real>::operator () (const size_t& i, const size_t& j)
{
  if (i > 1 || j > 1)
    throw index_operator_out_of_range_exception (i, j);

  return data[i*2 + j];
}

template<typename Real>
Real Math::Matrix2<Real>::operator () (const size_t& i, const size_t& j) const
{
  if (i > 1 || j > 1)
    throw index_operator_out_of_range_exception (i, j);

  return data[i*2 + j];
}

template<typename Real>
Math::Matrix2<Real>::operator Real* ()
{
  return data;
}

template<typename Real>
Math::Matrix2<Real>::operator const Real* () const
{
  return data;
}

template<typename Real>
Math::Matrix2<Real>& Math::Matrix2<Real>::operator+= (const Math::Matrix2<Real>& matrix)
{
  data[0] += matrix (0,0);
  data[1] += matrix (0,1);
  data[2] += matrix (1,0);
  data[3] += matrix (1,1);

  return *this;
}

template<typename Real>
Math::Matrix2<Real>& Math::Matrix2<Real>::operator-= (const Math::Matrix2<Real>& matrix)
{
  data[0] -= matrix (0,0);
  data[1] -= matrix (0,1);
  data[2] -= matrix (1,0);
  data[3] -= matrix (1,1);

  return *this;
}

template<typename Real>
Math::Matrix2<Real>& Math::Matrix2<Real>::operator*= (const Real& scalar)
{
  data[0] *= scalar;
  data[1] *= scalar;
  data[2] *= scalar;
  data[3] *= scalar;

  return *this;
}

template<typename Real>
Math::Matrix2<Real>& Math::Matrix2<Real>::operator/= (const Real& scalar)
{
  if (scalar == 0)
    throw division_by_zero_exception ();

  data[0] /= scalar;
  data[1] /= scalar;
  data[2] /= scalar;
  data[3] /= scalar;

  return *this;
}

template<typename Real>
Real Math::Matrix2<Real>::determinant () const
{
  return data[0]*data[3] - data[1]*data[2];
}

template<typename Real>
Math::Matrix2<Real> Math::Matrix2<Real>::transpose () const
{
  return Matrix2<Real> (data[0], data[2], data[1], data[3]);
}

template<typename Real>
Math::Matrix2<Real> Math::Matrix2<Real>::inverse () const
{
  Real det = determinant ();

  if (det == 0)
    throw inverse_of_singular_matrix_exception ();

  Real scale = 1.0/det;

  Matrix2<Real> result (data[3], -data[1],
      -data[2], data[0]);

  return result * scale;
}

template<typename Real>
Math::Matrix2<Real> Math::operator+ (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix)
{
  auto result = lmatrix;
  result += rmatrix;
  return result;
}

template<typename Real>
Math::Matrix2<Real> Math::operator- (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix)
{
  auto result = lmatrix;
  result -= rmatrix;
  return result;
}

template<typename Real>
Math::Matrix2<Real> Math::operator* (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix)
{
  Matrix2<Real> res;
  res (0,0) = lmatrix (0,0) * rmatrix (0,0) + lmatrix (0,1) * rmatrix (1,0);
  res (0,1) = lmatrix (0,0) * rmatrix (0,1) + lmatrix (0,1) * rmatrix (1,1);
  res (1,0) = lmatrix (1,0) * rmatrix (0,0) + lmatrix (1,1) * rmatrix (1,0);
  res (1,1) = lmatrix (1,0) * rmatrix (0,1) + lmatrix (1,1) * rmatrix (1,1);

  return res;
}

template<typename Real>
Math::Matrix2<Real> Math::operator* (const Matrix2<Real>& matrix, const Real& scalar)
{
  auto result = matrix;
  result *= scalar;
  return result;
}

template<typename Real>
Math::Matrix2<Real> Math::operator* (const Real& scalar, const Matrix2<Real>& matrix)
{
  return matrix * scalar;
}

template<typename Real>
Math::Vector2<Real> Math::operator* (const Matrix2<Real>& matrix, const Vector2<Real>& vector)
{
  return Vector2<Real> (matrix[0] * vector.x + matrix[1] * vector.y,
      matrix[2] * vector.x + matrix[3] * vector.y);
}

template<typename Real>
Math::Vector2<Real> Math::operator* (const Vector2<Real>& vector, const Matrix2<Real>& matrix)
{
  return Vector2<Real> (matrix[0] * vector.x + matrix[2] * vector.y,
      matrix[1] * vector.x + matrix[3] * vector.y);
}

template<typename Real>
Math::Matrix2<Real> Math::operator/ (const Matrix2<Real>& matrix, const Real& scalar)
{
  auto result = matrix;
  result /= scalar;
  return result;
}

template<typename Real>
bool Math::operator== (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix)
{
  auto first1 = static_cast<const Real*> (lmatrix);
  auto last = first1 + 4;
  auto first2 = static_cast<const Real*> (rmatrix);

  return std::equal (first1, last, first2);
}

template<typename Real>
bool Math::operator!= (const Matrix2<Real>& lmatrix, const Matrix2<Real>& rmatrix)
{
  return !(lmatrix == rmatrix);
}

template<typename Real>
Math::Matrix2<Real>::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& row, const size_t& col)
  : index (0), row (row), col (col)
{ }

template<typename Real>
Math::Matrix2<Real>::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& index)
  : index (index), row (0), col (0)
{ }

template<typename Real>
const char* Math::Matrix2<Real>::index_operator_out_of_range_exception::what () const throw ()
{
  if (index == 0)
    return create_message_from_row_col ();
  return create_message_from_index ();
}

template<typename Real>
const char* Math::Matrix2<Real>::index_operator_out_of_range_exception::create_message_from_index () const
{
  std::stringstream out;
  out << "Tried to access index: " << index;
  return out.str ().c_str ();
}

template<typename Real>
const char* Math::Matrix2<Real>::index_operator_out_of_range_exception::create_message_from_row_col () const
{
  std::stringstream out;
  out << "Tried to access: (" << row << ", " << col << ")";
  return out.str ().c_str ();
}

#endif // MATH_MATRIX2_H_INCLUDED
