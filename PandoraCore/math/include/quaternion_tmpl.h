#ifndef INCLUDED_FROM_QUATERNION_H
#error "quaternion_tmpl.h can only be included from quaternion.h"
#else

template<typename Real>
static Matrix<Real, 4> create_matrix_with_scale_from_quaternion(const Quaternion<Real> & quaternion, const Real & s);

template<typename Real>
Quaternion<Real>::Quaternion()
    : real(1)
{ }

template<typename Real>
Quaternion<Real>::Quaternion(const Real & w, const Real & x, const Real & y, const Real & z)
    : real(w), imag({x, y, z})
{ }

template<typename Real>
Quaternion<Real>::Quaternion(const Real array[4])
    : real(array[0]), imag({array[1], array[2], array[3]})
{ }

template<typename Real>
Quaternion<Real>::Quaternion(const Real & real, const Vector<Real, 3> & imaginary_vector)
    : real(real), imag(imaginary_vector)
{ }

template<typename Real>
Quaternion<Real>::Quaternion(const Vector<Real, 3> & axis, const Real & angle)
    : real(std::cos(angle)), imag(axis * std::sin(angle))
{ }

template<typename Real>
Quaternion<Real>::Quaternion(const Matrix<Real, 4> & matrix)
    : real(0.5 * std::sqrt(matrix_trace(matrix)))
{
    const auto u = matrix_trace(matrix) - 1;
    if (u > matrix(0,0) && u > matrix(1,1) && u > matrix(2,2)) {
        create_quaternion_from_matrix_with_largest_u(matrix);
    } else {
        create_quaternion_from_matrix_with_smallest_u(matrix);
    }
}

template<typename Real>
Vector<Real,3> Quaternion<Real>::get_imag() const
{
    return imag;
}

template<typename Real>
Vector<Real,3> & Quaternion<Real>::get_imag()
{
    return imag;
}

template<typename Real>
Real & Quaternion<Real>::w()
{
    return real;
}

template<typename Real>
Real Quaternion<Real>::w() const
{
    return real;
}

template<typename Real>
Real & Quaternion<Real>::x()
{
    return imag[0];
}

template<typename Real>
Real Quaternion<Real>::x() const
{
    return imag[0];
}

template<typename Real>
Real & Quaternion<Real>::y()
{
    return imag[1];
}

template<typename Real>
Real Quaternion<Real>::y() const
{
    return imag[1];
}

template<typename Real>
Real & Quaternion<Real>::z()
{
    return imag[2];
}

template<typename Real>
Real Quaternion<Real>::z() const
{
    return imag[2];
}

template<typename Real>
Quaternion<Real> & operator+=(Quaternion<Real> & to, const Quaternion<Real> & other)
{
    to.get_imag() += other.get_imag();
    to.w() += other.w();
    return to;
}

template<typename Real>
Quaternion<Real> & operator-=(Quaternion<Real> & to, const Quaternion<Real> & other)
{
    to.get_imag() -= other.get_imag();
    to.w() -= other.w();
    return to;
}

template<typename Real>
Quaternion<Real> & operator*=(Quaternion<Real> & to, const Real & scalar)
{
    to.get_imag() *= scalar;
    to.w() *= scalar;
    return to;
}

template<typename Real>
Quaternion<Real> & operator/=(Quaternion<Real> & to, const Real & scalar)
{
    assert(scalar != 0 && "Ca not divide quaternion by zero");

    auto scalevalue = 1.0/scalar;
    to *= scalevalue;

    return to;
}

template<typename Real>
Matrix<Real, 4> quaternion_to_matrix(const Quaternion<Real> & quaternion)
{
    const auto quat_norm = quaternion_norm(quaternion);

    assert(quat_norm != 0 && "Can not make matrix from zero quaternion");

    const auto s = 2.0 / quat_norm;
    return create_matrix_with_scale_from_quaternion(quaternion, s);
}

template<typename Real>
Matrix<Real, 4> create_matrix_with_scale_from_quaternion(const Quaternion<Real> & quaternion, const Real & s)
{
    Matrix<Real, 4> result;
    const auto real = quaternion.w();
    const auto imag = quaternion.get_imag();

    result(0,0) -= s *(imag[1] * imag[1] + imag[2] * imag[2]);
    result(0,1) += s *(imag[0] * imag[1] - real * imag[2]);
    result(0,2) += s *(imag[0] * imag[2] + real * imag[1]);

    result(1,0) += s *(imag[0] * imag[1] + real * imag[2]);
    result(1,1) -= s *(imag[0] * imag[0] + imag[2] * imag[2]);
    result(1,2) += s *(imag[1] * imag[2] - real * imag[0]);

    result(2,0) += s *(imag[0] * imag[2] - real * imag[1]);
    result(2,1) += s *(imag[1] * imag[2] + real * imag[0]);
    result(2,2) -= s *(imag[0] * imag[0] + imag[1] * imag[1]);

    return result;
}

template<typename Real>
Real quaternion_norm(const Quaternion<Real> & quaternion)
{
    const auto real = quaternion.w();
    const auto imag = quaternion.get_imag();
    return std::sqrt(dot_product(imag, imag) + real * real);
}

template<typename Real>
void quaternion_normalize(Quaternion<Real> & quaternion)
{
    auto scale = quaternion_norm(quaternion);

    assert(scale != 0 && "Can not normalize zero quaternion");

    quaternion /= scale;
}

template<typename Real>
Quaternion<Real> quaternion_conjugate(const Quaternion<Real> & quaternion)
{
    const auto real = quaternion.w();
    const auto imag = quaternion.get_imag();
    return Quaternion<Real>(real, -imag);
}

template<typename Real>
Quaternion<Real> quaternion_inverse(const Quaternion<Real> & quaternion)
{
    const auto real = quaternion.w();
    const auto imag = quaternion.get_imag();

    const auto normsquared = vector_length_squared(imag) +(real * real);

    return quaternion_conjugate(quaternion) / normsquared;
}

template<typename Real>
Quaternion<Real> quaternion_slerp(const Quaternion<Real> & from, const Quaternion<Real> & to, const Real & t)
{
    const auto angle = std::acos(from.real * to.real + dot_product(from.imag, to.imag));
    const auto from_scale = std::sin(angle *(1 - t))/std::sin(angle);
    const auto to_scale = std::sin(angle * t)/std::sin(angle);
    return from_scale * from + to_scale * to;
}

template<typename Real>
Quaternion<Real> operator+(const Quaternion<Real> & left, const Quaternion<Real> & right)
{
    Quaternion<Real> res = left;
    res += right;
    return res;
}

template<typename Real>
Quaternion<Real> operator-(const Quaternion<Real> & left, const Quaternion<Real> & right)
{
    Quaternion<Real> res = left;
    res -= right;
    return res;
}

template<typename Real>
Quaternion<Real> operator*(const Quaternion<Real> & left, const Quaternion<Real> & right)
{
    return Quaternion<Real>(left.w() * right.w() - dot_product(left.imag, right.imag),
            cross_product(left.imag, right.imag) + left.real * right.imag + right.real * left.imag);
}

template<typename Real>
Quaternion<Real> operator*(const Quaternion<Real> & quaternion, const Real & scalar)
{
    Quaternion<Real> res = quaternion;
    res *= scalar;
    return res;
}

template<typename Real>
Quaternion<Real> operator*(const Real & scalar, const Quaternion<Real> & quaternion)
{
    return quaternion * scalar;
}

template<typename Real>
Quaternion<Real> operator/(const Quaternion<Real> & quaternion, const Real & scalar)
{
    Quaternion<Real> res = quaternion;
    res /= scalar;
    return res;
}

template<typename Real>
void Quaternion<Real>::create_quaternion_from_matrix_with_largest_u(const Matrix<Real, 4> & matrix)
{
    imag[0] = matrix(2,1) - matrix(1,2);
    imag[1] = matrix(0,2) - matrix(2,0);
    imag[2] = matrix(1,0) - matrix(0,1);

    imag /= (4 * real);
}

template<typename Real>
void Quaternion<Real>::create_quaternion_from_matrix_with_smallest_u(const Matrix<Real, 4> & matrix)
{
    imag[0] = std::sqrt(matrix(0,0) - matrix(1,1) - matrix(2,2) + matrix(3,3));
    imag[1] = std::sqrt(-matrix(0,0) + matrix(1,1) - matrix(2,2) + matrix(3,3));
    imag[2] = std::sqrt(-matrix(0,0) - matrix(1,1) + matrix(2,2) + matrix(3,3));

    imag *= 0.5;
}

#endif
