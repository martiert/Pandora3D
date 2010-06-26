/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix2.cpp

Purpose :

Creation Date : 2010-05-05

Last Modified : lø. 26. juni 2010 kl. 16.56 +0200

Created By :  Martin Ertsås
--------------------------------------------------------------------------------
*/

#include "PandoraMatrix2.h"

/********************************************************************************
 * Some special matrices.                                                       *
 *******************************************************************************/
template<>
const Pandora::Math::Matrix2<float> 
    Pandora::Math::Matrix2<float>::ZERO(0.0f, 0.0f, 0.0f, 0.0f);
template<>
const Pandora::Math::Matrix2<double>
    Pandora::Math::Matrix2<double>::ZERO(0.0, 0.0, 0.0, 0.0);

template<>
const Pandora::Math::Matrix2<float>
    Pandora::Math::Matrix2<float>::IDENTITY(1.0f, 0.0f, 0.0f, 1.0f);
template<>
const Pandora::Math::Matrix2<double>
    Pandora::Math::Matrix2<double>::IDENTITY(1.0, 0.0, 0.0, 1.0);

template<>
const Pandora::Math::Matrix2<float>
    Pandora::Math::Matrix2<float>::ONES(1.0f, 1.0f, 1.0f, 1.0f);
template<>
const Pandora::Math::Matrix2<double>
    Pandora::Math::Matrix2<double>::ONES(1.0, 1.0, 1.0, 1.0);
