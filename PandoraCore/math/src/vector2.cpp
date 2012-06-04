#include "vector2.h"

#include <sstream>
#include <cmath>

Math::Vector2::Vector2 ()
    : x (0), y (0)
{ }

Math::Vector2::Vector2 (const Real x, const Real y)
    : x (x), y (y)
{ }

Math::Vector2::Vector2 (const Real array[2])
    : x (array[0]), y (array[1])
{ }

Real& Math::Vector2::operator[] (const size_t& i)
{
    if (i > 1)
        throw index_operator_out_of_range_exception (i);

    return (&x)[i];
}

Real Math::Vector2::operator[] (const size_t& i) const
{
    if (i > 1)
        throw index_operator_out_of_range_exception (i);

    return (&x)[i];
}

Math::Vector2::operator Real* ()
{
    return &x;
}

Math::Vector2::operator const Real* () const
{
    return &x;
}

Math::Vector2& Math::Vector2::operator+= (const Math::Vector2& other)
{
    x += other.x;
    y += other.y;

    return (*this);
}

Math::Vector2& Math::Vector2::operator-= (const Math::Vector2& other)
{
    x -= other.x;
    y -= other.y;

    return (*this);
}

Math::Vector2& Math::Vector2::operator*= (const Math::Vector2& other)
{
    x *= other.x;
    y *= other.y;

    return (*this);
}

Math::Vector2& Math::Vector2::operator*= (const Real& scalar)
{
    x *= scalar;
    y *= scalar;

    return (*this);
}

Math::Vector2& Math::Vector2::operator/= (const Real& scalar)
{
    if (!scalar)
        throw division_by_zero_exception ();

    x /= scalar;
    y /= scalar;

    return (*this);
}

Real Math::Vector2::lengthSquared () const
{
    return dot (*this);
}

Real Math::Vector2::length () const
{
    return std::sqrt (lengthSquared ());
}

Real Math::Vector2::dot (const Math::Vector2& other) const
{
    return x * other.x + y * other.y;
}

Math::Vector2 Math::Vector2::perp () const
{
    return Vector2 (y, -x);
}

void Math::Vector2::normalize ()
{
    Real len = length ();

    if (len == 0)
        throw can_not_normalize_zero_vector_exception ();

    *this /= len;
}

void Math::Vector2::generateOrthonormalBasis (Vector2& vec1, Vector2& vec2)
{
    if ((vec1.x == 0 && vec1.y == 0) || (vec2.x == 0 && vec2.y == 0))
        throw can_not_make_orthonormal_basis_with_zero_vector_exception ();

    if (vec1 == vec2)
        throw can_not_make_orthonormal_basis_from_equal_vectors_exception () ;

    vec1.normalize ();
    vec2 = vec2 - (vec1.dot (vec2)) * vec1;
    vec2.normalize ();
}


Math::Vector2 Math::operator- (const Vector2& vec)
{
    return Vector2 (-vec.x, -vec.y);
}

Math::Vector2 Math::operator+ (const Vector2& vec1, const Vector2& vec2)
{
    return Vector2 (vec1.x + vec2.x, vec1.y + vec2.y);
}

Math::Vector2 Math::operator- (const Vector2& vec1, const Vector2& vec2)
{
    return Vector2 (vec1.x - vec2.x, vec1.y - vec2.y);
}

Math::Vector2 Math::operator* (const Vector2& vec1, const Vector2& vec2)
{
    return Vector2 (vec1.x * vec2.x, vec1.y * vec2.y);
}

Math::Vector2 Math::operator* (const Vector2& vec, const Real real)
{
    return Vector2 (vec.x * real, vec.y * real);
}

Math::Vector2 Math::operator/ (const Vector2& vec, const Real real)
{
    auto res = vec;
    res /= real;
    return res;
}

Math::Vector2 Math::operator* (const Real real, const Vector2& vec)
{
    return Vector2 (vec.x * real, vec.y * real);
}

bool Math::operator== (const Vector2& vec1, const Vector2& vec2)
{
    return (vec1.x == vec2.x && vec1.y == vec2.y);
}

bool Math::operator!= (const Vector2& vec1, const Vector2& vec2)
{
    return !(vec1 == vec2);
}

Math::Vector2::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& i)
    : index (i)
{}

const char* Math::Vector2::index_operator_out_of_range_exception::what () const throw ()
{
    std::stringstream out;
    out << "Tried to access index: " << index;
    return out.str ().c_str ();
}
