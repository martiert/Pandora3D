#ifndef INCLUDED_FROM_VECTOR2_H
#error "vector2_tmpl.h should only be included from vector2.h"
#else

template<typename Real>
Vector<Real, 2> perp_vector(const Vector<Real, 2> & vector)
{
    return Vector<Real, 2>({vector[1], -vector[0]});
}

template<typename Real>
void generate_orthonormal_basis(Vector<Real, 2> & vector1, Vector<Real, 2> & vector2)
{
    Vector<Real, 2> zero_vector;
    assert(vector1 != vector2 &&
            "Can not make orthonormal basis from equal vectors");

    assert(vector1 != zero_vector &&
            vector2 != zero_vector &&
            "Can not make orthonormal basis from a zero vector");

    normalize_vector(vector1);
    vector2 = perp_vector(vector1);
}

#endif
