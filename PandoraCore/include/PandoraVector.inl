/*
   -------------------------------------------------------------------------------
   This source file is part of Pandora3D.

   This program is free software: you can redistribute it and/or modify it under 
   the terms of the GNU General Public License as published by the Free Software 
   Foundation. Either version 2 of the License, or (at your option) any later 
   version.

   This program comes without any warranty whatsoever, but under the hope that it
   will be useful. See the GNU General Public License for more information.

   You should have received a copy of the GNU Lesser General Public License along 
   with this program; if not, write to the Free Software Foundation, Inc., 59 
   Temple Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
-------------------------------------------------------------------------------
*/

//-----------------------------------------------------------------------------
// This file contains the implementation of the Vector class from Pandora3D.
// See PandoraVector.h for more detailed explanation.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Constructor
//-----------------------------------------------------------------------------
template<class T>
Vector<T>::Vector(const size_t size, const size_t inc)
{
    m_size = size;
    m_increment = inc;
    m_elements = 0;
    m_data = new T[m_size];
}

//-----------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------
template<class T>
Vector<T>::~Vector()
{
    delete[] m_data;
}

//-----------------------------------------------------------------------------
// Get a c-pointer
//-----------------------------------------------------------------------------
template<class T>
T* Vector<T>::c_ptr()
{
    return m_data[0];
}

//-----------------------------------------------------------------------------
// Get a constant c-pointer
//-----------------------------------------------------------------------------
template<class T>
const T* Vector<T>::c_ptr() const
{
    return m_data[0];
}

//-----------------------------------------------------------------------------
// Access element number i
//-----------------------------------------------------------------------------
template<class T>
T& Vector<T>::operator[](const size_t i)
{
    assert(i < m_size && "Index out of bounds");

    return m_data[i];
}

//-----------------------------------------------------------------------------
// Access constant element number i.
//-----------------------------------------------------------------------------
template<class T>
const T& Vector<T>::operator[](const size_t i) const
{
    assert(i < m_size && "Index out of bounds");
    return m_data[i];
}

//-----------------------------------------------------------------------------
// Set this element to the first free element in the vector.
//
// If we have free places, we add to the first free place we find. If we 
// have a full array, we make a new array which is size + increment large. 
// then we move all the data to the new vector, and add the new element to 
// the end of the vector.
//-----------------------------------------------------------------------------
template<class T>
void Vector<T>::append(const T& element)
{
    if(m_elements < m_size) {
        m_data[m_elements++] = m_elements;
    } else {
        assert(m_increment != 0 && "Can't increment the vector");

        T *tmp = new T[m_size + m_increment];

        //Move data to the temporary array
        for(size_t i = 0; i < m_size; ++i) {
            tmp[i] = m_data[i];
        }

        delete[] m_data;

        m_data = tmp;
        m_data[m_elements++] = element;
        m_size += m_increment;
    }
}

//-----------------------------------------------------------------------------
// Inserts the element into the given place. If the place is unused, or we
// are accessing an element outside of the data, we increment the unmber of
// elements we have.
//
// If we have to resize the array, we do that by first finding out how many
// more elements we need, and then copying the data over to a new array.
//
// At the end, we set the given place to be the element we sent in.
//-----------------------------------------------------------------------------
template<class T>
void Vector<T>::insert(const size_t i, const T& element)
{
    if(i > m_size || m_data[i])
        ++m_elements;

    if(i > m_size) {
        size_t times = i - m_size;
        times = (int) (((float)times / m_increment) + 0.5f);
        T *tmp = new T[m_size + m_increment*times];

        for(size_t j = 0; j < m_size; ++j) {
            tmp[j] = m_data[j];
        }

        delete[] m_data;
        m_data = tmp;
        m_size += m_increment * times;
    }

    m_data[i] = element;
}

//-----------------------------------------------------------------------------
// Remove the element in the selected place, and return it.
//-----------------------------------------------------------------------------
template<class T>
T& Vector<T>::remove(const size_t i)
{
    assert(i < m_size && i >= 0 && "Index out of bounds");

    T tmp = m_data[i];
    for(size_t j = i; j < m_elements; ++j) {
        m_data[j] = m_data[j + 1];
    }

    m_data[m_elements--] = T();

    return tmp;
}

//-----------------------------------------------------------------------------
// Remove all the data from this vector
//-----------------------------------------------------------------------------
template<class T>
void Vector<T>::removeAll()
{
    for(size_t i = 0; i < m_elements; ++i) {
        m_data[i] = T();
    }
    m_elements = 0;
}

//-----------------------------------------------------------------------------
// Return the number of elements in the vector.
//-----------------------------------------------------------------------------
template<class T>
size_t Vector<T>::getElements() const
{
    return m_elements;
}

//-----------------------------------------------------------------------------
// Return the size of the vector.
//-----------------------------------------------------------------------------
template<class T>
size_t Vector<T>::getSize() const
{
    return m_size;
}

//-----------------------------------------------------------------------------
// Returns the number we are to increase the vector with.
//-----------------------------------------------------------------------------
template<class T>
size_t Vector<T>::getIncrement() const
{
    return m_increment;
}

//-----------------------------------------------------------------------------
// Set new size of the vector.
//-----------------------------------------------------------------------------
template<class T>
void Vector<T>::setSize(const size_t size)
{
    T *tmp = new T[size];

    for(size_t i = 0; i < m_size && i < size; ++i) {
        tmp[i] = m_data[i];
    }

    delete[] m_data;
    m_data = tmp;
    m_size =
        size;

    if(size < m_elements)
        m_elements = size;
}

//-----------------------------------------------------------------------------
// Set new number of element to increase by.
//-----------------------------------------------------------------------------
template<class T>
void Vector<T>::setIncrement(const size_t inc)
{
    m_increment = inc;
}
