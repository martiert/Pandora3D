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

#include "../include/PandoraVector4.hpp"

namespace Pandora
{
    template<> const Vector4<float> Vector4<float>::ZERO(0.0f, 0.0f, 0.0f, 
            0.0f);
    template<> const Vector4<float> Vector4<float>::UNIT_X(1.0f, 0.0f, 0.0f, 
            0.0f);
    template<> const Vector4<float> Vector4<float>::UNIT_Y(0.0f, 1.0f, 0.0f,
            0.0f);
    template<> const Vector4<float> Vector4<float>::UNIT_Z(0.0f, 0.0f, 1.0f,
            0.0f);
    template<> const Vector4<float> Vector4<float>::UNIT_W(0.0f, 0.0f, 0.0f,
            1.0f);

    template<> const Vector4<double> Vector4<double>::ZERO(0.0, 0.0, 0.0, 0.0);
    template<> const Vector4<double> Vector4<double>::UNIT_X(1.0, 0.0, 0.0, 
            0.0);
    template<> const Vector4<double> Vector4<double>::UNIT_Y(0.0, 1.0, 0.0, 
            0.0);
    template<> const Vector4<double> Vector4<double>::UNIT_Z(0.0, 0.0, 1.0,
            0.0);
    template<> const Vector4<double> Vector4<double>::UNIT_W(0.0, 0.0, 0.0,
            1.0);

//#############################################################################

    template<class Real>
    Vector4<Real>::Vector4(Real x, Real y, Real z, Real w)
    {
        m_data[0] = x;
        m_data[1] = y;
        m_data[2] = z;
        m_data[3] = w;
    }

//#############################################################################

    template<class Real>
    Vector4<Real>::Vector4(const Vector4<Real>& vector)
    {
        m_data[0] = vector[0];
        m_data[1] = vector[1];
        m_data[2] = vector[2];
        m_data[3] = vector[3];
    }

//#############################################################################

    template<class Real>
    Vector4<Real>::operator const Real*() const
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    Vector4<Real>::operator Real*()
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    const Real& Vector4<Real>::operator[](const int& i) const
    {
        assert(i >= 0 && i < 4);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    Real& Vector4<Real>::operator[](const int& i)
    {
        assert(i >= 0 && i < 4);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    int Vector4<Real>::compareVectors(const Vector4<Real>& vector) const
    {
        return memcmp(m_data, vector.m_data, 4*sizeof(Real));
    }

//#############################################################################

    template<class Real>
    bool Vector4<Real>::operator==(const Vector4<Real>& vector) const
    {
        return compareVectors(vector) == 0;
    }

//#############################################################################

    template<class Real>
    bool Vector4<Real>::operator!=(const Vector4<Real>& vector) const
    {
        return compareVectors(vector) != 0;
    }

//#############################################################################

    template<class Real>
    bool Vector4<Real>::operator<(const Vector4<Real>& vector) const
    {
        return compareVectors(vector) < 0;
    }

//#############################################################################

    template<class Real>
    bool Vector4<Real>::operator>(const Vector4<Real>& vector) const
    {
        return compareVectors(vector) > 0;
    }

//#############################################################################

    template<class Real>
    bool Vector4<Real>::operator<=(const Vector4<Real>& vector) const
    {
        return compareVectors(vector) <= 0;
    }

//#############################################################################

    template<class Real>
    bool Vector4<Real>::operator>=(const Vector4<Real>& vector) const
    {
        return compareVectors(vector) >= 0;
    }

//#############################################################################

    template<class Real>
    Vector4<Real> Vector4<Real>::operator+(const Vector4<Real>& vector) const
    {
        return Vector4<Real>(m_data[0] + vector[0], m_data[1] + vector[1],
                m_data[2] + vector[2], m_data[3] + vector[3]);
    }

//#############################################################################

    template<class Real>
    Vector4<Real> Vector4<Real>::operator-(const Vector4<Real>& vector) const
    {
        return Vector4<Real>(m_data[0] - vector[0], m_data[1] - vector[1],
                m_data[2] - vector[2], m_data[3] - vector[3]);
    }

//#############################################################################

    template<class Real>
    Vector4<Real> Vector4<Real>::operator*(const Real& scalar) const
    {
        return Vector4<Real>(m_data[0] * scalar, m_data[1] * scalar,
                m_data[2] * scalar, m_data[3] * scalar);
    }

//#############################################################################

    template<class Real>
    Vector4<Real> Vector4<Real>::operator/(const Real& scalar) const
    {
        return Vector4<Real>(m_data[0] / scalar, m_data[1] / scalar,
                m_data[2] / scalar, m_data[3] / scalar);
    }

//#############################################################################

    template<class Real>
    Vector4<Real> Vector4<Real>::operator-() const
    {
        return Vector4<Real>(-m_data[0], -m_data[1], -m_data[2], -m_data[3]);
    }

//#############################################################################

    template<class Real>
    void Vector4<Real>::operator+=(const Vector4<Real>& vector)
    {
        m_data[0] = vector[0];
        m_data[1] = vector[1];
        m_data[2] = vector[2];
        m_data[3] = vector[3];
    }

//#############################################################################

    template<class Real>
    void Vector4<Real>::operator-=(const Vector4<Real>& vector)
    {
        m_data[0] -= vector[0];
        m_data[1] -= vector[1];
        m_data[2] -= vector[2];
    }

//#############################################################################

    template<class Real>
    void Vector4<Real>::operator*=(const Real& scalar)
    {
        m_data[0] *= scalar;
        m_data[1] *= scalar;
        m_data[2] *= scalar;
        m_data[3] *= scalar;
    }

//#############################################################################

    template<class Real>
    void Vector4<Real>::operator/=(const Real& scalar)
    {
        m_data[0] /= scalar;
        m_data[1] /= scalar;
        m_data[2] /= scalar;
        m_data[3] /= scalar;
    }

//#############################################################################

    template<class Real>
    Real Vector4<Real>::operator*(const Vector4<Real>& vector) const
    {
        return m_data[0] * vector[0] + m_data[1] * vector[1] + 
            m_data[2] * vector[2] + m_data[3] * vector[3];
    }

//#############################################################################

    template<class Real>
    Real Vector4<Real>::length() const
    {
        return Math<Real>::Sqrt(m_data[0] * m_data[0] + m_data[1] * m_data[1] +
                m_data[2] * m_data[2] + m_data[3] * m_data[3]);
    }

//#############################################################################

    template<class Real>
    Real Vector4<real>::squaredLength() const
    {
        return m_data[0] * m_data[0] + m_data[1] * m_data[1] + 
            m_data[2] * m_data[2] + m_data[3] * m_data[3];
    }

//#############################################################################

    template<class Real>
    Real Vector4<Real>::normalize()
    {
        Real len = length();

        if(len > Math<Real>::EPSILON || len < -Math<Real>::EPSILON) {
            m_data[0] /= len;
            m_data[1] /= len;
            m_data[2] /= len;
            m_data[3] /= len;
            return len;
        }

        m_data[0] = m_data[1] = m_data[2] = m_data[3] = (Real) 0.0;
        return (Real) 0.0;
    }

//#############################################################################
}
