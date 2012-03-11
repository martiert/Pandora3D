#ifdef VECTOR3_INCLUDE_FILE

template<typename T>
Vector3<T>::Vector3 ()
    : x (0), y (0), z (0)
{}

template<typename T>
Vector3<T>::Vector3 (const T& x, const T& y, const T& z)
    : x (x), y (y), z (z)
{}

template<typename T>
Vector3<T>::Vector3 (const T data[3])
    : x (data[0]), y (data[1]), z (data[2])
{}

template<typename T>
T& Vector3<T>::operator[] (const size_t i)
{
    if (i > 2)
        throw std::out_of_range ("Index out of range for 3D vectors");

    if (i == 0)
        return x;
    if (i == 1)
        return y;

    return z;
}

template<typename T>
T Vector3<T>::operator[] (const size_t i) const
{
    if (i > 2)
        throw std::out_of_range ("Index out of range for 3D vectors");

    if (i == 0)
        return x;
    if (i == 1)
        return y;

    return z;
}

template<typename T>
Vector3<T>::operator T* ()
{
    return &x;
}

template<typename T>
Vector3<T>::operator const T* () const
{
    return &x;
}

template<typename T>
Vector3<T>& Vector3<T>::operator+= (const Vector3<T>& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;

    return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator-= (const Vector3<T>& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;

    return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator*= (const Vector3<T>& vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;

    return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator*= (const T& scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator/= (const T& scalar)
{
    if (scalar == 0)
        throw std::invalid_argument ("Can not divide vector by zero");

    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}

template<typename T>
T Vector3<T>::dot (const Vector3<T>& vec) const
{
    return (x * vec.x + y * vec.y + z * vec.z);
}

template<typename T>
T Vector3<T>::length () const
{
    return std::sqrt (lengthSquared ());
}

template<typename T>
T Vector3<T>::lengthSquared () const
{
    return dot (*this);
}

template<typename T>
void Vector3<T>::normalize ()
{
    float len = length ();

    if (len == 0)
        throw std::domain_error ("Can not normalize a zero vector");

    *this /= len;
}

template<typename T>
Vector3<T> Vector3<T>::cross (const Vector3<T>& other) const
{
    Vector3<T> res;
    res.x = y * other.z - z * other.y;
    res.y = z * other.x - x * other.z;
    res.z = x * other.y - y * other.x;

    return res;
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

template<typename T>
bool operator< (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    if (vec1.x < vec2.x)
        return true;
    if (vec1.x > vec2.x)
        return false;

    if (vec1.y < vec2.y)
        return true;
    if (vec1.y > vec2.y)
        return false;

    if (vec1.z < vec2.z)
        return true;

    return false;
}

template<typename T>
bool operator> (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    if (vec1.x > vec2.x)
        return true;
    if (vec1.x < vec2.x)
        return false;

    if (vec1.y > vec2.y)
        return true;
    if (vec1.y < vec2.y)
        return false;

    if (vec1.z > vec2.z)
        return true;

    return false;
}

template<typename T>
bool operator<= (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    return (vec1 == vec2 || vec1 < vec2);
}

template<typename T>
bool operator>= (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    return (vec1 == vec2 || vec1 > vec2);
}

template<typename T>
void generateOrthonormalBasis (Vector3<T>& vec1, Vector3<T>& vec2, Vector3<T>& vec3)
{
    if (vec1 == vec2 || vec1 == vec3 || vec2 == vec3)
        throw std::domain_error ("Can not make orthonormal basis of equal vectors");

    vec1.normalize ();
    vec2 = vec2 - vec1.dot (vec2) * vec1;
    vec2.normalize ();
    vec3 = vec3 - vec1.dot (vec3) * vec1 - vec2.dot (vec3) * vec2;
    vec3.normalize ();
}

#else // VECTOR3_INCLUDE_FILE

#error "Never include this file anywhere but vector3.h"

#endif // VECTOR3_INCLUDE_FILE
