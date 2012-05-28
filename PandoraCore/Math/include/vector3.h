#ifndef MATH_VECTOR3_HPP_INCLUDED
#define MATH_VECTOR3_HPP_INCLUDED

#include <type_traits>
#include <exception>
#include <cmath>
#include <string>

namespace Math
{
    template<typename T, class Enable = void>
    class Vector3;

    template<typename T>
    class Vector3<T, typename std::enable_if<std::is_arithmetic<T>::value>::type>
    {
        public:
            T x;
            T y;
            T z;

        public:
            Vector3 ();
            Vector3 (const T& x, const T& y, const T& z);
            Vector3 (const T data[3]);

            T& operator[] (const size_t i);
            T operator[] (const size_t i) const;
            operator T* ();
            operator const T* () const;

            Vector3& operator+= (const Vector3& vec);
            Vector3& operator-= (const Vector3& vec);
            Vector3& operator*= (const Vector3& vec);
            Vector3& operator*= (const T& scalar);
            Vector3& operator/= (const T& scalar);

            T dot (const Vector3& vec) const;

            T length () const;
            T lengthSquared () const;

            void normalize ();

            Vector3 cross (const Vector3& other) const;

            static void generateOrthonormalBasis (Vector3<T>& vec1, Vector3<T>& vec2, Vector3<T>& vec3);
        public:
            class normalizing_zero_vector_exception : public std::exception
            {};

            class division_by_zero_exception : public std::exception
            {};

            class can_not_make_orthonormal_basis_with_zero_vector_exception : std::exception
            {};

            class can_not_make_orthonormal_basis_with_equal_vectors_exception : std::exception
            {};

            class index_operator_out_of_range_exception : public std::exception
            {
                public:
                    index_operator_out_of_range_exception (const size_t& i)
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
    };

    typedef Vector3<float> Vec3f;
    typedef Vector3<double> Vec3d;
    typedef Vector3<int> Vec3i;
    typedef Vector3<unsigned int> Vec3u;

    template<typename T>
    Vector3<T> operator- (const Vector3<T>& vec);

    template<typename T>
    Vector3<T> operator+ (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    Vector3<T> operator- (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    Vector3<T> operator* (const Vector3<T>& vec, const T& scalar);

    template<typename T>
    Vector3<T> operator* (const T& scalar, const Vector3<T>& vec);

    template<typename T>
    Vector3<T> operator* (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    Vector3<T> operator/ (const Vector3<T>& vec, const T& scalar);

    template<typename T>
    bool operator== (const Vector3<T>& vec1, const Vector3<T>& vec2);

    template<typename T>
    bool operator!= (const Vector3<T>& vec1, const Vector3<T>& vec2);

#define VECTOR3_INCLUDE_FILE
#include "vector3-impl.h"
#undef VECTOR3_INCLUDE_FILE

}

#endif // MATH_VECTOR3_HPP_INCLUDED
