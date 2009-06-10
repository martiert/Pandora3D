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

            //Returns the number of items in the table
            int size();

            //Get the first element, and key, in the table.
            VALUE* getFirst(KEY* key) const;

            //Get the next element, and key, from the table. If there are no more
            //elements we return NULL:
            VALUE* next(KEY* key) const;
        protected:
            class HashItem
            {
                public:
                    KEY key;
                    VALUE value;
                    HashItem* next;
            };

            //The default hash function.
            int hashFunction(const KEY& key) const;

            //HashTable
            int m_tablesize;
            int m_size;
            HashItem** m_table;

            //Iterator data
            int m_index;
            HashItem* m_item;
    };

//#############################################################################

    template<class KEY, class VALUE>
    HashTable<KEY, VALUE>::HashTable(const int tablesize)
    {
        assert(tablesize >= 0);

        if(tablesize < 0)
            tablesize = 0;

        m_tablesize = tablesize;
        m_size = 0;
        m_table = new HashItem*[m_tablesize];
    }

//#############################################################################

    template<class KEY, class VALUE>
    HashTable<KEY,VALUE>::~HashTable()
    {
        removeAll();
        delete[] m_table;
    }

//#############################################################################

    template<class KEY, class VALUE>
    bool HashTable<KEY,VALUE>::add(const KEY& key, const VALUE& value)
    {
        int n = hashFunction(key);
        HashItem* item = m_table[n];

        while(item) {
            if(key == item->key)
                return false;
            item = item->next;
        }

        item = new HashItem;
        item->key = key;
        item->value = value;
        item->next = m_table[n];
        m_table[n] = item;
        ++m_size;
        return true;
    }

//#############################################################################

    template<class KEY, class VALUE>
    bool HashTable<KEY,VALUE>::remove(const KEY& key)
    {
        int n = hashFunction(key);
        HashItem* item = m_table[n];

        if(!item)
            return false;

        if(item->key == key) {
            m_table[n] = item->next;
            delete item;
            --m_size;
            return true;
        }

        while(item->next && item->next->key != key)
            item = item->next;

        if(!item->next)
            return false;

        HashItem* tmp = item->next;
        item->next = item->next->next;
        delete tmp;
        --m_size;
        return true;
    }

//#############################################################################

    template<class KEY, class VALUE>
    void HashTable<KEY,VALUE>::removeAll()
    {
        if(m_size != 0) {
            for(int i = 0; i < m_tablesize; ++i) {
                HashItem* item = m_table[i];

                while(item) {
                    HashItem* tmp = item;
                    item = item->next;
                    delete tmp;
                
                    if(--m_size == 0)
                        return;
                }
            }
        }   
    }

//#############################################################################

    template<class KEY, class VALUE>
    VALUE* HashTable<KEY,VALUE>::get(const KEY& key) const
    {
        int n = hashFunction(key);
        HashItem* item = m_table[n];

        while(item) {
            if(item->key == key)
                return &(item->value);
            item = item->next;
        }

        return NULL;
    }   

//#############################################################################

    template<class KEY, class VALUE>
    int HashTable<KEY,VALUE>::hashFunction(const KEY& key) const
    {
        static double multiplier = 0.5*(sqrt(5.0) - 1.0);
        unsigned int uikey;
        memcpy(&uikey, &key, sizeof(unsigned int));
        uikey %= m_tablesize;
        double fraction = fmod(multiplier * uikey, 1.0);
        return (int)floor(m_tablesize * fraction);
    }

//#############################################################################

    template<class KEY, class VALUE>
    VALUE* HashTable<KEY,VALUE>::getFirst(KEY* key) const
    {
        if(m_size == 0)
            return NULL;

        int i = 0;
        while(!m_table[i] && i < m_tablesize)
            ++i;

        m_item = m_table[i];
        m_index = i;
        key = &(m_item->key);
        return &(m_item->value);
    }

//#############################################################################

    template<class KEY, class VALUE>
    VALUE* HashTable<KEY,VALUE>::next(KEY* key) const
    {
        if(m_item->next) {
            m_item = m_item->next;
        } else {
            int i = m_index + 1;
            while(i < m_tablesize && !m_table[i])
                ++i;
            m_item = m_table[i];
            m_index = i;
        }
        key = &(m_item->key);
        return &(m_item->value);
    }

//#############################################################################
}
#endif
