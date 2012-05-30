#ifndef MATH_MATRIX4_H_INCLUDED
#define MATH_MATRIX4_H_INCLUDED

#include "mathconfig.h"
#include "matrix3.h"
#include "vector4.h"

#include <exception>

namespace Math
{
    class Matrix4
    {
        public:
            Matrix4 ();

            Matrix4 (const Real& a00, const Real& a01, const Real& a02, const Real& a03,
                     const Real& a10, const Real& a11, const Real& a12, const Real& a13,
                     const Real& a20, const Real& a21, const Real& a22, const Real& a23,
                     const Real& a30, const Real& a31, const Real& a32, const Real& a33);

            Matrix4 (const Real array[16]);
            Matrix4 (const Matrix3& matrix);

            Real& operator () (const size_t& i, const size_t& j);
            Real operator () (const size_t& i, const size_t& j) const;

            Real& operator[] (const size_t& i);
            Real operator[] (const size_t& i) const;

            operator Real* ();
            operator const Real* () const;

            Matrix4& operator*= (const Real& scalar);
            Matrix4& operator/= (const Real& scalar);
            Matrix4& operator+= (const Matrix4 other);
            Matrix4& operator-= (const Matrix4 other);

            Matrix4 transpose () const;
            Matrix4 inverse () const;

            Real trace () const;
            Real determinant () const;

            const static Matrix4 IDENTITY;
            const static Matrix4 ZERO;
        private:
            Real data[16];

            Real calculate_sub_determinant (const size_t& row, const size_t& column) const;

        public:
            class division_by_zero_exception : public std::exception { };

            class inverse_of_singular_matrix_exception : public std::exception { };

            class index_operator_out_of_range_exception : public std::exception
            {
                public:
                    index_operator_out_of_range_exception (const size_t& i)
                        : index (i), row (0), col (0)
                    { };

                    index_operator_out_of_range_exception (const size_t& row, const size_t& col)
                        : index (0), row (row), col (col)
                    {}

                    virtual const char* what () const throw ()
                    {
                        if (index == 0)
                            return get_from_row_col_input ();
                        return get_from_single_input ();
                    }

                    const char* get_from_single_input () const
                    {
                        std::string error = "Realried to access index: " + index;
                        return error.c_str ();
                    }

                    const char* get_from_row_col_input () const
                    {
                        std::string error = "Realried to access index: (" + row;
                        error += ", " + col;
                        error += ")";
                        return error.c_str ();
                    }
                private:
                    size_t index;
                    size_t row;
                    size_t col;
            };

    };

    Matrix4 operator* (const Matrix4& matrix, const Real& scalar);

    Matrix4 operator* (const Real& scalar, const Matrix4& matrix);

    Vector4 operator* (const Matrix4& matrix, const Vector4& vector);

    Vector4 operator* (const Vector4& vector, const Matrix4& matrix);

    Matrix4 operator* (const Matrix4& left, const Matrix4& right);

    Matrix4 operator/ (const Matrix4& matrix, const Real& scalar);

    Matrix4 operator+ (const Matrix4& left, const Matrix4& right);

    Matrix4 operator- (const Matrix4& left, const Matrix4& right);
}
#endif // MATH_MATRIX4_H_INCLUDED
