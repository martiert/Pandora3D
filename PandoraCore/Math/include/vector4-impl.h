#ifdef VECTOR4_INCLUDE_FILE

template<typename T>
Vector4<T>::Vector4 ()
    : _x (0), _y (0), _z (0), _w (0)
{ }

template<typename T>
Vector4<T>::Vector4 (const T& x, const T& y, const T& z, const T& w)
    : _x (x), _y (y), _z (z), _w (w)
{ }

template<typename T>
Vector4<T>::Vector4 (const Vector4<T>& vec)
    : _x (vec._x), _y (vec._y), _z (vec._z), _w (vec._w)
{ }

template<typename T>
Vector4<T>::Vector4 (const T data[4])
    : _x (data[0]), _y (data[1]), _z (data[2]), _w (data[3])
{ }

template<typename T>
    Vector4<T>::Vector4 (const Vector3<T>& vec)
: _x (vec.x ()), _y (vec.y ()), _z (vec.z ()), _w (1)
{ }

template<typename T>
T& Vector4<T>::x ()
{
    return _x;
}

template<typename T>
T& Vector4<T>::y ()
{
    return _y;
}

template<typename T>
T& Vector4<T>::z ()
{
    return _z;
}

template<typename T>
T& Vector4<T>::w ()
{
    return _w;
}

template<typename T>
T Vector4<T>::x () const
{
    return _x;
}

template<typename T>
T Vector4<T>::y () const
{
    return _y;
}

template<typename T>
T Vector4<T>::z () const
{
    return _z;
}

template<typename T>
T Vector4<T>::w () const
{
    return _w;
}

template<typename T>
T& Vector4<T>::operator[] (const size_t i)
{
    if (i > 3)
        throw std::out_of_range ("Index out of range for 4D vectors");

    if (i == 0)
        return _x;
    if (i == 1)
        return _y;
    if (i == 2)
        return _z;

    return _w;
}

template<typename T>
T Vector4<T>::operator[] (const size_t i) const
{
    if (i > 3)
        throw std::out_of_range ("Index out of range for 4D vectors");


    if (i == 0)
        return _x;
    if (i == 1)
        return _y;
    if (i == 2)
        return _z;

    return _w;
}

template<typename T>
Vector4<T>& Vector4<T>::operator+= (const Vector4<T>& vec)
{
    _x += vec.x ();
    _y += vec.y ();
    _z += vec.z ();
    _w += vec.w ();

    return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator-= (const Vector4<T>& vec)
{
    _x -= vec.x ();
    _y -= vec.y ();
    _z -= vec.z ();
    _w -= vec.w ();

    return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator*= (const Vector4<T>& vec)
{
    _x *= vec.x ();
    _y *= vec.y ();
    _z *= vec.z ();
    _w *= vec.w ();

    return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator*= (const T& scalar)
{
    _x *= scalar;
    _y *= scalar;
    _z *= scalar;
    _w *= scalar;

    return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator/= (const T& scalar)
{
    if (scalar == 0)
        throw std::invalid_argument ("Out of bounds of a 4D vector.");

    _x /= scalar;
    _y /= scalar;
    _z /= scalar;
    _w /= scalar;

    return *this;
}

template<typename T>
T Vector4<T>::length () const
{
    return std::sqrt (this->lengthSquared ());
}

template<typename T>
T Vector4<T>::lengthSquared () const
{
    return _x * _x + _y * _y + _z * _z + _w * _w;
}

template<typename T>
T Vector4<T>::dot (const Vector4<T>& vec) const
{
    return _x * vec.x () + _y * vec.y () + _z * vec.z () + _w * vec.w ();
}

template<typename T>
Vector4<T>& Vector4<T>::normalize ()
{
    T len = length ();

    if (len == 0)
        throw std::domain_error ("Cannot normalize a zero vector");

    _x /= len;
    _y /= len;
    _z /= len;
    _w /= len;

    return *this;
}

template<typename T>
Vector4<T> operator- (const Vector4<T>& vec)
{
    return Vector4<T> (-vec.x (), -vec.y (), -vec.z (), -vec.w ());
}

template<typename T>
Vector4<T> operator+ (const Vector4<T>& vec_1, const Vector4<T>& vec_2)
{
    return Vector4<T> (vec_1.x () + vec_2.x (),
                        vec_1.y () + vec_2.y (),
                        vec_1.z () + vec_2.z (),
                        vec_1.w () + vec_2.w ());
}

template<typename T>
Vector4<T> operator- (const Vector4<T>& vec_1, const Vector4<T>& vec_2)
{
    return Vector4<T> (vec_1.x () - vec_2.x (),
                        vec_1.y () - vec_2.y (),
                        vec_1.z () - vec_2.z (),
                        vec_1.w () - vec_2.w ());
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

#else // VECTOR4_INCLUDE_FILE
#error "Never include this file anywhere but vector4.h"
#endif // VECTOR4_INCLUDE_FILE
