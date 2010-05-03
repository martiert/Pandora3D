/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix2.cpp

Purpose : Templates for the Pandora 2D Matrix.

Creation Date : 2010-04-19

Last Modified : ma. 03. mai 2010 kl. 21.40 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "PandoraMatrix2.h"

using namespace Pandora

/********************************************************************************
 * A few special matrices.                                                      *
 *******************************************************************************/
template<>
const Math::Matrix2<float> Math::Matrix2<float>::ZERO(0.0f, 0.0f, 
        0.0f, 0.0f);
template<>
const Math::Matrix2<double> Math::Matrix2<double>::ZERO(0.0, 0.0, 
        0.0, 0.0);

template<>
const Math::Matrix2<float> Math::Matrix2<float>::IDENTITY(1.0f, 0.0f,
        0.0f, 1.0f);
template<>
const Math::Matrix2<double> Math::Matrix2<double>::IDENTITY(1.0, 0.0, 
        0.0, 1.0);

template<>
const Math::Matrix2<float> Math::Matrix2<float>::ONES(1.0f, 1.0f, 
        1.0f, 1.0f);
template<>
const Math::Matrix2<double> Math::Matrix2<double>::ONES(1.0, 1.0,
        1.0, 1.0);

/********************************************************************************
 * Function so we can write scalar*matrix2.                                     *
 *******************************************************************************/
template<class Real>
Math::Matrix2<Real> operator*(const Real scalar, const Math::Matrix2<Real>& mat)
{
    return mat * scalar;
}
