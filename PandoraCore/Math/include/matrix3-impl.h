#ifdef MATRIX3_INCLUDE_FILE

template<typename T>
using Matrix3def = Matrix3<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>;

template<typename T>
Matrix3def<T>::Matrix3 ()
    : data {1, 0, 0, 0, 1, 0, 0, 0, 1}
{ }

template<typename T>
Matrix3def<T>::Matrix3 (const T& m00, const T& m01, const T& m02,
                     const T& m10, const T& m11, const T& m12,
                     const T& m20, const T& m21, const T& m22)
    : data {m00, m01, m02, m10, m11, m12, m20, m21, m22}
{ }


template<typename T>
Matrix3def<T>::Matrix3 (const T array[9])
    : data {array[0], array[1], array[2],
            array[3], array[4], array[5],
            array[6], array[7], array[8]}
{ }

template<typename T>
T& Matrix3def<T>::operator () (const size_t& i, const size_t& j)
{
    if (i > 2 || j > 2)
        throw std::out_of_range ("Index operator out of range");

    return data[i*3 + j];
}

template<typename T>
T Matrix3def<T>::operator () (const size_t& i, const size_t& j) const
{
    if (i > 2 || j > 2)
        throw std::out_of_range ("Index operator out of range");

    return data[i*3 + j];
}

template<typename T>
T& Matrix3def<T>::operator [] (const size_t& i)
{
    if (i > 8)
        throw std::out_of_range ("Index operator out of range");

    return data[i];
}

template<typename T>
T Matrix3def<T>::operator [] (const size_t& i) const
{
    if (i > 8)
        throw std::out_of_range ("Index operator out of range");

    return data[i];
}

template<typename T>
Matrix3def<T>::operator T* ()
{
    return &data[0];
}

template<typename T>
Matrix3def<T>::operator const T* () const
{
    return &data[0];
}

template<typename T>
Matrix3def<T>& Matrix3def<T>::operator*= (const T& scalar)
{
    for (auto& i : data)
        i *= scalar;

    return *this;
}

template<typename T>
Matrix3def<T>& Matrix3def<T>::operator/= (const T& scalar)
{
    if (scalar == 0)
        throw std::invalid_argument ("Cannot divide a matrix by zero");

    for (auto& i : data)
        i /= scalar;

    return *this;
}

template<typename T>
Matrix3def<T>& Matrix3def<T>::operator+= (const Matrix3def<T>& other)
{
    for (auto i = 0; i < 9; ++i)
        data[i] += other.data[i];

    return *this;
}

template<typename T>
Matrix3def<T>& Matrix3def<T>::operator-= (const Matrix3def<T>& other)
{
    for (auto i = 0; i < 9; ++i)
        data[i] -= other.data[i];

    return *this;
}

template<typename T>
T Matrix3def<T>::determinant () const
{
    return  data[0] * (data[4]*data[8] - data[5]*data[7]) -
            data[1] * (data[3]*data[8] - data[5]*data[6]) +
            data[2] * (data[3]*data[7] - data[4]*data[6]);
}

template<typename T>
T Matrix3def<T>::trace () const
{
    return data[0] + data[4] + data[8];
}

template<typename T>
Matrix3def<T> Matrix3def<T>::transpose () const
{
  return Matrix3<T> (data[0], data[3], data[6],
                     data[1], data[4], data[7],
                     data[2], data[5], data[8]);
}

template<typename T>
Matrix3def<T> Matrix3def<T>::inverse () const
{
    auto det = determinant ();

    if (det == 0)
        throw std::runtime_error ("Can not invert singular matrix");

    auto trans = transpose ();

    Matrix3<T> result;
    result[0] = trans[4] * trans[8] - trans[5] * trans[7];
    result[1] = - (trans[3] * trans[8] - trans[5] * trans[6]);
    result[2] = trans[3] * trans[7] - trans[4] * trans[6];

    result[3] = - (trans[1] * trans[8] - trans[2] * trans[7]);
    result[4] = trans[0] * trans[8] - trans[2] * trans[6];
    result[5] = - (trans[0] * trans[7] - trans[1] * trans[6]);

    result[6] = trans[1] * trans[5] - trans[2] * trans[4];
    result[7] = - (trans[0] * trans[5] - trans[2] * trans[3]);
    result[8] = trans[0] * trans[4] - trans[1] * trans[3];

    return result / det;
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

template<typename T>
bool operator== (const Matrix3<T>& left, const Matrix3<T>& right)
{
    return std::memcmp ((const T*) left, (const T*) right, 9 * sizeof (T)) == 0;
}

template<typename T>
bool operator!= (const Matrix3<T>& left, const Matrix3<T>& right)
{
    return !operator== (left, right);
}


#else // MATRIX3_INCLUDE_FILE
#error "Never include this file anywhere but matrix3.h"
#endif // MATRIX3_INCLUDE_FILE
