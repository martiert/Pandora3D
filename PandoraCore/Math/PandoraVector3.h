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

#ifndef PANDORAVECTOR3_H
#define PANDORAVECTOR3_H

#include "PandoraMath.h"
#include <assert.h>
#include <stddef.h>

namespace Pandora
{
    namespace Math
    {
        /**
         *  A mathematical 3D vector class.
         */
        template<class Real>
        class Vector3
        {
            public:
                /**
                 *  Default constructor. Sets the elements.
                 *  \param
                 *      x - The first value of the vector.
                 *  \param
                 *      y - The second value of the vector.
                 *  \param
                 *      z - The third value of the vector.
                 */
                Vector3(const Real& x = 1.0, const Real& y = 0.0, 
                        const Real& z = 0.0);

                /**
                 *  Copy constructor. Copy a vector to this vector.
                 *  \param
                 *      vec - The vector we wish to copy.
                 */
                Vector3(const Vector3& vec);

                /**
                 *  Copy constructor. Copies an array to this vector.
                 *  \param
                 *      vec - The array.
                 */
                Vector3(const Real vec[3]);

                /**
                 *  Destructor. Destroys the vector
                 */
                ~Vector3();

                /**
                 *  Get the elements of the vector as a constant array.
                 *  \return
                 *      A constant pointer to the data elements.
                 */
                operator const Real* () const;

                /**
                 *  Get a pointer to the elements of the vector.
                 *  \return
                 *      A pointer to the elements of the vector.
                 */
                operator Real* ();

                /**
                 *  Access element number i from the vector.
                 *  \param
                 *      i - The index in the vector.
                 *  \return
                 *      A reference to element i of the vector.
                 */
                Real& operator[](const ptrdiff_t i);

                /**
                 *  Get a copy of the value in element number i from the 
                 *  vector.
                 *  \param
                 *      i - The index in the vector.
                 *  \return
                 *      A copy of the value in element i of the vector.
                 */
                Real operator[](const ptrdiff_t i) const;

                /**
                 *  Check if two vectors are equal.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      true if all the elements are equal, false else.
                 */
                bool operator==(const Vector3& vec) const;

                /**
                 *  Check if two vectors are unequal.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      true if at least one of the elements are unequal to the
                 *      elements of this vector, false otherwise.
                 */
                bool operator!=(const Vector3& vec) const;

                /**
                 *  Checks if this vector is smaller then another vector.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      true if all the elements are smaller then the elements
                 *      of vec, false otherwise.
                 */
                bool operator<(const Vector3& vec) const;

                /**
                 *  Checks if this vector is smaller then or equal to another
                 *  vector.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      true if all the elements are smaller then or equal to
                 *      the elements of vec, false otherwise.
                 */
                bool operator<=(const Vector3& vec) const;

                /**
                 *  Checks if this vector is larger then another vector.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      true if all the elements are larger then the elements
                 *      of vec, false otherwise.
                 */
                bool operator>(const Vector3& vec) const;

                /**
                 *  Checks if this vector is larger then or equal to another
                 *  vector.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      true if all the elements are larger then or equal to
                 *      the elements of vec, false otherwise.
                 */
                bool operator>=(const Vector3& vec) const;

                /**
                 *  Add this vector with another.
                 *  \param
                 *      vec - The vector to add this vector with.
                 *  \return
                 *      A new vector which is this vector added with vec.
                 */
                Vector3 operator+(const Vector3& vec) const;

                /**
                 *  Subtract a vector from this vector.
                 *  \param
                 *      vec - The vector to subtract with.
                 *  \return
                 *      This vector subtracted with vec.
                 */
                Vector3 operator-(const Vector3& vec) const;

                /**
                 *  Multiply two vectors together the normal way.
                 *  \param
                 *      vec - The vector to multiply with.
                 *  \return
                 *      A scalar which is the vector-to-vector multiplication
                 *      between this vector and vec.
                 */
                Real operator*(const Vector3& vec) const;

                /**
                 *  Multiply this vector with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      This vector multiplied with a scalar.
                 */
                Vector3 operator*(const Real& scalar) const;

                /**
                 *  Divide this vector with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      This vector divided with a scalar.
                 *  \note
                 *      Will crash if the scalar is equal to zero.
                 */
                Vector3 operator/(const Real& scalar) const;

                /**
                 *  Make this vector negated.
                 *  \return
                 *      This vector negated.
                 */
                Vector3 operator-() const;

                /**
                 *  Add a vector to this vector.
                 *  \param
                 *      vec - The vector to add to this vector.
                 */
                void operator+=(const Vector3& vec);

                /**
                 *  Subtract a vector from this vector.
                 *  \param
                 *      vec - The vector to subtract with.
                 */
                void operator-=(const Vector3& vec);

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
                 *  \note
                 *      If scalar is zero, the program will crash.
                 */
                void operator/=(const Real& scalar);

                /**
                 *  Get the length of the vector. As the sqrt of the sum of 
                 *  each element summed.
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
                 *  Normalize the vector, that its make the length of the 
                 *  vector 1.
                 *  \note
                 *      No error testing is done, do NOT try normalizing a zero
                 *      vector.
                 */
                void normalize();

                /**
                 *  Normalize the vector, but check if it can be done first.
                 *  \return
                 *      true if the vector is normalized, false if it can't be
                 *      done.
                 */
                bool normalizeChecked();

                /**
                 *  Cross multiply this vector with another.
                 *  \param
                 *      vec - The vector to cross multiply with.
                 *  \return
                 *      The two vectors crossed.
                 */
                Vector3 cross(const Vector3& vec) const;
            public:
                Real x, y, z;
        };

#include "PandoraVector3.inl"

    }
}
#endif
