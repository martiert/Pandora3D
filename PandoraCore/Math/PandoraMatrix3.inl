/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix3.inl

Purpose : Implementation of the Matrix3 class for Pandora3D

Creation Date : 2010-04-16

Last Modified : lø. 24. april 2010 kl. 15.50 +0200

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
 * Make a rotation matrix.                                                      *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(Real rad, const Vector3<Real>& axis)
{
    //TODO
}

/********************************************************************************
 * Make a scale matrix.                                                         *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(Real x_scale, Real y_scale, Real z_scale)
{
    m_data[0] = x_scale;    m_data[1] = 0;          m_data[2] = 0;
    m_data[3] = 0;          m_data[4] = y_scale;    m_data[5] = 0;
    m_data[6] = 0;          m_data[7] = 0;          m_data[8] = z_scale;
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
Matrix3<Real>::operator Real *()
{
    return &(m_data[0]);
}

/********************************************************************************
 * Implicit conversion to constant array.                                       *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::operator const Real *() const
{
    return &(m_data[0]);
}

/********************************************************************************
 * Get element number i.                                                        *
 *******************************************************************************/
template<class Real>
Real& Matrix3<Real>::operator[](const ptrdiff_t i)
{
    assert(i < 9 && "Index out of bounds");
    return m_data[i];
}

/********************************************************************************
 * Get number in element i.                                                     *
 *******************************************************************************/
template<class Real>
const Real Matrix3<Real>::operator[](const ptrdiff_t i) const
{
    assert(i < 9 && "Index out of bounds.");
    return m_data[i];
}

/********************************************************************************
 * Access element (row,col).                                                    *
 *******************************************************************************/
template<class Real>
Real& Matrix3<Real>::operator()(const int row, const int col)
{
    assert(row < 3 && col < 3 && "Index out of bounds.");
    return m_data[col + row*3];
}

/********************************************************************************
 * Get copy of element (row,col).                                               *
 *******************************************************************************/
template<class Real>
const Real Matrix3<Real>::operator(const int row, const int col) const
{
    assert(row < 3 && col < 3 && "Index out of bounds.");
    return m_data[col + row*3];
}

/********************************************************************************
 * Set row number row to the given vector.                                      *
 *******************************************************************************/
template<class Real>
void Matrix3<Real>::setRow(const int row, const Vector3<Real>& vec)
{
    assert(row < 3 && "Index out of bounds.");
    m_data[row*3]   = vec[0];
    m_data[row*3+1] = vec[1];
    m_data[row*3+2] = vec[2];
}

/********************************************************************************
 * Get row number row as a vector.                                              *
 *******************************************************************************/
template<class Real>
Vector3<Real> Matrix3<Real>::getRow(const int row) const
{
    assert(row < 3 && "Index out of bounds.");
    return Vector3<Real>(m_data[3*i], m_data[3*i+1], m_data[3*i+2]);
}

/********************************************************************************
 * Set column number col to the given vector.                                   *
 *******************************************************************************/
template<class Real>
void Matrix3<Real>::setColumn(const int col, const Vector3<Real>& vec)
{
    assert(col < 3 && "Index out of bounds.");
    m_data[col]     = vec[0];
    m_data[col + 3] = vec[1];
    m_data[col + 6] = vec[2];
}

/********************************************************************************
 * Get column number col as a vector.                                           *
 *******************************************************************************/
template<class Real>
Vector3<Real> Matrix3<Real>::getColumn(const int col) const
{
    assert(col < 3 && "Index out of bounds.");
    return Vector3<Real>(m_data[col], m_data[col + 3], m_data[col + 6]);
}
