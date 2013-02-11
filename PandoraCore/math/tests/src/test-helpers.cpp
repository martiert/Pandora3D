#include "test-helpers.h"

namespace
{

bool called = false;
double scale = 10000000.0;

}

double * create_double_array_of_size(const size_t & size)
{
    if (!called) {
        srand(time(NULL));
    }
    called = true;
    double * array = new double[size];
    for (size_t i = 0; i < size; ++i) {
        array[i] = rand() / scale;
    }

    return array;
}

double create_random_scalar()
{
    if (!called) {
        srand(time(NULL));
    }
    called = true;
    return rand() / scale;
}
