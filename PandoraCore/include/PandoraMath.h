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
         * \todo
         *      Make the constant, and add some fast functions.
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
                 *      The number of radians in the interval [-pi/2,pi/2].
                 *  \note
                 *      If the value is less then -1 we return PI, and if the
                 *      value us larger then 1, we return 0.
                 */
                static Real Asin(Real value);

                /**
                 * Calculates the inverse cosine.
                 * \param
                 *      value - The cosine value.
                 *  \return
                 *      The number of radians in the interval [0,pi].
                 *  \note
                 *      If the value is less then -1 we return -PI/2, if the
                 *      value is larger then 1, we return PI/2.
                 */
                static Real Acos(Real value);

                /**
                 * Calculates the inverse tangent.
                 * \param
                 *      value - The tangent value.
                 *  \return
                 *      The number of radians in the interval [-pi/2,pi/2].
                 */
                static Real Atan(Real value);

                /**
                 * Calculates the inverse tangent of y/x.
                 * \param
                 *      y - A value representing an y-coordinate.
                 *      x - A value representing an x-coordinate.
                 *  \return
                 *      The number of radians in the interval [-pi,pi].
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
                 *      exponent - The exponent to use.
                 *  \return
                 *      base to the power exponent.
                 */
                static Real Pow(Real base, Real exponent);

                /**
                 * Find the modulo of x by y.
                 * \param
                 *      x - The number to take modulo by.
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
                static Real Isqrt(Real value);
        };

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
        Real Math<Real>::Isqrt(Real value)
        {
            return (Real) (1.0/sqrt(value));
        }
    }
}
#endif
