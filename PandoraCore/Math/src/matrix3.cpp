#include "matrix3.h"

using Math::Matrix3;

typedef unsigned int uint;

template<>
const Matrix3<double> Matrix3<double>::IDENTITY (1, 0, 0,
                                                 0, 1, 0,
                                                 0, 0, 1);

template<>
const Matrix3<float> Matrix3<float>::IDENTITY (1, 0, 0,
                                               0, 1, 0,
                                               0, 0, 1);

template<>
const Matrix3<int> Matrix3<int>::IDENTITY (1, 0, 0,
                                           0, 1, 0,
                                           0, 0, 1);

template<>
const Matrix3<uint> Matrix3<uint>::IDENTITY (1, 0, 0,
                                             0, 1, 0,
                                             0, 0, 1);

template<>
const Matrix3<double> Matrix3<double>::ZERO (0, 0, 0,
                                             0, 0, 0,
                                             0, 0, 0);

template<>
const Matrix3<float> Matrix3<float>::ZERO (0, 0, 0,
                                           0, 0, 0,
                                           0, 0, 0);

template<>
const Matrix3<int> Matrix3<int>::ZERO (0, 0, 0,
                                       0, 0, 0,
                                       0, 0, 0);

template<>
const Matrix3<uint> Matrix3<uint>::ZERO (0, 0, 0,
                                         0, 0, 0,
                                         0, 0, 0);
