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

            static const Matrix2 ZERO;
            static const Matrix2 IDENTITY;
        protected:
            Real m_data[4];
            int compareMatrix(const Matrix2& matrix) const;
    };
}
#endif
