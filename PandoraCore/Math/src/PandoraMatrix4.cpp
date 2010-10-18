/*
-------------------------------------------------------------------------------
File Name : PandoraMatrix4.cpp

Purpose : Implementation of the Matrix4 class in Pandora3D.

Creation Date : 2010-06-26

Last Modified : ma. 18. okt. 2010 kl. 20.49 +0200

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
-------------------------------------------------------------------------------
*/

#include "PandoraMatrix4.h"

namespace Pandora
{
    namespace Math
    {

template<> 
const Matrix4<float> Matrix4<float>::ZERO(  0.0f, 0.0f, 0.0f, 0.0f,
                                            0.0f, 0.0f, 0.0f, 0.0f,
                                            0.0f, 0.0f, 0.0f, 0.0f,
                                            0.0f, 0.0f, 0.0f, 0.0f);
template<> 
const Matrix4<float> Matrix4<float>::IDENTITY(  1.0f, 0.0f, 0.0f, 0.0f,
                                                0.0f, 1.0f, 0.0f, 0.0f,
                                                0.0f, 0.0f, 1.0f, 0.0f,
                                                0.0f, 0.0f, 0.0f, 1.0f);
template<>
const Matrix4<float> Matrix4<float>::ONES(  1.0f, 1.0f, 1.0f, 1.0f,
                                            1.0f, 1.0f, 1.0f, 1.0f,
                                            1.0f, 1.0f, 1.0f, 1.0f,
                                            1.0f, 1.0f, 1.0f, 1.0f);

template<>
const Matrix4<double> Matrix4<double>::ZERO(0.0, 0.0, 0.0, 0.0,
                                            0.0, 0.0, 0.0, 0.0,
                                            0.0, 0.0, 0.0, 0.0,
                                            0.0, 0.0, 0.0, 0.0);
template<>
const Matrix4<double> Matrix4<double>::IDENTITY(1.0, 0.0, 0.0, 0.0,
                                                0.0, 1.0, 0.0, 0.0,
                                                0.0, 0.0, 1.0, 0.0,
                                                0.0, 0.0, 0.0, 1.0);
template<>
const Matrix4<double> Matrix4<double>::ONES(1.0, 1.0, 1.0, 1.0,
                                            1.0, 1.0, 1.0, 1.0,
                                            1.0, 1.0, 1.0, 1.0,
                                            1.0, 1.0, 1.0, 1.0);

    } // namespace Math
} // namespace Pandora
