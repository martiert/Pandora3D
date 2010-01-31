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

#ifndef PANDORAVECTOR4_H
#define PANDORAVECTOR4_h

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
                Vector4(Real& x = (Real) 1.0, Real& y = (Real) 0.0, 
                        Real& z = (Real) 0.0, Real& w = (Real) 0.0);

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
                 *  \note
                 *      If the length of vec is less then four, unexpected
                 *      behaviour will occur. The behaviour will depend on the
                 *      compiler used.
                 */
                Vector4(Real *vec);
        };
    }
}
#endif
