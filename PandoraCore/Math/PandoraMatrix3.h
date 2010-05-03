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

#ifndef PANDORAMATRIX3_H
#define PANDORAMATRIX3_H

#include <assert.h>
#include <stddef.h>
#include <string.h>

#include "PandoraMath.h"
#include "PandoraMatrix2.h"
#include "PandoraVector3.h"

namespace Pandora 
{
    namespace Math
    {
        /**
         *  The matrix class. The matrix is stored in the OpenGL way, that is
         *  in row-wise order.
         *
         *  |0 1 2|
         *  |3 4 5|
         *  |6 7 8|
         */
        template<class Real>
        class Matrix3
        {
            public:
                /**
                 *  Default constructor. Makes the matrix. Takes 9 optional
                 *  arguments. If none is given, it makes the identity matrix.
                 *  \param
                 *      a0 - The (0,0) element.
                 *  \param
                 *      a1 - The (0,1) element.
                 *  \param
                 *      a2 - The (0,2) element.
                 *  \param
                 *      a3 - The (1,0) element.
                 *  \param
                 *      a4 - The (1,1) element.
                 *  \param
                 *      a5 - The (1,2) element.
                 *  \param
                 *      a6 - The (2,0) element.
                 *  \param
                 *      a7 - The (2,1) element.
                 *  \param
                 *      a8 - The (2,2) element.
                 */
                Matrix3(Real a0 = 1.0, Real a1 = 0.0, Real a2 = 0.0,
                        Real a3 = 0.0, Real a4 = 1.0, Real a5 = 0.0, 
                        Real a6 = 0.0, Real a7 = 0.0, Real a8 = 1.0);

                /**
                 *  Construct a rotation matrix which rotates rad radians
                 *  around a given axis.
                 *  \param
                 *      rad - The number of radians to rotate.
                 *  \param
                 *      r - The axis to rotate around.
                 */
                Matrix3(Real rad, const Vector3& r);

                /**
                 *  Construct a scale matrix.
                 *  \param
                 *      x_scale - The number to scale with in x-direction.
                 *  \param
                 *      y_scale - The number to scale with in y-direction.
                 *  \param
                 *      z_scale - The number to scale with in z-direction.
                 */
                Matrix3(Real x_scale, Real y_scale, Real z_scale);

                /**
                 *  Initialize the matrix with an array.
                 *  \param
                 *      array - An array of size 9 which is used to initialize 
                 *              the array.
                 */
                Matrix3(Real array[9]);

                /**
                 *  Copy constructor.
                 *  \param
                 *      mat - The 3x3 matrix to copy.
                 */
                Matrix3(Matrix3& mat);

                /**
                 *  Copy constructor. Takes a 2x2 matrix and adds 0 everywhere
                 *  except in the last index, where we put a 1.
                 *  \param
                 *      mat - The 2x2 matrix to copy.
                 */
                Matrix3(Matrix2& mat);

                /**
                 *  Destructor. Does nothing.
                 */
                ~Matrix3();

                /**
                 *  Implicit conversion to array.
                 *  \return
                 *      The matrix as an array.
                 */
                operator Real *();

                /**
                 *  Implicit conversion to constant array.
                 *  \return
                 *      The matrix as an array.
                 */
                operator const Real *() const;

                /**
                 *  Get reference to element number i.
                 *  \param
                 *      i - The index to get the element from.
                 *  \return
                 *      Element number i.
                 */
                Real& operator[](const ptrdiff_t i);

                /**
                 *  Get the value of element i.
                 *  \param
                 *      i - The index to get the element from.
                 *  \return
                 *      Value of element number i.
                 */
                const Real operator[](const ptrdiff_t i) const;

                /**
                 *  Get element in (row,col)
                 *  \param
                 *      row - The row to look in.
                 *  \param
                 *      col - The column to look in.
                 *  \return
                 *      Element number row*3+col.
                 */
                Real& operator()(const int row, const int col);

                /**
                 *  Get the value of element in (row,col)
                 *  \param
                 *      row - The row to look in.
                 *  \param
                 *      col - The column to look in.
                 *  \return
                 *      Element number row*3+col;
                 */
                const Real operator()(const int row, const int col) const;

                /**
                 *  Set the row given to the vector given.
                 *  \param
                 *      row - The row to change.
                 *  \param
                 *      vec - The vector to copy from.
                 */
                void setRow(const int row, const Vector3& vec);

                /**
                 *  Get row given as a vector.
                 *  \param
                 *      row - The row we want.
                 *  \return
                 *      Row number row as a vector.
                 */
                Vector3 getRow(const int row) const;

                /**
                 *  Set the column given to the vector given.
                 *  \param
                 *      col - The column to switch.
                 *  \param
                 *      vec - The vector to insert.
                 */
                void setColumn(const int row, const Vector3& vec);

                /**
                 *  Get the column given as a vector.
                 *  \param
                 *      col - The column we want.
                 *  \return
                 *      Column number col as a vector.
                 */
                Vector3 getColumn(const int row) const;

                /**
                 *  Matrix assignment.
                 *  \param
                 *      mat - The matrix to copy.
                 */
                void operator=(const Matrix3& mat);

                /**
                 *  Negate the matrix.
                 *  \return
                 *      This matrix negated.
                 */
                Matrix3 operator-() const;

                /**
                 *  Add two matrices.
                 *  \param
                 *      mat - The matrix to add to this matrix.
                 *  \return
                 *      A matrix which is this matrix added with mat.
                 */
                Matrix3 operator+(const Matrix3& mat) const;

                /**
                 *  Subtract two matrices.
                 *  \param
                 *      mat - The matrix to subtract with.
                 *  \return
                 *      A matrix which is this matrix subtracted with mat.
                 */
                Matrix3 operator-(const Matrix3& mat) const;

                /**
                 *  multiply two matrices.
                 *  \param
                 *      mat - The matrix to multiply with.
                 *  \return
                 *      A matrix which is this matrix multiplied with another.
                 */
                Matrix3 operator*(const Matrix3& mat) const;

                /**
                 *  Multiply this matrix with a vector.
                 *  \param
                 *      vec - The vector to multiply with.
                 *  \return
                 *      A vector which is this matrix multiplied with a vector.
                 */
                Vector3 operator*(const Vector3& vec) const;

                /**
                 *  Multiply this matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply the vector with.
                 *  \return
                 *      A matrix which is this matrix multiplied with a scalar.
                 */
                Matrix3 operator*(const Real scalar) const;

                /**
                 *  Divide this matrix with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      A matrix which is this matrix divided with a scalar.
                 */
                Matrix3 operator/(const Real scalar) const;

                /**
                 *  Add a matrix to this matrix.
                 *  \param
                 *      mat - The matrix to add to this matrix.
                 */
                void operator+=(const Matrix3& mat);

                /**
                 *  Subtract a matrix from this matrix.
                 *  \param
                 *      mat - The matrix to subtract with.
                 */
                void operator-=(const Matrix3& mat);

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
                 *  Get the absolute value of this matrix. That is, the
                 *  absolute value of all the elements of the matrix.
                 *  \return
                 *      A matrix which is the absolute value of all the 
                 *      elements.
                 */
                Matrix3 abs() const;

                /**
                 *  Get the determinant of the matrix.
                 *  \return
                 *      The determinant of the matrix.
                 */
                Real det() const;

                /**
                 *  Get the transpose of this matrix.
                 *  \return
                 *      The transpose of this matrix.
                 */
                Matrix3 transpose() const;

                /**
                 *  Get the inverse of this matrix.
                 *  \return
                 *      The inverse of this matrix.
                 */
                Matrix3 inverse() const;

                /**
                 *  Check if this matrix is equal to another. All elements
                 *  have to be equal.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if all elements are equal. False otherwise.
                 */
                bool operator==(const Matrix3& mat) const;

                /**
                 *  Check if this matrix is not equal to another.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      False if all elements are equal. True otherwise.
                 */
                bool operator!=(const Matrix3& mat) const;

                /**
                 *  Check if this matrix is larger then or equal to another.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if all elements are larger then or equal, false
                 *      otherwise.
                 */
                bool operator>=(const Matrix3& mat) const;

                /**
                 *  Check if this matrix is larger then another.
                 *  \param
                 *      mat -  The matrix to compare to.
                 *  \return
                 *      True if all elements are larger, false otherwise.
                 */
                bool operator>(const Matrix3& mat) const;

                /**
                 *  Check if this matrix is less then or equal to another.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if all elements are less then or equal. False
                 *      otherwise.
                 */
                bool operator<=(const Matrix3& mat) const;

                /**
                 *  Check if this matrix is less then another.
                 *  \param
                 *      mat - The matrix to compare to.
                 *  \return
                 *      True if all elements are less, false otherwise.
                 */
                bool operator<(const Matrix3& mat) const;

#ifdef DEBUG
#include<stdio.h>
                /**
                 *  Print out the matrix. Only available in DEBUG mode.
                 */
                void print() const;
#endif

                static const Matrix3 ZERO;
                static const Matrix3 IDENTITY;
                static const Matrix3 ONES;
            protected:
                Real m_data[9];
        };
    }
}
#endif
