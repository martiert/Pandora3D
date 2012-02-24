template<typename T>
Vector2<T>::Vector2 ()
    : _x (0), _y (0)
{ }

template<typename T>
Vector2<T>::Vector2 (const T x, const T y)
    : _x (x), _y (y)
{ }

template<typename T>
Vector2<T>::Vector2 (const Vector2& vector)
    : _x (vector._x), _y (vector._y)
{ }

template<typename T>
Vector2<T>::Vector2 (const T array[2])
    : _x (array[0]), _y (array[1])
{ }

template<typename T>
T Vector2<T>::x () const
{
    return _x;
}

template<typename T>
T Vector2<T>::y () const
{
    return _y;
}

template<typename T>
T& Vector2<T>::x ()
{
    return _x;
}

template<typename T>
T& Vector2<T>::y ()
{
    return _y;
}

template<typename T>
T& Vector2<T>::operator[] (const size_t i)
{
    if (i > 1)
        throw std::out_of_range ("Index out of range for 2D vectors");

    if (i == 0)
        return _x;
    return _y;
}

template<typename T>
T Vector2<T>::operator[] (const size_t i) const
{
    if (i > 1)
        throw std::out_of_range ("Index out of range for 2D vectors");

    if (i == 0)
        return _x;
    return _y;
}

template<typename T>
Vector2<T>& Vector2<T>::operator+= (const Vector2<T>& other)
{
    _x += other.x ();
    _y += other.y ();

    return (*this);
}

template<typename T>
Vector2<T>& Vector2<T>::operator-= (const Vector2<T>& other)
{
    _x -= other.x ();
    _y -= other.y ();

    return (*this);
}

template<typename T>
Vector2<T>& Vector2<T>::operator*= (const Vector2<T>& other)
{
    _x *= other.x ();
    _y *= other.y ();

    return (*this);
}

template<typename T>
Vector2<T>& Vector2<T>::operator*= (const T& scalar)
{
    _x *= scalar;
    _y *= scalar;

    return (*this);
}

template<typename T>
Vector2<T>& Vector2<T>::operator/= (const T& scalar)
{
    if (!scalar)
        throw std::invalid_argument ("Can not divide vector by zero");

    _x /= scalar;
    _y /= scalar;

    return (*this);
}

template<typename T>
T Vector2<T>::lengthSquared () const
{
    return (_x * _x + _y * _y);
}

template<typename T>
T Vector2<T>::length () const
{
    return std::sqrt (_x * _x + _y * _y);
}

template<typename T>
T Vector2<T>::dot (const Vector2<T>& other) const
{
    return (x () * other.x () + y () * other.y ());
}

template<typename T>
Vector2<T> Vector2<T>::perp () const
{
    return Vector2<T> (_y, -_x);
}

template<typename T>
void Vector2<T>::normalize ()
{
    T len = length ();

    if (len == 0)
        throw std::domain_error ("Can not normalize a zero vector");

    _x /= len;
    _y /= len;
}

template<typename T>
Vector2<T> operator - (const Vector2<T>& vec)
{
    return Vector2<T> (-vec.x (), -vec.y ());
}

template<typename T>
Vector2<T> operator+ (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return Vector2<T> (vec1.x () + vec2.x (), vec1.y () + vec2.y ());
}

template<typename T>
Vector2<T> operator- (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return Vector2<T> (vec1.x () - vec2.x (), vec1.y () - vec2.y ());
}

template<typename T>
Vector2<T> operator* (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return Vector2<T> (vec1.x () * vec2.x (), vec1.y () * vec2.y ());
}

template<typename T>
Vector2<T> operator* (const Vector2<T>& vec, const T real)
{
    return Vector2<T> (vec.x () * real, vec.y () * real);
}

template<typename T>
Vector2<T> operator/ (const Vector2<T>& vec, const T real)
{
    if (!real)
        throw std::invalid_argument ("Can not divide vector by zero");
    return Vector2<T> (vec.x () / real, vec.y () / real);
}

template<typename T>
Vector2<T> operator* (const T real, const Vector2<T>& vec)
{
    return Vector2<T> (vec.x () * real, vec.y () * real);
}

template<typename T>
bool operator== (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return (vec1.x () == vec2.x () && vec1.y () == vec2.y ());
}

template<typename T>
bool operator!= (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return !(vec1.x () == vec2.x ());
}

template<typename T>
bool operator< (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return (vec1.x () < vec2.x () || (vec1.x () == vec2.x () && vec1.y () < vec2.y ()));
}

template<typename T>
bool operator> (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return (vec1.x () > vec2.x () || (vec1.x () == vec2.x () && vec1.y () > vec2.y ()));
}

template<typename T>
bool operator<= (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return ((vec1 == vec2) || (vec1 < vec2));
}

template<typename T>
bool operator>= (const Vector2<T>& vec1, const Vector2<T>& vec2)
{
    return ((vec1 == vec2) || (vec1 > vec2));
}

template<typename T>
void generateOrthonormalBasis (Vector2<T>& vec1, Vector2<T>& vec2)
{
    if (vec1 == vec2)
        throw std::domain_error ("Can not make orthonormal basis of equal vectors");
    vec1.normalize ();
    vec2 = vec2 - (vec1.dot (vec2)) * vec1;
    vec2.normalize ();
}
