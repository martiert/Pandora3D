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

namespace Pandora
{
    namespace Math
    {
        /**
         * A 2D vector class.
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
                Vec2(const Real x = 1.0, const Real y = 0.0);

                /**
                 * Copy constructor.
                 * \param
                 *      vec - The vector to copy.
                 */
                Vec2(const Vec2& vec);

                /** Destructor */
                ~Vec2();

                /**
                 * Copy a vector to this vector.
                 * \param
                 *      vec - The vector to copy.
                 */
                void operator=(const Vec2& vec);

                /**
                 * Adds two vectors.
                 * \param
                 *      vec - The vector to add to this vector.
                 *  \return
                 *      This vector added with vec.
                 */
                Vec2 operator+(const Vec2& vec);

                /**
                 * Subtract two vectors.
                 * \param
                 *      vec - The vector to subtract from this vector.
                 *  \return
                 *      this vector subtracted with vec.
                 */
                Vec2 operator-(const Vec2& vec);

                /**
                 * Dot-Multiply two vectors.
                 * \param
                 *      vec - The vector to dot-multiply with.
                 *  \return
                 *      This vector dot-multiplied with vec.
                 */
                Real operator*(const Vec2& vec);

                /**
                 * Divide each element of this vector, with the elements of 
                 * another vector.
                 * \param
                 *      vec - The vector to divide with.
                 *  \return
                 *      A vector where each of this vectors elements are
                 *      divided with the corresponding element of vec.
                 */
                Vec2 operator/(const Vec2& vec);

                /**
                 * Multiply this vector with a scalar.
                 * \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      A vector where each of it's elements is this vectors
                 *      elements multiplied with the scalar.
                 */
                Vec2 operator*(const Real scalar);

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
                Vec2 operator/(const Real scalar);

                /**
                 * Find the length of the vector.
                 * \return
                 *      The length of the vector.
                 */
                Real length();

                /**
                 * Find the squared length of the vector.
                 * \return
                 *      The squared length of the vector.
                 */
                Real lengthSquared();

                Real x, y;
        };
    }
}
#endif
