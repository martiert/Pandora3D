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

#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include "PandoraSystem.hpp"

namespace Pandora
{
    //This is a dynamical array, a data structure to be used instead of the
    //std::vector. Not to be used as a mathematical vector!
    template<class T>
    class Vector
    {
        public:
            //Default constructor. Makes an array of size one, and tells us to
            //increase the array with one for each time we need to allocate a 
            //larger array.
            Vector();

            //Constructor that takes two arguments, and makes the size of the
            //array be the first argument, and the second tells us what we 
            //should increase the array with each time we need to allocate a
            //larger array.
            Vector(uint size, uint inc);

            //Destructor. Destroys the array (freeing it from memory).
            ~Vector();

            //Returns the size of the vector, that is the number of elements.
            uint size() const;

            //Returns a pointer to the array.
            T* getArray();

            //Returns a constant pointer to the array.
            const T* getArray() const;

            //Returns a reference to element idx in the array for read/write
            //operations.
            T& operator[](const uint idx);

            //Returns a constant reference to element idx in the array for
            //read/write operations.
            const T& operator[](const uint idx) const;

            //Appends an element to the end of the array, allocates a larger
            //array if necessary.
            void append(const T& element);

            //Sets element number idx to the element, allocates a larger array
            //if necessary.
            void setElement(const uint idx, const T& element);

            //Removes element number idx from the array.
            void remove(const uint i);

            //Sets all the elements in the array to a default constructed 
            //element
            void removeAll();

            //Sets the new max quantity. The copy boolean tells us if we should
            //copy the old elements to the new array if the new Max is larger
            //than the old one.
            void setMaxQuantity(uint newMax, bool copy);

            //Returns the max quantity of this array.
            int getMaxQuantity() const;

            //Changes the number of elements to grow by if needed.
            void setGrow(uint growBy);

            //Get the number of elements we increment the array with when needed.
            uint getGrow() const;
        protected:
            T* m_array;
            uint m_size;
            uint m_maxSize;
            uint m_increase;
    };
}
#endif
