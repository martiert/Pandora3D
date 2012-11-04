#include "vector3.h"

template<>
const Math::Vector3<float> Math::Vector3<float>::ZERO(0, 0, 0);
template<>
const Math::Vector3<float> Math::Vector3<float>::E1(1, 0, 0);
template<>
const Math::Vector3<float> Math::Vector3<float>::E2(0, 1, 0);
template<>
const Math::Vector3<float> Math::Vector3<float>::E3(0, 0, 1);

template<>
const Math::Vector3<double> Math::Vector3<double>::ZERO(0, 0, 0);
template<>
const Math::Vector3<double> Math::Vector3<double>::E1(1, 0, 0);
template<>
const Math::Vector3<double> Math::Vector3<double>::E2(0, 1, 0);
template<>
const Math::Vector3<double> Math::Vector3<double>::E3(0, 0, 1);

template<>
const Math::Vector3<int> Math::Vector3<int>::ZERO(0, 0, 0);
template<>
const Math::Vector3<int> Math::Vector3<int>::E1(1, 0, 0);
template<>
const Math::Vector3<int> Math::Vector3<int>::E2(0, 1, 0);
template<>
const Math::Vector3<int> Math::Vector3<int>::E3(0, 0, 1);

template<>
const Math::Vector3<uint> Math::Vector3<uint>::ZERO(0, 0, 0);
template<>
const Math::Vector3<uint> Math::Vector3<uint>::E1(1, 0, 0);
template<>
const Math::Vector3<uint> Math::Vector3<uint>::E2(0, 1, 0);
template<>
const Math::Vector3<uint> Math::Vector3<uint>::E3(0, 0, 1);
