/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix4.cpp

Purpose : Templates for the Pandora 4D matrix.

Creation Date : 2010-05-03

Last Modified : ma. 03. mai 2010 kl. 21.40 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "PandoraMatrix4.h"
using namespace Pandora;

/********************************************************************************
 * Some templated matrices.                                                     *
 *******************************************************************************/
float zerof[16] = {0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f};
float identf[16] = {1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f};
float onesf[16] = {1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f};
template<>
const Math::Matrix4<float> Math::Matrix4<float>::ZERO(zerof);
template<>
const Math::Matrix4<float> Math::Matrix4<float>::IDENTITY(identf);
template<>
const Math::Matrix4<float> Math::Matrix4<float>::ONES(onesf);

double zerod[16] = {0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0};
double identd[16] = {1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0};
double onesd[16] = {1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0};
template<> 
const Math::Matrix4<double> Math::Matrix4<double>::ZERO(zerod);
template<>
const Math::Matrix4<double> Math::Matrix4<double>::IDENTITY(identd);
template<>
const Math::Matrix4<double> Math::Matrix4<double>::ONES(onesd);

/********************************************************************************
 * A function so we can write const * matrix.                                   *
 *******************************************************************************/
template<class Real>
Math::Matrix4<Real> operator*(const Real scalar, const Math::Matrix4<Real>& mat)
{
    return mat * scal;
}
