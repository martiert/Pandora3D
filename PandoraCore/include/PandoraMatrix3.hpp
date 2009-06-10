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

#ifndef _MATRIX3_HPP_
#define _MATRIX3_HPP_

#include "PandoraSystem.hpp"
#include "PandoraVector3.hpp"

namespace Pandora
{
    template<class Real>
    class Matrix3
    {
        public:
            //Constructors
            Matrix3(bool zero);
            Matrix3(Matrix3& matrix);
            Matrix3(Real data[9]);
            ~Matrix3();

            //Assignment operators
            operator const Real*() const;
            operator Real*();
            const Real& operator[](const int i) const;
            Real& operator[](const int i);
            const Real& operator()(const int row, const int col) const;
            Real& operator()(const int row, const int column);
            void operator=(const Matrix3& matrix);

            //Comparison operators
            bool operator==(const Matrix3& matrix) const;
            bool operator!=(const Matrix3& matrix) const;
            bool operator<(const Matrix3& matrix) const;
            bool operator>(const Matrix3& matrix) const;
            bool operator<=(const Matrix3& matrix) const;
            bool operator>=(const Matrix3& matrix) const;

            //Arithmetic operators
            //Matrix-Matrix operators
            Matrix3 operator+(const Matrix3& matrix) const;
            Matrix3 operator-(const Matrix3& matrix) const;
            Matrix3 operator*(const Matrix3& matrix) const;

            Matrix3 operator-() const;

            //Matrix-Vector operators
            Vector3<Real> operator*(const Vector3<Real>& vector) const;

            //Matrix-scalar operators
            Matrix3 operator*(const Real& scalar) const;
            Matrix3 operator/(const Real& scalar) const;

            Matrix3 transposeTimes(const Matrix3& matrix) const;
            Matrix3 timesTranspose(const Matrix3& matrix) const;

            //Operators on this matrix
            void operator+=(const Matrix3& matrix);
            void operator-=(const Matrix3& matrix);
            void operator*=(const Real& scalar);
            void operator/=(const Real& scalar);

            //Geometrical operations
            Real determinant() const;
            Matrix3 transpose() const;
            Matrix3 adjugate() const;
            Matrix3 inverse() const;
            Real trace() const;

            void toAxisAngle(Vector3<Real>& axis, Real& angle) const;
            void fromAxisAngle(const Vector3<Real>& axis, const Real& angle);
            
            //Using the angles: E(h,p,r) = Rz(r)Rx(p)Ry(h)
            void fromEulerAngle(const Real head, const Real pitch, 
                    const Real roll);
            bool toEulerAngle(Real& head, Real& pitch, Real& roll) const;

            static Matrix3 slerp(const Real t, const Matrix3& r0, 
                    const Matrix3& r1);

            static const Matrix3 ZERO;
            static const Matrix3 IDENTITY;
        protected:
            Real m_data[9];
            int compareMatrix(const Matrix3& matrix) const;
    };

    template<> const Matrix3<float> Matrix3<float>::ZERO(true);
    template<> const Matrix3<float> Matrix3<float>::IDENTITY(false);
    template<> const Matrix3<double> Matrix3<double>::ZERO(true);
    template<> const Matrix3<double> Matrix3<double>::IDENTITY(false);

//#############################################################################

    template<class Real>
    Matrix3<Real>::Matrix3(bool zero)
    {
        m_data[0] = m_data[1] = m_data[2] = m_data[3] = m_data[4] = m_data[5] =
            m_data[6] = m_data[7] = m_data[8] = (Real) 0.0;

        if(!zero)
            m_data[0] = m_data[4] = m_data[8] = (Real) 1.0;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real>::Matrix3(Matrix3& matrix)
    {
        m_data[0] = matrix[0];
        m_data[1] = matrix[1];
        m_data[2] = matrix[2];
        m_data[3] = matrix[3];
        m_data[4] = matrix[4];
        m_data[5] = matrix[5];
        m_data[6] = matrix[6];
        m_data[7] = matrix[7];
        m_data[8] = matrix[8];
    }

//#############################################################################

    template<class Real>
    Matrix3<Real>::Matrix3(Real data[9])
    {
        m_data[0] = data[0];
        m_data[1] = data[1];
        m_data[2] = data[2];
        m_data[3] = data[3];
        m_data[4] = data[4];
        m_data[5] = data[5];
        m_data[6] = data[6];
        m_data[7] = data[7];
        m_data[8] = data[8];
    }

//#############################################################################

    template<class Real>
    Matrix3<Real>::~Matrix3() { }

//#############################################################################

    template<class Real>
    Matrix3<Real>::operator const Real*() const
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    Matrix3<Real>::operator Real*()
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    const Real& Matrix3<Real>::operator[](const int i) const
    {
        assert(i < 9 && i >= 0);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    Real& Matrix3<Real>::operator[](const int i)
    {
        assert(i < 9 && i >= 0);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    const Real& Matrix3<Real>::operator()(const int row, const int col) const
    {
        assert(row >= 0 && col >= 0 && row < 3 && col < 3);
        return m_data[col + 3*row];
    }

//#############################################################################

    template<class Real>
    Real& Matrix3<Real>::operator()(const int row, const int col)
    {
        assert(row >= 0 && col >= 0 && row < 3 && col < 3);
        return m_data[col + 3*row];
    }

//#############################################################################

    template<class Real>
    void Matrix3<Real>::operator=(const Matrix3<Real>& matrix)
    {
        m_data[0] = matrix[0];
        m_data[1] = matrix[1];
        m_data[2] = matrix[2];
        m_data[3] = matrix[3];
        m_data[4] = matrix[4];
        m_data[5] = matrix[5];
        m_data[6] = matrix[6];
        m_data[7] = matrix[7];
        m_data[8] = matrix[8];
    }

//#############################################################################

    template<class Real>
    int Matrix3<Real>::compareMatrix(const Matrix3<Real>& matrix) const
    {
        return memcmp(m_data, matrix.m_data, 9*sizeof(Real));
    }

//#############################################################################

    template<class Real>
    bool Matrix3<Real>::operator==(const Matrix3<Real>& matrix) const
    {
        return compareMatrix(matrix) == 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix3<Real>::operator!=(const Matrix3<Real>& matrix) const
    {
        return compareMatrix(matrix) != 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix3<Real>::operator<(const Matrix3<Real>& matrix) const
    {
        return compareMatrix(matrix) < 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix3<Real>::operator>(const Matrix3<Real>& matrix) const
    {
        return compareMatrix(matrix) > 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix3<Real>::operator<=(const Matrix3<Real>& matrix) const
    {
        return compareMatrix(matrix) <= 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix3<Real>::operator>=(const Matrix3<Real>& matrix) const
    {
        return compareMatrix(matrix) >= 0;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::operator+(const Matrix3<Real>& matrix) const
    {
        Matrix3<Real> tmp(true);
        tmp[0] = m_data[0] + matrix[0];
        tmp[1] = m_data[1] + matrix[1];
        tmp[2] = m_data[2] + matrix[2];
        tmp[3] = m_data[3] + matrix[3];
        tmp[4] = m_data[4] + matrix[4];
        tmp[5] = m_data[5] + matrix[5];
        tmp[6] = m_data[6] + matrix[6];
        tmp[7] = m_data[7] + matrix[7];
        tmp[8] = m_data[8] + matrix[8];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::operator-(const Matrix3<Real>& matrix) const
    {
        Matrix3<Real> tmp(true);
        tmp[0] = m_data[0] - matrix[0];
        tmp[1] = m_data[1] - matrix[1];
        tmp[2] = m_data[2] - matrix[2];
        tmp[3] = m_data[3] - matrix[3];
        tmp[4] = m_data[4] - matrix[4];
        tmp[5] = m_data[5] - matrix[5];
        tmp[6] = m_data[6] - matrix[6];
        tmp[7] = m_data[7] - matrix[7];
        tmp[8] = m_data[8] - matrix[8];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::operator*(const Matrix3<Real>& matrix) const
    {
        Matrix3<Real> tmp(true);
        tmp[0] = m_data[0]*matrix[0] + m_data[1]*matrix[3] + 
            m_data[2]*matrix[6];
        tmp[1] = m_data[0]*matrix[1] + m_data[1]*matrix[4] + 
            m_data[2]*matrix[7];
        tmp[2] = m_data[0]*matrix[2] + m_data[1]*matrix[5] +
            m_data[2]*matrix[8];
        tmp[3] = m_data[3]*matrix[0] + m_data[4]*matrix[3] +
            m_data[5]*matrix[6];
        tmp[4] = m_data[3]*matrix[1] + m_data[4]*matrix[4] +
            m_data[5]*matrix[7];
        tmp[5] = m_data[3]*matrix[2] + m_data[4]*matrix[5] +
            m_data[5]*matrix[8];
        tmp[6] = m_data[6]*matrix[0] + m_data[7]*matrix[3] +
            m_data[8]*matrix[6];
        tmp[7] = m_data[6]*matrix[1] + m_data[7]*matrix[4] +
            m_data[8]*matrix[7];
        tmp[8] = m_data[6]*matrix[2] + m_data[7]*matrix[5] +
            m_data[8]*matrix[8];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::operator-() const
    {
        Matrix3<Real> tmp(true);
        tmp[0] = -m_data[0];
        tmp[1] = -m_data[1];
        tmp[2] = -m_data[2];
        tmp[3] = -m_data[3];
        tmp[4] = -m_data[4];
        tmp[5] = -m_data[5];
        tmp[6] = -m_data[6];
        tmp[7] = -m_data[7];
        tmp[8] = -m_data[8];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Vector3<Real> Matrix3<Real>::operator*(const Vector3<Real>& vector) const
    {
        Vector3<Real> tmp;
        tmp[0] = m_data[0]*vector[0] + m_data[1]*vector[1] + 
            m_data[2]*vector[2];
        tmp[1] = m_data[3]*vector[0] + m_data[4]*vector[1] +
            m_data[5]*vector[2];
        tmp[2] = m_data[6]*vector[0] + m_data[7]*vector[1] +
            m_data[8]*vector[2];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::operator*(const Real& scalar) const
    {
        Matrix3<Real> tmp(true);
        tmp[0] = m_data[0] * scalar;
        tmp[1] = m_data[1] * scalar;
        tmp[2] = m_data[2] * scalar;
        tmp[3] = m_data[3] * scalar;
        tmp[4] = m_data[4] * scalar;
        tmp[5] = m_data[5] * scalar;
        tmp[6] = m_data[6] * scalar;
        tmp[7] = m_data[7] * scalar;
        tmp[8] = m_data[8] * scalar;
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::operator/(const Real& scalar) const
    {
        assert(scalar > Math<Real>::EPSILON || scalar < -Math<Real>::EPSILON);
        Real s = 1 / scalar;
        Matrix3<Real> tmp(true);
        tmp[0] = m_data[0] * s;
        tmp[1] = m_data[1] * s;
        tmp[2] = m_data[2] * s;
        tmp[3] = m_data[3] * s;
        tmp[4] = m_data[4] * s;
        tmp[5] = m_data[5] * s;
        tmp[6] = m_data[6] * s;
        tmp[7] = m_data[7] * s;
        tmp[8] = m_data[8] * s;
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::transposeTimes(const Matrix3<Real>& matrix) 
    const
    {
        return transpose() * matrix;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::timesTranspose(const Matrix3<Real>& matrix)
    const
    {
        return *this * matrix.transpose();
    }

//#############################################################################

    template<class Real>
    void Matrix3<Real>::operator+=(const Matrix3<Real>& matrix)
    {
        m_data[0] += matrix[0];
        m_data[1] += matrix[1];
        m_data[2] += matrix[2];
        m_data[3] += matrix[3];
        m_data[4] += matrix[4];
        m_data[5] += matrix[5];
        m_data[6] += matrix[6];
        m_data[7] += matrix[7];
        m_data[8] += matrix[8];
    }

//#############################################################################

    template<class Real>
    void Matrix3<Real>::operator-=(const Matrix3<Real>& matrix)
    {
        m_data[0] -= matrix[0];
        m_data[1] -= matrix[1];
        m_data[2] -= matrix[2];
        m_data[3] -= matrix[3];
        m_data[4] -= matrix[4];
        m_data[5] -= matrix[5];
        m_data[6] -= matrix[6];
        m_data[7] -= matrix[7];
        m_data[8] -= matrix[8];
    }

//#############################################################################

    template<class Real>
    void Matrix3<Real>::operator*=(const Real& scalar)
    {
        m_data[0] *= scalar;
        m_data[1] *= scalar;
        m_data[2] *= scalar;
        m_data[3] *= scalar;
        m_data[4] *= scalar;
        m_data[5] *= scalar;
        m_data[6] *= scalar;
        m_data[7] *= scalar;
        m_data[8] *= scalar;
    }

//#############################################################################

    template<class Real>
    void Matrix3<Real>::operator/=(const Real& scalar)
    {
        assert(scalar > Math<Real>::EPSILON || scalar < -Math<Real>::EPSILON);
        Real s = 1 / scalar;
        m_data[0] *= s;
        m_data[1] *= s;
        m_data[2] *= s;
        m_data[3] *= s;
        m_data[4] *= s;
        m_data[5] *= s;
        m_data[6] *= s;
        m_data[7] *= s;
        m_data[8] *= s;
    }

//#############################################################################

    template<class Real>
    Real Matrix3<Real>::determinant() const
    {
        Real det = m_data[3]*m_data[4]*m_data[8] - 
            m_data[0]*m_data[5]*m_data[7] - m_data[1]*m_data[3]*m_data[8] +
            m_data[1]*m_data[5]*m_data[6] + m_data[2]*m_data[3]*m_data[7] -
            m_data[2]*m_data[4]*m_data[6];
        return det;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::transpose() const
    {
        Matrix3<Real> tmp(true);
        tmp[0] = m_data[0];
        tmp[1] = m_data[3];
        tmp[2] = m_data[6];
        tmp[3] = m_data[1];
        tmp[4] = m_data[4];
        tmp[5] = m_data[7];
        tmp[6] = m_data[2];
        tmp[7] = m_data[5];
        tmp[8] = m_data[8];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::adjugate() const
    {
        Matrix3<Real> tmp(true);
        tmp[0] = m_data[4]*m_data[8] - m_data[5]*m_data[7];
        tmp[1] = m_data[2]*m_data[7] - m_data[1]*m_data[8];
        tmp[2] = m_data[1]*m_data[5] - m_data[2]*m_data[4];
        tmp[3] = m_data[5]*m_data[6] - m_data[3]*m_data[8];
        tmp[4] = m_data[0]*m_data[8] - m_data[2]*m_data[6];
        tmp[5] = m_data[2]*m_data[3] - m_data[0]*m_data[5];
        tmp[6] = m_data[3]*m_data[7] - m_data[4]*m_data[6];
        tmp[7] = m_data[1]*m_data[6] - m_data[0]*m_data[7];
        tmp[8] = m_data[0]*m_data[4] - m_data[1]*m_data[3];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::inverse() const
    {
        Real det = determinant();
        assert(det > Math<Real>::EPSILON || det < -Math<Real>::EPSILON);

        if(det < Math<Real>::EOPSILON && det > -Math<Real>::EPSILON)
            return ZERO;

        return adjugate() / det;
    }

//#############################################################################

    template<class Real>
    Real Matrix3<Real>::trace() const
    {
        return m_data[0] + m_data[4] + m_data[8];
    }

//#############################################################################

    template<class Real>
    void Matrix3<Real>::toAxisAngle(Vector3<Real>& axis, Real& angle) const
    {
        angle = Acos((trace() - 1) * 0.5);
        if(angle == 0) {
            axis[0] = (Real) 1.0;
            axis[1] = (Real) 0.0;
            axis[2] = (Real) 0.0;
        } else {
            axis[0] = (m_data[7] - m_data[5]) / (2 * Sin(angle));
            axis[1] = (m_data[2] - m_data[6]) / (2 * Sin(angle));
            axis[2] = (m_data[3] - m_data[1]) / (2 * Sin(angle));
        }
    }

//#############################################################################

    template<class Real>
    void Matrix3<Real>::fromAxisAngle(const Vector3<Real>& axis, 
            const Real& angle)
    {
        Matrix3<Real> skew(true);
        skew[1] = -axis[2];
        skew[2] = axis[1];
        skew[5] = -axis[0];
        skew[3] = -skew[1];
        skew[6] = -skew[2];
        skew[7] = -skew[5];
        *this = IDENTITY + Sin(angle)*skew + (1 - Cos(angle))*skew*skew;
    }

//#############################################################################

    template<class Real>
    void Matrix3<Real>::fromEulerAngle(const Real head, const Real pitch, 
            const Real roll)
    {
        Matrix3<Real> rx(true);
        rx.fromAxisAngle(Vector3<Real>::UNIT_X, pitch);
        Matrix3<Real> ry(true);
        ry.fromAxisAngle(Vector3<Real>::UNIT_Y, head);
        Matrix3<Real> rz(true);
        rz.fromAxisAngle(Vector3<Real>::UNIT_Z, roll);
        *this = rz * rx * ry;
    }

//#############################################################################

    template<class Real>
    bool Matrix3<Real>::toEulerAngle(Real& head, Real& pitch, Real& roll) const
    {
        if(m_data[1] < Math<Real>::EPSILON && m_data[1] > -Math<Real>::EPSILON)
            return false;

        head = Atan2(-m_data[6], m_data[8]);
        pitch = Asin(m_data[7]);
        roll = Atan2(-m_data[1], m_data[4]);
        return true;
    }

//#############################################################################

    template<class Real>
    Matrix3<Real> Matrix3<Real>::slerp(const Real t, const Matrix3<Real>& r0,
            const Matrix3<Real>& r1)
    {
        Matrix3<Real> tmp = r0.transposeTimes(r1);
        Vector3<Real> axis;
        Real angle;
        tmp.toAxisAngle(&axis, &angle);
        angle *= t;
        tmp.fromAxisAngle(axis, angle);
        return tmp * r0;
    }

//#############################################################################
}
#endif
