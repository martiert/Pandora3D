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
#ifndef PANDORAVECTOR_H
#define PANDORAVECTOR_H

#include <stdlib.h>
#include <assert.h>

namespace Pandora
{
    namespace Utils
    {
        /** 
         *  A simple Vector class. Can be compared to the std::vector. 
         */ 
        template<class T>
        class Vector
        {
            public:
                /** 
                 *  Default constructor.
                 *  \param
                 *      size - The starting size of the vector. Defaults to 4.
                 *  \param
                 *      inc - The number of elements to increase the vector by.
                 *          Defaults to 4.
                 */
                Vector(const unsigned int size = 4, const unsigned int inc = 4);

                /** 
                 *  Destructor 
                 */
                ~Vector();

                /** 
                 *  Get a pointer to the data.
                 *  \return
                 *      A pointer to the data.
                 */
                T* c_ptr();

                /** 
                 *  Get a constant pointer to the data.
                 *  \return
                 *      A constant pointer to the data.
                 */
                const T* c_ptr() const;

                /** 
                 *  Get element in vector.
                 *  \param
                 *      i - The index we need the element from.
                 *  \return
                 *      The element from index i.
                 *  \note
                 *      No resizing is done. Error occurs if you try to access
                 *      element outside of the vector.
                 */
                T& operator[](const unsigned int i);

                /** 
                 *  Get constant element in vector.
                 *  \param
                 *      i - The index we need the element from.
                 *  \return
                 *      The element from index i.
                 *  \note
                 *      No resizing is done. Error occurs if you try to access
                 *      element outside of the vector.
                 */
                const T& operator[](const unsigned int i) const;

                /** 
                 *  Append data to the vector.
                 *  \param
                 *      element - The element to append at the end of the vector.
                 *  \note
                 *      Increases the size of the vector if needed.
                 */
                void append(const T& element);

                /** 
                 *  Insert data in the vector.
                 *  \param
                 *      i - The index we're inserting into.
                 *  \param
                 *      element - The element to insert.
                 *  \note
                 *      Increases the size of the vector if needed.
                 */
                void insert(const unsigned int i, const T& element);

                /** 
                 *  Remove an element from the vector.
                 *  \param
                 *      i - The index to remove.
                 *  \return
                 *      The old element.
                 */
                T& remove(const unsigned int i);

                /** 
                 *  Remove all elements from the vector.
                 */
                void removeAll();

                /** 
                 *  Get the number of elements in the vector.
                 *  \return
                 *      The number of elements in the vector.
                 */
                unsigned int getElements() const;

                /** 
                 *  Get the size of the vector.
                 *  \return
                 *      the number of places in the vector.
                 */
                unsigned int getSize() const;

                /** 
                 *  Get the number of elements to increment by.
                 *  \return
                 *      The number of elements to increase the vector by.
                 */
                unsigned int getIncrement() const;

                /** 
                 *  Set the size of the vector
                 *  \param
                 *      size - The new number of elements in the vector.
                 */
                void setSize(const unsigned int size);

                /** 
                 *  Set the number of elements to increment with.
                 *  \param
                 *      inc - The new number of element to increment the vector
                 *          by.
                 */
                void setIncrement(const unsigned int inc);
            private:
                T *m_data;
                unsigned int m_elements;
                unsigned int m_size;
                unsigned int m_increment;
        };

#include "PanoraVector.inl"

    }
}
#endif
