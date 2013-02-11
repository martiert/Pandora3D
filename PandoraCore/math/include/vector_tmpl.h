#ifndef INCLUDED_FROM_VECTOR_H
#error "vector_tmpl.h should only be included from vector.h"
#else

template<typename Real, size_t dim>
Vector<Real, dim>::Vector()
    : data {{0,}}
{
}

template<typename Real, size_t dim>
Vector<Real, dim>::Vector(std::initializer_list<Real> arguments)
{
    assert(arguments.size() == dim &&
            "Creation of an N dimensional vector requires N or zero arguments");
    std::copy(arguments.begin(), arguments.end(), data.begin());
}

template<typename Real, size_t dim>
Vector<Real, dim>::Vector(const Real array[dim])
{
    std::copy(array, array + dim, data.begin());
}

template<typename Real, size_t dim>
Vector<Real, dim> & Vector<Real, dim>::operator=(const Real array[dim])
{
    std::copy(array, array + dim, data.begin());
    return *this;
}

template<typename Real, size_t dim>
const Real* Vector<Real, dim>::begin() const
{
    return data.cbegin();
}

template<typename Real, size_t dim>
const Real* Vector<Real, dim>::end() const
{
    return data.cend();
}

template<typename Real, size_t dim>
Real* Vector<Real, dim>::begin()
{
    return data.begin();
}

template<typename Real, size_t dim>
Real* Vector<Real, dim>::end()
{
    return data.end();
}


template<typename Real, size_t dim>
Real & Vector<Real, dim>::operator[](const size_t & i)
{
    assert(i < dim && "Index operator out of range");
    return data[i];
}

template<typename Real, size_t dim>
Real Vector<Real, dim>::operator[](const size_t & i) const
{
    assert(i < dim && "Index operator out of range");
    return data[i];
}

template<typename Real, size_t dim>
Real vector_length(const Vector<Real, dim> & vector)
{
    return std::sqrt(vector_length_squared(vector));
}

template<typename Real, size_t dim>
Real vector_length_squared(const Vector<Real, dim> & vector)
{
    return dot_product(vector, vector);
}

template<typename Real, size_t dim>
Vector<Real, dim> normalize_vector(Vector<Real, dim> & vector)
{
    Real length = vector_length(vector);

    assert(length != 0 && "Can not normalize zero vector");

    for (size_t i = 0; i < dim; ++i) {
        vector[i] /= length;
    }
    return vector;
}

template<typename Real, size_t dim>
Real dot_product(const Vector<Real, dim> & left, const Vector<Real, dim> & right)
{
    Real result = 0;
    for (size_t i = 0; i < dim; ++i) {
        result += left[i] * right[i];
    }
    return result;
}

template<typename Real, size_t dim>
Vector<Real, dim> & operator+=(Vector<Real, dim> & to, const Vector<Real, dim> & from)
{
    for (size_t i = 0; i < dim; ++i) {
        to[i] += from[i];
    }
    return to;
}

template<typename Real, size_t dim>
Vector<Real, dim> & operator-=(Vector<Real, dim> & to, const Vector<Real, dim> & from)
{
    for (size_t i = 0; i < dim; ++i) {
        to[i] -= from[i];
    }
    return to;
}

template<typename Real, size_t dim>
Vector<Real, dim> & operator*=(Vector<Real, dim> & to, const Vector<Real, dim> & from)
{
    for (size_t i = 0; i < dim; ++i) {
        to[i] *= from[i];
    }
    return to;
}

template<typename Real, size_t dim>
Vector<Real, dim> & operator*=(Vector<Real, dim> & to, const Real & scalar)
{
    for (size_t i = 0; i < dim; ++i) {
        to[i] *= scalar;
    }
    return to;
}

template<typename Real, size_t dim>
Vector<Real, dim> & operator/=(Vector<Real, dim> & to, const Real & scalar)
{
    assert(scalar != 0 && "Can not divide vector by zero");
    for (size_t i = 0; i < dim; ++i) {
        to[i] /= scalar;
    }
    return to;
}

template<typename Real, size_t dim>
Vector<Real, dim> operator-(const Vector<Real, dim> & vector)
{
    return vector * (Real) -1;
}

template<typename Real, size_t dim>
Vector<Real, dim> operator+(const Vector<Real, dim> & left, const Vector<Real, dim> & right)
{
    Vector<Real, dim> result = left;
    result += right;
    return result;
}

template<typename Real, size_t dim>
Vector<Real, dim> operator-(const Vector<Real, dim> & left, const Vector<Real, dim> & right)
{
    Vector<Real, dim> result = left;
    result -= right;
    return result;
}

template<typename Real, size_t dim>
Vector<Real, dim> operator*(const Vector<Real, dim> & left, const Vector<Real, dim> & right)
{
    Vector<Real, dim> result = left;
    result *= right;
    return result;
}

template<typename Real, size_t dim>
Vector<Real, dim> operator*(const Vector<Real, dim> & vector, const Real & scalar)
{
    Vector<Real, dim> result = vector;
    result *= scalar;
    return result;
}

template<typename Real, size_t dim>
Vector<Real, dim> operator*(const Real & scalar, const Vector<Real, dim> & vector)
{
    return vector * scalar;
}

template<typename Real, size_t dim>
Vector<Real, dim> operator/(const Vector<Real, dim> & vector, const Real & scalar)
{
    Vector<Real, dim> result = vector;
    result /= scalar;
    return result;
}

template<typename Real, size_t dim>
bool operator==(const Vector<Real, dim> & left, const Vector<Real, dim> & right)
{
    for (size_t i = 0; i < dim; ++i) {
        if (left[i] != right[i]) {
            return false;
        }
    }
    return true;
}

template<typename Real, size_t dim>
bool operator!=(const Vector<Real, dim> & left, const Vector<Real, dim> & right)
{
    return !(left == right);
}

#endif
