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

#include "../include/PandoraStack.hpp"

namespace Pandora
{
//#############################################################################

    template<class T>
    Stack<T>::Stack(const int n)
    {
        m_index = -1;
        m_size = n;
        m_data = new T[n];
    }

//#############################################################################

    template<class T>
    Stack<T>::~Stack()
    {
        delete[] m_data;
    }

//#############################################################################

    template<class T>
    bool Stack<T>::isEmpty() const
    {
        return m_index == -1;
    }

//#############################################################################

    template<class T>
    bool Stack<T>::isFull() const
    {
        return m_index + 1 == m_size;
    }

//#############################################################################

    template<class T>
    void Stack<T>::push(const T& element)
    {
        if(m_index + 1 < m_size) {
            ++m_index;
            m_data[m_index] = element;
        } else {
            assert(false);
        }
    }

//#############################################################################

    template<class T>
    void Stack<T>::pop(T& element)
    {
        if(m_index > -1) {
            element = m_data[m_index];
            --m_index;
        } else {
            assert(false);
        }
    }

//#############################################################################

    template<class T>
    void Stack<T>::clear()
    {
        m_index = -1;
    }

//#############################################################################

    template<class T>
    bool Stack<T>::getTop(T& element) const
    {
        if(m_index == -1)
            return false;

        element = m_data[m_index];
        return true;
    }

//#############################################################################
}
