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

namespace Pandora
{
    namespace Math
    {
        /**
         * A mathematical 2D vector class.
         */
        template<class Real>
        class Vec2
        {
            public:
                /**
                 * Default constructor. Sets the elements.
                 * \param
                 *      x - Element one. Defaults to one.
                 *  \param
                 *      y - Element two. Defaults to zero.
                 */
                Vec2(const Real& x = 1.0, const Real& y = 0.0);

                /**
                 * Copy constructor.
                 * \param
                 *      vec - The vector to copy.
                 */
                Vec2(Vec2& vec);

                /**
                 * Copy constructor for arrays.
                 * \param
                 *      vec - The array to copy.
                 *  \note
                 *      The array must be of size at least two. Behaviour if
                 *      size is less then two is dependent of the compiler.
                 *      If size is larger then two, only the two first elements
                 *      will be used.
                 */
                Vec2(Real *vec);

                /** Destructor */
                ~Vec2();

                /**
                 * Copy a vector to this vector.
                 * \param
                 *      vec - The vector to copy.
                 */
                void operator=(Vec2& vec);

                /**
                 * Copy an array to this vector.
                 * \param
                 *      vec - The array to copy.
                 * \note
                 *      The array must be of size at least two. Behaviour if
                 *      size is less then two is dependent of the compiler.
                 *      If size is larger then two, only the two first elements
                 *      will be used.
                 */
                void operator=(Real *vec);

                /**
                 *  Access operator. Get element number i from the vector.
                 *  \param
                 *      i - The index to return.
                 *  \return
                 *      Element number i.
                 */
                Real& operator[](const unsigned int& i);

                /**
                 *  Get the vector as a c-pointer.
                 *  \return
                 *      The vector as a c-pointer.
                 */
                operator Real *();

                /**
                 * Adds two vectors.
                 * \param
                 *      vec - The vector to add to this vector.
                 *  \return
                 *      This vector added with vec.
                 */
                Vec2 operator+(const Vec2& vec) const;

                /**
                 * Subtract two vectors.
                 * \param
                 *      vec - The vector to subtract from this vector.
                 *  \return
                 *      this vector subtracted with vec.
                 */
                Vec2 operator-(const Vec2& vec) const;

                /**
                 * Multiply two vectors.
                 * \param
                 *      vec - The vector to multiply with.
                 *  \return
                 *      The two vectors multiplied. A scalar.
                 */
                Real operator*(const Vec2& vec) const;

                /**
                 * Multiply this vector with a scalar.
                 * \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      A vector where each of it's elements is this vectors
                 *      elements multiplied with the scalar.
                 */
                Vec2 operator*(const Real& scalar) const;

                /**
                 * Divide this vector with a scalar.
                 * \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      A vector where each of it's elements is this vectors
                 *      elements divided with the scalar.
                 *  \note
                 *      The scalar can not be zero.
                 */
                Vec2 operator/(const Real& scalar) const;

                /**
                 * Dot multiply this vector with another.
                 * \param
                 *      vec - The vector to multiply with.
                 * \return
                 *      A new vector which components is the components from
                 *      this vector multiplied with vec.
                 */
                Vec2 dot(const Vec2& vec) const;

                /**
                 *  Add a vector to this vector.
                 *  \param
                 *      vec - The vector to add to this vector.
                 */
                void operator+=(const Vec2& vec);

                /**
                 *  Subtract a vector from this vector.
                 *  \param
                 *      vec - The vector to subtract with.
                 */
                void operator-=(const Vec2& vec);

                /**
                 *  Multiply this vector with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 */
                void operator*=(const Real& scalar);

                /**
                 *  Multiply each component with the corresponding component of
                 *  vec.
                 *  \param
                 *      vec - The vector to multiply with.
                 */
                void operator*=(const Vec2& vec);

                /**
                 *  Checks if two vectors are equal.
                 *  \param
                 *      vec - The vector to compare with.
                 *  \return
                 *      True if all the components are equal. False otherwise.
                 */
                bool operator==(const Vec2& vec) const;

                /**
                 * Checks if this vector is different from another.
                 * \param
                 *      vec - The vector to compare to.
                 * \return
                 *      False if all the components are equal. False otherwise.
                 */
                bool operator!=(const Vec2& vec) const;

                /**
                 *  Checks if this vector is larger then another.
                 *  \param
                 *      vec - The vector to compare with.
                 *  \return
                 *      True if all the components of this vector is larger
                 *      then the corresponding components of vec.
                 */
                bool operator>(const Vec2& vec) const;

                /**
                 *  Checks if this vector is larger then or equal to another 
                 *  vector.
                 *  \param
                 *      vec - The vector to compare with.
                 * \return
                 *      True if all the components of this vector is larger 
                 *      then or equal to the corresponding component of vec.
                 */
                bool operator>=(const Vec2& vec) const;

                /**
                 *  Checks if this vector is smaller then another.
                 *  \param
                 *      vec - The vector to compare with.
                 *  \return
                 *      True if all the components of this vector is smaller
                 *      then the corresponding component of vec.
                 */
                bool operator<(const Vec2& vec) const;

                /**
                 *  Checks if this vector is smaller then or equal to another.
                 *  \param
                 *      vec - The vector to compare with.
                 *  \return
                 *      True if all the components of this vector is smaller
                 *      then or equal to the corresponding component of vec.
                 */
                bool operator<=(const Vec2& vec) const;


                /**
                 *  Dot multiply two vector.
                 *  \param
                 *      vec - The vector to dot multiply with.
                 *  \return
                 *      The two vectors dot multiplied.
                 */
                Vec2 dotprod(const Vec2& vec) const;

                /**
                 * Find the length of the vector.
                 * \return
                 *      The length of the vector.
                 */
                Real length() const;

                /**
                 * Find the squared length of the vector.
                 * \return
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
