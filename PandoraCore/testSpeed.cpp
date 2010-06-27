/*
-------------------------------------------------------------------------------
File Name : testSpeed.cpp

Purpose :

Creation Date : 2010-06-27

Last Modified : s�. 27. juni 2010 kl. 22.25 +0200

Created By :  Martin Erts�s
-------------------------------------------------------------------------------
*/

#include "Math/PandoraMatrix4.h"

using namespace Pandora;

int main()
{
    Math::Mat4f test1, test2;
    for(int i = 0; i < 10000000; i++) {
        test1 *= test2;
    }
    return 0;
}
