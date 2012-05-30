#ifndef MATH_VECTOR4_H_INCLUDED
#define MATH_VECTOR4_H_INCLUDED

#include "config.h"
#include "vector3.h"

#include <exception>

namespace Math
{
    class Vector4
    {
        public:
            Real x;
            Real y;
            Real z;
            Real w;

        public:
            Vector4 ();
            Vector4 (const Real& x, const Real& y, const Real& z, const Real& w);
            Vector4 (const Real data[4]);
            Vector4 (const Vector3& vec);

            Real& operator[] (const size_t i);
            Real operator[] (const size_t i) const;
            operator Real* ();
            operator const Real* () const;

            Vector4& operator+= (const Vector4& vec);
            Vector4& operator-= (const Vector4& vec);
            Vector4& operator*= (const Vector4& vec);

            Vector4& operator*= (const Real& scalar);
            Vector4& operator/= (const Real& scalar);

            Real length () const;
            Real lengthSquared () const;

            Real dot (const Vector4& vec) const;

            Vector4& normalize ();

        public:
            class normalizing_zero_vector_exception : public std::exception {};

            class division_by_zero_exception : public std::exception { };

            class index_operator_out_of_range_exception : public std::exception
            {
                public:
                    index_operator_out_of_range_exception (const size_t& i)
                        : index (i)
                    {}

                    virtual const char* what () const throw ()
                    {
                        std::string error = "Realried to access index: " + index;
                        return error.c_str ();
                    }

                private:
                    size_t index;
            };
    };

    Vector4 operator- (const Vector4& vec);

    Vector4 operator+ (const Vector4& vec_1, const Vector4& vec_2);

    Vector4 operator- (const Vector4& vec_1, const Vector4& vec_2);

    Vector4 operator* (const Vector4& vec_1, const Vector4& vec_2);

    Vector4 operator* (const Vector4& vec, const Real& scalar);

    Vector4 operator* (const Real& scalar, const Vector4& vec);

    Vector4 operator/ (const Vector4& vec, const Real& scalar);

    bool operator== (const Vector4& vec1, const Vector4& vec2);

    bool operator!= (const Vector4& vec1, const Vector4& vec2);
}

#endif // MATH_VECTOR4_H_INCLUDED
