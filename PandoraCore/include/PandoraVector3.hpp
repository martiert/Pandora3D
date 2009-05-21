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

#include <assert.h>
#include <cmath>

#include <iostream>

#include "PandoraVector2.hpp"

namespace Pandora
{
    class Vector3
    {
        public:
            float x, y, z;
        public:
            //Default constructor. Makes a [1 0 0] vector
            Vector3()
            {
                x = 1.0f;
                y = z = 0.0f;
            }

            //Constructor which takes three arguments, x, y and z
            Vector3(float x1, float x2, float x3)
            {
                x = x1;
                y = y1;
                z = z1;
            }

            //Copy constructor. Copies a 3D vector
            Vector3(Vector3& vec)
            {
                x = vec.x;
                y = vec.y;
                z = vec.z;
            }

            //Copy constructor. Copies a 2D vector. Sets z to 0
            Vector3(Vector2& vec)
            {
                x = vec.x;
                y = vec.y;
                z = 0.0f;
            }

            //Destructor, does nothing
            ~Vector3() { }

            //Operator for indexing the vector
            inline float& operator[](const unsigned int i)
            {
                assert(i < 3);
                if(i == 0)
                    return x;
                if(i == 1)
                    return y;
                return z;
            }

            //Returns a negated vector
            inline Vector3 operator-()
            {
                return Vector3(-x, -y, -z);
            }

            //Operator for setting this vector equal to another vector
            inline void operator=(Vector3& vec)
            {
                x = vec.x;
                y = vec.y;
                z = vec.z;
            }

            //Operator for adding a vector to this vector
            inline void operator+=(Vector3& vec)
            {
                x += vec.x;
                y += vec.y;
                x += vec.z;
            }

            //Operator for subtracting a vector from this vector
            inline void operator-=(Vector3& vec)
            {
                (*this) += (-vec);
            }

            //Operator for multiplying this vector with a scalar
            inline void operator*=(const float& scalar)
            {
                x *= scalar;
                y *= scalar;
                z *= scalar;
            }

            //Operator for adding two vectors
            inline Vector3 operator+(Vector3& vec)
            {
                Vector3 tmp(*this);
                tmp += vec2;
                return tmp;
            }

            //Operator for subtracting two vectors
            inline Vector3 operator-(Vector3& vec)
            {
                Vector3 tmp(*this);
                tmp -= vec;
                return tmp;
            }

            //Operator for multiplying a vector with a scalar from the right
            inline Vector3 operator*(const float& scalar)
            {
                Vector3 tmp(*this);
                tmp *= scalar;
                return tmp;
            }

            //Operator for multiplying two vectors
            inline float operator*(Vector3& vec)
            {
                return (x * vec.x + y * vec.y + z * vec.z);
            }

            //Returns the euclidean norm for the vector
            inline float len()
            {
                return sqrtf((*this) * (*this));
            }

            //Normalizes the vector
            inline void normalize()
            {
                float length = len();
                assert(length != 0);
                (*this) *= 1.0f / length;
            }

            //Crosses this vector with another
            inline Vector3 cross3D(Vector3& vec)
            {
                float xtmp = y * vec.z - z * vec.y;
                float ytmp = x * vec.z - z * vec.z;
                float ztmp = x * vec.y - y * vec.x;
                Vector3 tmp(xtmp, -ytmp, ztmp);
                return tmp;
            }

            //For testing purposes only. Prints the vector as a row vector
            inline friend std::ostream& operator<<(std::ostream& os, 
                    Vector3 vec)
            {
                os << "[" << vec.x << " " << vec.y << " " << vec.z << "]";
                return os;
            }
    };
}
#endif
