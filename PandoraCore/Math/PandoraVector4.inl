/*
--------------------------------------------------------------------------------
File Name : PandoraVector4.inl

Purpose : Implementation of the Vector4 class.

Creation Date : 2010-01-31

Last Modified : on. 30. juni 2010 kl. 23.05 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

/********************************************************************************
 * Typedefs.                                                                    *
 *******************************************************************************/
typedef Vector4<float> Vec4f;
typedef Vector4<double> Vec4d;
typedef Vector4<int> Vec4i;
typedef Vector4<unsigned int> Vec4u;

/********************************************************************************
 * Default constructor.                                                         *
 *******************************************************************************/
template<class Real>
Vector4<Real>::Vector4(Real x, Real y, Real z, Real w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

/********************************************************************************
 * Copy constructor.                                                            *
 *******************************************************************************/
template<class Real>
Vector4<Real>::Vector4(Vector4<Real>& vec)
{
    memcpy(&x, &(vec.x), 4*sizeof(Real));
}

/********************************************************************************
 * Copy an array to this vector.                                                *
 *******************************************************************************/
template<class Real>
Vector4<Real>::Vector4(Real vec[4])
{
    memcpy(&x, vec, 4*sizeof(Real));
}

/********************************************************************************
 * Destructor.                                                                  *
 *******************************************************************************/
template<class Real>
Vector4<Real>::~Vector4()
{}

/********************************************************************************
 * Assign a vector to this vector.                                              *
 *******************************************************************************/
template<class Real>
Vector4<Real>& Vector4<Real>::operator=(const Vector4<Real>& vec)
{
    if(this != &vec)
        memcpy(&x, &(vec.x), 4*sizeof(Real));
    return *this;
}

/********************************************************************************
 * Get element number i from the vector.                                        *
 *******************************************************************************/
template<class Real>
Real& Vector4<Real>::operator[](const ptrdiff_t i)
{
    assert(i < 4 && "Index out of range");
    return (&x)[i];
}

/********************************************************************************
 * Get value in element number i from the vector.                               *
 *******************************************************************************/
template<class Real>
Real Vector4<Real>::operator[](const ptrdiff_t i) const
{
    assert(i < 4 && "Index out of range");
    return (&x)[i];
}

/********************************************************************************
 * Implicit conversion to array.                                                *
 *******************************************************************************/
template<class Real>
Vector4<Real>::operator Real *()
{
    return &x;
}

/********************************************************************************
 * Implicit conversion to constant array.                                       *
 *******************************************************************************/
template<class Real>
Vector4<Real>::operator const Real *() const
{
    return &x;
}

/********************************************************************************
 * Negate a vector.                                                             *
 *******************************************************************************/
template<class Real>
Vector4<Real> Vector4<Real>::operator-() const
{
    return Vector4<Real>(-x, -y, -z, -w);
}

/********************************************************************************
 * Add two vectors.                                                             *
 *******************************************************************************/
template<class Real>
Vector4<Real> Vector4<Real>::operator+(const Vector4<Real>& vec) const
{
    return Vector4<Real>(x+vec.x, y+vec.y, z+vec.z, w+vec.w);
}

/********************************************************************************
 * Subtract two vectors.                                                        *
 *******************************************************************************/
template<class Real>
Vector4<Real> Vector4<Real>::operator-(const Vector4<Real>& vec) const
{
    return ((*this) + (-vec));
}

/********************************************************************************
 * Multiply a vector with a scalar.                                             *
 *******************************************************************************/
template<class Real>
Vector4<Real> Vector4<Real>::operator*(const Real& scalar) const
{
    return Vector4<Real>(x*scalar, y*scalar, z*scalar, w*scalar);
}

/********************************************************************************
 * Divide a vector with a scalar.                                               *
 *******************************************************************************/
template<class Real>
Vector4<Real> Vector4<Real>::operator/(const Real& scalar) const
{
    assert(scalar != 0 && "Can not divide by zero");
 
    Real s = ((Real) 1.0)/scalar;
    return ((*this) * s);
}

/********************************************************************************
 * Dot multiply two vectors.                                                    *
 *******************************************************************************/
template<class Real>
Real Vector4<Real>::operator*(const Vector4<Real>& vec) const
{
    return (x*vec.x + y*vec.y + z*vec.z + w*vec.w);
}

/********************************************************************************
 * Add a vector to this vector.                                                 *
 *******************************************************************************/
template<class Real>
Vector4<Real>& Vector4<Real>::operator+=(const Vector4<Real>& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    w += vec.w;
    return *this;
}

/********************************************************************************
 * Subtract a vector from this vector.                                          *
 *******************************************************************************/
template<class Real>
Vector4<Real>& Vector4<Real>::operator-=(const Vector4<Real>& vec)
{
    (*this) += -vec;
    return *this;
}

/********************************************************************************
 * Multiply this vector with a scalar.                                          *
 *******************************************************************************/
template<class Real>
Vector4<Real>& Vector4<Real>::operator*=(const Real& scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}

/********************************************************************************
 * Divide this vector with a scalar.                                            *
 *******************************************************************************/
template<class Real>
Vector4<Real>& Vector4<Real>::operator/=(const Real& scalar)
{
    assert(scalar != 0 && "Can not divide by zero");
    
    Real s = ((Real) 1.0)/scalar;
    (*this) *= s;
    return *this;
}

/********************************************************************************
 * Check if two vectors are equal.                                              '
 *******************************************************************************/
template<class Real>
bool Vector4<Real>::operator==(const Vector4<Real>& vec) const
{
    return compare(vec) == 0;
}

/********************************************************************************
 * Check if two vectors are unequal.                                            *
 *******************************************************************************/
template<class Real>
bool Vector4<Real>::operator!=(const Vector4<Real>& vec) const
{
    return compare(vec) != 0;
}

/********************************************************************************
 * Check if this vector is less then another.                                   *
 *******************************************************************************/
template<class Real>
bool Vector4<Real>::operator<(const Vector4<Real>& vec) const
{
    return compare(vec) < 0;
}

/********************************************************************************
 * Check if this vector is less then or equal to another.                       *
 *******************************************************************************/
template<class Real>
bool Vector4<Real>::operator<=(const Vector4<Real>& vec) const
{
    return compare(vec) <= 0;
}

/********************************************************************************
 * Check if this vector is larger then another.                                 *
 *******************************************************************************/
template<class Real>
bool Vector4<Real>::operator>(const Vector4<Real>& vec) const
{
    return compare(vec) > 0;
}

/********************************************************************************
 * Check if this vector is larger then or equal to another.                     *
 *******************************************************************************/
template<class Real>
bool Vector4<Real>::operator>=(const Vector4<Real>& vec) const
{
    return compare(vec) >= 0;
}

/********************************************************************************
 * Get the length of the vector.                                                *
 *******************************************************************************/
template<class Real>
Real Vector4<Real>::length() const
{
    return Math<Real>::Sqrt(x*x + y*y + z*z + w*w);
}

/********************************************************************************
 * Get the squared length of the vector.                                        *
 *******************************************************************************/
template<class Real>
Real Vector4<Real>::lengthSquared() const
{
    return (x*x + y*y + z*z + w*w);
}

/********************************************************************************
 * Normalize the vector.                                                        *
 *******************************************************************************/
template<class Real>
Vector4<Real>& Vector4<Real>::normalize()
{
    Real len = length();

    assert(len != (Real) 0.0);

    (*this) /= len;
    return *this;
}

/********************************************************************************
 * Allows one to write scalar * vector.                                         *
 *******************************************************************************/
template<class Real>
Vector4<Real> operator*(const Real& scalar, const Vector4<Real>& vec)
{
    return vec*scalar;
}

#ifdef DEBUG
/********************************************************************************
 * Print out the vector.                                                        *
 *******************************************************************************/
template<class Real>
void Vector4<Real>::print() const
{
    printf("\n[%g %g %g %g]\n\n", x, y, z, w);
}
#endif

/********************************************************************************
 * Makes it possible to write scalar*vec.                                       *
 *******************************************************************************/
template<class Real>
Vector4<Real> operator*(const Real scalar, const Vector4<Real>& vec)
{
    return vec*scalar;
}

/********************************************************************************
 * Comparison function.                                                         *
 *******************************************************************************/
template<class Real>
int Vector4<Real>::compare(const Vector4<Real>& vec) const
{
    return memcmp(&x, &vec.x, 4*sizeof(Real));
}
