/*
--------------------------------------------------------------------------------
File Name : PandoraQuat.inl

Purpose :

Creation Date : 2010-08-09

Last Modified : ti. 10. aug. 2010 kl. 18.43 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

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
Quat<Real>::Quat(const Real& mx, const Real& my, const Real& mz, const Real& mw)
{
    x = mx;
    y = my;
    z = mz;
    w = mw;
}

/********************************************************************************
 * Copy constructor.                                                            *
 *******************************************************************************/
template<class Real>
Quat<Real>::Quat(const Quat<Real>& quat)
{
    memcpy(&x, &(quat.x), 4*sizeof(Real));
}

/********************************************************************************
 * Copy operator.                                                               *
 *******************************************************************************/
template<class Real>
Quat<Real>& Quat<Real>::operator=(const Quat<Real>& quat)
{
    memcpy(&x, &(quat.x), 4*sizeof(Real));
    return *this
}

/********************************************************************************
 * Add two quaternions.                                                         *
 *******************************************************************************/
template<class Real>
Quat<Real> Quat<Real>::operator+(const Quat<Real>& quat) const
{
    return Quat<Real>(x+quat.x, y+quat.y, z+quat.z, w+quat.w);
}

/********************************************************************************
 * Subtract two quaternions.                                                    *
 *******************************************************************************/
template<class Real>
Quat<Real> Quat<Real>::operator-(const Quat<Real>& quat) const
{
    return Quat<Real>(x-quat.x, y-quat.y, z-quat.z, w-quat.w);
}

/********************************************************************************
 * Multiply a quaternion with a scalar.                                         *
 *******************************************************************************/
template<class Real>
Quat<Real> Quat<Real>::operator*(const Real& scalar) const
{
    return Quat<Real>(x*scalar, y*scalar, z*scalar, w*scalar);
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
 * Calculate the length of the quaternion.                                      *
 *******************************************************************************/
template<class Real>
Real Quat<Real>::length() const
{
    return Math<Real>::Sqrt(x*x + y*y + z*z + w*w);
}

/********************************************************************************
 * Calculate the squared length of the quaternion.                              *
 *******************************************************************************/
template<class Real>
Real Quat<Real>::lengthSquared() const
{
    return (x*x + y*y + z*z + w*w);
}

/********************************************************************************
 * Normalize the quaternion.                                                    *
 *******************************************************************************/
template<class Real>
Quat<Real>& Quat<Real>::normalize()
{
    Real len = length();

    assert( len != 0.0 );

    x /= len;
    y /= len;
    z /= len;
    w /= len;
    return (*this);
}

#ifdef DEBUG
/********************************************************************************
 * Print the quaternion.                                                        *
 *******************************************************************************/
template<class Real>
void Quat<Real>::print() const
{
    printf("|%8.4f %8.4f %8.4f %8.4f|\n", x, y, z, w);
}
#endif
