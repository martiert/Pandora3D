#ifdef MATRIX4_INCLUDE_FILE

template<typename T>
Matrix4<T>::Matrix4 ()
  : data ({1, 0, 0, 0,
           0, 1, 0, 0,
           0, 0, 1, 0,
           0, 0, 0, 1})
{ }

template<typename T>
Matrix4<T>::Matrix4 (const T& a00, const T& a01, const T& a02, const T& a03,
                     const T& a10, const T& a11, const T& a12, const T& a13,
                     const T& a20, const T& a21, const T& a22, const T& a23,
                     const T& a30, const T& a31, const T& a32, const T& a33)
{ }

template<typename T>
T& Matrix4<T>::operator () (const size_t& i, const size_t& j)
{
    return data[i*4 + j];
}

template<typename T>
T Matrix4<T>::operator () (const size_t& i, const size_t& j) const
{
    return data[i*4 + j];
}

#else // MATRIX4_INCLUDE_FILE
#error "Never include this file anywhere but matrix4.h"
#endif // MATRIX4_INCLUDE_FILE
