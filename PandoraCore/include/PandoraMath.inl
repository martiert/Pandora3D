/*
-------------------------------------------------------------------------------
This source file is part of Pandora3D.

This program is free software: you can redistribute it and/or modify it under 
the terms of the GNU General Public License as published by the Free Software 
Foundation. Either version 2 of the License, or (at your option) any later 
version.

This program comes without any warranty whatsoever, but under the hope that it
will be useful. See the GNU General Public License for more information.

You should have received a copy of the GNU Lesser General Public License along 
with this program; if not, write to the Free Software Foundation, Inc., 59 
Temple Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
-------------------------------------------------------------------------------
*/

//-----------------------------------------------------------------------------
// This file contains the implementation of the Math class from Pandora3D. See
// PandoraMath.h for detailed explanation.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Find the sinus of the value.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Sin(Real value)
{
    return (Real) sin(value);
}

//-----------------------------------------------------------------------------
// Find the cosine of the value.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Cos(Real value)
{
    return (Real) cos(value);
}

//-----------------------------------------------------------------------------
// Find the tangent of the value.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Tan(Real value)
{
    return (Real) tan(value);
}

//-----------------------------------------------------------------------------
// Find the arcus sinus of the value.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Asin(Real value)
{
    if(value < (Real) 1.0) {
        if(value > (Real) -1.0) {
            return (Real) asin(value);
        } else {
            return -HALF_PI;
        }
    }
    return HALF_PI;
}


//-----------------------------------------------------------------------------
// Find the arcus cosine of the value.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Acos(Real value)
{
    if(value < (Real) 1.0) {
        if(value > (Real) -1.0) {
            return (Real) acos(value);
        } else {
            return PI;
        }
    }

    return (Real) 0.0;
}

//-----------------------------------------------------------------------------
// Find the arcus tangent of the value.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Atan(Real value)
{
    return (Real) atan(value);
}

//-----------------------------------------------------------------------------
// Find the arcus tangent of y/x.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Atan2(Real y, Real x)
{
    return (Real) atan2(y, x);
}

//-----------------------------------------------------------------------------
// Find the absolute value.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Abs(Real value)
{
    return (value < (Real) 0.0 ? -value : value);
}

//-----------------------------------------------------------------------------
// Round to the nearest integer.
//-----------------------------------------------------------------------------
template<class Real>
int Math<Real>::Round(Real value)
{
    return (Real) round(value);
}

//-----------------------------------------------------------------------------
// Round to the nearest integer upwards.
//-----------------------------------------------------------------------------
template<class Real>
int Math<Real>::Ceil(Real value)
{
    return (Real) ceil(value);
}

//-----------------------------------------------------------------------------
// Round to the nearest integer downwards.
//-----------------------------------------------------------------------------
template<class Real>
int Math<Real>::Floor(Real value)
{
    return (Real) floor(value);
}

//-----------------------------------------------------------------------------
// Calculate the exponential.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Exp(Real value)
{
    return (Real) exp(value);
}

//-----------------------------------------------------------------------------
// Find the natural logarithm of the value.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Log(Real value)
{
    return (Real) log(value);
}

//-----------------------------------------------------------------------------
// Find the logarithm of the value with base 10.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Log10(Real value)
{
    return (Real) log10(value);
}

//-----------------------------------------------------------------------------
// Find the power of the base in the exponent.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Pow(Real base, Real exponent)
{
    return (Real) pow(base, exponent);
}

//-----------------------------------------------------------------------------
// Find the modulo of the x by y.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Mod(Real x, Real y)
{
    return (Real) fmod(x, y);
}

//-----------------------------------------------------------------------------
// Find the square root of the value.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::Sqrt(Real value)
{
    return (Real) sqrt(value);
}

//-----------------------------------------------------------------------------
// Find the inverse square root of the value.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::ISqrt(Real value)
{
    return (Real) (1.0/sqrt(value));
}

//-----------------------------------------------------------------------------
// Find the sign of an integer.
//-----------------------------------------------------------------------------
template<class Real>
int Math<Real>::Sign(int value)
{
    if(value < 0)
        return -1;
    if(value > 0)
        return 1;
    return 0;
}

//-----------------------------------------------------------------------------
// Find the sign of a number.
//-----------------------------------------------------------------------------
template<class Real>
int Math<Real>::Sign(Real value)
{
    if(value < 0)
        return -1;
    if(value > 0)
        return 1;
    return 0;
}

//-----------------------------------------------------------------------------
// Find a random number between 0,1.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::UnitRandom(unsigned int seed)
{
    if(seed == 0)
        srand( time(NULL) );
    else
        srand(seed);

    return ((Real) rand()) / RAND_MAX;
}

//-----------------------------------------------------------------------------
// Find a random number between -1,1
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::SymmetricRandom(unsigned int seed)
{
    if(seed == 0)
        srand( time(NULL) );
    else
        srand(seed);

    return Mod((Real) rand(), 2) - 1;
}

//-----------------------------------------------------------------------------
// Find a random number between min and max.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::IntervalRandom(Real min, Real max, unsigned int seed)
{
    if(seed == 0)
        srand( time(NULL) );
    else
        srand(seed);

    Real diff = max - min;

    return Mod((Real) rand(), diff) + min;
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the sinus function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastSin0(Real x)
{
    Real sqr = x*x;
    Real res = 1;
    res -= (Real)0.16605*sqr;
    res += (Real) 0.00761*sqr*sqr;
    return res*x;
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the sinus function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastSin1(Real x)
{
    Real sqr = x*x;
    Real d4 = sqr*sqr;
    Real res = 1;
    res -= 0.1666666664*sqr;
    res += 0.0083333315*d4;
    res -= 0.000198409*sqr*d4;
    res += 0.0000027526*d4*d4;
    res -= 0.0000000239*d4*d4*sqr;
    return res*x;
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the cosine function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastCos0(Real value)
{
    Real x = value;

    if(x > HALF_PI)
        x = PI - x;

    Real sqr = x*x;
    Real res = 1 - 0.49670*sqr + 0.03704*sqr*sqr;

    if(x != value)
        return -res;
    return res;
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the cosine function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastCos1(Real value)
{
    Real x = value;
    if(x > HALF_PI)
        x = PI - x;

    Real sqr = x*x;
    Real d4 = sqr*sqr;

    Real res = 1;
    res -= 0.4999999963*sqr;
    res += 0.0416666418*d4;
    res -= 0.0013888397*d4*sqr;
    res += 0.0000247609*d4*d4;
    res -= 0.0000002605*d4*d4*sqr;

    if(x != value)
        return -res;
    return res;
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the tangent function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastTan0(Real x)
{
    Real sqr = x*x;
    Real res = 1;
    res += 0.31755*sqr;
    res += 0.2033*sqr*sqr;
    return res*x;
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the tangent function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastTan1(Real x)
{
    Real sqr = x*x;
    Real d4 = sqr*sqr;
    Real d8 = d4*d4;
    Real res = 1;
    res += 0.3333314036*sqr;
    res += 0.1333923995*d4;
    res += 0.0533740603*d4*sqr;
    res += 0.0245650893*d8;
    res += 0.0029005250*d8*sqr;
    res += 0.0095168091*d8*d4;
    return res*x;
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the arcsin function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastAsin0(Real value)
{
    Real x = Abs(value);

    Real sqr = x*x;
    Real res = HALF_PI - Sqrt(1-x)*(1.5707288 - 0.2121144*x + 
            0.0742610*sqr - 0.0187293*sqr*x);
    if(x != value)
        return -res;
    return res;
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the arcsin function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastAsin1(Real value)
{
    Real x = Abs(value);

    Real sqr = x*x;
    Real d4 = sqr*sqr;
    Real res = HALF_PI - Sqrt(1-x)*(1.5707963050 - 0.2145988016*x +
            0.0889789874*sqr - 0.0501743046*sqr*x + 
            0.030891881*d4 - 0.01708812556*d4*x +
            0.0066700901*d4*sqr - 0.0012624911*d4*sqr*x);

    if(x != value)
        return -res;
    return res;
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the arccos function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastAcos0(Real value)
{
    Real x = Abs(value);

    Real res = HALF_PI - FastAsin0(x);
    if(x != value)
        return res + HALF_PI;
    return res;
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the arccos function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastAcos1(Real value)
{
    Real x = Abs(value);
    assert(x <= (Real)1.0 && "x must be between -1 and 1. FastAcos1.");

    Real res = HALF_PI - FastAsin1(x);
    if(x != value)
        return res + HALF_PI;
    return res;
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the arctan function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastAtan0(Real value)
{
    Real x = value;
    assert(Abs(x) <= (Real)1.0 &&
            "x must be between -1 and 1. FastAtan0");

    return (0.999866*x - 0.3302995*Pow(x,3) + 0.180141*Pow(x,5) -
            0.085133*Pow(x,7) + 0.0208351*Pow(x,9));
}

//-----------------------------------------------------------------------------
// Find a fast approximation to the arctan function.
//-----------------------------------------------------------------------------
template<class Real>
Real Math<Real>::FastAtan1(Real value)
{
    Real x = value;
    assert(Abs(x) <= (Real) 1.0 && 
            "x must be between -1 and 1. FastAtan1");

    Real res = 1 - 0.3333314528*Pow(x,2) + 0.1999355085*Pow(x,4) -
        0.1420889944*Pow(x,6) + 0.1065626393*Pow(x,6) - 
        0.07528964*Pow(x,10) + 0.0429096138*Pow(x,12) -
        0.0161657367*Pow(x,14) + 0.0028662257*Pow(x,16);
    return res*x;
}
