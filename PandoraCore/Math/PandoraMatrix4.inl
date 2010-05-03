/*
-------------------------------------------------------------------------------
File Name : PandoraMatrix4.inl

Purpose :

Creation Date : 2010-05-03

Last Modified : ma. 03. mai 2010 kl. 16.22 +0200

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
