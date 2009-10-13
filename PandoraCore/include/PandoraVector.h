#ifndef PANDORAVECTOR_H
#define PANDORAVECTOR_H

#include "PandoraSystem.h"

namespace Pandora
{
    template<class T>
    class Vector
    {
        public:
            Vector(const size_t size = 4, const size_t inc = 4);
            ~Vector();

            //Get the number of elements in the vector
            size_t getElements() const;

            //Get a pointer to the data
            T* c_ptr();
            const T* c_ptr() const;

            //Get element number i from the data. No resizing done
            T& operator[](const size_t i);
            const T& operator[](const size_t i) const;

            //Append data to the vector
            void append(const T& element);
            void insert(const size_t i, const T& element);

            //Remove elements
            void remove(const size_t i);
            void removeAll();
        protected:
            T *m_data;
            size_t m_elements;
            size_t m_size;
            size_t m_increment;
    };

    //-------------------------------------------------------------------------
    // Constructor
    //-------------------------------------------------------------------------
    template<class T>
    Vector<T>::Vector(const size_t size, const size_t inc)
    {
        m_size = size;
        m_increment = inc;
        m_elements = 0;
        m_data = new T[m_size];
    }

    //-------------------------------------------------------------------------
    // Destructor
    //-------------------------------------------------------------------------
    template<class T>
    Vector<T>::~Vector()
    {
        delete[] m_data;
    }

    //-------------------------------------------------------------------------
    // Get the number of elements in the set
    //-------------------------------------------------------------------------
    template<class T>
    size_t Vector<T>::getElements() const
    {
        return m_elements;
    }

    //-------------------------------------------------------------------------
    // Get a c-pointer
    //-------------------------------------------------------------------------
    template<class T>
    T* Vector<T>::c_ptr()
    {
        return m_data[0];
    }

    //-------------------------------------------------------------------------
    // Get a constant c-pointer
    //-------------------------------------------------------------------------
    template<class T>
    const T* Vector<T>::c_ptr() const
    {
        return m_data[0];
    }

    //-------------------------------------------------------------------------
    // Access element number i
    //-------------------------------------------------------------------------
    template<class T>
    T& Vector<T>::operator[](const size_t i)
    {
        assert(i < m_size && "Index out of bounds");
        return m_data[i];
    }

    //-------------------------------------------------------------------------
    // Access constant element number i
    //-------------------------------------------------------------------------
    template<class T>
    const T& Vector<T>::operator[](const size_t i) const
    {
        assert(i < m_size && "Index out of bounds");
        return m_data[i];
    }
}

#endif
