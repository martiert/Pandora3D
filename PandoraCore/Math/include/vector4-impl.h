#ifdef VECTOR4_INCLUDE_FILE

template<typename T>
using Vector4def = Vector4<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>;

template<typename T>
Vector4def<T>::Vector4 ()
    : x (0), y (0), z (0), w (0)
{ }

template<typename T>
Vector4def<T>::Vector4 (const T& x, const T& y, const T& z, const T& w)
    : x (x), y (y), z (z), w (w)
{ }

template<typename T>
Vector4def<T>::Vector4 (const T data[4])
    : x (data[0]), y (data[1]), z (data[2]), w (data[3])
{ }

template<typename T>
    Vector4def<T>::Vector4 (const Vector3<T>& vec)
: x (vec.x), y (vec.y), z (vec.z), w (1)
{ }

template<typename T>
T& Vector4def<T>::operator[] (const size_t i)
{
    if (i > 3)
        throw std::out_of_range ("Index out of range for 4D vectors");

    return (&x)[i];
}

template<typename T>
T Vector4def<T>::operator[] (const size_t i) const
{
    if (i > 3)
        throw std::out_of_range ("Index out of range for 4D vectors");

    return (&x)[i];
}

template<typename T>
Vector4def<T>::operator T* ()
{
    return &x;
}

template<typename T>
Vector4def<T>::operator const T* () const
{
    return &x;
}

template<typename T>
Vector4def<T>& Vector4def<T>::operator+= (const Vector4def<T>& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    w += vec.w;

    return *this;
}

template<typename T>
Vector4def<T>& Vector4def<T>::operator-= (const Vector4def<T>& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    w -= vec.w;

    return *this;
}

template<typename T>
Vector4def<T>& Vector4def<T>::operator*= (const Vector4def<T>& vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;
    w *= vec.w;

    return *this;
}

template<typename T>
Vector4def<T>& Vector4def<T>::operator*= (const T& scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;

    return *this;
}

template<typename T>
Vector4def<T>& Vector4def<T>::operator/= (const T& scalar)
{
    if (scalar == 0)
        throw std::invalid_argument ("Out of bounds of a 4D vector.");

    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;

    return *this;
}

template<typename T>
T Vector4def<T>::length () const
{
    return std::sqrt (this->lengthSquared ());
}

template<typename T>
T Vector4def<T>::lengthSquared () const
{
    return dot (*this);
}

template<typename T>
T Vector4def<T>::dot (const Vector4def<T>& vec) const
{
    return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
}

template<typename T>
Vector4def<T>& Vector4def<T>::normalize ()
{
    T len = length ();

    if (len == 0)
        throw std::domain_error ("Cannot normalize a zero vector");

    return *this /= len;
}

template<typename T>
Vector4<T> operator- (const Vector4<T>& vec)
{
    return Vector4<T> (-vec.x, -vec.y, -vec.z, -vec.w);
}

template<typename T>
Vector4<T> operator+ (const Vector4<T>& vec_1, const Vector4<T>& vec_2)
{
    auto result = vec_1;
    result += vec_2;
    return result;
}

template<typename T>
Vector4<T> operator- (const Vector4<T>& vec_1, const Vector4<T>& vec_2)
{
    auto result = vec_1;
    result -= vec_2;
    return result;
}

template<typename T>
Vector4<T> operator* (const Vector4<T>& vec_1, const Vector4<T>& vec_2)
{
    auto tmp = vec_1;
    tmp *= vec_2;
    return tmp;
}

template<typename T>
Vector4<T> operator* (const Vector4<T>& vec, const T& scalar)
{
    auto tmp = vec;
    tmp *= scalar;
    return tmp;
}

template<typename T>
Vector4<T> operator* (const T& scalar, const Vector4<T>& vec)
{
    return vec * scalar;
}

template<typename T>
Vector4<T> operator/ (const Vector4<T>& vec, const T& scalar)
{
    auto tmp = vec;
    tmp /= scalar;
    return tmp;
}

template<typename T>
bool operator== (const Vector4<T>& vec1, const Vector4<T>& vec2)
{
    return (vec1.x == vec2.x &&
            vec1.y == vec2.y &&
            vec1.z == vec2.z &&
            vec1.w == vec2.w);
}

template<typename T>
bool operator!= (const Vector4<T>& vec1, const Vector4<T>& vec2)
{
    return !(vec1 == vec2);
}

#else // VECTOR4_INCLUDE_FILE
#error "Never include this file anywhere but vector4.h"
#endif // VECTOR4_INCLUDE_FILE
