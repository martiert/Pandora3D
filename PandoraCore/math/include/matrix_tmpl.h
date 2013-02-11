#ifndef INCLUDED_FROM_MATRIX_H
#error "matrix_tmpl.h can only be included from matrix.h"
#else

template<typename Real, size_t dim>
static Matrix<Real, dim-1> create_submatrix(const Matrix<Real, dim> & matrix, const size_t & row, const size_t & col);

template<typename Real, size_t dim>
Real calculate_element(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right,
        const size_t & i, const size_t & j);

template<typename Real, size_t dim>
Matrix<Real, dim>::Matrix()
    : data {{0,}}
{
    for (size_t i = 0; i < dim; ++i) {
        data[i*dim+i] = 1;
    }
}

template<typename Real, size_t dim>
Matrix<Real, dim>::Matrix(const std::initializer_list<Real> & elements)
{
    std::copy(elements.begin(), elements.end(), data.begin());
}

template<typename Real, size_t dim>
Matrix<Real, dim>::Matrix(const Real array[dim*dim])
{
    std::copy(array, array + dim*dim, data.begin());
}

template<typename Real, size_t dim>
Real & Matrix<Real, dim>::operator[](const size_t & i)
{
    assert(i < dim*dim && "Index operator out of range");
    return data[i];
}

template<typename Real, size_t dim>
Real Matrix<Real, dim>::operator[](const size_t & i) const
{
    assert(i < dim*dim && "Index operator out of range");
    return data[i];
}

template<typename Real, size_t dim>
Real & Matrix<Real, dim>::operator()(const size_t & i, const size_t & j)
{
    assert(i < dim && j < dim && "Index operator out of range");
    return data[i*dim + j];
}

template<typename Real, size_t dim>
Real Matrix<Real, dim>::operator()(const size_t & i, const size_t & j) const
{
    assert(i < dim && j < dim && "Index operator out of range");
    return data[i*dim + j];
}

template<typename Real>
Real matrix_determinant(const Matrix<Real, 2> & matrix)
{
    return matrix(0,0) * matrix(1,1) - matrix(0,1) * matrix(1,0);
}

template<typename Real, size_t dim>
Real matrix_determinant(const Matrix<Real, dim> & matrix)
{
    Real result = 0;
    int sign = 1;
    for (size_t i = 0; i < dim; ++i) {
        result += sign * matrix(0, i) * matrix_determinant(create_submatrix(matrix, 0, i));
        sign *= -1;
    }

    return result;
}

template<typename Real, size_t dim>
Matrix<Real, dim> matrix_transpose(const Matrix<Real, dim> & matrix)
{
    Matrix<Real, dim> result;
    for (size_t i = 0; i < dim; ++i) {
        for (size_t j = 0; j < dim; ++j) {
            result(i,j) = matrix(j,i);
        }
    }
    return result;
}

template<typename Real, size_t dim>
Real matrix_trace(const Matrix<Real, dim> & matrix)
{
    Real result = 0;
    for (size_t i = 0; i < dim; ++i) {
        result += matrix(i,i);
    }
    return result;
}

template<typename Real, size_t dim>
Real sub_determinant(const Matrix<Real, dim> & matrix, const size_t & row, const size_t & col)
{
    auto submatrix = create_submatrix(matrix, row, col);
    return matrix_determinant(submatrix);
}

template<typename Real, size_t dim>
Matrix<Real, dim> matrix_adjugate(const Matrix<Real, dim> & matrix)
{
    Matrix<Real, dim> adjugate;
    for (size_t i = 0; i < dim; i++) {
        for (size_t j = 0; j < dim; j++) {
            adjugate(i,j) = pow(-1,i+j) * sub_determinant(matrix, i, j);
        }
    }

    return matrix_transpose(adjugate);
}

template<typename Real, size_t dim>
Matrix<Real, dim> matrix_inverse(const Matrix<Real, dim> & matrix)
{
    return matrix_adjugate(matrix) / matrix_determinant(matrix);
}

template<typename Real, size_t dim>
Matrix<Real, dim> & operator+=(Matrix<Real, dim> & to, const Matrix<Real, dim> & from)
{
    for (size_t i = 0; i < dim*dim; ++i) {
        to[i] += from[i];
    }
    return to;
}

template<typename Real, size_t dim>
Matrix<Real, dim> & operator-=(Matrix<Real, dim> & to, const Matrix<Real, dim> & from)
{
    for (size_t i = 0; i < dim*dim; ++i) {
        to[i] -= from[i];
    }
    return to;
}

template<typename Real, size_t dim>
Matrix<Real, dim> & operator*=(Matrix<Real, dim> & matrix, const Real & scalar)
{
    for (size_t i = 0; i < dim*dim; ++i) {
        matrix[i] *= scalar;
    }
    return matrix;
}

template<typename Real, size_t dim>
Matrix<Real, dim> & operator/=(Matrix<Real, dim> & matrix, const Real & scalar)
{
    matrix *= (1./scalar);
    return matrix;
}

template<typename Real, size_t dim>
Matrix<Real, dim> operator+(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right)
{
    auto result (left);
    result += right;
    return result;
}

template<typename Real, size_t dim>
Matrix<Real, dim> operator-(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right)
{
    auto result (left);
    result -= right;
    return result;
}

template<typename Real, size_t dim>
Matrix<Real, dim> operator*(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right)
{
    Matrix<Real, dim> result;
    for (size_t i = 0; i < dim; ++i) {
        for (size_t j = 0; j < dim; ++j) {
            result(i,j) = calculate_element(left, right, i, j);
        }
    }
    return result;
}

template<typename Real, size_t dim>
Vector<Real, dim> operator*(const Matrix<Real, dim> & matrix, const Vector<Real, dim> & vector)
{
    Vector<Real, dim> result;
    for (size_t i = 0; i < dim; ++i) {
        for (size_t j = 0; j < dim; ++j) {
            result[i] += matrix(i,j) * vector[j];
        }
    }
    return result;
}

template<typename Real, size_t dim>
Vector<Real, dim> operator*(const Vector<Real, dim> & vector, const Matrix<Real, dim> & matrix)
{
    return matrix_transpose(matrix) * vector;
}

template<typename Real, size_t dim>
Matrix<Real, dim> operator*(const Matrix<Real, dim> & matrix, const Real & scalar)
{
    auto result (matrix);
    result *= scalar;
    return result;
}

template<typename Real, size_t dim>
Matrix<Real, dim> operator*(const Real & scalar, const Matrix<Real, dim> & matrix)
{
    return matrix * scalar;
}

template<typename Real, size_t dim>
Matrix<Real, dim> operator/(const Matrix<Real, dim> & matrix, const Real & scalar)
{
    auto result (matrix);
    result /= scalar;
    return result;
}

template<typename Real, size_t dim>
bool operator==(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right)
{
    for (size_t i = 0; i < dim*dim; ++i) {
        if (left[i] != right[i]) {
            return false;
        }
    }
    return true;
}

template<typename Real, size_t dim>
bool operator!=(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right)
{
    return !(left == right);
}

template<typename Real, size_t dim>
Real calculate_element(const Matrix<Real, dim> & left, const Matrix<Real, dim> & right,
        const size_t& i, const size_t& j)
{
    Real element = 0;
    for (size_t k = 0; k < dim; ++k) {
        element += left(i,k) * right(k,j);
    }
    return element;
}

template<typename Real, size_t dim>
static Matrix<Real, dim-1> create_submatrix(const Matrix<Real, dim> & matrix, const size_t & row, const size_t & col)
{
    Matrix<Real, dim-1> result;
    size_t index = 0;

    for (size_t i = 0; i < dim; ++i) {
        for (size_t j = 0; j < dim; ++j) {
            if (i != row && j != col) {
                result[index++] = matrix(i, j);
            }
        }
    }

    return result;
}

#endif
