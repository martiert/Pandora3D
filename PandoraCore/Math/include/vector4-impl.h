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
  if (i == 0)
    return _x;
  if (i == 1)
    return _y;
  if (i == 2)
    return _z;

  return _w;
}

#else // VECTOR4_INCLUDE_FILE
#error "Never include this file anywhere but vector4.h"
#endif // VECTOR4_INCLUDE_FILE
