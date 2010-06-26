/*
-------------------------------------------------------------------------------
File Name : PandoraMatrix4.cpp

Purpose :

Creation Date : 2010-06-26

Last Modified : lø. 26. juni 2010 kl. 18.33 +0200

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include "PandoraMatrix4.h"

/********************************************************************************
 * Some special matrices.                                                       *
 *******************************************************************************/
template<>
const Pandora::Math::Matrix4<float>
    Pandora::Math::Matrix4<float>::ZERO(        0.0f, 0.0f, 0.0f, 0.0f,
                                                0.0f, 0.0f, 0.0f, 0.0f,
                                                0.0f, 0.0f, 0.0f, 0.0f,
                                                0.0f, 0.0f, 0.0f, 0.0f);
template<>
const Pandora::Math::Matrix4<float>
    Pandora::Math::Matrix4<float>::IDENTITY(    1.0f, 0.0f, 0.0f, 0.0f,
                                                0.0f, 1.0f, 0.0f, 0.0f,
                                                0.0f, 0.0f, 1.0f, 0.0f,
                                                0.0f, 0.0f, 0.0f, 1.0f);
template<>
const Pandora::Math::Matrix4<float>
    Pandora::Math::Matrix4<float>::ONES(        1.0f, 1.0f, 1.0f, 1.0f,
                                                1.0f, 1.0f, 1.0f, 1.0f,
                                                1.0f, 1.0f, 1.0f, 1.0f,
                                                1.0f, 1.0f, 1.0f, 1.0f);

template<>
const Pandora::Math::Matrix4<double>
    Pandora::Math::Matrix4<double>::ZERO(       0.0, 0.0, 0.0, 0.0,
                                                0.0, 0.0, 0.0, 0.0,
                                                0.0, 0.0, 0.0, 0.0,
                                                0.0, 0.0, 0.0, 0.0);
template<>
const Pandora::Math::Matrix4<double>
    Pandora::Math::Matrix4<double>::IDENTITY(   1.0, 0.0, 0.0, 0.0,
                                                0.0, 1.0, 0.0, 0.0,
                                                0.0, 0.0, 1.0, 0.0,
                                                0.0, 0.0, 0.0, 1.0);
template<>
const Pandora::Math::Matrix4<double>
    Pandora::Math::Matrix4<double>::ONES(       1.0, 1.0, 1.0, 1.0,
                                                1.0, 1.0, 1.0, 1.0,
                                                1.0, 1.0, 1.0, 1.0,
                                                1.0, 1.0, 1.0, 1.0);
