/*
-------------------------------------------------------------------------------
File Name : PandoraMatrix3.cpp

Purpose :

Creation Date : 2010-06-26

Last Modified : lø. 26. juni 2010 kl. 18.27 +0200

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "PandoraMatrix3.h"

/********************************************************************************
 * Some special matrices.                                                       *
 *******************************************************************************/
template<>
const Pandora::Math::Matrix3<float>
    Pandora::Math::Matrix3<float>::ZERO(        0.0f, 0.0f, 0.0f,
                                                0.0f, 0.0f, 0.0f,
                                                0.0f, 0.0f, 0.0f);
template<>
const Pandora::Math::Matrix3<float>
    Pandora::Math::Matrix3<float>::IDENTITY(    1.0f, 0.0f, 0.0f,
                                                0.0f, 1.0f, 0.0f,
                                                0.0f, 0.0f, 1.0f);
template<>
const Pandora::Math::Matrix3<float>
    Pandora::Math::Matrix3<float>::ONES(        1.0f, 1.0f, 1.0f,
                                                1.0f, 1.0f, 1.0f,
                                                1.0f, 1.0f, 1.0f);

template<>
const Pandora::Math::Matrix3<double>
    Pandora::Math::Matrix3<double>::ZERO(       0.0, 0.0, 0.0,
                                                0.0, 0.0, 0.0,
                                                0.0, 0.0, 0.0);
template<>
const Pandora::Math::Matrix3<double>
    Pandora::Math::Matrix3<double>::IDENTITY(   1.0, 0.0, 0.0,
                                                0.0, 1.0, 0.0,
                                                0.0, 0.0, 1.0);
template<>
const Pandora::Math::Matrix3<double>
    Pandora::Math::Matrix3<double>::ONES(       1.0, 1.0, 1.0,
                                                1.0, 1.0, 1.0,
                                                1.0, 1.0, 1.0);
