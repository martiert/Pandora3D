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
            //Wrappers around normal mathematical functions.
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
            static Real Atan2(Real x, Real y);

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

            //Fast functions. The trigonometric functions comes in two
            //variants. 0 and 1. 0 is faster, but less accurate. 1 is slower,
            //but more accurate.
            static Real FastSin0(Real angle);
            static Real FastSin1(Real angle);
            static Real FastCos0(Real angle);
            static Real FastCos1(Real angle);
            static Real FastTan0(Real angle);
            static Real FastTan1(Real angle);
            static Real FastAsin0(Real angle);
            static Real FastAsin1(Real angle);
            static Real FastAcos0(Real angle);
            static Real FastAcos1(Real angle);
            static Real FastAtan0(Real angle);
            static Real FastAtan1(Real angle);

            //Inverse square root
            static Real FastInvSqrt(Real value);
    };

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

    template<class Real>
    Real Math<Real>::Atan2(Real x, Real y)
    {
        return (Real) atan2((double) x, (double) y);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastSin0(Real angle)
    {
        Real ans = (Real) 7.61e-3;
        ans *= angle * angle;;
        ans -= (Real) 0.16605;
        ans *= angle * angle;
        ans += (Real) 1.0;
        return ans * angle;
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastSin1(Real angle)
    {
        Real angleSqr = angle * angle;
        Real ans = -(Real) 2.39e-8;
        ans *= angleSqr;
        ans += (Real) 2.7526e-6;
        ans *= angleSqr;
        ans -= (Real) 1.984090e-4;
        ans *= angleSqr;
        ans += (Real) 8.3333315e-3;
        ans *= angleSqr;
        ans -= (Real) 0.1666666664;
        ans *= angleSqr;
        ans += (Real) 1.0;
        return ans * angle;
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastCos0(Real angle)
    {
        Real ans = (Real) 3.705e-2 * angle * angle;
        ans -= (Real) 0.4967;
        ans *= angle * angle;
        ans += (Real) 1.0;
        return ans;
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastCos1(Real angle)
    {
        Real angleSqr = angle * angle;
        Real ans = - (Real) 2.605e-7;
        ans *= angleSqr;
        ans += (Real)2.47609e-5;
        ans *= angleSqr;
        ans -= (Real)1.3888397e-3;
        ans *= angleSqr;
        ans += (Real) 4.16666418e-2;
        ans *= angleSqr;
        ans -= (Real) 0.4999999963;
        ans *= angleSqr;
        ans += (Real) 1.0;
        return ans;
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastTan0(Real angle)
    {
        Real ans = (Real) 0.20330 * angle * angle;
        ans += (Real) 0.31755;
        ans *= angle * angle;
        ans += (Real) 1.0;
        return ans * angle;
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastTan1(Real angle)
    {
        Real angleSqr = angle * angle;
        Real ans = (Real) 9.5168091e-3;
        ans *= angleSqr;
        ans += (Real) 2.9005250e-3;
        ans *= angleSqr;
        ans += (Real) 2.45650893e-2;
        ans *= angleSqr;
        ans += (Real) 5.33740603e-2;
        ans *= angleSqr;
        ans += (Real) 0.1333923995;
        ans *= angleSqr;
        ans += (Real) 0.3333314036;
        ans *= angleSqr;
        ans += (Real) 1.0;
        return ans * angle;
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastAsin0(Real angle)
    {
        Real ans = - ((Real) 1.87293e-2 * angle * angle * angle);
        ans += (Real) 7.42610e-2 * angle * angle;
        ans -= (Real) 0.2121144 * angle;
        ans += (Real) 1.5707288;
        ans *= Sqrt((Real) 1.0 - angle);
        return HALF_PI - ans;
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastAsin1(Real angle)
    {
        Real ans = -(Real) 1.2624911e-3;
        ans *= angle;
        ans += (Real) 6.6700901e-3;
        ans *= angle;
        ans -= (Real) 1.708812556e-2;
        ans *= angle;
        ans += (Real) 3.0891881e-2;
        ans *= angle;
        ans -= (Real) 5.01743046e-2;
        ans *= angle;
        ans += (Real) 8.89789874e-2;
        ans *= angle;
        ans -= (Real) 0.2145988016;
        ans *= angle;
        ans += (Real) 1.5707963050;
        ans *= Sqrt((Real) 1.0 - angle);
        return HALF_PI - ans;
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastAcos0(Real angle)
    {
        return HALF_PI - FastAsin0(angle);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastAcos1(Real angle)
    {
        return HALF_PI - FastAsin1(angle);
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastAtan0(Real angle)
    {
        Real angleSqr = angle * angle;
        Real ans = (Real) 2.08351e-2;
        ans *= angleSqr;
        ans -= (Real) 8.51330e-2;
        ans *= angleSqr;
        ans += (Real) 0.1801410;
        ans *= angleSqr;
        ans -= (Real) 0.3302995;
        ans *= angleSqr;
        ans += (Real) 0.9998660;
        return ans * angle;
    }

//#############################################################################

    template<class Real>
    Real Math<Real>::FastAtan1(Real angle)
    {
        Real angleSqr = angle * angle;
        Real ans = (Real) 2.8662257e-3;
        ans *= angleSqr;
        ans -= (Real) 1.61657367e-2;
        ans *= angleSqr;
        ans += (Real) 4.29096138e-2;
        ans *= angleSqr;
        ans -= (Real) 7.528964e-2;
        ans *= angleSqr;
        ans += (Real) 0.1065626393;
        ans *= angleSqr;
        ans -= (Real) 0.1420889944;
        ans *= angleSqr;
        ans += (Real) 0.1999355085;
        ans *= angleSqr;
        ans -= (Real) 0.3333314528;
        ans *= angleSqr;
        ans += (Real) 1.0;
        return ans * angle;
    }

//#############################################################################

    template<>
    float Math<float>::FastInvSqrt(float value)
    {
        float half = 0.5f * value;
        int i = *(int*)&value;
        i = 0x5f3759df - (i >> 1);
        value = *(float*)&i;
        value *= (1.5f - half*value*value);
        return value;
    }

//#############################################################################

    template<>
    double Math<double>::FastInvSqrt(double value)
    {
        double half = 0.5 * value;
        long long i = *(long long*)&value;
        i = 0x5fe6ec85e7de30da - (i >> 1);
        value = *(double*)&i;
        value *= (1.5 - half*value*value);
        return value;
    }

//#############################################################################
}
#endif
