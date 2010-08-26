/*
--------------------------------------------------------------------------------
File Name : PandoraQuat.cpp

Purpose : Implementation of the quaternion class in Pandora 3D.

Creation Date : 2010-08-09

Last Modified : to. 26. aug. 2010 kl. 21.33 +0200

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
--------------------------------------------------------------------------------
*/

#include "../include/PandoraQuat.h"

namespace Pandora
{
    namespace Math
    {

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
    return *this
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
    (*this) w= (*this) + quat;
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
 * Make a rotation matrix.                                                      *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Quat<Real>::toRotationMatrix() const
{
    assert( length() == 1.0 && "Quat<Real>::toRotationMatrix: Quaternion needs to be unit length");
    Matrix3<Real> tmp = toRotationMatrix();
    Matrix4<Real> ans(tmp);

    return ans;
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

        root = Math<Real>:Sqrt( mat(i,i) - rot(j,j) - rot(k,k) + 1.0);
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
} // namespace Math
} // namespace Pandora
