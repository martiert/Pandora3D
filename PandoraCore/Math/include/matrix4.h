#ifndef MATH_MATRIX4_H_INCLUDED
#define MATH_MATRIX4_H_INCLUDED

#include "matrix3.h"
#include "vector4.h"

#include <type_traits>
#include <stdexcept>

namespace Math
{
    template<typename T, class Enable = void>
    class Matrix4;

    template<typename T>
    class Matrix4<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>
    {
        public:
            Matrix4 ();

            Matrix4 (const T& a00, const T& a01, const T& a02, const T& a03,
                     const T& a10, const T& a11, const T& a12, const T& a13,
                     const T& a20, const T& a21, const T& a22, const T& a23,
                     const T& a30, const T& a31, const T& a32, const T& a33);

            Matrix4 (const T array[16]);
            Matrix4 (const Matrix3<T>& matrix);

            T& operator () (const size_t& i, const size_t& j);
            T operator () (const size_t& i, const size_t& j) const;

            T& operator[] (const size_t& i);
            T operator[] (const size_t& i) const;

            operator T* ();
            operator const T* () const;

            Matrix4& operator*= (const T& scalar);
            Matrix4& operator/= (const T& scalar);
            Matrix4& operator+= (const Matrix4 other);
            Matrix4& operator-= (const Matrix4 other);

            Matrix4 transpose () const;
            Matrix4 inverse () const;

            T trace () const;
            T determinant () const;

            const static Matrix4 IDENTITY;
            const static Matrix4 ZERO;
        private:
            T data[16];

            T calculate_sub_determinant (const size_t& row, const size_t& column) const;
    };

    typedef Matrix4<double> Matrix4d;
    typedef Matrix4<float> Matrix4f;
    typedef Matrix4<int> Matrix4i;
    typedef Matrix4<unsigned int> Matrix4u;

    template<typename T>
    Matrix4<T> operator* (const Matrix4<T>& matrix, const T& scalar);

    template<typename T>
    Matrix4<T> operator* (const T& scalar, const Matrix4<T>& matrix);

    template<typename T>
    Vector4<T> operator* (const Matrix4<T>& matrix, const Vector4<T>& vector);

    template<typename T>
    Vector4<T> operator* (const Vector4<T>& vector, const Matrix4<T>& matrix);

    template<typename T>
    Matrix4<T> operator* (const Matrix4<T>& left, const Matrix4<T>& right);

    template<typename T>
    Matrix4<T> operator/ (const Matrix4<T>& matrix, const T& scalar);

    template<typename T>
    Matrix4<T> operator+ (const Matrix4<T>& left, const Matrix4<T>& right);

    template<typename T>
    Matrix4<T> operator- (const Matrix4<T>& left, const Matrix4<T>& right);

#define MATRIX4_INCLUDE_FILE
#include "matrix4-impl.h"
#undef MATRIX4_INCLUDE_FILE
}
#endif // MATH_MATRIX4_H_INCLUDED
