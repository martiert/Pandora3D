#ifndef MATH_MATRIX2_H_INCLUDED
#define MATH_MATRIX2_H_INCLUDED

#include "vector2.h"

#include <type_traits>
#include <exception>
#include <algorithm>

namespace Math
{
    template<typename T, class Enable = void>
    class Matrix2;

    template<typename T>
    class Matrix2<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>
    {
        public:
            Matrix2 ();
            Matrix2 (const T& m00, const T& m01, const T& m10, const T&  m11);
            Matrix2 (const T array[4]);

            T& operator () (const size_t& i, const size_t& j);
            T operator () (const size_t& i, const size_t& j) const;
            operator T* ();
            operator const T* () const;

            Matrix2& operator+= (const Matrix2& matrix);
            Matrix2& operator-= (const Matrix2& matrix);
            Matrix2& operator*= (const T& scalar);
            Matrix2& operator/= (const T& scalar);

            T determinant () const;
            Matrix2 transpose () const;
            Matrix2 inverse () const;

            const static Matrix2 IDENTITY;
            const static Matrix2 ZERO;
        private:
            T data[4];

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
                        std::string error ("Tried to access: (");
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

    typedef Matrix2<double> Matrix2d;
    typedef Matrix2<float> Matrix2f;
    typedef Matrix2<int> Matrix2i;
    typedef Matrix2<unsigned int> Matrix2u;

    template<typename T>
    Matrix2<T> operator+ (const Matrix2<T>& lmatrix, const Matrix2<T>& rmatrix);

    template<typename T>
    Matrix2<T> operator- (const Matrix2<T>& lmatrix, const Matrix2<T>& rmatrix);

    template<typename T>
    Matrix2<T> operator* (const Matrix2<T>& lmatrix, const Matrix2<T>& rmatrix);

    template<typename T>
    Matrix2<T> operator* (const Matrix2<T>& matrix, const T& scalar);

    template<typename T>
    Vector2<T> operator* (const Matrix2<T>& matrix, const Vector2<T>& vector);

    template<typename T>
    Vector2<T> operator* (const Vector2<T>& vector, const Matrix2<T>& matrix);

    template<typename T>
    Matrix2<T> operator* (const T& scalar, const Matrix2<T>& matrix);

    template<typename T>
    Matrix2<T> operator/ (const Matrix2<T>& matrix, const T& scalar);

    template<typename T>
    bool operator== (const Matrix2<T>& lmatrix, const Matrix2<T>& rmatrix);

    template<typename T>
    bool operator!= (const Matrix2<T>& lmatrix, const Matrix2<T>& rmatrix);

#define MATRIX2_INCLUDE_FILE
#include "matrix2-impl.h"
#undef MATRIX2_INCLUDE_FILE
}

#endif // MATH_MATRIX2_H_INCLUDED
