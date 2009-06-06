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

#include "../include/PandoraHashSet.hpp"

namespace Pandora
{
//#############################################################################

    template<class KEY>
    HashSet<KEY>::HashSet(const int& tablesize)
    {
        assert(tablesize >= 0);

        if(tablesize < 0)
            tablesize = 0;

        m_tablesize = tablesize;
        m_size = 0;
        m_table = new HashItem*[m_tablesize];
    }

//#############################################################################

    template<class KEY>
    HashSet<KEY>::~HashSet()
    {
        removeAll();
        delete[] m_table;
    }

//#############################################################################

    template<class KEY>
    int HashSet<KEY>::size()
    {
        return m_size;
    }

//#############################################################################

    template<class KEY>
    KEY* HashSet<KEY>::add(const KEY& key)
    {
        int n = hashFunction(key);
        
        if(!m_table[n]) {
            m_table[n] = new HashItem;
            m_table[n]->key = key;
            return &(m_table[n]->key);
        }
 
        HashItem* item = m_table[n];
        while(item) {
            if(item->key == key)
                return &(item->key);
            item = item->next;
        }

        item = m_table[n];
        m_table[n] = new HashItem;
        m_table[n]->key = key;
        m_table[n]->next = item;
        return &(m_table[n]->key);
    }

//#############################################################################

    template<class KEY>
    KEY* HashSet<KEY>::get(const KEY& key) const
    {
        int n = hashFunction(key);
        HashItem* item = m_table[n];

        while(item) {
            if(item->key == key)
                return &(item->key);
            item = item->next;
        }

        return NULL;
    }

//#############################################################################

    template<class KEY>
    bool HashSet<KEY>::remove(const KEY& key)
    {
        int n = hashFunction(key);
        HashItem* item = m_table[n];
        HashItem* last = NULL;

        while(item) {
            if(item->key == key) {
                if(last) {
                    last->next = item->next;
                    delete item;
                } else {
                    m_table[n] = item->next;
                    delete item;
                }
                return true;
            }
            last = item;
            item = item->next;
        }

        return false;
    }

//#############################################################################

    template<class KEY>
    void HashSet<KEY>::removeAll()
    {
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

//#############################################################################

    template<class KEY>
    int HashSet<KEY>::hashFunction(const KEY& key) const
    {
        static double multiplier = 0.5*(sqrt(5.0) - 1.0);
        unsigned int uikey;
        memcpy(&uikey, &key, sizeof(unsigned int));
        uikey %= m_tablesize;
        double fraction = fmod(multiplier * uikey, 1.0);
        return (int)floor(m_tablesize * fraction);
    }

//#############################################################################

    template<class KEY>
    KEY* HashSet<KEY>::getFirst() const
    {
        if(m_size == 0)
            return NULL;

        int i = 0;
        while(!m_table[i] && i < m_tablesize)
            i++;

        m_index = i;
        m_item = m_table[i];
        return &(m_item->key);
    }

//#############################################################################

    template<class KEY>
    KEY* HashSet<KEY>::next()
    {
        m_item = m_item->next;

        while(!m_item && m_index < m_tablesize) {
            ++m_index;
            m_item = m_table[m_index];
        }

        if(!m_item)
            return NULL;
        return &(m_item->next);
    }

//#############################################################################
}
