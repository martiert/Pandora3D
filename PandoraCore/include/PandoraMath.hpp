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

#ifndef _MATH_HPP_
#define _MATH_HPP_

#include "PandoraSystem.hpp"

namespace Pandora
{
    template<class Real>
    class Math
    {
        public:
            static Real Sqrt(Real s);
            static Real InvSqrt(Real s);
            static Real Pow(Real base, Real exp);
            static Real Log(Real s);
            static Real Fmod(Real a, Real b);
            static Real Fabs(Real s);
            static Real Exp(Real s);
            static Real Floor(Real s);
            static Real Ceil(Real s);

            static Real Sin(Real s);
            static Real Cos(Real s);
            static Real Tan(Real s);
            static Real Asin(Real s);
            static Real Acos(Real s);
            static Real Atan(Real s);

            //Constants to be used
            static const Real EPSILON;
            static const Real MAX_REAL;
            static const Real PI;
            static const Real TWO_PI;
            static const Real HALF_PI;
            static const Real INV_PI;
            static const Real INV_TWO_PI;
            static const Real DEG_TO_RAD;
            static const Real RAD_TO_DEG;
    };
}
#endif
