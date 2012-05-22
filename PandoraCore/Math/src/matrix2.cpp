#include "matrix2.h"

using Math::Matrix2;

typedef unsigned int uint;

template<>
const Matrix2<double> Matrix2<double>::IDENTITY (1, 0, 0, 1);

template<>
const Matrix2<float> Matrix2<float>::IDENTITY (1, 0, 0, 1);

template<>
const Matrix2<int> Matrix2<int>::IDENTITY (1, 0, 0, 1);

template<>
const Matrix2<uint> Matrix2<uint>::IDENTITY (1, 0, 0, 1);

template<>
const Matrix2<double> Matrix2<double>::ZERO (0, 0, 0, 0);

template<>
const Matrix2<float> Matrix2<float>::ZERO (0, 0, 0, 0);

template<>
const Matrix2<int> Matrix2<int>::ZERO (0, 0, 0, 0);

template<>
const Matrix2<uint> Matrix2<uint>::ZERO (0, 0, 0, 0);
