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

#ifndef PANDORAQUATERNION_H
#define PANDORAQUATERNION_H

#include "PandoraMath.h"
#include "PandoraVector3.h"
#include "PandoraMatrix3.h"
#include "PandoraVector4.h"
#include "PandoraMatrix4.h"

namespace Pandora
{
    namespace Math
    {
        /**
         *  A simple quaternion class of the form [x,y,z,w] where x,y and z are
         *  imaginary components, while w is a real component.
         */
        template<class Real>
        class Quaternion
        {
            public:
                /**
                 *  Constructor. Makes a quaternion with unspecified 
                 *  components.
                 */
                Quaternion();

                /**
                 *  Constructor. Makes a specified quaternion.
                 *  \param
                 *      mx - The x component.
                 *  \param
                 *      my - The y component.
                 *  \param
                 *      mz - The z component.
                 *  \param
                 *      mw - The w component.
                 */
                Quaternion(const Real& mx, const Real& my, const Real& mz,
                        const Real& mw);

                /**
                 *  Copy constructor.
                 *  \param
                 *      quat - The quaternion to copy.
                 */
                Quaternion(const Quaterion& quat);

                /**
                 *  Assignment operator.
                 *  \param
                 *      quat - The quaternion we should assign to.
                 *  \return
                 *      This quaternion.
                 */
                Quaternion& operator=(const Quaternion& quat);

                /**
                 *  Add two quaternions.
                 *  \param
                 *      quat - The quaternion to add with.
                 *  \return
                 *      This quaternion added by quat.
                 */
                Quaternion operator+(const Quaternion& quat) const;

                /**
                 *  Subtract two quaternions.
                 *  \param
                 *      quat - The quaternion to subtract with.
                 *  \return
                 *      This quaternion subtracted by quat.
                 */
                Quaternion operator-(const Quaternion& quat) const;

                /**
                 *  Multiply a quaternion with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      This quaternion multiplied by scalar.
                 */
                Quaternion operator*(const Real& scalar) const;

                /**
                 *  Divide a quaternion by a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      This quaternion divided by scalar.
                 *  \note
                 *      Checks for division by zero in DEBUG mode only.
                 */
                Quaternion operator/(const Real& scalar) const;

                /**
                 *  Multiply two quaternions.
                 *  \param
                 *      quat - The quaternion to multiply with.
                 *  \return
                 *      This quaternion multiplied with quat.
                 */
                Quaternion operator*(const Quaternion& quat) const;

                /**
                 *  Add a quaternion to this quaternion.
                 *  \param
                 *      quat - The quaternion to add with.
                 *  \return
                 *      This quaternion.
                 */
                Quaternion& operator+=(const Quaternion& quat);

                /**
                 *  Subtract a quaternion from this quaternion.
                 *  \param
                 *      quat - The quaternion to subtract with.
                 *  \return
                 *      This quaternion.
                 */
                Quaternion& operator-=(const Quaternion& quat);

                /**
                 *  Multiply this quaternion with a scalar.
                 *  \param  
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      This quaternion.
                 */
                Quaternion& operator*=(const Real& scalar);

                /**
                 *  Divide this quaternion with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      This quaternion.
                 *  \note
                 *      Will only check for division by zero in DEBUG mode.
                 */
                Quaternion& operator/=(const Real& scalar);

                /**
                 *  Calculate the length of the quaternion, which is:
                 *  sqrt(w^2 + x^2 + y^2 + z^2).
                 *  \return
                 *      The length of the quaternion.
                 */
                Real length() const;

                /**
                 *  Calculate the squared length of the quaternion.
                 *  \return
                 *      The squared length of the quaternion.
                 */
                Real lengthSquared() const;

                /**
                 *  Normalize the quaternion.
                 *  \return
                 *      This quaternion.
                 *  \note
                 *      Will only check for zero length in DEBUG mode.
                 */
                Quaternion& normalize();

#ifdef DEBUG
                /**
                 *  Print the quaternion.
                 *  \note
                 *      Will only be available in DEBUG mode.
                 */
                void print();
#endif //DEBUG
            public:
                Real x, y, z, w;

                /**
                 *  Comparison function.
                 *  \param
                 *      quat - The quaternion to compare to.
                 *  \return
                 *      0 if equal, positive if this is larger and negative 
                 *      else.
                 */
                int compare(const Quaternion<Real>& quat) const;
        };
    } //namespace Math
} //namespace Pandora
#endif //PANDORAQUATERNION_H
