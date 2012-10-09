#ifndef MATH_MATRIX3_H_INCLUDED
#define MATH_MATRIX3_H_INCLUDED

#include "config.h"

#include <array>
#include <exception>
#include <sstream>
#include <algorithm>

namespace Math
{
  template<typename Real>
  class Matrix3
  {
    public:
      explicit Matrix3 ();
      explicit Matrix3 (const Real& m00, const Real& m01, const Real& m02,
                        const Real& m10, const Real& m11, const Real& m12,
                        const Real& m20, const Real& m21, const Real& m22);
      explicit Matrix3 (const std::array<Real, 9> array);

      Real& operator () (const size_t& i, const size_t& j);
      Real operator () (const size_t& i, const size_t& j) const;

      Real& operator [] (const size_t& i);
      Real operator [] (const size_t& i) const;

      std::array<Real, 9>& get_data ();
      std::array<Real, 9> get_data () const;

      Matrix3& operator*= (const Real& scalar);
      Matrix3& operator/= (const Real& scalar);
      Matrix3& operator+= (const Matrix3& other);
      Matrix3& operator-= (const Matrix3& other);

      Real determinant () const;
      Real trace () const;

      Matrix3 transpose () const;

      Matrix3 inverse () const;

      const static Matrix3 IDENTITY;
      const static Matrix3 ZERO;
    private:
      std::array<Real, 9> data;

    public:
      class division_by_zero_exception : public std::exception { };

      class inverse_of_singular_matrix_exception : public std::exception { };

      class index_operator_out_of_range_exception : public std::exception
      {
        public:
          index_operator_out_of_range_exception (const size_t& i);
          index_operator_out_of_range_exception (const size_t& row, const size_t& col);

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
  Matrix3<Real> operator* (const Matrix3<Real>& matrix, const Real& scalar);

  template<typename Real>
  Matrix3<Real> operator* (const Real& scalar, const Matrix3<Real>& matrix);

  template<typename Real>
  Matrix3<Real> operator/ (const Matrix3<Real>& matrix, const Real& scalar);

  template<typename Real>
  Matrix3<Real> operator+ (const Matrix3<Real>& left, const Matrix3<Real>& right);

  template<typename Real>
  Matrix3<Real> operator- (const Matrix3<Real>& left, const Matrix3<Real>& right);

  template<typename Real>
  Matrix3<Real> operator* (const Matrix3<Real>& left, const Matrix3<Real>& right);

  template<typename Real>
  bool operator== (const Matrix3<Real>& left, const Matrix3<Real>& right);

  template<typename Real>
  bool operator!= (const Matrix3<Real>& left, const Matrix3<Real>& right);
}

// Implementation
template<typename Real>
Math::Matrix3<Real>::Matrix3 ()
  : data {{1, 0, 0, 0, 1, 0, 0, 0, 1}}
{ }

template<typename Real>
Math::Matrix3<Real>::Matrix3 (const Real& m00, const Real& m01, const Real& m02,
                        const Real& m10, const Real& m11, const Real& m12,
                        const Real& m20, const Real& m21, const Real& m22)
  : data {{m00, m01, m02, m10, m11, m12, m20, m21, m22}}
{ }

template<typename Real>
Math::Matrix3<Real>::Matrix3 (const std::array<Real, 9> array)
  : data (array)
{ }

template<typename Real>
Real& Math::Matrix3<Real>::operator () (const size_t& i, const size_t& j)
{
  if (i > 2 || j > 2)
    throw index_operator_out_of_range_exception (i, j);

  return data[i*3 + j];
}

template<typename Real>
Real Math::Matrix3<Real>::operator () (const size_t& i, const size_t& j) const
{
  if (i > 2 || j > 2)
    throw index_operator_out_of_range_exception (i, j);

  return data[i*3 + j];
}

template<typename Real>
Real& Math::Matrix3<Real>::operator [] (const size_t& i)
{
  if (i > 8)
    throw index_operator_out_of_range_exception (i);

  return data[i];
}

template<typename Real>
Real Math::Matrix3<Real>::operator [] (const size_t& i) const
{
  if (i > 8)
    throw index_operator_out_of_range_exception (i);

  return data[i];
}

template<typename Real>
std::array<Real, 9>& Math::Matrix3<Real>::get_data ()
{
  return data;
}

template<typename Real>
std::array<Real, 9> Math::Matrix3<Real>::get_data () const
{
  return data;
}

template<typename Real>
Math::Matrix3<Real>& Math::Matrix3<Real>::operator*= (const Real& scalar)
{
  for (auto& i : data)
    i *= scalar;

  return *this;
}

template<typename Real>
Math::Matrix3<Real>& Math::Matrix3<Real>::operator/= (const Real& scalar)
{
  if (scalar == 0)
    throw division_by_zero_exception ();

  for (auto& i : data)
    i /= scalar;

  return *this;
}

template<typename Real>
Math::Matrix3<Real>& Math::Matrix3<Real>::operator+= (const Math::Matrix3<Real>& other)
{
  for (auto i = 0; i < 9; ++i)
    data[i] += other.data[i];

  return *this;
}

template<typename Real>
Math::Matrix3<Real>& Math::Matrix3<Real>::operator-= (const Math::Matrix3<Real>& other)
{
  for (auto i = 0; i < 9; ++i)
    data[i] -= other.data[i];

  return *this;
}

template<typename Real>
Real Math::Matrix3<Real>::determinant () const
{
  return  data[0] * (data[4]*data[8] - data[5]*data[7]) -
    data[1] * (data[3]*data[8] - data[5]*data[6]) +
    data[2] * (data[3]*data[7] - data[4]*data[6]);
}

template<typename Real>
Real Math::Matrix3<Real>::trace () const
{
  return data[0] + data[4] + data[8];
}

template<typename Real>
Math::Matrix3<Real> Math::Matrix3<Real>::transpose () const
{
  return Matrix3<Real> (data[0], data[3], data[6],
      data[1], data[4], data[7],
      data[2], data[5], data[8]);
}

template<typename Real>
Math::Matrix3<Real> Math::Matrix3<Real>::inverse () const
{
  auto det = determinant ();

  if (det == 0)
    throw inverse_of_singular_matrix_exception ();

  auto trans = transpose ();

  Matrix3<Real> result;
  result[0] = trans[4] * trans[8] - trans[5] * trans[7];
  result[1] = - (trans[3] * trans[8] - trans[5] * trans[6]);
  result[2] = trans[3] * trans[7] - trans[4] * trans[6];

  result[3] = - (trans[1] * trans[8] - trans[2] * trans[7]);
  result[4] = trans[0] * trans[8] - trans[2] * trans[6];
  result[5] = - (trans[0] * trans[7] - trans[1] * trans[6]);

  result[6] = trans[1] * trans[5] - trans[2] * trans[4];
  result[7] = - (trans[0] * trans[5] - trans[2] * trans[3]);
  result[8] = trans[0] * trans[4] - trans[1] * trans[3];

  return result / det;
}

template<typename Real>
Math::Matrix3<Real> Math::operator* (const Matrix3<Real>& matrix, const Real& scalar)
{
  auto result (matrix);
  result *= scalar;
  return result;
}

template<typename Real>
Math::Matrix3<Real> Math::operator* (const Real& scalar, const Matrix3<Real>& matrix)
{
  return matrix * scalar;
}

template<typename Real>
Math::Matrix3<Real> Math::operator/ (const Matrix3<Real>& matrix, const Real& scalar)
{
  auto result = matrix;
  result /= scalar;
  return result;
}

template<typename Real>
Math::Matrix3<Real> Math::operator+ (const Matrix3<Real>& left, const Matrix3<Real>& right)
{
  Matrix3<Real> result (left);
  result += right;
  return result;
}

template<typename Real>
Math::Matrix3<Real> Math::operator- (const Matrix3<Real>& left, const Matrix3<Real>& right)
{
  Matrix3<Real> result (left);
  result -= right;
  return result;
}

template<typename Real>
Math::Matrix3<Real> Math::operator* (const Matrix3<Real>& left, const Matrix3<Real>& right)
{
  Matrix3<Real> result;

  result (0,0) = left (0,0) * right (0,0) + left (0,1) * right (1,0) + left (0,2) * right (2,0);
  result (0,1) = left (0,0) * right (0,1) + left (0,1) * right (1,1) + left (0,2) * right (2,1);
  result (0,2) = left (0,0) * right (0,2) + left (0,1) * right (1,2) + left (0,2) * right (2,2);

  result (1,0) = left (1,0) * right (0,0) + left (1,1) * right (1,0) + left (1,2) * right (2,0);
  result (1,1) = left (1,0) * right (0,1) + left (1,1) * right (1,1) + left (1,2) * right (2,1);
  result (1,2) = left (1,0) * right (0,2) + left (1,1) * right (1,2) + left (1,2) * right (2,2);

  result (2,0) = left (2,0) * right (0,0) + left (2,1) * right (1,0) + left (2,2) * right (2,0);
  result (2,1) = left (2,0) * right (0,1) + left (2,1) * right (1,1) + left (2,2) * right (2,1);
  result (2,2) = left (2,0) * right (0,2) + left (2,1) * right (1,2) + left (2,2) * right (2,2);

  return result;
}

template<typename Real>
bool Math::operator== (const Matrix3<Real>& left, const Matrix3<Real>& right)
{
  return left.get_data () == right.get_data ();
}

template<typename Real>
bool Math::operator!= (const Matrix3<Real>& left, const Matrix3<Real>& right)
{
  return !operator== (left, right);
}

template<typename Real>
Math::Matrix3<Real>::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& i)
  : index (i), row (0), col (0)
{ }

template<typename Real>
Math::Matrix3<Real>::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& row, const size_t& col)
  : index (0), row (row), col (col)
{ }

template<typename Real>
const char* Math::Matrix3<Real>::index_operator_out_of_range_exception::what () const throw ()
{
  if (index == 0)
    return create_message_from_row_col ();
  return create_message_from_index ();
}

template<typename Real>
const char* Math::Matrix3<Real>::index_operator_out_of_range_exception::create_message_from_index () const
{
  std::stringstream out;
  out << "Tried to access index: " << index;
  return out.str ().c_str ();
}

template<typename Real>
const char* Math::Matrix3<Real>::index_operator_out_of_range_exception::create_message_from_row_col () const
{
  std::stringstream out;
  out << "Tried to access: (" << row << ", " << col << ")";
  return out.str ().c_str ();
}

#endif // MATH_MATRIX3_H_INCLUDED
