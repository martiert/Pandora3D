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

#ifndef _VECTOR2_HPP_
#define _VECTOR2_HPP_

#include "PandoraSystem.hpp"

namespace Pandora
{
    template<class Real>
    class Vector2
    {
        public:
            Real x, y;

            //Constructor. Makes a vector with the m_x as x and m_y as y.
            Vector2(Real m_x = 1, Real m_y = 0);

            //Copy constructor
            Vector2(Vector2& vec);

            //Operators for accessing the data.
            operator const Real*() const;
            operator Real*();
            Real operator[](const int i) const;
            Real& operator[](const int i);

            //Comparison operators.
            bool operator==(Vector2& vector) const;
            bool operator!=(Vector2& vector) const;
            bool operator<(Vector2& vector) const;
            bool operator>(Vector2& vector) const;
            bool operator<=(Vector2& vector) const;
            bool operator>=(Vector2& vector) const;

            //Mathematical operators.
            Vector2 operator+(Vector2& vector) const;
            Vector2 operator-(Vector2& vector) const;
            Vector2 operator*(Real& scalar) const;
            Vector2 operator/(Real& scalar) const;
            Vector2 operator-() const;

            void operator+=(Vector2& vector);
            void operator-=(Vector2& vector);
            void operator*=(Real& scalar);
            void operator/=(Real& scalar);

            //Dot product.
            Real operator*(Vector2& vector) const;

            //Geometrical operations.
            Real length() const;
            Real squaredLength() const;
            Real normalize();
    };
    typedef Vector2<float> Vector2f;
    typedef Vector2<double> Vector2d;
}
#endif
