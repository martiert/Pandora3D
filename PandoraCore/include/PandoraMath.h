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

#ifndef PANDORAMATH_H
#define PANDORAMATH_H

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <float.h>

namespace Pandora
{
    /**
     * This namespace is for all the mathematical functions.
     */
    namespace Math
    {
        /**
         * The Math class. Holds all the normal mathematical functions, like
         * trigonometric functions, logarithm, power, square roots, etc. Also
         * holds mathematical constant like PI, e, etc.
         *
         * \note
         *      The fast functions is supposed to be used with slow hardware.
         *      You will gain little/nothing using modern architecture.
         */
        template<class Real>
        class Math
        {
            public:
                static const Real EPSILON;
                static const Real MAX_REAL;
                static const Real PI;
                static const Real TWO_PI;
                static const Real HALF_PI;
                static const Real INV_PI;
                static const Real INV_TWO_PI;
                static const Real DEG_TO_RAD;
                static const Real RAD_TO_DEG;

                /**
                 * Calculate the cosine value.
                 * \param
                 *      value - The number of radians.
                 *  \return
                 *      The cosine value.
                 */
                static Real Cos(Real value);

                /**
                 * Calculate the sinus value.
                 * \param
                 *      value - The number of radians.
                 *  \return
                 *      The sinus value.
                 */
                static Real Sin(Real value);

                /**
                 * Calculate the tangent value.
                 * \param
                 *      value - The number of radians.
                 *  \return
                 *      The tangent value.
                 */
                static Real Tan(Real value);

                /**
                 * Calculates the inverse sinus.
                 * \param
                 *      value - The sinus value.
                 *  \return
                 *      The number of radians in the interval \f$
                 *      [-\frac{\pi}{2},\frac{\pi}{2}]\f$.
                 *  \note
                 *      If the value is less then -1 we return \f$ 
                 *      -\frac{\pi}{2}\f$, and if the value us larger then 1, 
                 *      we return \f$\frac{\pi}{2}\f$.
                 */
                static Real Asin(Real value);

                /**
                 * Calculates the inverse cosine.
                 * \param
                 *      value - The cosine value.
                 *  \return
                 *      The number of radians in the interval [0,\f$\pi\f$].
                 *  \note
                 *      If the value is less then -1 we return \f$ \pi \f$, if 
                 *      the value is larger then 1, we return 0.
                 */
                static Real Acos(Real value);

                /**
                 * Calculates the inverse tangent.
                 * \param
                 *      value - The tangent value.
                 *  \return
                 *      The number of radians in the interval \f$ 
                 *      [-\frac{\pi}{2},\frac{\pi}{2}] \f$.
                 */
                static Real Atan(Real value);

                /**
                 * Calculates the inverse tangent of \f$ \frac{y}{x} \f$.
                 *
                 * \param
                 *      x - A value representing an x-coordinate.
                 * \param
                 *      y - A value representing an y-coordinate.
                 *  \return
                 *      The number of radians in the interval \f$ [-\pi,\pi] \f$.
                 */
                static Real Atan2(Real x, Real y);

                /**
                 * Calculates the absolute value of a number.
                 * \param
                 *      value - The number.
                 * \return
                 *      The absolute value of the number.
                 */
                static Real Abs(Real value);

                /**
                 * Rounds the number to the nearest integer.
                 * \param
                 *      value - The number.
                 *  \return
                 *      The nearest integer.
                 */
                static int Round(Real value);

                /**
                 * Round the number to the nearest integer upwards.
                 * \param
                 *      value - The number.
                 *  \return
                 *      The nearest integer upwards.
                 */
                static int Ceil(Real value);

                /**
                 * Round the number to the nearest integers downwards.
                 * \param
                 *      value - The number.
                 *  \return
                 *      The nearest integer downwards.
                 */
                static int Floor(Real value);

                /**
                 * Find e to the power value.
                 * \param
                 *      value - The power to use.
                 *  \return
                 *      e^value.
                 */
                static Real Exp(Real value);

                /**
                 * Find the logarithm of the number. Uses base e.
                 * \param
                 *      value - The number to take the logarithm of.
                 *  \return
                 *      log(value).
                 */
                static Real Log(Real value);

                /**
                 * Find the logarithm of the number. Uses base 10.
                 * \param
                 *      value - The number to take the logarithm of.
                 *  \return
                 *      log(value) with base 10.
                 */
                static Real Log10(Real value);

                /**
                 * Find the base to the power exponent.
                 * \param
                 *      base - The base to use.
                 *  \param
                 *      exponent - The exponent to use.
                 *  \return
                 *      base to the power exponent.
                 */
                static Real Pow(Real base, Real exponent);

                /**
                 * Find the modulo of x by y.
                 * \param
                 *      x - The number to take modulo by.
                 *  \param
                 *      y - The number to use as divisor.
                 *  \return
                 *      x mod y.
                 */
                static Real Mod(Real x, Real y);

                /**
                 * Find the square root of a number.
                 * \param
                 *      value - The number to find the square root of.
                 *  \return
                 *      The square root of value.
                 *  \note
                 *      Only non-negative numbers.
                 */
                static Real Sqrt(Real value);

                /**
                 * Find the inverse square root of a number.
                 * \param
                 *      value - The number to find the inverse square root of.
                 *  \return
                 *      The inverse square root of value.
                 *  \note
                 *      Only strict positive numbers.
                 */
                static Real ISqrt(Real value);

                /**
                 * Find the sign of an integer.
                 * \param
                 *      value - The integer to check for the sign of.
                 *  \return
                 *      -1 if negative, 0 if 0 and 1 if positive.
                 */
                static int Sign(int value);

                /**
                 * Find the sign of a number.
                 * \param
                 *      value - The number to check for the sign of.
                 *  return
                 *      -1 if negative, 0 if 0 and 1 if positive.
                 */
                static int Sign(Real value);

                /**
                 * Find a random number between 0 and 1.
                 * \param
                 *      seed - The seed to use. Optional. Defaults to 0.
                 *  \return
                 *      A random number in [0,1). Including 0, excluding 1.
                 */
                static Real UnitRandom(unsigned int seed = 0);

                /**
                 * Find a random number between -1,1.
                 * \param
                 *      seed - The seed to use. Optional. Defaults to 0.
                 *  \return
                 *      A random number in [-1,1). Including -1, excluding 1.
                 */
                static Real SymmetricRandom(unsigned int seed = 0);

                /**
                 * Find a random number between min and max.
                 * \param
                 *      min - The minimum number.
                 *  \param
                 *      max - The maximum number.
                 *  \param
                 *      seed - The seed to use. Optional. Defaults to 0.
                 *  \return
                 *      A random number between [min,max). Including min, 
                 *      excluding max.
                 */
                static Real IntervalRandom(Real min, Real max, 
                        unsigned int seed = 0);

                /**
                 * A fast sinus function. Uses the approximation
                 * \f[
                 * \frac{\sin(x)}{x}=1 - 0.16605x^2 + 0.00761x^4+\epsilon(x)
                 * \f]
                 *
                 * \param
                 *      value - The number to find the sinus of. Must be
                 *      between \f$ -\frac{\pi}{2} \f$ and \f$ \frac{\pi}{2} \f$.
                 *  \return
                 *      An approximation to the sinus function. 
                 *      Returns 1 if \f$x > \frac{\pi}{2}\f$ and -1 if h
                 *      \f$x < -\frac{\pi}{2}\f$.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastSin0(Real value);

                /**
                 * A fast sinus function. Uses the approximation
                 * \f[
                 * \frac{\sin(x)}{x} = 1 - 0.1666666664x^2 + 0.0083333315x^4
                 * - 0.0001984090x^6 + 0.0000027526x^8 - 0.0000000236x^10 + 
                 *   \epsilon(x).
                 * \f]
                 *
                 *   \param
                 *      value - The number to find the sinus of.
                 *  \return
                 *      An approximation to the sinus function.
                 *      Returns 1 if \f$x > \frac{\pi}{2}\f$ and -1 if h
                 *      \f$x < -\frac{\pi}{2}\f$.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastSin1(Real value);

                /**
                 * A fast cosine function. Uses the approximation
                 * \f[
                 * \cos(x) = 1 - 0.49670x^2 + 0.03705x^4 + \epsilon(x).
                 * \f]
                 *
                 * \param
                 *      value - The number to find the cosine of.
                 *  \return
                 *      An approximation to the cosine function.
                 *      Returns 1 if \f$x < 0\f$ and -1 if \f$x > \pi\f$.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastCos0(Real value);

                /**
                 * A fast cosine function. Uses the approximation
                 * \f[
                 * \cos(x) = 1 - 0.4999999963x^2 + 0.0416666418x^4 - 
                 * 0.0013888397x^6 + 0.0000247609x^8 - 0.0000002605x^10 + 
                 * \epsilon(x)
                 * \f]
                 *
                 * \param
                 *      value - The number to find the cosine of. Must be
                 *      between 0 and \f$ \pi \f$.
                 *  \return
                 *      An approximation to the cosine function.
                 *      Returns 1 if \f$x < 0\f$ and -1 if \f$x > \pi\f$.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastCos1(Real value);

                /**
                 * A fast tangent function. Uses the approximation
                 * \f[
                 * \frac{\tan(x)}{x} = 1 + 0.31755x^2 + 0.20330x^4 + 
                 * \epsilon(x)
                 * \f]
                 *
                 * \param
                 *      value - The number to find the tangent of.
                 *  \return
                 *      An approximation to the tangent.
                 *      Returns 1 if \f$x > \frac{\pi}{4}\f$, returns -1 if 
                 *      \f$x < -\frac{\pi}{4}\f$.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastTan0(Real x);

                /**
                 * A fast tangent function. Uses the approximation
                 * \f[
                 * \frac{\tan(x)}{x} = 1 + 0.3333314036x^2 + 0.1333923995x^4 +
                 * 0.0533740603x^6 + 0.0245650893x^8 + 0.0029005250x^{10} +
                 * 0.0095168091x^{12} + \epsilon(x)
                 * \f]
                 *
                 * \param
                 *      value - The number to find the tangent of.
                 *  \return
                 *      An approximation to the tangent.
                 *      Returns 1 if \f$x > \frac{\pi}{4}\f$, returns -1 if 
                 *      \f$x < -\frac{\pi}{4}\f$.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastTan1(Real x);

                /**
                 * A fast arcus sinus function. Uses the approximation
                 * \f[
                 * \arcsin(x) = \frac{\pi}{2} - \sqrt{1-x}(1.5707288 - 
                 * 0.2121144x + 0.0742610x^2 - 0.0187293x^3) + \epsilon(x)
                 * \f]
                 *
                 * \param
                 *      value - The number to find the arcus sinus of. Must be
                 *      between [-1,1].
                 *  \return
                 *      An approximation to the arcus sinus function.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastAsin0(Real value);

                /**
                 * A fast arcus sinus function. Uses the approximation
                 * \f[
                 * \arcsin(x) = \frac{\pi}{2} - \sqrt{1-x}(1.5707963050 -
                 * 0.2145988016x + 0.0889789874x^2 - 0.0501743046x^3 +
                 * 0.0308918810x^4 - 0.01708812556x^5 + 0.0066700901x^6
                 * - 0.0012624911x^7) + \epsilon(x)
                 * \f]
                 *
                 * \param
                 *      value - The number to find the arcus sinus of. Must be
                 *      between [-1,1].
                 *  \return
                 *      An approximation to the arcus sinus function.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastAsin1(Real value);

                /**
                 *  A fast arcus cosine function. Uses the approximation
                 *  \f[
                 *  \arccos(x) = \frac{\pi}{2} - \arcsin(x)
                 *  \f]
                 *
                 *  Uses the FastAsin0 to find \f$\arcsin(x)\f$.
                 *
                 *  \param
                 *      value - The number to find the arcus cosine of. Must be
                 *      between [-1, 1].
                 *  \return
                 *      An approximation to the arcus cosine function.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastAcos0(Real value);

                /**
                 *  A fast arcus cosine function. Uses the approximation
                 *  \f[
                 *  \arccos(x) = \frac{\pi}{2} - \arcsin(x)
                 *  \f]
                 *
                 *  Uses the FastAsin1 to find \f$\arcsin(x)\f$.
                 *
                 *  \param
                 *      value - The number to find the arcus cosine of. Must be
                 *      between -1 and 1.
                 *  \return
                 *      An approximation to the arcus cosine function.
                 *  \note
                 *      Returns 0 if \f$x > \f$ and \f$\pi\f$ if \f$x < -1\f$.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastAcos1(Real value);

                /**
                 *  A fast arcus tangent function. Uses the approximation
                 *  \f[
                 *  \arctan(x) = 0.9998660x - 0.3302995x^3 + 0.1801410x^5 -
                 *  0.0851330x^7 + 0.0208351x^9 + \epsilon(x)
                 *  \f].
                 *
                 *  \param
                 *      value - The number to find the arcus tangent of. Must
                 *      be between -1 and 1.
                 *  \return
                 *      An approximation to the arcus tangent function.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastAtan0(Real value);

                /**
                 *  A fast arcus tangent function. Uses the approximation
                 *  \f[
                 *  \frac{\arctan(x)}{x} = 1 - 0.3333314528x^2 + 
                 *  0.1999355085x^4 - 0.1420889944x^6 + 0.1065626393x^8 -
                 *  0.0752896400x^{10} + 0.0429096138x^{12} - 
                 *  0.0161657367x^{14} + 0.0028662257x^{16} + \epsilon(x)
                 *  \f]
                 *
                 *  \param
                 *      value - The number to find the arcus tangent of. Must
                 *      be between -1 and 1.
                 *  \return
                 *      An approximation to the arcus tangent function.
                 *  \todo
                 *      Check the speed and the error.
                 */
                static Real FastAtan1(Real value);

                /**
                 *  A fast inverse square root function. Uses Newton's method.
                 *  \param
                 *      value - The number to find the square root of. Must be
                 *      non-negative.
                 *  \return
                 *      An approximation to the inverse square root of the 
                 *      number.
                 *  \todo
                 *      Check the speed and the error.
                 *  \note
                 *      This is borrowed from the fast inverse square root
                 *      function from the quake gaming engine. The initial
                 *      guess is however borrowed form Wild Magic.
                 *
                 *      Speedup for float is about 175000, and the error
                 *      is bounded by \f$1.69*10^{-3}\f$.
                 *
                 *      Speedup for double is about 90000, and the error is
                 *      bounded by \f$1.67*10^{-3}\f$.
                 */
                static Real FastISqrt(Real value);
        };

        template<> const float Math<float>::EPSILON = FLT_EPSILON;
        template<> const float Math<float>::MAX_REAL = FLT_MAX;
        template<> const float Math<float>::PI = (float)(4.0*atan(1.0));
        template<> const float Math<float>::TWO_PI = (float)(8.0*atan(1.0));
        template<> const float Math<float>::HALF_PI = (float)(2.0*atan(1.0));
        template<> const float Math<float>::INV_PI = (float)(1.0/(4.0*atan(1.0)));
        template<> const float Math<float>::INV_TWO_PI = (float)(1.0/(8.0*atan(1.0)));
        template<> const float Math<float>::DEG_TO_RAD = (float)(4.0*atan(1.0)/180);
        template<> const float Math<float>::RAD_TO_DEG = (float)(180/(4.0*atan(1.0)));

        template<> const double Math<double>::EPSILON = DBL_EPSILON;
        template<> const double Math<double>::MAX_REAL = DBL_MAX;
        template<> const double Math<double>::PI = 4.0*atan(1.0);
        template<> const double Math<double>::TWO_PI = 8.0*atan(1.0);
        template<> const double Math<double>::HALF_PI = 2.0*atan(1.0);
        template<> const double Math<double>::INV_PI = 1.0/(4.0*atan(1.0));
        template<> const double Math<double>::INV_TWO_PI = 1.0/(8.0*atan(1.0));
        template<> const double Math<double>::DEG_TO_RAD = 4.0*atan(1.0)/180;
        template<> const double Math<double>::RAD_TO_DEG = 180/(4.0*atan(1.0));

        //---------------------------------------------------------------------
        // Find the sinus of the value.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Sin(Real value)
        {
            return (Real) sin(value);
        }

        //---------------------------------------------------------------------
        // Find the cosine of the value.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Cos(Real value)
        {
            return (Real) cos(value);
        }

        //---------------------------------------------------------------------
        // Find the tangent of the value.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Tan(Real value)
        {
            return (Real) tan(value);
        }

        //---------------------------------------------------------------------
        // Find the arcus sinus of the value.
        //---------------------------------------------------------------------
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


        //---------------------------------------------------------------------
        // Find the arcus cosine of the value.
        //---------------------------------------------------------------------
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

        //---------------------------------------------------------------------
        // Find the arcus tangent of the value.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Atan(Real value)
        {
            return (Real) atan(value);
        }

        //---------------------------------------------------------------------
        // Find the arcus tangent of y/x.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Atan2(Real y, Real x)
        {
            return (Real) atan2(y, x);
        }

        //---------------------------------------------------------------------
        // Find the absolute value.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Abs(Real value)
        {
            return (value < (Real) 0.0 ? -value : value);
        }

        //---------------------------------------------------------------------
        // Round to the nearest integer.
        //---------------------------------------------------------------------
        template<class Real>
        int Math<Real>::Round(Real value)
        {
            return (Real) round(value);
        }

        //---------------------------------------------------------------------
        // Round to the nearest integer upwards.
        //---------------------------------------------------------------------
        template<class Real>
        int Math<Real>::Ceil(Real value)
        {
            return (Real) ceil(value);
        }

        //---------------------------------------------------------------------
        // Round to the nearest integer downwards.
        //---------------------------------------------------------------------
        template<class Real>
        int Math<Real>::Floor(Real value)
        {
            return (Real) floor(value);
        }

        //---------------------------------------------------------------------
        // Calculate the exponential.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Exp(Real value)
        {
            return (Real) exp(value);
        }

        //---------------------------------------------------------------------
        // Find the natural logarithm of the value.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Log(Real value)
        {
            return (Real) log(value);
        }

        //---------------------------------------------------------------------
        // Find the logarithm of the value with base 10.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Log10(Real value)
        {
            return (Real) log10(value);
        }

        //---------------------------------------------------------------------
        // Find the power of the base in the exponent.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Pow(Real base, Real exponent)
        {
            return (Real) pow(base, exponent);
        }

        //---------------------------------------------------------------------
        // Find the modulo of the x by y.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Mod(Real x, Real y)
        {
            return (Real) fmod(x, y);
        }

        //---------------------------------------------------------------------
        // Find the square root of the value.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::Sqrt(Real value)
        {
            return (Real) sqrt(value);
        }

        //---------------------------------------------------------------------
        // Find the inverse square root of the value.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::ISqrt(Real value)
        {
            return (Real) (1.0/sqrt(value));
        }

        //---------------------------------------------------------------------
        // Find the sign of an integer.
        //---------------------------------------------------------------------
        template<class Real>
        int Math<Real>::Sign(int value)
        {
            if(value < 0)
                return -1;
            if(value > 0)
                return 1;
            return 0;
        }

        //---------------------------------------------------------------------
        // Find the sign of a number.
        //---------------------------------------------------------------------
        template<class Real>
        int Math<Real>::Sign(Real value)
        {
            if(value < 0)
                return -1;
            if(value > 0)
                return 1;
            return 0;
        }

        //---------------------------------------------------------------------
        // Find a random number between 0,1.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::UnitRandom(unsigned int seed)
        {
            if(seed == 0)
                srand( time(NULL) );
            else
                srand(seed);

            return ((Real) rand()) / RAND_MAX;
        }

        //---------------------------------------------------------------------
        // Find a random number between -1,1
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::SymmetricRandom(unsigned int seed)
        {
            if(seed == 0)
                srand( time(NULL) );
            else
                srand(seed);

            return Mod((Real) rand(), 2) - 1;
        }

        //---------------------------------------------------------------------
        // Find a random number between min and max.
        //---------------------------------------------------------------------
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

        //---------------------------------------------------------------------
        // Find a fast approximation to the sinus function.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::FastSin0(Real x)
        {
            Real sqr = x*x;
            Real res = 1;
            res -= (Real)0.16605*sqr;
            res += (Real) 0.00761*sqr*sqr;
            return res*x;
        }

        //---------------------------------------------------------------------
        // Find a fast approximation to the sinus function.
        //---------------------------------------------------------------------
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

        //---------------------------------------------------------------------
        // Find a fast approximation to the cosine function.
        //---------------------------------------------------------------------
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

        //---------------------------------------------------------------------
        // Find a fast approximation to the cosine function.
        //---------------------------------------------------------------------
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

        //---------------------------------------------------------------------
        // Find a fast approximation to the tangent function.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::FastTan0(Real x)
        {
            Real sqr = x*x;
            Real res = 1;
            res += 0.31755*sqr;
            res += 0.2033*sqr*sqr;
            return res*x;
        }

        //---------------------------------------------------------------------
        // Find a fast approximation to the tangent function.
        //---------------------------------------------------------------------
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

        //---------------------------------------------------------------------
        // Find a fast approximation to the arcsin function.
        //---------------------------------------------------------------------
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

        //---------------------------------------------------------------------
        // Find a fast approximation to the arcsin function.
        //---------------------------------------------------------------------
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

        //---------------------------------------------------------------------
        // Find a fast approximation to the arccos function.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::FastAcos0(Real value)
        {
            Real x = Abs(value);

            Real res = HALF_PI - FastAsin0(x);
            if(x != value)
                return res + HALF_PI;
            return res;
        }

        //---------------------------------------------------------------------
        // Find a fast approximation to the arccos function.
        //---------------------------------------------------------------------
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

        //---------------------------------------------------------------------
        // Find a fast approximation to the arctan function.
        //---------------------------------------------------------------------
        template<class Real>
        Real Math<Real>::FastAtan0(Real value)
        {
            Real x = value;
            assert(Abs(x) <= (Real)1.0 &&
                    "x must be between -1 and 1. FastAtan0");

            return (0.999866*x - 0.3302995*Pow(x,3) + 0.180141*Pow(x,5) -
                0.085133*Pow(x,7) + 0.0208351*Pow(x,9));
        }

        //---------------------------------------------------------------------
        // Find a fast approximation to the arctan function.
        //---------------------------------------------------------------------
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

        //---------------------------------------------------------------------
        // Find the fast inverse square root.
        //---------------------------------------------------------------------
        //Single precision.
        template<>
        float Math<float>::FastISqrt(float value)
        {
            float x = value;
            float xhalf = 0.5f*x;
            int i = *(int*)&x;
            i = 0x5f375a86 - (i>>1);
            x = *(float*)&i;
            return x*(1.5f - xhalf*x*x);
        }

        //Double precision.
        template<>
        double Math<double>::FastISqrt(double value)
        {
            double half = 0.5*value;
            long long i = *(long long*)&value;
            i = 0x5fe6ec85e7de30daLL - (i >> 1);
            value = *(double*)&i;
            value = value*(1.5 - half*value*value);
            return value;
        }
    }
}
#endif
