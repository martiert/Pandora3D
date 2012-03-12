#ifdef MATRIX3_INCLUDE_FILE

template<typename T>
Matrix3<T>::Matrix3 ()
    : data {1, 0, 0, 0, 1, 0, 0, 0, 1}
{ }

template<typename T>
Matrix3<T>::Matrix3 (const T& m00, const T& m01, const T& m02,
                     const T& m10, const T& m11, const T& m12,
                     const T& m20, const T& m21, const T& m22)
    : data {m00, m01, m02, m10, m11, m12, m20, m21, m22}
{ }


template<typename T>
Matrix3<T>::Matrix3 (const T array[9])
    : data {array[0], array[1], array[2],
            array[3], array[4], array[5],
            array[6], array[7], array[8]}
{ }

template<typename T>
T& Matrix3<T>::operator () (const size_t& i, const size_t& j)
{
    if (i > 2 || j > 2)
        throw std::out_of_range ("Index operator out of range");

    return data[i*3 + j];
}

template<typename T>
T Matrix3<T>::operator () (const size_t& i, const size_t& j) const
{
    if (i > 2 || j > 2)
        throw std::out_of_range ("Index operator out of range");

    return data[i*3 + j];
}

#else // MATRIX3_INCLUDE_FILE
#error "Never include this file anywhere but matrix3.h"
#endif // MATRIX3_INCLUDE_FILE
