#ifdef VECTOR2_INCLUDE_FILE

template<typename T>
using Vector2def = Vector2<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>;

template<typename T>
Vector2def<T>::Vector2 ()
    : x (0), y (0)
{ }

template<typename T>
Vector2def<T>::Vector2 (const T x, const T y)
    : x (x), y (y)
{ }

template<typename T>
Vector2def<T>::Vector2 (const T array[2])
    : x (array[0]), y (array[1])
{ }

template<typename T>
T& Vector2def<T>::operator[] (const size_t i)
{
    if (i > 1)
        throw index_out_of_range_exception (i);

    return (&x)[i];
}

template<typename T>
T Vector2def<T>::operator[] (const size_t i) const
{
    if (i > 1)
        throw index_out_of_range_exception (i);

    return (&x)[i];
}

template<typename T>
Vector2def<T>::operator T* ()
{
    return &x;
}

template<typename T>
Vector2def<T>::operator const T* () const
{
    return &x;
}

template<typename T>
Vector2def<T>& Vector2def<T>::operator+= (const Vector2def<T>& other)
{
    x += other.x;
    y += other.y;

    return (*this);
}

template<typename T>
Vector2def<T>& Vector2def<T>::operator-= (const Vector2def<T>& other)
{
    x -= other.x;
    y -= other.y;

    return (*this);
}

template<typename T>
Vector2def<T>& Vector2def<T>::operator*= (const Vector2def<T>& other)
{
    x *= other.x;
    y *= other.y;

    return (*this);
}

template<typename T>
Vector2def<T>& Vector2def<T>::operator*= (const T& scalar)
{
    x *= scalar;
    y *= scalar;

    return (*this);
}

template<typename T>
Vector2def<T>& Vector2def<T>::operator/= (const T& scalar)
{
    if (!scalar)
        throw division_by_zero_exception ();

    x /= scalar;
    y /= scalar;

    return (*this);
}

template<typename T>
T Vector2def<T>::lengthSquared () const
{
    return dot (*this);
}

template<typename T>
T Vector2def<T>::length () const
{
    return std::sqrt (lengthSquared ());
}

template<typename T>
T Vector2def<T>::dot (const Vector2def<T>& other) const
{
    return x * other.x + y * other.y;
}

template<typename T>
Vector2def<T> Vector2def<T>::perp () const
{
    return Vector2<T> (y, -x);
}

template<typename T>
void Vector2def<T>::normalize ()
{
    T len = length ();

    if (len == 0)
        throw can_not_normalize_zero_vector_exception ();

    *this /= len;
}

template<typename T>
void Vector2def<T>::generateOrthonormalBasis (Vector2<T>& vec1, Vector2<T>& vec2)
{
    if ((vec1.x == 0 && vec1.y == 0) || (vec2.x == 0 && vec2.y == 0))
        throw can_not_make_orthonormal_basis_with_zero_vector_exception ();

    if (vec1 == vec2)
        throw can_not_make_orthonormal_basis_from_equal_vectors_exception () ;

    vec1.normalize ();
    vec2 = vec2 - (vec1.dot (vec2)) * vec1;
    vec2.normalize ();
}


template<typename T>
Vector2<T> operator - (const Vector2<T>& vec)
{
    return Vector2<T> (-vec.x, -vec.y);
}

template<typename T>
Vector2<T> operator+ (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return Vector2<T> (vec1.x + vec2.x, vec1.y + vec2.y);
}

template<typename T>
Vector2<T> operator- (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return Vector2<T> (vec1.x - vec2.x, vec1.y - vec2.y);
}

template<typename T>
Vector2<T> operator* (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return Vector2<T> (vec1.x * vec2.x, vec1.y * vec2.y);
}

template<typename T>
Vector2<T> operator* (const Vector2<T>& vec, const T real)
{
    return Vector2<T> (vec.x * real, vec.y * real);
}

template<typename T>
Vector2<T> operator/ (const Vector2<T>& vec, const T real)
{
    auto res = vec;
    res /= real;
    return res;
}

template<typename T>
Vector2<T> operator* (const T real, const Vector2<T>& vec)
{
    return Vector2<T> (vec.x * real, vec.y * real);
}

template<typename T>
bool operator== (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return (vec1.x == vec2.x && vec1.y == vec2.y);
}

template<typename T>
bool operator!= (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return !(vec1 == vec2);
}

#else // VECTOR2_INCLUDE_FILE
#error "Never include this file anywhere but vector2.h"
#endif // VECTOR2_INCLUDE_FILE
