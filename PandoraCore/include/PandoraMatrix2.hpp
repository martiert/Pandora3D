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

#ifndef _MATRIX2_HPP_
#define _MATRIX2_HPP_

#include "PandoraSystem.hpp"
#include "PandoraVector2.hpp"

namespace Pandora
{
    template<class Real>
    class Matrix2
    {
        public:
            //Constructors
            Matrix2(bool zeroMatrix);
            Matrix2(Matrix2& matrix);
            Matrix2(Real data[4]);
            ~Matrix2();
            
            //Assignment operators
            operator const Real*() const;
            operator Real*();
            const Real operator[](const int i) const;
            Real& operator[](const int i);
            const Real operator()(const int row, const int column) const;
            Real& operator()(const int row, const int column);
            void operator=(const Matrix2& matrix);

            //Comparison operators
            bool operator==(const Matrix2& matrix) const;
            bool operator!=(const Matrix2& matrix) const;
            bool operator<(const Matrix2& matrix) const;
            bool operator>(const Matrix2& matrix) const;
            bool operator<=(const Matrix2& matrix) const;
            bool operator>=(const Matrix2& matrix) const;

            //Arithmetic operators
            //Matrix-Matrix operators
            Matrix2 operator+(const Matrix2& matrix) const;
            Matrix2 operator-(const Matrix2& matrix) const;
            Matrix2 operator*(const Matrix2& matrix) const;

            Matrix2 operator-() const;

            //Matrix-Vector operator
            Vector2<Real> operator*(const Vector2<Real>& vector) const;

            //Matrix-scalar operators
            Matrix2 operator*(const Real& scalar) const;
            Matrix2 operator/(const Real& scalar) const;

            //Operators on this matrix
            void operator+=(const Matrix2& matrix);
            void operator-=(const Matrix2& matrix);
            void operator*=(const Real& scalar);
            void operator/=(const Real& scalar);

            //Geometrical operations
            Real determinant() const;
            Matrix2 transpose() const;
            Matrix2 transposeTimes(const Matrix2& matrix) const;
            Matrix2 timesTranspose(const Matrix2& matrix) const;
            Matrix2 adjugate() const;
            Matrix2 inverse() const;

            Real toAngle() const;
            void orthonormalize();
            void eigenDecomposition(Matrix2& rot, Matrix2& diag) const;

            static const Matrix2 ZERO;
            static const Matrix2 IDENTITY;
        protected:
            Real m_data[4];
            int compareMatrix(const Matrix2& matrix) const;
    };

    template<> const Matrix2<float> Matrix2<float>::ZERO(true);
    template<> const Matrix2<float> Matrix2<float>::IDENTITY(false);
    template<> const Matrix2<double> Matrix2<double>::ZERO(true);
    template<> const Matrix2<double> Matrix2<double>::IDENTITY(false);

//#############################################################################

    template<class Real>
    Matrix2<Real>::Matrix2(bool zeroMatrix)
    {
        if(zeroMatrix) {
            m_data[0] = m_data[1] = m_data[2] = m_data[3] = (Real) 0.0;
        } else {
            m_data[0] = m_data[2] = (Real) 1.0;
            m_data[1] = m_data[3] = (Real) 0.0;
        }
    }

//#############################################################################

    template<class Real>
    Matrix2<Real>::Matrix2(Matrix2<Real>& matrix)
    {
        m_data[0] = matrix[0];
        m_data[1] = matrix[1];
        m_data[2] = matrix[2];
        m_data[3] = matrix[3];
    }

//#############################################################################

    template<class Real>
    Matrix2<Real>::Matrix2(Real data[4])
    {
        m_data[0] = data[0];
        m_data[1] = data[1];
        m_data[2] = data[2];
        m_data[3] = data[3];
    }

//#############################################################################

    template<class Real>
    Matrix2<Real>::~Matrix2() { }

//#############################################################################

    template<class Real>
    Matrix2<Real>::operator const Real*() const
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    Matrix2<Real>::operator Real*()
    {
        return &m_data[0];
    }

//#############################################################################

    template<class Real>
    const Real Matrix2<Real>::operator[](const int i) const
    {
        assert(i < 4 && i >= 0);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    Real& Matrix2<Real>::operator[](const int i)
    {
        assert(i < 4 && i >= 0);
        return m_data[i];
    }

//#############################################################################

    template<class Real>
    const Real Matrix2<Real>::operator()(const int row, const int column) const
    {
        assert(row < 2 && column < 2 && row >= 0 && column >= 0);
        return m_data[column + 2*row];
    }

//#############################################################################

    template<class Real>
    Real& Matrix2<Real>::operator()(const int row, const int column)
    {
        assert(row < 2 && column < 2 && row >= 0 && column >= 0);
        return m_data[column + 2*row];
    }

//#############################################################################

    template<class Real>
    void Matrix2<Real>::operator=(const Matrix2<Real>& matrix)
    {
        m_data[0] = matrix[0];
        m_data[1] = matrix[1];
        m_data[2] = matrix[2];
        m_data[3] = matrix[3];
    }

//#############################################################################

    template<class Real>
    int Matrix2<Real>::compareMatrix(const Matrix2<Real>& matrix) const
    {
        return memcmp(m_data, matrix.m_data, 4*sizeof(Real));
    }

//#############################################################################

    template<class Real>
    bool Matrix2<Real>::operator==(const Matrix2<Real>& matrix) const
    {
        return compareMatrix(matrix) == 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix2<Real>::operator!=(const Matrix2<Real>& matrix) const
    {
        return compareMatrix(matrix) != 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix2<Real>::operator<(const Matrix2<Real>& matrix) const
    {
        return compareMatrix(matrix) < 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix2<Real>::operator>(const Matrix2<Real>& matrix) const
    {
        return compareMatrix(matrix) > 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix2<Real>::operator<=(const Matrix2<Real>& matrix) const
    {
        return compareMatrix(matrix) <= 0;
    }

//#############################################################################

    template<class Real>
    bool Matrix2<Real>::operator>=(const Matrix2<Real>& matrix) const
    {
        return compareMatrix(matrix) >= 0;
    }

//#############################################################################

    template<class Real>
    Matrix2<Real> Matrix2<Real>::operator+(const Matrix2<Real>& matrix) const
    {
        Matrix2<Real> tmp(true);
        tmp[0] = m_data[0] + matrix[0];
        tmp[1] = m_data[1] + matrix[1];
        tmp[2] = m_data[2] + matrix[2];
        tmp[3] = m_data[3] + matrix[3];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix2<Real> Matrix2<Real>::operator-(const Matrix2<Real>& matrix) const
    {
        Matrix2<Real> tmp(true);
        tmp[0] = m_data[0] - matrix[0];
        tmp[1] = m_data[1] - matrix[1];
        tmp[2] = m_data[2] - matrix[2];
        tmp[3] = m_data[3] - matrix[3];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix2<Real> Matrix2<Real>::operator*(const Matrix2<Real>& matrix) const
    {
        Matrix2<Real> tmp(true);
        tmp[0] = m_data[0]*matrix[0] + m_data[1]*matrix[2];
        tmp[1] = m_data[0]*matrix[1] + m_data[1]*matrix[3];
        tmp[2] = m_data[2]*matrix[0] + m_data[3]*matrix[2];
        tmp[3] = m_data[2]*matrix[1] + m_data[3]*matrix[3];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix2<Real> Matrix2<Real>::operator-() const
    {
        Matrix2<Real> tmp(true);
        tmp[0] = -m_data[0];
        tmp[1] = -m_data[1];
        tmp[2] = -m_data[2];
        tmp[3] = -m_data[3];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Vector2<Real> Matrix2<Real>::operator*(const Vector2<Real>& vector) const
    {
        Vector2<Real> tmp;
        tmp[0] = vector[0]*m_data[0] + vector[1]*m_data[1];
        tmp[1] = vector[0]*m_data[2] + vector[1]*m_data[3];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix2<Real> Matrix2<Real>::operator*(const Real& scalar) const
    {
        Matrix2<Real> tmp(true);
        tmp[0] = m_data[0] * scalar;
        tmp[1] = m_data[1] * scalar;
        tmp[2] = m_data[2] * scalar;
        tmp[3] = m_data[3] * scalar;
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix2<Real> Matrix2<Real>::operator/(const Real& scalar) const
    {
        assert(scalar > Math<Real>::EPSILON || scalar < -Math<Real>::EPSILON);
        Matrix2<Real> tmp(true);
        tmp[0] = m_data[0] / scalar;
        tmp[1] = m_data[1] / scalar;
        tmp[2] = m_data[2] / scalar;
        tmp[3] = m_data[3] / scalar;
        return tmp;
    }

//#############################################################################

    template<class Real>
    void Matrix2<Real>::operator+=(const Matrix2<Real>& matrix)
    {
        m_data[0] += matrix[0];
        m_data[1] += matrix[1];
        m_data[2] += matrix[2];
        m_data[3] += matrix[3];
    }

//#############################################################################

    template<class Real>
    void Matrix2<Real>::operator-=(const Matrix2<Real>& matrix)
    {
        m_data[0] -= matrix[0];
        m_data[1] -= matrix[1];
        m_data[2] -= matrix[2];
        m_data[3] -= matrix[3];
    }

//#############################################################################

    template<class Real>
    void Matrix2<Real>::operator*=(const Real& scalar)
    {
        m_data[0] *= scalar;
        m_data[1] *= scalar;
        m_data[2] *= scalar;
        m_data[3] *= scalar;
    }

//#############################################################################

    template<class Real>
    void Matrix2<Real>::operator/=(const Real& scalar)
    {
        assert(scalar > Math<Real>::EPSILON || scalar < -Math<Real>::EPSILON);
        m_data[0] /= scalar;
        m_data[1] /= scalar;
        m_data[2] /= scalar;
        m_data[3] /= scalar;
    }

//#############################################################################

    template<class Real>
    Real Matrix2<Real>::determinant() const
    {
        return m_data[0]*m_data[3] - m_data[1]*m_data[2];
    }

//#############################################################################

    template<class Real>
    Matrix2<Real> Matrix2<Real>::transpose() const
    {
        Matrix2<Real> tmp(true);
        tmp[0] = m_data[0];
        tmp[1] = m_data[2];
        tmp[2] = m_data[1];
        tmp[3] = m_data[3];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix2<Real> Matrix2<Real>::transposeTimes(const Matrix2<Real>& matrix) 
    const
    {
        return transpose() * matrix;
    }

//#############################################################################

    template<class Real>
    Matrix2<Real> Matrix2<Real>::timesTranspose(const Matrix2<Real>& matrix)
    const
    {
        return *this * matrix.transpose();
    }

//#############################################################################

    template<class Real>
    Matrix2<Real> Matrix2<Real>::adjugate() const
    {
        Matrix2<Real> tmp(true);
        tmp[0] = m_data[3];
        tmp[1] = -m_data[1];
        tmp[2] = -m_data[2];
        tmp[2] = m_data[0];
        return tmp;
    }

//#############################################################################

    template<class Real>
    Matrix2<Real> Matrix2<Real>::inverse() const
    {
        Matrix2<Real> tmp(true);
        Real det = determinant();

        assert(det > Math<Real>::EPSILON || det < -Math<Real>::EPSILON);
        
        if(det < Math<Real>::EPSILON && det > -Math<Real>::EPSILON)
            return tmp;

        tmp = adjugate();
        tmp /= det;
        return tmp;
    }

//#############################################################################

    template<class Real>
    Real Matrix2<Real>::toAngle() const
    {
        return atan2(m_data[2], m_data[0]);
    }

//#############################################################################

    template<class Real>
    void Matrix2<Real>::orthonormalize()
    {
        Real scale = Math<Real>::Sqrt(m_data[0]*m_data[0] +
                m_data[2]*m_data[2]);
        m_data[0] /= scale;
        m_data[2] /= scale;

        scale = (m_data[0]*m_data[1] + m_data[2]*m_data[3]) / (scale * scale);
        m_data[1] -= scale * m_data[0];
        m_data[3] -= scale * m_data[2];

        scale = Math<Real>::Sqrt(m_data[1]*m_data[1] + m_data[3]*m_data[3]);
        m_data[1] /= scale;
        m_data[3] /= scale;
    }

//#############################################################################

    template<class Real>
    void Matrix2<Real>::eigenDecomposition(Matrix2& rot, Matrix2& diag) const
    {
        Real a = (Real) 1.0;
        Real b = -(m_data[0] + m_data[3]);
        Real c = m_data[0]*m_data[3] - m_data[1]*m_data[2];

        assert((4 * c) <= (Real) 0.0 || b*b >= 4*c);

        if((4*c) > 0 || b*b < 4*c) {
            rot = ZERO;
            diag = ZERO;
            return;
        }

        diag[1] = diag[2] = (Real) 0.0;
        diag[0] = (-b - Math<Real>::Sqrt(b*b - 4*c)) / (Real) 2.0;
        diag[3] = (-b + Math<Real>::Sqrt(b*b - 4*c)) / (Real) 2.0;

        Real diff = m_data[0] - m_data[3];
        Real cos, sin;

        if(diff >= (Real) 0.0) {
            cos = m_data[1];
            sin = diff[0] - m_data[0];
        } else {
            cos = diff[0] - m_data[3];
            sin = m_data[1];
        }

        Real tmp = Math<Real>::Sqrt(cos*cos + sin*sin);
        cos /= tmp;
        sin /= tmp;

        rot[0] = cos;
        rot[1] = -sin;
        rot[2] = cos;
        rot[3] = sin;
    }

//#############################################################################
}
#endif