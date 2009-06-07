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

#include "../include/PandoraVector2.hpp"

namespace Pandora
{
    template<> const Vector2<float> Vector2<float>::ZERO(0.0f, 0.0f);
    template<> const Vector2<float> Vector2<float>::UNIT_X(1.0f, 0.0f);
    template<> const Vector2<float> Vector2<float>::UNIT_Y(0.0f, 1.0f);

    template<> const Vector2<double> Vector2<double>::ZERO(0.0, 0.0);
    template<> const Vector2<double> Vector2<double>::UNIT_X(1.0, 0.0);
    template<> const Vector2<double> Vector2<double>::UNIT_Y(0.0, 1.0);

//#############################################################################

    template<class Real>
    Vector2<Real>::Vector2(Real x, Real y)
    {
        m_data[0] = x;
        m_data[1] = y;
    }

//#############################################################################

    template<class Real>
    Vector2<Real>::Vector2(const Vector2<Real>& vec)
    {
        m_data[0] = vec[0];
        m_data[1] = vec[1];
    }

//#############################################################################

    template<class Real>
    Vector2<Real>::~Vector2() { }

//#############################################################################

    template<class Real>
    Vector2<Real>::operator const Real*() const
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    Vector2<Real>::operator Real*()
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    const Real& Vector2<Real>::operator[](const int i) const
    {
        assert(i >= 0 && i < 2);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    Real& Vector2<Real>::operator[](const int i)
    {
        assert(i >= 0 && i < 2);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    int Vector2<Real>::compareVectors(const Vector2<Real>& vector)
    {
        return memcmp(m_data, vector.m_data, 2*sizeof(Real));
    }

//#############################################################################

    template<class Real>
    bool Vector2<Real>::operator==(const Vector2<Real>& vector) const
    {
        return compareVectors(vector) == 0;
    }

//#############################################################################

    template<class Real>
    bool Vector2<Real>::operator!=(const Vector2<Real>& vector) const
    {
        return compareVectors(vector) != 0;
    }

//#############################################################################

    template<class Real>
    bool Vector2<Real>::operator<(const Vector2<Real>& vector) const
    {
        return compareVectors(vector) < 0;
    }

//#############################################################################

    template<class Real>
    bool Vector2<Real>::operator>(const Vector2<Real>& vector) const
    {
        return compareVectors(vector) > 0;
    }

//#############################################################################

    template<class Real>
    bool Vector2<Real>::operator<=(const Vector2<Real>& vector) const
    {
        return compareVectors(vector) <= 0;
    }

//#############################################################################

    template<class Real>
    bool Vector2<Real>::operator>=(const Vector2<Real>& vector) const
    {
        return compareVectors(vector) >= 0;
    }

//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::operator+(const Vector2<Real>& vector) const
    {
        return Vector2<Real>(m_data[0] + vector[0], m_data[1] + vector[1]);
    }

//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::operator-(const Vector2<Real>& vector) const
    {
        return Vector2<Real>(m_data[0] - vector[0], m_data[1] - vector[1]);
    }

//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::operator*(const Real& scalar) const
    {
        return Vector2<Real>(m_data[0] * scalar, m_data[1] * scalar);
    }

//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::operator/(const Real& scalar) const
    {
        return Vector2<Real>(m_data[0] / scalar, m_data[1] / scalar);
    }

//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::operator-() const
    {
        return Vector2<Real>(-m_data[0], -m_data[1]);
    }

//#############################################################################

    template<class Real>
    void Vector2<Real>::operator+=(const Vector2<Real>& vector)
    {
        m_data[0] += vector[0];
        m_data[1] += vector[1];
    }

//#############################################################################

    template<class Real>
    void Vector2<Real>::operator-=(const Vector2<Real>& vector)
    {
        m_data[0] -= vector[0];
        m_data[1] -= vector[1];
    }

//#############################################################################

    template<class Real>
    void Vector2<Real>::operator*=(const Real& scalar)
    {
        m_data[0] *= scalar;
        m_data[1] *= scalar;
    }

//#############################################################################

    template<class Real>
    void Vector2<Real>::operator/=(const Real& scalar)
    {
        m_data[0] /= scalar;
        m_data[1] /= scalar;
    }

//#############################################################################

    template<class Real>
    Real Vector2<Real>::operator*(const Vector2& vector) const
    {
        return m_data[0] * vector[0] + m_data[1] * vector[1];
    }

//#############################################################################

    template<class Real>
    Real Vector2<Real>::length() const
    {
        return Math<Real>::Sqrt(m_data[0] * m_data[0] + m_data[1] * m_data[1]);
    }

//#############################################################################

    template<class Real>
    Real Vector2<Real>::squaredLength() const
    {
        return m_data[0] * m_data[0] + m_data[1] * m_data[1];
    }

//#############################################################################

    template<class Real>
    Real Vector2<Real>::normalize()
    {
        Real len = length();

        if(len > Math<Real>::EPSILON || len < -Math<Real>::EPSILON) {
            m_data[0] /= len;
            m_data[1] /= len;
        } else {
            len = (Real)0.0;
            m_data[0] = (Real) 1.0;
            m_data[1] = (Real) 0.0;
        }
        return len;
    }

//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::perp() const
    {
        return Vector2<Real>(m_data[1], -m_data[0]);
    }

//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::unitPerp() const
    {
        return (Vector2<Real>(m_data[1], -m_data[0]).normalize());
    }

//#############################################################################

    template<class Real>
    Real Vector2<Real>::dotPerp(const Vector2<Real>& vector) const
    {
        return m_data[0] * vector[1] - m_data[1] * vector[0];
    }

//#############################################################################

    template<class Real>
    void Vector2<Real>::orthonormalize(Vector2<Real>& v1, Vector2<Real>& v2)
    {
        v1 = v1.normalize();
        v2 = (v2 - (v1 * v2) * v1);
        v2 = v2.normalize();
    }

//#############################################################################
}
