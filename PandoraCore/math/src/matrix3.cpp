#include "matrix3.h"

template<>
const Math::Matrix3<float> Math::Matrix3<float>::IDENTITY (1, 0, 0,
                                                           0, 1, 0,
                                                           0, 0, 1);
template<>
const Math::Matrix3<float> Math::Matrix3<float>::ZERO (0, 0, 0,
                                                       0, 0, 0,
                                                       0, 0, 0);
template<>
const Math::Matrix3<double> Math::Matrix3<double>::IDENTITY (1, 0, 0,
                                                           0, 1, 0,
                                                           0, 0, 1);
template<>
const Math::Matrix3<double> Math::Matrix3<double>::ZERO (0, 0, 0,
                                                       0, 0, 0,
                                                       0, 0, 0);

template<>
const Math::Matrix3<int> Math::Matrix3<int>::IDENTITY (1, 0, 0,
                                                           0, 1, 0,
                                                           0, 0, 1);
template<>
const Math::Matrix3<int> Math::Matrix3<int>::ZERO (0, 0, 0,
                                                       0, 0, 0,
                                                       0, 0, 0);

template<>
const Math::Matrix3<uint> Math::Matrix3<uint>::IDENTITY (1, 0, 0,
                                                           0, 1, 0,
                                                           0, 0, 1);
template<>
const Math::Matrix3<uint> Math::Matrix3<uint>::ZERO (0, 0, 0,
                                                       0, 0, 0,
                                                       0, 0, 0);
