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

#ifndef _HASHTABLE_HPP_
#define _HASHTABLE_HPP_

#include "PandoraSystem.hpp"

namespace Pandora
{
    template<class KEY, class VALUE>
    class HashTable
    {

        public:
            //Constructor. Makes a table of HashItem objects.
            HashTable(const int tablesize);
            ~HashTable();

            //Inserts an item into the HashTable. Returns false only if an
            //element with the same key exists in the table.
            bool add(const KEY& key, const VALUE& value);

            //Removes an item from the HashTable. Returns false only if no
            //elements with the key exists in the table.
            bool remove(const KEY& key);

            //Removes all the items from the HashTable.
            void removeAll();

            //Finds the value associated with key, returns NULL if the element
            //is not in the table.
            VALUE* get(const KEY& key) const;
        protected:
            class HashItem
            {
                public:
                    KEY key;
                    VALUE value;
                    SmallList* next;
            }

            //The default hash function.
            int hashFunction(const KEY& key) const;

            //HashTable
            int m_tableSize;
            int m_size;
            HashItem** m_table;
    };
}

#endif
