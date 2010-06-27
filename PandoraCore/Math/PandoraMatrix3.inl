/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix3.inl

Purpose : Implementation of the Matrix3 class for Pandora3D

Creation Date : 2010-04-16

Last Modified : sø. 27. juni 2010 kl. 22.16 +0200

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
Matrix3<Real>::Matrix3(Real rad, const Vector3<Real>& r)
{
    //Normalize the axis.
    r.normalize();
    Real t_cos = Math<Real>::Cos(rad);
    Real t_sin = Math<Real>::Sin(rad);

    m_data[0] = t_cos + (1 - t_cos)*r.x*r.x;
    m_data[1] = (1 - t_cos)*r.x*r.y - r.z*t_sin;
    m_data[2] = (1 - t_cos)*r.x*r.z + r.y*t_sin;

    m_data[3] = (1 - t_cos)*r.x*r.y + r.z*t_sin;
    m_data[4] = t_cos + (1 - t_cos)*r.y*r.y;
    m_data[5] = (1 - t_cos)*r.y*r.z - r.x*t_sin;

    m_data[6] = (1 - t_cos)*r.x*r.z - r.y*t_sin;
    m_data[7] = (1 - t_cos)*r.y*r.z + r.x*t_sin;
    m_data[8] = t_cos + (1 - t_cos)*r.z*r.z;
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
    memcpy(m_data, array, 9);
}

/********************************************************************************
 * Copy constructor.                                                            *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(const Matrix3<Real>& mat)
{
    memcpy(m_data, mat.m_data, 9);
}

/********************************************************************************
 * Copy a 2D matrix to this matrix.                                             *
 *******************************************************************************/
template<class Real>
Matrix3<Real>::Matrix3(const Matrix2<Real>& mat)
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
const Real Matrix3<Real>::operator()(const int row, const int col) const
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
    return Vector3<Real>(m_data[3*row], m_data[3*row + 1], m_data[3*row + 2]);
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

/********************************************************************************
 * Matrix assignment.                                                           *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::operator=(const Matrix3<Real>& mat)
{
    memcpy(m_data, mat.m_data, 9);
    return *this;
}

/********************************************************************************
 * Negate the matrix.                                                           *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator-() const
{
    return Matrix3<Real>( -m_data[0], -m_data[1], -m_data[2],
            -m_data[3], -m_data[4], -m_data[5],
            -m_data[6], -m_data[7], -m_data[8] );
}

/********************************************************************************
 * Add two matrices.                                                            *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator+(const Matrix3<Real>& mat) const
{
    return Matrix3<Real>(
            m_data[0] + mat[0], m_data[1] + mat[1], m_data[2] + mat[2],
            m_data[3] + mat[3], m_data[4] + mat[4], m_data[5] + mat[5],
            m_data[6] + mat[6], m_data[7] + mat[7], m_data[8] + mat[8]);
}

/********************************************************************************
 * Subtract two matrices.                                                       *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator-(const Matrix3<Real>& mat) const
{
    return Matrix3<Real>(
            m_data[0] - mat[0], m_data[1] - mat[1], m_data[2] - mat[2],
            m_data[3] - mat[3], m_data[4] - mat[4], m_data[5] - mat[5],
            m_data[6] - mat[6], m_data[7] - mat[7], m_data[8] - mat[8]);
}

/********************************************************************************
 * Multiply two matrix.                                                         *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator*(const Matrix3<Real>& mat) const
{
    return Matrix3<Real>(
            m_data[0]*mat[0] + m_data[1]*mat[3] + m_data[2]*mat[6],
            m_data[0]*mat[1] + m_data[1]*mat[4] + m_data[2]*mat[7],
            m_data[0]*mat[2] + m_data[1]*mat[5] + m_data[2]*mat[8],
            m_data[3]*mat[0] + m_data[4]*mat[3] + m_data[5]*mat[6],
            m_data[3]*mat[1] + m_data[4]*mat[4] + m_data[5]*mat[7],
            m_data[3]*mat[2] + m_data[4]*mat[5] + m_data[5]*mat[8],
            m_data[6]*mat[0] + m_data[7]*mat[3] + m_data[8]*mat[6],
            m_data[6]*mat[1] + m_data[7]*mat[4] + m_data[8]*mat[7],
            m_data[6]*mat[2] + m_data[7]*mat[5] + m_data[8]*mat[8]);
}

/********************************************************************************
 * Multiply a matrix with a vector.                                             *
 *******************************************************************************/
template<class Real>
Vector3<Real> Matrix3<Real>::operator*(const Vector3<Real>& vec) const
{
    return Vector3<Real>(
            m_data[0]*vec[0] + m_data[1]*vec[1] + m_data[2]*vec[2],
            m_data[3]*vec[0] + m_data[4]*vec[1] + m_data[5]*vec[2],
            m_data[6]*vec[0] + m_data[7]*vec[1] + m_data[8]*vec[2]);
}

/********************************************************************************
 * Multiply a matrix with a scalar.                                             *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator*(const Real scalar) const
{
    return Matrix3<Real>(
            m_data[0]*scalar, m_data[1]*scalar, m_data[2]*scalar,
            m_data[3]*scalar, m_data[4]*scalar, m_data[5]*scalar,
            m_data[6]*scalar, m_data[7]*scalar, m_data[8]*scalar);
}

/********************************************************************************
 * Divide a matrix with a scalar.                                               *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::operator/(const Real scalar) const
{
    assert(scalar != (Real)0.0 && "Division by zero error");
    return (*this) * (1.0/scalar);
}

/********************************************************************************
 * Add a matrix to this matrix.                                                 *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::operator+=(const Matrix3<Real>& mat)
{
    (*this) = (*this) + mat;
    return *this;
}

/********************************************************************************
 * Subtract a matrix from this matrix.                                          *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::operator-=(const Matrix3<Real>& mat)
{
    (*this) = (*this) - mat;
    return *this;
}

/********************************************************************************
 * Multiply this matrix with a scalar.                                          *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::operator*=(const Real& scalar)
{
    (*this) = (*this) * scalar;
    return *this;
}

/********************************************************************************
 * Divide this matrix with a scalar.                                            *
 *******************************************************************************/
template<class Real>
Matrix3<Real>& Matrix3<Real>::operator/=(const Real& scalar)
{
    (*this) = (*this) / scalar;
    return *this;
}

/********************************************************************************
 * Get the absolute value of the matrix.                                        *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::abs() const
{
    return Matrix3<Real>(
            Math<Real>::Abs(m_data[0]), Math<Real>::Abs(m_data[1]), Math<Real>::Abs(m_data[2]),
            Math<Real>::Abs(m_data[3]), Math<Real>::Abs(m_data[4]), Math<Real>::Abs(m_data[5]),
            Math<Real>::Abs(m_data[6]), Math<Real>::Abs(m_data[7]), Math<Real>::Abs(m_data[8]));
}

/********************************************************************************
 * Get the determinant of the matrix.                                           *
 *******************************************************************************/
template<class Real>
Real Matrix3<Real>::det() const
{
    return (m_data[0]*(m_data[4]*m_data[8] - m_data[5]*m_data[7]) -
            m_data[1]*(m_data[3]*m_data[8] - m_data[5]*m_data[6]) +
            m_data[2]*(m_data[3]*m_data[7] - m_data[4]*m_data[6]));
}

/********************************************************************************
 * Get the transpose of the matrix.                                             *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::transpose() const
{
    return Matrix3<Real>(m_data[0], m_data[3], m_data[6],
            m_data[1], m_data[4], m_data[7],
            m_data[2], m_data[5], m_data[8]);
}

/********************************************************************************
 * Get the inverse of the matrix.                                               *
 *******************************************************************************/
template<class Real>
Matrix3<Real> Matrix3<Real>::inverse() const
{
    assert( det() != (Real) 0.0 && "Trying to invert a singular matrix.");

    return ( Matrix3<Real>(
                m_data[4]*m_data[8] - m_data[5]*m_data[7],
                m_data[3]*m_data[8] - m_data[5]*m_data[6],
                m_data[3]*m_data[7] - m_data[4]*m_data[6],
                m_data[1]*m_data[8] - m_data[2]*m_data[7],
                m_data[0]*m_data[8] - m_data[2]*m_data[6],
                m_data[0]*m_data[7] - m_data[1]*m_data[6],
                m_data[1]*m_data[5] - m_data[2]*m_data[4],
                m_data[0]*m_data[5] - m_data[2]*m_data[3],
                m_data[0]*m_data[4] - m_data[1]*m_data[3]) / det());
}

/********************************************************************************
 * Check if two matrices are equal.                                             *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator==(const Matrix3<Real>& mat) const
{
    return (m_data[0] == mat[0] && m_data[1] == mat[1] && m_data[2] == mat[2] &&
            m_data[3] == mat[3] && m_data[4] == mat[4] && m_data[5] == mat[5] &&
            m_data[6] == mat[6] && m_data[7] == mat[7] && m_data[8] == mat[8]);
}

/********************************************************************************
 * Check if two matrices are not equal.                                         *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator!=(const Matrix3<Real>& mat) const
{
    return !((*this) == mat);
}

/********************************************************************************
 * Check if this matrix is larger-then-or-equal-to another.                     *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator>=(const Matrix3<Real>& mat) const
{
    return (m_data[0] >= mat[0] && m_data[1] >= mat[1] && m_data[2] >= mat[2] &&
            m_data[3] >= mat[3] && m_data[4] >= mat[4] && m_data[5] >= mat[5] &&
            m_data[6] >= mat[6] && m_data[7] >= mat[7] && m_data[8] >= mat[8]);
}

/********************************************************************************
 * Check if this matrix is larger then another matrix.
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator>(const Matrix3<Real>& mat) const
{
    return (m_data[0] > mat[0] && m_data[1] > mat[1] && m_data[2] > mat[2] &&
            m_data[3] > mat[3] && m_data[4] > mat[4] && m_data[5] > mat[5] &&
            m_data[6] > mat[6] && m_data[7] > mat[7] && m_data[8] > mat[8]);
}

/********************************************************************************
 * Check if this matrix is smaller-then-or-equal-to another matrix.             *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator<=(const Matrix3<Real>& mat) const
{
    return (m_data[0] <= mat[0] && m_data[1] <= mat[1] && m_data[2] <= mat[2] &&
            m_data[3] <= mat[3] && m_data[4] <= mat[4] && m_data[5] <= mat[5] &&
            m_data[6] <= mat[6] && m_data[7] <= mat[7] && m_data[8] <= mat[8]);
}

/********************************************************************************
 * Check if this matrix is smaller then another.                                *
 *******************************************************************************/
template<class Real>
bool Matrix3<Real>::operator<(const Matrix3<Real>& mat) const
{
    return (m_data[0] < mat[0] && m_data[1] < mat[1] && m_data[2] < mat[2] &&
            m_data[3] < mat[3] && m_data[4] < mat[4] && m_data[5] < mat[5] &&
            m_data[6] < mat[6] && m_data[7] < mat[7] && m_data[8] < mat[8]);
}

#ifdef DEBUG
/********************************************************************************
 * Print out the matrix.                                                        *
 *******************************************************************************/
template<class Real>
void Matrix3<Real>::print() const
{
    printf("\n|%g %g %g|\n|%g %g %g|\n|%g %g %g|\n", 
            m_data[0], m_data[1], m_data[2],
            m_data[3], m_data[4], m_data[5],
            m_data[6], m_data[7], m_data[8]);
}
#endif

/********************************************************************************
 * Makes it possible to write scalar*matrix.                                    *
 *******************************************************************************/
template<class Real>
Matrix3<Real> operator*(const Real scalar, const Matrix3<Real>& mat)
{
    return mat*scalar;
}
