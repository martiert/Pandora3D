#ifndef PANDORAVECTOR_H
#define PANDORAVECTOR_H

#include "PandoraSystem.h"

namespace Pandora
{
    //A simple vector class.
    template<class T>
    class Vector
    {
        public:
            Vector(const size_t size = 1, const size_t inc = 1);
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

            //Remove elements, do not delete.
            T& remove(const size_t i);
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
    // Access constant element number i.
    //-------------------------------------------------------------------------
    template<class T>
    const T& Vector<T>::operator[](const size_t i) const
    {
        assert(i < m_size && "Index out of bounds");
        return m_data[i];
    }

    //-------------------------------------------------------------------------
    // Set this element to the first free element in the vector.
    //
    // If we have free places, we add to the first free place we find. If we 
    // have a full array, we make a new array which is size + increment large. 
    // then we move all the data to the new vector, and add the new element to 
    // the end of the vector.
    //-------------------------------------------------------------------------
    template<class T>
    void Vector<T>::append(const T& element)
    {
        if(m_elements < m_size && !m_data[m_elements]) {
            m_data[m_elements++] = m_elements;
        } else {
            assert(m_increment != 0 && "Can't increment the vector");

            T *tmp = new T[m_size + m_increment];

            //Move data to the temporary array
            for(int i = 0; i < m_size; ++i) {
                tmp[i] = m_data[i];
            }

            delete[] m_data;

            m_data = tmp;
            m_data[m_elements++] = element;
            m_size += m_increment;
        }
    }

    //-------------------------------------------------------------------------
    // Inserts the element into the given place. If the place is unused, or we
    // are accessing an element outside of the data, we increment the unmber of
    // elements we have.
    //
    // If we have to resize the array, we do that by first finding out how many
    // more elements we need, and then copying the data over to a new array.
    //
    // At the end, we set the given place to be the element we sent in.
    //-------------------------------------------------------------------------
    template<class T>
    void Vector<T>::insert(const size_t i, const T& element)
    {
        if(i > m_size || m_data[i])
            ++m_elements;
        
        if(i > m_size) {
            size_t times = i - m_size;
            times = (int) (((float)times / m_increment) + 0.5f);
            T *tmp = new T[m_size + m_increment*times];

            for(int j = 0; j < m_size; ++j) {
                tmp[j] = m_data[j];
            }

            delete[] m_data;
            m_data = tmp;
            m_size += m_increment * times;
        }

        m_data[i] = element;
    }

    //-------------------------------------------------------------------------
    // Remove the element in the selected place, and return it.
    //-------------------------------------------------------------------------
    template<class T>
    T& Vector<T>::remove(const size_t i)
    {
        assert(i < m_size && "Index out of bounds");

        T tmp = m_data[i];
        m_data[i] = NULL;
        return tmp;
    }

    //-------------------------------------------------------------------------
    // Remove all the data from this vector
    //-------------------------------------------------------------------------
    template<class T>
    void Vector<T>::removeAll()
    {
        for(int i = 0; i < m_size; ++i) {
            m_data[i] = NULL;
        }
    }
}

#endif
