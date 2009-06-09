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

#include "../include/PandoraMatrix4.hpp"

namespace Pandora
{
    template<> const Matrix4<float> Matrix4<float>::ZERO(true);
    template<> const Matrix4<float> Matrix4<float>::IDENTITY(false);
    template<> const Matrix4<double> Matrix4<double>::ZERO(true);
    template<> const Matrix4<double> Matrix4<double>::IDENTITY(false);

//#############################################################################

    template<class Real>
    Matrix4<Real>::Matrix4(bool zero)
    {
        m_data[0] = m_data[1] = m_data[2] = m_data[3] = m_data[4] = m_data[5] =
            m_data[6] = m_data[7] = m_data[8] = m_data[9] = m_data[10] =
            m_data[11] = m_data[12] = m_data[13] = m_data[14] = m_data[15] =
            (Real) 0.0;

        if(!zero)
            m_data[0] = m_data[5] = m_data[10] = m_data[15];
    }

//#############################################################################

    template<class Real>
    Matrix4<Real>::Matrix4(Matrix4<Real>& matrix)
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
        m_data[9] = matrix[9];
        m_data[10] = matrix[10];
        m_data[11] = matrix[11];
        m_data[12] = matrix[12];
        m_data[13] = matrix[13];
        m_data[14] = matrix[14];
        m_data[15] = matrix[15];
    }

//#############################################################################

    template<class Real>
    Matrix4<Real>::Matrix4(Real data[16])
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
        m_data[9] = data[9];
        m_data[10] = data[10];
        m_data[11] = data[11];
        m_data[12] = data[12];
        m_data[13] = data[13];
        m_data[14] = data[14];
        m_data[15] = data[15];
    }

//#############################################################################

    template<class Real>
    Matrix4<Real>::~Matrix4() { }

//#############################################################################

    template<class Real>
    Matrix4<Real>::operator const Real*() const
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    Matrix4<Real>::operator Real*()
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    const Real& Matrix4<Real>::operator[](const int i) const
    {
        assert(i >= 0 && i < 16);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    Real& Matrix4<Real>::operator[](const int i)
    {
        assert(i >= 0 && i < 16);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    const Real& Matrix4<Real>::operator()(const int row, const int col) const
    {
        assert(row >= 0 && col >= 0 && row < 4 && col < 4);
        return m_data[col + row*4];
    }

//#############################################################################

    template<class Real>
    Real& Matrix4<Real>::operator()(const int row, const int col)
    {
        assert(row >= 0 && col >= 0 && row < 4 && col < 4);
        return m_data[col + row*4];
    }

//#############################################################################

    template<class Real>
    void Matrix4<Real>::operator=(const Matrix4<Real>& matrix)
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
        m_data[9] = matrix[9];
        m_data[10] = matrix[10];
        m_data[11] = matrix[11];
        m_data[12] = matrix[12];
        m_data[13] = matrix[13];
        m_data[14] = matrix[14];
        m_data[15] = matrix[15];
    }

//#############################################################################

    template<class Real>
    int Matrix4<Real>::compareMatrix(const Matrix4<Real>& matrix) const
    {
        return memcmp(m_data, matrix.m_data, 16*sizeof(Real));
    }

//#############################################################################

    template<class Real>
    bool Matrix4<Real>::operator==(const Matrix4<Real>& matrix) const
    {
        return compareMatrix(matrix) == 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix4<Real>::operator!=(const Matrix4<Real>& matrix) const
    {
        return compareMatrix(matrix) != 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix4<Real>::operator<(const Matrix4<Real>& matrix) const
    {
        return compareMatrix(matrix) < 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix4<Real>::operator>(const Matrix4<Real>& matrix) const
    {
        return compareMatrix(matrix) > 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix4<Real>::operator<=(const Matrix4<Real>& matrix) const
    {
        return compareMatrix(matrix) <= 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix4<Real>::operator>=(const Matrix4<Real>& matrix) const
    {
        return compareMatrix(matrix) >= 0;
    }

//#############################################################################

    template<class Real>
    Matrix4<Real> Matrix4<Real>::operator+(const Matrix4<Real>& matrix) const
    {
        Matrix4<Real> tmp(true);
        tmp[0] = m_data[0] + matrix[0];
        tmp[1] = m_data[1] + matrix[1];
        tmp[2] = m_data[2] + matrix[2];
        tmp[3] = m_data[3] + matrix[3];
        tmp[4] = m_data[4] + matrix[4];
        tmp[5] = m_data[5] + matrix[5];
        tmp[6] = m_data[6] + matrix[6];
        tmp[7] = m_data[7] + matrix[7];
        tmp[8] = m_data[8] + matrix[8];
        tmp[9] = m_data[9] + matrix[9];
        tmp[10] = m_data[10] + matrix[10];
        tmp[11] = m_data[11] + matrix[11];
        tmp[12] = m_data[12] + matrix[12];
        tmp[13] = m_data[13] + matrix[13];
        tmp[14] = m_data[14] + matrix[14];
        tmp[15] = m_data[15] + matrix[15];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix4<Real> Matrix4<Real>::operator-(const Matrix4<Real>& matrix) const
    {
        Matrix4<Real> tmp(true);
        tmp[0] = m_data[0] - matrix[0];
        tmp[1] = m_data[1] - matrix[1];
        tmp[2] = m_data[2] - matrix[2];
        tmp[3] = m_data[3] - matrix[3];
        tmp[4] = m_data[4] - matrix[4];
        tmp[5] = m_data[5] - matrix[5];
        tmp[6] = m_data[6] - matrix[6];
        tmp[7] = m_data[7] - matrix[7];
        tmp[8] = m_data[8] - matrix[8];
        tmp[9] = m_data[9] - matrix[9];
        tmp[10] = m_data[10] - matrix[10];
        tmp[11] = m_data[11] - matrix[11];
        tmp[12] = m_data[12] - matrix[12];
        tmp[13] = m_data[13] - matrix[13];
        tmp[14] = m_data[14] - matrix[14];
        tmp[15] = m_data[15] - matrix[15];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix4<Real> Matrix4<Real>::operator*(const Matrix4<Real>& matrix) const
    {
        Matrix4<Real> tmp(true);
        tmp[0] = m_data[0]*matrix[0] + m_data[1]*matrix[4] + 
            m_data[2]*matrix[8] + m_data[3]*matrix[12];
        tmp[1] = m_data[0]*matrix[1] + m_data[1]*matrix[5] +
            m_data[2]*matrix[9] + m_data[3]*matrix[13];
        tmp[2] = m_data[0]*matrix[2] + m_data[1]*matrix[6] +
            m_data[2]*matrix[10] + m_data[3]*matrix[14];
        tmp[3] = m_data[0]*matrix[3] + m_data[1]*matrix[7] +
            m_data[2]*matrix[11] + m_data[3]*matrix[15];
        tmp[4] = m_data[4]*matrix[0] + m_data[5]*matrix[4] +
            m_data[6]*matrix[8] + m_data[7]*matrix[12];
        tmp[5] = m_data[4]*matrix[1] + m_data[5]*matrix[5] +
            m_data[6]*matrix[9] + m_data[7]*matrix[13];
        tmp[6] = m_data[4]*matrix[2] + m_data[5]*matrix[6] +
            m_data[6]*matrix[10] + m_data[7]*matrix[14];
        tmp[7] = m_data[4]*matrix[3] + m_data[5]*matrix[7] +
            m_data[6]*matrix[11] + m_data[7]*matrix[15];
        tmp[8] = m_data[8]*matrix[0] + m_data[9]*matrix[4] +
            m_data[10]*matrix[8] + m_data[11]*matrix[12];
        tmp[9] = m_data[8]*matrix[1] + m_data[9]*matrix[5] +
            m_data[10]*matrix[9] + m_data[11]*matrix[13];
        tmp[10] = m_data[8]*matrix[2] + m_data[9]*matrix[6] +
            m_data[10]*matrix[10] + m_data[11]*matrix[14];
        tmp[11] = m_data[8]*matrix[3] + m_data[9]*matrix[7] +
            m_data[10]*matrix[11] + m_data[11]*matrix[15];
        tmp[12] = m_data[12]*matrix[0] + m_data[13]*matrix[4] +
            m_data[14]*matrix[8] + m_data[15]*matrix[12];
        tmp[13] = m_data[12]*matrix[1] + m_data[13]*matrix[5] +
            m_data[14]*matrix[9] + m_data[15]*matrix[13];
        tmp[14] = m_data[12]*matrix[2] + m_data[13]*matrix[6] +
            m_data[14]*matrix[10] + m_data[15]*matrix[14];
        tmp[15] = m_data[12]*matrix[3] + m_data[13]*matrix[7] +
            m_data[14]*matrix[11] + m_data[15]*matrix[15];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix4<Real> Matrix4<Real>::operator-() const
    {
        return ZERO - (*this);
    }

//#############################################################################

    template<class Real>
    Vector4<Real> Matrix4<Real>::operator*(const Vector4<Real>& vector) const
    {
        Vector4<Real> tmp;
        tmp[0] = m_data[0]*vector[0] + m_data[1]*vector[1] + 
            m_data[2]*vector[2] + m_data[3]*vector[3];
        tmp[1] = m_data[4]*vector[0] + m_data[5]*vector[1] +
            m_data[6]*vector[2] + m_data[7]*vector[3];
        tmp[2] = m_data[8]*vector[0] + m_data[9]*vector[1] +
            m_data[10]*vector[2] + m_data[11]*vector[3];
        tmp[3] = m_data[12]*vector[0] + m_data[13]*vector[1] +
            m_data[14]*vector[2] + m_data[15]*vector[3];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix4<Real> Matrix4<Real>::operator*(const Real& scalar) const
    {
        Matrix4<Real> tmp(*this);
        tmp[0] *= scalar;
        tmp[1] *= scalar;
        tmp[2] *= scalar;
        tmp[3] *= scalar;
        tmp[4] *= scalar;
        tmp[5] *= scalar;
        tmp[6] *= scalar;
        tmp[7] *= scalar;
        tmp[8] *= scalar;
        tmp[9] *= scalar;
        tmp[10] *= scalar;
        tmp[11] *= scalar;
        tmp[12] *= scalar;
        tmp[13] *= scalar;
        tmp[14] *= scalar;
        tmp[15] *= scalar;
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix4<Real> Matrix4<Real>::operator/(const Real& scalar) const
    {
        assert(scalar > Math<Real>::EPSILON || scalar < -Math<Real>::EPSILON);
        Real s = 1 / scalar;
        Matrix4<Real> tmp(*this);
        tmp[0] *= s;
        tmp[1] *= s;
        tmp[2] *= s;
        tmp[3] *= s;
        tmp[4] *= s;
        tmp[5] *= s;
        tmp[6] *= s;
        tmp[7] *= s;
        tmp[8] *= s;
        tmp[9] *= s;
        tmp[10] *= s;
        tmp[11] *= s;
        tmp[12] *= s;
        tmp[13] *= s;
        tmp[14] *= s;
        tmp[15] *= s;
        return tmp;
    }

//#############################################################################

    template<class Real>
    void Matrix4<Real>::operator+=(const Matrix4<Real>& matrix)
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
        m_data[9] += matrix[9];
        m_data[10] += matrix[10];
        m_data[11] += matrix[11];
        m_data[12] += matrix[12];
        m_data[13] += matrix[13];
        m_data[14] += matrix[14];
        m_data[15] += matrix[15];
    }

//#############################################################################

    template<class Real>
    void Matrix4<Real>::operator-=(const Matrix4<Real>& matrix)
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
        m_data[9] -= matrix[9];
        m_data[10] -= matrix[10];
        m_data[11] -= matrix[11];
        m_data[12] -= matrix[12];
        m_data[13] -= matrix[13];
        m_data[14] -= matrix[14];
        m_data[15] -= matrix[15];
    }

//#############################################################################

    template<class Real>
    void Matrix4<Real>::operator*=(const Real& scalar) 
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
        m_data[9] *= scalar;
        m_data[10] *= scalar;
        m_data[11] *= scalar;
        m_data[12] *= scalar;
        m_data[13] *= scalar;
        m_data[14] *= scalar;
        m_data[15] *= scalar;
    }

//#############################################################################

    template<class Real>
    void Matrix4<Real>::operator/=(const Real& scalar)
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
        m_data[9] *= s;
        m_data[10] *= s;
        m_data[11] *= s;
        m_data[12] *= s;
        m_data[13] *= s;
        m_data[14] *= s;
        m_data[15] *= s;
    }

//#############################################################################

    template<class Real>
    Real Matrix4<Real>::determinant() const
    {
        return m_data[0]*m_data[5]*m_data[10]*m_data[15] - 
            m_data[0]*m_data[5]*m_data[14]*m_data[11] -
            m_data[0]*m_data[6]*m_data[9]*m_data[15] +
            m_data[0]*m_data[6]*m_data[11]*m_data[13] +
            m_data[0]*m_data[7]*m_data[9]*m_data[14] -
            m_data[0]*m_data[7]*m_data[10]*m_data[13] -
            m_data[1]*m_data[4]*m_data[10]*m_data[15] +
            m_data[1]*m_data[4]*m_data[11]*m_data[14] +
            m_data[1]*m_data[6]*m_data[9]*m_data[15] -
            m_data[1]*m_data[6]*m_data[11]*m_data[12] -
            m_data[1]*m_data[7]*m_data[8]*m_data[14] +
            m_data[1]*m_data[7]*m_data[10]*m_data[12] +
            m_data[2]*m_data[4]*m_data[9]*m_data[15] -
            m_data[2]*m_data[4]*m_data[11]*m_data[13] -
            m_data[2]*m_data[5]*m_data[8]*m_data[15] +
            m_data[2]*m_data[5]*m_data[11]*m_data[12] +
            m_data[2]*m_data[7]*m_data[8]*m_data[13] -
            m_data[2]*m_data[7]*m_data[9]*m_data[12] -
            m_data[3]*m_data[4]*m_data[9]*m_data[14] +
            m_data[3]*m_data[4]*m_data[10]*m_data[13] +
            m_data[3]*m_data[5]*m_data[8]*m_data[14] -
            m_data[3]*m_data[5]*m_data[10]*m_data[12] -
            m_data[3]*m_data[6]*m_data[8]*m_data[13] +
            m_data[3]*m_data[6]*m_data[9]*m_data[12];
    }

//#############################################################################

    template<class Real>
    Matrix4<Real> Matrix4<Real>::transpose() const
    {
        Matrix4<Real> tmp(true);
        tmp[0] = m_data[0];
        tmp[1] = m_data[4];
        tmp[2] = m_data[8];
        tmp[3] = m_data[12];
        tmp[4] = m_data[1];
        tmp[5] = m_data[5];
        tmp[6] = m_data[9];
        tmp[7] = m_data[13];
        tmp[8] = m_data[2];
        tmp[9] = m_data[6];
        tmp[10] = m_data[10];
        tmp[11] = m_data[14];
        tmp[12] = m_data[3];
        tmp[13] = m_data[7];
        tmp[14] = m_data[11];
        tmp[15] = m_data[15];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix4<Real> Matrix4<Real>::timesTranspose(const Matrix4<Real>& matrix) 
    const
    {
        return *this * matrix.transpose();
    }

//#############################################################################

    template<class Real>
    Matrix4<Real> Matrix4<Real>::transposeTimes(const Matrix4<Real>& matrix)
    const
    {
        return transpose() * matrix;
    }

//#############################################################################

    template<class Real>
    Matrix4<Real> Matrix4<Real>::adjugate() const
    {
        Matrix4<Real> tmp(true);
        tmp[0] = m_data[5] * (m_data[10]*m_data[15] - m_data[11]*m_data[14]) - 
            m_data[9] * (m_data[6]*m_data[15] - m_data[7]*m_data[14]) +
            m_data[13] * (m_data[6]*m_data[11] - m_data[10]*m_data[7]);
        tmp[1] -= m_data[1] * (m_data[10]*m_data[15] - m_data[11]*m_data[14]) -
            m_data[9] * (m_data[2]*m_data[15] - m_data[3]*m_data[14]) +
            m_data[13]* (m_data[2]*m_data[11] - m_data[3]*m_data[10]);
        tmp[2] = m_data[1] * (m_data[6]*m_data[15] - m_data[7]*m_data[14]) -
            m_data[5] * (m_data[2]*m_data[15] - m_data[3]*m_data[14]) +
            m_data[13] * (m_data[2]*m_data[7] - m_data[6]*m_data[3]);
        tmp[3] -= m_data[1] * (m_data[6]*m_data[11] - m_data[10]*m_data[7]) -
            m_data[5] * (m_data[2]*m_data[11] - m_data[3]*m_data[10]) +
            m_data[9] * (m_data[2]*m_data[7] - m_data[6]*m_data[3]);
        tmp[4] -= m_data[4] * (m_data[10]*m_data[15] - m_data[11]*m_data[14]) -
            m_data[8] * (m_data[6]*m_data[15] - m_data[7]*m_data[14]) +
            m_data[12] * (m_data[6]*m_data[11] - m_data[10]*m_data[7]);
        tmp[5] = m_data[0] * (m_data[10]*m_data[15] - m_data[11]*m_data[14]) -
            m_data[8] * (m_data[2]*m_data[15] - m_data[3]*m_data[14]) +
            m_data[12] * (m_data[2]*m_data[11] - m_data[3]*m_data[10]);
        tmp[6] -= m_data[0] * (m_data[6]*m_data[15] - m_data[7]*m_data[14]) -
            m_data[4] * (m_data[2]*m_data[15] - m_data[3]*m_data[14]) +
            m_data[12] * (m_data[2]*m_data[7] - m_data[6]*m_data[3]);
        tmp[7] = m_data[0] * (m_data[6]*m_data[11] - m_data[10]*m_data[7]) -
            m_data[4] * (m_data[2]*m_data[11] - m_data[3]*m_data[10]) +
            m_data[8] * (m_data[2]*m_data[7] - m_data[3]*m_data[6]);
        tmp[8] = m_data[4] * (m_data[9]*m_data[15] - m_data[11]*m_data[13]) -
            m_data[8] * (m_data[5]*m_data[15] - m_data[13]*m_data[7]) +
            m_data[12] * (m_data[5]*m_data[11] - m_data[9]*m_data[7]);
        tmp[9] -= m_data[0] * (m_data[9]*m_data[15] - m_data[11]*m_data[13]) -
            m_data[8] * (m_data[1]*m_data[15] - m_data[3]*m_data[13]) +
            m_data[12] * (m_data[1]*m_data[11] - m_data[3]*m_data[9]);
        tmp[10] = m_data[0] * (m_data[5]*m_data[15] - m_data[7]*m_data[13]) -
            m_data[4] * (m_data[1]*m_data[15] - m_data[3]*m_data[13]) +
            m_data[12] * (m_data[1]*m_data[7] - m_data[5]*m_data[3]);
        tmp[11] -= m_data[0] * (m_data[5]*m_data[11] - m_data[9]*m_data[7]) -
            m_data[4] * (m_data[1]*m_data[11] - m_data[3]*m_data[9]) +
            m_data[8] * (m_data[1]*m_data[7] - m_data[5]*m_data[3]);
        tmp[12] -= m_data[4] * (m_data[9]*m_data[14] - m_data[10]*m_data[13]) -
            m_data[8] * (m_data[5]*m_data[14] - m_data[6]*m_data[13]) +
            m_data[12] * (m_data[5]*m_data[10] - m_data[6]*m_data[9]);
        tmp[13] = m_data[0] * (m_data[9]*m_data[14] - m_data[10]*m_data[13]) -
            m_data[8] * (m_data[1]*m_data[14] - m_data[13]*m_data[2]) +
            m_data[12] * (m_data[1]*m_data[10] - m_data[2]*m_data[9]);
        tmp[14] -= m_data[0] * (m_data[5]*m_data[14] - m_data[13]*m_data[6]) -
            m_data[4] * (m_data[1]*m_data[14] - m_data[13]*m_data[2]) +
            m_data[12] * (m_data[1]*m_data[6] - m_data[2]*m_data[5]);
        tmp[15] = m_data[0] * (m_data[5]*m_data[10] - m_data[6]*m_data[9]) -
            m_data[4] * (m_data[1]*m_data[10] - m_data[9]*m_data[2]) +
            m_data[8] * (m_data[1]*m_data[6] - m_data[2]*m_data[5]);
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix4<Real> Matrix4<Real>::inverse() const
    {
        Real det = determinant();
        assert(det > Math<Real>::EPSILON || det < -Math<Real>::EPSILON);
        return adjugate() / det;
    }

//#############################################################################
}
