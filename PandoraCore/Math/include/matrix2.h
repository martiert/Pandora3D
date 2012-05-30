#ifndef MATH_MATRIX2_H_INCLUDED
#define MATH_MATRIX2_H_INCLUDED

#include "vector2.h"

#include <exception>
#include <algorithm>

typedef double Real;

namespace Math
{
    class Matrix2
    {
        public:
            Matrix2 ();
            Matrix2 (const Real& m00, const Real& m01, const Real& m10, const Real&  m11);
            Matrix2 (const Real array[4]);

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
                    index_operator_out_of_range_exception (const size_t& row, const size_t& col)
                        : row (row), col (col)
                    {}

                    virtual const char* what () const throw ()
                    {
                        std::string error ("Realried to access: (");
                        error += row;
                        error += ", ";
                        error += col;
                        error += ")";
                        return error.c_str ();
                    }
                private:
                    size_t row;
                    size_t col;
            };
    };

    Matrix2 operator+ (const Matrix2& lmatrix, const Matrix2& rmatrix);

    Matrix2 operator- (const Matrix2& lmatrix, const Matrix2& rmatrix);

    Matrix2 operator* (const Matrix2& lmatrix, const Matrix2& rmatrix);

    Matrix2 operator* (const Matrix2& matrix, const Real& scalar);

    Vector2 operator* (const Matrix2& matrix, const Vector2& vector);

    Vector2 operator* (const Vector2& vector, const Matrix2& matrix);

    Matrix2 operator* (const Real& scalar, const Matrix2& matrix);

    Matrix2 operator/ (const Matrix2& matrix, const Real& scalar);

    bool operator== (const Matrix2& lmatrix, const Matrix2& rmatrix);

    bool operator!= (const Matrix2& lmatrix, const Matrix2& rmatrix);
}

#endif // MATH_MATRIX2_H_INCLUDED
