/*
 * ----------------------------------------------------------------------------
 * This source file is part of Pandora3D. For information, see 
 * http://Pandora3D.sourceforge.net.
 *
 * Copyright (c) 2009 Martin Ertsås
 *
 * This program is free software. You can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the license, or any later version.
 *
 * This program is distributed in hope that it will be useful, but WITHOUT ANY 
 * WARRANTY.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston MA 02111-1307, USA, or go to:
 *
 * http://www.gnu.org/licenses/#GPL
 * ----------------------------------------------------------------------------
 */

#ifndef _SET_HPP_
#define _SET_HPP_

#include "PandoraSystem.hpp"

namespace Pandora
{
    //A simple set. Starts with eight places and increments the set with
    //eight if needed.
    template<class T>
    class Set
    {
        public:
            //Constructor. Sets the size of the set to size, and increment to
            //the variable increment.
            Set(int size = 8, int increment = 8);

            //Destructor.
            ~Set();

            //Add an element to the set. Returns false if the element is 
            //already in the set. If the set is full, we increment the size of
            //the set.
            bool add(const T& element);

            //Checks if the set contains a specific element.
            bool exists(const T& element);

            //Removes an element from the set. Returns true if the element is
            //removed and false if the set don't contain the element.
            bool remove(const T& element);

            //Clears the whole set.
            void clear();

            //Clears the set, and makes the set maxsize big and changes the
            //int we increment the set with to increment.
            void clear(int maxsize, int increment);

            //Get the number of elements in the set.
            int size();

            //Get the array of elements.
            T* getElements();
            const T* getElements() const;

            //Get element number idx.
            T& operator[](const int idx);
            const T& operator[](const int idx) const;

            //Changes the number we increment the set with. Negative numbers
            //leaves the variable as it is.
            void changeInc(const int increment);
        protected:
            T* m_data;
            int m_size;
            int m_setsize;
            int m_increment;

            //Increments the set
            void incrementSet();
    };

//#############################################################################
    template<class T>
    Set<T>::Set(int size, int increment)
    {
        if(size < 1)
            size = 1;
        if(increment < 1)
            increment = 1;

        m_setsize = size;
        m_increment = increment;
        m_size = 0;
        m_data = new T[m_setsize];
    }

//#############################################################################

    template<class T>
    Set<T>::~Set()
    {
        delete[] m_data;
    }

//#############################################################################

    template<class T>
    bool Set<T>::add(const T& element)
    {
        for(int i = 0; i < m_size; i++)
            if(m_data[i] == element)
                return false;

        if(m_size == m_setsize)
            incrementSet();

        m_data[m_size++] = element;
        return true;
    }

//#############################################################################

    template<class T>
    bool Set<T>::exists(const T& element)
    {
        for(int i = 0; i < m_size; i++)
            if(m_data[i] == element)
                return true;
        return false;
    }

//#############################################################################

    template<class T>
    bool Set<T>::remove(const T& element)
    {
        if(m_size == 0)
            return false;

        bool found = false;
        for(int i = 0; i < m_size; i++) {
            if(found || m_data[i] == element) {
                found = true;
                if(i + 1 == m_setsize) {
                    m_data[i] = NULL;
                } else {
                    m_data[i] = m_data[i+1];
                }
            }
        }

        if(found)
            --m_size;

        return found;
    }

//#############################################################################

    template<class T>
    void Set<T>::clear()
    {
        delete[] m_data;
        m_data = new T[m_setsize];
        m_size = 0;
    }

//#############################################################################

    template<class T>
    void Set<T>::clear(int maxsize, int increment)
    {
        delete[] m_data;
        m_data = maxsize;
        m_setsize = maxsize;
        m_increment = increment;
        m_size = 0;
    }

//#############################################################################

    template<class T>
    int Set<T>::size()
    {
        return m_size;
    }

//#############################################################################

    template<class T>
    T* Set<T>::getElements()
    {
        return &m_data[0];
    }

//#############################################################################

    template<class T>
    const T* Set<T>::getElements() const
    {
        return &m_data[0];
    }

//#############################################################################

    template<class T>
    T& Set<T>::operator[](const int idx)
    {
        assert(idx >= 0 && idx < m_size);

        if(idx < 0 && idx >= m_size)
            return NULL;

        return m_data[idx];
    }

//#############################################################################

    template<class T>
    const T& Set<T>::operator[](const int idx) const
    {
        assert(idx >= 0 && idx < idx);

        if(idx < 0 && idx >= m_size)
            return NULL;

        return m_data[idx];
    }

//#############################################################################

    template<class T>
    void Set<T>::changeInc(const int increment)
    {
        if(increment <= 0)
            return;

        m_increment = increment;
    }

//#############################################################################

    template<class T>
    void Set<T>::incrementSet()
    {
        m_setsize += m_increment;
        T* tmp = new T[m_setsize];

        for(int i = 0; i < m_size; i++)
            tmp[i] = m_data[i];

        delete[] m_data;
        m_data = tmp;
    }

//#############################################################################
}
#endif
