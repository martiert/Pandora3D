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

#ifndef _VECTOR4_HPP_
#define _VECTOR4_HPP_

#include "PandoraSystem.hpp"

namespace Pandora
{
    template<class Real>
    class Vector4
    {
        public:
            Real x, y, z, w;

            //Constructor. Makes a vector with the m_x as x and m_y as y.
            Vector4(Real m_x = 1, Real m_y = 0, Real m_z = 0, Real m_w = 0);

            //Copy constructor
            Vector4(Vector4& vec);

            //Operators for accessing the data.
            operator const Real*() const;
            operator Real*();
            Real operator[](const int i) const;
            Real& operator[](const int i);

            //Comparison operators.
            bool operator==(Vector4& vector) const;
            bool operator!=(Vector4& vector) const;
            bool operator<(Vector4& vector) const;
            bool operator>(Vector4& vector) const;
            bool operator<=(Vector4& vector) const;
            bool operator>=(Vector4& vector) const;

            //Mathematical operators.
            Vector4 operator+(Vector4& vector) const;
            Vector4 operator-(Vector4& vector) const;
            Vector4 operator*(Real& scalar) const;
            Vector4 operator/(Real& scalar) const;
            Vector4 operator-() const;

            void operator+=(Vector4& vector);
            void operator-=(Vector4& vector);
            void operator*=(Real& scalar);
            void operator/=(Real& scalar);

            //Dot product.
            Real operator*(Vector4& vector) const;

            //Geometrical operations.
            Real length() const;
            Real squaredLength() const;
            Real normalize();
    };
    typedef Vector4<float> Vector4f;
    typedef Vector4<double> Vector4d;
}
#endif
