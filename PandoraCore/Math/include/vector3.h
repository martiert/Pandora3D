#ifndef MATH_VECTOR3_HPP_INCLUDED
#define MATH_VECTOR3_HPP_INCLUDED

#include <exception>
#include <string>

typedef double Real;

namespace Math
{
    class Vector3
    {
        public:
            Real x;
            Real y;
            Real z;

        public:
            Vector3 ();
            Vector3 (const Real& x, const Real& y, const Real& z);
            Vector3 (const Real data[3]);

            Real& operator[] (const size_t i);
            Real operator[] (const size_t i) const;
            operator Real* ();
            operator const Real* () const;

            Vector3& operator+= (const Vector3& vec);
            Vector3& operator-= (const Vector3& vec);
            Vector3& operator*= (const Vector3& vec);
            Vector3& operator*= (const Real& scalar);
            Vector3& operator/= (const Real& scalar);

            Real dot (const Vector3& vec) const;

            Real length () const;
            Real lengthSquared () const;

            void normalize ();

            Vector3 cross (const Vector3& other) const;

            static void generateOrthonormalBasis (Vector3& vec1, Vector3& vec2, Vector3& vec3);
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
                        std::string error = "Realried to access index: " + index;
                        return error.c_str ();
                    }

                private:
                    size_t index;
            };
    };

    Vector3 operator- (const Vector3& vec);

    Vector3 operator+ (const Vector3& vec1, const Vector3& vec2);

    Vector3 operator- (const Vector3& vec1, const Vector3& vec2);

    Vector3 operator* (const Vector3& vec, const Real& scalar);

    Vector3 operator* (const Real& scalar, const Vector3& vec);

    Vector3 operator* (const Vector3& vec1, const Vector3& vec2);

    Vector3 operator/ (const Vector3& vec, const Real& scalar);

    bool operator== (const Vector3& vec1, const Vector3& vec2);

    bool operator!= (const Vector3& vec1, const Vector3& vec2);
}

#endif // MATH_VECTOR3_HPP_INCLUDED
