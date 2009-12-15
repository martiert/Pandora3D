#ifndef PANDORASET_H
#define PANDORASET_H

#include <stdlib.h>
#include <assert.h>

namespace PandoraUtils
{
    //A simple Set class. We can append, remove, get the number of elements, 
    //get a raw pointer from the set and remove all the elements in the set.
    template<class T>
    class Set
    {
        public:
            //Constructor and destructor
            Set(const size_t size = 6, const size_t increment = 4);
            ~Set();

            //Append an element to the end of the array.
            void insert(const T& in);

            //Remove the element given from the set. Returns false if the set
            //doesn't contain the element.
            bool remove(const T& elem);

            //Get the number of elements in the set
            unsigned int getSize() const;

            //Get a pointer to the data
            T* getPointer();

            //Remove all the elements in the set
            void removeAll();
        protected:
            T *m_data;
            size_t m_elements; //The number of elements in the set
            size_t m_size; //The size of the array
            size_t m_increment; //What to increment the array size with
    };

    //-------------------------------------------------------------------------
    // Constructor
    //-------------------------------------------------------------------------
    template<class T>
    Set<T>::Set(size_t size, size_t increment)
    {
        m_data = new T[size];
        m_size = size;
        m_increment = increment;
        m_elements = 0;
    }

    //-------------------------------------------------------------------------
    // Destructor
    //-------------------------------------------------------------------------
    template<class T>
    Set<T>::~Set()
    {
        delete[] m_data;
    }

    //-------------------------------------------------------------------------
    // Appends an element to the first free place in the set. If no free spots,
    // we have to resize the array.
    //-------------------------------------------------------------------------
    template<class T>
    void Set<T>::insert(const T& in)
    {
        //If we have room for the element, no rearranging have to be done.
        if(m_elements < m_size) {
            m_data[m_elements++] = in;
        } else {
            //Checks if we are allowed to resize the set.
            assert(m_increment != 0 && 
                    "Not allowed to resize this set, but resize needed");

            //Resize the array
            T *tmp = new T[m_size + m_increment];

            //Copy the data to the new array
            for(int i = 0; i < m_size; ++i)
                tmp[i] = m_data[i];

            //Delete the old array, copy the new large array to the data 
            //pointer and set the new size to the old size + the 
            //incrementation.
            delete[] m_data;
            m_data = tmp;
            m_size += m_increment;

            //Set the data in the set
            m_data[m_elements++] = in;
        }
    }

    //-------------------------------------------------------------------------
    // Get the number of elements in the set
    //-------------------------------------------------------------------------
    template<class T>
    unsigned int Set<T>::getSize() const
    {
        return m_elements;
    }
 
    // Get the array itself
    //-------------------------------------------------------------------------
    template<class T>
    T* Set<T>::getPointer()
    {
        return m_data;
    }

    //-------------------------------------------------------------------------
    // Remove an element from the set. Returns true if the element is removed,
    // returns false otherwise
    //-------------------------------------------------------------------------
    template<class T>
    bool Set<T>::remove(const T& elem)
    {
        size_t i = 0;

        //Search for the element.
        while(i < m_elements && m_data[i] != elem) {
            ++i;
        }

        //The element doesn't exist.
        if(i == m_elements)
            return false;

        //Shuffle all the remaining data
        for(;i < m_size - 1; ++i)
            m_data[i] = m_data[i + 1];
        m_data[i] = NULL;

        return true;
    }

    //-------------------------------------------------------------------------
    // Removes all the data from the set
    //-------------------------------------------------------------------------
    template<class T>
    void Set<T>::removeAll()
    {
        m_elements = 0;
        delete[] m_data;
        m_data = new T[m_size];
    }
}

#endif
