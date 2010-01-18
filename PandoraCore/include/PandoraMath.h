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

#include "PandoraMath.inl"

    }
}
#endif
