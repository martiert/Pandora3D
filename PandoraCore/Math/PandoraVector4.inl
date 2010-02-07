/*
-------------------------------------------------------------------------------
File Name : PandoraVector4.inl

Purpose : Implementation of the Vector4 class.

Creation Date : 2010-01-31

Last Modified : to. 04. feb. 2010 kl. 14.31 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

//-----------------------------------------------------------------------------
//  Default constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real>::Vector4(Real x, Real y, Real z, Real w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

//-----------------------------------------------------------------------------
//  Copy constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real>::Vector4(Vector4<Real>& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = vec.w;
}

//-----------------------------------------------------------------------------
//  Copy an array to this vector.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real>::Vector4(Real *vec)
{
    x = vec[0];
    y = vec[1];
    z = vec[2];
    w = vec[3];
}

//-----------------------------------------------------------------------------
//  Destructor.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real>::~Vector4()
{}

//-----------------------------------------------------------------------------
//  Assign a vector to this vector.
//-----------------------------------------------------------------------------
template<class Real>
void Vector4<Real>::operator=(const Vector4<Real>& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = vec.w;
}

//-----------------------------------------------------------------------------
//  Assign an array to this vector.
//-----------------------------------------------------------------------------
template<class Real>
void Vector4<Real>::operator=(const Real *vec)
{
    x = vec[0];
    y = vec[1];
    z = vec[2];
    w = vec[3];
}

//-----------------------------------------------------------------------------
//  Get element number i from the vector.
//-----------------------------------------------------------------------------
template<class Real>
Real& Vector4<Real>::operator[](const ptrdiff_t i)
{
    assert(i < 4 && "Index out of range");
    return (&x)[i];
}

//-----------------------------------------------------------------------------
//  Get value in element number i from the vector.
//-----------------------------------------------------------------------------
template<class Real>
Real Vector4<Real>::operator[](const ptrdiff_t i) const
{
    assert(i < 4 && "Index out of range");
    return (&x)[i];
}

//-----------------------------------------------------------------------------
//  Implicit conversion to array.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real>::operator Real *()
{
    return &x;
}

//-----------------------------------------------------------------------------
//  Implicit conversion to constant array.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real>::operator const Real *() const
{
    return &x;
}

//-----------------------------------------------------------------------------
//  Negate a vector.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real> Vector4<Real>::operator-() const
{
    return Vector4<Real>(-x, -y, -z, -w);
}

//-----------------------------------------------------------------------------
//  Add two vectors.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real> Vector4<Real>::operator+(const Vector4<Real>& vec) const
{
    return Vector4<Real>(x+vec.x, y+vec.y, z+vec.z, w+vec.w);
}

//-----------------------------------------------------------------------------
//  Subtract two vectors.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real> Vector4<Real>::operator-(const Vector4<Real>& vec) const
{
    return ((*this) + (-vec));
}

//-----------------------------------------------------------------------------
//  Multiply a vector with a scalar.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real> Vector4<Real>::operator*(const Real& scalar) const
{
    return Vector4<Real>(x*scalar, y*scalar, z*scalar, w*scalar);
}

//-----------------------------------------------------------------------------
//  Divide a vector with a scalar.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real> Vector4<Real>::operator/(const Real& scalar) const
{
    assert(scalar != 0 && "Can not divide by zero");
 
    Real s = ((Real) 1.0)/scalar;
    return ((*this) * s);
}

//-----------------------------------------------------------------------------
//  Dot multiply two vectors.
//-----------------------------------------------------------------------------
template<class Real>
Real Vector4<Real>::operator*(const Vector4<Real>& vec) const
{
    return (x*vec.x + y*vec.y + z*vec.z + w*vec.w);
}

//-----------------------------------------------------------------------------
//  Add a vector to this vector.
//-----------------------------------------------------------------------------
template<class Real>
void Vector4<Real>::operator+=(const Vector4<Real>& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    w += vec.w;
}

//-----------------------------------------------------------------------------
//  Subtract a vector from this vector.
//-----------------------------------------------------------------------------
template<class Real>
void Vector4<Real>::operator-=(const Vector4<Real>& vec)
{
    (*this) += -vec;
}

//-----------------------------------------------------------------------------
//  Multiply this vector with a scalar.
//-----------------------------------------------------------------------------
template<class Real>
void Vector4<Real>::operator*=(const Real& scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
}

//-----------------------------------------------------------------------------
//  Divide this vector with a scalar.
//-----------------------------------------------------------------------------
template<class Real>
void Vector4<Real>::operator/=(const Real& scalar)
{
    assert(scalar != 0 && "Can not divide by zero");
    
    Real s = ((Real) 1.0)/scalar;
    (*this) *= s;
}

//-----------------------------------------------------------------------------
//  Check if two vectors are equal.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector4<Real>::operator==(const Vector4<Real>& vec) const
{
    return ((Math<Real>::Abs(x - vec.x) < Math<Real>::EPSILON) &&
            (Math<Real>::Abs(y - vec.y) < Math<Real>::EPSILON) &&
            (Math<Real>::Abs(z - vec.z) < Math<Real>::EPSILON) &&
            (Math<Real>::Abs(w - vec.w) < Math<Real>::EPSILON));
}

//-----------------------------------------------------------------------------
//  Check if two vectors are unequal.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector4<Real>::operator!=(const Vector4<Real>& vec) const
{
    return !(*this == vec);
}

//-----------------------------------------------------------------------------
//  Check if this vector is less then another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector4<Real>::operator<(const Vector4<Real>& vec) const
{
    return (x < vec.x && y < vec.y && z < vec.z && w < vec.w);
}

//-----------------------------------------------------------------------------
//  Check if this vector is less then or equal to another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector4<Real>::operator<=(const Vector4<Real>& vec) const
{
    return (x <= vec.x && y <= vec.y && z <= vec.z && w <= vec.w);
}

//-----------------------------------------------------------------------------
//  Check if this vector is larger then another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector4<Real>::operator>(const Vector4<Real>& vec) const
{
    return (x > vec.x && y > vec.y && z > vec.z && w > vec.w);
}

//-----------------------------------------------------------------------------
//  Check if this vector is larger then or equal to another.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector4<Real>::operator>=(const Vector4<Real>& vec) const
{
    return (x >= vec.x && y >= vec.y && z >= vec.z && w >= vec.w);
}

//-----------------------------------------------------------------------------
//  Get the length of the vector.
//-----------------------------------------------------------------------------
template<class Real>
Real Vector4<Real>::length() const
{
    return Math<Real>::Sqrt(x*x + y*y + z*z + w*w);
}

//-----------------------------------------------------------------------------
//  Get the squared length of the vector.
//-----------------------------------------------------------------------------
template<class Real>
Real Vector4<Real>::lengthSquared() const
{
    return (x*x + y*y + z*z + w*w);
}

//-----------------------------------------------------------------------------
//  Normalize the vector. No error checking.
//-----------------------------------------------------------------------------
template<class Real>
void Vector4<Real>::normalize()
{
    Real len = length();
    (*this) /= len;
}

//-----------------------------------------------------------------------------
//  Normalize the vector. Error checking.
//-----------------------------------------------------------------------------
template<class Real>
bool Vector4<Real>::normalizeChecked()
{
    Real len = length();
    if(len == 0)
        return false;

    (*this) /= len;
    return true;
}

//-----------------------------------------------------------------------------
//  Allows one to write scalar * vector.
//-----------------------------------------------------------------------------
template<class Real>
Vector4<Real> operator*(const Real& scalar, const Vector4<Real>& vec)
{
    return vec*scalar;
}
