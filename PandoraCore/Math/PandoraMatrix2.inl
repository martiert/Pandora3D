/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix2.inl

Purpose : Implementation of the Matrix class from Pandora3D

Creation Date : 2010-04-14

Last Modified : sø. 27. juni 2010 kl. 22.21 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

/********************************************************************************
 * Typedefs.                                                                    *
 *******************************************************************************/
typedef Matrix2<float>          Mat2f;
typedef Matrix2<double>         Mat2d;
typedef Matrix2<int>            Mat2i;
typedef Matrix2<unsigned int>   Mat2u;

/********************************************************************************
 * Constructors.                                                                *
 *******************************************************************************/
template<class Real>
Matrix2<Real>::Matrix2()
{
}

/********************************************************************************
 * Give four numbers to put in the matrix.                                      *
 *******************************************************************************/ 
template<class Real>
Matrix2<Real>::Matrix2(const Real& a, const Real& b, 
        const Real& c, const Real& d)
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
Matrix2<Real>::Matrix2(const Real array[4])
{
    memcpy(m_data, array, 4*sizeof(Real));
}

/********************************************************************************
 * Copy a matrix to this matrix on construction of this matrix.                 *
 *******************************************************************************/
template<class Real>
Matrix2<Real>::Matrix2(const Matrix2<Real>& matrix)
{
    memcpy(m_data, matrix.m_data, 4*sizeof(Real));
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
template<class Real>
const Real Matrix2<Real>::operator()(const int row, const int col) const
{
    assert(row < 2 && col < 2 && "Index out of bounds");

    return m_data[row*2 + col];
}

/********************************************************************************
 * Set a row to the given vector.                                               *
 *******************************************************************************/
template<class Real>
void Matrix2<Real>::setRow(const int row, const Vector2<Real>& vec)
{
    assert(row < 2 && "Index out of bounds");

    m_data[row*2] = vec[0];
    m_data[row*2+1] = vec[1];
}

/********************************************************************************
 * Get the row asked for as a vector.                                           *
 *******************************************************************************/
template<class Real>
Vector2<Real> Matrix2<Real>::getRow(const int row) const
{
    assert(row < 2 && "Index out of bounds");

    return Vector2<Real>(m_data[row*2], m_data[row*2 + 1]);
}

/********************************************************************************
 * Set given column to the given vector.                                        *
 *******************************************************************************/
template<class Real>
void Matrix2<Real>::setColumn(const int col, const Vector2<Real>& vec)
{
    assert(col < 2 && "Index out of bounds");

    m_data[col] = vec[0];
    m_data[2+col] = vec[1];
}

/********************************************************************************
 * Get column number col as a vector.                                           *
 *******************************************************************************/
template<class Real>
Vector2<Real> Matrix2<Real>::getColumn(const int col) const
{
    assert(col < 2 && "Index out of bounds");

    return Vector2<Real>(m_data[col], m_data[2+col]);
}

/********************************************************************************
 * Assignment operator.                                                         *
 *******************************************************************************/
template<class Real>
Matrix2<Real>& Matrix2<Real>::operator=(const Matrix2<Real>& matrix)
{
    if(this != &matrix)
        memcpy(m_data, matrix.m_data, 4*sizeof(Real));
    return *this;
}

/********************************************************************************
 * Negation operator.                                                           *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator-() const
{
    return Matrix2<Real>(-m_data[0], -m_data[1], -m_data[2], -m_data[3]);
}

/********************************************************************************
 * Add two matrices.                                                            *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator+(const Matrix2<Real>& matrix) const
{
    return Matrix2<Real>(m_data[0]+matrix[0], m_data[1]+matrix[1], 
            m_data[2]+matrix[2], m_data[3]+matrix[3]);
}

/********************************************************************************
 * Subtract two matrices.                                                       *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator-(const Matrix2<Real>& matrix) const
{
    return Matrix2<Real>(m_data[0]-matrix[0], m_data[1]-matrix[1],
            m_data[2]-matrix[2], m_data[3]-matrix[3]);
}

/********************************************************************************
 * Multiply two matrices.                                                       *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator*(const Matrix2<Real>& matrix) const
{
    return Matrix2<Real>(m_data[0]*matrix[0] + m_data[1]*matrix[2],
            m_data[0]*matrix[1] + m_data[1]*matrix[3],
            m_data[2]*matrix[0] + m_data[3]*matrix[2],
            m_data[2]*matrix[1] + m_data[3]*matrix[3]);
}

/********************************************************************************
 * Multiply a matrix with a scalar.                                             *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator*(const Real& scalar) const
{
    return Matrix2<Real>(m_data[0]*scalar, m_data[1]*scalar,
            m_data[2]*scalar, m_data[3]*scalar);
}

/********************************************************************************
 * Divide a matrix with a scalar.                                               *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::operator/(const Real& scalar) const
{
    assert(scalar != 0 && "Division by zero");

    Real scale = 1.0/scalar;
    return Matrix2<Real>(m_data[0]*scale, m_data[1]*scale,
            m_data[2]*scale, m_data[3]*scale);
}

/********************************************************************************
 * Add a matrix to this matrix.                                                 *
 *******************************************************************************/
template<class Real>
Matrix2<Real>& Matrix2<Real>::operator+=(const Matrix2<Real>& matrix)
{
    *this = *this + matrix;
    return *this;
}

/********************************************************************************
 * Subtract a matrix from this matrix.                                          *
 *******************************************************************************/
template<class Real>
Matrix2<Real>& Matrix2<Real>::operator-=(const Matrix2<Real>& matrix)
{
    *this = *this - matrix;
    return *this;
}

/********************************************************************************
 * Multiply this matrix with a scalar.                                          *
 *******************************************************************************/
template<class Real>
Matrix2<Real>& Matrix2<Real>::operator*=(const Real& scalar)
{
    *this = *this * scalar;
    return *this;
}

/********************************************************************************
 * Divide this matrix with a scalar.                                            *
 *******************************************************************************/
template<class Real>
Matrix2<Real>& Matrix2<Real>::operator/=(const Real& scalar)
{
    *this = *this / scalar;
    return *this;
}

/********************************************************************************
 * Multiply this matrix with a vector.                                          *
 *******************************************************************************/
template<class Real>
Vector2<Real> Matrix2<Real>::operator*(const Vector2<Real>& vec) const
{
    return Vector2<Real>(m_data[0]*vec[0] + m_data[1]*vec[1],
            m_data[2]*vec[0] + m_data[3]*vec[1]);
}

/********************************************************************************
 * Get the determinant of the matrix.                                           *
 *******************************************************************************/
template<class Real>
Real Matrix2<Real>::det() const
{
    return m_data[0]*m_data[3] - m_data[1]*m_data[2];
}

/********************************************************************************
 * Get the transposed matrix.                                                   *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::transpose() const
{
    return Matrix2<Real>(m_data[0], m_data[2], m_data[1], m_data[3]);
}

/********************************************************************************
 * Get the inverse matrix.                                                      *
 *******************************************************************************/
template<class Real>
Matrix2<Real> Matrix2<Real>::inverse() const
{
    assert(det() != 0.0 && "Singular matrix");

    Real scale = 1.0/det();
    return (Matrix2<Real>(m_data[3], -m_data[1], -m_data[2], m_data[0]) * scale);
}

/********************************************************************************
 * Equality operator.                                                           *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator==(const Matrix2<Real>& mat) const
{
    return (m_data[0] == mat[0] && m_data[1] == mat[1] &&
            m_data[2] == mat[2] && m_data[3] == mat[3]);
}

/********************************************************************************
 * Inequality operator.                                                         *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator!=(const Matrix2<Real>& mat) const
{
    return !(*this == mat);
}

/********************************************************************************
 * Larger-than-or-equal-to operator.                                            *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator>=(const Matrix2<Real>& mat) const
{
    return (m_data[0] >= mat[0] && m_data[1] >= mat[1] &&
            m_data[2] >= mat[2] && m_data[3] >= mat[3]);
}

/********************************************************************************
 * Larger-than operator.                                                        *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator>(const Matrix2<Real>& mat) const
{
    return (m_data[0] > mat[0] && m_data[1] > mat[1] &&
            m_data[2] > mat[2] && m_data[3] > mat[3]);
}

/********************************************************************************
 * Smaller-than-or-equal-to operator.                                           *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator<=(const Matrix2<Real>& mat) const
{
    return (m_data[0] <= mat[0] && m_data[1] <= mat[1] &&
            m_data[2] <= mat[2] && m_data[3] <= mat[3]);
}

/********************************************************************************
 * Smaller-than operator.                                                       *
 *******************************************************************************/
template<class Real>
bool Matrix2<Real>::operator<(const Matrix2<Real>& mat) const
{
    return (m_data[0] < mat[0] && m_data[1] < mat[1] &&
            m_data[2] < mat[2] && m_data[3] < mat[3]);
}

#ifdef DEBUG
/********************************************************************************
 * Print out the matrix.                                                        *
 *******************************************************************************/
template<class Real>
void Matrix2<Real>::print() const
{
    printf("\n|%g %g|\n|%g %g|\n\n", m_data[0], m_data[1], m_data[2], 
            m_data[3]);
}
#endif

/********************************************************************************
 * So we can write Real * Matrix                                                *
 *******************************************************************************/
template<class Real>
Matrix2<Real> operator*(const Real scale, const Matrix2<Real>& mat)
{
    return mat * scale;
}
