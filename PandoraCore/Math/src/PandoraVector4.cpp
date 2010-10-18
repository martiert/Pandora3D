/*
--------------------------------------------------------------------------------
File Name : PandoraVector4.cpp

Purpose : Implementation of the Vector4 class.

Creation Date : 2010-01-31

Last Modified : ma. 18. okt. 2010 kl. 20.51 +0200

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
--------------------------------------------------------------------------------
*/

#include "PandoraVector4.h"

namespace Pandora
{
    namespace Math
    {

template<> const Vector4<float> Vector4<float>::e1(1.0f, 0.0f, 0.0f, 0.0f);
template<> const Vector4<float> Vector4<float>::e2(0.0f, 1.0f, 0.0f, 0.0f);
template<> const Vector4<float> Vector4<float>::e3(0.0f, 0.0f, 1.0f, 0.0f);
template<> const Vector4<float> Vector4<float>::e4(0.0f, 0.0f, 0.0f, 1.0f);
template<> const Vector4<float> Vector4<float>::ZERO(0.0f, 0.0f, 0.0f, 0.0f);
template<> const Vector4<float> Vector4<float>::ONES(1.0f, 1.0f,1.0f, 1.0f);

template<> const Vector4<double> Vector4<double>::e1(1.0, 0.0, 0.0, 0.0);
template<> const Vector4<double> Vector4<double>::e2(0.0, 1.0, 0.0, 0.0);
template<> const Vector4<double> Vector4<double>::e3(0.0, 0.0, 1.0, 0.0);
template<> const Vector4<double> Vector4<double>::e4(0.0, 0.0, 0.0, 1.0);
template<> const Vector4<double> Vector4<double>::ZERO(0.0, 0.0, 0.0, 0.0);
template<> const Vector4<double> Vector4<double>::ONES(1.0, 1.0,1.0, 1.0);

    } // namespace Math
} // namespace Pandora
