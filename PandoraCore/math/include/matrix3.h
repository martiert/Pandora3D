#ifndef MATH_MATRIX3_H_INCLUDED
#define MATH_MATRIX3_H_INCLUDED

#include "config.h"

#include <exception>

namespace Math
{
  class Matrix3
  {
    public:
      Matrix3 ();
      Matrix3 (const Real& m00, const Real& m01, const Real& m02,
          const Real& m10, const Real& m11, const Real& m12,
          const Real& m20, const Real& m21, const Real& m22);
      Matrix3 (const Real array[9]);

      Real& operator () (const size_t& i, const size_t& j);
      Real operator () (const size_t& i, const size_t& j) const;

      Real& operator [] (const size_t& i);
      Real operator [] (const size_t& i) const;

      operator Real* ();
      operator const Real* () const;

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
      Real data[9];

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

  Matrix3 operator* (const Matrix3& matrix, const Real& scalar);

  Matrix3 operator* (const Real& scalar, const Matrix3& matrix);

  Matrix3 operator/ (const Matrix3& matrix, const Real& scalar);

  Matrix3 operator+ (const Matrix3& left, const Matrix3& right);

  Matrix3 operator- (const Matrix3& left, const Matrix3& right);

  Matrix3 operator* (const Matrix3& left, const Matrix3& right);

  bool operator== (const Matrix3& left, const Matrix3& right);

  bool operator!= (const Matrix3& left, const Matrix3& right);
}

#endif // MATH_MATRIX3_H_INCLUDED
