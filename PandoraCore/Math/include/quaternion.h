#ifndef MATH_QUATERNION_H_INCLUDED
#define MATH_QUATERNION_H_INCLUDED

#include "vector3.h"
#include "matrix4.h"
#include <type_traits>
#include <exception>

namespace Math
{
    class can_not_normalize_zero_quaternion_exception : public std::exception
    { };

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
            T& x ();
            T& y ();
            T& z ();

            T w () const;
            T x () const;
            T y () const;
            T z () const;

            Quat operator+= (const Quat& other);
            Quat operator-= (const Quat& other);
            Quat operator*= (const T& scalar);
            Quat operator/= (const T& scalar);

            Matrix4<T> create_matrix () const;

            T norm () const;
            void normalize ();

            Quat conjugate () const;
            Quat inverse () const;

        public:
            T real;
            Vector3<T> imag;
    };

    typedef Quat<double> Quat4d;

    template<typename T>
    Quat<T> operator+ (const Quat<T>& left, const Quat<T>& right);

    template<typename T>
    Quat<T> operator- (const Quat<T>& left, const Quat<T>& right);

    template<typename T>
    Quat<T> operator* (const Quat<T>& left, const Quat<T>& right);

    template<typename T>
    Quat<T> operator* (const Quat<T>& quaternion, const T& scalar);

    template<typename T>
    Quat<T> operator/ (const Quat<T>& quaternion, const T& scalar);

#define QUATERNION_INCLUDE_FILE
#include "quaternion-impl.h"
#undef QUATERNION_INCLUDE_FILE
}

#endif // MATH_QUATERNION_H_INCLUDED
