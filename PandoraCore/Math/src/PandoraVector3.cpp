/*
--------------------------------------------------------------------------------
File Name : PandoraVector3.cpp

Purpose : Implementation of the 3D vector class.

Creation Date : 2010-01-28

Last Modified : ma. 18. okt. 2010 kl. 20.50 +0200

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
--------------------------------------------------------------------------------
*/

#include "PandoraVector3.h"

namespace Pandora
{
    namespace Math
    {

template<> const Vector3<float> Vector3<float>::e1(1.0f, 0.0f, 0.0f);
template<> const Vector3<float> Vector3<float>::e2(0.0f, 1.0f, 0.0f);
template<> const Vector3<float> Vector3<float>::e3(0.0f, 0.0f, 1.0f);
template<> const Vector3<float> Vector3<float>::ZERO(0.0f, 0.0f, 0.0f);
template<> const Vector3<float> Vector3<float>::ONES(1.0f, 1.0f,1.0f);

template<> const Vector3<double> Vector3<double>::e1(1.0, 0.0, 0.0);
template<> const Vector3<double> Vector3<double>::e2(0.0, 1.0, 0.0);
template<> const Vector3<double> Vector3<double>::e3(0.0, 0.0, 1.0);
template<> const Vector3<double> Vector3<double>::ZERO(0.0, 0.0, 0.0);
template<> const Vector3<double> Vector3<double>::ONES(1.0, 1.0,1.0);

    } // namespace Math
} // namespace Pandora
