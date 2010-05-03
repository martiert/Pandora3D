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
                 *  Constructor. Takes four optional elements.
                 *  \param
                 *      a - Element in row one, column one.
                 *  \param
                 *      b - Element in row one, column two.
                 *  \param
                 *      c - Element in row two, column one.
                 *  \param
                 *      d - Element in row two, column two.
                 *  \note
                 *      If no elements are sent to the constructor, the 
                 *      identity matrix is constructed.
                 */
                Matrix2(const Real& a = (Real) 1.0, const Real& b = (Real) 0.0, 
                        const Real& c = (Real) 0.0, const Real& d = (Real) 1.0);

                /**
                 *  Constructor. Copies an array to this vector.
                 *  \param
                 *      array - The array we take values from.
                 */
                Matrix2(Real array[4]);

                /**
                 *  Copy a matrix to this matrix.
                 *  \param
                 *      mat - The matrix to copy from
                 */
                Matrix2(Matrix2& mat);

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
                void setRow(const int row, const Vector2& vec);

                /**
                 *  Get a row from our matrix as a vector.
                 *  \param
                 *      row - The row we want.
                 *  \return
                 *      row number row as a vector.
                 */
                Vector2 getRow(const int row) const;

                /**
                 *  Set a column in our matrix from a vector.
                 *  \param
                 *      col - The column to change.
                 *  \param
                 *      vec - The vector to change it with.
                 */
                void setColumn(const int col, const Vector2& vec);

                /**
                 *  Get a column from out matrix.
                 *  \param
                 *      col - The colum we want.
                 *  \return
                 *      Columns number col as a vector.
                 */
                Vector2 getColumn(const int col) const; 

                /**
                 *  Assignment. Matrix to matrix.
                 *  \param
                 *      matrix - The matrix to assign it to.
                 */
                void operator=(const Matrix2& matrix);

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
                 */
                Matrix2 operator/(const Real& scalar) const;

                /**
                 *  Add a matrix to this matrix.
                 *  \param
                 *      matrix - The matrix to add with.
                 */
                void operator+=(const Matrix2& matrix);

                /**
                 *  Subtract a matrix from this matrix.
                 *  \param
                 *      matrix - The matrix to subtract with.
                 */
                void operator-=(const Matrix2& matrix);

                /**
                 *  Multiply this matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 */
                void operator*=(const Real& scalar);

                /**
                 *  Divide this matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 */
                void operator/=(const Real& scalar);

                /**
                 *  Multiply a matrix with a vector.
                 *  \param
                 *      vec - The vector to multiply with.
                 *  \return
                 *      A matrix multiplied with a scalar.
                 */
                Vector2 operator*(const Vector2& vec) const;
    
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
                 *      True if all elements are larger then or equal. False
                 *      otherwise.
                 */
                bool operator>=(const Matrix2& mat) const;

                /**
                 *  Check if this matrix is larger then another matrix. That is
                 *  all elements have to be larger.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if all elements are larger, false otherwise.
                 */
                bool operator>(const Matrix2& mat) const;

                /**
                 *  Check if this matrix is smaller then or equal to another
                 *  matrix. That is, all elements have to be smaller then or
                 *  equal.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if all elements are smaller then or equal. False
                 *      otherwise.
                 */
                bool operator<=(const Matrix2& mat) const;

                /**
                 *  Check if this matrix is smaller then another matrix. That
                 *  is, all elements have to be smaller.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if all elements are smaller, false otherwise.
                 */
                bool operator<(const Matrix2& mat) const;

#ifdef DEBUG
#include<stdio.h>
                /**
                 *  Print put the matrix. Available only in DEBUG mode.
                 */
                void print() const;
#endif

                static const Matrix2 ZERO;
                static const Matrix2 IDENTITY
            protected:
                Real m_data[4];
        };
    }
}
