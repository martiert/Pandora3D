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
    : data ({a00, a01, a02, a03,
             a10, a11, a12, a13,
             a20, a21, a22, a23,
             a30, a31, a32, a33})
{ }

template<typename T>
Matrix4<T>::Matrix4 (const T array[16])
    : data ({array[0], array[1], array[2], array[3],
             array[4], array[5], array[6], array[7],
             array[8], array[9], array[10], array[11],
             array[12], array[13], array[14], array[15] })
{ }

template<typename T>
Matrix4<T>::Matrix4 (const Matrix3<T>& matrix)
    : data ({matrix[0], matrix[1], matrix[2], 0,
             matrix[3], matrix[4], matrix[5], 0,
             matrix[6], matrix[7], matrix[8], 0,
             0,         0,         0,         1})
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

template<typename T>
T& Matrix4<T>::operator[] (const size_t& i)
{
    return data[i];
}

template<typename T>
T Matrix4<T>::operator[] (const size_t& i) const
{
    return data[i];
}

#else // MATRIX4_INCLUDE_FILE
#error "Never include this file anywhere but matrix4.h"
#endif // MATRIX4_INCLUDE_FILE
