#ifdef VECTOR3_INCLUDE_FILE

template<typename T>
using Vector3def = Vector3<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>;

template<typename T>
Vector3def<T>::Vector3 ()
    : x (0), y (0), z (0)
{}

template<typename T>
Vector3def<T>::Vector3 (const T& x, const T& y, const T& z)
    : x (x), y (y), z (z)
{}

template<typename T>
Vector3def<T>::Vector3 (const T data[3])
    : x (data[0]), y (data[1]), z (data[2])
{}

template<typename T>
T& Vector3def<T>::operator[] (const size_t i)
{
    if (i > 2)
        throw index_operator_out_of_range_exception (i);

    return (&x)[i];
}

template<typename T>
T Vector3def<T>::operator[] (const size_t i) const
{
    if (i > 2)
        throw index_operator_out_of_range_exception (i);

    return (&x)[i];
}

template<typename T>
Vector3def<T>::operator T* ()
{
    return &x;
}

template<typename T>
Vector3def<T>::operator const T* () const
{
    return &x;
}

template<typename T>
Vector3def<T>& Vector3def<T>::operator+= (const Vector3def<T>& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;

    return *this;
}

template<typename T>
Vector3def<T>& Vector3def<T>::operator-= (const Vector3def<T>& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;

    return *this;
}

template<typename T>
Vector3def<T>& Vector3def<T>::operator*= (const Vector3def<T>& vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;

    return *this;
}

template<typename T>
Vector3def<T>& Vector3def<T>::operator*= (const T& scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

template<typename T>
Vector3def<T>& Vector3def<T>::operator/= (const T& scalar)
{
    if (scalar == 0)
        throw division_by_zero_exception ();

    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}

template<typename T>
T Vector3def<T>::dot (const Vector3def<T>& vec) const
{
    return (x * vec.x + y * vec.y + z * vec.z);
}

template<typename T>
T Vector3def<T>::length () const
{
    return std::sqrt (lengthSquared ());
}

template<typename T>
T Vector3def<T>::lengthSquared () const
{
    return dot (*this);
}

template<typename T>
void Vector3def<T>::normalize ()
{
    float len = length ();

    if (len == 0)
        throw normalizing_zero_vector_exception ();

    *this /= len;
}

template<typename T>
Vector3def<T> Vector3def<T>::cross (const Vector3def<T>& other) const
{
    Vector3<T> res;
    res.x = y * other.z - z * other.y;
    res.y = z * other.x - x * other.z;
    res.z = x * other.y - y * other.x;

    return res;
}

template<typename T>
void Vector3def<T>::generateOrthonormalBasis (Vector3<T>& vec1, Vector3<T>& vec2, Vector3<T>& vec3)
{
    if (vec1 == vec2 || vec1 == vec3 || vec2 == vec3)
        throw can_not_make_orthonormal_basis_with_equal_vectors_exception ();

    const Vector3<T> zero;
    if (vec1 == zero || vec2 == zero || vec3 == zero)
        throw can_not_make_orthonormal_basis_with_zero_vector_exception ();

    vec2 = vec1.cross (vec3);
    vec3 = vec1.cross (vec2);

    vec1.normalize ();
    vec2.normalize ();
    vec3.normalize ();
}

template<typename T>
Vector3<T> operator- (const Vector3<T>& vec)
{
    return Vector3<T> (-vec.x, -vec.y, -vec.z);
}

template<typename T>
Vector3<T> operator+ (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    auto tmp = vec1;
    tmp += vec2;
    return tmp;
}

template<typename T>
Vector3<T> operator- (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    auto tmp = vec1;
    tmp -= vec2;
    return tmp;
}

template<typename T>
Vector3<T> operator* (const Vector3<T>& vec, const T& scalar)
{
    auto tmp = vec;
    tmp *= scalar;
    return tmp;
}

template<typename T>
Vector3<T> operator* (const T& scalar, const Vector3<T>& vec)
{
    return vec * scalar;
}

template<typename T>
Vector3<T> operator* (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    auto tmp = vec1;
    tmp *= vec2;
    return tmp;
}

template<typename T>
Vector3<T> operator/ (const Vector3<T>& vec, const T& scalar)
{
    auto tmp = vec;
    tmp /= scalar;
    return tmp;
}

template<typename T>
bool operator== (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    return (vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z);
}

template<typename T>
bool operator!= (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    return !(vec1 == vec2);
}

#else // VECTOR3_INCLUDE_FILE

#error "Never include this file anywhere but vector3.h"

#endif // VECTOR3_INCLUDE_FILE
