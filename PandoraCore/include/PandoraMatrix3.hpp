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

#include "PandoraVector3.hpp"

namespace Pandora
{
    template<class Real>
    class Matrix3
    {
        public:
            //Constructors
            Matrix3();
            Matrix3(Matrix3& matrix);
            Matrix3(Real data[9]);
            ~Matrix3();

            //Assignment operators
            operator const Real*() const;
            operator Real*();
            const Real& operator[](const int i) const;
            Real& operator[](const int i);
            const Real& operator()(const int row, const int column) const;
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

            //Operators on this matrix
            void operator+=(const Matrix3& matrix);
            void operator-=(const Matrix3& matrix);
            void operator*=(const Real& scalar);
            void operator/=(const Real& scalar);

            //Geometrical operations
            Matrix3 transpose() const;
            Matrix3 adj() const;
            Matrix3 inverse() const;

            static const Matrix3 ZERO;
            static const Matrix3 IDENTITY;
        protected:
            Real m_data[9];
            int compareMatrix(const Matrix3& matrix) const;
    };
}
#endif
