/*
-------------------------------------------------------------------------------
File Name : PandoraMatrix3.cpp

Purpose : Implementation of the Matrix3 class in Pandora 3D.

Creation Date : 2010-06-26

Last Modified : Fri 27 Aug 2010 11:45:01 CEST

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
-------------------------------------------------------------------------------
*/

#include "../include/PandoraMatrix3.h"

namespace Pandora
{
    namespace Math
    {

/********************************************************************************
 * Some special matrices.                                                       *
 *******************************************************************************/
template<> const Matrix3<float> Matrix3<float>::ZERO(   0.0f, 0.0f, 0.0f,
                                                        0.0f, 0.0f, 0.0f,
                                                        0.0f, 0.0f, 0.0f);
template<> const Matrix3<float> Matrix3<float>::IDENTITY(   1.0f, 0.0f, 0.0f,
                                                            0.0f, 1.0f, 0.0f,
                                                            0.0f, 0.0f, 1.0f);
template<> const Matrix3<float> Matrix3<float>::ONES(   1.0f, 1.0f, 1.0f,
                                                        1.0f, 1.0f, 1.0f,
                                                        1.0f, 1.0f, 1.0f);

template<> const Matrix3<double> Matrix3<double>::ZERO( 0.0, 0.0, 0.0,
                                                        0.0, 0.0, 0.0,
                                                        0.0, 0.0, 0.0);
template<> const Matrix3<double> Matrix3<double>::IDENTITY( 1.0, 0.0, 0.0,
                                                            0.0, 1.0, 0.0,
                                                            0.0, 0.0, 1.0);
template<> const Matrix3<double> Matrix3<double>::ONES( 1.0, 1.0, 1.0,
                                                        1.0, 1.0, 1.0,
                                                        1.0, 1.0, 1.0);


/********************************************************************************
 * Default constructor.                                                         *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(Real a0, Real a1, Real a2, Real a3, Real a4, Real a5, 
        Real a6, Real a7, Real a8)
{
    m_data[0] = a0;     m_data[1] = a1;     m_data[2] = a2;
    m_data[3] = a3;     m_data[4] = a4;     m_data[5] = a5;
    m_data[6] = a6;     m_data[7] = a7;     m_data[8] = a8;
}


/********************************************************************************
 * Make a rotation matrix.                                                      *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(Real rad, const Vector3<Real>& axis)
{
    //Normalize the axis.
    Vector3<Real> r = axis;
    r.normalize();
    Real t_cos = Math<Real>::Cos(rad);
    Real t_sin = Math<Real>::Sin(rad);

    m_data[0] = t_cos + (1 - t_cos)*r.x*r.x;
    m_data[1] = (1 - t_cos)*r.x*r.y - r.z*t_sin;
    m_data[2] = (1 - t_cos)*r.x*r.z + r.y*t_sin;

    m_data[3] = (1 - t_cos)*r.x*r.y + r.z*t_sin;
    m_data[4] = t_cos + (1 - t_cos)*r.y*r.y;
    m_data[5] = (1 - t_cos)*r.y*r.z - r.x*t_sin;

    m_data[6] = (1 - t_cos)*r.x*r.z - r.y*t_sin;
    m_data[7] = (1 - t_cos)*r.y*r.z + r.x*t_sin;
    m_data[8] = t_cos + (1 - t_cos)*r.z*r.z;
}


/********************************************************************************
 * Make a scale matrix.                                                         *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(Real x_scale, Real y_scale, Real z_scale)
{
    m_data[0] = x_scale;    m_data[1] = 0;          m_data[2] = 0;
    m_data[3] = 0;          m_data[4] = y_scale;    m_data[5] = 0;
    m_data[6] = 0;          m_data[7] = 0;          m_data[8] = z_scale;
}


/********************************************************************************
 * Copy an array to this matrix.                                                *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(Real array[9])
{
    memcpy(m_data, array, 9*sizeof(Real));
}


/********************************************************************************
 * Copy constructor.                                                            *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(const Matrix3<Real>& mat)
{
    memcpy(m_data, mat.m_data, 9*sizeof(Real));
}


/********************************************************************************
 * Copy a 2D matrix to this matrix.                                             *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(const Matrix2<Real>& mat)
{
    m_data[0] = mat[0];     m_data[1] = mat[1];     m_data[2] = (Real) 0.0;
    m_data[3] = mat[2];     m_data[4] = mat[3];     m_data[5] = (Real) 0.0;
    m_data[6] = (Real) 0.0; m_data[7] = (Real) 0.0; m_data[8] = (Real) 1.0;
}


/********************************************************************************
 * Implicit conversion.                                                         *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::operator Real *()
{
    return &(m_data[0]);
}


/********************************************************************************
 * Implicit conversion to constant array.                                       *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::operator const Real *() const
{
    return &(m_data[0]);
}


/********************************************************************************
 * Get element number i.                                                        *
 *******************************************************************************/
template<class Real>
Real& Matrix3<Real>::operator[](const ptrdiff_t i)
{
    assert(i < 9 && "Index out of bounds");
    return m_data[i];
}


/********************************************************************************
 * Get number in element i.                                                     *
 *******************************************************************************/
template<class Real>
const Real Matrix3<Real>::operator[](const ptrdiff_t i) const
{
    assert(i < 9 && "Index out of bounds.");
    return m_data[i];
}


/********************************************************************************
 * Access element (row,col).                                                    *
 *******************************************************************************/
template<class Real>
Real& Matrix3<Real>::operator()(const int row, const int col)
{
    assert(row < 3 && col < 3 && "Index out of bounds.");
    return m_data[col + row*3];
}


/********************************************************************************
 * Get copy of element (row,col).                                               *
 *******************************************************************************/
template<class Real>
const Real Matrix3<Real>::operator()(const int row, const int col) const
{
    assert(row < 3 && col < 3 && "Index out of bounds.");
    return m_data[col + row*3];
}


/********************************************************************************
 * Set row number row to the given vector.                                      *
 *******************************************************************************/
template<class Real>
void Matrix3<Real>::setRow(const int row, const Vector3<Real>& vec)
{
    assert(row < 3 && "Index out of bounds.");
    m_data[row*3]   = vec[0];
    m_data[row*3+1] = vec[1];
    m_data[row*3+2] = vec[2];
}


/********************************************************************************
 * Get row number row as a vector.                                              *
 *******************************************************************************/
template<class Real>
Vector3<Real> Matrix3<Real>::getRow(const int row) const
{
    assert(row < 3 && "Index out of bounds.");
    return Vector3<Real>(m_data[3*row], m_data[3*row + 1], m_data[3*row + 2]);
}


/********************************************************************************
 * Set column number col to the given vector.                                   *
 *******************************************************************************/
template<class Real>
void Matrix3<Real>::setColumn(const int col, const Vector3<Real>& vec)
{
    assert(col < 3 && "Index out of bounds.");
    m_data[col]     = vec[0];
    m_data[col + 3] = vec[1];
    m_data[col + 6] = vec[2];
}


/********************************************************************************
 * Get column number col as a vector.                                           *
 *******************************************************************************/
template<class Real>
Vector3<Real> Matrix3<Real>::getColumn(const int col) const
{
    assert(col < 3 && "Index out of bounds.");
    return Vector3<Real>(m_data[col], m_data[col + 3], m_data[col + 6]);
}


/********************************************************************************
 * Matrix assignment.                                                           *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::operator=(const Matrix3<Real>& mat)
{
    if(this != &mat)
        memcpy(m_data, mat.m_data, 9*sizeof(Real));
    return *this;
}


/********************************************************************************
 * Negate the matrix.                                                           *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator-() const
{
    return Matrix3<Real>( -m_data[0], -m_data[1], -m_data[2],
            -m_data[3], -m_data[4], -m_data[5],
            -m_data[6], -m_data[7], -m_data[8] );
}


/********************************************************************************
 * Add two matrices.                                                            *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator+(const Matrix3<Real>& mat) const
{
    return Matrix3<Real>(
            m_data[0] + mat[0], m_data[1] + mat[1], m_data[2] + mat[2],
            m_data[3] + mat[3], m_data[4] + mat[4], m_data[5] + mat[5],
            m_data[6] + mat[6], m_data[7] + mat[7], m_data[8] + mat[8]);
}


/********************************************************************************
 * Subtract two matrices.                                                       *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator-(const Matrix3<Real>& mat) const
{
    return Matrix3<Real>(
            m_data[0] - mat[0], m_data[1] - mat[1], m_data[2] - mat[2],
            m_data[3] - mat[3], m_data[4] - mat[4], m_data[5] - mat[5],
            m_data[6] - mat[6], m_data[7] - mat[7], m_data[8] - mat[8]);
}


/********************************************************************************
 * Multiply two matrix.                                                         *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator*(const Matrix3<Real>& mat) const
{
    return Matrix3<Real>(
            m_data[0]*mat[0] + m_data[1]*mat[3] + m_data[2]*mat[6],
            m_data[0]*mat[1] + m_data[1]*mat[4] + m_data[2]*mat[7],
            m_data[0]*mat[2] + m_data[1]*mat[5] + m_data[2]*mat[8],
            m_data[3]*mat[0] + m_data[4]*mat[3] + m_data[5]*mat[6],
            m_data[3]*mat[1] + m_data[4]*mat[4] + m_data[5]*mat[7],
            m_data[3]*mat[2] + m_data[4]*mat[5] + m_data[5]*mat[8],
            m_data[6]*mat[0] + m_data[7]*mat[3] + m_data[8]*mat[6],
            m_data[6]*mat[1] + m_data[7]*mat[4] + m_data[8]*mat[7],
            m_data[6]*mat[2] + m_data[7]*mat[5] + m_data[8]*mat[8]);
}


/********************************************************************************
 * Multiply a matrix with a vector.                                             *
 *******************************************************************************/
template<class Real>
Vector3<Real> Matrix3<Real>::operator*(const Vector3<Real>& vec) const
{
    return Vector3<Real>(
            m_data[0]*vec[0] + m_data[1]*vec[1] + m_data[2]*vec[2],
            m_data[3]*vec[0] + m_data[4]*vec[1] + m_data[5]*vec[2],
            m_data[6]*vec[0] + m_data[7]*vec[1] + m_data[8]*vec[2]);
}


/********************************************************************************
 * Multiply a matrix with a scalar.                                             *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator*(const Real& scalar) const
{
    return Matrix3<Real>(
            m_data[0]*scalar, m_data[1]*scalar, m_data[2]*scalar,
            m_data[3]*scalar, m_data[4]*scalar, m_data[5]*scalar,
            m_data[6]*scalar, m_data[7]*scalar, m_data[8]*scalar);
}


/********************************************************************************
 * Divide a matrix with a scalar.                                               *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator/(const Real& scalar) const
{
    assert(scalar != (Real)0.0 && "Division by zero error");
    return (*this) * (1.0/scalar);
}


/********************************************************************************
 * Add a matrix to this matrix.                                                 *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::operator+=(const Matrix3<Real>& mat)
{
    (*this) = (*this) + mat;
    return *this;
}


/********************************************************************************
 * Subtract a matrix from this matrix.                                          *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::operator-=(const Matrix3<Real>& mat)
{
    (*this) = (*this) - mat;
    return *this;
}


/********************************************************************************
 * Multiply this matrix with a scalar.                                          *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::operator*=(const Real& scalar)
{
    (*this) = (*this) * scalar;
    return *this;
}


/********************************************************************************
 * Divide this matrix with a scalar.                                            *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::operator/=(const Real& scalar)
{
    (*this) = (*this) / scalar;
    return *this;
}


/********************************************************************************
 * Get the absolute value of the matrix.                                        *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::abs() const
{
    return Matrix3<Real>(
            Math<Real>::Abs(m_data[0]), Math<Real>::Abs(m_data[1]), Math<Real>::Abs(m_data[2]),
            Math<Real>::Abs(m_data[3]), Math<Real>::Abs(m_data[4]), Math<Real>::Abs(m_data[5]),
            Math<Real>::Abs(m_data[6]), Math<Real>::Abs(m_data[7]), Math<Real>::Abs(m_data[8]));
}


/********************************************************************************
 * Get the determinant of the matrix.                                           *
 *******************************************************************************/
template<class Real>
Real Matrix3<Real>::det() const
{
    return (m_data[0]*(m_data[4]*m_data[8] - m_data[5]*m_data[7]) -
            m_data[1]*(m_data[3]*m_data[8] - m_data[5]*m_data[6]) +
            m_data[2]*(m_data[3]*m_data[7] - m_data[4]*m_data[6]));
}


/********************************************************************************
 * Get the transpose of the matrix.                                             *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::transpose() const
{
    return Matrix3<Real>(m_data[0], m_data[3], m_data[6],
            m_data[1], m_data[4], m_data[7],
            m_data[2], m_data[5], m_data[8]);
}


/********************************************************************************
 * Get the inverse of the matrix.                                               *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::inverse() const
{
    Real determ = this->det();
    assert( determ != (Real) 0.0 && "Trying to invert a singular matrix.");
    determ = 1.0/determ;

    Matrix3<Real> mat = this->transpose();

    Real m11, m12, m13, m21, m22, m23, m31, m32, m33;
    m11 = mat(1,1)*mat(2,2) - mat(1,2)*mat(2,1); 
    m12 = mat(1,2)*mat(2,0) - mat(1,0)*mat(2,2);
    m13 = mat(1,0)*mat(2,1) - mat(1,1)*mat(2,0);

    m21 = mat(0,2)*mat(2,1) - mat(0,1)*mat(2,2);
    m22 = mat(0,0)*mat(2,2) - mat(0,2)*mat(2,0);
    m23 = mat(0,1)*mat(2,0) - mat(0,0)*mat(2,1);

    m31 = mat(0,1)*mat(1,2) - mat(0,2)*mat(1,1);
    m32 = mat(0,2)*mat(1,0) - mat(0,0)*mat(1,2);
    m33 = mat(0,0)*mat(1,1) - mat(0,1)*mat(1,0);
    
    return (determ*Matrix3<Real>(m11, m12, m13,
                m21, m22, m23,
                m31, m32, m33));
}


/********************************************************************************
 * Check if two matrices are equal.                                             *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator==(const Matrix3<Real>& mat) const
{
    return compare(mat) == 0;
}


/********************************************************************************
 * Check if two matrices are not equal.                                         *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator!=(const Matrix3<Real>& mat) const
{
    return compare(mat) != 0;
}


/********************************************************************************
 * Check if this matrix is larger-then-or-equal-to another.                     *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator>=(const Matrix3<Real>& mat) const
{
    return compare(mat) >= 0;
}


/********************************************************************************
 * Check if this matrix is larger then another matrix.
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator>(const Matrix3<Real>& mat) const
{
    return compare(mat) > 0;
}


/********************************************************************************
 * Check if this matrix is smaller-then-or-equal-to another matrix.             *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator<=(const Matrix3<Real>& mat) const
{
    return compare(mat) <= 0;
}


/********************************************************************************
 * Check if this matrix is smaller then another.                                *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator<(const Matrix3<Real>& mat) const
{
    return compare(mat) < 0;
}


/********************************************************************************
 * Get the axis angle.                                                          *
 *******************************************************************************/
template<class Real>
void Matrix3<Real>::toAxisAngle(Vector3<Real>& axis, Real& angle) const
{
    Real trace = m_data[0] + m_data[4] + m_data[8];
    angle = Math<Real>::Arccos((trace - 1)/2);

    while( angle >= Math<Real>::TWO_PI )
        angle -= Math<Real>::TWO_PI;

    trace = 2*Math<Real>::Sin(angle);
    axis[0] = (m_data[2][1] - m_data[1][2])/trace;
    axis[1] = (m_data[0][2] - m_data[2][0])/trace;
    axis[2] = (m_data[1][0] - m_data[0][1])/trace;
}


/********************************************************************************
 * From euler angles.                                                           *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::fromEulerAnglesXYZ(const Real& yaw, const Real& pitch, 
        const Real& roll)
{
    Real cos, sin;

    cos = Math<Real>::Cos(yaw);
    sin = Math<Real>::Sin(yaw);
    Matrix3<Real> x_mat(1.0, 0.0, 0.0,
                        0.0, cos, -sin,
                        0.0, sin, cos);

    cos = Math<Real>::Cos(pitch);
    sin = Math<Real>::Sin(pitch);
    Matrix3<Real> y_mat(cos, 0.0, sin,
                        0.0, 1.0, 0.0,
                        -sin, 0.0, cos);

    cos = Math<Real>::Cos(roll);
    sin = Math<Real>::Sin(roll);
    Matrix3<Real> z_mat(cos, -sin, 0.0,
                        sin, cos, 0.0, 
                        0.0, 0.0, 1.0);

    *this = x_mat*(y_mat*z_mat);
    return *this;
}


template<class Real>
Matrix3<Real>& Matrix3<Real>::fromEulerAnglesXZY(const Real& yaw, const Real& pitch, 
        const Real& roll)
{
    Real cos, sin;

    cos = Math<Real>::Cos(yaw);
    sin = Math<Real>::Sin(yaw);
    Matrix3<Real> x_mat(1.0, 0.0, 0.0,
                        0.0, cos, -sin,
                        0.0, sin, cos);

    cos = Math<Real>::Cos(pitch);
    sin = Math<Real>::Sin(pitch);
    Matrix3<Real> z_mat(cos, -sin, 0.0,
                        sin, cos, 0.0,
                        0.0, 0.0, 1.0);

    cos = Math<Real>::Cos(roll);
    sin = Math<Real>::Sin(roll);
    Matrix3<Real> y_mat(cos, 0.0, sin,
                        0.0, 1.0, 0.0,
                        -sin, 0.0, cos);

    *this = x_mat*(z_mat*y_mat);
    return *this;
}


template<class Real>
Matrix3<Real>& Matrix3<Real>::fromEulerAnglesYXZ(const Real& yaw, const Real& pitch, 
        const Real& roll)
{
    Real cos, sin;

    cos = Math<Real>::Cos(yaw);
    sin = Math<Real>::Sin(yaw);
    Matrix3<Real> y_mat(cos, 0.0, sin,
                        0.0, 1.0, 0.0,
                        -sin, 0.0, cos);

    cos = Math<Real>::Cos(pitch);
    sin = Math<Real>::Sin(pitch);
    Matrix3<Real> x_mat(1.0, 0.0 ,0.0,
                        0.0, cos, -sin,
                        0.0, sin, cos);

    cos = Math<Real>::Cos(roll);
    sin = Math<Real>::Sin(roll);
    Matrix3<Real> z_mat(cos, -sin, 0.0,
                        sin, cos, 0.0,
                        0.0, 0.0, 1.0);

    *this = y_mat*(x_mat*z_mat);
    return *this;
}


template<class Real>
Matrix3<Real>& Matrix3<Real>::fromEulerAnglesYZX(const Real& yaw, const Real& pitch, 
        const Real& roll)
{
    Real cos, sin;

    cos = Math<Real>::Cos(yaw);
    sin = Math<Real>::Sin(yaw);
    Matrix3<Real> y_mat(cos, 0.0, sin,
                        0.0, 1.0, 0.0,
                        -sin, 0.0, cos);

    cos = Math<Real>::Cos(pitch);
    sin = Math<Real>::Sin(pitch);
    Matrix3<Real> z_mat(cos, -sin, 0.0,
                        sin, cos, 0.0,
                        0.0, 0.0, 1.0);


    cos = Math<Real>::Cos(roll);
    sin = Math<Real>::Sin(roll); 
    Matrix3<Real> x_mat(1.0, 0.0 ,0.0,
                        0.0, cos, -sin,
                        0.0, sin, cos);

    *this = y_mat*(z_mat*x_mat);
    return *this;
}


template<class Real>
Matrix3& fromEulerAnglesZXY(const Real& yaw, const Real& pitch, const Real& roll)
{
    Real cos, sin;

    cos = Math<Real>::Cos(yaw);
    sin = Math<Real>::Sin(yaw);
    Matrix3<Real> z_mat(cos, -sin, 0.0,
                        sin, cos, 0.0,
                        0.0, 0.0, 1.0);


    cos = Math<Real>::Cos(pitch);
    sin = Math<Real>::Sin(pitch);
    Matrix3<Real> x_mat(1.0, 0.0 ,0.0,
                        0.0, cos, -sin,
                        0.0, sin, cos);

    cos = Math<Real>::Cos(roll);
    sin = Math<Real>::Sin(roll);
    Matrix3<Real> y_mat(cos, 0.0, sin,
                        0.0, 1.0, 0.0,
                        -sin, 0.0, cos);

    *this = z_mat*(x_mat*y_mat);
    return *this;
}


template<class Real>
Matrix3<Real>& Matrix3<Real>::fromEulerAnglesZYX(const Real& yaw, const Real& pitch, 
        const Real& roll)
{
    Real cos, sin;

    cos = Math<Real>::Cos(yaw);
    sin = Math<Real>::Sin(yaw);
    Matrix3<Real> z_mat(cos, -sin, 0.0,
                        sin, cos, 0.0,
                        0.0, 0.0, 1.0);

    cos = Math<Real>::Cos(pitch);
    sin = Math<Real>::Sin(pitch);
    Matrix3<Real> y_mat(cos, 0.0, sin,
                        0.0, 1.0, 0.0,
                        -sin, 0.0, cos);

    cos = Math<Real>::Cos(roll);
    sin = Math<Real>::Sin(roll);
    Matrix3<Real> x_mat(1.0, 0.0 ,0.0,
                        0.0, cos, -sin,
                        0.0, sin, cos);

    *this = z_mat*(y_mat*x_mat);
    return *this;
}


/********************************************************************************
 * To Euler angles.                                                             *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::toEulerAnglesXYZ(Real& yaw, Real& pitch, Real& roll)
{
    return false;
}


template<class Real>
bool Matrix3<Real>::toEulerAnglesXZY(Real& yaw, Real& pitch, Real& roll)
{
    return false;
}


template<class Real>
bool Matrix3<Real>::toEulerAnglesYXZ(Real& yaw, Real& pitch, Real& roll)
{
    return false;
}


template<class Real>
bool Matrix3<Real>::toEulerAnglesYZX(Real& yaw, Real& pitch, Real& roll)
{
    return false;
}


template<class Real>
bool Matrix3<Real>::toEulerAnglesZXY(Real& yaw, Real& pitch, Real& roll)
{
    return false;
}


template<class Real>
bool Matrix3<Real>::toEulerAnglesZYX(Real& yaw, Real& pitch, Real& roll)
{
    return false;
}


/********************************************************************************
 * Orthonormalize the matrix.                                                   *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::orthonormalize()
{
    Real len = Math<Real>::Sqrt( m_data[0]*m_data[0] + m_data[3]*m_data[3] +
            m_data[6]*m_data[6] );
    
    assert( len != 0 );

    m_data[0] /= len;
    m_data[3] /= len;
    m_data[6] /= len;

    Real dot = m_data[0]*m_data[1] + m_data[3]*m_data[4] + m_data[6]*m_data[7];
    m_data[1] -= dot*m_data[0];
    m_data[4] -= dot*m_data[3];
    m_data[7] -= dot*m_data[6];

    len = Math<Real>::Sqrt( m_data[1]*m_data[1] + m_data[4]*m_data[4] +
            m_data[7]*m_data[7]);

    assert( len != 0 );
    m_data[1] /= len;
    m_data[4] /= len;
    m_data[7] /= len;

    dot = m_data[0]*m_data[2] + m_data[3]*m_data[5] + m_data[6]*m_data[8];
    m_data[2] -= dot*m_data[0];
    m_data[5] -= dot*m_data[3];
    m_data[8] -= dot*m_data[6];

    dot = m_data[1]*m_data[2] + m_data[4]*m_data[5] + m_data[7]*m_data[8];
    m_data[2] -= dot*m_data[1];
    m_data[5] -= dot*m_data[4];
    m_data[8] -= dot*m_data[7];

    len = Math<Real>::Sqrt( m_data[2]*m_data[2] + m_data[5]*m_data[5] +
            m_data[8]*m_data[8] );

    assert( len != 0 );

    m_data[2] /= len;
    m_data[5] /= len;
    m_data[8] /= len;
    return *this;
}


/********************************************************************************
 * Eigenvalue decomposition.                                                    *
 *******************************************************************************/
template<class Real>
void Matrix3<Real>::eigenDecompose(Vector3<Real>& lambda, Matrix3<Real>& v_mat)
    const
{
    Real diag[3], subdiag[2];
    v_mat = *this;
    bool reflection = v_mat.tridiagonalize(diag, subdiag);
    bool converged = v_mat.QLfactorize(diag, subdiag);
    assert( converged );

    int i;
    Real save;

    if( diag[1] < diag[0] ) {
        save = diag[0];
        diag[0] = diag[1];
        diag[1] = save;

        for(i = 0; i < 3; i++) {
            save = v_mat(i,0);
            v_mat(i,0) = v_mat(i, 1);
            v_mat(i, 1) = save;
        }
        reflection = !reflection;
    }

    if( diag[2]  < diag[1] ) {
        save = diag[1];
        diag[1] = diag[2];
        diag[2] = save;

        for(i = 0; i < 3; i++) {
            save = v_mat(i,1);
            v_mat(i,1) = v_mat(i,2);
            v_mat(i,2) = save;
        }
        reflection = !reflection;
    }

    if( diag[1] < diag[0] ) {
        save = diag[0];
        diag[0] = diag[1];
        diag[1] = save;

        for(i = 0; i < 3; i++) {
            save = v_mat(i,0);
            v_mat(i,0) = v_mat(i,1);
            v_mat(i,1) = save;
        }
        
        reflection = !reflection;
    }

    lambda[0] = diag[0];
    lambda[1] = diag[1];
    lambda[2] = diag[2];

    if( reflection ) {
        v_mat(0,2) = -v_mat(0,2);
        v_mat(1,2) = -v_mat(1,2);
        v_mat(2,2) = -v_mat(2,2);
    }
}


/********************************************************************************
 * Makes it possible to write scalar*matrix.                                    *
 *******************************************************************************/
template<class Real>
Matrix3<Real> operator*(const Real& scalar, const Matrix3<Real>& mat)
{
    return mat*scalar;
}


/********************************************************************************
 * Compare two matrices.                                                        *
 *******************************************************************************/
template<class Real>
int Matrix3<Real>::compare(const Matrix3<Real>& mat) const
{
    for(int i = 0; i < 9; i++) {
        if(Math<Real>::Abs(m_data[i] - mat[i]) >= Math<Real>::EPSILON) {
            if(m_data[i] < mat[i])
                return -1;
            return 1;
        }
    }

    return 0;
}


/********************************************************************************
 * Tridiagonalize the matrix.                                                   *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::tridiagonalize(Real diag[3], Real subdiag[2])
{
    Real m00 = m_data[0];
    Real m01 = m_data[1];
    Real m02 = m_data[2];
    Real m11 = m_data[4];
    Real m12 = m_data[5];
    Real m22 = m_data[8];

    diag[0] = m00;
    if( Math<Real>::Abs(m02) >= Math<Real>::EPSILON) {
        subdiag[0] = Math<Real>::Sqrt(m01*m01 + m02*m02);
        Real invlen = 1.0/subdiag[0];
        m01 *= invlen;
        m02 *= invlen;

        Real tmp = 2.0*m01*m12*m02*(m22-m11);
        diag[1] = m11 + m02*tmp;
        diag[2] = m22 - m02*tmp;
        subdiag[1] = m12 - m01*tmp;

        m_data[0] = 1.0;
        m_data[1] = 0.0;
        m_data[2] = 0.0;
        m_data[3] = 0.0;
        m_data[4] = m01;
        m_data[5] = m02;
        m_data[6] = 0.0;
        m_data[7] = m02;
        m_data[8] = -m01;
        return true;
    }

    diag[1] = m11;
    diag[2] = m22;
    subdiag[0] = m01;
    subdiag[1] = m12;

    m_data[0] = 1.0;
    m_data[1] = 0.0;
    m_data[2] = 0.0;
    m_data[3] = 0.0;
    m_data[4] = 1.0;
    m_data[5] = 0.0;
    m_data[6] = 0.0;
    m_data[7] = 0.0;
    m_data[8] = 1.0;
    return false;
}


/********************************************************************************
 * Run a QL factorization algorithm.                                            *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::QLfactorize(Real diag[3], Real subdiag[2])
{
    const int max = 32;
    for(int i = 0; i < max; i++) {
        Real sum, diff, discr, evalue0, evalue1, cos, sin, tmp;
        int row;

        sum = Math<Real>::Abs(diag[0]) + Math<Real>::Abs(diag[1]);
        if( subdiag[0] == (Real) 0.0 ) {
            sum = diag[1] + diag[2];
            diff = diag[1] - diag[2];
            discr = Math<Real>::Sqrt(diff*diff + 4.0*subdiag[1]*subdiag[1]);
            evalue0 = 0.5*(sum - discr);
            evalue1 = 0.5*(sum + discr);

            if( diff < 0.0 ) {
                cos = diag[2] - evalue0;
                sin = subdiag[1];
            } else {
                cos = subdiag[1];
                sin = diag[1] - evalue0;
            }

            tmp = Math<Real>::InvSqrt(cos*cos + sin*sin);
            cos *= tmp;
            sin *= tmp;

            for(row = 0; row < 3; row++) {
                tmp = m_data[3*row + 2];
                m_data[3*row+2] = sin*m_data[3*row + 1] + cos*tmp;
                m_data[3*row+1] = cos*m_data[3*row+1] - sin*tmp;
            }

            diag[1] = evalue0;
            diag[2] = evalue1;
            subdiag[0] = 0.0;
            subdiag[1] = 0.0;
            return true;
        }

        sum = Math<Real>::Abs(diag[1]) + Math<Real>::Abs(diag[2]);
        if( subdiag[1] == 0.0 ) {
            sum = diag[0] + diag[1];
            diff = diag[0] - diag[1];
            discr = Math<Real>::Sqrt(diff*diff + 4.0*subdiag[0]*subdiag[0]);
            evalue0 = 0.5*(sum - discr);
            evalue1 = 0.5*(sum + discr);

            if(diff < 0.0) {
                cos = diag[1] - evalue0;
                sin = subdiag[0];
            } else {
                cos = subdiag[0];
                sin = diag[0] - evalue0;
            }

            tmp = Math<Real>::InvSqrt(cos*cos + sin*sin);
            cos *= tmp;
            sin *= tmp;

            for(row = 0; row < 3; row++) {
                tmp = m_data[3*row + 1];
                m_data[3*row + 1] = sin*m_data[3*row] + cos*tmp;
                m_data[3*row] = cos*m_data[3*row] - sin*tmp;
            }

            diag[0] = evalue0;
            diag[1] = evalue1;
            subdiag[0] = 0.0;
            subdiag[1] = 0.0;
            return true;
        }

        Real ratio = (diag[1] - diag[0])/(2.0*subdiag[0]);
        Real root = Math<Real>::Sqrt(1.0 + ratio*ratio);
        Real B = subdiag[1];
        Real A = diag[2] - diag[0];
        if( ratio < 0.0 )
            A += subdiag[0]/(ratio - root);
        else
            A += subdiag[0]/(ratio + root);

        if( Math<Real>::Abs(B) >= Math<Real>::Abs(A) ) {
            ratio = A/B;
            sin = Math<Real>::InvSqrt(1.0 + ratio*ratio);
            cos = ratio*sin;
        } else {
            ratio = B/A;
            cos = Math<Real>::InvSqrt(1.0 + ratio*ratio);
            sin = ratio*cos;
        }

        for(row = 0; row < 3; row++) {
            tmp = m_data[row*3 + 2];
            m_data[row*3+2] = sin*m_data[row*3+1] + cos*tmp;
            m_data[row*3+1] = cos*m_data[row*3+1] - sin*tmp;
        }

        Real tmp0 = (diag[1] - diag[2])*sin + 2.0*subdiag[1]*cos;
        Real tmp1 = cos*subdiag[0];
        B = sin*subdiag[0];
        A = cos*tmp0 - subdiag[1];
        tmp0 *= sin;

        if( Math<Real>::Abs(B) >= Math<Real>::Abs(A) ) {
            ratio = A/B;
            root = Math<Real>::Sqrt(1.0 + ratio*ratio);
            subdiag[1] = B*root;
            sin = 1.0/root;
            cos = ratio*sin;
        } else {
            ratio = B/A;
            root = Math<Real>::Sqrt(1.0 + ratio*ratio);
            subdiag[1] = A*root;
            cos = 1.0/root;
            sin = ratio*cos;
        }

        for(row = 0; row < 3; row++) {
            tmp = m_data[row*3 + 1];
            m_data[row*3+1] = sin*m_data[row*3] + cos*tmp;
            m_data[row*3] = cos*m_data[row*3] - sin*tmp;
        }

        Real tmp2 = diag[1] - tmp0;
        diag[2] += tmp0;
        tmp0 = (diag[0] - tmp2)*sin + 2.0*tmp1*cos;
        subdiag[0] = cos*tmp0 - tmp1;
        tmp0 *= sin;
        diag[1] = tmp2 + tmp0;
        diag[0] -= tmp0;
    }

    return false;
}


#ifdef DEBUG
/********************************************************************************
 * Print out the matrix.                                                        *
 *******************************************************************************/
template<class Real>
void Matrix3<Real>::print() const
{
    printf("\n|%8.4f %8.4f %8.4f|\n|%8.4f %8.4f %8.4f|\n|%8.4f %8.4f %8.4f|\n", 
            m_data[0], m_data[1], m_data[2],
            m_data[3], m_data[4], m_data[5],
            m_data[6], m_data[7], m_data[8]);
}
#endif
} // namespace Math
} // namespace Pandora
