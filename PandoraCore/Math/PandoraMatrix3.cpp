/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix3.cpp

Purpose :

Creation Date : 2010-04-28

Last Modified : on. 28. april 2010 kl. 16.20 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "PandoraMatrix3.h"

using namespace Pandora

/********************************************************************************
 * A few special matrices.                                                      *
 *******************************************************************************/
template<>
const Matrix3<float> Matrix3<float>::ZERO(0.0f, 0.0f, 0.0f, 
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f);
template<>
const Matrix3<double> Matrix3<double>::ZERO(0.0, 0.0, 0.0, 
        0.0, 0.0, 0.0, 
        0.0, 0.0, 0.0);

template<>
const Matrix3<float> Matrix3<float>::IDENTITY(1.0f, 0.0f, 0.0f, 
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f);
template<>
const Matrix3<double> Matrix3<double>::IDENTITY(1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0);
