#ifndef MATH_VECTOR3_HPP_INCLUDED
#define MATH_VECTOR3_HPP_INCLUDED

#include <stdexcept>
#include <cmath>

namespace Math
{
    template<typename T>
    class Vector3
    {
        public:
            Vector3 ();
            Vector3 (const T& x, const T& y, const T& z);
            Vector3 (const Vector3& vec);
            Vector3 (const T data[3]);

            T& x ();
            T& y ();
            T& z ();

            T x () const;
            T y () const;
            T z () const;

            T& operator[] (const size_t i);
            T operator[] (const size_t i) const;

            Vector3& operator+= (const Vector3& vec);
            Vector3& operator-= (const Vector3& vec);
            Vector3& operator*= (const Vector3& vec);
            Vector3& operator*= (const T& scalar);
            Vector3& operator/= (const T& scalar);

            T dot (const Vector3& vec) const;

            T length () const;
            T lengthSquared () const;

            void normalize ();

            Vector3 cross (const Vector3& other) const;
        private:
            T _x;
            T _y;
            T _z;
    };

    template<typename T>
    Vector3<T> operator- (const Vector3<T>& vec);

    template<typename T>
    Vector3<T> operator+ (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    Vector3<T> operator- (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    Vector3<T> operator* (const Vector3<T>& vec, const T& scalar);

    template<typename T>
    Vector3<T> operator* (const T& scalar, const Vector3<T>& vec);

    template<typename T>
    Vector3<T> operator* (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    Vector3<T> operator/ (const Vector3<T>& vec, const T& scalar);

    template<typename T>
    bool operator== (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    bool operator!= (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    bool operator< (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    bool operator> (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    bool operator<= (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    bool operator>= (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    void generateOrthonormalBasis (Vector3<T>& vec1, Vector3<T>& vec2, Vector3<T>& vec3);

#define VECTOR3_INCLUDE_FILE
#include "vector3-impl.h"
#undef VECTOR3_INCLUDE_FILE

    typedef Vector3<float> Vec3f;
    typedef Vector3<double> Vec3d;
    typedef Vector3<int> Vec3i;
    typedef Vector3<unsigned int> Vec3u;
}

#endif // MATH_VECTOR3_HPP_INCLUDED
