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
            //Default constructor. Takes two arguments, which defaults to one
            //if they are not passed. The arguments are the size of the array
            //we are to make at startup, and the number of elements to extend
            //the array with if needed
            Vector(int size = 1, int increment = 1);

            //Copy constructor. Copies the vector
            Vector(const Vector& vec);

            //Destructor. Destroys the array (freeing it from memory).
            ~Vector();

            //Returns the size of the vector, that is the number of elements.
            int size() const;

            //Returns a pointer to the array.
            T* getArray();

            //Returns a constant pointer to the array.
            const T* getArray() const;

            //Returns a reference to element idx in the array for read/write
            //operations.
            T& operator[](const int idx);

            //Returns a constant reference to element idx in the array for
            //read/write operations.
            const T& operator[](const int idx) const;

            //Copy operator. Copies the vector.
            Vector& operator=(const Vector& vec);

            //Appends an element to the end of the array, allocates a larger
            //array if necessary.
            void append(const T& element);

            //Sets element number idx to the element, allocates a larger array
            //if necessary.
            void setElement(const int idx, const T& element);

            //Removes element number idx from the array.
            void remove(const int idx);

            //Sets all the elements in the array to a default constructed 
            //element
            void removeAll();

            //Sets the new max size. The copy boolean tells us if we should
            //copy the old elements to the new array if the new Max is larger
            //than the old one.
            void setMaxSize(const int newMax, const bool copy);

            //Returns the max size of this array.
            const int getMaxSize() const;

            //Changes the number of elements to grow by if needed.
            void setGrow(int growBy);

            //Get the number of elements we increment the array with when needed.
            const int getGrow() const;
        protected:
            T* m_array;
            int m_size;
            int m_maxSize;
            int m_increment;
    };
}
#endif
