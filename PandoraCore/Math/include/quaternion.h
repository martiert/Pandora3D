#ifndef MATH_QUATERNION_H_INCLUDED
#define MATH_QUATERNION_H_INCLUDED

#include "vector3.h"
#include "matrix4.h"
#include <type_traits>

namespace Math
{
    template<typename T, class Enable = void>
    class Quat;


    template<typename T>
    class Quat<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>
    {
        public:
            Quat ();

            Quat (const T& w, const T& x, const T& y, const T& z);

            Quat (const T array[4]);

            Quat (const T& real, const Vector3<T>& imaginary_vector);

            Quat (const Matrix4<T>& matrix);

            T& w ();
            T w () const;

            T& x ();
            T x () const;

            T& y ();
            T y () const;

            T& z ();
            T z () const;

        protected:
            T real;
            Vector3<T> imag;
    };

    typedef Quat<double> Quat4d;

#define QUATERNION_INCLUDE_FILE
#include "quaternion-impl.h"
#undef QUATERNION_INCLUDE_FILE
}

#endif // MATH_QUATERNION_H_INCLUDED
