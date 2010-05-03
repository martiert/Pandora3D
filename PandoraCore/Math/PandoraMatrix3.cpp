/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix3.cpp

Purpose : Templates for the Pandora 3D Matrix.

Creation Date : 2010-04-28

Last Modified : ma. 03. mai 2010 kl. 21.40 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "PandoraMatrix3.h"

using namespace Pandora

/********************************************************************************
 * A few special matrices.                                                      *
 *******************************************************************************/
template<>
const Math::Matrix3<float> Math::Matrix3<float>::ZERO(0.0f, 0.0f, 0.0f, 
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f);
template<>
const Math::Matrix3<double> Math::Matrix3<double>::ZERO(0.0, 0.0, 0.0, 
        0.0, 0.0, 0.0, 
        0.0, 0.0, 0.0);

template<>
const Math::Matrix3<float> Math::Matrix3<float>::IDENTITY(1.0f, 0.0f, 0.0f, 
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f);
template<>
const Math::Matrix3<double> Math::Matrix3<double>::IDENTITY(1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0);

template<>
const Math::Matrix3<float> Math::Matrix3<float>::ZERO(1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f);
template<>
const Math::Matrix3<double> Math::Matrix3<double>::ZERO(1.0, 1.0, 1.0,
        1.0, 1.0, 1.0,
        1.0, 1.0, 1.0);

/********************************************************************************
 * Operator so we can write scalar*matrix.                                      *
 *******************************************************************************/
template<class Real>
Math::Matrix3<Real> operator*(const Real scalar, const Math::Matrix3<Real>& mat)
{
    return mat * scalar;
}
