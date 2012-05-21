#ifndef SYSTEM_STACK_H
#define SYSTEM_STACK_H

#include <stdexcept>

namespace System
{
    template<typename T>
    class Stack
    {
        public:
            Stack (const size_t& size = 8);

            ~Stack ();

            void push (const T& element);

            T& pop ();

            T& peak () const;

            size_t size () const;

            size_t max_size () const;
        protected:
            size_t elements_on_stack;
            const size_t max_elements_on_stack;

            T* elements;
    };

#define STACK_INCLUDE_FILE
#include "stack-impl.h"
#undef STACK_INCLUDE_FILE
}

#endif // SYSTEM_STACK_H
