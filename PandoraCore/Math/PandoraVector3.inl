/*
--------------------------------------------------------------------------------
File Name : PandoraVector3.inl

Purpose : The implementation of the 3D vector class.

Creation Date : 2010-01-28

Last Modified : on. 30. juni 2010 kl. 23.04 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

/********************************************************************************
 * Typedefs.                                                                    *
 *******************************************************************************/
typedef Vector3<float> Vec3f;
typedef Vector3<double> Vec3d;
typedef Vector3<int> Vec3i;
typedef Vector3<unsigned int> Vec3u;

/********************************************************************************
 * Default constructor.                                                         *
 *******************************************************************************/
template<class Real>
Vector3<Real>::Vector3(const Real& x, const Real& y, const Real& z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

/********************************************************************************
 * Copy constructor.                                                            *
 *******************************************************************************/
template<class Real>
Vector3<Real>::Vector3(const Vector3<Real>& vec)
{
    memcpy(&x, &vec.x, 3*sizeof(Real));
}

/********************************************************************************
 * Copy an array to this vector.                                                *
 *******************************************************************************/
template<class Real>
Vector3<Real>::Vector3(const Real vec[3])
{
    memcpy(&x, vec, 3*sizeof(Real));
}

/********************************************************************************
 * Assignment operator.                                                         *
 *******************************************************************************/
template<class Real>
Vector3<Real>& Vector3<Real>::operator=(const Vector3<Real>& vec)
{
    if(this != &vec)
        memcpy(&x, &vec.x, 3*sizeof(Real));
    return *this;
}

/********************************************************************************
 * Destructor.                                                                  *
 *******************************************************************************/
template<class Real>
Vector3<Real>::~Vector3()
{ }

/********************************************************************************
 * Implicit conversion to constant pointer.                                     *
 *******************************************************************************/
template<class Real>
Vector3<Real>::operator const Real* () const
{
    return &x;
}

/********************************************************************************
 * Implicit conversion.                                                         *
 *******************************************************************************/
template<class Real>
Vector3<Real>::operator Real* ()
{
    return &x;
}

/********************************************************************************
 * Assignment operator.                                                         *
 *******************************************************************************/
template<class Real>
Real& Vector3<Real>::operator[](const ptrdiff_t i)
{
    assert(i < 3 && "Index out of range\n");

    return (&x)[i];
}

/********************************************************************************
 * Get value from index i.                                                      *
 *******************************************************************************/
template<class Real>
Real Vector3<Real>::operator[](const ptrdiff_t i) const
{
    assert(i < 3 && "Index out of range\n");

    return (&x)[i];
}

/********************************************************************************
 * Equality operator.                                                           *
 *******************************************************************************/
template<class Real>
bool Vector3<Real>::operator==(const Vector3<Real>& vec) const
{
    return compare(vec) == 0;
}

/********************************************************************************
 * Inequality operator.                                                         *
 *******************************************************************************/
template<class Real>
bool Vector3<Real>::operator!=(const Vector3<Real>& vec) const
{
    return compare(vec) != 0;
}

/********************************************************************************
 * Check if this vector is less then another.                                   *
 *******************************************************************************/
template<class Real>
bool Vector3<Real>::operator<(const Vector3<Real>& vec) const
{
    return compare(vec) < 0;
}

/********************************************************************************
 * Check if this vector is smaller then or equal to another.                    *
 *******************************************************************************/
template<class Real>
bool Vector3<Real>::operator<=(const Vector3<Real>& vec) const
{
    return compare(vec) <= 0;
}

/********************************************************************************
 * Check if this vector is larger than another.                                 *
 *******************************************************************************/
template<class Real>
bool Vector3<Real>::operator>(const Vector3<Real>& vec) const
{
    return compare(vec) > 0;
}

/********************************************************************************
 * Check if this vector is larger then or equal to another.                     *
 *******************************************************************************/
template<class Real>
bool Vector3<Real>::operator>=(const Vector3<Real>& vec) const
{
    return compare(vec) >= 0;
}

/********************************************************************************
 * Add this vector with another.                                                *
 *******************************************************************************/
template<class Real>
Vector3<Real> Vector3<Real>::operator+(const Vector3<Real>& vec) const
{
    return Vector3<Real>(x + vec.x, y + vec.y, z + vec.z);
}

/********************************************************************************
 * Subtract a vector from this vector.                                          *
 *******************************************************************************/
template<class Real>
Vector3<Real> Vector3<Real>::operator-(const Vector3<Real>& vec) const
{
    return ((*this) + (-vec));
}

/********************************************************************************
 * Dot multiply two vectors.                                                    *
 *******************************************************************************/
template<class Real>
Real Vector3<Real>::operator*(const Vector3<Real>& vec) const
{
    return x*vec.x + y*vec.y + z*vec.z;
}

/********************************************************************************
 * Multiply this vector with a scalar.                                          *
 *******************************************************************************/
template<class Real>
Vector3<Real> Vector3<Real>::operator*(const Real& scalar) const
{
    return Vector3<Real>(x*scalar, y*scalar, z*scalar);
}

/********************************************************************************
 * Divide this vector with a scalar.                                            *
 *******************************************************************************/
template<class Real>
Vector3<Real> Vector3<Real>::operator/(const Real& scalar) const
{
    assert( scalar != (Real) 0.0 && "Can not divide by zero\n");
    Real s = ((Real) 1.0)/scalar;
    return (*this)*s;
}

/********************************************************************************
 * Negate the vector.                                                           *
 *******************************************************************************/
template<class Real>
Vector3<Real> Vector3<Real>::operator-() const
{
    return Vector3<Real>(-x, -y, -z);
}

/********************************************************************************
 * Add a vector to this vector.                                                 *
 *******************************************************************************/
template<class Real>
Vector3<Real>& Vector3<Real>::operator+=(const Vector3<Real>& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

/********************************************************************************
 * Subtract a vector from this vector.                                          *
 *******************************************************************************/
template<class Real>
Vector3<Real>& Vector3<Real>::operator-=(const Vector3<Real>& vec)
{
    (*this) += -vec;
    return *this;
}

/********************************************************************************
 * Multiply this vector with a scalar.                                          *
 *******************************************************************************/
template<class Real>
Vector3<Real>& Vector3<Real>::operator*=(const Real& scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

/********************************************************************************
 * Divide this vector with a scalar.                                            *
 *******************************************************************************/
template<class Real>
Vector3<Real>& Vector3<Real>::operator/=(const Real& scalar)
{
    assert( scalar != (Real) 0.0 && "Can't divide by zero\n");
    Real s = ((Real) 1.0)/scalar;
    (*this) *= s;
    return *this;
}

/********************************************************************************
 * Getting the length of the vector.                                            *
 *******************************************************************************/
template<class Real>
Real Vector3<Real>::length() const
{
    return Math<Real>::Sqrt(x*x + y*y + z*z);
}

/********************************************************************************
 * Getting the squared length of the vector.                                    *
 *******************************************************************************/
template<class Real>
Real Vector3<Real>::lengthSquared() const
{
    return (x*x + y*y + z*z);
}

/********************************************************************************
 * Normalize the vector.                                                        *
 *******************************************************************************/
template<class Real>
Vector3<Real>& Vector3<Real>::normalize()
{
    Real len = length();

    assert(len != (Real) 0.0);

    *this /= len;
    return *this;
}

/********************************************************************************
 * Cross multiply this vector with another.                                     *
 *******************************************************************************/
template<class Real>
Vector3<Real> Vector3<Real>::cross(const Vector3<Real>& vec) const
{
    return Vector3<Real>(y*vec.z - z*vec.y,
            vec.x*z - x*vec.z,
            x*vec.y - y*vec.x);
}

#ifdef DEBUG
/********************************************************************************
 * Print out the matrix.
 *******************************************************************************/
template<class Real>
void Vector3<Real>::print() const
{
    printf("\n[%g %g %g]\n\n", x, y, z);
}
#endif

/********************************************************************************
 * Makes it possible to write scalar*vec.                                       *
 *******************************************************************************/
template<class Real>
Vector3<Real> operator*(const Real& scalar, const Vector3<Real>& vec)
{
    return vec*scalar;
}

/********************************************************************************
 * Comparison function.                                                         *
 *******************************************************************************/
template<class Real>
int Vector3<Real>::compare(const Vector3<Real>& vec) const
{
    return memcmp(&x, &vec.x, 3*sizeof(Real));
}
