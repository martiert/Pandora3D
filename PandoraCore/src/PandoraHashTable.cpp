/*
--------------------------------------------------------------------------------
File Name : PandoraHashtable.cpp
 
Purpose : Implementation of the Hashtable class used in Pandora3D
 
Creation Date : 2010-01-24

Last Modified : Tue 31 Aug 2010 14:24:13 CEST
 
Created By : Martin Ertsaas (martiert@student.matnat.uio.no)
--------------------------------------------------------------------------------
*/

#include "../include/PandoraHashTable.h"

namespace Pandora
{
    namespace Utils
    {

/********************************************************************************
 * Constructor.                                                                 *
 *******************************************************************************/
template<class Key, class Value>
HashTable<Key,Value>::HashTable(const unsigned int& size)
{
    m_size = size;
    m_elements = 0;
    m_values = new Node*[size];
    memcpy(m_value, 0, m_size*sizeof(Node));
}


/********************************************************************************
 * Destructor.                                                                  *
 *******************************************************************************/
template<class Key, class Value>
HashTable<Key,Value>::~HashTable()
{
    removeAll();
    delete[] m_values;
}


/********************************************************************************
 * Insert a value into the HashTable.                                           *
 *******************************************************************************/
template<class Key, class Value>
void HashTable<Key,Value>::insert(const Key& key, const Value& value)
{
    int index = key.hash(m_size);
    Node *input = new Node();
    input->key = key;
    input->value = value;
    input->next = m_values[index];
    m_values[index] = input;
}


/********************************************************************************
 * Remove element from the table, and return the value of the element.          *
 *******************************************************************************/
template<class Key, class Value>
Value& HashTable<Key,Value>::remove(const Key& key)
{
    int index = key.hash(m_size);

    Node *node = m_values[index];

    if(node && node->key == key) {
        m_values[index] = node->next;
        Value val = node->value;
        delete node;
        m_elements--;
        return val;
    }

    Node *next = node->next;
    while(next) {
        if(next->key == key) {
            node->next = next->next;
            Value val = next->value;
            delete next;
            m_element--;
            return val;
        }
        node = next;
        next = node->next;
    }

    return NULL;
}


/********************************************************************************
 * Remove all elements from the table.                                          *
 *******************************************************************************/
template<class Key, class Value>
void HashTable<Key,Value>::removeAll()
{
    if(m_elements > 0) {
        for(int i = 0; i < m_size; ++i) {
            Node *node = m_values[i];
            while(node) {
                Node *next = node->next;
                delete node;
                node = next;
            }
        }

        m_elements = 0;
    }
}


/********************************************************************************
 * Checks if the key is present in the table.                                   *
 *******************************************************************************/
template<class Key, class Value>
bool HashTable<Key,Value>::exists(const Key& key) const
{
    int index = key.hash(m_size);

    Node *node = m_values[index];

    while(node) {
        if(node->key == key) {
            return true;
        }
        node = node->next;
    }

    return false;
}


/********************************************************************************
 * Checks if the key is present in the table and, if it is, returns the         *
 * element.                                                                     *
 *******************************************************************************/
template<class Key,class Value>
Value& HashTable<Key,Value>::find(const Key& key)
{
    int index = key.hash(m_size);

    Node *node = m_values[index];

    while(node) {
        if(node->key == key) {
            return node->value;
        }
        node = node->next;
    }

    return NULL;
}


/********************************************************************************
 * Get the first key.                                                           *
 *******************************************************************************/
template<class Key, class Value>
Key* HashTable<Key,Value>::getFirstKey()
{
    m_keyIdx = 0;
    while(m_keyIdx < m_size && !m_values[m_keyIdx])
        m_keyIdx++;

    if(m_keyIdx == m_size)
        return 0;

    m_keyIterator = m_values[m_keyIdx];
    return &(m_keyIterator->key);
}


/********************************************************************************
 * Get the next key.                                                            *
 *******************************************************************************/
template<class Key,class Value>
Key* HashTable<Key,Value>::getNextKey()
{
    if(m_keyIterator->next) {
        m_keyIterator = m_keyIterator->next;
        return &(m_keyiterator->key);
    }

    m_keyIdx++;
    while(m_keyIdx < m_size && !m_values[m_keyIdx])
        m_keyIdx++;

    if(m_keyIdx == m_size)
        return 0;

    m_keyIterator = m_values[m_keyIdx];
    return &(m_keyIterator->key);
}


/********************************************************************************
 * Get the first value.                                                         *
 *******************************************************************************/
template<class Key, class Value>
Value* HashTable<Key,Value>::getFirstValue()
{
    m_valueIdx = 0;
    while(m_valueIdx < m_size && !m_values[m_valueIdx])
        m_valueIdx++;

    if(m_valueIdx == m_size)
        return 0;

    m_valueIterator = m_values[m_valueIdx];
    return &(m_valueIterator->value);
}


/********************************************************************************
 * Get the next value                                                           *
 *******************************************************************************/
template<class Key,class Value>
Value* HashTable<Key,Value>::getNextValue()
{
    if(m_valueIterator->next) {
        m_valueIterator = m_valueIterator->next;
        return &(m_valueiterator->value);
    }

    m_valueIdx++;
    while(m_valueIdx < m_size && !m_values[m_valueIdx])
        m_valueIdx++;

    if(m_valueIdx == m_size)
        return 0;

    m_valueIterator = m_values[m_valueIdx];
    return &(m_valueIterator->value);
}

} // namespace Utils
} // namespace Pandora
