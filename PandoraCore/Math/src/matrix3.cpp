#include "matrix3.h"

const Math::Matrix3 Math::Matrix3::IDENTITY (1, 0, 0,
                                             0, 1, 0,
                                             0, 0, 1);

const Math::Matrix3 Math::Matrix3::ZERO (0, 0, 0,
                                         0, 0, 0,
                                         0, 0, 0);

Math::Matrix3::Matrix3 ()
    : data {1, 0, 0, 0, 1, 0, 0, 0, 1}
{ }

Math::Matrix3::Matrix3 (const Real& m00, const Real& m01, const Real& m02,
                     const Real& m10, const Real& m11, const Real& m12,
                     const Real& m20, const Real& m21, const Real& m22)
    : data {m00, m01, m02, m10, m11, m12, m20, m21, m22}
{ }


Math::Matrix3::Matrix3 (const Real array[9])
    : data {array[0], array[1], array[2],
            array[3], array[4], array[5],
            array[6], array[7], array[8]}
{ }

Real& Math::Matrix3::operator () (const size_t& i, const size_t& j)
{
    if (i > 2 || j > 2)
        throw index_operator_out_of_range_exception (i, j);

    return data[i*3 + j];
}

Real Math::Matrix3::operator () (const size_t& i, const size_t& j) const
{
    if (i > 2 || j > 2)
        throw index_operator_out_of_range_exception (i, j);

    return data[i*3 + j];
}

Real& Math::Matrix3::operator [] (const size_t& i)
{
    if (i > 8)
        throw index_operator_out_of_range_exception (i);

    return data[i];
}

Real Math::Matrix3::operator [] (const size_t& i) const
{
    if (i > 8)
        throw index_operator_out_of_range_exception (i);

    return data[i];
}

Math::Matrix3::operator Real* ()
{
    return &data[0];
}

Math::Matrix3::operator const Real* () const
{
    return &data[0];
}

Math::Matrix3& Math::Matrix3::operator*= (const Real& scalar)
{
    for (auto& i : data)
        i *= scalar;

    return *this;
}

Math::Matrix3& Math::Matrix3::operator/= (const Real& scalar)
{
    if (scalar == 0)
        throw division_by_zero_exception ();

    for (auto& i : data)
        i /= scalar;

    return *this;
}

Math::Matrix3& Math::Matrix3::operator+= (const Math::Matrix3& other)
{
    for (auto i = 0; i < 9; ++i)
        data[i] += other.data[i];

    return *this;
}

Math::Matrix3& Math::Matrix3::operator-= (const Math::Matrix3& other)
{
    for (auto i = 0; i < 9; ++i)
        data[i] -= other.data[i];

    return *this;
}

Real Math::Matrix3::determinant () const
{
    return  data[0] * (data[4]*data[8] - data[5]*data[7]) -
            data[1] * (data[3]*data[8] - data[5]*data[6]) +
            data[2] * (data[3]*data[7] - data[4]*data[6]);
}

Real Math::Matrix3::trace () const
{
    return data[0] + data[4] + data[8];
}

Math::Matrix3 Math::Matrix3::transpose () const
{
  return Matrix3 (data[0], data[3], data[6],
                     data[1], data[4], data[7],
                     data[2], data[5], data[8]);
}

Math::Matrix3 Math::Matrix3::inverse () const
{
    auto det = determinant ();

    if (det == 0)
        throw inverse_of_singular_matrix_exception ();

    auto trans = transpose ();

    Matrix3 result;
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

Math::Matrix3 Math::operator* (const Matrix3& matrix, const Real& scalar)
{
    auto result (matrix);
    result *= scalar;
    return result;
}

Math::Matrix3 Math::operator* (const Real& scalar, const Matrix3& matrix)
{
    return matrix * scalar;
}

Math::Matrix3 Math::operator/ (const Matrix3& matrix, const Real& scalar)
{
    auto result = matrix;
    result /= scalar;
    return result;
}

Math::Matrix3 Math::operator+ (const Matrix3& left, const Matrix3& right)
{
    Matrix3 result (left);
    result += right;
    return result;
}

Math::Matrix3 Math::operator- (const Matrix3& left, const Matrix3& right)
{
    Matrix3 result (left);
    result -= right;
    return result;
}

Math::Matrix3 Math::operator* (const Matrix3& left, const Matrix3& right)
{
    Matrix3 result;

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

bool Math::operator== (const Matrix3& left, const Matrix3& right)
{
    const Real* first1 = (const Real*) left;
    const Real* last = first1 + 9;
    const Real* first2 = (const Real*) right;

    return std::equal (first1, last, first2);
}

bool Math::operator!= (const Matrix3& left, const Matrix3& right)
{
    return !operator== (left, right);
}
