#include "matrix4.h"
#include "matrix3.h"

#include <sstream>
#include <algorithm>

const Math::Matrix4 Math::Matrix4::IDENTITY (1, 0, 0, 0,
                                             0, 1, 0, 0,
                                             0, 0, 1, 0,
                                             0, 0, 0, 1);

const Math::Matrix4 Math::Matrix4::ZERO (0, 0, 0, 0,
                                         0, 0, 0, 0,
                                         0, 0, 0, 0,
                                         0, 0, 0, 0);

Math::Matrix4::Matrix4 ()
    : data {1, 0, 0, 0,
             0, 1, 0, 0,
             0, 0, 1, 0,
             0, 0, 0, 1}
{ }

Math::Matrix4::Matrix4 (const Real& a00, const Real& a01, const Real& a02, const Real& a03,
                        const Real& a10, const Real& a11, const Real& a12, const Real& a13,
                        const Real& a20, const Real& a21, const Real& a22, const Real& a23,
                        const Real& a30, const Real& a31, const Real& a32, const Real& a33)
    : data {a00, a01, a02, a03,
             a10, a11, a12, a13,
             a20, a21, a22, a23,
             a30, a31, a32, a33}
{ }

Math::Matrix4::Matrix4 (const Real array[16])
    : data {array[0], array[1], array[2], array[3],
            array[4], array[5], array[6], array[7],
            array[8], array[9], array[10], array[11],
            array[12], array[13], array[14], array[15] }
{ }

Math::Matrix4::Matrix4 (const Matrix3& matrix)
    : data {matrix[0], matrix[1], matrix[2], 0,
             matrix[3], matrix[4], matrix[5], 0,
             matrix[6], matrix[7], matrix[8], 0,
             0,         0,         0,         1}
{ }

Real& Math::Matrix4::operator () (const size_t& i, const size_t& j)
{
    if (i > 3 || j > 3)
        throw index_operator_out_of_range_exception (i, j);

    return data[i*4 + j];
}

Real Math::Matrix4::operator () (const size_t& i, const size_t& j) const
{
    if (i > 3 || j > 3)
        throw index_operator_out_of_range_exception (i, j);

    return data[i*4 + j];
}

Real& Math::Matrix4::operator[] (const size_t& i)
{
    if (i > 15)
        throw index_operator_out_of_range_exception (i);

    return data[i];
}

Real Math::Matrix4::operator[] (const size_t& i) const
{
    if (i > 15)
        throw index_operator_out_of_range_exception (i);

    return data[i];
}

Math::Matrix4::operator Real* ()
{
    return data;
}

Math::Matrix4::operator const Real* () const
{
    return data;
}

Math::Matrix4& Math::Matrix4::operator*= (const Real& scalar)
{
    for (auto i = 0; i < 16; ++i)
        data[i] *= scalar;

    return *this;
}

Math::Matrix4& Math::Matrix4::operator/= (const Real& scalar)
{
    if (scalar == 0)
        throw division_by_zero_exception ();

    for (auto i = 0; i < 16; ++i)
        data[i] /= scalar;

    return *this;
}

Math::Matrix4& Math::Matrix4::operator+= (const Matrix4 other)
{
    for (auto i = 0; i < 16; ++i)
        data[i] += other[i];
    return *this;
}

Math::Matrix4& Math::Matrix4::operator-= (const Matrix4 other)
{
    for (auto i = 0; i < 16; ++i)
        data[i] -= other[i];
    return *this;
}

Math::Matrix4 Math::Matrix4::transpose () const
{
    Matrix4 res;
    for (auto i = 0; i < 4; ++i)
        for (auto j = 0; j < 4; ++j)
            res (j,i) = data[i*4 + j];

    return res;
}

// Code from the MESA implementation of gluInvertMatrix.
Math::Matrix4 Math::Matrix4::inverse () const
{
    Real det = determinant ();

    if (det == 0)
        throw inverse_of_singular_matrix_exception ();

    Matrix4 res;

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

Real Math::Matrix4::trace () const
{
    return data[0] + data[5] + data[10] + data[15];
}

Real Math::Matrix4::determinant () const
{
    const Real sub1 = calculate_sub_determinant (0,0);
    const Real sub2 = calculate_sub_determinant (0,1);
    const Real sub3 = calculate_sub_determinant (0,2);
    const Real sub4 = calculate_sub_determinant (0,3);

    return data[0] * sub1 - data[1] * sub2 + data[2] * sub3 - data[3] * sub4;
}

Math::Matrix4 Math::operator* (const Matrix4& matrix, const Real& scalar)
{
    Matrix4 result = matrix;
    for (auto i = 0; i < 16; ++i)
        result[i] *= scalar;
    return result;
}

Math::Matrix4 Math::operator* (const Real& scalar, const Matrix4& matrix)
{
    return matrix * scalar;
}

Math::Vector4 Math::operator* (const Matrix4& matrix, const Vector4& vector)
{
    Vector4 res;
    for (auto i = 0; i < 4; ++i)
        for (auto j = 0; j < 4; ++j)
            res[i] += matrix (i,j) * vector[j];

    return res;
}

Math::Vector4 Math::operator* (const Vector4& vector, const Matrix4& matrix)
{
    Vector4 res;
    for (auto i = 0; i < 4; ++i)
        for (auto j = 0; j < 4; ++j)
            res[i] += vector[j] * matrix (j,i);

    return res;
}

Math::Matrix4 Math::operator/ (const Matrix4& matrix, const Real& scalar)
{
    auto result = matrix;
    result /= scalar;
    return result;
}

Math::Matrix4 Math::operator+ (const Matrix4& left, const Matrix4& right)
{
    Matrix4 result;
    for (auto i = 0; i < 16; ++i)
        result[i] = left[i] + right[i];
    return result;
}

Math::Matrix4 Math::operator- (const Matrix4& left, const Matrix4& right)
{
    Matrix4 result;
    for (auto i = 0; i < 16; ++i)
        result[i] = left[i] - right[i];
    return result;
}

Math::Matrix4 Math::operator* (const Matrix4& left, const Matrix4& right)
{
    Matrix4 result;
    for (auto i = 0; i < 4; ++i) {
        for (auto j = 0; j < 4; ++j) {
            Real element = 0;
            for (auto k = 0; k < 4; ++k)
                element += left (i,k) * right (k,j);
            result (i,j) = element;
        }
    }
    return result;
}


bool Math::operator== (const Matrix4& left, const Matrix4& right)
{
    auto left_array = static_cast<const double*> (left);
    auto right_array = static_cast<const double*> (right);

    return std::equal (left_array, &left_array[15], right_array);
}

bool Math::operator!= (const Matrix4& left, const Matrix4& right)
{
    return !(left == right);
}

Real Math::Matrix4::calculate_sub_determinant (const size_t& row, const size_t& column) const
{
    Matrix3 matrix;
    size_t index = 0;
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            if (i != row && j != column) {
                matrix[index] = data[i * 4 + j];
                ++index;
            }
        }
    }

    return matrix.determinant ();
}

Math::Matrix4::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& i)
    : index (i), row (0), col (0)
{ }

Math::Matrix4::index_operator_out_of_range_exception::index_operator_out_of_range_exception (const size_t& row, const size_t& col)
    : index (0), row (row), col (col)
{ }

const char* Math::Matrix4::index_operator_out_of_range_exception::what () const throw ()
{
    if (index == 0)
        return create_message_from_row_col ();
    return create_message_from_index ();
}

const char* Math::Matrix4::index_operator_out_of_range_exception::create_message_from_index () const
{
    std::stringstream out;
    out << "Tried to access index: " << index;
    return out.str ().c_str ();
}

const char* Math::Matrix4::index_operator_out_of_range_exception::create_message_from_row_col () const
{
    std::stringstream out;
    out << "Tried to access: (" << row << ", " << col << ")";
    return out.str ().c_str ();
}
