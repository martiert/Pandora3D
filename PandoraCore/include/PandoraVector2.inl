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
// This file contains the implementation of the Vector2 class from Pandora3D.
// See PandoraVector2.h for more detailed explanation.
//-----------------------------------------------------------------------------

typedef Vec2<float> Vec2f;
typedef Vec2<double> Vec2d;
typedef Vec2<int> Vec2i;
typedef Vec2<unsigned int> Vec2u;

//-----------------------------------------------------------------------------
// Constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real>::Vec2(const Real x, const Real y)
{
    this->x = x;
    this->y = y;
}

//-----------------------------------------------------------------------------
// Constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real>::Vec2(const Vec2<Real>& vec)
{
    x = vec[0];
    y = vec[1];
}

//-----------------------------------------------------------------------------
// Constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real>::Vec2(const Real *vec)
{
    x = vec[0];
    y = vec[1];
}

//-----------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real>::~Vec2()
{
}

//-----------------------------------------------------------------------------
// Assignment operator.
//-----------------------------------------------------------------------------
template<class Real>
void Vec2<Real>::operator=(const Vec2<Real>& vec)
{
    x = vec[0];
    y = vec[1];
}

//-----------------------------------------------------------------------------
// Assignment operator.
//-----------------------------------------------------------------------------
template<class Real>
void Vec2<Real>::operator=(const Real *vec)
{
    x = vec[0];
    y = vec[1];
}

//-----------------------------------------------------------------------------
// Access operator.
//-----------------------------------------------------------------------------
template<class Real>
Real& Vec2<Real>::operator[](const unsigned int i)
{
    assert(i < 2 && "Index out of bounds.");

    if(i == 0)
        return x;
    return y;
}

//-----------------------------------------------------------------------------
// Implicit conversion operator.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real>::operator Real*()
{
    return &x;
}

//-----------------------------------------------------------------------------
// Addition operator.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real> Vec2<Real>::operator+(const Vec2<Real>& vec) const
{
    return Vec2<Real>(x + vec.x, y + vec.y);
}

//-----------------------------------------------------------------------------
// Subtraction operator.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real> Vec2<Real>::operator-(const Vec2<Real>& vec) const
{
    return Vec2<Real>(x - vec.x, y - vec.y);
}

//-----------------------------------------------------------------------------
// Normal vector multiplication.
//-----------------------------------------------------------------------------
template<class Real>
Real Vec2<Real>::operator*(const Vec2<Real>& vec) const
{
    return x*vec.x + y*vec.y;
}

//-----------------------------------------------------------------------------
// Multiply vector with a scalar.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real> Vec2<Real>::operator*(const Real scalar) const
{
    return Vec2<Real>(x*scalar, y*scalar);
}

//-----------------------------------------------------------------------------
// Dot multiply two vectors.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real> Vec2<Real>::dot(const Vec2<Real>& vec) const
{
    return Vec2<Real>(x*vec.x, y*vec.y);
}

//-----------------------------------------------------------------------------
// Addition operator.
//-----------------------------------------------------------------------------
template<class Real>
void Vec2<Real>::operator+=(const Vec2<Real>& vec)
{
    x += vec.x;
    y += vec.y;
}

//-----------------------------------------------------------------------------
// Subtraction operator.
//-----------------------------------------------------------------------------
template<class Real>
void Vec2<Real>::operator-=(const Vec2<Real>& vec)
{
    x -= vec.x;
    y -= vec.y;
}

//-----------------------------------------------------------------------------
// Multiplication with scalar.
//-----------------------------------------------------------------------------
template<class Real>
void Vec2<Real>::operator*=(const Real scalar)
{
    x *= scalar;
    y *= scalar;
}

//-----------------------------------------------------------------------------
// Dot multiplication.
//-----------------------------------------------------------------------------
template<class Real>
void Vec2<Real>::operator*=(const Vec2<Real>& vec)
{
    x *= vec.x;
    y *= vec.y;
}

//-----------------------------------------------------------------------------
// Equality operator.
//-----------------------------------------------------------------------------
template<class Real>
bool Vec2<Real>::operator==(const Vec2<Real>& vec) const
{
    return (x == vec.x && y == vec.y);
}

//-----------------------------------------------------------------------------
// Non equality operator.
//-----------------------------------------------------------------------------
template<class Real>
bool Vec2<Real>::operator!=(const Vec2<Real>& vec) const
{
    return !(*this == vec);
}
