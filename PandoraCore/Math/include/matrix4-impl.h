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
    if (i > 3 || j > 3)
        throw std::out_of_range ("Element outside of matrix boundary");

    return data[i*4 + j];
}

template<typename T>
T Matrix4<T>::operator () (const size_t& i, const size_t& j) const
{
    if (i > 3 || j > 3)
        throw std::out_of_range ("Element outside of matrix boundary");

    return data[i*4 + j];
}

template<typename T>
T& Matrix4<T>::operator[] (const size_t& i)
{
    if (i > 15)
        throw std::out_of_range ("Element outside of matrix boundary");

    return data[i];
}

template<typename T>
T Matrix4<T>::operator[] (const size_t& i) const
{
    if (i > 15)
        throw std::out_of_range ("Element outside of matrix boundary");

    return data[i];
}

template<typename T>
Matrix4<T>::operator T* ()
{
    return data;
}

template<typename T>
Matrix4<T>::operator const T* () const
{
    return data;
}

template<typename T>
Matrix4<T>& Matrix4<T>::operator*= (const T& scalar)
{
    for (auto i = 0; i < 16; ++i)
        data[i] *= scalar;

    return *this;
}

template<typename T>
Matrix4<T>& Matrix4<T>::operator/= (const T& scalar)
{
    if (scalar == 0)
        throw std::invalid_argument ("Can not divide matrix by zero");

    for (auto i = 0; i < 16; ++i)
        data[i] /= scalar;

    return *this;
}

template<typename T>
Matrix4<T>& Matrix4<T>::operator+= (const Matrix4 other)
{
    for (auto i = 0; i < 16; ++i)
        data[i] += other[i];
    return *this;
}

template<typename T>
Matrix4<T>& Matrix4<T>::operator-= (const Matrix4 other)
{
    for (auto i = 0; i < 16; ++i)
        data[i] -= other[i];
    return *this;
}

template<typename T>
Matrix4<T> Matrix4<T>::transpose () const
{
    Matrix4<T> res;
    for (auto i = 0; i < 4; ++i)
        for (auto j = 0; j < 4; ++j)
            res (j,i) = data[i*4 + j];

    return res;
}

template<typename T>
T Matrix4<T>::trace () const
{
    return data[0] + data[5] + data[10] + data[15];
}

template<typename T>
T Matrix4<T>::determinant () const
{
    const T sub1 = data[5] * (data[10] * data[15] - data[11] * data[14]) -
                        operator() (1,2) * (operator() (2,1) * operator() (3,3) - operator() (2,3) * operator() (3,1)) +
                        operator() (1,3) * (operator() (2,1) * operator() (3,2) - operator() (3,1) * operator() (2,2));

    const T sub2 = operator() (1,0) * (operator() (2,2) * operator() (3,3) - operator() (2,3) * operator() (3,2)) -
                        operator() (1,2) * (operator() (2,0) * operator() (3,3) - operator() (2,3) * operator() (3,0)) +
                        operator() (1,3) * (operator() (2,0) * operator() (3,2) - operator() (2,2) * operator() (3,0));

    const T sub3 = operator() (1,0) * (operator() (2,1) * operator() (3,3) - operator() (2,3) * operator() (3,1)) -
                        operator() (1,1) * (operator() (2,0) * operator() (3,3) - operator() (2,3) * operator() (3,0)) +
                        operator() (1,3) * (operator() (2,0) * operator() (3,1) - operator() (2,1) * operator() (3,0));

    const T sub4 = operator() (1,0) * (operator() (2,1) * operator() (3,2) - operator() (3,2) * operator() (3,1)) -
                        operator() (1,1) * (operator() (2,0) * operator() (3,2) - operator() (2,2) * operator() (3,0)) +
                        operator() (1,2) * (operator() (2,0) * operator() (3,1) - operator() (2,1) * operator() (3,0));

    return operator() (0,0) * sub1 - operator() (0,1) * sub2 + operator() (0,2) * sub3 - operator() (0,3) * sub4;
}

template<typename T>
Matrix4<T> operator* (const Matrix4<T>& matrix, const T& scalar)
{
    Matrix4<T> result = matrix;
    for (auto i = 0; i < 16; ++i)
        result[i] *= scalar;
    return result;
}

template<typename T>
Matrix4<T> operator* (const T& scalar, const Matrix4<T>& matrix)
{
    return matrix * scalar;
}

template<typename T>
Vector4<T> operator* (const Matrix4<T>& matrix, const Vector4<T>& vector)
{
    Vector4<T> res;
    for (auto i = 0; i < 4; ++i)
        for (auto j = 0; j < 4; ++j)
            res[i] += matrix (i,j) * vector[j];

    return res;
}

template<typename T>
Vector4<T> operator* (const Vector4<T>& vector, const Matrix4<T>& matrix)
{
    Vector4<T> res;
    for (auto i = 0; i < 4; ++i)
        for (auto j = 0; j < 4; ++j)
            res[i] += vector[j] * matrix (j,i);

    return res;
}

template<typename T>
Matrix4<T> operator/ (const Matrix4<T>& matrix, const T& scalar)
{
    if (scalar == 0)
        throw std::invalid_argument ("Can not divide matrix by zero");

    Matrix4<T> result = matrix;
    for (auto i = 0; i < 16; ++i)
        result[i] /= scalar;
    return result;
}

template<typename T>
Matrix4<T> operator+ (const Matrix4<T>& left, const Matrix4<T>& right)
{
    Matrix4<T> result;
    for (auto i = 0; i < 16; ++i)
        result[i] = left[i] + right[i];
    return result;
}

template<typename T>
Matrix4<T> operator- (const Matrix4<T>& left, const Matrix4<T>& right)
{
    Matrix4<T> result;
    for (auto i = 0; i < 16; ++i)
        result[i] = left[i] - right[i];
    return result;
}

template<typename T>
Matrix4<T> operator* (const Matrix4<T>& left, const Matrix4<T>& right)
{
    Matrix4<T> result;
    for (auto i = 0; i < 4; ++i) {
        for (auto j = 0; j < 4; ++j) {
            T element = 0;
            for (auto k = 0; k < 4; ++k)
                element += left (i,k) * right (k,j);
            result (i,j) = element;
        }
    }
    return result;
}

#else // MATRIX4_INCLUDE_FILE
#error "Never include this file anywhere but matrix4.h"
#endif // MATRIX4_INCLUDE_FILE
