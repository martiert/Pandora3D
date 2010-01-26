/*
-------------------------------------------------------------------------------
File Name : PandoraVector2.inl

Purpose : Implementation of the Vector2 class used in Pandora3D

Creation Date : 2010-01-26

Last Modified : ti. 26. jan. 2010 kl. 13.09 +0100

Created By : Martin Ertsås
-------------------------------------------------------------------------------
*/

//-----------------------------------------------------------------------------
// Typedefs.
//-----------------------------------------------------------------------------
typedef Vec2<float> Vec2f;
typedef Vec2<double> Vec2d;
typedef Vec2<int> Vec2i;
typedef Vec2<unsigned int> Vec2u;

//-----------------------------------------------------------------------------
// Constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real>::Vec2(const Real& x, const Real& y)
{
    this->x = x;
    this->y = y;
}

//-----------------------------------------------------------------------------
// Constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real>::Vec2(Vec2<Real>& vec)
{
    x = vec[0];
    y = vec[1];
}

//-----------------------------------------------------------------------------
// Constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real>::Vec2(Real *vec)
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
void Vec2<Real>::operator=(Vec2<Real>& vec)
{
    x = vec[0];
    y = vec[1];
}

//-----------------------------------------------------------------------------
// Assignment operator.
//-----------------------------------------------------------------------------
template<class Real>
void Vec2<Real>::operator=(Real *vec)
{
    x = vec[0];
    y = vec[1];
}

//-----------------------------------------------------------------------------
// Access operator.
//-----------------------------------------------------------------------------
template<class Real>
Real& Vec2<Real>::operator[](const ptrdiff_t i)
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
Vec2<Real> Vec2<Real>::operator*(const Real& scalar) const
{
    return Vec2<Real>(x*scalar, y*scalar);
}

//-----------------------------------------------------------------------------
// Divide vector with a scalar.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real> Vec2<Real>::operator/(const Real& scalar) const
{
    assert( scalar != (Real) 0.0 );
    return Vec2<Real>(x/scalar, y/scalar);
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
void Vec2<Real>::operator*=(const Real& scalar)
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
// Division with scalar.
//-----------------------------------------------------------------------------
template<class Real>
void Vec2<Real>::operator/=(const Real& scalar)
{
    assert( scalar != (Real) 0.0 );
    x /= scalar;
    y /= scalar;
}

//-----------------------------------------------------------------------------
// Equality operator.
//-----------------------------------------------------------------------------
template<class Real>
bool Vec2<Real>::operator==(const Vec2<Real>& vec) const
{
    return (Math<Real>::Abs(x - vec.x) < Math<Real>::EPSILON && 
            Math<Real>::Abs(y - vec.y) < Math<Real>::EPSILON);
}

//-----------------------------------------------------------------------------
// Non equality operator.
//-----------------------------------------------------------------------------
template<class Real>
bool Vec2<Real>::operator!=(const Vec2<Real>& vec) const
{
    return !(*this == vec);
}

//-----------------------------------------------------------------------------
// Check if this vector is larger then another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vec2<Real>::operator>(const Vec2<Real>& vec) const
{
    return (x > vec.x && y > vec.y);
}

//-----------------------------------------------------------------------------
// Check if this vector is larger then or equal to another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vec2<Real>::operator>=(const Vec2<Real>& vec) const
{
    return (x >= vec.x && y >= vec.y);
}

//-----------------------------------------------------------------------------
// Check if this vector is smaller then another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vec2<Real>::operator<(const Vec2<Real>& vec) const
{
    return (x < vec.x && y < vec.y);
}

//-----------------------------------------------------------------------------
// Check if this vector is smaller then or equal to another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vec2<Real>::operator<=(const Vec2<Real>& vec) const
{
    return (x <= vec.x && y <= vec.y);
}

//-----------------------------------------------------------------------------
// Dot product between two vectors.
//-----------------------------------------------------------------------------
template<class Real>
Vec2<Real> Vec2<Real>::dotprod(const Vec2<Real>& vec) const
{
    return Vec2<Real>(x * vec.x, y * vec.y);
}

//-----------------------------------------------------------------------------
// Return length of the vector.
//-----------------------------------------------------------------------------
template<class Real>
Real Vec2<Real>::length() const
{
    Real length = x*x + y*y;
    return Math<Real>::Sqrt(length);
}

//-----------------------------------------------------------------------------
// Return squared length of the vector.
//-----------------------------------------------------------------------------
template<class Real>
Real Vec2<Real>::lengthSquared() const
{
    return (x*x + y*y);
}

//-----------------------------------------------------------------------------
// Normalize the vector.
//-----------------------------------------------------------------------------
template<class Real>
void Vec2<Real>::normalize()
{
    Real scale = length();
    *this /= scale;
}

//-----------------------------------------------------------------------------
// Normalize the vector. Check if the scaling value is zero.
//-----------------------------------------------------------------------------
template<class Real>
bool Vec2<Real>::normalizeChecked()
{
    Real scale = length();
    if(scale == 0)
        return false;

    *this /= scale;
    return true;
}
