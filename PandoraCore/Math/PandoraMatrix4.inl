/*
-------------------------------------------------------------------------------
File Name : PandoraMatrix4.inl

Purpose : Implementation of the Matrix4 class for Pandora.

Creation Date : 2010-05-03

Last Modified : lø. 26. juni 2010 kl. 18.17 +0200

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

/********************************************************************************
 * Default constructor.                                                         *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(){}

/********************************************************************************
 * Make rotation matrix.                                                        *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(const Real& rad, const Vector4& r)
{
    r.normalize();
    Real t_cos = Math::Cos(rad);
    Real t_sin = Math::Sin(rad);

    m_data[0] = t_cos + (1 - t_cos)*r.x*r.x;
    m_data[1] = (1 - t_cos)*r.x*r.y - r.z*t_sin;
    m_data[2] = (1 - t_cos)*r.x*r.z + r.y*t_sin;

    m_data[4] = (1 - t_cos)*r.x*r.y + r.z*t_sin;
    m_data[5] = t_cos + (1 - t_cos)*r.y*r.y;
    m_data[6] = (1 - t_cos)*r.y*r.z - r.x*t_sin;

    m_data[8] = (1 - t_cos)*r.x*r.z - r.y*t_sin;
    m_data[9] = (1 - t_cos)*r.y*r.z + r.x*t_sin;
    m_data[10] = t_cos + (1 - t_cos)*r.z*r.z;

    m_data[3] = 0;
    m_data[7] = 0;
    m_data[11] = 0;
    m_data[12] = 0;
    m_data[13] = 0;
    m_data[14] = 0;
    m_data[15] = 1;
}

/********************************************************************************
 * Make a scaling or a rotation matrix.                                         *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(const Vector3& vec, const bool scale)
{
    *this = IDENTITY;
    if(scale) {
        m_data[0] = vec[0];
        m_data[5] = vec[1];
        m_data[10] = vec[2];
        return;
    }

    m_data[3] = vec[0];
    m_data[7] = vec[1];
    m_data[11] = vec[2];
}

/********************************************************************************
 * Construct a matrix from an array.                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(const Real array[16])
{
    memcpy(m_data, array, 16);
}

/********************************************************************************
 * Copy a 4D matrix.                                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(const Matrix4<Real>& mat)
{
    memcpy(m_data, mat.m_data, 16);
}

/********************************************************************************
 * Copy a 3D matrix.                                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::Matrix4(const Matrix3<Real>& mat)
{
    *this = IDENTITY;
    m_data[0] = mat[0]; m_data[1] = mat[1]; m_data[2] = mat[2];
    m_data[4] = mat[3]; m_data[5] = mat[4]; m_data[6] = mat[5];
    m_data[8] = mat[6]; m_data[9] = mat[7]; m_data[10] = mat[8];
}

/********************************************************************************
 * Destructor.                                                                  *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::~Matrix4() {}

/********************************************************************************
 * Conversion operator.                                                         *
 *******************************************************************************/
template<class Real>
Matrix4<Real>::operator Real *()
{
    return &(m_data[0]);
}

/********************************************************************************
 * Constant conversion operator.                                                *
 *******************************************************************************/
template<class Real>
const Matrix4<Real>::operator Real *() const
{
    return &(m_data[0]);
}

/********************************************************************************
 * Access operator.                                                             *
 *******************************************************************************/
template<class Real>
Real& Matrix4<Real>::operator[](const ptrdiff_t i)
{
    assert(i < 16 && "Index out of bounds");

    return m_data[i];
}

/********************************************************************************
 * Constant access operator.                                                    *
 *******************************************************************************/
template<class Real>
const Real Matrix4<Real>::operator[](const ptrdiff_t i) const
{
    assert(i < 16 && "Index out of bounds");

    return m_data[i];
}

/********************************************************************************
 * Get reference to element (row,col).                                          *
 *******************************************************************************/
template<class Real>
Real& Matrix4<Real>::operator()(const int row, const int col)
{
    assert(row < 4 && col < 4 && "Index out of bounds");

    return m_data[col + row*4];
}

/********************************************************************************
 * Get constant copy of element (row,col).                                      *
 *******************************************************************************/
template<class Real>
const Real Matrix4<Real>::operator()(const int row, const int col) const
{
    assert(row < 4 && col < 4 && "Index out of bounds");

    return m_data[col + row*4];
}

/********************************************************************************
 * Get row number row.                                                          *
 *******************************************************************************/
template<class Real>
Vector4<Real> Matrix4<Real>::getRow(const int row) const
{
    assert(row < 4 && "Index out of bounds");

    return Vector4<Real>(m_data[4*row], m_data[4*row + 1], m_data[4*row + 2],
            m_data[4*row + 3]);
}

/********************************************************************************
 * Set row number row to the given vector.                                      *
 *******************************************************************************/
template<class Real>
void Matrix4<Real>::setRow(const int row, const Vector4<Real>& vec)
{
    assert(row < 4 && "Index out of bounds");

    m_data[4*row]       = vec[0];
    m_data[4*row + 1]   = vec[1];
    m_data[4*row + 2]   = vec[2];
    m_data[4*row + 3]   = vec[3];
}

/********************************************************************************
 * Get column numbet col as a vector.                                           *
 *******************************************************************************/
template<class Real>
Vector4<Real> Matrix4<Real>::getColumn(const int col) const
{
    assert(col < 4 && "Index out of bounds");

    return Vector4<real>(m_data[col], m_data[col + 4], m_data[col + 8], 
            m_data[col + 12]);
}

/********************************************************************************
 * Set column number col to the given vector.                                   *
 *******************************************************************************/
template<class Real>
void Matrix4<Real>::setColumn(const int col, const Vector4<Real>& vec)
{
    assert(col < 4 && "Index out of bounds");

    m_data[col]      = vec[0];
    m_data[col + 4]  = vec[1];
    m_data[col + 8]  = vec[2];
    m_data[col + 12] = vec[3];
}

/********************************************************************************
 * Copy a matrix to this matrix.                                                *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator=(const Matrix4<Real>& mat)
{
    memcpy(m_data, mat.m_data, 16);
    return *this;
}

/********************************************************************************
 * Negate this matrix.                                                          *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator-() const
{
    return ((*this) * ((Real) -1.0));
}

/********************************************************************************
 * Add two matrices.                                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator+(const Matrix4<Real>& mat) const
{
    Matrix4<Real> tmp((*this));

    for(int i = 0; i < 16; i++)
        tmp[i] += mat[i];

    return tmp;
}

/********************************************************************************
 * Subtract two matrices.                                                       *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator-(const Matrix4<Real>& mat) const
{
    Matrix4<Real> tmp((*this));

    for(int i = 0; i < 16; i++)
        tmp[i] -= mat[i];
    
    return tmp;
}

/********************************************************************************
 * Multiply two matrices.                                                       *
 * TODO: Check for speedups.                                                    *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator*(const Matrix4<Real>& mat) const
{
    Matrix4<Real> tmp = Matrix4<Real>::ZERO;

    /*
    for(int row = 0; row < 4; row++) {
        for(int col = 0; col < 4; col++) {
            for(int k = 0; k < 4; k++) {
                tmp[row*4 + col] += m_data[row*4 + k] * mat[k*4 + col];
            }
        }
    }
    */

    //Row 1
    tmp[0] = m_data[0]*mat[0] + m_data[1]*mat[4] + m_data[2]*mat[8] + 
        m_data[3]*mat[12];
    tmp[1] = m_data[0]*mat[1] + m_data[1]*mat[5] + m_data[2]*mat[9] +
        m_data[3]*mat[13];
    tmp[2] = m_data[0]*mat[2] + m_data[1]*mat[6] + m_data[2]*mat[10] +
        m_data[3]*mat[14];
    tmp[3] = m_data[0]*mat[3] + m_data[1]*mat[7] + m_data[2]*mat[11] +
        m_data[3]*mat[15];

    //Row 2
    tmp[4] = m_data[4]*mat[0] + m_data[5]*mat[4] + m_data[6]*mat[8] +
        m_data[7]*mat[12];
    tmp[5] = m_data[4]*mat[1] + m_data[5]*mat[5] + m_data[6]*mat[9] +
        m_data[7]*mat[13];
    tmp[6] = m_data[4]*mat[2] + m_data[5]*mat[6] + m_data[6]*mat[10] +
        m_data[7]*mat[14];
    tmp[7] = m_data[4]*mat[3] + m_data[5]*mat[7] + m_data[6]*mat[11] +
        m_data[7]*mat[15];

    //Row 3
    tmp[8] = m_data[8]*mat[0] + m_data[9]*mat[4] + m_data[10]*mat[8] +
        m_data[11]*mat[12];
    tmp[9] = m_data[8]*mat[1] + m_data[9]*mat[5] + m_data[10]*mat[9] +
        'm_data[11]*mat[13];
    tmp[10] = m_data[8]*mat[2] + m_data[9]*mat[6] + m_data[10]*mat[10] +
        m_data[11]*mat[14];
    tmp[11] = m_data[8]*mat[3] + m_data[9]*mat[7] + m_data[10]*mat[11] +
        m_data[11]*mat[15];

    //Row 4
    tmp[12] = m_data[12]*mat[0] + m_data[13]*mat[4] + m_data[14]*mat[8] +
        m_data[15]*mat[12];
    tmp[13] = m_data[12]*mat[1] + m_data[13]*mat[5] + m_data[14]*mat[9] +
        m_data[15]*mat[13];
    tmp[14] = m_data[12]*mat[2] + m_data[13]*mat[6] + m_data[14]*mat[10] +
        m_data[15]*mat[14];
    tmp[15] = m_data[12]*mat[3] + m_data[13]*mat[7] + m_data[14]*mat[11] +
        m_data[15]*mat[15];

    return tmp;
}

/********************************************************************************
 * Multiply a matrix with a vector.                                             *
 *******************************************************************************/
template<class Real>
Vector4<Real> Matrix4<Real>::operator*(const Vector4<Real>& vec) const
{
    return Vector4<Real>(
            vec[0]*mat[0] + vec[1]*mat[1] + vec[2]*mat[2] + vec[3]*mat[3],
            vec[0]*mat[4] + vec[1]*mat[5] + vec[2]*mat[6] + vec[3]*mat[7],
            vec[0]*mat[8] + vec[1]*mat[9] + vec[2]*mat[10] + vec[3]*mat[11],
            vec[0]*mat[12] + vec[1]*mat[13] + vec[2]*mat[14] + vec[3]*mat[15]);
}

/********************************************************************************
 * Multiply a matrix with a scalar.                                             *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator*(const Real& scalar) const
{
    Matrix4<Real> mat((*this));

    for(int i = 0; i < 16; i++)
        mat *= scalar;
    return mat;
}

/********************************************************************************
 * Divide a matrix with a scalar.                                               *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator/(const Real& scalar) const
{
    assert(scalar != 0 && "Division by zero");

    return ((*this) * (1.0/scalar));
}

/********************************************************************************
 * Add a matrix to this matrix.                                                 *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator+=(const Matrix4<Real>& mat)
{
    for(int i = 0; i < 16; i++)
        m_data[i] += mat[i];
    return *this;
}

/********************************************************************************
 * Subtract a matrix from this matrix.                                          *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator-=(const Matrix4<Real>& mat)
{
    for(int i = 0; i < 16; i++)
        m_data[i] -= mat[i];
    return *this;
}

/********************************************************************************
 * Multiply this matrix with a scalar.                                          *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator*=(const Real& scalar)
{
    for(int i = 0; i < 16; i++)
        m_data[i] *= scalar;
    return *this;
}

/********************************************************************************
 * Divide this matrix with a scalar.                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::operator/=(const Real& scalar)
{
    assert(scalar != 0.0 && "Division by zero");

    Real tmp = 1.0/scalar;

    for(int i = 0; i < 16; i++)
        m_data[i] *= tmp;
    return *this;
}

/********************************************************************************
 * Dot multiply two matrices.                                                   *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::dotprod(const Matrix4<Real>& mat) const
{
    Matrix4<Real> tmp((*this));

    for(int i = 0; i < 16; i++)
        tmp[i] *= mat[i];

    return tmp;
}

/********************************************************************************
 * Dot multiply a matrix to this matrix.                                        *
 *******************************************************************************/
template<class Real>
void Matrix4<Real>::operator*=(const Matrix4<Real>& mat)
{
    for(int i = 0; i < 16; i++)
        m_data[i] *= mat[i];
}

/********************************************************************************
 * Get the absolute value of all the elements in the matrix.                    *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::abs() const
{
    Matrix4<Real> tmp;

    for(int i = 0; i < 16; i++)
        tmp[i] = Math::Abs(m_data[i]);

    return tmp;
}

/********************************************************************************
 * Get the determinant of the matrix.                                           *
 *******************************************************************************/
template<class Real>
Real Matrix4<Real>::det() const
{
    return m_data[0]*(m_data[5] * (m_data[10]*m_data[15] - m_data[11]*m_data[14])
                - m_data[6] * (m_data[9]*m_data[15] - m_data[11]*m_data[13])
                + m_data[7] * (m_data[9]*m_data[14] - m_data[10]*m_data[13]))
        - m_data[1]*(m_data[4] * (m_data[10]*m_data[15] - m_data[11]*m_data[14])
                - m_data[6] * (m_data[8]*m_data[15] - m_data[11]*m_data[12])
                + m_data[7] * (m_data[8]*m_data[14] - m_data[10]*m_data[12]))
        + m_data[2]*(m_data[4] * (m_data[9]*m_data[15] - m_data[11]*m_data[13])
                - m_data[5] * (m_data[8]*m_data[15] - m_data[11]*m_data[12])
                + m_data[7] * (m_data[8]*m_data[13] - m_data[9]*m_data[12]))
        - m_data[3]*(m_data[4] * (m_data[9]*m_data[14] - m_data[10]*m_data[13])
                - m_data[5] * (m_data[8]*m_data[14] - m_data[10]*m_data[12])
                + m_data[6] * (m_data[8]*m_data[13] - m_data[9]*m_data[12]));
}

/********************************************************************************
 * Find the transpose of the matrix.                                            *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::transpose() const
{
    Matrix4<Real> tmp;

    for(int row = 0; row < 4; row++) {
        for(int col = 0; col < 4; col++) {
            tmp[row*4 + col] = m_data[col*4 + row];
        }
    }
    
    return tmp;
}

/********************************************************************************
 * Find the cofactor matrix of this matrix.                                     *
 * TODO: Simplify this implementation.
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::cofactor() const
{
    Matrix4<Real> cofact;
    Matrix3<Real> determ[16];

    determ[0] = Matrix3<Real>(m_data[5], m_data[6], m_data[7],
            m_data[9], m_data[10], m_data[11],
            m_data[13], m_data[14], m_data[15]);
    determ[1] = Matrix3<Real>(m_data[4], m_data[6], m_data[7],
            m_data[8], m_data[10], m_data[11],
            m_data[12], m_data[14], m_data[15]);
    determ[2] = Matrix3<Real>(m_data[4], m_data[5], m_data[7],
            m_data[8], m_data[9], m_data[11],
            m_data[12], m_data[13], m_data[15]);
    determ[3] = Matrix3<Real>(m_data[4], m_data[5], m_data[6],
            m_data[8], m_data[9], m_data[10],
            m_data[12], m_data[13], m_data[14]);

    determ[4] = Matrix3<Real>(m_data[1], m_data[2], m_data[3],
            m_data[9], m_data[10], m_data[11],
            m_data[13], m_data[14], m_data[15]);
    determ[5] = Matrix3<Real>(m_data[0], m_data[2], m_data[3],
            m_data[8], m_data[10], m_data[11],
            m_data[12], m_data[14], m_data[15]);
    determ[6] = Matrix3<Real>(m_data[0], m_data[1], m_data[3],
            m_data[8], m_data[9], m_data[11],
            m_data[12], m_data[13], m_data[15]);
    determ[7] = Matrix3<real>(m_data[0], m_data[1], m_data[2],
            m_data[8], m_data[9], m_data[10],
            m_data[12], m_data[13], m_data[14]);

    determ[8] = Matrix3<Real>(m_data[1], m_data[2], m_data[3],
            m_data[5], m_data[6], m_data[7],
            m_data[13], m_data[14], m_data[15]);
    determ[9] = Matrix3<Real>(m_data[0], m_data[2], m_data[3],
            m_data[4], m_data[6], m_data[7],
            m_data[12], m_data[14], m_data[15]);
    determ[10] = Matrix3<Real>(m_data[0], m_data[1], m_data[3],
            m_data[4], m_data[5], m_data[7],
            m_data[12], m_data[13], m_data[15]);
    determ[11] = Matrix3<Real>(m_data[0], m_data[1], m_data[2],
            m_data[4], m_data[5], m_data[6],
            m_data[12], m_data[13], m_data[14]);

    determ[12] = Matrix3<Real>(m_data[1], m_data[2], m_data[3],
            m_data[5], m_data[6], m_data[7],
            m_data[9], m_data[10], m_data[11]);
    determ[13] = Matrix3<Real>(m_data[0], m_data[2], m_data[3],
            m_data[4], m_data[6], m_data[7],
            m_data[8], m_data[10], m_data[11]);
    determ[14] = Matrix3<Real>(m_data[0], m_data[1], m_data[3],
            m_data[4], m_data[5], m_data[7],
            m_data[8], m_data[9], m_data[11]);
    determ[15] = Matrix3<Real>(m_data[0], m_data[1], m_data[2],
            m_data[4], m_data[5], m_data[6],
            m_data[8], m_data[9], m_data[10]);

    for(int i = 0; i < 16; i++)
        cofact[i] = determ[i].det();

    Matrix4<Real> tmp = ONES;
    tmp[1] = -1;
    tmp[3] = -1;
    tmp[4] = -1;
    tmp[6] = -1;
    tmp[9] = -1;
    tmp[11] = -1;
    tmp[12] = -1;
    tmp[14] = -1;

    return (cofact.dot(tmp));
}


/********************************************************************************
 * Find the inverse of the matrix.                                              *
 *******************************************************************************/
template<class Real>
Matrix4<Real> Matrix4<Real>::inverse() const
{
    assert(this->det() != 0 && "Singular matrix");

    Matrix4<Real> adjoint = (this->cofactor()).transpose();

    return adjoint / (this->det());
}

/********************************************************************************
 * Check for equality.                                                          *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator==(const Matrix4<Real>& mat) const
{
    for(int i = 0; i < 16; i++) {
        if(mat[i] != m_data[i]) {
            return false;
        }
    }
    return true;
}

/********************************************************************************
 * Check for inequality.                                                        *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator!=(const Matrix4<Real>& mat) const
{
    return !((*this) == mat);
}

/********************************************************************************
 * Check if this matrix is larger-then-or-equal-to another matrix.              *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator>=(const Matrix4<Real>& mat) const
{
    for(int i = 0; i < 16; i++) {
        if(mat[i] > m_data[i]) {
            return false;
        }
    }
    return true;
}

/********************************************************************************
 * Check if this matrix is larger then another matrix.                          *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator>(const Matrix4<Real>& mat) const
{
    for(int i = 0; i < 16; i++) {
        if(mat[i] >= m_data[i]) {
            return false;
        }
    }

    return true;
}

/********************************************************************************
 * Check if this matrix is less-then-or-equal-to another matrix.                *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator<=(const Matrix4<Real>& mat) const
{
    for(int i = 0; i < 16; i++) {
        if(mat[i] < m_data[i]) {
            return false;
        }
    }
    return true;
}

/********************************************************************************
 * Check if this matrix is less then another matrix.                            *
 *******************************************************************************/
template<class Real>
bool Matrix4<Real>::operator<(const Matrix4<Real>& mat) const
{
    for(int i = 0; i < 16; i++) {
        if(mat[i] <= m_data[i]) {
            return false;
        }
    }
    return true;
}

#ifdef DEBUG
/********************************************************************************
 * Print the matrix.                                                            *
 *******************************************************************************/
template<class Real>
void Matrix4<Real>::print() const
{
    printf("\n");
    for(int row = 0; row < 4; row++) {
        printf("|");
        for(int col = 0; col < 3; col++) {
            printf("%g ", m_data[row*4 + col]);
        }
        printf("%g|\n", m_data[row*4 + 4]);
    }
}
#endif

/********************************************************************************
 * Makes it possible to write scalar*matrix.                                    *
 *******************************************************************************/
template<class Real>
Matrix4<Real> operator*(const Real scalar, const Matrix4<Real>& mat)
{
    return mat * scalar;
}
