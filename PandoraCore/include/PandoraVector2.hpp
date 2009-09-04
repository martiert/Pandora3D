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

#include "PandoraMath.hpp"

namespace Pandora
{
    template<class Real>
    class Vector2
    {
        public:
            //Constructor. Default constructor makes an identity vector.
            Vector2(Real tx = 1, Real ty = 0);
            Vector2(const Vector2<Real>& vec);
            ~Vector2();

            //Assignment operators
            void operator=(const Vector2<Real>& vec);

            //Comparsion operators
            bool operator==(const Vector2<Real>& vec) const;
            bool operator!=(const Vector2<Real>& vec) const;

            //Aritmethic operators
            Vector2<Real> operator+(const Vector2<Real>& vec) const;
            Vector2<Real> operator-(const Vector2<Real>& vec) const;
            Vector2<Real> operator*(const Real& scalar) const;
            Vector2<Real> operator/(const Real& scalar) const;
            Vector2<Real> operator-() const;

            void operator+=(const Vector2<Real>& vec);
            void operator-=(const Vector2<Real>& vec);
            void operator*=(const Real& scalar);
            void operator/=(const Real& scalar);

            Real operator*(const Vector2<Real>& vec) const;

            //Data assignment
            Real operator[](int i) const;
            Real& operator[](int i);
            operator const Real* () const;
            operator Real* ();

            //Geometric operations
            Real length() const;
            Real squaredLength() const;
            Real dot(const Vector2<Real>& vec) const;
            Real normalize();
            Vector2<Real> perp() const;
            Vector2<Real> unitPerp() const;
            Real dotPerp(const Vector2<Real>& vec) const;
        public:
            Real x, y;
    };

//#############################################################################
//
//                   Constructor. Sets x = tx and y = ty.
//
//#############################################################################

    template<class Real>
    Vector2<Real>::Vector2(Real tx, Real ty)
    {
        x = tx;
        y = ty;
    }

//#############################################################################
//
//           Copy constructor. Copies the vector sent as argument.
//
//#############################################################################

    template<class Real>
    Vector2<Real>::Vector2(const Vector2<Real>& vec)
    {
        x = vec.x;
        y = vec.y;
    }

//#############################################################################
//
//                       Destructor. Does nothing.
//
//#############################################################################

    template<class Real>
    Vector2<Real>::~Vector2() { }

//#############################################################################
//
//      Assignment operator. Sets this vector equal to the other.
//
//#############################################################################

    template<class Real>
    void Vector2<Real>::operator=(const Vector2<Real>& vec)
    {
        x = vec.x;
        y = vec.y;
    }

//#############################################################################
//
//  Comparison operator. Checks if the two values in the vectors are equal.
//
//#############################################################################


    template<class Real>
    bool Vector2<Real>::operator==(const Vector2<Real>& vec) const
    {
        return x == vec.x && y == vec.y;
    }

//#############################################################################
//
// Comparison operator, checks if this vector is different from the other.
//
//#############################################################################

    template<class Real>
    bool Vector2<Real>::operator!=(const Vector2<Real>& vec) const
    {
        return !operator==(vec);
    }

//#############################################################################
//
//    Adds two vector. Element x are added together and element y are added 
//                                  together
//
//#############################################################################


    template<class Real>
    Vector2<Real> Vector2<Real>::operator+(const Vector2<Real>& vec) const
    {
        return Vector2<Real>(x+vec.x,y+vec.y);
    }

//#############################################################################
//
//                              Subtracts two vector.
//
//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::operator-(const Vector2<Real>& vec) const
    {
        return Vector2<Real>(x - vec.x,y - vec.y);
    }

//#############################################################################
//
//   Multiplies a scalar to a vector. Multiplies each element of the vector
//                                with the scalar
//
//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::operator*(const Real& scalar) const
    {
        return Vector2<Real>(x*scalar, y*scalar);
    }

//#############################################################################
//
//  Divides a vector with a scalar, the same manner as the multiplication.
//                   Fails in debug mode if scalar is zero.
//
//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::operator/(const Real& scalar) const
    {
        assert(scalar != (Real) 0.0);
        return Vector2<Real>(x / scalar, y / scalar);
    }

//#############################################################################
//
//                  Returns a negated vector of this vector.
//
//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::operator-() const
    {
        return Vector2<Real>(-x, -y);
    }

//#############################################################################
//
//                      Adds a vector to this vector.
//
//#############################################################################

    template<class Real>
    void Vector2<Real>::operator+=(const Vector2<Real>& vec)
    {
        *this = *this + vec;
    }

//#############################################################################
//
//                      Subtracts a vector from this vector.
//
//#############################################################################

    template<class Real>
    void Vector2<Real>::operator-=(const Vector2<Real>& vec)
    {
        *this = *this - vec;
    }

//#############################################################################
//
//                   Multiplies this vector with a scalar.
//
//#############################################################################

    template<class Real>
    void Vector2<Real>::operator*=(const Real& scalar)
    {
        *this = *this * scalar;
    }

//#############################################################################
//
//                          Divides this vector with a scalar.
//
//#############################################################################

    template<class Real>
    void Vector2<Real>::operator/=(const Real& scalar)
    {
        *this = *this / scalar;
    }

//#############################################################################
//
// Multiplies two vectors. If vec1 = (x1,y1) and vec2 = (x2,y2). The result is:
//                                  x1*x2 + y1*y2
//
//#############################################################################

    template<class Real>
    Real Vector2<Real>::operator*(const Vector2<Real>& vec) const
    {
        return vec.x*x + vec.y*y;
    }

//#############################################################################
//
//              Get element number i from the vector.
//
//#############################################################################

    template<class Real>
    Real Vector2<Real>::operator[](int i) const
    {
        assert(i < 2);
        return *(&x+i);
    }

//#############################################################################
//
//              Get refference to element number i from the vector.
//
//#############################################################################

    template<class Real>
    Real& Vector2<Real>::operator[](int i)
    {
        assert(i < 2);
        return *(&x + i);
    }

//#############################################################################
//
//                      Returns the data as a constant pointer.
//
//#############################################################################

    template<class Real>
    Vector2<Real>::operator const Real* () const
    {
        return &x;
    }

//#############################################################################
//
//                          Returns the data as a pointer.
//
//#############################################################################

    template<class Real>
    Vector2<Real>::operator Real*()
    {
        return &x;
    }

//#############################################################################
//
//                      Returns the length of the vector.
//
//#############################################################################

    template<class Real>
    Real Vector2<Real>::length() const
    {
        return Math<Real>::Sqrt(x*x + y*y);
    }

//#############################################################################
//
//                  Returns the squared length of the vector.
//
//#############################################################################

    template<class Real>
    Real Vector2<Real>::squaredLength() const
    {
        return x*x + y*y;
    }

//#############################################################################
//
//               Computes the dot product of two vectors.
//
//#############################################################################

    template<class Real>
    Real Vector2<Real>::dot(const Vector2<Real>& vec) const
    {
        return (*this) * vec;
    }

//#############################################################################
//
//      Normalizes the vector, and returns the length of the old vector.
//
//#############################################################################

    template<class Real>
    Real Vector2<Real>::normalize()
    {
        Real len = length();
        x /= len;
        y /= len;
        return len;
    }

//#############################################################################
//
//                      Returns the perpendicular vector.
//
//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::perp() const
    {
        return Vector2<Real>(y,-x);
    }

//#############################################################################
//
//               Returns the normalized perpendicular vector.
//
//#############################################################################

    template<class Real>
    Vector2<Real> Vector2<Real>::unitPerp() const
    {
        return (*this).perp().normalize();
    }

//#############################################################################
//
//              Multiplies the perpendicular vector with a vector.
//
//#############################################################################

    template<class Real>
    Real Vector2<Real>::dotPerp(const Vector2<Real>& vec) const
    {
        return perp() * vec;
    }

//#############################################################################
}
