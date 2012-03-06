#ifdef VECTOR3_INCLUDE_FILE

template<typename T>
Vector3<T>::Vector3 ()
    : _x (0), _y (0), _z (0)
{}

template<typename T>
Vector3<T>::Vector3 (const T& x, const T& y, const T& z)
    : _x (x), _y (y), _z (z)
{}

template<typename T>
Vector3<T>::Vector3 (const Vector3<T>& vec)
    : _x (vec._x), _y (vec._y), _z (vec._z)
{}

template<typename T>
Vector3<T>::Vector3 (const T data[3])
    : _x (data[0]), _y (data[1]), _z (data[2])
{}

template<typename T>
T& Vector3<T>::x ()
{
    return _x;
}

template<typename T>
T& Vector3<T>::y ()
{
    return _y;
}

template<typename T>
T& Vector3<T>::z ()
{
    return _z;
}

template<typename T>
T Vector3<T>::x () const
{
    return _x;
}

template<typename T>
T Vector3<T>::y () const
{
    return _y;
}

template<typename T>
T Vector3<T>::z () const
{
    return _z;
}

template<typename T>
T& Vector3<T>::operator[] (const size_t i)
{
    if (i > 2)
        throw std::out_of_range ("Index out of range for 3D vectors");

    if (i == 0)
        return _x;
    if (i == 1)
        return _y;

    return _z;
}

template<typename T>
T Vector3<T>::operator[] (const size_t i) const
{
    if (i > 2)
        throw std::out_of_range ("Index out of range for 3D vectors");

    if (i == 0)
        return _x;
    if (i == 1)
        return _y;

    return _z;
}

template<typename T>
Vector3<T>& Vector3<T>::operator+= (const Vector3<T>& vec)
{
    _x += vec.x ();
    _y += vec.y ();
    _z += vec.z ();

    return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator-= (const Vector3<T>& vec)
{
    _x -= vec.x ();
    _y -= vec.y ();
    _z -= vec.z ();

    return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator*= (const Vector3<T>& vec)
{
    _x *= vec.x ();
    _y *= vec.y ();
    _z *= vec.z ();

    return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator*= (const T& scalar)
{
    _x *= scalar;
    _y *= scalar;
    _z *= scalar;

    return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator/= (const T& scalar)
{
    if (scalar == 0)
        throw std::invalid_argument ("Can not divide vector by zero");

    _x /= scalar;
    _y /= scalar;
    _z /= scalar;

    return *this;
}

template<typename T>
T Vector3<T>::dot (const Vector3<T>& vec) const
{
    return (_x * vec.x () + _y * vec.y () + _z * vec.z ());
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
    res.x () = _y * other.z () - _z * other.y ();
    res.y () = _z * other.x () - _x * other.z ();
    res.z () = _x * other.y () - _y * other.x ();

    return res;
}

template<typename T>
Vector3<T> operator- (const Vector3<T>& vec)
{
    return Vector3<T> (-vec.x (), -vec.y (), -vec.z ());
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
    return (vec1.x () == vec2.x () && vec1.y () == vec2.y () && vec1.z () == vec2.z ());
}

template<typename T>
bool operator!= (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    return !(vec1 == vec2);
}

template<typename T>
bool operator< (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    if (vec1.x () < vec2.x ())
        return true;
    if (vec1.x () > vec2.x ())
        return false;

    if (vec1.y () < vec2.y ())
        return true;
    if (vec1.y () > vec2.y ())
        return false;

    if (vec1.z () < vec2.z ())
        return true;

    return false;
}

template<typename T>
bool operator> (const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    if (vec1.x () > vec2.x ())
        return true;
    if (vec1.x () < vec2.x ())
        return false;

    if (vec1.y () > vec2.y ())
        return true;
    if (vec1.y () < vec2.y ())
        return false;

    if (vec1.z () > vec2.z ())
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
