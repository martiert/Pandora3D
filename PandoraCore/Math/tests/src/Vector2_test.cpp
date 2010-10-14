/*
-------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2010-10-14

Last Modified : Thu Oct 14 13:48:32 2010

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
-------------------------------------------------------------------------------
*/

#include "Vector2_test.h"

using Pandora::Math::Vec2f;

Vector2_test::Vector2_test()
{
    float tmp[2] = {4.0, 6.7};
    vec1 = Vec2f(4.0, 2.0);
    vec2 = Vec2f(tmp);
    vec3 = Vec2f(vec2);
}

void Vector2_test::test_construct()
{
}
