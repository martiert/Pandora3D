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
#ifndef PANDORAVECTOR2_H
#define PANDORAVECTOR2_H

#include "PandoraMath.h"
#include <assert.h>
#include <stddef.h>

namespace Pandora
{
    namespace Math
    {
        /**
         *  A mathematical 2D vector class.
         */
        template<class Real>
        class Vector2
        {
            public:
                /**
                 *  Default constructor. Sets the elements.
                 *  \param
                 *      x - Element one. Defaults to one.
                 *  \param
                 *      y - Element two. Defaults to zero.
                 */
                Vector2(const Real& x = 1.0, const Real& y = 0.0);

                /**
                 *  Copy constructor.
                 *  \param
                 *      vec - The vector to copy.
                 */
                Vector2(Vector2& vec);

                /**
                 *  Copy constructor for arrays.
                 *  \param
                 *      vec - The array to copy.
                 */
                Vector2(Real vec[2]);

                /** 
                 *  Destructor 
                 */
                ~Vector2();

                /**
                 *  Copy a vector to this vector.
                 *  \param
                 *      vec - The vector to copy.
                 */
                void operator=(Vector2& vec);

                /**
                 *  Copy an array to this vector.
                 *  \param
                 *      vec - The array to copy.
                 */
                void operator=(Real vec[2]);

                /**
                 *  Access operator. Get element number i from the vector.
                 *  \param
                 *      i - The index to return.
                 *  \return
                 *      Element number i.
                 */
                Real& operator[](const ptrdiff_t i);

                /**
                 *  Access operator. Get value of element number i from the 
                 *  vector.
                 *  \param
                 *      i - The index of the element.
                 *  \return
                 *      The value in element number i.
                 */
                Real operator[](const ptrdiff_t i) const;

                /**
                 *  Get the vector as a c-pointer.
                 *  \return
                 *      The vector as a c-pointer.
                 */
                operator Real* ();

                /**
                 *  Get an array of values of the array.
                 *  \return
                 *      The values of the vector.
                 */
                operator const Real* () const;

                /**
                 *  Adds two vectors.
                 *  \param
                 *      vec - The vector to add to this vector.
                 *  \return
                 *      This vector added with vec.
                 */
                Vector2 operator+(const Vector2& vec) const;

                /**
                 *  Subtract two vectors.
                 *  \param
                 *      vec - The vector to subtract from this vector.
                 *  \return
                 *      this vector subtracted with vec.
                 */
                Vector2 operator-(const Vector2& vec) const;
                
                /**
                 *  Multiply this vector with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      A vector where each of it's elements is this vectors
                 *      elements multiplied with the scalar.
                 */
                Vector2 operator*(const Real& scalar) const;

                /**
                 *  Multiply each element from this vector with the 
                 *  corresponding element from the other vector, and adding
                 *  them together.
                 *  \param
                 *      vec - The vector to multiply with.
                 *  \return
                 *      A scalar being the vector-to-vector multiplication of
                 *      this vector and vec.
                 */
                Real operator*(const Vector2& vec) const;

                /**
                 *  Divide this vector with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      A vector where each of it's elements is this vectors
                 *      elements divided with the scalar.
                 *  \note
                 *      The scalar can not be zero.
                 */
                Vector2 operator/(const Real& scalar) const;

                 /**
                 *  Add a vector to this vector.
                 *  \param
                 *      vec - The vector to add to this vector.
                 */
                void operator+=(const Vector2& vec);

                /**
                 *  Subtract a vector from this vector.
                 *  \param
                 *      vec - The vector to subtract with.
                 */
                void operator-=(const Vector2& vec);

                /**
                 *  Multiply this vector with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 */
                void operator*=(const Real& scalar);

                /**
                 *  Divide this vector with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 */
                void operator/=(const Real& scalar);

                /**
                 *  Checks if two vectors are equal.
                 *  \param
                 *      vec - The vector to compare with.
                 *  \return
                 *      True if all the components are equal. False otherwise.
                 */
                bool operator==(const Vector2& vec) const;

                /**
                 *  Checks if this vector is different from another.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      False if all the components are equal. False otherwise.
                 */
                bool operator!=(const Vector2& vec) const;

                /**
                 *  Checks if this vector is larger then another.
                 *  \param
                 *      vec - The vector to compare with.
                 *  \return
                 *      True if all the components of this vector is larger
                 *      then the corresponding components of vec.
                 */
                bool operator>(const Vector2& vec) const;

                /**
                 *  Checks if this vector is larger then or equal to another 
                 *  vector.
                 *  \param
                 *      vec - The vector to compare with.
                 *  \return
                 *      True if all the components of this vector is larger 
                 *      then or equal to the corresponding component of vec.
                 */
                bool operator>=(const Vector2& vec) const;

                /**
                 *  Checks if this vector is smaller then another.
                 *  \param
                 *      vec - The vector to compare with.
                 *  \return
                 *      True if all the components of this vector is smaller
                 *      then the corresponding component of vec.
                 */
                bool operator<(const Vector2& vec) const;

                /**
                 *  Checks if this vector is smaller then or equal to another.
                 *  \param
                 *      vec - The vector to compare with.
                 *  \return
                 *      True if all the components of this vector is smaller
                 *      then or equal to the corresponding component of vec.
                 */
                bool operator<=(const Vector2& vec) const;

                /**
                 *  Negate the vector.
                 *  \return
                 *      The vector negated.
                 */
                Vector2 operator-() const;


                /**
                 *  Dot multiply two vector.
                 *  \param
                 *      vec - The vector to dot multiply with.
                 *  \return
                 *      The two vectors dot multiplied.
                 */
                Vector2 dotprod(const Vector2& vec) const;

                /**
                 * Find the length of the vector.
                 * \return
                 *      The length of the vector.
                 */
                Real length() const;

                /**
                 *  Find the squared length of the vector.
                 *  \return
                 *      The squared length of the vector.
                 */
                Real lengthSquared() const;

                /**
                 *  Normalize the vector. No error checking is done.
                 */
                void normalize();

                /**
                 *  Normalize the vector. Check if possible first (length is 
                 *  not zero).
                 *  \return
                 *      False if the length of the vector is zero, and thus the
                 *      vector is not normalized. True otherwise.
                 */
                bool normalizeChecked();
            public:
                Real x, y;
        };

#include "PandoraVector2.inl"

   }
}
#endif