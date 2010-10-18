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

                static Quat IDENTITY;
        };

/********************************************************************************
 * Default constructor.                                                         *
 *******************************************************************************/
template<class Real>
Quat<Real>::Quat()
{
}


/********************************************************************************
 * Constructor.                                                                 *
 *******************************************************************************/
template<class Real>
Quat<Real>::Quat(const Real& mw, const Real& x, const Real& y, const Real& z)
{
    w = mw;
    imag[0] = x;
    imag[1] = y;
    imag[2] = z;
}


/********************************************************************************
 * Constructor.                                                                 *
 *******************************************************************************/
template<class Real>
Quat<Real>::Quat(const Real& mw, const Vector3<Real>& mimag)
{
    w = mw;
    imag = mimag;
}


/********************************************************************************
 * Copy constructor.                                                            *
 *******************************************************************************/
template<class Real>
Quat<Real>::Quat(const Quat<Real>& quat)
{
    w = quat.w;
    imag = quat.imag;
}


/********************************************************************************
 * Quaternion from matrix.                                                      *
 *******************************************************************************/
template<class Real>
Quat<Real>::Quat(const Matrix3<Real>& mat)
{
    fromRotationMatrix(mat);
}


/********************************************************************************
 * Quaternion from matrix.                                                      *
 *******************************************************************************/
template<class Real>
Quat<Real>::Quat(const Matrix4<Real>& mat)
{
    Matrix3<Real> tmp(mat[0], mat[1], mat[2],
                      mat[4], mat[5], mat[6],
                      mat[8], mat[9], mat[10]);
    fromRotationMatrix(tmp);
}


/********************************************************************************
 * Negate the quaternion.                                                       *
 *******************************************************************************/
template<class Real>
Quat<Real> Quat<Real>::operator-() const
{
    return Quat<Real>(-w, -imag);
}


/********************************************************************************
 * Copy operator.                                                               *
 *******************************************************************************/
template<class Real>
Quat<Real>& Quat<Real>::operator=(const Quat<Real>& quat)
{
    w = quat.w;
    imag = quat.imag;
    return *this;
}


/********************************************************************************
 * Add two quaternions.                                                         *
 *******************************************************************************/
template<class Real>
Quat<Real> Quat<Real>::operator+(const Quat<Real>& quat) const
{
    return Quat<Real>(w + quat.w, imag + quat.imag);
}


/********************************************************************************
 * Subtract two quaternions.                                                    *
 *******************************************************************************/
template<class Real>
Quat<Real> Quat<Real>::operator-(const Quat<Real>& quat) const
{
    return Quat<Real>(w - quat.w, imag - quat.imag);
}


/********************************************************************************
 * Multiply a quaternion with a scalar.                                         *
 *******************************************************************************/
template<class Real>
Quat<Real> Quat<Real>::operator*(const Real& scalar) const
{
    return Quat<Real>(scalar * w, imag * scalar);
}


/********************************************************************************
 * Divide a quaternion with a scalar.                                           *
 *******************************************************************************/
template<class Real>
Quat<Real> Quat<Real>::operator/(const Real& scalar) const
{
    assert( scalar != 0.0 );
    Real scal = 1.0/scalar;
    return ((*this) * scal);
}


/********************************************************************************
 * Multiply two quaternions.                                                    *
 *******************************************************************************/
template<class Real>
Quat<Real> Quat<Real>::operator*(const Quat<Real>& quat) const
{
    return Quat<Real>(w*quat.w - imag*quat.imag, 
            imag.cross(quat.imag) + quat.w*imag + w*quat.imag);
}


/********************************************************************************
 * Add a quaternion to this quaternion.                                         *
 *******************************************************************************/
template<class Real>
Quat<Real>& Quat<Real>::operator+=(const Quat<Real>& quat)
{
    (*this) = (*this) + quat;
    return (*this);
}


/********************************************************************************
 * Subtract a quaternion from this quaternion.                                  *
 *******************************************************************************/
template<class Real>
Quat<Real>& Quat<Real>::operator-=(const Quat<Real>& quat)
{
    (*this) = (*this) - quat;
    return (*this);
}


/********************************************************************************
 * Multiply this quaternion with a scalar.                                      *
 *******************************************************************************/
template<class Real>
Quat<Real>& Quat<Real>::operator*=(const Real& scalar)
{
    (*this) = (*this) * scalar;
    return (*this);
}


/********************************************************************************
 * Divide this quaternion with a scalar.                                        *
 *******************************************************************************/
template<class Real>
Quat<Real>& Quat<Real>::operator/=(const Real& scalar)
{
    (*this) = (*this) / scalar;
    return (*this);
}


/********************************************************************************
 * Compute the conjugate.                                                       *
 *******************************************************************************/
template<class Real>
Quat<Real> Quat<Real>::conjugate() const
{
    return Quat<Real>(w, -imag);
}


/********************************************************************************
 * Inverte the quaternion.                                                      *
 *******************************************************************************/
template<class Real>
Quat<Real> Quat<Real>::inverse() const
{
    return (1.0/lengthSquared())*conjugate();
}


/********************************************************************************
 * Calculate the length of the quaternion.                                      *
 *******************************************************************************/
template<class Real>
Real Quat<Real>::length() const
{
    return Math<Real>::Sqrt(w*w + imag*imag);
}


/********************************************************************************
 * Calculate the squared length of the quaternion.                              *
 *******************************************************************************/
template<class Real>
Real Quat<Real>::lengthSquared() const
{
    return (w*w + imag*imag);
}


/********************************************************************************
 * Normalize the quaternion.                                                    *
 *******************************************************************************/
template<class Real>
Quat<Real>& Quat<Real>::normalize()
{
    Real len = length();

    assert( len != 0.0 );

    *this /= len;
    return (*this);
}


/********************************************************************************
 * Make a rotation matrix.                                                      *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Quat<Real>::toRotationMatrix() const
{
    assert( length() == 1.0 && "Quat<Real>::toRotationMatrix: Quaternion needs to be unit length");
    Matrix3<Real> tmp;

    tmp[0] = 1 - 2 * (imag[1]*imag[1] + imag[2]*imag[2]);
    tmp[1] = 2 * (imag[0]*imag[1] - w*imag[2]);
    tmp[2] = 2 * (imag[0]*imag[2] + w*imag[1]);

    tmp[3] = 2 * (imag[0]*imag[1] + w*imag[2]);
    tmp[4] = 1 - 2*(imag[0]*imag[0] + imag[2]*imag[2]);
    tmp[5] = 2 * (imag[1]*imag[2] - w*imag[0]);

    tmp[6] = 2 * (imag[0]*imag[2] - w*imag[1]);
    tmp[7] = 2 * (imag[1]*imag[2] + w*imag[0]);
    tmp[8] = 1 - 2 * (imag[0]*imag[0] + imag[1]*imag[1]);

    return tmp;
}

/********************************************************************************
 * Make quaternion from a 3D matrix.                                            *
 *******************************************************************************/
template<class Real>
Quat<Real>& Quat<Real>::fromRotationMatrix(const Matrix3<Real>& mat)
{
    Real trace = mat.trace();
    Real root;

    if(trace > 0.0) {
        // |w| > 1/2
        root = Math<Real>::Sqrt(trace + 1);
        w = 0.5*root; //w
        root = 0.5/root; //1/(4w)
        imag[0] = (mat(2,1) - mat(1,2))*root;
        imag[1] = (mat(0,2) - mat(2,0))*root;
        imag[2] = (mat(1,0) - mat(0,1))*root;
    } else {
        // |w| <= 1/2
        int i = 0;
        if( mat(1,1) > mat(0,0) )
            i = 1;
        if( mat(2,2) > mat(i,i) )
            i = 2;

        int j = (i+1) % 3;
        int k = (j+1) % 3;

        root = Math<Real>::Sqrt(mat(i,i) - mat(j,j) - mat(k,k) + 1.0);
        imag[i] = 0.5*root;
        root = 0.5/root;
        w = (mat(k,j) - mat(j,k))*root;
        imag[j] = (mat(j,i) + mat(i,j))*root;
        imag[k] = (mat(k,i) + mat(i,k))*root;
    }

    return *this;
}


/********************************************************************************
 * Check for equality.                                                          *
 *******************************************************************************/
template<class Real>
bool Quat<Real>::operator==(const Quat<Real>& quat) const
{
    return compare(quat) == 0;
}


/********************************************************************************
 * Check for inequality.                                                        *
 *******************************************************************************/
template<class Real>
bool Quat<Real>::operator!=(const Quat<Real>& quat) const
{
    return compare(quat) != 0;
}


/********************************************************************************
 * geq operator.                                                                *
 *******************************************************************************/
template<class Real>
bool Quat<Real>::operator>=(const Quat<Real>& quat) const
{
    return compare(quat) >= 0;
}


/********************************************************************************
 * > operator.                                                                  *
 *******************************************************************************/
template<class Real>
bool Quat<Real>::operator>(const Quat<Real>& quat) const
{
    return compare(quat) > 0;
}


/********************************************************************************
 * leq operator.                                                                *
 *******************************************************************************/
template<class Real>
bool Quat<Real>::operator<=(const Quat<Real>& quat) const
{
    return compare(quat) <= 0;
}


/********************************************************************************
 * < operator.                                                                  *
 *******************************************************************************/
template<class Real>
bool Quat<Real>::operator<(const Quat<Real>& quat) const
{
    return compare(quat) < 0;
}


/********************************************************************************
 * comparison.                                                                  *
 *******************************************************************************/
template<class Real>
int Quat<Real>::compare(const Quat<Real>& quat) const
{
    if(w > quat.w)
        return 1;
    if(w < quat.w)
        return -1;

    for(int i = 0; i < 3; i++) {
        if(imag[i] > quat.imag[i])
            return 1;
        if(imag[i] < quat.imag[i])
            return -1;
    }

    return 0;
}


#ifdef DEBUG
/********************************************************************************
 * Print the quaternion.                                                        *
 *******************************************************************************/
template<class Real>
void Quat<Real>::print() const
{
    printf("|%8.4f %8.4f %8.4f %8.4f|\n", w, imag[0], imag[1], imag[2]);
}
#endif

    } //namespace Math
} //namespace Pandora
#endif //PANDORAQUATERNION_H
