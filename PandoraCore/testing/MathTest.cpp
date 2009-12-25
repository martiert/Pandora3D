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
#include <limits.h>
#include "../include/PandoraMath.h"
#include "../include/PandoraSystem.h"

namespace Pandora
{
    class MathTest
    {
        public:
            void sinusTest()
            {
                //Timing tests
                double sinTime = 0.0;
                double sin0Time = 0.0;
                double sin1Time = 0.0;

                double max0Err = 0.0;
                double max1Err = 0.0;
                int iter = 0;
                for(double i = -Math::Math<double>::HALF_PI; i < Math::Math<double>::HALF_PI; i += 0.0000001) {
                    ++iter;
                    double exact = Math::Math<double>::Sin(i);

                    double sin0 = Math::Math<double>::FastSin0(i);

                    double sin1 = Math::Math<double>::FastSin1(i);

                    double err0 = Math::Math<double>::Abs(exact - sin0)/i;
                    double err1 = Math::Math<double>::Abs(exact - sin1)/i;
                    max0Err = (err0 > max0Err) ? err0 : max0Err;
                    max1Err = (err1 > max1Err) ? err1 : max1Err;
                }

                double start = System::getTime();
                for(double i = -Math::Math<double>::HALF_PI; i < Math::Math<double>::HALF_PI; i += 0.0000001) {
                    Math::Math<double>::Sin(i);
                }
                sinTime = (System::getTime() - start);

                start = System::getTime();
                for(double i = -Math::Math<double>::HALF_PI; i < Math::Math<double>::HALF_PI; i += 0.0000001) {
                    Math::Math<double>::FastSin0(i);
                }
                sin0Time = (System::getTime() - start);

                start = System::getTime();
                for(double i = -Math::Math<double>::HALF_PI; i < Math::Math<double>::HALF_PI; i += 0.0000001) {
                    Math::Math<double>::FastSin1(i);
                }
                sin1Time = (System::getTime() - start);

                printf("Time used for normal sin function: %e seconds\n", sinTime/iter);
                printf("Time used for first fast sin function: %e seconds\n", sin0Time/iter);
                printf("\tSpeedup is: %.8f\n", sinTime/sin0Time);
                printf("\tMax error is: %e\n", max0Err);
                printf("Time used for second fast sin function: %e seconds\n", sin1Time/iter);
                printf("\tSpeedup is: %.8f\n", sinTime/sin1Time);
                printf("\tMax error is: %e\n\n", max1Err);
            }

            void cosTest()
            {
                double cosTime;
                double cos0Time;
                double cos1Time;

                double max0Err = 0.0;
                double max1Err = 0.0;

                int iter = 0;
                for(double i = 0; i < Math::Math<double>::PI; i += 0.0000001) {
                    ++iter;
                    double exact = Math::Math<double>::Cos(i);
                    double approx0 = Math::Math<double>::FastCos0(i);
                    double approx1 = Math::Math<double>::FastCos1(i);

                    double err0 = Math::Math<double>::Abs(exact - approx0);
                    double err1 = Math::Math<double>::Abs(exact - approx1);

                    max0Err = (max0Err > err0) ? max0Err : err0;
                    max1Err = (max1Err > err1) ? max1Err : err1;
                }

                double start = System::getTime();
                for(double i = 0; i < Math::Math<double>::PI; i += 0.0000001) {
                    Math::Math<double>::Cos(i);
                }
                cosTime = System::getTime() - start;

                start = System::getTime();
                for(double i = 0; i < Math::Math<double>::PI; i += 0.0000001) {
                    Math::Math<double>::FastCos0(i);
                }
                cos0Time = System::getTime() - start;

                start = System::getTime();
                for(double i = 0; i < Math::Math<double>::PI; i += 0.0000001) {
                    Math::Math<double>::FastCos1(i);
                }
                cos1Time = System::getTime() - start;

                printf("Time used for normal cos function: %e seconds\n", cosTime/iter);
                printf("Time used for first fast cos function: %e seconds\n", cos0Time/iter);
                printf("\tSpeedup is: %.8f\n", cosTime/cos0Time);
                printf("\tMax error is: %e\n", max0Err);
                printf("Time used for second fast cos function: %e seconds\n", cos1Time/iter);
                printf("\tSpeedup is: %.8f\n", cosTime/cos1Time);
                printf("\tMax error is: %e\n\n", max1Err);
            }

            void sqrtTest()
            {
                /*
                double sqrtTime;
                double fstsqrtTime;
                float error = 0.0;

                for(int i = 0; i < 1000000; ++i) {
                    float ans = Math::Math<float>::ISqrt(i);
                    float approx = Math::Math<float>::FastISqrt(i);
                    float err = Math::Math<float>::Abs(ans - approx);
                    error = (error < err) ? err : error;
                }

                double start = System::getTime();
                for(int i = 0; i < 1000000; ++i) {
                    Math::Math<float>::ISqrt(i);
                }
                sqrtTime = System::getTime() - start;

                start = System::getTime();
                for(int i = 0; i < 1000000; ++i) {
                    Math::Math<float>::FastISqrt(i);
                }
                fstsqrtTime = System::getTime() - start;

                printf("Time for normal sqrt function is: %e seconds\n", sqrtTime/1000000);
                printf("Time for fast sqrt function is: %e seconds\n", fstsqrtTime/1000000);
                printf("\tSpeedup is: %.8f\n", sqrtTime/fstsqrtTime);
                printf("\tMax error is: %e\n\n", error);*/
                printf("%.4f\n%.4f\n%.4f\n\n", Math::Math<float>
            }
    };
}

int main()
{
    Pandora::MathTest test;
    //test.sinusTest();
    //test.cosTest();
    test.sqrtTest();
    return 0;
}
