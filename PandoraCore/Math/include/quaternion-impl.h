#ifdef QUATERNION_INCLUDE_FILE

template<typename T>
using Quatdef = Quat<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>;

template<typename T>
Quatdef<T>::Quat ()
    : real (1)
{ }

template<typename T>
Quatdef<T>::Quat (const T& w, const T& x, const T& y, const T& z)
    : real (w), imag (x, y, z)
{ }

template<typename T>
Quatdef<T>::Quat (const T array[4])
    : real (array[0]), imag (array[1], array[2], array[3])
{ }

template<typename T>
Quatdef<T>::Quat (const T& real, const Vector3<T>& imaginary_vector)
    : real (real), imag (imaginary_vector)
{ }

template<typename T>
Quatdef<T>::Quat (const Matrix4<T>& matrix)
    : real (1)
{ }

template<typename T>
T& Quatdef<T>::w ()
{
    return real;
}

template<typename T>
T Quatdef<T>::w () const
{
    return real;
}

template<typename T>
T& Quatdef<T>::x ()
{
    return imag.x;
}

template<typename T>
T Quatdef<T>::x () const
{
    return imag.x;
}

template<typename T>
T& Quatdef<T>::y ()
{
    return imag.y;
}

template<typename T>
T Quatdef<T>::y () const
{
    return imag.y;
}

template<typename T>
T& Quatdef<T>::z ()
{
    return imag.z;
}

template<typename T>
T Quatdef<T>::z () const
{
    return imag.z;
}

template<typename T>
Quatdef<T> Quatdef<T>::operator+= (const Quat& other)
{
    real += other.real;
    imag += other.imag;
    return *this;
}

template<typename T>
Quatdef<T> Quatdef<T>::operator-= (const Quat& other)
{
    real -= other.real;
    imag -= other.imag;
    return *this;
}

template<typename T>
Quatdef<T> Quatdef<T>::operator*= (const T& scalar)
{
    real *= scalar;
    imag *= scalar;
    return *this;
}

template<typename T>
Quatdef<T> Quatdef<T>::operator/= (const T& scalar)
{
    real /= scalar;
    imag /= scalar;
    return *this;
}

template<typename T>
Matrix4<T> Quatdef<T>::create_matrix () const
{
    return Matrix4<T> ();
}

template<typename T>
T Quatdef<T>::norm () const
{
    return std::sqrt (imag.dot (imag) + real * real);
}

template<typename T>
Quatdef<T> Quatdef<T>::conjugate () const
{
    return Quatdef<T> (real, -imag);
}

template<typename T>
Quatdef<T> Quatdef<T>::inverse () const
{
    const auto normsquared = imag.lengthSquared () + (real * real);

    return conjugate () / normsquared;
}

template<typename T>
Quat<T> operator+ (const Quat<T>& left, const Quat<T>& right)
{
    Quat<T> res = left;
    res += right;
    return res;
}

template<typename T>
Quat<T> operator- (const Quat<T>& left, const Quat<T>& right)
{
    Quat<T> res = left;
    res -= right;
    return res;
}

template<typename T>
Quat<T> operator* (const Quat<T>& left, const Quat<T>& right)
{
    return Quat<T> (left.w () * right.w () - left.imag.dot (right.imag),
                    left.imag.cross (right.imag) + left.real * right.imag + right.real * left.imag);
}

template<typename T>
Quat<T> operator* (const Quat<T>& quaternion, const T& scalar)
{
    Quat<T> res = quaternion;
    res *= scalar;
    return res;
}

template<typename T>
Quat<T> operator/ (const Quat<T>& quaternion, const T& scalar)
{
    Quat<T> res = quaternion;
    res /= scalar;
    return res;
}

#else // QUATERNION_INCLUDE_FILE
#error "Only include this file from quaternion.h"
#endif // QUATERNION_INCLUDE_FILE
