#ifndef MATH_VECTOR2_H_INCLUDED
#define MATH_VECTOR2_H_INCLUDED

#include <type_traits>
#include <stdexcept>
#include <cmath>

namespace Math
{
    class can_not_make_orthonormal_2d_vectors_from_equal_vectors_exception : public std::exception
    { };

    class can_not_make_orthonormal_2d_vectors_with_zero_vector_exception : public std::exception
    { };

    class can_not_normalize_zero_vector2d_exception : public std::exception
    { };

    class can_not_divide_vector2d_by_zero_exception : public std::exception
    { };

    class vector2d_index_out_of_range_exception : public std::exception
    {
        public:
            vector2d_index_out_of_range_exception (const size_t& i)
                : index (i)
            {}

            virtual const char* what () const throw ()
            {
                std::string error = "Tried to access index: " + index;
                return error.c_str ();
            }

        private:
            size_t index;
    };

    template<typename T, class Enable = void>
    class Vector2;

    template<typename T>
    class Vector2<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>
    {
        public:
            T x;
            T y;

        public:
            Vector2 ();
            Vector2 (const T x, const T y);
            Vector2 (const T data[2]);

            T& operator[] (const size_t i);
            T operator[] (const size_t i) const;
            operator T* ();
            operator const T* () const;

            Vector2& operator+= (const Vector2& other);
            Vector2& operator-= (const Vector2& other);
            Vector2& operator*= (const Vector2& other);
            Vector2& operator*= (const T& scalar);
            Vector2& operator/= (const T& scalar);

            T length () const;
            T lengthSquared () const;

            T dot (const Vector2& other) const;
            Vector2 perp () const;

            void normalize ();
    };

    typedef Vector2<float> Vec2f;
    typedef Vector2<double> Vec2d;
    typedef Vector2<int> Vec2i;
    typedef Vector2<unsigned int> Vec2u;

    template<typename T>
    Vector2<T> operator- (const Vector2<T>& vec);

    template<typename T>
    Vector2<T> operator+ (const Vector2<T>& vec1, const Vector2<T>& vec2);

    template<typename T>
    Vector2<T> operator- (const Vector2<T>& vec1, const Vector2<T>& vec2);

    template<typename T>
    Vector2<T> operator* (const Vector2<T>& vec1, const Vector2<T>& vec2);

    template<typename T>
    Vector2<T> operator* (const Vector2<T>& vec, const T real);

    template<typename T>
    Vector2<T> operator* (const T real, const Vector2<T>& vec);

    template<typename T>
    Vector2<T> operator/ (const Vector2<T>& vec, const T real);

    template<typename T>
    bool operator== (const Vector2<T>& vec1, const Vector2<T>& vec2);

    template<typename T>
    bool operator!= (const Vector2<T>& vec1, const Vector2<T>& vec2);

    template<typename T>
    void generateOrthonormalBasis (Vector2<T>& vec1, Vector2<T>& vec2);

#define VECTOR2_INCLUDE_FILE
#include "vector2-impl.h"
#undef VECTOR2_INCLUDE_FILE
}

#endif // MATH_VECTOR2_H_INCLUDED
