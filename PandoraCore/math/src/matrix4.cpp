#include "matrix4.h"

template<>
const Math::Matrix4<float> Math::Matrix4<float>::IDENTITY (1, 0, 0, 0,
                                                           0, 1, 0, 0,
                                                           0, 0, 1, 0,
                                                           0, 0, 0, 1);
template<>
const Math::Matrix4<float> Math::Matrix4<float>::ZERO (0, 0, 0, 0,
                                                       0, 0, 0, 0,
                                                       0, 0, 0, 0,
                                                       0, 0, 0, 0);

template<>
const Math::Matrix4<double> Math::Matrix4<double>::IDENTITY (1, 0, 0, 0,
                                                             0, 1, 0, 0,
                                                             0, 0, 1, 0,
                                                             0, 0, 0, 1);
template<>
const Math::Matrix4<double> Math::Matrix4<double>::ZERO (0, 0, 0, 0,
                                                         0, 0, 0, 0,
                                                         0, 0, 0, 0,
                                                         0, 0, 0, 0);

template<>
const Math::Matrix4<int> Math::Matrix4<int>::IDENTITY (1, 0, 0, 0,
                                                       0, 1, 0, 0,
                                                       0, 0, 1, 0,
                                                       0, 0, 0, 1);
template<>
const Math::Matrix4<int> Math::Matrix4<int>::ZERO (0, 0, 0, 0,
                                                   0, 0, 0, 0,
                                                   0, 0, 0, 0,
                                                   0, 0, 0, 0);

template<>
const Math::Matrix4<uint> Math::Matrix4<uint>::IDENTITY (1, 0, 0, 0,
                                                         0, 1, 0, 0,
                                                         0, 0, 1, 0,
                                                         0, 0, 0, 1);
template<>
const Math::Matrix4<uint> Math::Matrix4<uint>::ZERO (0, 0, 0, 0,
                                                     0, 0, 0, 0,
                                                     0, 0, 0, 0,
                                                     0, 0, 0, 0);

