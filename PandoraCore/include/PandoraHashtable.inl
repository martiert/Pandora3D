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

//-----------------------------------------------------------------------------
// This file contains the definition of the HashTable that belongs to Pandora3D
//-----------------------------------------------------------------------------
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
    int index = hashFunction(key);

    //Crashes with other element
    if(m_values[index]) {
        return false;
    }

    //Successful insertion.
    m_values[index] = malloc(sizeof(Node<Key,Value>));
    m_values[index]->key = key;
    m_values[index]->value = value;
    m_elements++;
    return true;
}

//-------------------------------------------------------------------------
//  Remove element from the table, and return the value of the element.
//-------------------------------------------------------------------------
template<class Key, class Value>
Value& HashTable<Key,Value>::remove(const Key& key)
{
    int index = hashFunction(key);

    //If the key doesn't hash to anything we have, or the keys mismatch, we
    //return a NULL object.
    if(!m_values[index] || m_values[index]->key != key) {
        return NULL;
    }

    //Found the right element, removing it.
    Value tmp = m_values[index]->value;
    free(m_values[index]);
    m_values[index] = NULL;
    m_elements--;

    //Return the element we found.
    return tmp;
}

//---------------------------------------------------------------------
//                  Remove all elements from the table.
//---------------------------------------------------------------------
template<class Key, class Value>
void HashTable<Key,Value>::removeAll()
{
    if(m_elements > 0) {
        for(int i = 0; i < m_size; ++i) {
            if(m_values[i]) {
                free(m_values[i]);
            }
        }

        m_elements = 0;
    }
}

//---------------------------------------------------------------------
//          Checks if the key is present in the table.
//---------------------------------------------------------------------
template<class Key, class Value>
bool HashTable<Key,Value>::exists(const Key& key) const
{
    int index = hashFunction(key);

    if(m_values[index] && m_values[index]->key == key) {
        return false;
    }

    return false;
}

//---------------------------------------------------------------------
// Checks if the key is present in the table and, if it is, returns the
//                                  element.
//---------------------------------------------------------------------
template<class Key,class Value>
Value& HashTable<Key,Value>::find(const Key& key) const
{
    int index = hashFunction(key);

    if(m_values[index] && m_values[index]->key == key) {
        return m_values[index]->value;
    }

    return NULL;
}

//---------------------------------------------------------------------
//                      The Hash function.
//---------------------------------------------------------------------
template<class Key, class Value>
int HashTable<Key,Value>::hashFunction(const Key& key) const
{
    if(userHashFunction)
        return (*userHashFunction)(key);

    static double multiply = 0.5*(sqrt(5.0) - 1.0);
    size_t hashKey;
    memcpy(&hashKey, &key, sizeof(size_t));
    hashKey %= m_size;
    double fraction = fmod(multiply * hashKey, 1.0);
    return floor(fraction * m_size);
}
