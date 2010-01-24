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
        };

#include "PandoraMath.inl"

    }
}
#endif
