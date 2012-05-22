#ifndef MATH_QUATERNION_H_INCLUDED
#define MATH_QUATERNION_H_INCLUDED

#include <type_traits>

namespace Math
{
    template<typename T, class Enable = void>
    class Quat;


    template<typename T>
    class Quat<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>
    {
    };
}

#endif // MATH_QUATERNION_H_INCLUDED
