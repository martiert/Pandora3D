#ifndef MATH_MATRIX4_H_INCLUDED
#define MATH_MATRIX4_H_INCLUDED

#include "matrix3.h"
#include <stdexcept>

namespace Math
{
    template<typename T>
    class Matrix4
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
        private:
            T data[16];

    };

    typedef Matrix4<double> Matrix4d;
    typedef Matrix4<float> Matrix4f;
    typedef Matrix4<int> Matrix4i;
    typedef Matrix4<unsigned int> Matrix4u;

#define MATRIX4_INCLUDE_FILE
#include "matrix4-impl.h"
#undef MATRIX4_INCLUDE_FILE
}
#endif // MATH_MATRIX4_H_INCLUDED
