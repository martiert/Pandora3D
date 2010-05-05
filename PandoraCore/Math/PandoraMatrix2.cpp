/*
--------------------------------------------------------------------------------
File Name : PandoraMatrix2.cpp

Purpose :

Creation Date : 2010-05-05

Last Modified : on. 05. mai 2010 kl. 22.24 +0200

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

/********************************************************************************
 * So we can write Real * Matrix                                                *
 *******************************************************************************/
template<class Real>
Pandora::Math::Matrix2<Real> operator*(const Real& scale, 
        const Pandora::Math::Matrix2<Real>& mat)
{
    return mat * scale;
}
