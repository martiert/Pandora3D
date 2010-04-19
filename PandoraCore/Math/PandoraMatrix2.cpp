/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix2.cpp

Purpose :

Creation Date : 2010-04-19

Last Modified : ma. 19. april 2010 kl. 13.53 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "PandoraMatrix2.h"

using namespace Pandora

/********************************************************************************
 * A few special matrices.                                                      *
 *******************************************************************************/
template<>
const Matrix2<float> Matrix2<float>::ZERO(0.0f, 0.0f, 0.0f, 0.0f);
template<>
const Matrix2<double> Matrix2<double>::ZERO(0.0, 0.0, 0.0, 0.0);

template<>
const Matrix2<float> Matrix2<float>::IDENTITY(1.0f, 0.0f, 0.0f, 1.0f);
const Matrix2<double> Matrix2<double>::IDENTITY(1.0, 0.0, 0.0, 1.0);
