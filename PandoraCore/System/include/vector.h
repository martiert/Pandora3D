#ifndef SYSTEM_VECTOR_H
#define SYSTEM_VECTOR_H

#include <stdexcept>
#include <algorithm>

namespace System
{
    template<typename T>
    class Vector
    {
        public:
            Vector (const size_t& initial_capacity = 20, const size_t& increment_by = 20);

            ~Vector ();

            void append (const T& element);

            T& element_at (const size_t& i) const;

            T remove_at (const size_t& i);

            size_t size () const;
            size_t capacity () const;
        private:
            size_t elements_in_vector;
            size_t vector_capacity;
            size_t vector_increment;

            T* elements;

            void resize ();
            void rearrange (size_t from);
    };

#define VECTOR_INCLUDE_FILE
#include "vector-impl.h"
#undef VECTOR_INCLUDE_FILE
}
#endif // SYSTEM_VECTOR_H
