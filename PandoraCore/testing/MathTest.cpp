/*
-------------------------------------------------------------------------------
File Name : MathTest.c

Purpose : Testing of the Fast Math functions from PandoraMath.h

Creation Date : 2009-12-25

Last Modified : fr. 25. des. 2009 kl. 17.42 +0100

Created By :  Martin Ertsås
-------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "../include/PandoraMath.h"
#include "../include/PandoraSystem.h"

namespace Pandora
{
    class MathTest
    {
        public:
            void sinusTest()
            {
                int runs = 1000000;
                //Timing tests
                double sinTime = 0.0;
                double sin0Time = 0.0;
                double sin1Time = 0.0;

                float max0Err = 0.0;
                float max1Err = 0.0;
                for(int i = 0; i < runs; ++i) {
                    float rand = Math::Math<float>::IntervalRandom(
                            -Math::Math<float>::HALF_PI,
                            Math::Math<float>::HALF_PI);

                    float exact = Math::Math<float>::Sin(rand);

                    float sin0 = Math::Math<float>::FastSin0(rand);

                    float sin1 = Math::Math<float>::FastSin1(rand);

                    float err0 = Math::Math<float>::Abs(exact - sin0)/rand;
                    float err1 = Math::Math<float>::Abs(exact - sin1)/rand;
                    max0Err = (err0 > max0Err) ? err0 : max0Err;
                    max1Err = (err1 > max1Err) ? err1 : max1Err;
                }

                double start = System::getTime();
                for(int i = 0; i < runs; ++i) {
                    float rand = Math::Math<float>::IntervalRandom(
                            -Math::Math<float>::HALF_PI,
                            Math::Math<float>::HALF_PI);
                    float exact = Math::Math<float>::Sin(rand);
                }
                sinTime = System::getTime() - start;

                start = System::getTime();
                for(int i = 0; i < runs; ++i) {
                    float rand = Math::Math<float>::IntervalRandom(
                            -Math::Math<float>::HALF_PI,
                            Math::Math<float>::HALF_PI);
                    float test = Math::Math<float>::FastSin0(rand);
                }
                sin0Time = System::getTime() - start;

                start = System::getTime();
                for(int i = 0; i < runs; ++i) {
                    float rand = Math::Math<float>::IntervalRandom(
                            -Math::Math<float>::HALF_PI,
                            Math::Math<float>::HALF_PI);
                    float test = Math::Math<float>::FastSin1(rand);
                }
                sin1Time = System::getTime() - start;

                printf("Time used for normal sin function: %.8f\n", sinTime);
                printf("Time used for first fast sin function: %.8f\n", sin0Time);
                printf("\tMax error is: %e\n", max0Err);
                printf("Time used for second fast sin function: %.8f\n", sin1Time);
                printf("\tMax error is: %e\n", max1Err);
            }
    };
}

int main()
{
    Pandora::MathTest test;
    test.sinusTest();
    return 0;
}
