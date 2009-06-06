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

#include "../include/PandoraHashTable.hpp"

template<class KEY, class VALUE>
HashTable<KEY, VALUE>::HashTable(const int tablesize)
{
    assert(tablesize >= 0);

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
        it(key == item->key)
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
        for(int i = 0; i < m_tableSize; ++i) {
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
VALUE& HashTable<KEY,VALUE>::get(const KEY& key) const
{
    int n = hashFunction(key);
    HashItem* item = m_table[n];

    while(item) {
        if(item->key == key)
            return item->value;
        item = item->next;
    }

    return NULL;
}

//#############################################################################

template<class KEY, class VALUE>
int& HashTable<KEY,VALUE>::hashFunction(const KEY& key) const
{
    static double multiplier = 0.5*(sqrt(5.0) - 1.0);
    unsigned int uikey;
    memcpy(&uikey, &key, sizeof(unsigned int));
    uikey %= m_tablesize;
    double fraction = fmod(multiplier * uikey, 1.0);
    return (int)floor(m_tablesize * fraction);
}

//#############################################################################
