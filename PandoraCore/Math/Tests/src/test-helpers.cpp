#include "test-helpers.h"

bool called = false;

double* create_double_array_of_size (const size_t& size)
{
    if (!called)
        srand (time (NULL));
    called = true;
    double * array = new double[size];
    for (size_t i = 0; i < size; ++i)
        array[i] = rand () / 100.0;

    return array;
}

const Math::Vec2d create_random_vector2d ()
{
    auto array = create_double_array_of_size (2);
    Math::Vec2d vector (array);

    delete [] array;
    return vector;
}

const Math::Vec3d create_random_vector3d ()
{
    auto array = create_double_array_of_size (3);
    Math::Vec3d vector (array);

    delete [] array;
    return vector;
}

const Math::Vec4d create_random_vector4d ()
{
    auto array = create_double_array_of_size (4);
    Math::Vec4d vector (array);

    delete [] array;
    return vector;
}

const Math::Matrix2d create_random_matrix2d ()
{
    auto array = create_double_array_of_size (4);
    Math::Matrix2d matrix (array);

    delete [] array;
    return matrix;
}

const Math::Matrix3d create_random_matrix3d ()
{
    auto array = create_double_array_of_size (9);
    Math::Matrix3d matrix (array);

    delete [] array;
    return matrix;
}

const Math::Matrix4d create_random_matrix4d ()
{
    auto array = create_double_array_of_size (16);
    Math::Matrix4d matrix (array);

    delete [] array;
    return matrix;
}
