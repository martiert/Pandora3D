#ifdef MATRIX2_INCLUDE_FILE

template<typename T>
Matrix2<T>::Matrix2 ()
    : data {1, 0, 0, 1}
{ }

template<typename T>
Matrix2<T>::Matrix2 (const T& m00, const T& m01, const T& m10, const T&  m11)
    : data {m00, m01, m10, m11}
{ }

template<typename T>
Matrix2<T>::Matrix2 (T array[4])
    : data {array[0], array[1], array[2], array[3]}
{ }

template<typename T>
Matrix2<T>::Matrix2 (const Matrix2<T>& matrix)
    : data {matrix.data[0], matrix.data[1], matrix.data[2], matrix.data[3]}
{ }

template<typename T>
T& Matrix2<T>::operator () (const size_t& i, const size_t& j)
{
    if (i > 1 || j > 1)
        throw std::out_of_range ("matrix index out of range");
    return data[i*2 + j];
}

template<typename T>
T Matrix2<T>::operator () (const size_t& i, const size_t& j) const
{
    if (i > 1 || j > 1)
        throw std::out_of_range ("matrix index out of range");
    return data[i*2 + j];
}

template<typename T>
Matrix2<T>::operator T* ()
{
    return data;
}

template<typename T>
Matrix2<T>::operator const T* () const
{
    return data;
}

template<typename T>
Matrix2<T>& Matrix2<T>::operator+= (const Matrix2<T>& matrix)
{
    data[0] += matrix (0,0);
    data[1] += matrix (0,1);
    data[2] += matrix (1,0);
    data[3] += matrix (1,1);

    return *this;
}

template<typename T>
Matrix2<T> operator+ (const Matrix2<T>& lmatrix, const Matrix2<T>& rmatrix)
{
    return Matrix2<T> (lmatrix (0,0) + rmatrix (0,0), lmatrix (0,1) + rmatrix (0,1),
                       lmatrix (1,0) + rmatrix (1,0), lmatrix (1,1) + rmatrix (1,1));
}

template<typename T>
Matrix2<T> operator* (const Matrix2<T>& matrix, const T& scalar)
{
    return Matrix2<T> (matrix (0,0) * scalar, matrix (0,1) * scalar,
                       matrix (1,0) * scalar, matrix (1,1) * scalar);
}

template<typename T>
Matrix2<T> operator* (const T& scalar, const Matrix2<T>& matrix)
{
    return matrix * scalar;
}

#else // MATRIX2_INCLUDE_FILE
#error "Never include this file anywhere but matrix2.h"
#endif // MATRIX2_INCLUDE_FILE
