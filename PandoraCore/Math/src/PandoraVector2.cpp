/*
--------------------------------------------------------------------------------
File Name : PandoraVector2.cpp

Purpose : Implementation of the Vector2 class used in Pandora3D

Creation Date : 2010-01-26

Last Modified : ma. 18. okt. 2010 kl. 20.50 +0200

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
--------------------------------------------------------------------------------
*/

#include "PandoraVector2.h"

namespace Pandora
{
    namespace Math
    {

template<> const Vector2<float> Vector2<float>::e1(1.0f, 0.0f);
template<> const Vector2<float> Vector2<float>::e2(0.0f, 1.0f);
template<> const Vector2<float> Vector2<float>::ZERO(0.0f, 0.0f);
template<> const Vector2<float> Vector2<float>::ONES(1.0f, 1.0f);

template<> const Vector2<double> Vector2<double>::e1(1.0, 0.0);
template<> const Vector2<double> Vector2<double>::e2(0.0, 1.0);
template<> const Vector2<double> Vector2<double>::ZERO(0.0, 0.0);
template<> const Vector2<double> Vector2<double>::ONES(1.0, 1.0);

    } // namespace Math
} // namespace Pandora
