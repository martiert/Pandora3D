#ifndef INCLUDED_FROM_MATRIX2_H
#error "matrix2_tmpl.h can only be included from matrix2.h"
#else

template<typename Real>
Matrix<Real, 2> matrix_adjugate(const Matrix<Real, 2> & matrix)
{
    return Matrix<Real, 2>({matrix[3], -matrix[1],
                            -matrix[2], matrix[0]});
}

#endif
