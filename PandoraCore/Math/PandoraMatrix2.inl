/*
-------------------------------------------------------------------------------
File Name : PandoraMatrix2.inl

Purpose : Implementation of the Matrix class from Pandora3D

Creation Date : 2010-04-14

Last Modified : on. 14. april 2010 kl. 15.02 +0200

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

//-----------------------------------------------------------------------------
// Typedefs.
//-----------------------------------------------------------------------------
typedef Matrix2<float> Mat2f;
typedef Matrix2<double> Mat2d;
typedef Matrix2<int> Mat2i;
typedef Matrix2<unsigned int> Mat2u;

//-----------------------------------------------------------------------------
// Constructors.
//-----------------------------------------------------------------------------
template<class Real>
Matrix2<Real>::Matrix2(const Real a, const Real b, const Real c, const Real d)
{
    m_data[0] = a;
    m_data[1] = b;
    m_data[2] = c;
    m_data[3] = d;
}
