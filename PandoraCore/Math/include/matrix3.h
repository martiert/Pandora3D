#ifndef MATH_MATRIX3_H_INCLUDED
#define MATH_MATRIX3_H_INCLUDED

#include <stdexcept>

namespace Math
{
    template<typename T>
    class Matrix3
    {
        public:
            Matrix3 ();
            Matrix3 (const T& m00, const T& m01, const T& m02,
                     const T& m10, const T& m11, const T& m12,
                     const T& m20, const T& m21, const T& m22);
            Matrix3 (const T array[9]);

            T& operator () (const size_t& i, const size_t& j);
            T operator () (const size_t& i, const size_t& j) const;

            T& operator [] (const size_t& i);
            T operator [] (const size_t& i) const;

            operator T* ();
            operator const T* () const;

            Matrix3& operator*= (const T& scalar);
            Matrix3& operator/= (const T& scalar);
            Matrix3& operator+= (const Matrix3& other);
            Matrix3& operator-= (const Matrix3& other);

            T determinant () const;
            T trace () const;

            Matrix3 transpose () const;

            Matrix3 inverse () const;

            const static Matrix3 IDENTITY;
            const static Matrix3 ZERO;
        private:
            T data[9];
    };

    typedef Matrix3<double> Matrix3d;
    typedef Matrix3<float> Matrix3f;
    typedef Matrix3<int> Matrix3i;
    typedef Matrix3<unsigned int> Matrix3u;

    template<typename T>
    Matrix3<T> operator* (const Matrix3<T>& matrix, const T& scalar);

    template<typename T>
    Matrix3<T> operator* (const T& scalar, const Matrix3<T>& matrix);

    template<typename T>
    Matrix3<T> operator/ (const Matrix3<T>& matrix, const T& scalar);

    template<typename T>
    Matrix3<T> operator+ (const Matrix3<T>& left, const Matrix3<T>& right);

    template<typename T>
    Matrix3<T> operator- (const Matrix3<T>& left, const Matrix3<T>& right);

    template<typename T>
    Matrix3<T> operator* (const Matrix3<T>& left, const Matrix3<T>& right);

    template<typename T>
    bool operator== (const Matrix3<T>& left, const Matrix3<T>& right);

    template<typename T>
    bool operator!= (const Matrix3<T>& left, const Matrix3<T>& right);

#define MATRIX3_INCLUDE_FILE
#include "matrix3-impl.h"
#undef MATRIX3_INCLUDE_FILE
}

#endif // MATH_MATRIX3_H_INCLUDED
