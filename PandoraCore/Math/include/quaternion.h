#ifndef MARealH_QUARealERNION_H_INCLUDED
#define MARealH_QUARealERNION_H_INCLUDED

#include "vector3.h"
#include "matrix4.h"

#include <exception>

typedef double Real;

namespace Math
{
    class Quaternion
    {
        public:
            Quaternion ();

            Quaternion (const Real& w, const Real& x, const Real& y, const Real& z);

            Quaternion (const Real array[4]);

            Quaternion (const Real& scalar, const Vector3& imaginary_vector);

            Quaternion (const Matrix4& matrix);

            Real& w ();
            Real& x ();
            Real& y ();
            Real& z ();

            Real w () const;
            Real x () const;
            Real y () const;
            Real z () const;

            Quaternion operator+= (const Quaternion& other);
            Quaternion operator-= (const Quaternion& other);
            Quaternion operator*= (const Real& scalar);
            Quaternion operator/= (const Real& scalar);

            Matrix4 create_matrix () const;

            Real norm () const;
            void normalize ();

            Quaternion conjugate () const;
            Quaternion inverse () const;

        public:
            Real real;
            Vector3 imag;

        protected:
            Matrix4 create_matrix_with_scale (const Real& s) const;

            void create_quaternion_from_matrix_with_largest_u (const Matrix4& matrix);
            void create_quaternion_from_matrix_with_smallest_u (const Matrix4& matrix);

        public:
            class normalizing_zero_quaternion_exception : public std::exception { };
            class can_not_make_matrix_from_zero_quaternion_exception : public std::exception { };
            class division_by_zero_exception : public std::exception { };
    };

    Quaternion operator+ (const Quaternion& left, const Quaternion& right);

    Quaternion operator- (const Quaternion& left, const Quaternion& right);

    Quaternion operator* (const Quaternion& left, const Quaternion& right);

    Quaternion operator* (const Quaternion& quaternion, const Real& scalar);

    Quaternion operator/ (const Quaternion& quaternion, const Real& scalar);
}

#endif // MARealH_QUARealERNION_H_INCLUDED
