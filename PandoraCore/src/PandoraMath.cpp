#include "../include/PandoraMath.h"

template<> const float Pandora::Math::Math<float>::EPSILON = FLT_EPSILON;
template<> const float Pandora::Math::Math<float>::MAX_REAL = FLT_MAX;
template<> const float Pandora::Math::Math<float>::PI = (float)(4.0*atan(1.0));
template<> const float Pandora::Math::Math<float>::TWO_PI = (float)(8.0*atan(1.0));
template<> const float Pandora::Math::Math<float>::HALF_PI = (float)(2.0*atan(1.0));
template<> const float Pandora::Math::Math<float>::INV_PI = (float)(1.0/(4.0*atan(1.0)));
template<> const float Pandora::Math::Math<float>::INV_TWO_PI = (float)(1.0/(8.0*atan(1.0)));
template<> const float Pandora::Math::Math<float>::DEG_TO_RAD = (float)(4.0*atan(1.0)/180);
template<> const float Pandora::Math::Math<float>::RAD_TO_DEG = (float)(180/(4.0*atan(1.0)));

template<> const double Pandora::Math::Math<double>::EPSILON = DBL_EPSILON;
template<> const double Pandora::Math::Math<double>::MAX_REAL = DBL_MAX;
template<> const double Pandora::Math::Math<double>::PI = 4.0*atan(1.0);
template<> const double Pandora::Math::Math<double>::TWO_PI = 8.0*atan(1.0);
template<> const double Pandora::Math::Math<double>::HALF_PI = 2.0*atan(1.0);
template<> const double Pandora::Math::Math<double>::INV_PI = 1.0/(4.0*atan(1.0));
template<> const double Pandora::Math::Math<double>::INV_TWO_PI = 1.0/(8.0*atan(1.0));
template<> const double Pandora::Math::Math<double>::DEG_TO_RAD = 4.0*atan(1.0)/180;
template<> const double Pandora::Math::Math<double>::RAD_TO_DEG = 180/(4.0*atan(1.0));

/*
template<>
float Pandora::Math::Math<float>::FastISqrt(float value)
{
    float x = value;
    float xhalf = 0.5f*x;
    int i = *(int*)&x;
    i = 0x5f375a86 - (i>>1);
    x = *(float*)&i;
    return x*(1.5f - xhalf*x*x);
}

//Double precision.
template<>
double Pandora::Math::Math<double>::FastISqrt(double value)
{
    double half = 0.5*value;
    long long i = *(long long*)&value;
    i = 0x5fe6ec85e7de30daLL - (i >> 1);
    value = *(double*)&i;
    value = value*(1.5 - half*value*value);
    return value;
}*/