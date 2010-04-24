/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix3.inl

Purpose : Implementation of the Matrix3 class for Pandora3D

Creation Date : 2010-04-16

Last Modified : ma. 19. april 2010 kl. 18.06 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

/********************************************************************************
 * Typedefs.                                                                    *
 *******************************************************************************/
typedef Matrix3<float>          Mat3f;
typedef Matrix3<double>         Mat3d;
typedef Matrix3<int>            Mat3i;
typedef Matrix3<unsigned int>   Mat3u;

/********************************************************************************
 * Default constructor.                                                         *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(Real a0, Real a1, Real a2, Real a3, Real a4, Real a5, 
        Real a6, Real a7, Real a8)
{
    m_data[0] = a0;     m_data[1] = a1;     m_data[2] = a2;
    m_data[3] = a3;     m_data[4] = a4;     m_data[5] = a5;
    m_data[6] = a6;     m_data[7] = a7;     m_data[8] = a8;
}

/********************************************************************************
 * Copy an array to this matrix.                                                *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(Real array[9])
{
    m_data[0] = array[0];   m_data[1] = array[1];   m_data[2] = array[2];
    m_data[3] = array[3];   m_data[4] = array[4];   m_data[5] = array[5];
    m_data[6] = array[6];   m_data[7] = array[7];   m_data[8] = array[8];
}

/********************************************************************************
 * Copy constructor.                                                            *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(Matrix3<Real>& mat)
{
    m_data[0] = mat[0];     m_data[1] = mat[1];     m_data[2] = mat[2];
    m_data[3] = mat[3];     m_data[4] = mat[4];     m_data[5] = mat[5];
    m_data[6] = mat[6];     m_data[7] = mat[7];     m_data[8] = mat[8];
}

/********************************************************************************
 * Copy a 2D matrix to this matrix.                                             *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(Matrix3<Real>& mat)
{
    m_data[0] = mat[0];     m_data[1] = mat[1];     m_data[2] = (Real) 0.0;
    m_data[3] = mat[2];     m_data[4] = mat[3];     m_data[5] = (Real) 0.0;
    m_data[6] = (Real) 0.0; m_data[7] = (Real) 0.0; m_data[8] = (Real) 1.0;
}

/********************************************************************************
 * Implicit conversion.                                                         *
 *******************************************************************************/
template<class Real>
operator Real *()
{
    return &(m_data[0]);
}

/********************************************************************************
 * Implicit conversion to constant array.                                       *
 *******************************************************************************/
template<class Real>
operator const Real *() const
{
    return &(m_data[0]);
}
