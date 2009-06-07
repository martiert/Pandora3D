/*
 * ----------------------------------------------------------------------------
 * This source file is part of Pandora3D. For information, see 
 * http://Pandora3D.sourceforge.net.
 *
 * Copyright (c) 2009 Martin Ertsås
 *
 * This program is free software. You can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the license, or any later version.
 *
 * This program is distributed in hope that it will be useful, but WITHOUT ANY 
 * WARRANTY.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston MA 02111-1307, USA, or go to:
 *
 * http://www.gnu.org/licenses/#GPL
 * ----------------------------------------------------------------------------
 */

#include "../include/PandoraVector3.hpp"

namespace Pandora
{
    template<> const Vector3<float> Vector3<float>::ZERO(0.0f, 0.0f, 0.0f);
    template<> const Vector3<float> Vector3<float>::UNIT_X(1.0f, 0.0f, 0.0f);
    template<> const Vector3<float> Vector3<float>::UNIT_Y(0.0f, 1.0f, 0.0f);
    template<> const Vector3<float> Vector3<float>::UNIT_Z(0.0f, 0.0f, 1.0f);

    template<> const Vector3<double> Vector3<double>::ZERO(0.0, 0.0, 0.0);
    template<> const Vector3<double> Vector3<double>::UNIT_X(1.0, 0.0, 0.0);
    template<> const Vector3<double> Vector3<double>::UNIT_Y(0.0, 1.0, 0.0);
    template<> const Vector3<double> Vector3<double>::UNIT_Z(0.0, 0.0, 1.0);

//#############################################################################

    template<class Real>
    Vector3<Real>::Vector3(Real x, Real y, Real z)
    {
        m_data[0] = x;
        m_data[1] = y;
        m_data[2] = z;
    }

//#############################################################################

    template<class Real>
    Vector3<Real>::Vector3(const Vector3<Real>& vector)
    {
        m_data[0] = vector[0];
        m_data[1] = vector[1];
        m_data[2] = vector[2];
    }

//#############################################################################

    template<class Real>       
    Vector3<Real>::operator const Real*() const
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    Vector3<Real>::operator Real*()
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    const Real& Vector3<Real>::operator[](const int i) const
    {
        assert(i < 3 && i >= 0);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    Real& Vector3<Real>::operator[](const int i)
    {
        assert(i < 3 && i >= 0);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    int Vector3<Real>::compareVectors(const Vector3& vector) const
    {
        return memcmp(m_data, vector.m_data, 3*sizeof(Real));
    }

//#############################################################################

    template<class Real>
    bool Vector3<Real>::operator==(const Vector3& vector) const
    {
        return compareVectors(vector) == 0;
    }

//#############################################################################

    template<class Real>
    bool Vector3<Real>::operator!=(const Vector3& vector) const
    {
        return compareVectors(vector) != 0;
    }

//#############################################################################

    template<class Real>
    bool Vector3<Real>::operator<(const Vector3& vector) const
    {
        return compareVectors(vector) < 0;
    }

//#############################################################################

    template<class Real>
    bool Vector3<Real>::operator>(const Vector3& vector) const
    {
        return compareVectors(vector) > 0;
    }

//#############################################################################

    template<class Real>
    bool Vector3<Real>::operator<=(const Vector3& vector) const
    {
        return compareVectors(vector) <= 0;
    }

//#############################################################################

    template<class Real>
    bool Vector3<Real>::operator>=(const Vector3& vector) const
    {
        return compareVectors(vector) >= 0;
    }

//#############################################################################

    template<class Real>
    Vector3<Real> Vector3<Real>::operator+(const Vector3& vector) const
    {
        return Vector3(m_data[0] + vector[0], m_data[1] + vector[1], 
                m_data[2] + vector[2]);
    }

//#############################################################################

    template<class Real>
    Vector3<Real> Vector3<Real>::operator-(const Vector3& vector) const
    {
        return Vector3(m_data[0] - vector[0], m_data[1] - vector[1],
                m_data[2] - vector[2]);
    }

//#############################################################################

    template<class Real>
    Vector3<Real> Vector3<Real>::operator*(const Real& scalar) const
    {
        return Vector3(m_data[0] * scalar, m_data[1] * scalar,
                m_data[2] * scalar);
    }

//#############################################################################

    template<class Real>
    Vector3<Real> Vector3<Real>::operator/(const Real& scalar) const
    {
        return Vector3(m_data[0] / scalar, m_data[1] / scalar,
                m_data[2] / scalar);
    }

//#############################################################################

    template<class Real>
    Vector3<Real> Vector3<Real>::operator-() const
    {
        return Vector3(-m_data[0], -m_data[1], -m_data[2]);
    }

//#############################################################################

    template<class Real>
    void Vector3<Real>::operator+=(const Vector3<Real>& vector)
    {
        m_data[0] += vector[0];
        m_data[1] += vector[1];
        m_data[2] += vector[2];
    }

//#############################################################################

    template<class Real>
    void Vector3<Real>::operator-=(const Vector3<Real>& vector)
    {
        m_data[0] -= vector[0];
        m_data[1] -= vector[1];
        m_data[2] -= vector[2];
    }

//#############################################################################

    template<class Real>
    void Vector3<Real>::operator*=(const Real& scalar)
    {
        m_data[0] *= scalar;
        m_data[1] *= scalar;
        m_data[2] *= scalar;
    }

//#############################################################################

    template<class Real>
    void Vector3<Real>::operator/=(const Real& scalar)
    {
        m_data[0] /= scalar;
        m_data[1] /= scalar;
        m_data[2] /= scalar;
    }

//#############################################################################

    template<class Real>
    Real Vector3<Real>::operator*(const Vector3<Real>& vector) const
    {
        return (m_data[0]*vector[0] + m_data[1]*vector[1] + 
                m_data[2]*vector[2]);
    }

//#############################################################################

    template<class Real>
    Real Vector3<Real>::length() const
    {
        return Math<Real>::Sqrt(m_data[0]*m_data[0] + m_data[1]*m_data[1] +
                m_data[2] * m_data[2]);
    }

//#############################################################################

    template<class Real>
    Real Vector3<Real>::squaredLength() const
    {
        return m_data[0]*m_data[0] + m_data[1]*m_data[1] + m_data[2]*m_data[2];
    }

//#############################################################################

    template<class Real>
    Real Vector3<Real>::normalize() 
    {
        Real len = length();

        if(len > Math<Real>::EPSILON || len < -Math<Real>::EPSILON) {
            m_data[0] /= len;
            m_data[1] /= len;
            m_data[2] /= len;
        } else {
            len = (Real) 0.0;
            m_data[0] = m_data[1] = m_data[2] = (Real) 0.0;
        }

        return len;
    }

//#############################################################################

    template<class Real>
    Vector3<Real> Vector3<Real>::cross(const Vector3<Real>& vector) const
    {
        Real x = m_data[1]*vector[2] - m_data[2]*vector[1];
        Real y = m_data[0]*vector[2] - m_data[2]*vector[0];
        Real z = m_data[0]*vector[1] - m_data[1]*vector[0];
        return Vector3(x, y, z);
    }

//#############################################################################
}
