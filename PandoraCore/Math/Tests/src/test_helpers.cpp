#include "test_helpers.h"

double* create_double_array_of_size (const size_t& size)
{
    double * array = new double[size];
    srand (time (NULL));
    for (size_t i = 0; i < size; ++i)
        array[i] = rand () / 100.0;

    return array;
}

Math::Matrix4d create_random_4d_matrix ()
{
    auto array = create_double_array_of_size (16);
    Math::Matrix4d matrix (array);

    delete [] array;
    return matrix;
}

Math::Matrix3d create_random_3d_matrix ()
{
    auto array = create_double_array_of_size (9);
    Math::Matrix3d matrix (array);

    delete [] array;
    return matrix;
}
