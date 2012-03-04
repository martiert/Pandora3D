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
            Vector4 ();
            Vector4 (const T& x, const T& y, const T& z, const T& w);
            Vector4 (const Vector4& vec);
            Vector4 (const T data[4]);
            Vector4 (const Vector3<T>& vec);

            T& x ();
            T& y ();
            T& z ();
            T& w ();

            T x () const;
            T y () const;
            T z () const;
            T w () const;

            T& operator[] (const size_t i);
            T operator[] (const size_t i) const;

            Vector4& operator+= (const Vector4& vec);
            Vector4& operator-= (const Vector4& vec);

            T length () const;
            T lengthSquared () const;

            Vector4& normalize ();
        private:
            T _x;
            T _y;
            T _z;
            T _w;
    };

    template<typename T>
    Vector4<T> operator- (const Vector4<T>& vec);

    template<typename T>
    Vector4<T> operator+ (const Vector4<T>& vec_1, const Vector4<T>& vec_2);

    template<typename T>
    Vector4<T> operator- (const Vector4<T>& vec_1, const Vector4<T>& vec_2);

#define VECTOR4_INCLUDE_FILE
#include "vector4-impl.h"
#undef VECTOR4_INCLUDE_FILE

    typedef Vector4<float> Vec4f;
    typedef Vector4<double> Vec4d;
    typedef Vector4<int> Vec4i;
    typedef Vector4<unsigned int> Vec4u;
}

#endif // MATH_VECTOR4_HPP_INCLUDED
