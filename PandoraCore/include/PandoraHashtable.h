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

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>

//TODO: Make an iterator!
namespace PandoraUtils
{
    namespace
    {
        //One node in the table.
        template<class Key, class Value>
        struct Node
        {
            Key key;
            Value *value;
        };
    } //Anon namespace

    /**
     * A HashTable class.
     */
    template<class Key, class Value>
    class HashTable
    {
        public:
            //Constructor.
            HashTable(const size_t& size);
            ~HashTable();

            bool insert(const Key& key, const Value& value);
            Value& remove(const Key& key);
            void removeAll();

            bool exists(const Key& key) const;
            Value& find(const Key& key) const;
        protected:
            size_t m_size;
            size_t m_elements;
            Node<Key, Value> *m_values;
    };

    //-------------------------------------------------------------------------
    //                              Constructor.
    //-------------------------------------------------------------------------
    template<class Key, class Value>
    HashTable<Key,Value>::HashTable(const size_t& size)
    {
        m_size = size;
        m_elements = 0;
        m_values = new Node<Key,Value>[size];
    }

    //-------------------------------------------------------------------------
    //                              Destructor.
    //-------------------------------------------------------------------------
    template<class Key, class Value>
    HashTable<Key,Value>::~HashTable()
    {
        for(int i = 0; i < m_size; ++i) {
            free(m_values[i]);
        }
        delete[] m_values;
    }

    //-------------------------------------------------------------------------
    // Insert a value into the HashTable. Returns false if the table is full or
    //          if it hashes to the same value as another element.
    //-------------------------------------------------------------------------
    template<class Key, class Value>
    bool HashTable<Key,Value>::insert(const Key& key, const Value& value)
    {
        //No spaces free.
        if(m_elements == m_size) {
            return false;
        }

        //Get the index for this element.
        int index = key.hashFunction();

        //Crashes with other element
        if(m_values[index]) {
            return false;
        }

        //Successful insertion.
        m_values[index] = malloc(sizeof(Node<Key,Value>));
        m_values[index]->key = key;
        m_values[index]->value = value;
        return true;
    }

    //-------------------------------------------------------------------------
    //  Remove element from the set, and return the value of the element.
    //-------------------------------------------------------------------------
    template<class Key, class Value>
    Value& HashTable<Key,Value>::remove(const Key& key)
    {
        int index = key.hashFunction();

        //If the key doesn't hash to anything we have, or the keys mismatch, we
        //return a NULL object.
        if(!m_values[index] || m_values[index]->key != key) {
            return NULL;
        }

        //Found the right element, removing it.
        Value tmp = m_values[index]->value;
        free(m_values[index]);
        m_values[index] = NULL;

        //Return the element we found.
        return tmp;
    }
}
#endif
