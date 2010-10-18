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
        class Quat
        {
            public:
                /**
                 *  Constructor. Makes a undefined quaternion
                 */
                Quat();

                /**
                 *  Constructor. Makes a specified quaternion.
                 *  \param
                 *      w - The w component (Real part)
                 *  \param
                 *      x - The x component.
                 *  \param
                 *      y - The y component.
                 *  \param
                 *      z - The z component.
                 */
                Quat(const Real& w, const Real& x, const Real& y, 
                        const Real& z);

                /**
                 *  Constructor. Makes a quaternion.
                 *  \param
                 *      w - The real part.
                 *  \param
                 *      imag - The imaginary part.
                 */
                Quat(const Real& mw, const Vector3<Real>& mimag);

                /**
                 *  Copy constructor.
                 *  \param
                 *      quat - The quaternion to copy.
                 */
                Quat(const Quat& quat);

                /**
                 *  Make a quaternion from a 3D rotation matrix.
                 *  \param
                 *      mat - The rotation matrix.
                 */
                Quat(const Matrix3<Real>& mat);

                /**
                 *  Make a quaternion from a 4D rotation matrix.
                 *  \param
                 *      mat - The rotation matrix.
                 */
                Quat(const Matrix4<Real>& mat);

                /**
                 *  Assignment operator.
                 *  \param
                 *      quat - The quaternion we should assign to.
                 *  \return
                 *      This quaternion.
                 */
                Quat& operator=(const Quat& quat);

                /**
                 *  Negate the quaternion.
                 *  \return
                 *      The quaternion negated.
                 */
                Quat operator-() const;

                /**
                 *  Add two quaternions.
                 *  \param
                 *      quat - The quaternion to add with.
                 *  \return
                 *      This quaternion added by quat.
                 */
                Quat operator+(const Quat& quat) const;

                /**
                 *  Subtract two quaternions.
                 *  \param
                 *      quat - The quaternion to subtract with.
                 *  \return
                 *      This quaternion subtracted by quat.
                 */
                Quat operator-(const Quat& quat) const;

                /**
                 *  Multiply a quaternion with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      This quaternion multiplied by scalar.
                 */
                Quat operator*(const Real& scalar) const;

                /**
                 *  Divide a quaternion by a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      This quaternion divided by scalar.
                 *  \note
                 *      Checks for division by zero in DEBUG mode only.
                 */
                Quat operator/(const Real& scalar) const;

                /**
                 *  Multiply two quaternions.
                 *  \param
                 *      quat - The quaternion to multiply with.
                 *  \return
                 *      This quaternion multiplied with quat.
                 */
                Quat operator*(const Quat& quat) const;

                /**
                 *  Add a quaternion to this quaternion.
                 *  \param
                 *      quat - The quaternion to add with.
                 *  \return
                 *      This quaternion.
                 */
                Quat& operator+=(const Quat& quat);

                /**
                 *  Subtract a quaternion from this quaternion.
                 *  \param
                 *      quat - The quaternion to subtract with.
                 *  \return
                 *      This quaternion.
                 */
                Quat& operator-=(const Quat& quat);

                /**
                 *  Multiply this quaternion with a scalar.
                 *  \param  
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      This quaternion.
                 */
                Quat& operator*=(const Real& scalar);

                /**
                 *  Divide this quaternion with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      This quaternion.
                 *  \note
                 *      Will only check for division by zero in DEBUG mode.
                 */
                Quat& operator/=(const Real& scalar);

                /**
                 *  Compute the conjugate of the quaternion.
                 *  \return
                 *      The conjugate of the quaternion.
                 */
                Quat conjugate() const;

                /**
                 *  Calculate the inverse of the quaternion.
                 *  \return
                 *      This quaternion inverse.
                 */
                Quat inverse() const;

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
                Quat& normalize();

                /*
                 *  Get the rotation matrix from this quaternion.
                 *  \return
                 *      The rotation matrix this quaternion represents.
                 *  \note
                 *      This only works if the quaternion is already a
                 *      unit quaternion.
                 */
                Matrix3<Real> toRotationMatrix() const;

                /**
                 *  Make this quaternion from a rotation matrix.
                 *  \param
                 *      mat - The matrix were converting from.
                 *  \return
                 *      This quaternion.
                 */
                Quat& fromRotationMatrix(const Matrix3<Real>& mat);

                /**
                 *  Check if two quaternions are equal.
                 *  \param
                 *      quat - The quaternion to compare with.
                 *  \return
                 *      True if all elements are equal, false else.
                 */
                bool operator==(const Quat& quat) const;

                /**
                 *  Check if two quaternions are different.
                 *  \param
                 *      quat - The quaternion to compare with.
                 *  \return
                 *      True if not all elements are equal.
                 */
                bool operator!=(const Quat& quat) const;


                /**
                 *  Check if this quaternion are larger then another.
                 *  \param
                 *      quat - The quaternion to compare with.
                 *  \return
                 *      True if the first different element is larger then
                 *      in quat, or all elements are equal.
                 */
                bool operator>=(const Quat& quat) const;

                /**
                 *  Check if this quaternion are larger then in quat.
                 *  \param
                 *      quat - The quaternion to compare with.
                 *  \return
                 *      True if the first different element is larger
                 *      then in quat and the two quaternions differ.
                 */
                bool operator>(const Quat& quat) const;
                
                 /**
                 *  Check if this quaternion is smaller then or equal to another.
                 *  \param
                 *      quat - The quaternion to compare with.
                 *  \return
                 *      True if all elements are equal, or if the first non-equal
                 *      element is smaller in this quaternion.
                 */
                bool operator<=(const Quat& quat) const;               
                
                /**
                 *  Check if this quaternion is smaller then another.
                 *  \param
                 *      quat - The quaternion to compare with.
                 *  \return
                 *      True if they are not equal and the first differing
                 *      element in this quaternion is smallest.
                 */
                bool operator<(const Quat& quat) const;

#ifdef DEBUG
                /**
                 *  Print the quaternion.
                 *  \note
                 *      Will only be available in DEBUG mode.
                 */
                void print();
#endif //DEBUG
            public:
                Real w;
                Vector3<Real> imag;

                /**
                 *  Comparison function.
                 *  \param
                 *      quat - The quaternion to compare to.
                 *  \return
                 *      0 if equal, positive if this is larger and negative 
                 *      else.
                 */
                int compare(const Quat<Real>& quat) const;

                static const Quat IDENTITY;
                static const Quat ZERO;
                static const Quat ONES;
        };

#include "tmpl/PandoraQuat.tmpl"

    } //namespace Math
} //namespace Pandora
#endif //PANDORAQUATERNION_H
