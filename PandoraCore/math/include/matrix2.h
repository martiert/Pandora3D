#ifndef MATH_MATRIX2_H_INCLUDED
#define MATH_MATRIX2_H_INCLUDED

#include "matrix.h"

namespace Math
{

typedef Matrix<float,     2> Matrix2f;
typedef Matrix<double,    2> Matrix2d;
typedef Matrix<int,       2> Matrix2i;
typedef Matrix<uint32_t,  2> Matrix2u;

#define INCLUDED_FROM_MATRIX2_H
#include "matrix2_tmpl.h"
#undef INCLUDED_FROM_MATRIX2_H

}

#endif
