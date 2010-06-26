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

#ifndef PANDORAVECTOR4_H
#define PANDORAVECTOR4_h

#include <stdio.h>
#include <assert.h>
#include <stddef.h>

#include "PandoraMath.h"

namespace Pandora
{
    namespace Math
    {
        /**
         *  A 4D vector class.
         */
        template<class Real>
        class Vector4
        {
           public:
                /**
                 *  Default constructor. Takes four arguments, if no arguments
                 *  are given we make the identity vector.
                 *  \param
                 *      x - The value of the first parameter.
                 *  \param
                 *      y - The value of the second parameter.
                 *  \param
                 *      z - The value of the third parameter.
                 *  \param
                 *      w - The value of the fourth parameter.
                 */
                Vector4(Real x = (Real) 1.0, Real y = (Real) 0.0, 
                        Real z = (Real) 0.0, Real w = (Real) 0.0);

                /**
                 *  Copy constructor. Copies a vector to this vector.
                 *  \param
                 *      vec - The vector to copy from.
                 */
                Vector4(Vector4& vec);

                /**
                 *  Copy an array to this vector.
                 *  \param
                 *      vec - The array.
                 */
                Vector4(Real vec[4]);

                /**
                 *  Destructor.
                 */
                ~Vector4();

                /**
                 *  Copy a vector to this vector.
                 *  \param
                 *      vec - The vector to copy from.
                 *  \return
                 *      This vector.
                 */
                Vector4 operator=(const Vector4& vec);

                /**
                 *  Get element number i from the vector.
                 *  \param
                 *      i - The index we should find.
                 *  \return
                 *      Element number i.
                 *  \note
                 *      If the index is larger then or equal to four, the 
                 *      program will crash.
                 */
                Real& operator[](const ptrdiff_t i);

                /**
                 *  Get the value of element number i from te vector.
                 *  \param
                 *      i - The index.
                 *  \return
                 *      The value of element number i.
                 *  \note
                 *      If the index is larger then or equal to four, the 
                 *      program will crash.
                 */
                Real operator[](const ptrdiff_t i) const;

                /**
                 *  Get the vector as an array. Implicit conversion.
                 *  \return
                 *      The vector as an array.
                 */
                operator Real *();

                /**
                 *  Get the vector as a constant array. Implicit conversion.
                 *  \return
                 *      The vector as a constant array.
                 */
                operator const Real *() const;

                /**
                 *  Negate a vector.
                 *  \return
                 *      The vector negated.
                 */
                Vector4 operator-() const;

                /**
                 *  Add two vectors.
                 *  \param
                 *      vec - The vector to add to this vector.
                 *  \return
                 *      A new vector which is the addition between this vector
                 *      and vec.
                 */
                Vector4 operator+(const Vector4& vec) const;

                /**
                 *  Subtract two vectors.
                 *  \param  
                 *      vec - The vector to subtract with.
                 *  \return
                 *      A new vector which is this vector subtracted by vec.
                 */
                Vector4 operator-(const Vector4& vec) const;

                /**
                 *  Multiply a vector with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      A new vector which is this vector multiplied by scalar.
                 */
                Vector4 operator*(const Real& scalar) const;

                /**
                 *  Divide a vector with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      A new vector which is this vector divided by scalar.
                 *  \note
                 *      If scalar is zero, the program will crash.
                 */
                Vector4 operator/(const Real& scalar) const;

                /**
                 *  Dot multiply two vectors.
                 *  \param
                 *      vec - The vector to dot multiply with.
                 *  \return
                 *      A scalar which is the two vector dot multiplied.
                 */
                Real operator*(const Vector4& vec) const;

                /**
                 *  Add a vector to this vector.
                 *  \param
                 *      vec - The vector to add to this vector.
                 *  \return
                 *      This vector.
                 */
                Vector4 operator+=(const Vector4& vec);

                /**
                 *  Subtract a vector from this vector.
                 *  \param
                 *      vec - The vector to subtract with.
                 *  \return
                 *      This vector.
                 */
                Vector4 operator-=(const Vector4& vec);

                /**
                 *  Multiply this vector with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      This vector.
                 */
                Vector4 operator*=(const Real& scalar);

                /**
                 *  Divide this vector with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      This vector.
                 *  \note
                 *      The program will crash if the scalar is zero.
                 */
                Vector4 operator/=(const Real& scalar);

                /**
                 *  Check if two vectors are equal.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      True if all of the elements are equal, false otherwise.
                 */
                bool operator==(const Vector4& vec) const;

                /**
                 *  Check if two vectors are different.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      False if all of the elements are equal, true otherwise.
                 */
                bool operator!=(const Vector4& vec) const;

                /**
                 *  Check if this vector is less then another.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      True if all of the elements of this vector is less then
                 *      the corresponding elements of vec, false otherwise.
                 */
                bool operator<(const Vector4& vec) const;

                /**
                 *  Check if this vector is less then or equal to another.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      True if all of the elements of this vector is less then
                 *      or equal to the corresponding elements of vec. False
                 *      otherwise.
                 */
                bool operator<=(const Vector4& vec) const;

                /**
                 *  Check if this vector is larger then another.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      True if all of the elements of this vector is larger
                 *      then the corresponding elements of vec. False 
                 *      otherwise.
                 */
                bool operator>(const Vector4& vec) const;

                /**
                 *  Check if this vector is larger then or equal to another.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      True if all of the elements of this vector is larger
                 *      then or equal to the corresponding elements of vec. 
                 *      False otherwise.
                 */
                bool operator>=(const Vector4& vec) const;

                /**
                 *  Get the length of the vector: Sqrt(x*x+y*y+z*z+w*w).
                 *  \return
                 *      The length of the vector.
                 */
                Real length() const;

                /**
                 *  Get the squared length of the vector.
                 *  \return 
                 *      The squared length of the vector.
                 */
                Real lengthSquared() const;

                /**
                 *  Normalize the vector. No error checking is done.
                 */
                void normalize();

                /**
                 *  Normalize the vector if the length is different from zero.
                 *  \return
                 *      true if the vector is normalized. False otherwise.
                 */
                bool normalizeChecked();

#ifdef DEBUG
                /**
                 * Print the vector. Only available in DEBUG mode.
                 */
                void print() const;
#endif
           public:
                Real x, y, z, w;
        };

        /**
         *  Makes it possible to write scalar*vec.
         *  \param
         *      scalar - The scalar.
         *  \param
         *      vec - The vector.
         *  \return
         *      scalar*vec.
         */
        template<class Real>
        Vector4<Real> operator*(const Real scalar, const Vector4<Real>& vec);

#include "PandoraVector4.inl"

    }
}
#endif
