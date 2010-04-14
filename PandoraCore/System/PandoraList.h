/*
--------------------------------------------------------------------------------
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
--------------------------------------------------------------------------------
*/
#ifndef PANDORALIST_H
#define PANDORALIST_H

#include <stdlib.h>

namespace Pandora
{
    namespace Utils
    {
        namespace {
        template<class T>
            struct Node
            {
                Node *next;
                T data;
            };
        } //Anon namespace

        /** 
         *  A List class. Very minimalistic.
         */
        template<class T>
        class List
        {
            public:
                /** 
                 *  Default constructor
                 *  \param
                 *      data - Optional argument. If present it's the root
                 *      node of the List.
                 */
                List(const T& data = NULL);

                /** 
                 *  Destructor 
                 */
                ~List();

                /** 
                 *  Inserts an item into the List.
                 *  \param
                 *      data - The data to be inserted.
                 */
                void insert(const T& data);

                /** 
                 *  Removes an item from the List.
                 *  \param
                 *      data - The data to be removed.
                 *  \return
                 *      true if the item is successfully removed. False if
                 *      the item is not in the List.
                 */
                bool remove(const T& data);

                /** 
                 *  Checks if an item exists in the List
                 *  \param
                 *      data - The element we are looking for.
                 *  \return
                 *      true if the item is present, false otherwise.
                 */
                bool exists(const T& data);

                /** 
                 *  Removes all the data in the List.
                 */
                void removeAll();

                /**
                 *  Get the length of the list
                 */
                unsigned int length();
            protected:
                Node<T> *m_root;
                unsigned int m_size;
        };

#include "PandoraList.inl"

    }
}
#endif
