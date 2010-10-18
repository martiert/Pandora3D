/*
-------------------------------------------------------------------------------
This source file is part of Pandora3D.

This program is free software: you can redistribute it and/or modify it under 
the terms of the GNU General Public License as published by the Free Software 
Foundation. Either version 2 of the License, or (at your option) any later 
version.

This program comes without any warranty whatsoever, but under the hope that it
will be useful. See the GNU General Public License for more information.

You should have received a copy of the GNU Lesser General Public License along 
with this program; if not, write to the Free Software Foundation, Inc., 59 
Temple Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
-------------------------------------------------------------------------------
*/

#ifndef PANDORAMATRIX4_H
#define PANDORAMATRIX4_H

#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>

#include "PandoraMath.h"
#include "PandoraMatrix3.h"
#include "PandoraVector3.h"
#include "PandoraVector4.h"

namespace Pandora
{
    namespace Math
    {
        /**
         *  Pandoras Matrix4 class. Values are stored in row major order, like
         *  OpenGL:
         *
         *  |0   1  2  3|
         *  |4   5  6  7|
         *  |8   9 10 11|
         *  |12 13 14 15|
         */
        template<class Real>
        class Matrix4
        {
            public:
                /**
                 *  Default constructor. Makes a non-spesific matrix for speed.
                 */
                Matrix4();

                /**
                 *  Constructor. Makes a 4x4 matrix of the numbers given.
                 *  \param
                 *      m00 - The number at [0][0]
                 *  \param
                 *      m01 - The number at [0][1]
                 *  \param
                 *      m02 - The number at [0][2]
                 *  \param
                 *      m03 - The number at [0][3]
                 *  \param
                 *      m10 - The number at [1][0]
                 *  \param
                 *      m11 - The number at [1][1]
                 *  \param
                 *      m12 - The number at [1][2]
                 *  \param
                 *      m13 - The number at [1][3]
                 *  \param
                 *      m20 - The number at [2][0]
                 *  \param
                 *      m21 - The number at [2][1]
                 *  \param
                 *      m22 - The number at [2][2]
                 *  \param
                 *      m23 - The number at [2][3]
                 *  \param
                 *      m30 - The number at [3][0]
                 *  \param
                 *      m31 - The number at [3][1]
                 *  \param
                 *      m32 - The number at [3][2]
                 *  \param
                 *      m33 - The number at [3][3]
                 */
                Matrix4(const Real& m00, const Real& m01, const Real& m02, 
                            const Real& m03,
                        const Real& m10, const Real& m11, const Real& m12,
                            const Real& m13,
                        const Real& m20, const Real& m21, const Real& m22,
                            const Real& m23,
                        const Real& m30, const Real& m31, const Real& m32,
                            const Real& m33);

                /**
                 *  Makes a matrix which rotates rad radians around given axis.
                 *  \param
                 *      rad - The number of radians to rotate.
                 *  \param
                 *      r - The axis to rotate around.    
                 */
                Matrix4(const Real& rad, Vector4<Real> r);

                /**
                 *  Construct either a scaling or a translation matrix,
                 *  depending on the boolean value given.
                 *  \param
                 *      vec - The scaling/translation vector.
                 *  \param
                 *      scale - A bool value which tells if it's a scaling
                 *              or a translation matrix. True if scaling, false
                 *              if translating.
                 */
                Matrix4(const Vector3<Real>& vec, const bool scale);

                /**
                 *  Initialize the matrix with an array.
                 *  \param
                 *      array - An array of size 16, which holds the values
                 *              of the matrix.
                 */
                Matrix4(const Real array[16]);

                /**
                 *  Copy a 4D matrix.
                 *  \param
                 *      mat - The matrix to copy.
                 */
                Matrix4(const Matrix4& mat);

                /**
                 *  Copy a 3D matrix.
                 *  \param
                 *      mat - The matrix to copy.
                 */
                Matrix4(const Matrix3<Real>& mat);

                /**
                 *  Implicit conversion to array.
                 *  \return
                 *      The matrix as an array.
                 */
                operator Real *();

                /**
                 *  Implicit conversion to constant array.
                 *  \return
                 *      The matrix as a constant array.
                 */
                operator const Real *() const;

                /**
                 *  Get reference to element i in the matrix.
                 *  \param
                 *      i - The element we want.
                 *  \return
                 *      A reference to element i in the matrix.
                 */
                Real& operator[](const ptrdiff_t i);

                /**
                 *  Get the value in element i from the matrix.
                 *  \param
                 *      i - The value we want.
                 *  \return
                 *      The value in element i in the matrix.
                 */
                const Real operator[](const ptrdiff_t i) const;

                /**
                 *  Get element in (row,col).
                 *  \param
                 *      row - The row we want.
                 *  \param
                 *      col - The column we want.
                 *  \return
                 *      Reference to the element in (row,col).
                 */
                Real& operator()(const int row, const int col);

                /**
                 *  Get the value in element (row,col) from the matrix.
                 *  \param
                 *      row - The row we want.
                 *  \param
                 *      col - The column we want.
                 *  \return
                 *      The value in element (row,col) from the matrix.
                 */
                const Real operator()(const int row, const int col) const;

                /**
                 *  Get row number i from the matrix as a vector.
                 *  \param
                 *      row - The row we want.
                 *  \return
                 *      Row number i as a vector.
                 */
                Vector4<Real> getRow(const int row) const;

                /**
                 *  Set row number i to the given vector.
                 *  \param
                 *      row - The row we wish to set.
                 *  \param
                 *      vec - The vector we wish to set it to.
                 */
                void setRow(const int row, const Vector4<Real>& vec);

                /**
                 *  Get column number i from the matrix as a vector.
                 *  \param
                 *      col - The column we want.
                 *  \return
                 *      Column i as a 4D vector.
                 */
                Vector4<Real> getColumn(const int col) const;

                /**
                 *  Set column number i to the given matrix.
                 *  \param
                 *      col - The column we wish to set.
                 *  \param
                 *      vec - The vector we wish to set it to.
                 */
                void setColumn(const int col, const Vector4<Real>& vec);

                /**
                 *  Matrix assignment. Set this matrix equal to another.
                 *  \param
                 *      mat - The matrix we wish to set it to.
                 *  \return
                 *      This matrix.
                 */
                Matrix4& operator=(const Matrix4& mat);

                /**
                 *  Matrix assignment. Set the top left part of the matrix
                 *  equal to a 3x3 matrix.
                 *  \param
                 *      mat - The matrix we assign to.
                 *  \return
                 *      This matrix.
                 */
                Matrix4& operator=(const Matrix3<Real>& mat);

                /**
                 *  Negate the matrix.
                 *  \return
                 *      This matrix negated.
                 */
                Matrix4 operator-() const;

                /**
                 *  Add two matrices.
                 *  \param
                 *      mat - The matrix to add with.
                 *  \return
                 *      This matrix added with mat.
                 */
                Matrix4 operator+(const Matrix4& mat) const;

                /**
                 *  Subtract two matrices.
                 *  \param
                 *      mat - The matrix to subtract with.
                 *  \return
                 *      This matrix subtracted with mat.
                 */
                Matrix4 operator-(const Matrix4& mat) const;

                /**
                 *  Multiply two matrices.
                 *  \param
                 *      mat - The matrix to multiply with.
                 *  \return
                 *      This matrix multiplied with mat.
                 */
                Matrix4 operator*(const Matrix4& mat) const;

                /**
                 *  Multiply a matrix and a vector.
                 *  \param
                 *      vec - The vector to multiply with.
                 *  \return
                 *      This matrix multiplied with vec.
                 */
                Vector4<Real> operator*(const Vector4<Real>& vec) const;

                /**
                 *  Multiply a matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      This matrix multiplied with a scalar.
                 */
                Matrix4 operator*(const Real& scalar) const;

                /**
                 *  Divide a matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return 
                 *      This matrix divided by a scalar.
                 *  \note
                 *      Will only check for division by zero in DEBUG mode.
                 */
                Matrix4 operator/(const Real& scalar) const;

                /**
                 *  Add a matrix to this matrix.
                 *  \param
                 *      mat - The matrix to add with.
                 *  \return
                 *      This matrix.
                 */
                Matrix4& operator+=(const Matrix4& mat);

                /**
                 *  Subtract a matrix from this matrix.
                 *  \param
                 *      mat - The matrix to subtract with.
                 *  \return
                 *      This matrix.
                 */
                Matrix4& operator-=(const Matrix4& mat);

                /**
                 *  Multiply this matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      This matrix.
                 */
                Matrix4& operator*=(const Real& scalar);

                /**
                 *  Divide this matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      This matrix.
                 *  \note
                 *      Will only check for division by zero in DEBUG mode.
                 */
                Matrix4& operator/=(const Real& scalar);


                /**
                 *  Dot multiply this matrix with another.
                 *  \param
                 *      mat - The matrix to dot multiply with.
                 *  \return
                 *      This matrix dot-multiplied with another.
                 */
                Matrix4 dotprod(const Matrix4& mat) const;

                /**
                 *  Dot multiply a matrix to this matrix.
                 *  \param
                 *      mat - The matrix to dot multiply with.
                 *  \return
                 *      This matrix.
                 */
                Matrix4& operator*=(const Matrix4& mat);

                /**
                 *  Get the absolute value of this matrix.
                 *  \return
                 *      This matrix where all elements is positive.
                 */
                Matrix4 abs() const;

                /**
                 *  Get the determinant of this matrix.
                 *  \return
                 *      The determinant of this matrix.
                 */
                Real det() const;

                /**
                 *  Get the transpose of this matrix.
                 *  \return 
                 *      The transpose of this matrix.
                 */
                Matrix4 transpose() const;

                /**
                 *  Calculate the cofactor matrix of this matirx.
                 *  \param
                 *      The cofactor matrix of this matrix.
                 */
                Matrix4 cofactor() const;

                /**
                 *  Get the inverse of this matrix.
                 *  \return
                 *      The inverse of this matrix.
                 */
                Matrix4 inverse() const;

                /**
                 *  Check for equality.
                 *  \param
                 *      mat - The matrix to check if is equal.
                 *  \return
                 *      True if all elements are equal, false otherwise.
                 */
                bool operator==(const Matrix4& mat) const;

                /**
                 *  Check for inequality.
                 *  \param
                 *      mat - The matrix to check if differs from this.
                 *  \return
                 *      False if all elements are equal, true otherwise.
                 */
                bool operator!=(const Matrix4& mat) const;

                /**
                 *  Check if this matrix is larger-then-or-equal-to another
                 *  matrix.
                 *  \param
                 *      mat - The matrix to compare with.
                 *  \return 
                 *      True if all elements are equal, or if the first element
                 *      that differ is larger then mat. False otherwise.
                 */
                bool operator>=(const Matrix4& mat) const;

                /**
                 *  Check if this matrix is larger-then another.
                 *  \param
                 *      mat - The matrix to compare with.
                 *  \return
                 *      True if the first element that differ is larger then
                 *      the element in mat. False otherwise.
                 */
                bool operator>(const Matrix4& mat) const;

                /**
                 *  Check if this matrix is less-then-or-equal-to another 
                 *  matrix.
                 *  \param
                 *      mat - The matrix to compare with.
                 *  \return
                 *      True if all elements are equal, or if the first element
                 *      that differ is smaller. False otherwise.
                 */
                bool operator<=(const Matrix4& mat) const;

                /**
                 *  Check if this matrix is less-then another matrix.
                 *  \param
                 *      mat - The matrix to compare with.
                 *  \return
                 *      True if the first element that differs is smaller then
                 *      in mat. False otherwise.
                 */
                bool operator<(const Matrix4& mat) const;

                /**
                 *  Get the trace of the matrix.
                 *  \return
                 *      The trace of the matrix.
                 */
                Real trace() const;

#ifdef DEBUG
                /**
                 *  Print out the matrix. Only available in DEBUG mode.
                 */
                void print() const;
#endif //DEBUG
                static const Matrix4 ZERO;
                static const Matrix4 IDENTITY;
                static const Matrix4 ONES;
            protected:
                Real m_data[16];

                int compare(const Matrix4& mat) const;
        };

        /**
         *  Makes it possible to write scalar*matrix.
         *  \param
         *      scalar - The scalar.
         *  \parma
         *      mat - The matrix.
         *  \return
         *      scalar*matrix.
         */
        template<class Real>
        Matrix4<Real> operator*(const Real scalar, const Matrix4<Real>& mat);

        /**
         *  Typedefs.
         */
        typedef Matrix4<float>          Mat4f;
        typedef Matrix4<double>         Mat4d;
        typedef Matrix4<int>            Mat4i;
        typedef Matrix4<unsigned int>   Mat4u;

/********************************************************************************
 * Default constructor.                                                         *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(){}


/********************************************************************************
 * Constructor.                                                                 *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(
        const Real& m00, const Real& m01, const Real& m02, const Real& m03,
        const Real& m10, const Real& m11, const Real& m12, const Real& m13,
        const Real& m20, const Real& m21, const Real& m22, const Real& m23,
        const Real& m30, const Real& m31, const Real& m32, const Real& m33)
{
    m_data[0] = m00; m_data[1] = m01; m_data[2] = m02; m_data[3] = m03;
    m_data[4] = m10; m_data[5] = m11; m_data[6] = m12; m_data[7] = m13;
    m_data[8] = m20; m_data[9] = m21; m_data[10] = m22; m_data[11] = m23;
    m_data[12] = m30; m_data[13] = m31; m_data[14] = m32; m_data[15] = m33;
}


/********************************************************************************
 * Make rotation matrix.                                                        *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(const Real& rad, Vector4<Real> r)
{
    r.normalize();
    Real t_cos = Math<Real>::Cos(rad);
    Real t_sin = Math<Real>::Sin(rad);

    m_data[0] = t_cos + (1 - t_cos)*r[0]*r[0];
    m_data[1] = (1 - t_cos)*r[0]*r[1] - r[2]*t_sin;
    m_data[2] = (1 - t_cos)*r[0]*r[2] + r[1]*t_sin;

    m_data[4] = (1 - t_cos)*r[0]*r[1] + r[2]*t_sin;
    m_data[5] = t_cos + (1 - t_cos)*r[1]*r[1];
    m_data[6] = (1 - t_cos)*r[1]*r[2] - r[0]*t_sin;

    m_data[8] = (1 - t_cos)*r[0]*r[2] - r[1]*t_sin;
    m_data[9] = (1 - t_cos)*r[1]*r[2] + r[0]*t_sin;
    m_data[10] = t_cos + (1 - t_cos)*r[2]*r[2];

    m_data[3] = 0;
    m_data[7] = 0;
    m_data[11] = 0;
    m_data[12] = 0;
    m_data[13] = 0;
    m_data[14] = 0;
    m_data[15] = 1;
}


/********************************************************************************
 * Make a scaling or a rotation matrix.                                         *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(const Vector3<Real>& vec, const bool scale)
{
    *this = IDENTITY;
    if(scale) {
        m_data[0] = vec[0];
        m_data[5] = vec[1];
        m_data[10] = vec[2];
        return;
    }

    m_data[3] = vec[0];
    m_data[7] = vec[1];
    m_data[11] = vec[2];
}


/********************************************************************************
 * Construct a matrix from an array.                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(const Real array[16])
{
    memcpy(m_data, array, 16*sizeof(Real));
}


/********************************************************************************
 * Copy a 4D matrix.                                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(const Matrix4<Real>& mat)
{
    memcpy(m_data, mat.m_data, 16*sizeof(Real));
}


/********************************************************************************
 * Copy a 3D matrix.                                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(const Matrix3<Real>& mat)
{
    *this = IDENTITY;
    m_data[0] = mat[0]; m_data[1] = mat[1]; m_data[2] = mat[2];
    m_data[4] = mat[3]; m_data[5] = mat[4]; m_data[6] = mat[5];
    m_data[8] = mat[6]; m_data[9] = mat[7]; m_data[10] = mat[8];
}


/********************************************************************************
 * Conversion operator.                                                         *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::operator Real *()
{
    return &(m_data[0]);
}


/********************************************************************************
 * Constant conversion operator.                                                *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::operator const Real *() const
{
    return &(m_data[0]);
}


/********************************************************************************
 * Access operator.                                                             *
 *******************************************************************************/
template<class Real>
Real& Matrix4<Real>::operator[](const ptrdiff_t i)
{
    assert(i < 16 && "Index out of bounds");

    return m_data[i];
}


/********************************************************************************
 * Constant access operator.                                                    *
 *******************************************************************************/
template<class Real>
const Real Matrix4<Real>::operator[](const ptrdiff_t i) const
{
    assert(i < 16 && "Index out of bounds");

    return m_data[i];
}


/********************************************************************************
 * Get reference to element (row,col).                                          *
 *******************************************************************************/
template<class Real>
Real& Matrix4<Real>::operator()(const int row, const int col)
{
    assert(row < 4 && col < 4 && "Index out of bounds");

    return m_data[col + row*4];
}


/********************************************************************************
 * Get constant copy of element (row,col).                                      *
 *******************************************************************************/
template<class Real>
const Real Matrix4<Real>::operator()(const int row, const int col) const
{
    assert(row < 4 && col < 4 && "Index out of bounds");

    return m_data[col + row*4];
}


/********************************************************************************
 * Get row number row.                                                          *
 *******************************************************************************/
template<class Real>
Vector4<Real> Matrix4<Real>::getRow(const int row) const
{
    assert(row < 4 && "Index out of bounds");

    return Vector4<Real>(m_data[4*row], m_data[4*row + 1], m_data[4*row + 2],
            m_data[4*row + 3]);
}


/********************************************************************************
 * Set row number row to the given vector.                                      *
 *******************************************************************************/
template<class Real>
void Matrix4<Real>::setRow(const int row, const Vector4<Real>& vec)
{
    assert(row < 4 && "Index out of bounds");

    m_data[4*row]       = vec[0];
    m_data[4*row + 1]   = vec[1];
    m_data[4*row + 2]   = vec[2];
    m_data[4*row + 3]   = vec[3];
}


/********************************************************************************
 * Get column numbet col as a vector.                                           *
 *******************************************************************************/
template<class Real>
Vector4<Real> Matrix4<Real>::getColumn(const int col) const
{
    assert(col < 4 && "Index out of bounds");

    return Vector4<Real>(m_data[col], m_data[col + 4], m_data[col + 8], 
            m_data[col + 12]);
}


/********************************************************************************
 * Set column number col to the given vector.                                   *
 *******************************************************************************/
template<class Real>
void Matrix4<Real>::setColumn(const int col, const Vector4<Real>& vec)
{
    assert(col < 4 && "Index out of bounds");

    m_data[col]      = vec[0];
    m_data[col + 4]  = vec[1];
    m_data[col + 8]  = vec[2];
    m_data[col + 12] = vec[3];
}


/********************************************************************************
 * Copy a matrix to this matrix.                                                *
 *******************************************************************************/
template<class Real>
Matrix4<Real>& Matrix4<Real>::operator=(const Matrix4<Real>& mat)
{
    if(this != &mat)
        memcpy(m_data, mat.m_data, 16*sizeof(Real));
    return *this;
}


/********************************************************************************
 * Copy a 3x3 matrix to this matrix.                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real>& Matrix4<Real>::operator=(const Matrix3<Real>& mat)
{
    *this = IDENTITY;
    m_data[0] = mat[0]; m_data[1] = mat[1]; m_data[2] = mat[2];
    m_data[4] = mat[3]; m_data[5] = mat[4]; m_data[6] = mat[5];
    m_data[8] = mat[6]; m_data[9] = mat[7]; m_data[10] = mat[8];

    return (*this);
}


/********************************************************************************
 * Negate this matrix.                                                          *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator-() const
{
    Mat4d tmp;
    tmp = (*this) * (-1);
    return tmp;
}


/********************************************************************************
 * Add two matrices.                                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator+(const Matrix4<Real>& mat) const
{
    Matrix4<Real> tmp((*this));

    for(int i = 0; i < 16; i++)
        tmp[i] += mat[i];

    return tmp;
}


/********************************************************************************
 * Subtract two matrices.                                                       *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator-(const Matrix4<Real>& mat) const
{
    Matrix4<Real> tmp((*this));

    for(int i = 0; i < 16; i++)
        tmp[i] -= mat[i];
    
    return tmp;
}


/********************************************************************************
 * Multiply two matrices.                                                       *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator*(const Matrix4<Real>& mat) const
{
    Matrix4<Real> tmp = Matrix4<Real>::ZERO;

    for(int row = 0; row < 4; row++) {
        for(int col = 0; col < 4; col++) {
            for(int k = 0; k < 4; k++) {
                tmp[row*4 + col] += m_data[row*4 + k] * mat[k*4 + col];
            }
        }
    }

    return tmp;
}


/********************************************************************************
 * Multiply a matrix with a vector.                                             *
 *******************************************************************************/
template<class Real>
Vector4<Real> Matrix4<Real>::operator*(const Vector4<Real>& vec) const
{
    return Vector4<Real>(
            vec[0]*m_data[0] + vec[1]*m_data[1] + vec[2]*m_data[2] + 
                vec[3]*m_data[3],
            vec[0]*m_data[4] + vec[1]*m_data[5] + vec[2]*m_data[6] + 
                vec[3]*m_data[7],
            vec[0]*m_data[8] + vec[1]*m_data[9] + vec[2]*m_data[10] + 
                vec[3]*m_data[11],
            vec[0]*m_data[12] + vec[1]*m_data[13] + vec[2]*m_data[14] + 
                vec[3]*m_data[15]);
}


/********************************************************************************
 * Multiply a matrix with a scalar.                                             *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator*(const Real& scalar) const
{
    Matrix4<Real> mat((*this));

    for(int i = 0; i < 16; i++)
        mat[i] *= scalar;
    return mat;
}


/********************************************************************************
 * Divide a matrix with a scalar.                                               *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator/(const Real& scalar) const
{
    assert(scalar != 0 && "Division by zero");

    return ((*this) * (1.0/scalar));
}


/********************************************************************************
 * Add a matrix to this matrix.                                                 *
 *******************************************************************************/
template<class Real>
Matrix4<Real>& Matrix4<Real>::operator+=(const Matrix4<Real>& mat)
{
    for(int i = 0; i < 16; i++)
        m_data[i] += mat[i];
    return *this;
}


/********************************************************************************
 * Subtract a matrix from this matrix.                                          *
 *******************************************************************************/
template<class Real>
Matrix4<Real>& Matrix4<Real>::operator-=(const Matrix4<Real>& mat)
{
    for(int i = 0; i < 16; i++)
        m_data[i] -= mat[i];
    return *this;
}


/********************************************************************************
 * Multiply this matrix with a scalar.                                          *
 *******************************************************************************/
template<class Real>
Matrix4<Real>& Matrix4<Real>::operator*=(const Real& scalar)
{
    for(int i = 0; i < 16; i++)
        m_data[i] *= scalar;
    return *this;
}


/********************************************************************************
 * Divide this matrix with a scalar.                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real>& Matrix4<Real>::operator/=(const Real& scalar)
{
    assert(scalar != 0.0 && "Division by zero");

    Real tmp = 1.0/scalar;

    for(int i = 0; i < 16; i++)
        m_data[i] *= tmp;
    return *this;
}


/********************************************************************************
 * Dot multiply two matrices.                                                   *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::dotprod(const Matrix4<Real>& mat) const
{
    Matrix4<Real> tmp((*this));

    for(int i = 0; i < 16; i++)
        tmp[i] *= mat[i];

    return tmp;
}


/********************************************************************************
 * Dot multiply a matrix to this matrix.                                        *
 *******************************************************************************/
template<class Real>
Matrix4<Real>& Matrix4<Real>::operator*=(const Matrix4<Real>& mat)
{
    for(int i = 0; i < 16; i++)
        m_data[i] *= mat[i];
}


/********************************************************************************
 * Get the absolute value of all the elements in the matrix.                    *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::abs() const
{
    Matrix4<Real> tmp;

    for(int i = 0; i < 16; i++)
        tmp[i] = Math<Real>::Abs(m_data[i]);

    return tmp;
}


/********************************************************************************
 * Get the determinant of the matrix.                                           *
 *******************************************************************************/
template<class Real>
Real Matrix4<Real>::det() const
{
    return m_data[0]*(m_data[5] * (m_data[10]*m_data[15] - m_data[11]*m_data[14])
                - m_data[6] * (m_data[9]*m_data[15] - m_data[11]*m_data[13])
                + m_data[7] * (m_data[9]*m_data[14] - m_data[10]*m_data[13]))
        - m_data[1]*(m_data[4] * (m_data[10]*m_data[15] - m_data[11]*m_data[14])
                - m_data[6] * (m_data[8]*m_data[15] - m_data[11]*m_data[12])
                + m_data[7] * (m_data[8]*m_data[14] - m_data[10]*m_data[12]))
        + m_data[2]*(m_data[4] * (m_data[9]*m_data[15] - m_data[11]*m_data[13])
                - m_data[5] * (m_data[8]*m_data[15] - m_data[11]*m_data[12])
                + m_data[7] * (m_data[8]*m_data[13] - m_data[9]*m_data[12]))
        - m_data[3]*(m_data[4] * (m_data[9]*m_data[14] - m_data[10]*m_data[13])
                - m_data[5] * (m_data[8]*m_data[14] - m_data[10]*m_data[12])
                + m_data[6] * (m_data[8]*m_data[13] - m_data[9]*m_data[12]));
}


/********************************************************************************
 * Find the transpose of the matrix.                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::transpose() const
{
    Matrix4<Real> tmp;

    for(int row = 0; row < 4; row++) {
        for(int col = 0; col < 4; col++) {
            tmp[row*4 + col] = m_data[col*4 + row];
        }
    }
    
    return tmp;
}


/********************************************************************************
 * Find the cofactor matrix of this matrix.                                     *
 * TODO: Simplify this implementation.
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::cofactor() const
{
    Matrix4<Real> cofact;
    Matrix3<Real> determ[16];

    determ[0] = Matrix3<Real>(m_data[5], m_data[6], m_data[7],
            m_data[9], m_data[10], m_data[11],
            m_data[13], m_data[14], m_data[15]);
    determ[1] = Matrix3<Real>(m_data[4], m_data[6], m_data[7],
            m_data[8], m_data[10], m_data[11],
            m_data[12], m_data[14], m_data[15]);
    determ[2] = Matrix3<Real>(m_data[4], m_data[5], m_data[7],
            m_data[8], m_data[9], m_data[11],
            m_data[12], m_data[13], m_data[15]);
    determ[3] = Matrix3<Real>(m_data[4], m_data[5], m_data[6],
            m_data[8], m_data[9], m_data[10],
            m_data[12], m_data[13], m_data[14]);

    determ[4] = Matrix3<Real>(m_data[1], m_data[2], m_data[3],
            m_data[9], m_data[10], m_data[11],
            m_data[13], m_data[14], m_data[15]);
    determ[5] = Matrix3<Real>(m_data[0], m_data[2], m_data[3],
            m_data[8], m_data[10], m_data[11],
            m_data[12], m_data[14], m_data[15]);
    determ[6] = Matrix3<Real>(m_data[0], m_data[1], m_data[3],
            m_data[8], m_data[9], m_data[11],
            m_data[12], m_data[13], m_data[15]);
    determ[7] = Matrix3<Real>(m_data[0], m_data[1], m_data[2],
            m_data[8], m_data[9], m_data[10],
            m_data[12], m_data[13], m_data[14]);

    determ[8] = Matrix3<Real>(m_data[1], m_data[2], m_data[3],
            m_data[5], m_data[6], m_data[7],
            m_data[13], m_data[14], m_data[15]);
    determ[9] = Matrix3<Real>(m_data[0], m_data[2], m_data[3],
            m_data[4], m_data[6], m_data[7],
            m_data[12], m_data[14], m_data[15]);
    determ[10] = Matrix3<Real>(m_data[0], m_data[1], m_data[3],
            m_data[4], m_data[5], m_data[7],
            m_data[12], m_data[13], m_data[15]);
    determ[11] = Matrix3<Real>(m_data[0], m_data[1], m_data[2],
            m_data[4], m_data[5], m_data[6],
            m_data[12], m_data[13], m_data[14]);

    determ[12] = Matrix3<Real>(m_data[1], m_data[2], m_data[3],
            m_data[5], m_data[6], m_data[7],
            m_data[9], m_data[10], m_data[11]);
    determ[13] = Matrix3<Real>(m_data[0], m_data[2], m_data[3],
            m_data[4], m_data[6], m_data[7],
            m_data[8], m_data[10], m_data[11]);
    determ[14] = Matrix3<Real>(m_data[0], m_data[1], m_data[3],
            m_data[4], m_data[5], m_data[7],
            m_data[8], m_data[9], m_data[11]);
    determ[15] = Matrix3<Real>(m_data[0], m_data[1], m_data[2],
            m_data[4], m_data[5], m_data[6],
            m_data[8], m_data[9], m_data[10]);

    for(int i = 0; i < 16; i++)
        cofact[i] = determ[i].det();

    Matrix4<Real> tmp = ONES;
    tmp[1] = -1;
    tmp[3] = -1;
    tmp[4] = -1;
    tmp[6] = -1;
    tmp[9] = -1;
    tmp[11] = -1;
    tmp[12] = -1;
    tmp[14] = -1;

    return (cofact.dotprod(tmp));
}


/********************************************************************************
 * Find the inverse of the matrix.                                              *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::inverse() const
{
    assert(this->det() != 0 && "Singular matrix");

    Matrix4<Real> adjoint = (this->cofactor()).transpose();

    return adjoint / (this->det());
}


/********************************************************************************
 * Get the trace of the matrix.                                                 *
 *******************************************************************************/
template<class Real>
Real Matrix4<Real>::trace() const
{
    return m_data[0] + m_data[5] + m_data[10] + m_data[15];
}


/********************************************************************************
 * Check for equality.                                                          *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator==(const Matrix4<Real>& mat) const
{
    return compare(mat) == 0;
}


/********************************************************************************
 * Check for inequality.                                                        *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator!=(const Matrix4<Real>& mat) const
{
    return compare(mat) != 0;
}


/********************************************************************************
 * Check if this matrix is larger-then-or-equal-to another matrix.              *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator>=(const Matrix4<Real>& mat) const
{
    return compare(mat) >= 0;
}


/********************************************************************************
 * Check if this matrix is larger then another matrix.                          *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator>(const Matrix4<Real>& mat) const
{
    return compare(mat) > 0;
}


/********************************************************************************
 * Check if this matrix is less-then-or-equal-to another matrix.                *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator<=(const Matrix4<Real>& mat) const
{
    return compare(mat) <= 0;
}


/********************************************************************************
 * Check if this matrix is less then another matrix.                            *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator<(const Matrix4<Real>& mat) const
{
    return compare(mat) < 0;
}


/********************************************************************************
 * Makes it possible to write scalar*matrix.                                    *
 *******************************************************************************/
template<class Real>
Matrix4<Real> operator*(const Real scalar, const Matrix4<Real>& mat)
{
    return mat * scalar;
}


/********************************************************************************
 * Compare two matrices.                                                        *
 *******************************************************************************/
template<class Real>
int Matrix4<Real>::compare(const Matrix4<Real>& mat) const
{
    for(int i = 0; i < 16; i++) {
        if(Math<Real>::Abs(m_data[i] - mat[i]) >= Math<Real>::EPSILON) {
            if(m_data[i] < mat[i])
                return -1;
            return 1;
        }
    }

    return 0;
}


#ifdef DEBUG
/********************************************************************************
 * Print the matrix.                                                            *
 *******************************************************************************/
template<class Real>
void Matrix4<Real>::print() const
{
    printf("\n");
    for(int row = 0; row < 4; row++) {
        printf("|");
        for(int col = 0; col < 4; col++) {
            printf("%8.4f", m_data[row*4 + col]);
        }
        printf("|\n");
    }
}
#endif

    } //namespace Math
} //namespace Pandora
#endif //PANDORAMATRIX4_H
