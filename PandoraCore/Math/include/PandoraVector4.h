/*
--------------------------------------------------------------------------------
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
--------------------------------------------------------------------------------
*/

#ifndef PANDORAVECTOR4_H
#define PANDORAVECTOR4_H

#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>

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
                Vector4(Real x = (Real) 1.0, Real y = (Real) 0.0, 
                        Real z = (Real) 0.0, Real w = (Real) 0.0);

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
                 */
                Vector4(Real vec[4]);

                /**
                 *  Destructor.
                 */
                ~Vector4();

                /**
                 *  Copy a vector to this vector.
                 *  \param
                 *      vec - The vector to copy from.
                 *  \return
                 *      This vector.
                 */
                Vector4& operator=(const Vector4& vec);

                /**
                 *  Get element number i from the vector.
                 *  \param
                 *      i - The index we should find.
                 *  \return
                 *      Element number i.
                 *  \note
                 *      If the index is larger then or equal to four, the 
                 *      program will crash.
                 */
                Real& operator[](const ptrdiff_t i);

                /**
                 *  Get the value of element number i from te vector.
                 *  \param
                 *      i - The index.
                 *  \return
                 *      The value of element number i.
                 *  \note
                 *      If the index is larger then or equal to four, the 
                 *      program will crash.
                 */
                Real operator[](const ptrdiff_t i) const;

                /**
                 *  Get the vector as an array. Implicit conversion.
                 *  \return
                 *      The vector as an array.
                 */
                operator Real *();

                /**
                 *  Get the vector as a constant array. Implicit conversion.
                 *  \return
                 *      The vector as a constant array.
                 */
                operator const Real *() const;

                /**
                 *  Negate a vector.
                 *  \return
                 *      The vector negated.
                 */
                Vector4 operator-() const;

                /**
                 *  Add two vectors.
                 *  \param
                 *      vec - The vector to add to this vector.
                 *  \return
                 *      A new vector which is the addition between this vector
                 *      and vec.
                 */
                Vector4 operator+(const Vector4& vec) const;

                /**
                 *  Subtract two vectors.
                 *  \param  
                 *      vec - The vector to subtract with.
                 *  \return
                 *      A new vector which is this vector subtracted by vec.
                 */
                Vector4 operator-(const Vector4& vec) const;

                /**
                 *  Multiply a vector with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      A new vector which is this vector multiplied by scalar.
                 */
                Vector4 operator*(const Real& scalar) const;

                /**
                 *  Divide a vector with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      A new vector which is this vector divided by scalar.
                 *  \note
                 *      Will only check for division by zero in DEBUG mode.
                 */
                Vector4 operator/(const Real& scalar) const;

                /**
                 *  Dot multiply two vectors.
                 *  \param
                 *      vec - The vector to dot multiply with.
                 *  \return
                 *      A scalar which is the two vector dot multiplied.
                 */
                Real operator*(const Vector4& vec) const;

                /**
                 *  Add a vector to this vector.
                 *  \param
                 *      vec - The vector to add to this vector.
                 *  \return
                 *      This vector.
                 */
                Vector4& operator+=(const Vector4& vec);

                /**
                 *  Subtract a vector from this vector.
                 *  \param
                 *      vec - The vector to subtract with.
                 *  \return
                 *      This vector.
                 */
                Vector4& operator-=(const Vector4& vec);

                /**
                 *  Multiply this vector with a scalar.
                 *  \param
                 *      scalar - The scalar to multiply with.
                 *  \return
                 *      This vector.
                 */
                Vector4& operator*=(const Real& scalar);

                /**
                 *  Divide this vector with a scalar.
                 *  \param
                 *      scalar - The scalar to divide with.
                 *  \return
                 *      This vector.
                 *  \note
                 *      Will only check for division by zero in DEBUG mode.
                 */
                Vector4& operator/=(const Real& scalar);

                /**
                 *  Check if two vectors are equal.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      True if all of the elements are equal, false otherwise.
                 */
                bool operator==(const Vector4& vec) const;

                /**
                 *  Check if two vectors are different.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      False if all of the elements are equal, true otherwise.
                 */
                bool operator!=(const Vector4& vec) const;

                /**
                 *  Check if this vector is less then another.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      True if the first different element is smaller then in
                 *      vec. False otherwise.
                 */
                bool operator<(const Vector4& vec) const;

                /**
                 *  Check if this vector is less then or equal to another.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      True if either < or == holds. False otherwise.
                 */
                bool operator<=(const Vector4& vec) const;

                /**
                 *  Check if this vector is larger then another.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      True if the first different element is larger then in
                 *      vec. False otherwise.
                 */
                bool operator>(const Vector4& vec) const;

                /**
                 *  Check if this vector is larger then or equal to another.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      True if > or == holds. False otherwise.
                 */
                bool operator>=(const Vector4& vec) const;

                /**
                 *  Get the length of the vector: Sqrt(x*x+y*y+z*z+w*w).
                 *  \return
                 *      The length of the vector.
                 */
                Real length() const;

                /**
                 *  Get the squared length of the vector.
                 *  \return 
                 *      The squared length of the vector.
                 */
                Real lengthSquared() const;

                /**
                 *  Normalize the vector.
                 *  \return 
                 *      This vector.
                 *  \note
                 *      Will only check for zero length in DEBUG mode.
                 */
                Vector4& normalize();

#ifdef DEBUG
                /**
                 * Print the vector. Only available in DEBUG mode.
                 */
                void print() const;
#endif //DEBUG
           protected:
                Real m_data[4];

                /**
                 *  Comparison function.
                 *  \param
                 *      vec - The vector to compare to.
                 *  \return
                 *      0 if equal, positive if this is larger and negative 
                 *      else.
                 */
                int compare(const Vector4<Real>& vec) const;
        };

        /**
         *  Makes it possible to write scalar*vec.
         *  \param
         *      scalar - The scalar.
         *  \param
         *      vec - The vector.
         *  \return
         *      scalar*vec.
         */
        template<class Real>
        Vector4<Real> operator*(const Real scalar, const Vector4<Real>& vec);

        /**
         *  Typedefs.
         */
        typedef Vector4<float>          Vec4f;
        typedef Vector4<double>         Vec4d;
        typedef Vector4<int>            Vec4i;
        typedef Vector4<unsigned int>   Vec4u;

/********************************************************************************
 * Default constructor.                                                         *
 *******************************************************************************/
template<class Real>
Vector4<Real>::Vector4(Real x, Real y, Real z, Real w)
{
    m_data[0] = x;
    m_data[1] = y;
    m_data[2] = z;
    m_data[3] = w;
}


/********************************************************************************
 * Copy constructor.                                                            *
 *******************************************************************************/
template<class Real>
Vector4<Real>::Vector4(Vector4<Real>& vec)
{
    memcpy(m_data, vec.m_data, 4*sizeof(Real));
}


/********************************************************************************
 * Copy an array to this vector.                                                *
 *******************************************************************************/
template<class Real>
Vector4<Real>::Vector4(Real vec[4])
{
    memcpy(m_data, vec, 4*sizeof(Real));
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
        memcpy(m_data, vec.m_data, 4*sizeof(Real));
    return *this;
}


/********************************************************************************
 * Get element number i from the vector.                                        *
 *******************************************************************************/
template<class Real>
Real& Vector4<Real>::operator[](const ptrdiff_t i)
{
    assert(i < 4 && "Index out of range");
    return m_data[i];
}


/********************************************************************************
 * Get value in element number i from the vector.                               *
 *******************************************************************************/
template<class Real>
Real Vector4<Real>::operator[](const ptrdiff_t i) const
{
    assert(i < 4 && "Index out of range");
    return m_data[i];
}


/********************************************************************************
 * Implicit conversion to array.                                                *
 *******************************************************************************/
template<class Real>
Vector4<Real>::operator Real *()
{
    return m_data;
}


/********************************************************************************
 * Implicit conversion to constant array.                                       *
 *******************************************************************************/
template<class Real>
Vector4<Real>::operator const Real *() const
{
    return m_data;
}


/********************************************************************************
 * Negate a vector.                                                             *
 *******************************************************************************/
template<class Real>
Vector4<Real> Vector4<Real>::operator-() const
{
    return Vector4<Real>(-m_data[0], -m_data[1], -m_data[2], -m_data[3]);
}


/********************************************************************************
 * Add two vectors.                                                             *
 *******************************************************************************/
template<class Real>
Vector4<Real> Vector4<Real>::operator+(const Vector4<Real>& vec) const
{
    return Vector4<Real>(m_data[0] + vec[0],
            m_data[1] + vec[1],
            m_data[2] + vec[2],
            m_data[3] + vec[3]);
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
    return Vector4<Real>(m_data[0]*scalar,
            m_data[1]*scalar,
            m_data[2]*scalar,
            m_data[3]*scalar);
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
    return (m_data[0]*vec[0] + m_data[1]*vec[1] + 
            m_data[2]*vec[2] + m_data[3]*vec[3]);
}


/********************************************************************************
 * Add a vector to this vector.                                                 *
 *******************************************************************************/
template<class Real>
Vector4<Real>& Vector4<Real>::operator+=(const Vector4<Real>& vec)
{
    m_data[0] += vec[0];
    m_data[1] += vec[1];
    m_data[2] += vec[2];
    m_data[3] += vec[3];
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
    m_data[0] *= scalar;
    m_data[1] *= scalar;
    m_data[2] *= scalar;
    m_data[3] *= scalar;
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
    return Math<Real>::Sqrt(m_data[0]*m_data[0] + m_data[1]*m_data[1] +
            m_data[2]*m_data[2] + m_data[3]*m_data[3]);
}


/********************************************************************************
 * Get the squared length of the vector.                                        *
 *******************************************************************************/
template<class Real>
Real Vector4<Real>::lengthSquared() const
{
    return (m_data[0]*m_data[0] + m_data[1]*m_data[1] + m_data[2]*m_data[2] +
            m_data[3]*m_data[3]);
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
    for(int i = 0; i < 4; i++) {
        if(Math<Real>::Abs(m_data[i] - vec[i]) >= Math<Real>::EPSILON) {
            if(m_data[i] > vec[i])
                return 1;
            return -1;
        }
    }       

    return 0;
}


#ifdef DEBUG
/********************************************************************************
 * Print out the vector.                                                        *
 *******************************************************************************/
template<class Real>
void Vector4<Real>::print() const
{
    printf("\n[%8.4f %8.4f %8.4f %8.4f]\n\n", m_data[0], m_data[1], m_data[2], m_data[3]);
}
#endif

    } //namespace Math
} //namespace Pandora
#endif //PANDORAVECTOR4_H
