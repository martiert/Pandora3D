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

            void tanTest()
            {
                double time;
                double time0;
                double time1;
                double err0 = 0.0;
                double err1 = 0.0;
                double PI_FOURTH = Math::Math<double>::HALF_PI*0.5;
                int iter = 0;

                for(double i = -PI_FOURTH; i < PI_FOURTH; i += 0.0000001) {
                    iter++;
                    double exact = Math::Math<double>::Tan(i);
                    double approx0 = Math::Math<double>::FastTan0(i);
                    double approx1 = Math::Math<double>::FastTan1(i);

                    double error0 = Math::Math<double>::Abs(exact - approx0);
                    double error1 = Math::Math<double>::Abs(exact - approx1);

                    err0 = (error0 > err0) ? error0 : err0;
                    err1 = (error1 > err1) ? error1 : err1;
                }

                double start = System::getTime();
                for(double i = -PI_FOURTH; i < PI_FOURTH; i += 0.0000001) {
                    Math::Math<double>::Tan(i);
                }
                time = System::getTime() - start;

                start = System::getTime();
                for(double i = -PI_FOURTH; i < PI_FOURTH; i += 0.0000001) {
                    Math::Math<double>::FastTan0(i);
                }
                time0 = System::getTime() - start;
                
                start = System::getTime();
                for(double i = -PI_FOURTH; i < PI_FOURTH; i += 0.0000001) {
                    Math::Math<double>::FastTan1(i);
                }
                time1 = System::getTime() - start;

                printf("Time for normal tan function: %e seconds\n", time/iter);
                printf("Time for first fast tan function: %e seconds\n", time0/iter);
                printf("\tSpeedup: %.8f\n", time/time0);
                printf("\tError: %e\n", err0);
                printf("Time for second fast tan function: %e seconds\n", time1/iter);
                printf("\tSpeedup: %.8f\n", time/time1);
                printf("\tError: %e\n", err1);
            }
    };
}

int main()
{
    Pandora::MathTest test;
    //test.sinusTest();
    //test.cosTest();
    //test.tanTest();
    return 0;
}
