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

#include <cmath>
#include "PandoraMatrix.hpp"
#include "PandoraVector3.hpp"
#include "PandoraVector4.hpp"

namespace Pandora
{
    class Quaternion
    {
        public:
            float x, y, z, w;
        public:
            Quaternion();
            ~Quaternion();
    };
}
#endif
