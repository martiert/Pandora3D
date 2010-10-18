/*
-------------------------------------------------------------------------------
File Name : PandoraMatrix3.cpp

Purpose : Implementation of the Matrix3 class in Pandora 3D.

Creation Date : 2010-06-26

Last Modified : ma. 18. okt. 2010 kl. 20.49 +0200

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
-------------------------------------------------------------------------------
*/

#include "PandoraMatrix3.h"

namespace Pandora
{
    namespace Math
    {

template<> const Matrix3<float> Matrix3<float>::ZERO(   0.0f, 0.0f, 0.0f,
                                                        0.0f, 0.0f, 0.0f,
                                                        0.0f, 0.0f, 0.0f);
template<> const Matrix3<float> Matrix3<float>::IDENTITY(   1.0f, 0.0f, 0.0f,
                                                            0.0f, 1.0f, 0.0f,
                                                            0.0f, 0.0f, 1.0f);
template<> const Matrix3<float> Matrix3<float>::ONES(   1.0f, 1.0f, 1.0f,
                                                        1.0f, 1.0f, 1.0f,
                                                        1.0f, 1.0f, 1.0f);

template<> const Matrix3<double> Matrix3<double>::ZERO( 0.0, 0.0, 0.0,
                                                        0.0, 0.0, 0.0,
                                                        0.0, 0.0, 0.0);
template<> const Matrix3<double> Matrix3<double>::IDENTITY( 1.0, 0.0, 0.0,
                                                            0.0, 1.0, 0.0,
                                                            0.0, 0.0, 1.0);
template<> const Matrix3<double> Matrix3<double>::ONES( 1.0, 1.0, 1.0,
                                                        1.0, 1.0, 1.0,
                                                        1.0, 1.0, 1.0);

    } // namespace Math
} // namespace Pandora
