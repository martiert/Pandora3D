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
                 *  Makes a matrix which rotates rad radians around given axis.
                 *  \param
                 *      rad - The number of radians to rotate.
                 *  \param
                 *      r - The axis to rotate around.    
                 */
                Matrix4(const Real rad, const Vector4<Real>& r);

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
                Matrix4(const Matrix3& mat);

                /**
                 *  Destructor, does nothing.
                 */
                ~Matrix4();

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
                const operator Real *() const;

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
                Vector4<Real> getRow(const int row);

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
                Vector4<Real> getColumn(const int col);

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
                 */
                Matrix4 operator=(const Matrix4 mat);

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
                 */
                Matrix4 operator/(const Real& scalar) const;

                /**
                 *  Add a matrix to this matrix.
                 *  \param
                 *      mat - The matrix to add with.
                 */
                Matrix4 operator+=(const Matrix4& mat);

                /**
                 *  Subtract a matrix from this matrix.
                 *  \param
                 *      mat - The matrix to subtract with.
                 */
                Matrix4 operator-=(const Matrix4& mat);

                /**
                 *  Multiply this matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 */
                Matrix4 operator*=(const Real& scalar);

                /**
                 *  Divide this matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 */
                Matrix4 operator/=(const Real& scalar);


                /**
                 *  Dot multiply this matrix with another.
                 *  \param
                 *      mat - The matrix to dot multiply with.
                 *  \return
                 *      This matrix dot-multiplied with another.
                 */
                Matrix4 dotprod() const;

                /**
                 *  Dot multiply a matrix to this matrix.
                 *  \param
                 *      mat - The matrix to dot multiply with.
                 */
                Matrix4 operator*=(const Matrix4& mat);

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
                 *      True if all elements are larger-then-or-equal-to the
                 *      corresponding elements in mat. False otherwise.
                 */
                bool operator>=(const Matrix4& mat) const;

                /**
                 *  Check if this matrix is larger-then another.
                 *  \param
                 *      mat - The matrix to compare with.
                 *  \return
                 *      True if all elements are larger-then the corresponding
                 *      elements in mat. False otherwise.
                 */
                bool operator>(const Matrix4& mat) const;

                /**
                 *  Check if this matrix is less-then-or-equal-to another 
                 *  matrix.
                 *  \param
                 *      mat - The matrix to compare with.
                 *  \return
                 *      True if all elements is less-then-or-equal-to the
                 *      corresponding elements in mat. False otherwise.
                 */
                bool operator<=(const Matrix4& mat) const;

                /**
                 *  Check if this matrix is less-then another matrix.
                 *  \param
                 *      mat - The matrix to compare with.
                 *  \return
                 *      True if all elements is less-then the corresponding
                 *      elements in mat. False otherwise.
                 */
                bool operator<(const Matrix4& mat) const;

#ifdef DEBUG
                /**
                 *  Print out the matrix. Only available in DEBUG mode.
                 */
                void print() const;
#endif
                static const Matrix4 ZERO;
                static const Matrix4 IDENTITY;
                static const Matrix4 ONES;
            protected:
                Real m_data[16];
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

#include "PandoraMatrix4.inl"

    }
}
#endif
