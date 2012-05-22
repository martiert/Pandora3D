#ifdef MATRIX2_INCLUDE_FILE

template<typename T>
using Matrix2def = Matrix2<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>;

template<typename T>
Matrix2def<T>::Matrix2 ()
    : data {1,0,0,1}
{
}

template<typename T>
Matrix2def<T>::Matrix2 (const T& m00, const T& m01, const T& m10, const T&  m11)
    : data {m00, m01, m10, m11}
{
}

template<typename T>
Matrix2def<T>::Matrix2 (const T array[4])
    : data {array[0], array[1], array[2], array[3]}
{
}

template<typename T>
T& Matrix2def<T>::operator () (const size_t& i, const size_t& j)
{
    if (i > 1 || j > 1)
        throw std::out_of_range ("matrix index out of range");

    return data[i*2 + j];
}

template<typename T>
T Matrix2def<T>::operator () (const size_t& i, const size_t& j) const
{
    if (i > 1 || j > 1)
        throw std::out_of_range ("matrix index out of range");

    return data[i*2 + j];
}

template<typename T>
Matrix2def<T>::operator T* ()
{
    return data;
}

template<typename T>
Matrix2def<T>::operator const T* () const
{
    return data;
}

template<typename T>
Matrix2def<T>& Matrix2def<T>::operator+= (const Matrix2def<T>& matrix)
{
    data[0] += matrix (0,0);
    data[1] += matrix (0,1);
    data[2] += matrix (1,0);
    data[3] += matrix (1,1);

    return *this;
}

template<typename T>
Matrix2def<T>& Matrix2def<T>::operator-= (const Matrix2def<T>& matrix)
{
    data[0] -= matrix (0,0);
    data[1] -= matrix (0,1);
    data[2] -= matrix (1,0);
    data[3] -= matrix (1,1);

    return *this;
}

template<typename T>
Matrix2def<T>& Matrix2def<T>::operator*= (const T& scalar)
{
    data[0] *= scalar;
    data[1] *= scalar;
    data[2] *= scalar;
    data[3] *= scalar;

    return *this;
}

template<typename T>
Matrix2def<T>& Matrix2def<T>::operator/= (const T& scalar)
{
    if (scalar == 0)
        throw std::invalid_argument ("Cannot divide a matrix by zero");

    data[0] /= scalar;
    data[1] /= scalar;
    data[2] /= scalar;
    data[3] /= scalar;

    return *this;
}

template<typename T>
T Matrix2def<T>::determinant () const
{
    return data[0]*data[3] - data[1]*data[2];
}

template<typename T>
Matrix2def<T> Matrix2def<T>::transpose () const
{
    return Matrix2<T> (data[0], data[2], data[1], data[3]);
}


template<typename T>
Matrix2def<T> Matrix2def<T>::inverse () const
{
    T det = determinant ();

    if (det == 0)
        throw std::runtime_error ("Inverse of singular matrix don't exist");

    T scale = 1.0/det;

    Matrix2<T> result (data[3], -data[1],
                       -data[2], data[0]);

    return result * scale;
}

template<typename T>
Matrix2<T> operator+ (const Matrix2<T>& lmatrix, const Matrix2<T>& rmatrix)
{
    auto result = lmatrix;
    result += rmatrix;
    return result;
}

template<typename T>
Matrix2<T> operator- (const Matrix2<T>& lmatrix, const Matrix2<T>& rmatrix)
{
    auto result = lmatrix;
    result -= rmatrix;
    return result;
}

template<typename T>
Matrix2<T> operator* (const Matrix2<T>& lmatrix, const Matrix2<T>& rmatrix)
{
    Matrix2<T> res;
    res (0,0) = lmatrix (0,0) * rmatrix (0,0) + lmatrix (0,1) * rmatrix (1,0);
    res (0,1) = lmatrix (0,0) * rmatrix (0,1) + lmatrix (0,1) * rmatrix (1,1);
    res (1,0) = lmatrix (1,0) * rmatrix (0,0) + lmatrix (1,1) * rmatrix (1,0);
    res (1,1) = lmatrix (1,0) * rmatrix (0,1) + lmatrix (1,1) * rmatrix (1,1);

    return res;
}

template<typename T>
Matrix2<T> operator* (const Matrix2<T>& matrix, const T& scalar)
{
    auto result = matrix;
    result *= scalar;
    return result;
}

template<typename T>
Matrix2<T> operator* (const T& scalar, const Matrix2<T>& matrix)
{
    return matrix * scalar;
}

template<typename T>
Vector2<T> operator* (const Matrix2<T>& matrix, const Vector2<T>& vector)
{
    return Vector2<T> (matrix[0] * vector.x + matrix[1] * vector.y,
                       matrix[2] * vector.x + matrix[3] * vector.y);
}

template<typename T>
Vector2<T> operator* (const Vector2<T>& vector, const Matrix2<T>& matrix)
{
    return Vector2<T> (matrix[0] * vector.x + matrix[2] * vector.y,
                       matrix[1] * vector.x + matrix[3] * vector.y);
}

template<typename T>
Matrix2<T> operator/ (const Matrix2<T>& matrix, const T& scalar)
{
    auto result = matrix;
    result /= scalar;
    return result;
}

template<typename T>
bool operator== (const Matrix2<T>& lmatrix, const Matrix2<T>& rmatrix)
{
    auto first1 = static_cast<const T*> (lmatrix);
    auto last = first1 + 4;
    auto first2 = static_cast<const T*> (rmatrix);

    return std::equal (first1, last, first2);
}

template<typename T>
bool operator!= (const Matrix2<T>& lmatrix, const Matrix2<T>& rmatrix)
{
    return !(lmatrix == rmatrix);
}

#else // MATRIX2_INCLUDE_FILE
#error "Never include this file anywhere but matrix2.h"
#endif // MATRIX2_INCLUDE_FILE
