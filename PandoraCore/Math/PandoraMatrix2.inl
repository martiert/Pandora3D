/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix2.inl

Purpose : Implementation of the Matrix class from Pandora3D

Creation Date : 2010-04-14

Last Modified : on. 14. april 2010 kl. 17.22 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

/********************************************************************************
 * Typedefs.                                                                    *
 *******************************************************************************/
typedef Matrix2<float> Mat2f;
typedef Matrix2<double> Mat2d;
typedef Matrix2<int> Mat2i;
typedef Matrix2<unsigned int> Mat2u;

/********************************************************************************
 * Constructors.                                                                *
 *                                                                              *
 * Give four numbers to put in the matrix.                                      *
 *******************************************************************************/ 
template<class Real>
Matrix2<Real>::Matrix2(const Real a, const Real b, const Real c, const Real d)
{
    m_data[0] = a;
    m_data[1] = b;
    m_data[2] = c;
    m_data[3] = d;
}

/********************************************************************************
 * Give an array to use as the matrix.                                          *
 *******************************************************************************/
template<class Real>
Matrix2<Real>::Matrix2(Real array[4])
{
    m_data[0] = array[0];
    m_data[1] = array[1];
    m_data[2] = array[2];
    m_data[3] = array[3];
}

/********************************************************************************
 * Copy a matrix to this matrix on construction of this matrix.                 *
 *******************************************************************************/
template<class Real>
Matrix2<Real>::Matrix2(Matrix2<Real>& matrix)
{
    m_data[0] = matrix[0];
    m_data[1] = matrix[1];
    m_data[2] = matrix[2];
    m_data[3] = matrix[3];
}

/********************************************************************************
 * Implicit conversion to array.                                                *
 *******************************************************************************/ 
template<class Real>
Matrix2<Real>::operator Real *()
{
    return &(m_data[0]);
}

/********************************************************************************
 * Implicit conversion to constant array.                                       * 
 *******************************************************************************/ 
template<class Real>
Matrix2<Real>::operator const Real *() const
{
    return &(m_data[0]);
}

/********************************************************************************
 * Get index number i from the matrix.                                          * 
 *******************************************************************************/ 
template<class Real>
Real& Matrix2<Real>::operator[](const ptrdiff_t i)
{
    assert( i < 4 && "Index out of bounds\n");

    return m_data[i];
}

/********************************************************************************
 * Return constant reference to index number i in the matrix.                   * 
 *******************************************************************************/ 
template<class Real>
const Real Matrix2<Real>::operator[](const ptrdiff_t i) const
{
     assert( i < 4 && "Index out of bounds\n");   
     return m_data[i];
}

/********************************************************************************
 * Get element in (row,col) from the matrix.                                    * 
 *******************************************************************************/ 
template<class Real>
Real& Matrix2<Real>::operator()(const int row, const int col)
{
    assert(row < 2 && col < 2 && "Index out of bounds");

    return m_data[row*2 + col];
}

/********************************************************************************
 * Get constant refference to element (row,col) in the matrix.                  * 
 *******************************************************************************/ 
