#include "matrix2.h"

#include <algorithm>
#include <string>

const Math::Matrix2 Math::Matrix2::IDENTITY (1, 0, 0, 1);

const Math::Matrix2 Math::Matrix2::ZERO (0, 0, 0, 0);

Math::Matrix2::Matrix2 ()
    : data {1,0,0,1}
{
}

Math::Matrix2::Matrix2 (const Real& m00, const Real& m01, const Real& m10, const Real&  m11)
    : data {m00, m01, m10, m11}
{
}

Math::Matrix2::Matrix2 (const Real array[4])
    : data {array[0], array[1], array[2], array[3]}
{
}

Real& Math::Matrix2::operator[] (const size_t& i)
{
    if (i > 3)
        throw index_operator_out_of_range_exception (i);

    return data[i];
}

Real Math::Matrix2::operator[] (const size_t& i) const
{
    if (i > 3)
        throw index_operator_out_of_range_exception (i);

    return data[i];
}

Real& Math::Matrix2::operator () (const size_t& i, const size_t& j)
{
    if (i > 1 || j > 1)
        throw index_operator_out_of_range_exception (i, j);

    return data[i*2 + j];
}

Real Math::Matrix2::operator () (const size_t& i, const size_t& j) const
{
    if (i > 1 || j > 1)
        throw index_operator_out_of_range_exception (i, j);

    return data[i*2 + j];
}

Math::Matrix2::operator Real* ()
{
    return data;
}

Math::Matrix2::operator const Real* () const
{
    return data;
}

Math::Matrix2& Math::Matrix2::operator+= (const Math::Matrix2& matrix)
{
    data[0] += matrix (0,0);
    data[1] += matrix (0,1);
    data[2] += matrix (1,0);
    data[3] += matrix (1,1);

    return *this;
}

Math::Matrix2& Math::Matrix2::operator-= (const Math::Matrix2& matrix)
{
    data[0] -= matrix (0,0);
    data[1] -= matrix (0,1);
    data[2] -= matrix (1,0);
    data[3] -= matrix (1,1);

    return *this;
}

Math::Matrix2& Math::Matrix2::operator*= (const Real& scalar)
{
    data[0] *= scalar;
    data[1] *= scalar;
    data[2] *= scalar;
    data[3] *= scalar;

    return *this;
}

Math::Matrix2& Math::Matrix2::operator/= (const Real& scalar)
{
    if (scalar == 0)
        throw division_by_zero_exception ();

    data[0] /= scalar;
    data[1] /= scalar;
    data[2] /= scalar;
    data[3] /= scalar;

    return *this;
}

Real Math::Matrix2::determinant () const
{
    return data[0]*data[3] - data[1]*data[2];
}

Math::Matrix2 Math::Matrix2::transpose () const
{
    return Matrix2 (data[0], data[2], data[1], data[3]);
}


Math::Matrix2 Math::Matrix2::inverse () const
{
    Real det = determinant ();

    if (det == 0)
        throw inverse_of_singular_matrix_exception ();

    Real scale = 1.0/det;

    Matrix2 result (data[3], -data[1],
                       -data[2], data[0]);

    return result * scale;
}

Math::Matrix2 Math::operator+ (const Matrix2& lmatrix, const Matrix2& rmatrix)
{
    auto result = lmatrix;
    result += rmatrix;
    return result;
}

Math::Matrix2 Math::operator- (const Matrix2& lmatrix, const Matrix2& rmatrix)
{
    auto result = lmatrix;
    result -= rmatrix;
    return result;
}

Math::Matrix2 Math::operator* (const Matrix2& lmatrix, const Matrix2& rmatrix)
{
    Matrix2 res;
    res (0,0) = lmatrix (0,0) * rmatrix (0,0) + lmatrix (0,1) * rmatrix (1,0);
    res (0,1) = lmatrix (0,0) * rmatrix (0,1) + lmatrix (0,1) * rmatrix (1,1);
    res (1,0) = lmatrix (1,0) * rmatrix (0,0) + lmatrix (1,1) * rmatrix (1,0);
    res (1,1) = lmatrix (1,0) * rmatrix (0,1) + lmatrix (1,1) * rmatrix (1,1);

    return res;
}

Math::Matrix2 Math::operator* (const Matrix2& matrix, const Real& scalar)
{
    auto result = matrix;
    result *= scalar;
    return result;
}

Math::Matrix2 Math::operator* (const Real& scalar, const Matrix2& matrix)
{
    return matrix * scalar;
}

Math::Vector2 Math::operator* (const Matrix2& matrix, const Vector2& vector)
{
    return Vector2 (matrix[0] * vector.x + matrix[1] * vector.y,
                       matrix[2] * vector.x + matrix[3] * vector.y);
}

Math::Vector2 Math::operator* (const Vector2& vector, const Matrix2& matrix)
{
    return Vector2 (matrix[0] * vector.x + matrix[2] * vector.y,
                       matrix[1] * vector.x + matrix[3] * vector.y);
}

Math::Matrix2 Math::operator/ (const Matrix2& matrix, const Real& scalar)
{
    auto result = matrix;
    result /= scalar;
    return result;
}

bool Math::operator== (const Matrix2& lmatrix, const Matrix2& rmatrix)
{
    auto first1 = static_cast<const Real*> (lmatrix);
    auto last = first1 + 4;
    auto first2 = static_cast<const Real*> (rmatrix);

    return std::equal (first1, last, first2);
}

bool Math::operator!= (const Matrix2& lmatrix, const Matrix2& rmatrix)
{
    return !(lmatrix == rmatrix);
}

Math::Matrix2::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& row, const size_t& col)
    : index (0), row (row), col (col)
{ }

Math::Matrix2::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& index)
    : index (index), row (0), col (0)
{ }


const char* Math::Matrix2::index_operator_out_of_range_exception::what () const throw ()
{
    if (index == 0)
        return create_message_from_row_col ();
    return create_message_from_index ();
}

const char* Math::Matrix2::index_operator_out_of_range_exception::create_message_from_index () const
{
    std::string error ("Tried to access index: ");
    error += index;
    return error.c_str ();
}

const char* Math::Matrix2::index_operator_out_of_range_exception::create_message_from_row_col () const
{
    std::string error ("Tried to access: (");
    error += row;
    error += ", ";
    error += col;
    error += ")";
    return error.c_str ();
}
