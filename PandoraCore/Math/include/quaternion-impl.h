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
    : real (0.5 * std::sqrt (matrix.trace ()))
{
    const auto u = matrix.trace () - 1;
    if (u > matrix (0,0) && u > matrix (1,1) && u > matrix (2,2))
        create_quaternion_from_matrix_with_largest_u (matrix);
    else
        create_quaternion_from_matrix_with_smallest_u (matrix);
}

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
    if (scalar == 0)
        throw division_by_zero_exception ();

    real /= scalar;
    imag /= scalar;
    return *this;
}

template<typename T>
Matrix4<T> Quatdef<T>::create_matrix () const
{
    const auto quat_norm = norm ();

    if (quat_norm == 0)
        throw can_not_make_matrix_from_zero_quaternion_exception ();

    const auto s = 2.0 / quat_norm;
    return create_matrix_with_scale (s);
}

template<typename T>
Matrix4<T> Quatdef<T>::create_matrix_with_scale (const T& s) const
{
    Matrix4<T> result;

    result (0,0) -= s * (imag.y * imag.y + imag.z * imag.z);
    result (0,1) += s * (imag.x * imag.y - real * imag.z);
    result (0,2) += s * (imag.x * imag.z + real * imag.y);

    result (1,0) += s * (imag.x * imag.y + real * imag.z);
    result (1,1) -= s * (imag.x * imag.x + imag.z * imag.z);
    result (1,2) += s * (imag.y * imag.z - real * imag.x);

    result (2,0) += s * (imag.x * imag.z - real * imag.y);
    result (2,1) += s * (imag.y * imag.z + real * imag.x);
    result (2,2) -= s * (imag.x * imag.x + imag.y * imag.y);

    return result;
}

template<typename T>
T Quatdef<T>::norm () const
{
    return std::sqrt (imag.dot (imag) + real * real);
}

template<typename T>
void Quatdef<T>::normalize ()
{
    auto scale = norm ();

    if (scale == 0)
        throw normalizing_zero_quaternion_exception ();

    real /= scale;
    imag /= scale;
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

template<typename T>
void Quatdef<T>::create_quaternion_from_matrix_with_largest_u (const Matrix4<T>& matrix)
{
    imag.x = matrix (2,1) - matrix (1,2);
    imag.y = matrix (0,2) - matrix (2,0);
    imag.z = matrix (1,0) - matrix (0,1);

    imag /= (4 * real);
}

template<typename T>
void Quatdef<T>::create_quaternion_from_matrix_with_smallest_u (const Matrix4<T>& matrix)
{
    imag.x = std::sqrt (matrix (0,0) - matrix (1,1) - matrix (2,2) + matrix (3,3));
    imag.y = std::sqrt (-matrix (0,0) + matrix (1,1) - matrix (2,2) + matrix (3,3));
    imag.z = std::sqrt (-matrix (0,0) - matrix (1,1) + matrix (2,2) + matrix (3,3));

    imag *= 0.4;
}

#else // QUATERNION_INCLUDE_FILE
#error "Only include this file from quaternion.h"
#endif // QUATERNION_INCLUDE_FILE
