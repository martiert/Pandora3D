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

#include "../include/PandoraMath.hpp"

namespace Pandora
{
    //Constants for both float and double:
    template<> const float Math<float>::EPSILON = FLT_EPSILON;
    template<> const float Math<float>::MAX_REAL = FLT_MAX;
    template<> const float Math<float>::PI = (float)(4.0f*atan(1.0f));
    template<> const float Math<float>::TWO_PI = Math<float>::PI*2;
    template<> const float Math<float>::HALF_PI = Math<float>::PI*0.5f;
    template<> const float Math<float>::INV_PI = 1.0f/Math<float>::PI;
    template<> const float Math<float>::INV_TWO_PI = 1.0f/Math<float>::TWO_PI;
    template<> const float Math<float>::DEG_TO_RAD = Math<float>::PI/180.0f;
    template<> const float Math<float>::RAD_TO_DEG = 180.0f/Math<float>::PI;

    template<> const double Math<double>::EPSILON = DBL_EPSILON;
    template<> const double Math<double>::MAX_REAL = DBL_MAX;
    template<> const double Math<double>::PI = 4.0*atan(1.0);
    template<> const double Math<double>::TWO_PI = Math<double>::PI*2;
    template<> const double Math<double>::HALF_PI = Math<double>::PI*0.5;
    template<> const double Math<double>::INV_PI = 1.0/Math<double>::PI;
    template<> const double Math<double>::INV_TWO_PI = 1.0/Math<double>::TWO_PI;
    template<> const double Math<double>::DEG_TO_RAD = Math<double>::PI/180.0;
    template<> const double Math<double>::RAD_TO_DEG = 180.0/Math<double>::PI;

//#############################################################################

    template<class Real>
    Real Math<Real>::Sqrt(Real s)
    {
        return (Real)sqrt((double) s);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::InvSqrt(Real s)
    {
        return (Real) (1.0 / sqrt((double)s));
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Pow(Real base, Real exp)
    {
        return (Real) pow((double) base, (double) exp);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Log(Real s)
    {
        return (Real) log((double) s);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Fmod(Real a, Real b)
    {
        return (Real) fmod((double) a, (double) b);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Fabs(Real s)
    {
        return (Real) fabs((double) s);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Exp(Real s)
    {
        return (Real) exp((double) s);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Floor(Real s)
    {
        return (Real) floor((double) s);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Ceil(Real s)
    {
        return (Real) ceil((double) s);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Sin(Real s)
    {
        return (Real) sin((double) s);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Cos(Real s)
    {
        return (Real) cos((double) s);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Tan(Real s)
    {
        return (Real) tan((double) s);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Asin(Real s)
    {
        if(-(Real)1.0 < s)
        {
            if(s < (Real) 1.0)
                return (Real) asin((double) s);
            else
                return HALF_PI;
        }
        return -HALF_PI;
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Acos(Real s)
    {
        if(-(Real)1.0 < s)
        {
            if(s < (Real) 1.0)
                return (Real) acos((double) s);
            else
                return (Real) 0.0;
        }
        return PI;
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::Atan(Real s)
    {
        return (Real) atan((double) s);
    }

//#############################################################################
}
