/*
--------------------------------------------------------------------------------
File Name : PandoraVector2.inl

Purpose : Implementation of the Vector2 class used in Pandora3D

Creation Date : 2010-01-26

Last Modified : ti. 10. aug. 2010 kl. 15.14 +0200

Created By : Martin Ertsås
--------------------------------------------------------------------------------
*/

/********************************************************************************
 * Typedefs.                                                                    * 
 *******************************************************************************/ 
typedef Vector2<float> Vec2f;
typedef Vector2<double> Vec2d;
typedef Vector2<int> Vec2i;
typedef Vector2<unsigned int> Vec2u;

/********************************************************************************
 * Constructor.                                                                 * 
 *******************************************************************************/ 
template<class Real>
Vector2<Real>::Vector2(const Real& x, const Real& y)
{
    m_data[0] = x;
    m_data[1] = y;
}

/********************************************************************************
 * Constructor.                                                                 * 
 *******************************************************************************/ 
template<class Real>
Vector2<Real>::Vector2(Vector2<Real>& vec)
{
    memcpy(m_data, vec.m_data, 2*sizeof(Real));
}

/********************************************************************************
 * Constructor.                                                                 * 
 *******************************************************************************/ 
template<class Real>
Vector2<Real>::Vector2(Real vec[2])
{
    memcpy(m_data, vec, 2*sizeof(Real));
}

/********************************************************************************
 * Destructor.                                                                  * 
 *******************************************************************************/ 
template<class Real>
Vector2<Real>::~Vector2()
{
}

/********************************************************************************
 * Assignment operator.                                                         * 
 *******************************************************************************/ 
template<class Real>
Vector2<Real>& Vector2<Real>::operator=(const Vector2<Real>& vec)
{
    if(this != &vec)
        memcpy(m_data, vec.m_data, 2*sizeof(Real));
    return *this;
}

/********************************************************************************
 * Access operator.                                                             *
 *******************************************************************************/ 
template<class Real>
Real& Vector2<Real>::operator[](const ptrdiff_t i)
{
    assert(i < 2 && "Index out of bounds.");

    return m_data[i];
}

/********************************************************************************
 * Get a copy of element number i from the vector.                              *
 *******************************************************************************/
template<class Real>
Real Vector2<Real>::operator[](const ptrdiff_t i) const
{
    assert(i < 2 && "Index out of bounds.");

    return m_data[i];
}

/********************************************************************************
 * Implicit conversion operator.                                                *
 *******************************************************************************/ 
template<class Real>
Vector2<Real>::operator Real*()
{
    return m_data;
}

/********************************************************************************
 * Get a constant copy of the vector.                                           *
 *******************************************************************************/
template<class Real>
Vector2<Real>::operator const Real* () const
{
    return m_data;
}

/********************************************************************************
 * Addition operator.                                                           *
 *******************************************************************************/ 
template<class Real>
Vector2<Real> Vector2<Real>::operator+(const Vector2<Real>& vec) const
{
    return Vector2<Real>(m_data[0] + vec[0], m_data[1] + vec[1]);
}

/********************************************************************************
 * Subtraction operator.                                                        *
 *******************************************************************************/ 
template<class Real>
Vector2<Real> Vector2<Real>::operator-(const Vector2<Real>& vec) const
{
    return Vector2<Real>(m_data[0] - vec[0], m_data[1] - vec[1]);
}

/********************************************************************************
 * Normal vector multiplication.                                                *
 *******************************************************************************/ 
template<class Real>
Real Vector2<Real>::operator*(const Vector2<Real>& vec) const
{
    return m_data[0]*vec[0] + m_data[1]*vec[1];
}

/********************************************************************************
 * Multiply vector with a scalar.                                               *
 *******************************************************************************/
template<class Real>
Vector2<Real> Vector2<Real>::operator*(const Real& scalar) const
{
    return Vector2<Real>(m_data[0]*scalar, m_data[1]*scalar);
}

/********************************************************************************
 * Divide vector with a scalar.                                                 *
 *******************************************************************************/
template<class Real>
Vector2<Real> Vector2<Real>::operator/(const Real& scalar) const
{
    assert( scalar != (Real) 0.0 );
    Real s = ((Real) 1.0)/scalar;
    return (*this) * s;
}

/********************************************************************************
 * Addition operator.                                                           *
 *******************************************************************************/
template<class Real>
Vector2<Real>& Vector2<Real>::operator+=(const Vector2<Real>& vec)
{
    m_data[0] += vec[0];
    m_data[1] += vec[1];
    return *this;
}

/********************************************************************************
 * Subtraction operator.                                                        *
 *******************************************************************************/
template<class Real>
Vector2<Real>& Vector2<Real>::operator-=(const Vector2<Real>& vec)
{
    m_data[0] -= vec[0];
    m_data[1] -= vec[1];
    return *this;
}

/********************************************************************************
 * Multiplication with scalar.                                                  *
 *******************************************************************************/
template<class Real>
Vector2<Real>& Vector2<Real>::operator*=(const Real& scalar)
{
    m_data[0] *= scalar;
    m_data[1] *= scalar;
    return *this;
}

/********************************************************************************
 * Division with scalar.                                                        *
 *******************************************************************************/
template<class Real>
Vector2<Real>& Vector2<Real>::operator/=(const Real& scalar)
{
    assert( scalar != (Real) 0.0 );
    Real s = ((Real) 1.0)/scalar;
    (*this) *= s;
    return *this;
}

/********************************************************************************
 * Equality operator.                                                           *
 *******************************************************************************/
template<class Real>
bool Vector2<Real>::operator==(const Vector2<Real>& vec) const
{
    return compare(vec) == 0;
}

/********************************************************************************
 * Non equality operator.                                                       *
 *******************************************************************************/
template<class Real>
bool Vector2<Real>::operator!=(const Vector2<Real>& vec) const
{
    return compare(vec) != 0;
}

/********************************************************************************
 * Check if this vector is larger then another.                                 *
 *******************************************************************************/
template<class Real>
bool Vector2<Real>::operator>(const Vector2<Real>& vec) const
{
    return compare(vec) > 0;
}

/********************************************************************************
 * Check if this vector is larger then or equal to another.                     *
 *******************************************************************************/
template<class Real>
bool Vector2<Real>::operator>=(const Vector2<Real>& vec) const
{
    return compare(vec) >= 0;
}

/********************************************************************************
 * Check if this vector is smaller then another.                                *
 *******************************************************************************/
template<class Real>
bool Vector2<Real>::operator<(const Vector2<Real>& vec) const
{
    return compare(vec) < 0;
}

/********************************************************************************
 * Check if this vector is smaller then or equal to another.                    *
 *******************************************************************************/
template<class Real>
bool Vector2<Real>::operator<=(const Vector2<Real>& vec) const
{
    return compare(vec) <= 0;
}

/********************************************************************************
 * Negate a vector.                                                             *
 *******************************************************************************/
template<class Real>
Vector2<Real> Vector2<Real>::operator-() const
{
    return Vector2<Real>(-m_data[0], -m_data[1]);
}

/********************************************************************************
 * Dot product between two vectors.                                             *
 *******************************************************************************/
template<class Real>
Vector2<Real> Vector2<Real>::dotprod(const Vector2<Real>& vec) const
{
    return Vector2<Real>(m_data[0]*vec[0], m_data[1]*vec[1]);
}

/********************************************************************************
 * Return length of the vector.                                                 *
 *******************************************************************************/
template<class Real>
Real Vector2<Real>::length() const
{
    return Math<Real>::Sqrt(m_data[0]*m_data[0] + m_data[1]*m_data[1]);
}

/********************************************************************************
 * Return squared length of the vector.                                         *
 *******************************************************************************/
template<class Real>
Real Vector2<Real>::lengthSquared() const
{
    return (m_data[0]*m_data[0] + m_data[1]*m_data[1]);
}

/********************************************************************************
 * Normalize the vector.                                                        *
 *******************************************************************************/
template<class Real>
Vector2<Real>& Vector2<Real>::normalize()
{
    Real scale = length();

    assert(scale != (Real) 0.0);

    *this /= scale;
    return *this;
}

/********************************************************************************
 * Allows one to write scalar * vector.                                         *
 *******************************************************************************/
template<class Real>
Vector2<Real> operator*(const Real& scalar, const Vector2<Real>& vec)
{
    return vec * scalar;
}

#ifdef DEBUG
/********************************************************************************
 * Print out the vector.                                                        *
 *******************************************************************************/
template<class Real>
void Vector2<Real>::print() const
{
    printf("\n[%8.4f %8.4f]\n\n", m_data[0], m_data[1]);
}
#endif

/********************************************************************************
 * Makes it possible to write scalar * vec.                                     *
 *******************************************************************************/
template<class Real>
Vector2<Real> operator*(const Real scalar, const Vector2<Real>& vec)
{
    return vec * scalar;
}

/********************************************************************************
 * Compare two vectors.                                                         *
 *******************************************************************************/
template<class Real>
int Vector2<Real>::compare(const Vector2<Real>& vec) const
{
    for(int i = 0; i < 2; i++) {
        if(Math<Real>::Abs(m_data[i] - vec[i]) >= Math<Real>::EPSILON) {
            if(m_data[i] > vec[i])
                return 1;
            return -1;
        }
    }

    return 0;
}
