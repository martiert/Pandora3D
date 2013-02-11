#ifndef INCLUDED_FROM_VECTOR3_H
#error "vector3_tmpl.h should only be included from vector3.h"
#else

template<typename Real>
Vector<Real, 3> cross_product(const Vector<Real, 3> & left, const Vector<Real, 3> & right)
{
    Vector<Real, 3> result;

    result[0] = left[1]*right[2] - left[2]*right[1];
    result[1] = left[2]*right[0] - left[0]*right[2];
    result[2] = left[0]*right[1] - left[1]*right[0];

    return result;
}

template<typename Real>
void generate_orthonormal_basis(Vector<Real, 3> & vector1, Vector<Real, 3> & vector2, Vector<Real, 3> & vector3)
{
    Vector<Real, 3> zero;
    assert(vector1 != zero &&
            vector2 != zero &&
            vector3 != zero &&
            "Can not make orthonormal basis with zero vector");

    assert(vector1 != vector2 &&
            vector1 != vector3 &&
            vector2 != vector3 &&
            "Can not make orthonormal basis with equal vectors");

    vector2 = cross_product(vector1, vector3);
    vector3 = cross_product(vector1, vector2);

    normalize_vector(vector1);
    normalize_vector(vector2);
    normalize_vector(vector3);
}

#endif
