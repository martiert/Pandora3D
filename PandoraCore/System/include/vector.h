#ifndef SYSTEM_VECTOR_H
#define SYSTEM_VECTOR_H

#include <cstring>

namespace System
{
    template<typename T>
    class Vector
    {
        public:
            Vector (const size_t& initial_capacity = 20);

            void append (const T& element);

            T& element_at (const size_t& i) const;

            size_t size () const;
            size_t capacity () const;
        private:
            size_t elements_in_vector;
            size_t vector_capacity;

            T* elements;
    };

#define VECTOR_INCLUDE_FILE
#include "vector-impl.h"
#undef VECTOR_INCLUDE_FILE
}
#endif // SYSTEM_VECTOR_H
