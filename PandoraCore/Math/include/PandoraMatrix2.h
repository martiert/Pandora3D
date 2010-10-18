/*
--------------------------------------------------------------------------------
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
--------------------------------------------------------------------------------
*/

#ifndef PANDORAMATRIX2_H
#define PANDORAMATRIX2_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "PandoraMath.h"
#include "PandoraVector2.h"

namespace Pandora
{
    namespace Math
    {
        /**
         *  A 2x2 Matrix class. Keeps the data in row vise order. Like:
         *
         *  |0 1|
         *  |2 3|
         */
        template<class Real>
        class Matrix2
        {
            public:
                /**
                 *  Default constructor. Takes no arguments and makes an
                 *  undefined matrix.
                 */
                Matrix2();

                /**
                 *  Constructor. Takes four arguments.
                 *  \param
                 *      a - Element in row one, column one.
                 *  \param
                 *      b - Element in row one, column two.
                 *  \param
                 *      c - Element in row two, column one.
                 *  \param
                 *      d - Element in row two, column two.
                 */
                Matrix2(const Real& a, const Real& b, 
                        const Real& c, const Real& d);

                /**
                 *  Constructor. Copies an array to this vector.
                 *  \param
                 *      array - The array we take values from.
                 */
                Matrix2(const Real array[4]);

                /**
                 *  Copy a matrix to this matrix.
                 *  \param
                 *      mat - The matrix to copy from
                 */
                Matrix2(const Matrix2& mat);

                /**
                 *  Implicit conversion.
                 *  \return
                 *      The matrix as an array.
                 */
                operator Real *();

                /**
                 *  Implicit conversion.
                 *  \return
                 *      The matrix as a constant array.
                 */
                operator const Real *() const;

                /**
                 *  Get index number i.
                 *  \param
                 *      i - The index we are looking into.
                 *  \return
                 *      The element in index i.
                 */
                Real& operator[](const ptrdiff_t i);

                /**
                 *  Get value in index number i.
                 *  \param
                 *      i - The index we are looking into.
                 *  \return
                 *      Value of the element in index i.
                 */
                const Real operator[](const ptrdiff_t i) const;

                /**
                 *  Get element from (row,col).
                 *  \param
                 *      row - The row we are searching for.
                 *  \param
                 *      col - The column we are searching for.
                 *  \return
                 *      The element in (row,col)
                 */
                Real& operator()(const int row, const int col);

                /**
                 *  Get value in element (row,col).
                 *  \param
                 *      row - The row we are searching for.
                 *  \param
                 *      col - The column we are searching for.
                 *  \return
                 *      The value in element (row,col).
                 */
                const Real operator()(const int row, const int col) const;

                /**
                 *  Set a row in our matrix from a vector.
                 *  \param
                 *      row - The row to change.
                 *  \param  
                 *      vec - The vector to change it with.
                 */
                void setRow(const int row, const Vector2<Real>& vec);

                /**
                 *  Get a row from our matrix as a vector.
                 *  \param
                 *      row - The row we want.
                 *  \return
                 *      row number row as a vector.
                 */
                Vector2<Real> getRow(const int row) const;

                /**
                 *  Set a column in our matrix from a vector.
                 *  \param
                 *      col - The column to change.
                 *  \param
                 *      vec - The vector to change it with.
                 */
                void setColumn(const int col, const Vector2<Real>& vec);

                /**
                 *  Get a column from out matrix.
                 *  \param
                 *      col - The colum we want.
                 *  \return
                 *      Columns number col as a vector.
                 */
                Vector2<Real> getColumn(const int col) const; 

                /**
                 *  Assignment. Matrix to matrix.
                 *  \param
                 *      matrix - The matrix to assign it to.
                 *  \return
                 *      This matrix.
                 */
                Matrix2& operator=(const Matrix2& matrix);

                /**
                 *  Negate this matrix.
                 *  \return
                 *      This matrix negated.
                 */
                Matrix2 operator-() const;

                /**
                 *  Add two matrices.
                 *  \param
                 *      matrix - The matrix to add with.
                 *  \return
                 *      This matrix added with another.
                 */
                Matrix2 operator+(const Matrix2& matrix) const;

                /**
                 *  Subtract two matrices.
                 *  \param
                 *      matrix - The matrix to subtract with.
                 *  \return
                 *      This matrix subtracted by matrix.
                 */
                Matrix2 operator-(const Matrix2& matrix) const;

                /**
                 *  Matrix to matrix multiplication.
                 *  \param
                 *      matrix - The matrix to multiply this matrix with from 
                 *      the right.
                 *  \return
                 *      This matrix multiplied with matrix.
                 */
                Matrix2 operator*(const Matrix2& matrix) const;

                /**
                 *  Multiply a matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      This matrix multiplied with a scalar.
                 */
                Matrix2 operator*(const Real& scalar) const;

                /**
                 *  Divide a matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      The matrix divided with a scalar.
                 *  \note
                 *      Will only check for division by zero in DEBUG mode.
                 */
                Matrix2 operator/(const Real& scalar) const;

                /**
                 *  Add a matrix to this matrix.
                 *  \param
                 *      matrix - The matrix to add with.
                 *  \return
                 *      This matrix.
                 */
                Matrix2& operator+=(const Matrix2& matrix);

                /**
                 *  Subtract a matrix from this matrix.
                 *  \param
                 *      matrix - The matrix to subtract with.
                 *  \return
                 *      This matrix.
                 */
                Matrix2& operator-=(const Matrix2& matrix);

                /**
                 *  Multiply this matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      This matrix.
                 */
                Matrix2& operator*=(const Real& scalar);

                /**
                 *  Dot multiply this matrix with another matrix.
                 *  \param
                 *      mat - The matrix to multiply with.
                 *  \return
                 *      This matrix.
                 */
                Matrix2& operator*=(const Matrix2& mat);

                /**
                 *  Divide this matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      This matrix.
                 *  \note
                 *      Will only check for division by zero in DEBUG mode.
                 */
                Matrix2& operator/=(const Real& scalar);

                /**
                 *  Multiply a matrix with a vector.
                 *  \param
                 *      vec - The vector to multiply with.
                 *  \return
                 *      A matrix multiplied with a scalar.
                 */
                Vector2<Real> operator*(const Vector2<Real>& vec) const;

                /**
                 *  Dot multipiplication.
                 *  \param
                 *      mat - The matrix to dot multiply with.
                 *  \return
                 *      This matrix dot multiplied with another matrix.
                 */
                Matrix2 dot(const Matrix2& mat) const;
    
                /**
                 *  Get the determinant of this matrix.
                 *  \return
                 *      A scalar which is the matrix' determinant.
                 */
                Real det() const;

                /**
                 *  Make a transpose of this matrix.
                 *  \return
                 *      This matrix transposed.
                 */
                Matrix2 transpose() const;

                /**
                 *  Find this matrix inverted.
                 *  \return
                 *      This matrix inverted.
                 */
                Matrix2 inverse() const;

                /**
                 *  Check if this matrix is equal to another matrix. That is,
                 *  all elements have to be equal.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if all elements are equal, false otherwise.
                 */
                bool operator==(const Matrix2& mat) const;

                /**
                 *  Check if two matrices differ.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      False if all elements are equal, true otherwise.
                 */
                bool operator!=(const Matrix2& mat) const;

                /**
                 *  Check if this matrix is larger then or equal to another 
                 *  matrix. That is, all element have to be larger then or 
                 *  equal.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if all elements are equal, or the first element 
                 *      that differ is larger then mat. False otherwise.
                 */
                bool operator>=(const Matrix2& mat) const;

                /**
                 *  Check if this matrix is larger then another matrix. That is
                 *  all elements have to be larger.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if the first element that differ is larger then
                 *      mat. False otherwise.
                 */
                bool operator>(const Matrix2& mat) const;

                /**
                 *  Check if this matrix is smaller then or equal to another
                 *  matrix. That is, all elements have to be smaller then or
                 *  equal.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if all elements are equal, or if the first element
                 *      that differ is smaller then mat. False otherwise.
                 */
                bool operator<=(const Matrix2& mat) const;

                /**
                 *  Check if this matrix is smaller then another matrix. That
                 *  is, all elements have to be smaller.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if the first element that differ is smaller than
                 *      in mat. False otherwise.
                 */
                bool operator<(const Matrix2& mat) const;

                /**
                 *  Extract the angle of rotation from this rotation matrix.
                 *  \return
                 *      The angle we rotate using this rotation matrix.
                 */
                Real toAngle() const;

                /**
                 *  Orthonormalize this matrix.
                 */
                void orthonormalize();

                /**
                 *  Get the trace of the matrix.
                 *  \return
                 *      The trace of the matrix.
                 */
                Real trace() const;

                /**
                 *  Eigenvalue decompose this matrix.
                 *  \param
                 *      lambda - The eigenvalues.
                 *  \param
                 *      v_mat - The eigenvectors in columnwise order.
                 */
                void eigenDecompose(Vector2<Real>& lambda, Matrix2& v_mat) const;

#ifdef DEBUG
                /**
                 *  Print put the matrix. Available only in DEBUG mode.
                 */
                void print() const;
#endif //DEBUG

                static const Matrix2 ZERO;
                static const Matrix2 IDENTITY;
                static const Matrix2 ONES;
            protected:
                Real m_data[4];

                int compare(const Matrix2& mat) const;
        };

        /**
         *  Makes it possible to write
         *  scalar * matrix.
         *  \param
         *      scalar - The scalar to multipy with.
         *  \param
         *      mat - The matrix.
         *  \return
         *      The matrix mat multiplied with the scalar.
         */
        template<class Real>
        Matrix2<Real> operator*(const Real scalar, const Matrix2<Real>& mat);

        /**
         *  Typedefs.
         */
        typedef Matrix2<float>          Mat2f;
        typedef Matrix2<double>         Mat2d;
        typedef Matrix2<int>            Mat2i;
        typedef Matrix2<unsigned int>   Mat2u;

/********************************************************************************
 * Constructors.                                                                *
 *******************************************************************************/
template<class Real>
Matrix2<Real>::Matrix2()
{
}


/********************************************************************************
 * Give four numbers to put in the matrix.                                      *
 *******************************************************************************/ 
template<class Real>
Matrix2<Real>::Matrix2(const Real& a, const Real& b, 
        const Real& c, const Real& d)
{
    m_data[0] = a;
    m_data[1] = b;
    m_data[2] = c;
    m_data[3] = d;
}


/********************************************************************************
 * Give an array to use as the matrix.                                          *
 *******************************************************************************/
template<class Real>
Matrix2<Real>::Matrix2(const Real array[4])

{
    memcpy(m_data, array, 4*sizeof(Real));
}


/********************************************************************************
 * Copy a matrix to this matrix on construction of this matrix.                 *
 *******************************************************************************/
template<class Real>
Matrix2<Real>::Matrix2(const Matrix2<Real>& matrix)
{
    memcpy(m_data, matrix.m_data, 4*sizeof(Real));
}


/********************************************************************************
 * Implicit conversion to array.                                                *
 *******************************************************************************/ 
template<class Real>
Matrix2<Real>::operator Real *()
{
    return &(m_data[0]);
}


/********************************************************************************
 * Implicit conversion to constant array.                                       * 
 *******************************************************************************/ 
template<class Real>
Matrix2<Real>::operator const Real *() const
{
    return &(m_data[0]);
}


/********************************************************************************
 * Get index number i from the matrix.                                          * 
 *******************************************************************************/ 
template<class Real>
Real& Matrix2<Real>::operator[](const ptrdiff_t i)
{
    assert( i < 4 && "Index out of bounds\n");

    return m_data[i];
}


/********************************************************************************
 * Return constant reference to index number i in the matrix.                   * 
 *******************************************************************************/ 
template<class Real>
const Real Matrix2<Real>::operator[](const ptrdiff_t i) const
{
     assert( i < 4 && "Index out of bounds\n");   
     return m_data[i];
}


/********************************************************************************
 * Get element in (row,col) from the matrix.                                    * 
 *******************************************************************************/ 
template<class Real>
Real& Matrix2<Real>::operator()(const int row, const int col)
{
    assert(row < 2 && col < 2 && "Index out of bounds");

    return m_data[row*2 + col];
}


/********************************************************************************
 * Get constant refference to element (row,col) in the matrix.                  * 
 *******************************************************************************/ 
template<class Real>
const Real Matrix2<Real>::operator()(const int row, const int col) const
{
    assert(row < 2 && col < 2 && "Index out of bounds");

    return m_data[row*2 + col];
}


/********************************************************************************
 * Set a row to the given vector.                                               *
 *******************************************************************************/
template<class Real>
void Matrix2<Real>::setRow(const int row, const Vector2<Real>& vec)
{
    assert(row < 2 && "Index out of bounds");

    m_data[row*2] = vec[0];
    m_data[row*2+1] = vec[1];
}


/********************************************************************************
 * Get the row asked for as a vector.                                           *
 *******************************************************************************/
template<class Real>
Vector2<Real> Matrix2<Real>::getRow(const int row) const
{
    assert(row < 2 && "Index out of bounds");

    return Vector2<Real>(m_data[row*2], m_data[row*2 + 1]);
}


/********************************************************************************
 * Set given column to the given vector.                                        *
 *******************************************************************************/
template<class Real>
void Matrix2<Real>::setColumn(const int col, const Vector2<Real>& vec)
{
    assert(col < 2 && "Index out of bounds");

    m_data[col] = vec[0];
    m_data[2+col] = vec[1];
}


/********************************************************************************
 * Get column number col as a vector.                                           *
 *******************************************************************************/
template<class Real>
Vector2<Real> Matrix2<Real>::getColumn(const int col) const
{
    assert(col < 2 && "Index out of bounds");

    return Vector2<Real>(m_data[col], m_data[2+col]);
}


/********************************************************************************
 * Assignment operator.                                                         *
 *******************************************************************************/
template<class Real>
Matrix2<Real>& Matrix2<Real>::operator=(const Matrix2<Real>& matrix)
{
    if(this != &matrix)
        memcpy(m_data, matrix.m_data, 4*sizeof(Real));
    return *this;
}


/********************************************************************************
 * Negation operator.                                                           *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator-() const
{
    return Matrix2<Real>::ZERO - *this;
}


/********************************************************************************
 * Add two matrices.                                                            *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator+(const Matrix2<Real>& matrix) const
{
    return Matrix2<Real>(m_data[0]+matrix[0], m_data[1]+matrix[1], 
            m_data[2]+matrix[2], m_data[3]+matrix[3]);
}


/********************************************************************************
 * Subtract two matrices.                                                       *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator-(const Matrix2<Real>& matrix) const
{
    return Matrix2<Real>(m_data[0]-matrix[0], m_data[1]-matrix[1],
            m_data[2]-matrix[2], m_data[3]-matrix[3]);
}


/********************************************************************************
 * Multiply two matrices.                                                       *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator*(const Matrix2<Real>& matrix) const
{
    return Matrix2<Real>(m_data[0]*matrix[0] + m_data[1]*matrix[2],
            m_data[0]*matrix[1] + m_data[1]*matrix[3],
            m_data[2]*matrix[0] + m_data[3]*matrix[2],
            m_data[2]*matrix[1] + m_data[3]*matrix[3]);
}


/********************************************************************************
 * Multiply a matrix with a scalar.                                             *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator*(const Real& scalar) const
{
    return Matrix2<Real>(m_data[0]*scalar, m_data[1]*scalar,
            m_data[2]*scalar, m_data[3]*scalar);
}


/********************************************************************************
 * Divide a matrix with a scalar.                                               *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator/(const Real& scalar) const
{
    assert(scalar != 0 && "Division by zero");

    Real scale = 1.0/scalar;
    return Matrix2<Real>(m_data[0]*scale, m_data[1]*scale,
            m_data[2]*scale, m_data[3]*scale);
}


/********************************************************************************
 * Add a matrix to this matrix.                                                 *
 *******************************************************************************/
template<class Real>
Matrix2<Real>& Matrix2<Real>::operator+=(const Matrix2<Real>& matrix)
{
    *this = *this + matrix;
    return *this;
}


/********************************************************************************
 * Subtract a matrix from this matrix.                                          *
 *******************************************************************************/
template<class Real>
Matrix2<Real>& Matrix2<Real>::operator-=(const Matrix2<Real>& matrix)
{
    *this = *this - matrix;
    return *this;
}


/********************************************************************************
 * Multiply this matrix with a scalar.                                          *
 *******************************************************************************/
template<class Real>
Matrix2<Real>& Matrix2<Real>::operator*=(const Real& scalar)
{
    *this = *this * scalar;
    return *this;
}


/********************************************************************************
 * Dot multiplication.                                                          *
 *******************************************************************************/
template<class Real>
Matrix2<Real>& Matrix2<Real>::operator*=(const Matrix2<Real>& mat)
{
    m_data[0] *= mat[0]; m_data[1] *= mat[1];
    m_data[2] *= mat[2]; m_data[3] *= mat[3];
    return *this;
}


/********************************************************************************
 * Divide this matrix with a scalar.                                            *
 *******************************************************************************/
template<class Real>
Matrix2<Real>& Matrix2<Real>::operator/=(const Real& scalar)
{
    *this = *this / scalar;
    return *this;
}


/********************************************************************************
 * Multiply this matrix with a vector.                                          *
 *******************************************************************************/
template<class Real>
Vector2<Real> Matrix2<Real>::operator*(const Vector2<Real>& vec) const
{
    return Vector2<Real>(m_data[0]*vec[0] + m_data[1]*vec[1],
            m_data[2]*vec[0] + m_data[3]*vec[1]);
}


/********************************************************************************
 * Dot multiplication.                                                          *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::dot(const Matrix2<Real>& mat) const
{
    return Matrix2<Real>(m_data[0]*mat[0], m_data[1]*mat[1],
            m_data[2]*mat[2], m_data[3]*mat[3]);
}


/********************************************************************************
 * Get the determinant of the matrix.                                           *
 *******************************************************************************/
template<class Real>
Real Matrix2<Real>::det() const
{
    return m_data[0]*m_data[3] - m_data[1]*m_data[2];
}


/********************************************************************************
 * Get the transposed matrix.                                                   *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::transpose() const
{
    return Matrix2<Real>(m_data[0], m_data[2], m_data[1], m_data[3]);
}


/********************************************************************************
 * Get the inverse matrix.                                                      *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::inverse() const
{
    assert(det() != 0.0 && "Singular matrix");

    Real scale = 1.0/det();
    return (Matrix2<Real>(m_data[3], -m_data[1], -m_data[2], m_data[0]) * scale);
}


/********************************************************************************
 * Equality operator.                                                           *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator==(const Matrix2<Real>& mat) const
{
    return compare(mat) == 0;
}


/********************************************************************************
 * Inequality operator.                                                         *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator!=(const Matrix2<Real>& mat) const
{
    return compare(mat) != 0;
}


/********************************************************************************
 * Larger-than-or-equal-to operator.                                            *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator>=(const Matrix2<Real>& mat) const
{
    return compare(mat) >= 0;
}


/********************************************************************************
 * Larger-than operator.                                                        *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator>(const Matrix2<Real>& mat) const
{
    return compare(mat) > 0;
}


/********************************************************************************
 * Smaller-than-or-equal-to operator.                                           *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator<=(const Matrix2<Real>& mat) const
{
    return compare(mat) <= 0;
}


/********************************************************************************
 * Smaller-than operator.                                                       *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator<(const Matrix2<Real>& mat) const
{
    return compare(mat) < 0;
}


/********************************************************************************
 * Extract the angle of rotation.                                               *
 *******************************************************************************/
template<class Real>
Real Matrix2<Real>::toAngle() const
{
    return Math<Real>::Atan2(m_data[2], m_data[3]);
}


/********************************************************************************
 * Orthonormalize the matrix.                                                   *
 *******************************************************************************/
template<class Real>
void Matrix2<Real>::orthonormalize()
{
    Real len = Math<Real>::Sqrt(m_data[0]*m_data[0] + m_data[2]*m_data[2]);
    m_data[0] /= len;
    m_data[2] /= len;

    Real dot = m_data[0]*m_data[1] + m_data[2]*m_data[3];
    m_data[1] -= dot*m_data[0];
    m_data[3] -= dot*m_data[2];

    len = Math<Real>::Sqrt(m_data[1]*m_data[1] + m_data[3]*m_data[3]);
    m_data[1] /= len;
    m_data[3] /= len;
}


/********************************************************************************
 * Eigenvalue decompose the matrix.                                             *
 * Algorithm from http://cds.caltech.edu/~andrea/research/sw/2x2_eigen.html     *
 *******************************************************************************/
template<class Real>
void Matrix2<Real>::eigenDecompose(Vector2<Real>& lambda, Matrix2<Real>& v_mat) 
    const
{
    assert( m_data[0] == m_data[3] && 
            "Mat2::eigenm_data[3]ecompose: Matrix is not symmetric" );

    if(m_data[1]*m_data[2] < Math<Real>::EPSILON ) {
        lambda[0] = m_data[0]; v_mat[0] = 1; v_mat[1] = 0;
        lambda[1] = m_data[3]; v_mat[2] = 0; v_mat[3] = 1;
        return;
    }

    double tr = m_data[0] + m_data[3];
    double det = m_data[0] * m_data[3] - m_data[1] * m_data[2];
    double S = Math<Real>::Sqrt( tr*tr/4 - det );
    lambda[0] = tr/2 + S;
    lambda[1] = tr/2 - S;

    double SS = Math<Real>::Sqrt( Math<Real>::Max((m_data[0]-m_data[3])*(m_data[0]-m_data[3])/4 + m_data[1] * m_data[2], 0.0) );
    if( m_data[0] - m_data[3] < 0 ) {
        v_mat[0] = m_data[2];
        v_mat[1] = - (m_data[0]-m_data[3])/2 + SS;
        v_mat[2] = + (m_data[0]-m_data[3])/2 - SS;
        v_mat[3] = m_data[1];
    } else {
        v_mat[2] = m_data[2];
        v_mat[3] = - (m_data[0]-m_data[3])/2 - SS;
        v_mat[0] = + (m_data[0]-m_data[3])/2 + SS;
        v_mat[1] = m_data[1];
    }

    double n1 = Math<Real>::Sqrt(v_mat[0]*v_mat[0] + v_mat[1]*v_mat[1]);
    v_mat[0] /= n1; v_mat[1] /= n1;
    double n2 = Math<Real>::Sqrt(v_mat[2]*v_mat[2] + v_mat[3]*v_mat[3]);
    v_mat[2] /= n2; v_mat[3] /= n2;
}


/********************************************************************************
 * So we can write Real * Matrix                                                *
 *******************************************************************************/
template<class Real>
Matrix2<Real> operator*(const Real scale, const Matrix2<Real>& mat)
{
    return mat * scale;
}


/********************************************************************************
 * Get the trace of the matrix.                                                 *
 *******************************************************************************/
template<class Real>
Real Matrix2<Real>::trace() const
{
    return m_data[0] + m_data[3];
}


/********************************************************************************
 * Compare two matrices.                                                        *
 *******************************************************************************/
template<class Real>
int Matrix2<Real>::compare(const Matrix2<Real>& mat) const
{
    for(int i = 0; i < 4; i++) {
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
 * Print out the matrix.                                                        *
 *******************************************************************************/
template<class Real>
void Matrix2<Real>::print() const
{
    printf("\n|%8.4f %8.4f|\n|%8.4f %8.4f|\n\n", m_data[0], m_data[1], m_data[2], 
            m_data[3]);
}
#endif

    } //namespace Math
} //namespace Pandora
#endif //PANDORAMATRIX_H
