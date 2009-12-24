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

#include <math.h>

namespace Pandora
{
    /**
     * This namespace is for all the mathematical functions.
     */
    namespace Math
    {
        template<class Real>
        /**
         * The Math class. Holds all the normal mathematical functions, like
         * trigonometric functions, logarithm, power, square roots, etc. Also
         * holds mathematical constant like PI, e, etc.
         */
        class Math
        {
            public:
                static const Real EPSILON;
                static const Real MAX_REAL;
                static const Real PI;
                static const Real TWO_PI;
                static const Real HALF_PI;
                static const Real DEG_TO_RAD;
                static const Real RAD_TO_DEG;

                /**
                 * Calculate the cosine value.
                 * \param
                 *      value - The number of radians.
                 *  \return
                 *      The cosine value.
                 */
                static Real cos(Real value);

                /**
                 * Calculate the sinus value.
                 * \param
                 *      value - The number of radians.
                 *  \return
                 *      The sinus value.
                 */
                static Real sin(Real value);

                /**
                 * Calculate the tangent value.
                 * \param
                 *      value - The number of radians.
                 *  \return
                 *      The tangent value.
                 */
                static Real tan(Real value);

                /**
                 * Calculates the inverse sinus.
                 * \param
                 *      value - The sinus value.
                 *  \return
                 *      The number of radians in the interval [-pi/2,pi/2].
                 */
                static Real asin(Real value);

                /**
                 * Calculates the inverse cosine.
                 * \param
                 *      value - The cosine value.
                 *  \return
                 *      The number of radians in the interval [0,pi].
                 */
                static Real acos(Real value);

                /**
                 * Calculates the inverse tangent.
                 * \param
                 *      value - The tangent value.
                 *  \return
                 *      The number of radians in the interval [-pi/2,pi/2].
                 */
                static Real atan(Real value);

                /**
                 * Calculates the inverse tangent of y/x.
                 * \param
                 *      y - A value representing an y-coordinate.
                 *      x - A value representing an x-coordinate.
                 *  \return
                 *      The number of radians in the interval [-pi,pi].
                 */
                static Real atan2(Real x, Real y);

                /**
                 * Calculates the absolute value of a number.
                 * \param
                 *      value - The number.
                 * \return
                 *      The absolute value of the number.
                 */
                static Real abs(Real value);

                /**
                 * Rounds the number to the nearest integer.
                 * \param
                 *      value - The number.
                 *  \return
                 *      The nearest integer.
                 */
                static int round(Real value);

                /**
                 * Round the number to the nearest integer upwards.
                 * \param
                 *      value - The number.
                 *  \return
                 *      The nearest integer upwards.
                 */
                static int ceil(Real value);

                /**
                 * Round the number to the nearest integers downwards.
                 * \param
                 *      value - The number.
                 *  \return
                 *      The nearest integer downwards.
                 */
                static int floor(Real value);

                /**
                 * Find e to the power value.
                 * \param
                 *      value - The power to use.
                 *  \return
                 *      e^value.
                 */
                static Real exp(Real value);

                /**
                 * Find the logarithm of the number. Uses base e.
                 * \param
                 *      value - The number to take the logarithm of.
                 *  \return
                 *      log(value).
                 */
                static Real log(Real value);

                /**
                 * Find the logarithm of the number. Uses base 10.
                 * \param
                 *      value - The number to take the logarithm of.
                 *  \return
                 *      log(value) with base 10.
                 */
                static Real log10(Real value);

                /**
                 * Find the base to the power exponent.
                 * \param
                 *      base - The base to use.
                 *      exponent - The exponent to use.
                 *  \return
                 *      base to the power exponent.
                 */
                static Real pow(Real base, Real exponent);

                /**
                 * Find the modulo of x by y.
                 * \param
                 *      x - The number to take modulo by.
                 *      y - The number to use as divisor.
                 *  \return
                 *      x mod y.
                 */
                static Real mod(Real x, Real y);

                /**
                 * Find the square root of a number.
                 * \param
                 *      value - The number to find the square root of.
                 *  \return
                 *      The square root of value.
                 *  \note
                 *      Only non-negative numbers.
                 */
                static Real sqrt(Real value);

                /**
                 * Find the inverse square root of a number.
                 * \param
                 *      value - The number to find the inverse square root of.
                 *  \return
                 *      The inverse square root of value.
                 *  \note
                 *      Only strict positive numbers.
                 */
                static Real isqrt(Real value);
        };

        template<class Real>
        Real Math<Real>::sin(Real value)
        {
            return (Real)sin(value);
        }
    }
}
