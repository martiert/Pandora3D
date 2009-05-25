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

#ifndef _QUATERNION_HPP_
#define _QUATERNION_HPP_

#include <math.h>
#include <assert.h>

#include "PandoraMatrix.hpp"
#include "PandoraVector3.hpp"
#include "PandoraVector4.hpp"

namespace Pandora
{
    class Quaternion
    {
        public:
            //Representation of the quaternion. w is the real valued part
            float w, x, y, z;
        public:
            Quaternion()
            {
                x = y = z = w = 0.0f;
            }

            Quaternion(float w, float x, float y, float z)
            {
                this->w = w;
                this->x = x;
                this->y = y;
                this->z = z;
            }

            ~Quaternion() { }

            float length()
            {
                return sqrt(w*w + x*x + y*y + z*z);
            }

            void normalize()
            {
                float len = length();
                assert(len != 0);
                w /= len;
                x /= len;
                y /= len;
                z /= len;
            }

            Matrix toMatrix()
            {
                normalize();
                Matrix tmp;
                tmp[0][0] = 1 - 2*y*y - 2*z*z;
                tmp[0][1] = 2*x*y - 2*w*z;
                tmp[0][2] = 2*x*z + 2*w*y;
                tmp[1][0] = 2*x*y + 2*w*z;
                tmp[1][1] = 1 - 2*x*x - 2*z*z;
                tmp[1][2] = 2*y*z - 2*w*x;
                tmp[2][0] = 2*x*z - 2*w*y;
                tmp[2][1] = 2*y*z + 2*w*x;
                tmp[2][2] = 1 - 2*x*x - 2*y*y;
                return tmp;
            }

            Quaternion conjugate()
            {
                return Quaternion(w, -x, -y, -z);
            }
    };
}
#endif
