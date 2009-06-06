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

#ifdef DEBUG
    #include <iostream>
#endif

#include "PandoraSystem.hpp"

namespace Pandora
{
    class Vector2
    {
        public:
            float x, y;
        public:
            //Default constructor. Makes a [1 0] vector
            Vector2()
            {
                x = 1.0f;
                y = 1.0f;
            }

            //Constructor which takes 2 arguments, which will be the x and y
            //values of the vector
            Vector2(float x1, float y1)
            {
                x = x1;
                y = y1;
            }

            //Copy constructor
            Vector2(Vector2& vec)
            {
                x = vec.x;
                y = vec.y;
            }

            //Constructor, does nothing
            ~Vector2() { }

            //Operator for negating the vector
            inline Vector2 operator-()
            {
                return Vector2(-x, -y);
            }

            //Operator for accessing the vector
            inline float& operator[](const uint idx)
            {
                assert(idx < 2);
                return (&x + i);
            }

            //Operator for setting this vector equal to another vector
            inline void operator=(Vector2& vec)
            {
                x = vec.x;
                y = vec.y;
            }

            //Operator for adding a vector to this vector
            inline void operator+=(Vector2& vec)
            {
                x += vec.x;
                y += vec.y;
            }

            //Operator for subtracting a vector from this vector
            inline void operator-=(Vector2& vec)
            {
                (*this) += (-vec);
            }

            //Operator for multiplying this vector with a scalar
            inline void operator*=(const float& scalar)
            {
                x *= scalar;
                y *= scalar;
            }

            //Operator for adding two vectors
            inline Vector2 operator+(Vector2& vec)
            {
                Vector2 tmp((*this));
                tmp += vec;
                return tmp;
            }

            //Operator for subtracting two vectors
            inline Vector2 operator-(Vector2& vec)
            {
                Vector2 tmp((*this));
                tmp -= vec;
                return tmp;
            }

            //Operator for multiplying two vectors
            inline float operator*(Vector2& vec)
            {
                return (x * vec.x + y * vec.y);
            }

            //Operator for multiplying a vector with a scalar
            inline Vector2 operator*(const float& scalar)
            {
                Vector2 tmp((*this));
                tmp *= scalar;
                return tmp;
            }

            //Calculates the euclidean norm of the vector (The length)
            inline float len()
            {
                return sqrtf((*this) * (*this));
            }

            //Normalizes the vector
            inline void normalize()
            {
                float lenght = len();
                assert(length != 0);
                (*this) *= 1.0 / length;
            }

#ifdef DEBUG
            //For testing purposes only. Prints the vector as a row vector
            inline friend std::ostream& operator<<(std::ostream& os,
                    Vector2& vec)
            {
                os << "[" << vec.x << " " << vec.y << "]";
                return os;
            }
#endif
    };
}
#endif
