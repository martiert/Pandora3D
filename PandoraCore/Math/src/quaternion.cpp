#include "quaternion.h"

Math::Quaternion::Quaternion ()
    : real (1)
{ }

Math::Quaternion::Quaternion (const Real& w, const Real& x, const Real& y, const Real& z)
    : real (w), imag (x, y, z)
{ }

Math::Quaternion::Quaternion (const Real array[4])
    : real (array[0]), imag (array[1], array[2], array[3])
{ }

Math::Quaternion::Quaternion (const Real& real, const Vector3& imaginary_vector)
    : real (real), imag (imaginary_vector)
{ }

Math::Quaternion::Quaternion (const Vector3& axis, const Real& angle)
    : real (std::cos (angle)), imag (axis * std::sin (angle))
{ }

Math::Quaternion::Quaternion (const Matrix4& matrix)
    : real (0.5 * std::sqrt (matrix.trace ()))
{
    const auto u = matrix.trace () - 1;
    if (u > matrix (0,0) && u > matrix (1,1) && u > matrix (2,2))
        create_quaternion_from_matrix_with_largest_u (matrix);
    else
        create_quaternion_from_matrix_with_smallest_u (matrix);
}

Real& Math::Quaternion::w ()
{
    return real;
}

Real Math::Quaternion::w () const
{
    return real;
}

Real& Math::Quaternion::x ()
{
    return imag.x;
}

Real Math::Quaternion::x () const
{
    return imag.x;
}

Real& Math::Quaternion::y ()
{
    return imag.y;
}

Real Math::Quaternion::y () const
{
    return imag.y;
}

Real& Math::Quaternion::z ()
{
    return imag.z;
}

Real Math::Quaternion::z () const
{
    return imag.z;
}

Math::Quaternion Math::Quaternion::operator+= (const Quaternion& other)
{
    real += other.real;
    imag += other.imag;
    return *this;
}

Math::Quaternion Math::Quaternion::operator-= (const Quaternion& other)
{
    real -= other.real;
    imag -= other.imag;
    return *this;
}

Math::Quaternion Math::Quaternion::operator*= (const Real& scalar)
{
    real *= scalar;
    imag *= scalar;
    return *this;
}

Math::Quaternion Math::Quaternion::operator/= (const Real& scalar)
{
    if (scalar == 0)
        throw division_by_zero_exception ();

    real /= scalar;
    imag /= scalar;
    return *this;
}

Math::Matrix4 Math::Quaternion::create_matrix () const
{
    const auto quat_norm = norm ();

    if (quat_norm == 0)
        throw can_not_make_matrix_from_zero_quaternion_exception ();

    const auto s = 2.0 / quat_norm;
    return create_matrix_with_scale (s);
}

Math::Matrix4 Math::Quaternion::create_matrix_with_scale (const Real& s) const
{
    Matrix4 result;

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

Real Math::Quaternion::norm () const
{
    return std::sqrt (imag.dot (imag) + real * real);
}

void Math::Quaternion::normalize ()
{
    auto scale = norm ();

    if (scale == 0)
        throw normalizing_zero_quaternion_exception ();

    real /= scale;
    imag /= scale;
}

Math::Quaternion Math::Quaternion::conjugate () const
{
    return Quaternion (real, -imag);
}

Math::Quaternion Math::Quaternion::inverse () const
{
    const auto normsquared = imag.lengthSquared () + (real * real);

    return conjugate () / normsquared;
}

Math::Quaternion Math::Quaternion::slerp (const Quaternion& from, const Quaternion& to, const Real& t)
{
    const auto angle = std::acos (from.real * to.real + from.imag.dot (to.imag));
    const auto from_scale = std::sin (angle * (1 - t))/std::sin (angle);
    const auto to_scale = std::sin (angle * t)/std::sin (angle);
    return from * from_scale + to * to_scale;
}

Math::Quaternion Math::operator+ (const Quaternion& left, const Quaternion& right)
{
    Quaternion res = left;
    res += right;
    return res;
}

Math::Quaternion Math::operator- (const Quaternion& left, const Quaternion& right)
{
    Quaternion res = left;
    res -= right;
    return res;
}

Math::Quaternion Math::operator* (const Quaternion& left, const Quaternion& right)
{
    return Quaternion (left.w () * right.w () - left.imag.dot (right.imag),
                       left.imag.cross (right.imag) + left.real * right.imag + right.real * left.imag);
}

Math::Quaternion Math::operator* (const Quaternion& quaternion, const Real& scalar)
{
    Quaternion res = quaternion;
    res *= scalar;
    return res;
}

Math::Quaternion Math::operator/ (const Quaternion& quaternion, const Real& scalar)
{
    Quaternion res = quaternion;
    res /= scalar;
    return res;
}

void Math::Quaternion::create_quaternion_from_matrix_with_largest_u (const Matrix4& matrix)
{
    imag.x = matrix (2,1) - matrix (1,2);
    imag.y = matrix (0,2) - matrix (2,0);
    imag.z = matrix (1,0) - matrix (0,1);

    imag /= (4 * real);
}

void Math::Quaternion::create_quaternion_from_matrix_with_smallest_u (const Matrix4& matrix)
{
    imag.x = std::sqrt (matrix (0,0) - matrix (1,1) - matrix (2,2) + matrix (3,3));
    imag.y = std::sqrt (-matrix (0,0) + matrix (1,1) - matrix (2,2) + matrix (3,3));
    imag.z = std::sqrt (-matrix (0,0) - matrix (1,1) + matrix (2,2) + matrix (3,3));

    imag *= 0.5;
}
