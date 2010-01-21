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
#ifndef PANDORASET_H
#define PANDORASET_H

#include <stdlib.h>
#include <assert.h>

namespace Pandora
{
    /** Namespace for the util classes of the engine.
     */
    namespace Utils
    {
        /**
         * A simple Set class. We can append, remove, get the number of elements, 
         * get a raw pointer from the set and remove all the elements in the set.
        */
        template<class T>
        class Set
        {
            public:
                /** 
                 *  Default constructor
                 *  \param
                 *      size - The starting size of the set. Defaults to 6.
                 *  \param
                 *      increment - The number of elements to increase the set
                 *          with when needed, default to 4.
                 */
                Set(const size_t size = 6, const size_t increment = 4);

                /** 
                 *  Destructor 
                 */
                ~Set();

                /** 
                 *  Append an element at the end of the Set 
                 *  \param
                 *      in - The element we are inserting.
                 *  \return
                 *      True if the item is inserted, false if the Set is full
                 *      and we can't increment the size.
                 */
                bool insert(const T& in);

                /** 
                 *  Remove an element from the Set.
                 *  \param
                 *      elem - The element we are removing.
                 *  \return
                 *      False if the item is not present in the set. True otherwise.
                 */
                bool remove(const T& elem);

                /** 
                 *  Get the number of elements in the Set.
                 *  \return
                 *      The number of elements in the Set.
                 */
                size_t getSize() const;

                /** 
                 *  Get pointer to the data.
                 *  \return
                 *      A pointer to the data.
                 */
                T* getPointer();

                /** 
                 *  Remove all the elements in the Set 
                 */
                void removeAll();
            private:
                T *m_data;
                size_t m_elements; //The number of elements in the set
                size_t m_size; //The size of the array
                size_t m_increment; //What to increment the array size with
        };

#include "PandoraSet.inl"

    }
}
#endif
