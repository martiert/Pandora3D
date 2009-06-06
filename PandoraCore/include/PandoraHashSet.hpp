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

#ifndef _HASHSET_HPP_
#define _HASHSET_HPP_

#include "PandoraSystem.hpp"

namespace Pandora
{
    template<class KEY>
    class HashSet
    {
        public:
            //Constructor. Makes a table of size size.
            HashSet(const int& tablesize);

            //Destructor
            ~HashSet();

            //Returns the number of items in the table.
            int size();

            //Adds an item to the table. If the key is already found in the
            //table, we return ta pointer to the key that's already in, if it's
            //a new key, we add the key and return a pointer to the new key.
            KEY* add(const KEY& key);

            //Returns a reference to the key we are looking for.
            KEY* get(const KEY& key) const;

            //Removes the key. If the key is not in the table, we return false.
            bool remove(const KEY& key);

            //Removes all the data in the table.
            void removeAll();

            //Starts the iterator, returns the first non-NULL element of the 
            //data.
            KEY* getFirst() const;

            //Gets the next item from the iterator, returns NULL if there is no
            //more items.
            KEY* next();
        protected:
            class HashItem
            {
                public:
                    KEY key;
                    HashItem* next;
            };

            int hashFunction(const KEY& key) const;

            //Table data
            int m_tablesize;
            int m_size;
            HashItem** m_table;

            //Iterator data
            int m_index;
            HashItem* m_item;
    };
}
#endif
