#ifndef MATH_VECTOR4_HPP_INCLUDED
#define MATH_VECTOR4_HPP_INCLUDED

#include "vector3.h"
#include <stdexcept>

namespace Math
{
    template<typename T>
    class Vector4
    {
        public:
            T x;
            T y;
            T z;
            T w;

        public:
            Vector4 ();
            Vector4 (const T& x, const T& y, const T& z, const T& w);
            Vector4 (const Vector4& vec);
            Vector4 (const T data[4]);
            Vector4 (const Vector3<T>& vec);

            T& operator[] (const size_t i);
            T operator[] (const size_t i) const;
            operator T* ();
            operator const T* () const;

            Vector4& operator+= (const Vector4& vec);
            Vector4& operator-= (const Vector4& vec);
            Vector4& operator*= (const Vector4& vec);

            Vector4& operator*= (const T& scalar);
            Vector4& operator/= (const T& scalar);

            T length () const;
            T lengthSquared () const;

            T dot (const Vector4& vec) const;

            Vector4& normalize ();
    };

    template<typename T>
    Vector4<T> operator- (const Vector4<T>& vec);

    template<typename T>
    Vector4<T> operator+ (const Vector4<T>& vec_1, const Vector4<T>& vec_2);

    template<typename T>
    Vector4<T> operator- (const Vector4<T>& vec_1, const Vector4<T>& vec_2);

    template<typename T>
    Vector4<T> operator* (const Vector4<T>& vec_1, const Vector4<T>& vec_2);

    template<typename T>
    Vector4<T> operator* (const Vector4<T>& vec, const T& scalar);

    template<typename T>
    Vector4<T> operator* (const T& scalar, const Vector4<T>& vec);

    template<typename T>
    Vector4<T> operator/ (const Vector4<T>& vec, const T& scalar);

    template<typename T>
    bool operator== (const Vector4<T>& vec1, const Vector4<T>& vec2);

    template<typename T>
    bool operator!= (const Vector4<T>& vec1, const Vector4<T>& vec2);

    template<typename T>
    bool operator> (const Vector4<T>& vec1, const Vector4<T>& vec2);

    template<typename T>
    bool operator< (const Vector4<T>& vec1, const Vector4<T>& vec2);

    template<typename T>
    bool operator>= (const Vector4<T>& vec1, const Vector4<T>& vec2);

    template<typename T>
    bool operator<= (const Vector4<T>& vec1, const Vector4<T>& vec2);

#define VECTOR4_INCLUDE_FILE
#include "vector4-impl.h"
#undef VECTOR4_INCLUDE_FILE

    typedef Vector4<float> Vec4f;
    typedef Vector4<double> Vec4d;
    typedef Vector4<int> Vec4i;
    typedef Vector4<unsigned int> Vec4u;
}

#endif // MATH_VECTOR4_HPP_INCLUDED
