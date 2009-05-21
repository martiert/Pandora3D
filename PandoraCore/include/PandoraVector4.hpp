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

#include <assert.h>
#include <cmath>

#include <iostream>

#include "PandoraVector2.hpp"
#include "PandoraVector3.hpp"

namespace Pandora
{
    class Vector4
    {
        public:
            float x, y, z, w;
        public:
            //Default constructor, makes a [1 0 0 0] vector
            Vector4()
            {
                x = 1.0f;
                y = z = w = 0.0f;
            }

            //Takes the x, y, z and w values as arguments
            Vector4(float x1, float y1, float z1, float w1)
            {
                x = x1;
                y = y1;
                z = z1;
                w = w1;
            }

            //Copies a 4D vector
            Vector4(Vector4& vec)
            {
                x = vec.x;
                y = vec.y;
                z = vec.z;
                w = vec.w;
            }

            //Copies a 3D vector, padding with 0
            Vector4(Vector3& vec)
            {
                x = vec.x;
                y = vec.y;
                z = vec.z;
                w = 0.0f;
            }

            //Copies a 2D vector, padding with 0
            Vector4(Vector2& vec)
            {
                x = vec.x;
                y = vec.y;
                z = w = 0.0f;
            }

            //Destructor, does nothing
            ~Vector4() { }

            //Copies a vector
            inline void operator=(Vector4& vec)
            {
                x = vec.x;
                y = vec.y;
                z = vec.z;
                w = vec.w;
            }

            //Negates a vector
            inline Vector4 operator-()
            {
                return Vector4(-x, -y, -z, -w);
            }

            //Adds a vector to this vector
            inline void operator+=(Vector4& vec)
            {
                x += vec.x;
                y += vec.y;
                z += vec.z;
                w += vec.w;
            }

            //Subtracts a vector from this vector
            inline void operator-=(Vector4& vec)
            {
                *this += (-vec);
            }

            //Multiplies this vector with a scalar
            inline void operator*=(const float& scalar)
            {
                x *= scalar;
                y *= scalar;
                z *= scalar;
                w *= scalar;
            }

            //Adds two vectors
            inline Vector4 operator+(Vector4& vec)
            {
                Vector4 tmp(*this);
                tmp += vec;
                return tmp;
            }

            //Subtracts two vectors
            inline Vector4 operator-(Vector4& vec)
            {
                Vector4 tmp(*this);
                tmp -= vec;
                return tmp;
            }

            //Multiples two vectors (dot product)
            inline float operator*(Vector4& vec)
            {
                return (x * vec.x + y * vec.y + z * vec.z + w * vec.w);
            }

            //Multiplies a vector with a scalar
            inline Vector4 operator*(const float& scalar)
            {
                Vector4 tmp(*this);
                tmp *= scalar;
                return tmp;
            }

            //Returns the euclidean norm of this vector
            inline float len()
            {
                return sqrtf((*this) * (*this));
            }

            //Normalizes this vector
            inline void normalize()
            {
                float length = len();
                assert(length != 0);
                (*this) *= 1.0f / length;
            }

            //For testing purposes only. Prints the vector as a row vector
            inline friend std::ostream& operator<<(std::ostream& os,
                    Vector4 vec)
            {
                os << "[" << vec.x << " " << vec.y << " " << vec.z << " " 
                    << vec.w << "]";
                return os;
            }
    };
}
#endif
