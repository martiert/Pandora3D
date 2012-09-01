#include "matrix2.h"

template<>
const Math::Matrix2<float> Math::Matrix2<float>::IDENTITY (1, 0, 0, 1);
template<>
const Math::Matrix2<float> Math::Matrix2<float>::ZERO (0, 0, 0, 0);

template<>
const Math::Matrix2<double> Math::Matrix2<double>::IDENTITY (1, 0, 0, 1);
template<>
const Math::Matrix2<double> Math::Matrix2<double>::ZERO (0, 0, 0, 0);

template<>
const Math::Matrix2<int> Math::Matrix2<int>::IDENTITY (1, 0, 0, 1);
template<>
const Math::Matrix2<int> Math::Matrix2<int>::ZERO (0, 0, 0, 0);

template<>
const Math::Matrix2<uint> Math::Matrix2<uint>::IDENTITY (1, 0, 0, 1);
template<>
const Math::Matrix2<uint> Math::Matrix2<uint>::ZERO (0, 0, 0, 0);
