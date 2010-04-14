/*
--------------------------------------------------------------------------------
File Name : PandoraMath.inl

Purpose : Implementation of the Math class used in Pandora3D

Creation Date : 2010-01-26

Last Modified : on. 14. april 2010 kl. 17.36 +0200

Created By : Martin Ertsås
--------------------------------------------------------------------------------
*/

/********************************************************************************
 * Find the sinus of the value.                                                 * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Sin(Real value)
{
    return (Real) sin(value);
}

/********************************************************************************
 * Find the cosine of the value.                                                * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Cos(Real value)
{
    return (Real) cos(value);
}

/********************************************************************************
 * Find the tangent of the value.                                               *
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Tan(Real value)
{
    return (Real) tan(value);
}

/********************************************************************************
 * Find the arcus sinus of the value.                                           * 
 *******************************************************************************/ 
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

/********************************************************************************
 * Find the arcus cosine of the value.                                          * 
 *******************************************************************************/ 
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

/********************************************************************************
 * Find the arcus tangent of the value.                                         * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Atan(Real value)
{
    return (Real) atan(value);
}

/********************************************************************************
 * Find the arcus tangent of y/x.                                               * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Atan2(Real y, Real x)
{
    return (Real) atan2(y, x);
}

/********************************************************************************
 * Find the absolute value.                                                     * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Abs(Real value)
{
    return (value < (Real) 0.0 ? -value : value);
}

/********************************************************************************
 * Round to the nearest integer.                                                * 
 *******************************************************************************/ 
template<class Real>
int Math<Real>::Round(Real value)
{
    return (Real) round(value);
}

/********************************************************************************
 * Round to the nearest integer upwards.                                        * 
 *******************************************************************************/ 
template<class Real>
int Math<Real>::Ceil(Real value)
{
    return (Real) ceil(value);
}

/********************************************************************************
 * Round to the nearest integer downwards.                                      * 
 *******************************************************************************/ 
template<class Real>
int Math<Real>::Floor(Real value)
{
    return (Real) floor(value);
}

/********************************************************************************
 * Calculate the exponential.                                                   * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Exp(Real value)
{
    return (Real) exp(value);
}

/********************************************************************************
 * Find the natural logarithm of the value.                                     * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Log(Real value)
{
    return (Real) log(value);
}

/********************************************************************************
 * Find the logarithm of the value with base 10.                                * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Log10(Real value)
{
    return (Real) log10(value);
}

/********************************************************************************
 * Find the power of the base in the exponent.                                  * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Pow(Real base, Real exponent)
{
    return (Real) pow(base, exponent);
}

/********************************************************************************
 * Find the modulo of x by y.                                                   * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Mod(Real x, Real y)
{
    return (Real) fmod(x, y);
}

/********************************************************************************
 * Find the square root of the value.                                           * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::Sqrt(Real value)
{
    return (Real) sqrt(value);
}

/********************************************************************************
 * Find the inverse square root of the value.                                   * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::ISqrt(Real value)
{
    return (Real) (1.0/sqrt(value));
}

/********************************************************************************
 * Find the sign of an integer.                                                 * 
 *******************************************************************************/ 
template<class Real>
int Math<Real>::Sign(int value)
{
    if(value < 0)
        return -1;
    if(value > 0)
        return 1;
    return 0;
}

/********************************************************************************
 * Find the sign of a number.                                                   * 
 *******************************************************************************/ 
template<class Real>
int Math<Real>::Sign(Real value)
{
    if(value < 0)
        return -1;
    if(value > 0)
        return 1;
    return 0;
}

/********************************************************************************
 * Find a random number between 0,1.                                            * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::UnitRandom(unsigned int seed)
{
    if(seed == 0)
        srand( time(NULL) );
    else
        srand(seed);

    return ((Real) rand()) / RAND_MAX;
}

/********************************************************************************
 * Find a random number between -1,1                                            * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::SymmetricRandom(unsigned int seed)
{
    if(seed == 0)
        srand( time(NULL) );
    else
        srand(seed);

    return ((Real) rand()) / (RAND_MAX/2) - 1;
}

/********************************************************************************
 * Find a random number between min and max.                                    * 
 *******************************************************************************/ 
template<class Real>
Real Math<Real>::IntervalRandom(Real min, Real max, unsigned int seed)
{
    if(seed == 0)
        srand( time(NULL) );
    else
        srand(seed);

    Real diff = max - min;

    return ((Real) rand()) / (RAND_MAX/diff) + min;
}
