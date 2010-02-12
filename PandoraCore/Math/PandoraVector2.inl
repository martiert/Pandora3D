/*
-------------------------------------------------------------------------------
File Name : PandoraVector2.inl

Purpose : Implementation of the Vector2 class used in Pandora3D

Creation Date : 2010-01-26

Last Modified : fr. 12. feb. 2010 kl. 17.06 +0100

Created By : Martin Ertsås
-------------------------------------------------------------------------------
*/

//-----------------------------------------------------------------------------
//  Typedefs.
//-----------------------------------------------------------------------------
typedef Vector2<float> Vec2f;
typedef Vector2<double> Vec2d;
typedef Vector2<int> Vec2i;
typedef Vector2<unsigned int> Vec2u;

//-----------------------------------------------------------------------------
//  Constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real>::Vector2(const Real& x, const Real& y)
{
    this->x = x;
    this->y = y;
}

//-----------------------------------------------------------------------------
//  Constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real>::Vector2(Vector2<Real>& vec)
{
    x = vec[0];
    y = vec[1];
}

//-----------------------------------------------------------------------------
//  Constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real>::Vector2(Real vec[2])
{
    x = vec[0];
    y = vec[1];
}

//-----------------------------------------------------------------------------
//  Destructor
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real>::~Vector2()
{
}

//-----------------------------------------------------------------------------
//  Assignment operator.
//-----------------------------------------------------------------------------
template<class Real>
void Vector2<Real>::operator=(Vector2<Real>& vec)
{
    x = vec[0];
    y = vec[1];
}

//-----------------------------------------------------------------------------
//  Assignment operator.
//-----------------------------------------------------------------------------
template<class Real>
void Vector2<Real>::operator=(Real vec[2])
{
    x = vec[0];
    y = vec[1];
}

//-----------------------------------------------------------------------------
//  Access operator.
//-----------------------------------------------------------------------------
template<class Real>
Real& Vector2<Real>::operator[](const ptrdiff_t i)
{
    assert(i < 2 && "Index out of bounds.");

    if(i == 0)
        return x;
    return y;
}

//-----------------------------------------------------------------------------
//  Get a copy of element number i from the vector.
//-----------------------------------------------------------------------------
template<class Real>
Real Vector2<Real>::operator[](const ptrdiff_t i) const
{
    assert(i < 2 && "Index out of bounds.");

    if(i == 0)
        return x;
    return y;
}

//-----------------------------------------------------------------------------
//  Implicit conversion operator.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real>::operator Real*()
{
    return &x;
}

//-----------------------------------------------------------------------------
//  Get a constant copy of the vector.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real>::operator const Real* () const
{
    return &x;
}

//-----------------------------------------------------------------------------
//  Addition operator.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real> Vector2<Real>::operator+(const Vector2<Real>& vec) const
{
    return Vector2<Real>(x + vec.x, y + vec.y);
}

//-----------------------------------------------------------------------------
//  Subtraction operator.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real> Vector2<Real>::operator-(const Vector2<Real>& vec) const
{
    return Vector2<Real>(x - vec.x, y - vec.y);
}

//-----------------------------------------------------------------------------
//  Normal vector multiplication.
//-----------------------------------------------------------------------------
template<class Real>
Real Vector2<Real>::operator*(const Vector2<Real>& vec) const
{
    return x*vec.x + y*vec.y;
}

//-----------------------------------------------------------------------------
//  Multiply vector with a scalar.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real> Vector2<Real>::operator*(const Real& scalar) const
{
    return Vector2<Real>(x*scalar, y*scalar);
}

//-----------------------------------------------------------------------------
//  Divide vector with a scalar.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real> Vector2<Real>::operator/(const Real& scalar) const
{
    assert( scalar != (Real) 0.0 );
    Real s = ((Real) 1.0)/scalar;
    return (*this) * s;
}

//-----------------------------------------------------------------------------
//  Addition operator.
//-----------------------------------------------------------------------------
template<class Real>
void Vector2<Real>::operator+=(const Vector2<Real>& vec)
{
    x += vec.x;
    y += vec.y;
}

//-----------------------------------------------------------------------------
//  Subtraction operator.
//-----------------------------------------------------------------------------
template<class Real>
void Vector2<Real>::operator-=(const Vector2<Real>& vec)
{
    x -= vec.x;
    y -= vec.y;
}

//-----------------------------------------------------------------------------
//  Multiplication with scalar.
//-----------------------------------------------------------------------------
template<class Real>
void Vector2<Real>::operator*=(const Real& scalar)
{
    x *= scalar;
    y *= scalar;
}

//-----------------------------------------------------------------------------
//  Division with scalar.
//-----------------------------------------------------------------------------
template<class Real>
void Vector2<Real>::operator/=(const Real& scalar)
{
    assert( scalar != (Real) 0.0 );
    Real s = ((Real) 1.0)/scalar;
    (*this) *= s;
}

//-----------------------------------------------------------------------------
//  Equality operator.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector2<Real>::operator==(const Vector2<Real>& vec) const
{
    return (Math<Real>::Abs(x - vec.x) < Math<Real>::EPSILON && 
            Math<Real>::Abs(y - vec.y) < Math<Real>::EPSILON);
}

//-----------------------------------------------------------------------------
//  Non equality operator.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector2<Real>::operator!=(const Vector2<Real>& vec) const
{
    return !(*this == vec);
}

//-----------------------------------------------------------------------------
//  Check if this vector is larger then another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector2<Real>::operator>(const Vector2<Real>& vec) const
{
    return (x > vec.x && y > vec.y);
}

//-----------------------------------------------------------------------------
//  Check if this vector is larger then or equal to another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector2<Real>::operator>=(const Vector2<Real>& vec) const
{
    return (x >= vec.x && y >= vec.y);
}

//-----------------------------------------------------------------------------
//  Check if this vector is smaller then another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector2<Real>::operator<(const Vector2<Real>& vec) const
{
    return (x < vec.x && y < vec.y);
}

//-----------------------------------------------------------------------------
//  Check if this vector is smaller then or equal to another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector2<Real>::operator<=(const Vector2<Real>& vec) const
{
    return (x <= vec.x && y <= vec.y);
}

//-----------------------------------------------------------------------------
//  Negate a vector.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real> Vector2<Real>::operator-() const
{
    return Vector2<Real>(-x, -y);
}

//-----------------------------------------------------------------------------
//  Dot product between two vectors.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real> Vector2<Real>::dotprod(const Vector2<Real>& vec) const
{
    return Vector2<Real>(x * vec.x, y * vec.y);
}

//-----------------------------------------------------------------------------
//  Return length of the vector.
//-----------------------------------------------------------------------------
template<class Real>
Real Vector2<Real>::length() const
{
    return Math<Real>::Sqrt(x*x + y*y);
}

//-----------------------------------------------------------------------------
//  Return squared length of the vector.
//-----------------------------------------------------------------------------
template<class Real>
Real Vector2<Real>::lengthSquared() const
{
    return (x*x + y*y);
}

//-----------------------------------------------------------------------------
//  Normalize the vector.
//-----------------------------------------------------------------------------
template<class Real>
void Vector2<Real>::normalize()
{
    Real scale = length();
    *this /= scale;
}

//-----------------------------------------------------------------------------
//  Normalize the vector. Check if the scaling value is zero.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector2<Real>::normalizeChecked()
{
    Real scale = length();
    if(scale == 0)
        return false;

    *this /= scale;
    return true;
}

//-----------------------------------------------------------------------------
//  Allows one to write scalar * vector.
//-----------------------------------------------------------------------------
template<class Real>
Vector2<Real> operator*(const Real& scalar, const Vector2<Real>& vec)
{
    return vec * scalar;
}
