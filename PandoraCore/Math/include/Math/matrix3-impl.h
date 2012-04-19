#ifdef MATRIX3_INCLUDE_FILE

template<typename T>
Matrix3<T>::Matrix3 ()
    : data ({1, 0, 0, 0, 1, 0, 0, 0, 1})
{ }

template<typename T>
Matrix3<T>::Matrix3 (const T& m00, const T& m01, const T& m02,
                     const T& m10, const T& m11, const T& m12,
                     const T& m20, const T& m21, const T& m22)
    : data ({m00, m01, m02, m10, m11, m12, m20, m21, m22})
{ }


template<typename T>
Matrix3<T>::Matrix3 (const T array[9])
    : data ({array[0], array[1], array[2],
            array[3], array[4], array[5],
            array[6], array[7], array[8]})
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

template<typename T>
Matrix3<T>::operator T* ()
{
    return &data[0];
}

template<typename T>
Matrix3<T>::operator const T* () const
{
    return &data[0];
}

template<typename T>
Matrix3<T>& Matrix3<T>::operator*= (const T& scalar)
{
    for (auto& i : data)
        i *= scalar;

    return *this;
}

template<typename T>
Matrix3<T>& Matrix3<T>::operator/= (const T& scalar)
{
    if (scalar == 0)
        throw std::invalid_argument ("Cannot divide a matrix by zero");

    for (auto& i : data)
        i /= scalar;

    return *this;
}

template<typename T>
Matrix3<T>& Matrix3<T>::operator+= (const Matrix3<T>& other)
{
    for (auto i : {0,1,2,3,4,5,6,7,8})
        data[i] += other.data[i];

    return *this;
}

template<typename T>
Matrix3<T>& Matrix3<T>::operator-= (const Matrix3<T>& other)
{
    for (auto i : {0,1,2,3,4,5,6,7,8})
        data[i] -= other.data[i];

    return *this;
}

template<typename T>
T Matrix3<T>::determinant () const
{
    return  data[0] * (data[4]*data[8] - data[5]*data[7]) -
            data[1] * (data[3]*data[8] - data[5]*data[6]) +
            data[2] * (data[3]*data[7] - data[4]*data[6]);
}

template<typename T>
Matrix3<T> operator* (const Matrix3<T>& matrix, const T& scalar)
{
    auto result (matrix);
    result *= scalar;
    return result;
}

template<typename T>
Matrix3<T> operator* (const T& scalar, const Matrix3<T>& matrix)
{
    return matrix * scalar;
}

template<typename T>
Matrix3<T> operator/ (const Matrix3<T>& matrix, const T& scalar)
{
    auto result = matrix;
    result /= scalar;
    return result;
}

template<typename T>
Matrix3<T> operator+ (const Matrix3<T>& left, const Matrix3<T>& right)
{
    Matrix3<T> result (left);
    result += right;
    return result;
}

template<typename T>
Matrix3<T> operator- (const Matrix3<T>& left, const Matrix3<T>& right)
{
    Matrix3<T> result (left);
    result -= right;
    return result;
}

template<typename T>
Matrix3<T> operator* (const Matrix3<T>& left, const Matrix3<T>& right)
{
    Matrix3<T> result;

    result (0,0) = left (0,0) * right (0,0) + left (0,1) * right (1,0) + left (0,2) * right (2,0);
    result (0,1) = left (0,0) * right (0,1) + left (0,1) * right (1,1) + left (0,2) * right (2,1);
    result (0,2) = left (0,0) * right (0,2) + left (0,1) * right (1,2) + left (0,2) * right (2,2);

    result (1,0) = left (1,0) * right (0,0) + left (1,1) * right (1,0) + left (1,2) * right (2,0);
    result (1,1) = left (1,0) * right (0,1) + left (1,1) * right (1,1) + left (1,2) * right (2,1);
    result (1,2) = left (1,0) * right (0,2) + left (1,1) * right (1,2) + left (1,2) * right (2,2);

    result (2,0) = left (2,0) * right (0,0) + left (2,1) * right (1,0) + left (2,2) * right (2,0);
    result (2,1) = left (2,0) * right (0,1) + left (2,1) * right (1,1) + left (2,2) * right (2,1);
    result (2,2) = left (2,0) * right (0,2) + left (2,1) * right (1,2) + left (2,2) * right (2,2);

    return result;
}

#else // MATRIX3_INCLUDE_FILE
#error "Never include this file anywhere but matrix3.h"
#endif // MATRIX3_INCLUDE_FILE
