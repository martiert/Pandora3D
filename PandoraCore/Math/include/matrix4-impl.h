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

// Code from the MESA implementation of gluInvertMatrix.
template<typename T>
Matrix4<T> Matrix4<T>::inverse () const
{
    T det = determinant ();

    if (det == 0)
        throw std::domain_error ("Singular matrix has no inverse");

    Matrix4<T> res;

    res[0] = data[5]  * data[10] * data[15] -
             data[5]  * data[11] * data[14] -
             data[9]  * data[6]  * data[15] +
             data[9]  * data[7]  * data[14] +
             data[13] * data[6]  * data[11] -
             data[13] * data[7]  * data[10];

    res[4] = -data[4]  * data[10] * data[15] +
              data[4]  * data[11] * data[14] +
              data[8]  * data[6]  * data[15] -
              data[8]  * data[7]  * data[14] -
              data[12] * data[6]  * data[11] +
              data[12] * data[7]  * data[10];

    res[8] = data[4]  * data[9] * data[15] -
             data[4]  * data[11] * data[13] -
             data[8]  * data[5] * data[15] +
             data[8]  * data[7] * data[13] +
             data[12] * data[5] * data[11] -
             data[12] * data[7] * data[9];

    res[12] = -data[4]  * data[9] * data[14] +
               data[4]  * data[10] * data[13] +
               data[8]  * data[5] * data[14] -
               data[8]  * data[6] * data[13] -
               data[12] * data[5] * data[10] +
               data[12] * data[6] * data[9];

    res[1] = -data[1]  * data[10] * data[15] +
              data[1]  * data[11] * data[14] +
              data[9]  * data[2] * data[15] -
              data[9]  * data[3] * data[14] -
              data[13] * data[2] * data[11] +
              data[13] * data[3] * data[10];

    res[5] = data[0]  * data[10] * data[15] -
             data[0]  * data[11] * data[14] -
             data[8]  * data[2] * data[15] +
             data[8]  * data[3] * data[14] +
             data[12] * data[2] * data[11] -
             data[12] * data[3] * data[10];

    res[9] = -data[0]  * data[9] * data[15] +
              data[0]  * data[11] * data[13] +
              data[8]  * data[1] * data[15] -
              data[8]  * data[3] * data[13] -
              data[12] * data[1] * data[11] +
              data[12] * data[3] * data[9];

    res[13] = data[0]  * data[9] * data[14] -
              data[0]  * data[10] * data[13] -
              data[8]  * data[1] * data[14] +
              data[8]  * data[2] * data[13] +
              data[12] * data[1] * data[10] -
              data[12] * data[2] * data[9];

    res[2] = data[1]  * data[6] * data[15] -
             data[1]  * data[7] * data[14] -
             data[5]  * data[2] * data[15] +
             data[5]  * data[3] * data[14] +
             data[13] * data[2] * data[7] -
             data[13] * data[3] * data[6];

    res[6] = -data[0]  * data[6] * data[15] +
              data[0]  * data[7] * data[14] +
              data[4]  * data[2] * data[15] -
              data[4]  * data[3] * data[14] -
              data[12] * data[2] * data[7] +
              data[12] * data[3] * data[6];

    res[10] = data[0]  * data[5] * data[15] -
              data[0]  * data[7] * data[13] -
              data[4]  * data[1] * data[15] +
              data[4]  * data[3] * data[13] +
              data[12] * data[1] * data[7] -
              data[12] * data[3] * data[5];

    res[14] = -data[0]  * data[5] * data[14] +
               data[0]  * data[6] * data[13] +
               data[4]  * data[1] * data[14] -
               data[4]  * data[2] * data[13] -
               data[12] * data[1] * data[6] +
               data[12] * data[2] * data[5];

    res[3] = -data[1] * data[6] * data[11] +
              data[1] * data[7] * data[10] +
              data[5] * data[2] * data[11] -
              data[5] * data[3] * data[10] -
              data[9] * data[2] * data[7] +
              data[9] * data[3] * data[6];

    res[7] = data[0] * data[6] * data[11] -
             data[0] * data[7] * data[10] -
             data[4] * data[2] * data[11] +
             data[4] * data[3] * data[10] +
             data[8] * data[2] * data[7] -
             data[8] * data[3] * data[6];

    res[11] = -data[0] * data[5] * data[11] +
               data[0] * data[7] * data[9] +
               data[4] * data[1] * data[11] -
               data[4] * data[3] * data[9] -
               data[8] * data[1] * data[7] +
               data[8] * data[3] * data[5];

    res[15] = data[0] * data[5] * data[10] -
              data[0] * data[6] * data[9] -
              data[4] * data[1] * data[10] +
              data[4] * data[2] * data[9] +
              data[8] * data[1] * data[6] -
              data[8] * data[2] * data[5];

    det = 1.0 / det;
    return res * det;
}

template<typename T>
T Matrix4<T>::trace () const
{
    return data[0] + data[5] + data[10] + data[15];
}

template<typename T>
T Matrix4<T>::determinant () const
{
    const T sub1 = calculate_sub_determinant (0,0);
    const T sub2 = calculate_sub_determinant (0,1);
    const T sub3 = calculate_sub_determinant (0,2);
    const T sub4 = calculate_sub_determinant (0,3);

    return data[0] * sub1 - data[1] * sub2 + data[2] * sub3 - data[3] * sub4;
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

template<typename T>
T Matrix4<T>::calculate_sub_determinant (const size_t& row, const size_t& column) const
{
    Matrix3<T> matrix;
    size_t index = 0;
    for (auto i = 0; i < 4; ++i) {
        for (auto j = 0; j < 4; ++j) {
            if (i != row && j != column) {
                matrix[index] = data[i * 4 + j];
                ++index;
            }
        }
    }

    return matrix.determinant ();
}

#else // MATRIX4_INCLUDE_FILE
#error "Never include this file anywhere but matrix4.h"
#endif // MATRIX4_INCLUDE_FILE
