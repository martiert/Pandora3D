#ifndef PANDORALIST_H
#define PANDORALIST_H

#include "PandoraSystem.h"

namespace Pandora
{
    template<class T>
    class List
    {
        public:
            List();
            List(const T& data);
            ~List();

            void insert(const T& data);

        protected:
            T data;
            List *next;
            static size_t size;
    };
}

#endif
