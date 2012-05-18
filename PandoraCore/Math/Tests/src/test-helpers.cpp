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
