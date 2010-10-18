/*
--------------------------------------------------------------------------------
File Name : PandoraQuat.cpp

Purpose : Implementation of the quaternion class in Pandora 3D.

Creation Date : 2010-08-09

Last Modified : ma. 18. okt. 2010 kl. 20.50 +0200

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
--------------------------------------------------------------------------------
*/

#include "PandoraQuat.h"

namespace Pandora
{
    namespace Math
    {

template<> const Quat<float> Quat<float>::IDENTITY(1.0f, 0.0f, 0.0f, 0.0f);
template<> const Quat<float> Quat<float>::ONES(1.0f, 1.0f, 1.0f, 1.0f);
template<> const Quat<float> Quat<float>::ZERO(0.0f, 0.0f, 0.0f, 0.0f);

template<> const Quat<double> Quat<double>::IDENTITY(1.0, 0.0, 0.0, 0.0);
template<> const Quat<double> Quat<double>::ONES(1.0, 1.0, 1.0, 1.0);
template<> const Quat<double> Quat<double>::ZERO(0.0, 0.0, 0.0, 0.0);

    } // namespace Math
} // namespace Pandora
