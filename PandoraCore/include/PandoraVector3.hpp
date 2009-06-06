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

#ifndef _VECTOR3_HPP_
#define _VECTOR3_HPP_

#include "PandoraSystem.hpp"

namespace Pandora
{
    template<class Real>
    class Vector3
    {
        public:
            Real x, y, z;

            //Constructor. Makes a vector with the m_x as x and m_y as y.
            Vector3(Real m_x = 1, Real m_y = 0, Real m_z = 0);

            //Copy constructor
            Vector3(Vector3& vec);

            //Operators for accessing the data.
            operator const Real*() const;
            operator Real*();
            Real operator[](const int i) const;
            Real& operator[](const int i);

            //Comparison operators.
            bool operator==(Vector3& vector) const;
            bool operator!=(Vector3& vector) const;
            bool operator<(Vector3& vector) const;
            bool operator>(Vector3& vector) const;
            bool operator<=(Vector3& vector) const;
            bool operator>=(Vector3& vector) const;

            //Mathematical operators.
            Vector3 operator+(Vector3& vector) const;
            Vector3 operator-(Vector3& vector) const;
            Vector3 operator*(Real& scalar) const;
            Vector3 operator/(Real& scalar) const;
            Vector3 operator-() const;

            void operator+=(Vector3& vector);
            void operator-=(Vector3& vector);
            void operator*=(Real& scalar);
            void operator/=(Real& scalar);

            //dot product.
            Real operator*(Vector3& vector) const;

            //Geometrical operations.
            Real length() const;
            Real squaredLength() const;
            Real normalize();
            Vector3 cross(Vector3& vector) const;
    };
    typedef Vector3<float> Vector3f;
    typedef Vector3<double> Vector3d;
}
#endif
