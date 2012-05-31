#include "vector3.h"

#include <sstream>
#include <cmath>

Math::Vector3::Vector3 ()
    : x (0), y (0), z (0)
{}

Math::Vector3::Vector3 (const Real& x, const Real& y, const Real& z)
    : x (x), y (y), z (z)
{}

Math::Vector3::Vector3 (const Real data[3])
    : x (data[0]), y (data[1]), z (data[2])
{}

Real& Math::Vector3::operator[] (const size_t& i)
{
    if (i > 2)
        throw index_operator_out_of_range_exception (i);

    return (&x)[i];
}

Real Math::Vector3::operator[] (const size_t& i) const
{
    if (i > 2)
        throw index_operator_out_of_range_exception (i);

    return (&x)[i];
}

Math::Vector3::operator Real* ()
{
    return &x;
}

Math::Vector3::operator const Real* () const
{
    return &x;
}

Math::Vector3& Math::Vector3::operator+= (const Math::Vector3& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;

    return *this;
}

Math::Vector3& Math::Vector3::operator-= (const Math::Vector3& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;

    return *this;
}

Math::Vector3& Math::Vector3::operator*= (const Math::Vector3& vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;

    return *this;
}

Math::Vector3& Math::Vector3::operator*= (const Real& scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

Math::Vector3& Math::Vector3::operator/= (const Real& scalar)
{
    if (scalar == 0)
        throw division_by_zero_exception ();

    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}

Real Math::Vector3::dot (const Math::Vector3& vec) const
{
    return (x * vec.x + y * vec.y + z * vec.z);
}

Real Math::Vector3::length () const
{
    return std::sqrt (lengthSquared ());
}

Real Math::Vector3::lengthSquared () const
{
    return dot (*this);
}

void Math::Vector3::normalize ()
{
    float len = length ();

    if (len == 0)
        throw normalizing_zero_vector_exception ();

    *this /= len;
}

Math::Vector3 Math::Vector3::cross (const Math::Vector3& other) const
{
    Vector3 res;
    res.x = y * other.z - z * other.y;
    res.y = z * other.x - x * other.z;
    res.z = x * other.y - y * other.x;

    return res;
}

void Math::Vector3::generateOrthonormalBasis (Vector3& vec1, Vector3& vec2, Vector3& vec3)
{
    if (vec1 == vec2 || vec1 == vec3 || vec2 == vec3)
        throw can_not_make_orthonormal_basis_with_equal_vectors_exception ();

    const Vector3 zero;
    if (vec1 == zero || vec2 == zero || vec3 == zero)
        throw can_not_make_orthonormal_basis_with_zero_vector_exception ();

    vec2 = vec1.cross (vec3);
    vec3 = vec1.cross (vec2);

    vec1.normalize ();
    vec2.normalize ();
    vec3.normalize ();
}

Math::Vector3 Math::operator- (const Vector3& vec)
{
    return Vector3 (-vec.x, -vec.y, -vec.z);
}

Math::Vector3 Math::operator+ (const Vector3& vec1, const Vector3& vec2)
{
    auto tmp = vec1;
    tmp += vec2;
    return tmp;
}

Math::Vector3 Math::operator- (const Vector3& vec1, const Vector3& vec2)
{
    auto tmp = vec1;
    tmp -= vec2;
    return tmp;
}

Math::Vector3 Math::operator* (const Vector3& vec, const Real& scalar)
{
    auto tmp = vec;
    tmp *= scalar;
    return tmp;
}

Math::Vector3 Math::operator* (const Real& scalar, const Vector3& vec)
{
    return vec * scalar;
}

Math::Vector3 Math::operator* (const Vector3& vec1, const Vector3& vec2)
{
    auto tmp = vec1;
    tmp *= vec2;
    return tmp;
}

Math::Vector3 Math::operator/ (const Vector3& vec, const Real& scalar)
{
    auto tmp = vec;
    tmp /= scalar;
    return tmp;
}

bool Math::operator== (const Vector3& vec1, const Vector3& vec2)
{
    return (vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z);
}

bool Math::operator!= (const Vector3& vec1, const Vector3& vec2)
{
    return !(vec1 == vec2);
}

Math::Vector3::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t&i)
    : index (i)
{ }


const char* Math::Vector3::index_operator_out_of_range_exception::what () const throw ()
{
    std::stringstream out;
    out << "Tried to access index: " << index;
    return out.str ().c_str ();
}
