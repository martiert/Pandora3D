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

#ifndef _MATRIX4_HPP_
#define _MATRIX4_HPP_

#include "PandoraSystem.hpp"
#include "PandoraVector4.hpp"

namespace Pandora
{
    template<class Real>
    class Matrix4
    {
        public:
            Matrix4(bool zero);
            Matrix4(Matrix4& matrix);
            Matrix4(Real data[16]);
            ~Matrix4();

            //Assignment operators
            operator const Real*() const;
            operator Real*();
            const Real& operator[](const int i) const;
            Real& operator[](const int i);
            const Real& operator()(const int row, const int column) const;
            Real& operator()(const int row, const int column);
            void operator=(const Matrix4& matrix);

            //Comparison operators
            bool operator==(const Matrix4& matrix) const;
            bool operator!=(const Matrix4& matrix) const;
            bool operator<(const Matrix4& matrix) const;
            bool operator>(const Matrix4& matrix) const;
            bool operator<=(const Matrix4& matrix) const;
            bool operator>=(const Matrix4& matrix) const;

            //Arithmetic operators
            //Matrix-Matrix
            Matrix4 operator+(const Matrix4& matrix) const;
            Matrix4 operator-(const Matrix4& matrix) const;
            Matrix4 operator*(const Matrix4& matrix) const;

            Matrix4 operator-() const;

            //Matrix-Vector
            Vector4<Real> operator*(const Vector4<Real>& vector) const;

            //Matrix-Scalar
            Matrix4 operator*(const Real& scalar) const;
            Matrix4 operator/(const Real& scalar) const;

            //Operators on this matrix
            void operator+=(const Matrix4& matrix);
            void operator-=(const Matrix4& matrix);
            void operator*=(const Real& scalar);
            void operator/=(const Real& scalar);

            //Geometrical operations
            Real determinant() const;
            Matrix4 transpose() const;
            Matrix4 transposeTimes(const Matrix4& matrix) const;
            Matrix4 timesTranspose(const Matrix4& matrix) const;
            Matrix4 adjugate() const;
            Matrix4 inverse() const;

            static const Matrix4 ZERO;
            static const Matrix4 IDENTITY;
        protected:
            Real m_data[16];
            int compareMatrix(const Matrix4& matrix) const;
    };
}
#endif
