#ifndef MATH_VECTOR2_H_INCLUDED
#define MATH_VECTOR2_H_INCLUDED

#include <exception>
#include <string>

typedef double Real;

namespace Math
{
    class Vector2
    {
        public:
            Real x;
            Real y;

        public:
            Vector2 ();
            Vector2 (const Real x, const Real y);
            Vector2 (const Real data[2]);

            Real& operator[] (const size_t i);
            Real operator[] (const size_t i) const;
            operator Real* ();
            operator const Real* () const;

            Vector2& operator+= (const Vector2& other);
            Vector2& operator-= (const Vector2& other);
            Vector2& operator*= (const Vector2& other);
            Vector2& operator*= (const Real& scalar);
            Vector2& operator/= (const Real& scalar);

            Real length () const;
            Real lengthSquared () const;

            Real dot (const Vector2& other) const;
            Vector2 perp () const;

            void normalize ();

            static void generateOrthonormalBasis (Vector2& vec1, Vector2& vec2);

        public:
            class can_not_make_orthonormal_basis_from_equal_vectors_exception : public std::exception
            { };

            class can_not_make_orthonormal_basis_with_zero_vector_exception : public std::exception
            { };

            class can_not_normalize_zero_vector_exception : public std::exception
            { };

            class division_by_zero_exception : public std::exception
            { };

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

    Vector2 operator- (const Vector2& vec);

    Vector2 operator+ (const Vector2& vec1, const Vector2& vec2);

    Vector2 operator- (const Vector2& vec1, const Vector2& vec2);

    Vector2 operator* (const Vector2& vec1, const Vector2& vec2);

    Vector2 operator* (const Vector2& vec, const Real real);

    Vector2 operator* (const Real real, const Vector2& vec);

    Vector2 operator/ (const Vector2& vec, const Real real);

    bool operator== (const Vector2& vec1, const Vector2& vec2);

    bool operator!= (const Vector2& vec1, const Vector2& vec2);
}

#endif // MATH_VECTOR2_H_INCLUDED
