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

#include "../include/PandoraVector.hpp"

namespace Pandora
{
//#############################################################################

    template<class T>
    Vector<T>::Vector(int size, int increment)
    {
        if(size < 1)
            size = 1;
        if(increment < 1)
            increment = 1;

        m_maxSize = size;
        m_increment = increment;
        m_size = 0;
        m_array = new T[m_maxSize];
    }

//#############################################################################

    template<class T>
    Vector<T>::Vector(const Vector<T>& vec)
    {
        delete[] m_array;
        *this = vec;
    }

//#############################################################################

    template<class T>
    Vector<T>::~Vector()
    {
        delete[] m_array;
    }

//#############################################################################

    template<class T>
    int Vector<T>::size() const
    {
        return m_size;
    }

//#############################################################################

    template<class T>
    T* Vector<T>::getArray()
    {
        return m_array;
    }

//#############################################################################

    template<class T>
    const T* Vector<T>::getArray() const
    {
        return m_array;
    }

//#############################################################################

    template<class T>
    T& Vector<T>::operator[](const int idx)
    {
        assert(idx < m_maxSize);

        if(idx >= m_maxSize)
            return NULL;

        return m_array[idx];
    }

//#############################################################################

    template<class T>
    const T& Vector<T>::operator[](const int idx) const
    {
        assert(idx < m_maxSize);

        if(idx >= m_maxSize)
            return NULL;

        return m_array[idx];
    }

//#############################################################################

    template<class T>
    Vector<T>& Vector<T>::operator=(const Vector<T>& vec)
    {
        m_size = vec.m_size;
        m_maxSize = vec.m_maxSize;
        m_increment = vec.m_increment;

        delete[] m_array;

        if(m_maxSize > 0) {
            m_array = new T[m_maxSize];

            for(int i = 0; i < m_maxSize; ++i)
                m_array[i] = vec.m_array[i];
        } else {
            m_array = 0;
        }

        return *this;
    }

//#############################################################################

    template<class T>
    void Vector<T>::append(const T& element)
    {
        //Have to increment the size of the array
        if(m_size == m_maxSize) {
            setMaxSize(m_maxSize + m_increment, true);
        } 

        m_array[m_size] = element;
        ++m_size;
    }

//#############################################################################

    template<class T>
    void Vector<T>::setElement(const int idx, const T& element)
    {
        assert(idx >= 0);

        if(idx < 0)
            return;

        if(idx >= m_maxSize) {
            int inc = (int) (0.5f + (idx+1-m_maxSize)/(float) m_increment);
            ++inc;
            setMaxSize(m_maxSize + inc*m_increment, true);
        }

        if(!m_array[idx])
            ++m_size;

        m_array[idx] = element;
    }

//#############################################################################

    template<class T>
    void Vector<T>::remove(const int idx)
    {
        assert(idx < m_maxSize && idx >= 0);

        if(idx >= m_maxSize || idx < 0)
            return;
        
        for(int i = idx; i < m_maxSize - 1; ++i)
            m_array[i] = m_array[i + 1];

        m_array[m_maxSize - 1] = T();
        --m_size;
    }

//#############################################################################

    template<class T>
    void Vector<T>::removeAll()
    {
        for(int i = 0; i < m_maxSize; ++i)
            m_array[i] = T();
        m_size = 0;
    }

//#############################################################################

    template<class T>
    void Vector<T>::setMaxSize(const int newMax, const bool copy)
    {
        if(newMax != m_maxSize) {
            T* tmp = new T[newMax];

            if(copy && newMax > m_maxSize) {
                for(int i = 0; i < m_maxSize; i++)
                    tmp[i] = m_array[i];
            } else {
                m_size = 0;
            }

            delete[] m_array;

            m_array = tmp;
            m_maxSize = newMax;
        }
    }

//#############################################################################

    template<class T>
    const int Vector<T>::getMaxSize() const
    {
        return m_maxSize;
    }

//#############################################################################

    template<class T>
    void Vector<T>::setGrow(const int growBy)
    {
        if(growBy < 1)
            return;

        m_increment = growBy;
    }

//#############################################################################

    template<class T>
    const int Vector<T>::getGrow() const
    {
        return m_increment;
    }

//#############################################################################
}
