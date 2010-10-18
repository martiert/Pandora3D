/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix2.cpp

Purpose : Implementation of the Matrix2 class in Pandora 3D.

Creation Date : 2010-05-05

Last Modified : ma. 18. okt. 2010 kl. 20.49 +0200

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
--------------------------------------------------------------------------------
*/

#include "PandoraMatrix2.h"

namespace Pandora
{
    namespace Math
    {

template<> const Matrix2<float> Matrix2<float>::ZERO(0.0f, 0.0f, 0.0f, 0.0f);
template<> const Matrix2<float> Matrix2<float>::IDENTITY(1.0f, 0.0f, 0.0f, 1.0f);
template<> const Matrix2<float> Matrix2<float>::ONES(1.0f, 1.0f, 1.0f, 1.0f);

template<> const Matrix2<double> Matrix2<double>::ZERO(0.0, 0.0, 0.0, 0.0);
template<> const Matrix2<double> Matrix2<double>::IDENTITY(1.0, 0.0, 0.0, 1.0);
template<> const Matrix2<double> Matrix2<double>::ONES(1.0, 1.0, 1.0, 1.0);

    } // namespace Math
} //namespace Pandora
