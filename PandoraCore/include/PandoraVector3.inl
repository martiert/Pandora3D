/*
-------------------------------------------------------------------------------
File Name : PandoraVector3.inl

Purpose : The implementation of the 3D vector class.

Creation Date : 2010-01-28

Last Modified : fr. 29. jan. 2010 kl. 10.25 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

//-----------------------------------------------------------------------------
// Default constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vec3<Real>::Vec3(const Real& x, const Real& y, const Real& z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

//-----------------------------------------------------------------------------
// Copy constructor.
//-----------------------------------------------------------------------------
template<class Real>
Vec3<Real>::Vec3(const Vec3<Real>& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

//-----------------------------------------------------------------------------
// Copy an array to this vector.
//-----------------------------------------------------------------------------
template<class Real>
Vec3<Real>::Vec3(const Real *vec)
{
    x = vec[0];
    y = vec[1];
    z = vec[2];
}

//-----------------------------------------------------------------------------
// Destructor.
//-----------------------------------------------------------------------------
template<class Real>
Vec3<Real>::~Vec3()
{ }

//-----------------------------------------------------------------------------
// Implicit conversion to constant pointer.
//-----------------------------------------------------------------------------
template<class Real>
Vec3<Real>::operator const Real* () const
{
    return &x;
}

//-----------------------------------------------------------------------------
// Implicit conversion.
//-----------------------------------------------------------------------------
template<class Real>
Vec3<Real>::operator const Real* ()
{
    return &x;
}

//-----------------------------------------------------------------------------
// Assignment operator.
//-----------------------------------------------------------------------------
template<class Real>
Real& Vec3<Real>::operator[](const ptrdiff_t i)
{
    assert(i < 3 && "Index out of range\n");

    if(i == 0)
        return x;
    if(i == 1)
        return y;
    return z;
}

//-----------------------------------------------------------------------------
// Get value from index i.
//-----------------------------------------------------------------------------
template<class Real>
Real Vec3<Real>::operator[](const ptrdiff_t i) const
{
    assert(i < 3 && "Index out of range\n");

    if(i == 0)
        return x;
    if(i == 1)
        return y;
    return z;
}
